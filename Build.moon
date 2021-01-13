-- project name
var 'NAME', 'raytrace'

-- tools to use
public var 'CPP', 'g++'
public var 'LD', 'g++'
public var 'MOC', 'moc'

-- compile flags
var 'CFLAGS', {'-fPIC', '-fopenmp', '-Wall', '-Wextra', '-Isrc', '--std=c++11', '-O3'}
var 'LDFLAGS', {'-fPIC', '-fopenmp'}
var 'PKGS', {'Qt5Widgets'}

-- extra cli flags
public var 'XCFLAGS'
public var 'XLDFLAGS'
public var 'XPKGS'
public var 'XLIBS'

-- find all files for project
var 'SOURCES', _.wildcard 'src/**.cpp'
var 'HEADERS', _.wildcard 'src/**.h'
var 'QT_HEADERS', _.wildcard 'src/**.hh'

-- complete our flags
var 'PKGS', {PKGS, XPKGS}
var 'CFLAGS', {CFLAGS, XCFLAGS, _.pkgconfig.cflags PKGS}
var 'LDFLAGS', {LDFLAGS, LDCFLAGS}
var 'LIBS', {XLIBS, _.pkgconfig.libs PKGS}

-- determine our subtargets
var 'BINARY', "out/#{NAME}"
var 'OBJECTS', _.patsubst SOURCES, 'src/%.cpp', 'build/%.o'
var 'MOC_SOURCES', _.patsubst QT_HEADERS, 'src/%.hh', 'build/%.moc.cpp'
var 'MOC_OBJECTS', _.patsubst MOC_SOURCES, '%.cpp', '%.o'
var 'OBJECTS', {OBJECTS, MOC_OBJECTS}

-- print info
with public target 'info'
	\fn =>
		print "SOURCES: #{SOURCES}"
		print "HEADERS: #{HEADERS}"
		print "QT_HEADERS: #{QT_HEADERS}"
		print "OBJECTS: #{OBJECTS}"
		print "MOC_OBJECTS: #{MOC_OBJECTS}"

-- build everything
with public default target 'all'
	\depends BINARY

-- clean build objects
with public target 'clean'
	\fn => _.cmd 'rm', '-f', OBJECTS, MOC_SOURCES

-- clean everything
with public target 'mrproper'
	\after 'clean'
	\fn => _.cmd 'rm', '-f', BINARY

-- build and run
with public target 'run'
	\depends BINARY
	\fn => _.cmd "./#{BINARY}"

-- produce the binary from all objects
with target BINARY
	\produces BINARY
	\depends OBJECTS
	\fn => _.cmd LD, LDFLAGS, '-o', @outfile, @infiles, LIBS
	\mkdirs!

-- produce the objects from the sources
with target OBJECTS, pattern: 'build/%.o'
	\produces 'build/%.o'
	\depends 'src/%.cpp'
	\depends => _.cdeps[CPP] @infile, CFLAGS
	\fn => _.cmd CPP, CFLAGS, '-o', @outfile, '-c', @infile
	\mkdirs!

-- produce the objects from the moc-generated sources
with target MOC_OBJECTS, pattern: 'build/%.moc.o'
	\produces 'build/%.moc.o'
	\depends 'build/%.moc.cpp'
	\fn => _.cmd CPP, CFLAGS, '-o', @outfile, '-c', @infile

-- generate moc sources from the qt headers
with target MOC_SOURCES, pattern: 'build/%.moc.cpp'
	\produces 'build/%.moc.cpp'
	\depends 'src/%.hh'
	\fn => _.cmd MOC, '-o', @outfile, @infile
	\mkdirs!
