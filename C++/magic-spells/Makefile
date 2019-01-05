all:exec
	
exec:magic-spells.o
	g++ magic-spells.o -o exec
magic-spells.o: magic-spells.cpp
	g++ -c magic-spells.cpp -o magic-spells.o
run:exec
	./exec < input
	
clean:
	rm exec *.o
