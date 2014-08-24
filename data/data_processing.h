#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#define ARRAY_SIZE 10
#define STR_LENGTH 50
struct Data_unit
{
	int num;
	char description[20];
};

struct Data_unit* read_line(char * filename,int *p_size_array);

#endif