/*

	Description: Implementation of hashmap
	Author:Yatisha Raul
	Email:yatisharaul@gmail.com
	Version: 0


*/



#include<stdio.h>
#include<stdlib.h>
#include "hlist.h"
#include "hashmap.h"

#define ARRAY_SIZE 24

hnodeptr * create_map()
{
	hnodeptr * h = (hnodeptr *)calloc(ARRAY_SIZE,sizeof(hnodeptr));
	return h;		
}


void map_add( hnodeptr * h, char * key, int value)
{
	int index = hash_func(key);
	//printf("%p",*(h+index));
	hlist_push(&(h[index]),value,key);
	
}


int hash_func(char * key)
{
	int sum = 0; int i = 0;
	while(*(key+i)!='\0')
	{
		sum = sum + (int)(key[i]);
		i++;
	}
	int hash = (sum % ARRAY_SIZE);
	return hash;	

}

int obtain_value(hnodeptr * h ,char * key)
{
	int index = hash_func(key);
	hlist_search(h+index,key);
}

void remove_key(hnodeptr * h ,char * key)
{
	int index = hash_func(key);
	hlist_delete_node(h+index,key);
	
}



