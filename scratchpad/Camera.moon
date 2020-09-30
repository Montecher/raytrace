import type, typename from require 'classes'
Vec3 = require 'Vec3'
Ray = require 'Ray'
import insert, sort, concat from table

class Camera
	new: (@orig=Vec3!, @dir=(Vec3 1, 0, 0), @right=(Vec3 0, 1, 0), @width=1, @height=1) =>
		error "orig must be a Vec3, got a #{typename @orig}" unless (type @orig) == Vec3
		error "dir must be a Vec3, got a #{typename @dir}" unless (type @dir) == Vec3
		error "right must be a Vec3, got a #{typename @right}" unless (type @right) == Vec3
		error "width must be a number, got a #{typename @width}" unless (type @width) == 'number'
		error "height must be a number, got a #{typename @height}" unless (type @height) == 'number'

		@right = @right\normal!
		@up = (@dir * @right)\normal!

	__tostring: =>
		"Camera orig: #{@orig}, dir: #{@dir}, right: #{@right}, up: #{@up}, width: #{@width}, height: #{@height}"

	ray: (x, y, mx, my, w=1, h=1) =>
		x = (x / (mx - 1) - .5) / w * @width
		y = (y / (my - 1) - .5) / h * @height
		dir = (@dir + @right * x - @up * y)\normal!
		Ray @orig, dir

	getpixel: (scene, x, y, mx, my) =>
		mm = mx<my and my or mx
		w = mx/mm
		h = my/mm
		ray = @ray x, y, mx, my, w, h

		intersections = {}
		for object in *scene
			dist, point, normal = ray\intersect object
			if dist
				insert intersections, {:dist, :point, :normal, :object}
		sort intersections, (a, b) -> a.dist < b.dist

		intersections[1]

	render: (scene, mx, my) =>
		[ [ @getpixel scene, x, y, mx, my for x=0, mx-1 ] for y=0, my-1 ]

	renderstring: (scene, mx, my) =>
		pixels = @render scene, mx, my
		str = ''

		sizes = {
			[4]: (string.char 0xe2, 0x96, 0x91)
			[3]: (string.char 0xe2, 0x96, 0x92)
			[2]: (string.char 0xe2, 0x96, 0x93)
			[1]: (string.char 0xe2, 0x96, 0x88)
		}

		mindist, maxdist = do
			m, M = math.huge, 0
			for r in *pixels
				for p in *r
					if p and (typename p.object)!='Plane'
						m = p.dist if p.dist<m
						M = p.dist if p.dist>M
			m, M

		getchar = (angle, dist, object) ->
			shape = typename object
			char = do
				if shape!='Plane'
					size = math.floor (dist-mindist)/(maxdist-mindist) * 3 + 1
					size = 4 if size>4
					size = 1 if size<1
					sizes[size]
				else
					sizes[1]
			red = math.floor angle/math.pi * 255
			green = do
				name = typename object
				if name=='Plane'
					0
				elseif name=='Sphere'
					255
				else
					print name
					127
			"#{string.char 0x1b}[38;2;#{red};#{green};255m#{char}"

		for y=1, my
			str ..= '\n' if y!=1
			for x=1, mx
				pixel = pixels[y][x]
				if pixel
					import dist, point, normal, object from pixels[y][x]
					angle = (point - @orig)\angleto normal
					str ..= getchar angle, dist, object
				else
					str ..= ' '
		str ..= "#{string.char 0x1b}[0m"
		str
