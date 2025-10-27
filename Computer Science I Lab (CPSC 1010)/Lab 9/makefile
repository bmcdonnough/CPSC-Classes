# Benjamin McDonnough
# 10/27/22
# Lab9B
# CPSC 1011 -001
# This is a makefile that allows divulgance into lazy tendencies
# by only having to type a few words instead of writeing out every single
# file name.

lab9: defs.h mainDriver.c fillFlagArray.c writeHeader.c writePixels.c getWidth.c 
	gcc -Wall -o lab9 defs.h getWidth.c mainDriver.c fillFlagArray.c writeHeader.c writePixels.c

run: lab9
	./lab9

clean:
	rm lab9
