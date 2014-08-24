#include <stdio.h>
#include <stdlib.h>
#include "selection_sort_array.h"

int main(int argc, char const *argv[])
{
/*
*	Read data from user input (stdin)
*
*/

	if (argc!=2)
	{
		fprintf(stderr, "usage:data_processing filename\n");
		exit(EXIT_FAILURE);
	}
	int size_array=0;
	int *p_size_array = &size_array;
	struct Data_unit* p_data_array = read_line((char *)argv[1],p_size_array);

	printf("Read from row data as an Array:\n");
	for (int i = 0; i < *p_size_array; ++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,p_data_array[i].num, p_data_array[i].description );
	}
	printf("\n");
/*
*
*	Selection sort by array
*/
	selection_sort(p_data_array, *p_size_array);

	printf("*****************************************************\n");
	printf("After selection sorting by array:\n");
	for (int i = 0; i < *p_size_array; ++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,p_data_array[i].num, p_data_array[i].description );
	}
	return 0;
}