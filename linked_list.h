#include <cstdlib>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct linked_list linked_list;

struct linked_list{
	char *data;
	int index; /* normally not used with Linked Lists, just for exercise */
	struct linked_list *next;
	struct linked_list *prev;
};

int add_to_list(linked_list *ll, char *s);
    //Function will create a new list item and add that to end of list
    // *ll is pointing to head of the list
    //return: -1 as error (no space left), index position in success 

int display_item(linked_list *ll);
    //Displays the required element (pointed by parameter linked_list *ll) in a list
    //Return: -1 element not found , 0 ok
	
	
int display_list(linked_list *ll);
    //List all elements in a list
    //return: number of elements in list


linked_list * search_from_list(linked_list *ll, char *s);
   // Search for a data *s from a list
   // Return: NULL if not found, pointer to 


int delete_from_list(linked_list *ll, int index);
	//Delete item from a list and free space
	//Return value: -1 on error, length of remaining list

int empty_list(linked_list *ll);
    //remove all items from the list and will free allocated memory
    //return value items deleted from the list
	
int swap_items(linked_list *f, linked_list *s);
    //swap order of two items
    //return value
    //	0 in OK
    //  -1 if either items was not n the list (content of the list did not change)

int sort_list(linked_list *ll);
    //Sort list in rising order based on the data
	
int linkedlist_status(linked_list *ll);
    //will count the number of elements in the list
    //return value: amount

