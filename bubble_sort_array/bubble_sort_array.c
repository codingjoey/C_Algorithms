#include "bubble_sort_array.h"
#include <string.h>

void bubble_sort(struct Data_unit *p_data_array, int array_size){
	char str_temp[STR_LENGTH]={0};
	int  num_temp=0;

	for (int i = 0; i < array_size-1; ++i)
	{
		for (int j = 0; j < array_size-1-i; ++j)
		{
			if (p_data_array[j].num > p_data_array[j+1].num)
			{
				strcpy(str_temp, p_data_array[j+1].description);
				num_temp = p_data_array[j+1].num;

				strcpy(p_data_array[j+1].description, p_data_array[j].description);
				p_data_array[j+1].num = p_data_array[j].num;

				strcpy(p_data_array[j].description, str_temp);
				p_data_array[j].num = num_temp;
			}
		}
	}
}