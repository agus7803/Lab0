FLAG = -Wall -Wextra -O1 -g    


main: main.o  A.o B.o C.o 
	g++ $(FLAG)  -o main main.o  A.o B.o C.o 

main.o: main.cpp  A.o B.o C.o 
	g++ $(FLAG) -c -o main.o main.cpp 

A.o: cpp/A.cpp hpp/A.hpp  
	g++ $(FLAG) -c -o A.o cpp/A.cpp

B.o: cpp/B.cpp hpp/B.hpp 
	g++ $(FLAG) -c -o B.o cpp/B.cpp

C.o: cpp/C.cpp hpp/C.hpp
	g++ $(FLAG) -c -o C.o cpp/C.cpp 

clean:
	rm -f *.o
	rm -f  main
	
full: clean main
	./main