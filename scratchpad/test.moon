Camera = require 'Camera'
Vec3 = require 'Vec3'
Sphere = require 'Sphere'
Plane = require 'Plane'

scene = {
	Sphere (Vec3 4, 0, 0), 1
	Sphere (Vec3 3, 1, 1), .5
	Plane (Vec3 0, -1, 1), 3
}
camera = Camera!

print camera\renderstring scene, 100-19, 60
print camera\ray 0, 0, 100, 100
print camera\ray 0, 99, 100, 100
print camera\ray 99, 0, 100, 100
print camera\ray 99, 99, 100, 100
print (Vec3.x\angleto Vec3.y), (Vec3.y\angleto Vec3.x), (Vec3.x\angleto Vec3.y), (Vec3.x\angleto Vec3.x)
print (Vec3.x\angleto Vec3 1, 1, 0), (Vec3.x\angleto -Vec3.x), (Vec3.x\angleto Vec3 1, 1, 1)
