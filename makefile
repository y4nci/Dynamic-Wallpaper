CC = g++
CFLAGS = -Wall -g
 
LDFLAGS=
all	:
	$(CC)	$(CFLAGS)	main.cpp	wallpaper.cpp	-o	main	$(LDFLAGS)
wallpaper:
	$(CC)	$(CFLAGS)	wallpaper.cpp	-o	wallpaper	$(LDFLAGS)
main:
	$(CC)	$(CFLAGS)	main.cpp	-o	_main_	$(LDFLAGS)
clean:
	rm	main
