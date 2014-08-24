#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_processing.h"


struct Data_unit* extendSize(struct Data_unit *p_data_array, int * p_size_current){
	int new_size = 2 * *p_size_current;
	struct Data_unit *p_new_data_array = (struct Data_unit *)malloc(new_size*sizeof(struct Data_unit));
	if (p_new_data_array==NULL)
	{
		fprintf(stderr, "Can't allocate memory for p_new_data_array\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < *p_size_current; ++i)
	{
		p_new_data_array[i] = p_data_array[i];
	}

	*p_size_current = new_size;
	free(p_data_array);
	p_data_array=NULL;
	return p_new_data_array;
}

struct Data_unit* read_line(char * filename, int *p_size_array){
	FILE * fp_source = fopen(filename, "r+");
	if (fp_source==NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	struct Data_unit *p_data_array = (struct Data_unit *)malloc(ARRAY_SIZE*sizeof(struct Data_unit));
	if (p_data_array==NULL)
	{
		fprintf(stderr, "Can't allocate memory for p_data_array\n");
		exit(EXIT_FAILURE);
	}

	int size_current=ARRAY_SIZE;
	int size_count=0;
	char * str=(char *)malloc(STR_LENGTH*sizeof(char));

	while((fgets(str, STR_LENGTH*sizeof(char), fp_source))!=NULL){
		if (size_count==size_current)
		{
			int *p_size_current = &size_current;
			p_data_array = extendSize(p_data_array, p_size_current);
		}
		//printf("text:  %s\n",str);//testing
		struct Data_unit data;
		if(sscanf(str, "%d %s",&data.num, data.description)!=2)
			continue;
		
		//printf("Store into Struct, num=%d, description=%s\n",data.num, data.description);//testing
		//p_data_array[size_count].num = data.num;
		//strcpy(p_data_array[size_count].description, data.description);
		p_data_array[size_count]=data;
		size_count++;
	}
	
	*p_size_array = size_count;
	fclose(fp_source);
	return p_data_array;
}

//Testing
/*int main(int argc, char const *argv[])
{
	if (argc!=2)
	{
		fprintf(stderr, "usage:data_processing filename\n");
		exit(EXIT_FAILURE);
	}
	int size_array=0;
	int *p_size_array = &size_array;
	//printf("filename=%s\n",argv[1]);//testing
	struct Data_unit* p_data_array = read_line((char *)argv[1],p_size_array);
	for (int i = 0; i < *p_size_array; ++i)
	{
		printf("%d element: num=%d, description=%s\n",i+1,p_data_array[i].num, p_data_array[i].description );
	}
	return 0;
}*/