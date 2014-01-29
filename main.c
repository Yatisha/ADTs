#include  "list.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	
	lnodeptr head;
	printf("%p",head);
	list_push(&head,5);
	printf("%d \n",head->elem);
	list_push(&head,6);
	printf("%d \n",(head)->elem);
	list_push(&head,7);
	printf("%d \n",((head)->elem));
	list_push(&head,8);
	printf("%d \n",((head)-> nextptr)->elem);
	printf("%d",list_length(head));
	list_pop(&head);
	printf("%d",list_length(head));
	list_delete(&head);
	printf("%d",list_length(head));
	printf("%p",head);
	return 0;
}
