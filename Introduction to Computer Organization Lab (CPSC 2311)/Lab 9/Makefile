# Config, just variables

CC = gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# Goes through the directory and and child directories and
# finds all of the files that have the .c extension
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c)

# Goes through the directory and child directories and
# finds all of the files that have the .h extension
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

# Gets all of the object files from the .c files by replacing the .c
# extension with the .o extension
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))

# Goes through the src directory and filters out any .o files
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# default target. 
all: build
	@echo "All Done!"

# Link all built objects. Compiles the included files
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# This changes the rules for compiling for the OBJS by adding
# the bin/. This catches all of the root directory src files
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Does the same as the target above, however, it checks the 
# child directory files instead
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes any unneeded files for execution so that building / 
# execution is more efficient
clean:
	rm -f $(TARGET)
	rm -rf bin

# Runs the executable that is made from build
run: build
	./$(TARGET) F23Data.csv output.txt

# Print out which files were found that end in .c, .h, or .o
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"
