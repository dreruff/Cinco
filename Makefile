p4: main.o Cinco.o Dictionary.o
	g++ -o p4 main.o Cinco.o Dictionary.o

# define how each object file is to be built
main.o: main.cpp Cinco.h 
	g++ -c main.cpp

Cinco.o: Cinco.cpp Cinco.h Dictionary.h
	g++ -c Cinco.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

# clean up
clean:
	rm -f p4 *.o *~

