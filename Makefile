objects:
	g++ -c -I include/ -o object/Main.o src/Main.cpp
	g++ -c -I include/ -o object/MP3.o src/MP3.cpp
	g++ -c -I include/ -o object/Parser.o src/Parser.cpp

build:
	make objects
	g++ -I include/ -o bin/main -ltag -L/usr/lib/x86_64-linux-gnu object/Main.o object/MP3.o object/Parser.o

clean:
	rm object/*
	rm bin/*
