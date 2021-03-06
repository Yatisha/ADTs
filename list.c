/*

	Description: Implementation of singly-linked list
	Author:Yatisha Raul
	Email:yatisharaul@gmail.com
	Version: 0


*/



#include "list.h"
#include <stdio.h>
#include <stdlib.h>



void list_push(lnodeptr *ptr,int num)
{
        lnodeptr temp = *ptr;	//assign temporary pointer to head
        if(temp == NULL){
                temp = (lnodeptr)malloc(sizeof(lnode)); //create node
                if(temp == NULL)
                        printf("failure");
                                        
                else{
                        (temp)->elem = num;
                        (temp)->nextptr = NULL;
                        *ptr = temp; 
                }
        }
        else{
        
                while(temp->nextptr != NULL){
                	temp = temp->nextptr;
                }

                lnodeptr temp2 = (lnodeptr)malloc(sizeof(lnode));
				(temp2)->elem = num;
                (temp2)->nextptr = NULL;

                temp->nextptr = temp2;
                   
        }
}




int list_length(const lnodeptr p)
{

	lnodeptr temp = p;

	if(temp==NULL){
		return 0;
	}else{

		int i;
		lnodeptr temp2 = p;
		for(i=0;(temp2) != NULL;temp2 = temp2->nextptr){i++;}
		return i;
	}
}

void list_delete(lnodeptr * p)
{
	if(p == NULL){
		printf("list is empty");
	}else if((*p) == NULL){
		printf("list is empty");
	}else{
		int i=0;
		for(i=0; i <=list_length(*p);i++)
		{
			list_pop(p);
		}
		free(*p);
		*p = NULL;
	}

}

void list_pop(lnodeptr * p)
{
	lnodeptr temp3 = (*p);
	if(p=NULL){

		printf("list is empty cant pop");

	}
	else if(temp3==NULL){

		printf("list is empty cant pop");

	}
	else{

		/*lnodeptr temp3 = *p;*/ /*why does this give segmentation fault*/
		while(((temp3->nextptr)->nextptr)!= NULL)
		{
                (temp3) = (temp3)->nextptr;
        }

        lnodeptr temp4 = temp3->nextptr;
        free(temp4);
        temp4 = NULL;
        temp3->nextptr = NULL;
		
	}
}

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