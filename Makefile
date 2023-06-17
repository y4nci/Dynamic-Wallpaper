CC = g++
CFLAGS = -Wall -g
 
LDFLAGS=
all	: main
main:
	$(CC)	$(CFLAGS)	src/main.cpp	src/wallpaper.cpp	-o	bin/dynamic-wallpaper	$(LDFLAGS)
clean:
	rm	main
