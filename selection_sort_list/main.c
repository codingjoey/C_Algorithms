#include <stdio.h>
#include <stdlib.h>
#include "selection_sort_list.h"

int main(int argc, char const *argv[])
{
/*
*
*	Read data from user input (data_unsort.txt)
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
*	selection sort by linked list
*/
	printf("**************************************\n");
	printf("Convert this array into unsorted linked list:\n");
	struct data_list *first = NULL;
	first = convertArrayToList(first, p_data_array, *p_size_array);
	struct data_list *cur;
	int i;
	for (i=0, cur = first; cur != NULL ; cur = cur->next,++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,cur->num, cur->description );
	}
	printf("\n");
	printf("**************************************\n");
	printf("After selection sorting by list:\n");
	selection_sort_by_list(first);
	for (i=0, cur = first; cur != NULL ; cur = cur->next,++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,cur->num, cur->description );
	}


	return 0;
}