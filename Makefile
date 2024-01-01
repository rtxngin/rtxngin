CC = g++
CFLAGS = -Wall -Wextra

SOURCES = $(wildcard source/*.cpp)
OBJECTS = $(patsubst source/%.cpp, %.o, $(SOURCES))

rtx: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: source/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) rtx
