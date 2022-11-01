hw1 : disk.o fs.o testcase.o validate.o
	gcc -o hw1 disk.o fs.o testcase.o validate.o

disk.o : disk.c
	gcc -c -o disk.o disk.c

fs.o : fs.c
	gcc -c -o fs.o fs.c

testcase.o : testcase.c
	gcc -c -o testcase.o testcase.c

clean :
	rm fs.o disk.o testcase.o hw1
