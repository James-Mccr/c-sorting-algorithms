SHARED = obj\shared\Generate.o obj\shared\Search.o obj\shared\Sort.o

all: clean setup compile link

setup:
	mkdir bin
	mkdir obj
	mkdir obj\shared

compile:
	gcc -g -c src\Generate.c -o obj\shared\Generate.o
	gcc -g -c src\Search.c -o obj\shared\Search.o
	gcc -g -c src\Sort.c -o obj\shared\Sort.o
	gcc -g -c src\BinarySearch.c -Iheaders -o obj\BinarySearch.o
	gcc -g -c src\SelectionSort.c -Iheaders -o obj\SelectionSort.o
	gcc -g -c src\InsertionSort.c -Iheaders -o obj\InsertionSort.o
	gcc -g -c src\MergeSort.c -Iheaders -o obj\MergeSort.o
	gcc -g -c src\QuickSort.c -Iheaders -o obj\QuickSort.o
	gcc -g -c src\BubbleSort.c -Iheaders -o obj\BubbleSort.o
	gcc -g -c src\Test.c -Iheaders -o obj\Test.o

link: compile
	gcc obj\BinarySearch.o $(SHARED) -o bin\BinarySearch.exe
	gcc obj\SelectionSort.o $(SHARED) -o bin\SelectionSort.exe
	gcc obj\InsertionSort.o $(SHARED) -o bin\InsertionSort.exe
	gcc obj\MergeSort.o $(SHARED) -o bin\MergeSort.exe
	gcc obj\QuickSort.o $(SHARED) -o bin\QuickSort.exe
	gcc obj\BubbleSort.o $(SHARED) -o bin\BubbleSort.exe
	gcc obj\Test.o $(SHARED) -o bin\Test.exe

clean:
	rmdir /q /s bin
	rmdir /q /s obj
