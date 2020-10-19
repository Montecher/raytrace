.PHONY: all clean mrproper rebuild run

NAME = raytrace

CPP = g++
LD = g++
RM = rm -f
MOC = moc

CFLAGS = -fPIC -Wall -Wextra -O2 $(shell pkg-config Qt5Widgets --cflags)
LDFLAGS = -fPIC
LIBS = $(shell pkg-config Qt5Widgets --libs)

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

rebuild:
	@make mrproper
	@make

run: all
	./$(BINARY)

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
