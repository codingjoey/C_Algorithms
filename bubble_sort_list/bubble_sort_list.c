#include "bubble_sort_list.h"
#include <string.h>
#include "../bool/bool.h"


void swap(struct data_list*cur, struct data_list*cur_next){
	int num_temp=0;
	char str_temp[50];
	num_temp = cur->num;
	strcpy(str_temp, cur->description);
	cur->num = cur_next->num;
	strcpy(cur->description, cur_next->description);
	cur_next->num = num_temp;
	strcpy(cur_next->description, str_temp);
}

void bubble_sort_by_list(struct data_list* first){
	struct data_list *cur;
	BOOL isSwap = FALSE;

	do{
		isSwap = FALSE;
		for(cur=first; cur->next!=NULL;cur=cur->next){
			if (cur->num > cur->next->num)
			{
				swap(cur, cur->next);
				isSwap=TRUE;
			}
		}
	}while(isSwap);
	
}

