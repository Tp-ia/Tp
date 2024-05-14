CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

# Target executable
TARGET = parcour

# Source files
SRCS = parcour/profondeur_dabord.cpp jeu/plateau.cpp parcour/ida.cpp parcour/heuristiques.cpp

# Object files
OBJS = $(patsubst %.cpp,bin/%.o,$(SRCS))   

# Main target
$(TARGET): $(OBJS) bin/main.o
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)

# Compile source files
bin/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf bin

tplateau: $(OBJS) bin/test/tests_plateau.o
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)

tparcour: $(OBJS) bin/test/tests_parcour.o
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)