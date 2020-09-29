import type, typename from require 'classes'
Vec3 = require 'Vec3'
Object = require 'Object'

class Sphere extends Object
	new: (@center=Vec3!, @radius=1) =>
		error "center should be a Vec3, got #{typename @center}" unless (type @center) == Vec3
		error "radius should be a number, got #{typename @radius}" unless (type @radius) == 'number'

	__tostring: => "Sphere(center: #{@center}, radius: #{@radius})"

	_distanceto: (o) =>
		(o - @center)\norm! - @radius
