all:	app-hw1

app-hw1:	main.o initMatrix.o displayMatrix.o
	gcc main.o initMatrix.o displayMatrix.o -o app-hw1

main.o:	main.c
	gcc -c main.c -o main.o

initMatrix.o:	initMatrix.c
	gcc -c initMatrix.c -o initMatrix.o
	
displayMatrix.o:	displayMatrix.c
	gcc -c displayMatrix.c -o displayMatrix.o	

MultMatrices.o:	MultMatrices.c
	gcc -c MultMatrices.c -o MultMatrices.o	

ThreadCalcule.o:	ThreadCalcule.c
	gcc -c ThreadCalcule.c -o ThreadCalcule.o

clean:
	rm -fr app-hw1 *.o
