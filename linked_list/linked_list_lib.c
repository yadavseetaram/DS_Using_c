#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
Linked_list createList(){
	Linked_list list;
	list.head=NULL;
	list.tail=NULL;
	list.length =0;
	return list;
}
int add_to_list(Linked_list *list ,void *value){
	Element *e= (Element *)malloc(sizeof(Element));
	e->value = value;
	e->next= NULL;
	if(list->length == 0){
		list->head = list->tail = e;
	}
	else{
		list->tail->next = e;
		list->tail = e;
	}	
	list->length +=1;
	return list->length;
}

void *get_first_element(Linked_list list){
	return list.head->value;
}
void *get_last_element(Linked_list list){
	return list.tail->value;
}

void forEach(Linked_list list,ElementProcessor e){
	for(int i=0;i<list.length;i++){
		e(list.head->value);
		list.head = list.head->next;
	}
}	

void *getElementAt(Linked_list list, int index){
  for(int i=0;i<list.length;i++){
  	if(i==index)
      return list.head;
  	list.head = list.head->next;
  }
  return NULL;
}

int indexOf(Linked_list list, void *value){
	int i;
  for(i=0;i<list.length;i++){
    if(memcmp(list.head->value,value,sizeof(value))==0){
    	return i;
    }
    list.head=list.head->next;
  }
  return -1;
}

void *deleteElementAt(Linked_list *list, int index){
	Element *temp = list->head;
	if(index==0){
		list->head=temp->next;
		free(temp);
		list->length--;
		return list;
	}
	if(index==list->length-1){
		temp = getElementAt(*list,index-1);
		list->tail=temp;
		list->tail->next=NULL;
		list->length--;
		free(temp);
		return list;
	}
	else{
		Element *prev = getElementAt(*list,index-1);
		Element *ele =  getElementAt(*list,index);
		prev->next=ele->next;
		list->length--;
		free(ele);
		return list;
	};
	
	return NULL;
};
