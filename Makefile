TARGET = bin/MaxFlow
LIBS = -lm
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g 
CLEAN = rm src/*o

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst src/%.c, src/%.o, $(wildcard src/*c))
HEADERS = $(wildcard src/*.h)

src/%.o: %.c $(HEADERS)
	 $(CC) $(CFLAGS) -c $< -o $@
	 
.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
		   $(CC) $(OBJECTS) -o $@
		   $(CLEAN)
		   		   		 
clean: 
	$(CLEAN)

	
