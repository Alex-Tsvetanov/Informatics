all: build run
run:
	./Main.exe
build:
	g++ Main.cpp ./OpenGL/lib/*.cpp -I./OpenGL/include `pkg-config --libs --cflags sdl2` -o Main.exe -lGL
