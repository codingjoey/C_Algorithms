main: main.o selection_sort_array.o data_processing.o
	gcc main.o selection_sort_array.o data_processing.o -o main
main.o: main.c selection_sort_array.h ../data/data_processing.h
	gcc -c main.c
selection_sort_array.o: selection_sort_array.c selection_sort_array.h
	gcc -c selection_sort_array.c
data_processing.o: ../data/data_processing.c ../data/data_processing.h
	gcc -c ../data/data_processing.c
clean:
	rm *.o main