Camera = require 'Camera'
Vec3 = require 'Vec3'
Sphere = require 'Sphere'

scene = {
	Sphere (Vec3 4, 0, 0), 1
	Sphere (Vec3 3, 1, 1), .5
}
camera = Camera!

print camera\renderstring scene, 100, 60
print camera\ray 0, 0, 100, 100
print camera\ray 0, 99, 100, 100
print camera\ray 99, 0, 100, 100
print camera\ray 99, 99, 100, 100
