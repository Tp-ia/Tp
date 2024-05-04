CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

# Target executable
TARGET = profondeur_dabord

# Source files
SRCS = parcour/profondeur_dabord.cpp jeu/plateau.cpp parcour/tests.cpp


# Object files
OBJS = $(SRCS:.cpp=.o)

# Main target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	$(RM) $(TARGET) $(OBJS)