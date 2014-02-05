#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "hlist.h"
	int hash_func(char * key);

	hnodeptr * create_map();

	void map_add( hnodeptr * h, char * key, int value);

	int obtain_value(hnodeptr * h ,char * key);

	void remove_key(hnodeptr * h ,char * key);

#endif
