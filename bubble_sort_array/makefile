main: main.o bubble_sort_array.o data_processing.o
	gcc main.o bubble_sort_array.o data_processing.o -o main
main.o: main.c bubble_sort_array.h ../data/data_processing.h
	gcc -c main.c
bubble_sort_array.o: bubble_sort_array.c bubble_sort_array.h
	gcc -c bubble_sort_array.c
data_processing.o: ../data/data_processing.c ../data/data_processing.h
	gcc -c ../data/data_processing.c
clean:
	rm *.o main