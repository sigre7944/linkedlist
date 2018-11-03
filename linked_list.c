#include "linked_list.h"


int add_to_list(linked_list *ll, char *s)
{
	if (!s) return -1;// Check if null pointer
	
	linked_list *list0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for searching
	linked_list *next_list = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for adding
	list0 = ll;
	
	while(list0 -> next != NULL) //until there's no next
	{	
		list0 = list0->next;
	}
	
	next_list-> index = ((list0->index) +1);
	next_list-> data = s;
	next_list-> next = NULL;
	list0 -> next = next_list;
	
	return next_list-> index;
}


int display_item(linked_list *ll)
{
	printf("\nData: %s\n", ll->data); 
	printf("Index: %d\n", ll->index); 
	printf("Next: %d\n", &(ll->next)); //print next address 
	return 0;
}

int display_list(linked_list *ll)
{
	linked_list *list0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for searching
	list0 = ll;
	
	while(list0 -> next != NULL) //until there's no next
	{	
		display_item(list0);
		list0 = list0->next;
	}
	
	return 0;
}

linked_list * search_from_list(linked_list *ll, char *s)
{
	linked_list *null{0};
	if (!s) return null;// Check if null pointer
	
	linked_list *list0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for searching
	list0 = ll;
	
	while(list0 -> next != NULL) //until there's no next
	{	
		if ((strcmp (list0 -> data,s))==0)  //if two strings are equal
		{
			return list0;
		}
		list0 = list0->next;
	}
	
	return null;
	
}

		
int delete_from_list(linked_list *ll, int index)
{
	if (!ll) return -1;// Check if null pointer
	int count = 1; //count for finding the delete and for reducing the index
	
	linked_list *list0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for storing the head node
	list0 = ll; 
	linked_list *listcount = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for counting
	listcount = ll; 
	int length=1;
	
	
	while(listcount -> next != NULL) //until there's no next
	{	
	length ++;
	listcount = listcount->next;	
	}	
	
	if (index >= length)
	{
		return -1;
	}
	
	if (count == 0 && length == 1) //if delete the only value
	{
		ll -> data = NULL;
	}
	
	//display_list(list0);
	
	while(ll -> next != NULL) //until there's no next
	{	
		count ++;
		if (ll -> next -> index == index)  //if the next link is to be deleted
		{

			if (ll -> next -> next == NULL)
			{
				ll -> next = NULL;
			}
			else
			{
				ll->next = ll->next->next; //skip one step
				ll = ll->next; //go to the next to start minus 1 all index
			}
			break;
		}
	ll = ll->next;	
	}	
	
	while(ll -> next != NULL)
	{
	count ++;
	ll->index -= 1;
	ll = ll->next;	
	}
	
	ll=list0;
	//display_list(ll);
	
	
	return count;

}

int empty_list(linked_list *ll){
	if (!ll) return -1;// Check if null pointer
	int count = 1; //count the number of items that will be deleted
	
	linked_list *list0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for storing the head before realeasing it
	 
	
	while(ll -> next != NULL) //until there's no next
	{	
	list0 = ll;
	count ++;
	free(ll);
	ll = list0->next;
	}	
	
	return count;
}

int swap_items(linked_list *f, linked_list *s) {
	if (!f) return -1;// Check if null pointer
	if (!s) return -1;// Check if null pointer
	int same = 0; //check if s is from same linked list as f
	char *data_store; //for storing data
	int index_store; //for storing index
	
	linked_list *f0 = (struct linked_list*) malloc(sizeof(linked_list)); //initialize for checking if s is from the same link list as f
	linked_list *s0 = (struct linked_list*) malloc(sizeof(linked_list));
	
	f0 = s;
	
	while(f0 -> next != NULL ) //until there's no next
	{	
	if (f0 == s) //check if s is in the same linked list as f
	{
		same = 1;
		break;
	}
	f0 = f0 -> next;
	}	
	
	while(s0 -> next != NULL ) //until there's no next
	{	
	if (s0 == f) //check if f is in the same linked list as s
	{
		same = 1;
		break;
	}
	s0 = s0 -> next;
	}	
	
	if (same == 0) //if f and s are from different linked list
	{
		return -1;
	}
	
	index_store = f->index;
	data_store = f->data;
	
	f->
}
