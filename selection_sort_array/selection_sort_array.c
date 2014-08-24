#include "selection_sort_array.h"
#include "string.h"
#include "stdio.h"
#include "../bool/bool.h"

BOOL less_than(int, int);
void swap(struct Data_unit *, int, int);

void selection_sort(struct Data_unit *p_data_array, int array_size){
	for (int i = 0; i < array_size; ++i)
	{
		int min = i;
		for (int j = i+1; j < array_size; ++j)
		{
			if (less_than(p_data_array[j].num, p_data_array[min].num))
			{
				min = j;
			}
		}
		swap(p_data_array, i, min);
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

void swap(struct Data_unit *p_data_array, int i, int j){
	if (i==j)
	{
		return;
	}
	char str_temp[STR_LENGTH]={0};
	int  num_temp=0;

	strcpy(str_temp, p_data_array[i].description);
	num_temp = p_data_array[i].num;

	strcpy(p_data_array[i].description, p_data_array[j].description);
	p_data_array[i].num = p_data_array[j].num;

	strcpy(p_data_array[j].description, str_temp);
	p_data_array[j].num = num_temp;
}