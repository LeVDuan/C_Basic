wordcount: wordcount.o BST.o
	gcc -o wordcount wordcount.o BST.o
	rm *.o
wordcount.o: wordcount.c BST.h
	gcc -c wordcount.c
