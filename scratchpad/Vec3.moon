import type, typename, sametype from require 'classes'
import sqrt, acos from math

class Vec3
	new: (@x=0, @y=0, @z=0) =>

	__add: (o) =>
		error "attempt to use + on #{typename @} and #{typename o}" unless sametype @, o
		@@ @x+o.x, @y+o.y, @z+o.z

	__sub: (o) =>
		error "attempt to use - on #{typename @} and #{typename o}" unless sametype @, o
		@@ @x-o.x, @y-o.y, @z-o.z

	__unm: =>
		@@ -@x, -@y, -@z

	__mul: (o) =>
		if sametype @, o
			@@ @y*o.z-@z*o.y, @z*o.x-@x*o.z, @x*o.y-@y*o.x
		elseif (type @) == Vec3 and (type o) == 'number'
			@@ @x*o, @y*o, @z*o
		elseif (type @) == 'number' and (type o) == Vec3
			o * @
		else
			error "attempt to use * on #{typename @} and #{typename o}"

	__div: (o) =>
		if sametype @, o
			@x*o.x + @y*o.y + @z*o.z
		elseif (type @) == Vec3 and (type o) == 'number'
			@@ @x/o, @y/o, @z/o
		else
			error "attempt to use / on #{typename @} and #{typename o}"

	__tostring: =>
		"(#{@x}, #{@y}, #{@z})"

	norm: =>
		import x, y, z from @
		sqrt x*x+y*y+z*z

	normal: =>
		@ / @norm!

	angleto: (o) =>
		snorm = @norm!
		onorm = o\norm!
		acos (@/o) / (snorm * onorm)

	@x: @ 1, 0, 0
	@y: @ 0, 1, 0
	@z: @ 0, 0, 1
