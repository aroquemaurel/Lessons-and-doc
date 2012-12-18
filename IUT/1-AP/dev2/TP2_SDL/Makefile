dessinSDL.exe: dessinSDL.o BaseSDL.o
	g++ `sdl-config --cflags --libs` -o dessinSDL.exe dessinSDL.o BaseSDL.o

dessinSDL.o: dessinSDL.cpp
	g++ `sdl-config --cflags` -c dessinSDL.cpp 

	
