/*

	Description: Implementation of singly-linked list
	Author:Yatisha Raul
	Email:yatisharaul@gmail.com
	Version: 0


*/


#include <string.h>
#include "hlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "hlist.h"



void hlist_push(hnodeptr *ptr,int num,char * key)
{
        hnodeptr temp = *ptr;	//assign temporary pointer to head
        if(temp == NULL){
                temp = (hnodeptr)malloc(sizeof(hnode)); //create node
                if(temp == NULL)
                        return;
                                        
                else{
                        (temp)->elem = num;
						(temp)->key = key;
                        (temp)->nextptr = NULL;
                        *ptr = temp; 
                }
        }
        else{
        
                while(temp->nextptr != NULL){
                	temp = temp->nextptr;
                }

                hnodeptr temp2 = (hnodeptr)malloc(sizeof(hnode));
				(temp2)->key = key;
				(temp2)->elem = num;
        	    (temp2)->nextptr = NULL;
                temp->nextptr = temp2;
                   
        }
}




int hlist_length(const hnodeptr p)
{

	hnodeptr temp = p;

	if(temp==NULL){
		return 0;
	}else{

		int i;
		hnodeptr temp2 = p;
		for(i=0;(temp2) != NULL;temp2 = temp2->nextptr){i++;}
		return i;
	}
}

void hlist_delete(hnodeptr * p)
{
	if(p == NULL){
		printf("list is empty");
	}else if((*p) == NULL){
		printf("list is empty");
	}else{
		int i=0;
		for(i=0; i <=hlist_length(*p);i++)
		{
			hlist_pop(p);
		}
		free(*p);
		*p = NULL;
	}

}

void hlist_pop(hnodeptr * p)
{
	hnodeptr temp3 = (*p);
	if(p=NULL){

		return;

	}
	else if(temp3==NULL){

		return;

	}
	else{

		while(((temp3->nextptr)->nextptr)!= NULL)
		{
                (temp3) = (temp3)->nextptr;
        }

        hnodeptr temp4 = temp3->nextptr;
        free(temp4);
        temp4 = NULL;
        temp3->nextptr = NULL;
		
	}
}

int  hlist_search(hnodeptr * p,char * key)
{
	hnodeptr temp = *p;
	int flag=0;
	if(temp==NULL)
	{
		return -1;
	}

	while(temp != NULL){
		if(strcmp((temp->key), key) == 0){
			flag=1;
			return temp->elem;
		}else{
			temp = temp->nextptr;
		}
	}
	if(!flag){
		return -1;
	}
}


void  hlist_delete_head(hnodeptr * p)
{
	hnodeptr temp = *p;
	*p=temp->nextptr;
	free(temp);
	temp=NULL;	
}

void  hlist_delete_tail(hnodeptr * p)
{
	hnodeptr temp = *p;
	while((temp->nextptr)->nextptr!= NULL)
	{
			free(temp->nextptr);
			temp->nextptr= NULL;
	}
	
}

void  hlist_delete_node(hnodeptr * p,char * key)
{
	hnodeptr temp = *p;
	int flag=0;
	if(temp==NULL)
	{
		return ;
	}
	if(strcmp((temp->key),key)==0)
	{
		hlist_delete_head(p);
		return;

	}else{
		while(temp->nextptr != NULL)
		{

			if(strcmp((temp->nextptr)->key,key)==0){
				hnodeptr temp2 = temp->nextptr;
				temp->nextptr = temp2->nextptr;
				free(temp2);
				temp2 = NULL;
				return;
			}else{
				temp = temp->nextptr;
			}
		}

		if(strcmp((temp->key),key)==0){
			hlist_delete_tail(p);
			return;
		}
	}
	
}
