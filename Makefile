
all:	physics.exe planets.exe
	echo "all" > all
physics.exe:	physics.cpp
	g++ -g physics.cpp -lglut -lGLU -lGL -o physics.exe
planets.exe:	planets.cpp
	g++ -g planets.cpp -lglut -lGLU -lGL -o planets.exe
clean:
	rm *.o *.exe
