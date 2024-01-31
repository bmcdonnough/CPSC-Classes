# Benjamin McDonnough
# 12/07/22
# PA4
# CPSC 1010 -001
# This is a makefile that allows divulgance into lazy tendencies
# by only having to type a few words instead of writeing out every single
# file name.

PA4: defs.h mainDriver.c initInputImageArray.c manip.c writeHeader.c writePixels.c getHeader.c 
	gcc -g -Wall -o PA4 defs.h getHeader.c mainDriver.c initInputImageArray.c manip.c writeHeader.c writePixels.c

run: PA4
	./PA4 Disney.pnm ClemsonPaw.pnm

clean:
	rm PA4
	rm smallerImage1.pnm
	rm greenScreen1.pnm
	rm smallerImage2.pnm
