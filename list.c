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
        
                while(temp != NULL){
                	temp = temp->nextptr;
                }

                temp = (lnodeptr)malloc(sizeof(lnode));
				(temp)->elem = num;
                (temp)->nextptr = NULL;
          
             
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
	}else{
		int i=0;
		for(i=0; i < list_length(*p);i++)
		{
			list_pop(p);
		}
	}
}

void list_pop(lnodeptr * p)
{
	if(p=NULL){
		printf("list is empty cant pop");
	}else{

		lnodeptr temp;
		while(temp->nextptr != NULL){}
		temp=NULL;
		free(temp);
	}
}

int main(void)
{
	
	lnodeptr head = NULL;
	list_push(&head,5);
	list_push(&head,6);
	list_push(&head,7);
	list_push(&head,8);
	printf("%p",(head->nextptr));
	printf("%d",list_length(head));
	return 0;
}