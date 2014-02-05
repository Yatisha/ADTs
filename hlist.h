#ifndef _HLIST_H
#define _HLIST_H

	typedef struct hashmap_node hnode;
	typedef hnode * hnodeptr;
	
	struct hashmap_node
	{
			char * key;
        	int elem;
        	hnodeptr nextptr;
	};
	
	int  hlist_search(hnodeptr * p,char * key);
	void hlist_push(hnodeptr *ptr,int num,char * key);
	int  hlist_length(const hnodeptr p);
	void hlist_delete(hnodeptr * p);
	void hlist_pop(hnodeptr * p);
	void  hlist_delete_node(hnodeptr * p,char *key);
	void  hlist_delete_tail(hnodeptr * p);
	void  hlist_delete_head(hnodeptr * p);

#endif
