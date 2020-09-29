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
		sort intersections, (a, b) -> a.dist - b.dist

		intersections[1]

	render: (scene, mx, my) =>
		[ [ @getpixel scene, x, y, mx, my for x=0, mx-1 ] for y=0, my-1 ]

	renderstring: (scene, mx, my) =>
		pixels = @render scene, mx, my
		str = ''
		for y=1, my
			str ..= '\n' if y!=1
			str ..= pixels[y][x] and 'X' or ' ' for x=1, mx
		str
