.PHONY: all clean mrproper rebuild run png push icat doc

NAME = raytrace

CPP = g++
LD = g++
RM = rm -f
MOC = moc

PKGS = Qt5Widgets
CFLAGS = -fopenmp -fPIC -Wall -Wextra -O3
LDFLAGS = -fopenmp -fPIC
LIBS = 

CFLAGS := $(CFLAGS) $(shell pkg-config $(PKGS) --cflags)
LIBS := $(LIBS) $(shell pkg-config $(PKGS) --libs)

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
QHEADERS = $(wildcard src/*hh)

OBJECTS = $(foreach source, $(SOURCES), build/$(patsubst src/%.cpp,%.o,$(source)))
MOCS = $(foreach qheader, $(QHEADERS), build/$(patsubst src/%.hh,%.moc.cpp,$(qheader)))
MOCOBJS = $(foreach moc, $(MOCS), $(patsubst %.moc.cpp,%.moc.o,$(moc)))

BINARY = out/$(NAME)

all: $(BINARY)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(MOCOBJS)
	$(RM) $(MOCS)
	$(RM) Makefile.deps
	$(RM) build/?*.* # catch all renamed files
mrproper: clean
	$(RM) $(BINARY)
	$(RM) out/$(NAME).bmp out/$(NAME).png

rebuild:
	@make mrproper
	@make

run: all
	./$(BINARY)

bmp: out/$(NAME).bmp

png: out/$(NAME).png

push: out/$(NAME).png
	push -d a.png || true
	push $^ a.png

icat: out/$(NAME).bmp
	kitty +kitten icat $^

doc:
	doxygen Doxyfile

out/$(NAME).bmp: $(BINARY)
	./$(BINARY) > $@

out/$(NAME).png: out/$(NAME).bmp
	convert $^ $@

include Makefile.deps
Makefile.deps: $(SOURCES) $(HEADERS)
	@echo "Calculating dependencies"
	@$(RM) Makefile.deps
	@for file in $(SOURCES); do echo "build/`g++ $(CFLAGS) -M $$file`" >> Makefile.deps; done

$(BINARY): $(OBJECTS) $(MOCOBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/%.o: src/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

build/%.moc.o: build/%.moc.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

build/%.moc.cpp: src/%.hh
	$(MOC) -o $@ $<
