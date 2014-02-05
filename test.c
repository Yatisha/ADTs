
#include <stdio.h>
#include <stdlib.h>
#include "hlist.h"
#include "hashmap.h"

void main()
{
	hnodeptr * hmap=create_map();
	int i;
	
	map_add(hmap,"john",60);
	printf("%d",hash_func("john"));
	map_add(hmap,"lenon",70);	
	map_add(hmap,"paul",35);
	printf("%d \n",obtain_value(hmap,"john"));
	remove_key(hmap,"lenon");
	remove_key(hmap,"john");
}