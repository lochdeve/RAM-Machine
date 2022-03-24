#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/ram
EJEC :=./ram
RUN :=./bin/ram

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g  -std=c++14 #-Wall  --debug #-O2 
LIB := #-lsfml-graphics -lsfml-window -lsfml-system #-pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC := -I include


$(TARGET): $(OBJECTS)  	
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)  
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS)  -c -o $@ $<

run:
	$(RUN) ejemplosRAM/test1.ram cintas/input_tape.in cintas/output_tape.out 0

debug:

	$(CC) $(CFLAGS) *

clean:
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean