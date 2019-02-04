
all:	physics.exe planets.exe
	echo "all" > all
physics.exe:	physics.cpp Pobj.o
	g++ -g physics.cpp Pobj.o -lglut -lGLU -lGL -o physics.exe
planets.exe:	planets.cpp
	g++ -g planets.cpp -lglut -lGLU -lGL -o planets.exe
Pobj.o:	Pobj.cpp Pobj.h
	g++ -g -c Pobj.cpp -lglut -lGLU -lGL -o Pobj.o
clean:
	rm *.o *.exe
