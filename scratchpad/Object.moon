import type, typename from require 'classes'
import EPSILON from require 'constants'
Vec3 = require 'Vec3'
import huge from math

class Object
	__bxor: (obj, point) ->
		obj\distanceto point

	__pow: (obj, point) ->
		obj\normal point

	__mul: (o) => @@Intersection @, o
	__add: (o) => @@Union @, o
	__unm: => @@Negation @
	__sub: (o) => @@Exclusion @, o

	__tostring: => "[Invalid Object]"

	__inherited: (child) =>
		proto = child.__base
		for k, v in pairs @__base
			if (k\match '^__') and (rawget proto, k) == nil
				rawset proto, k, v

	distanceto: (point) =>
		error "attempt to get distance to a #{typename point}" unless (type point) == Vec3
		@_distanceto point

	normal: (point, epsilon=EPSILON) =>
		error "attempt to get normal at a #{typename point}" unless (type point) == Vec3
		v = @distanceto point
		x = ((@distanceto point + Vec3.x * epsilon) - v) / epsilon
		y = ((@distanceto point + Vec3.y * epsilon) - v) / epsilon
		z = ((@distanceto point + Vec3.z * epsilon) - v) / epsilon
		(Vec3 x, y, z)\normal!

	_distanceto: (point) =>
		error "attempt to get distance to an invalid Object (pure virtual method)"

	intersection: (...) => @@Intersection @, ...
	union: (...) => @@Union @, ...
	negate: => @@Negation @
	exclude: (o) => @@Exclusion @, o

class Intersection extends Object
	new: (...) =>
		@objs = {...}

	__tostring: => "Intersection(#{concat [tostring x for x in *@objs], ', '})"

	_distanceto: (point) =>
		dist = -huge
		for obj in *@objs
			d = obj\_distanceto point
			dist = d if d>dist
		dist

class Union extends Object
	new: (...) =>
		@objs = {...}

	__tostring: => "Union(#{concat [tostring x for x in *@objs], ', '})"

	_distanceto: (point) =>
		dist = huge
		for obj in *@objs
			d = obj\_distanceto point
			dist = d if d<dist
		dist

class Negation extends Object
	new: (@obj) =>

	__tostring: => "Negation(#{@obj})"

	_distanceto: (point) =>
		-(@obj\_distanceto point)

class Exclusion extends Object
	new: (@a, @b) =>

	__tostring: => "Exclusion(#{@obj})"

	_distanceto: (point) =>
		da = a\_distanceto point
		db = b\_distanceto point
		if da > -db
			da
		else
			-db

Object.Intersection = Intersection
Object.Union = Union
Object.Negation = Negation
Object.Exclusion = Exclusion

Object
