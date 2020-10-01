.PHONY: all clean mrproper rebuild run

NAME = raytrace

CPP = g++
LD = g++
RM = rm -f

CFLAGS = -Wall -Wextra -O2
LDFLAGS =
LIBS =

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)

OBJECTS = $(foreach source, $(SOURCES), build/$(patsubst src/%.cpp,%.o,$(source)))

BINARY = out/$(NAME)

all: $(BINARY)

clean:
	$(RM) $(OBJECTS)
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

$(BINARY): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/%.o: src/%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<
