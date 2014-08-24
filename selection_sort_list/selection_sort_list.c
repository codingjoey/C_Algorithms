#include "selection_sort_list.h"
#include <string.h>
#include "../bool/bool.h"

BOOL less_than(int, int);
void swap(struct data_list*, struct data_list*);

void selection_sort_by_list(struct data_list* first){
	struct data_list *cur, *min, *inner_cur;

	for(cur=first; cur!=NULL && cur->next!=NULL;cur=cur->next){
		min = cur;
		for (inner_cur = cur->next; inner_cur!=NULL; inner_cur = inner_cur->next)
		{
			if (less_than(inner_cur->num, min->num))
			{
				min = inner_cur;
			}
		}
		if (min!=cur)
		{
			swap(min, cur);
		}
	}
}

BOOL less_than(int a, int b){
	if (a<b)
	{
		return TRUE;
	}else{
		return FALSE;
	}
}

void swap(struct data_list *pa, struct data_list *pb){
	char temp_str[50];
	int temp_num;
	temp_num = pa->num;
	strcpy(temp_str, pa->description);
	pa->num = pb->num;
	strcpy(pa->description, pb->description);
	pb->num = temp_num;
	strcpy(pb->description, temp_str);
}