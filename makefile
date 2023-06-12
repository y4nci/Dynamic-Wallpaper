CC = g++
CFLAGS = -Wall -g
 
LDFLAGS=
all	: main
wallpaper:
	$(CC)	$(CFLAGS)	src/wallpaper.cpp	-o	wallpaper	$(LDFLAGS)
main:
	$(CC)	$(CFLAGS)	src/main.cpp	src/wallpaper.cpp	-o	main	$(LDFLAGS)
clean:
	rm	main
