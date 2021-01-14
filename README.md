# raytrace
A simple sphere marching renderer

The name comes from when it was actually raytracing

## Objectives
- Render "realistic" images using rays
- Handle composite shapes
- Have a GUI in Qt

## Examples
See `prod` folder  
![render 4](prod/render-1080p-500rpp-10d/scene4.png)

## Building
Requires a C++ compiler with at least c++11 support, and Qt (both the headers and the libraries)

### With make
Build it with `make`

### Without make
- Copy all sources into a QtCreator project and compile like that
- Or any method you usually use to compile a C++/Qt project

## How it works
- Cf documentation (`make doc` with pandoc installed to generate it)
- File names are what they do; objects are segregated in the `src/objects` directory to avoid polluting `src`
