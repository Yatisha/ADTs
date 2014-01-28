#ifndef _LIST_H
#define _LIST_H
	typedef struct lnode lnode;
	typedef lnode * lnodeptr;

	struct lnode
	{
        int elem;
        lnodeptr nextptr;
	};
	
	void list_push(lnodeptr *, int);

	void list_pop(lnodeptr *); 

	void list_delete(lnodeptr *);

	int list_length(const lnodeptr);



#endif
