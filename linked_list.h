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
    //Search for a data *s from a list
    //Return: NULL if not found, pointer to 
		
int delete_from_list(linked_list *ll, int index);
	//Delete item from a list and free space
	//Return value: -1 on error, length of remaining list
