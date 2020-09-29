Vec3 = require 'Vec3'
import EPSILON, MAXDIST from require 'constants'

class Ray
	new: (@orig, @dir) =>

	__tostring: => "Ray(orig: #{@orig}, dir: #{@dir})"

	point: (t) =>
		@orig + @dir * t

	intersect: (object, epsilon=EPSILON, maxdist=MAXDIST) =>
		lastt = 0
		while lastt<maxdist
			point = @point lastt
			dist = object\distanceto point
			if dist <= 0
				normal = object\normal point
				return lastt, point, normal
			dist = epsilon if dist<epsilon
			lastt += dist

