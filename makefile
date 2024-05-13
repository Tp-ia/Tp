CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

# Target executable
TARGET = recherche

# Source files
SRCS = parcour/profondeur_dabord.cpp jeu/plateau.cpp parcour/ida.cpp parcour/heuristiques.cpp test/tests_copy.cpp

# Object files
OBJS = $(patsubst %.cpp,bin/%.o,$(SRCS)) 

# Main target
$(TARGET): $(OBJS)
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

tcopy: $(OBJS) bin/test/tests_copy.o 
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)

tests: $(OBJS) bin/test/tests.o
	$(CC) $(CFLAGS) -o bin/$@ $^ $(LDFLAGS)
