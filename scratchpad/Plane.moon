import type, typename from require 'classes'
Vec3 = require 'Vec3'
Object = require 'Object'

class Plane extends Object
	new: (@normalvec=Vec3!, @offset=0) =>
		error "normalvec should be a Vec3, got #{typename @normalvec}" unless (type @normalvec) == Vec3
		error "offset should be a number, got #{typename @offset}" unless (type @offset) == 'number'

	__tostring: => "Plane(normalvec: #{@normalvec}, offset: #{@offset})"

	_distanceto: (o) =>
		(o/@normalvec + @offset) / @normalvec\norm!

	normal: (o) =>
		@normalvec
