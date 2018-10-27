all: tester.o rand.o
	gcc -o tester tester.o rand.o
tester.o: tester.c rand.h
	gcc -c tester.c rand.h
10randfile.o: rand.c rand.h
	gcc -c rand.c rand.h

run:
	./tester
clean:
	rm -f stuff.txt ./tester  *.out *~ *.o *.gch
