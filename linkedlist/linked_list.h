#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../bool/bool.h"
#include "../data/data_processing.h"
#define DISCRIPTION_LEN 20
struct data_list
{
	int num;
	char description[DISCRIPTION_LEN];
	struct data_list *next;
};


struct data_list * insert(struct data_list *first, int num, char *description);
//struct data_list * find(struct data_list *first, int num);
struct data_list * convertArrayToList(struct data_list *first, struct Data_unit *p_data_array, int array_size);
//BOOL search(struct data_list *first);


#endif