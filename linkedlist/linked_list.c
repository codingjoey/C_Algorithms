#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct data_list * insert(struct data_list *first, int num, char *description){
	struct data_list *new_element;

	new_element = (struct data_list*)malloc(sizeof(struct data_list));
	if (new_element==NULL)
	{
		fprintf(stderr, "error to allocate memory for insert new element to list!\n");
		exit(EXIT_FAILURE);
	}
	new_element->num = num;
	strcpy(new_element->description, description);
	new_element->next = first;
	return new_element;
	
}

struct data_list * convertArrayToList(struct data_list *first, struct Data_unit *p_data_array, int array_size){
	for (int i = 0; i < array_size; ++i)
	{
		first = insert(first, p_data_array[i].num, p_data_array[i].description);
	}
	return first;
}
//struct data_list * find(struct data_list *first, int num);

//Testing
/*int main(int argc, char const *argv[])
{
	if (argc!=2)
	{
		fprintf(stderr, "usage:linked_list filename\n");
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

	printf("**************************************\n");
	printf("\n");
	printf("Convert this array into unsorted linked list:\n");
	struct data_list *first = NULL;
	first = convertArrayToList(first, p_data_array, *p_size_array);
	struct data_list *cur;
	int i;
	for (i=0, cur = first; cur != NULL ; cur = cur->next,++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,cur->num, cur->description );
	}
	return 0;
}
*/