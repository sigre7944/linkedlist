#include <gtest/gtest.h>
#include "linked_list.h"

/***************************************************************************/
TEST(add_to_list,normal) 
{
   
	char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(head,str6);
    EXPECT_EQ(6,i);

}

/***************************************************************************/
TEST(add_to_list,null_pointer) 
{
    char *str{0};

    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL; 
	head->prev=NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str);
    EXPECT_EQ(-1,i);
	
}

/***************************************************************************/
TEST(display_item,add_to_list)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(head->next->index,1);
    EXPECT_EQ(i,1);
    EXPECT_STREQ(head->next->data,str1);

    i=add_to_list(head,str2);
   // display_list(head);
    EXPECT_EQ(head->next->next->index,2);
    EXPECT_EQ(i,2);
    EXPECT_STREQ(head->next->next->data,str2);

    i=add_to_list(head,str3);
   // display_list(head);
    EXPECT_EQ(head->next->next->next->index,3);
    EXPECT_EQ(i,3);
    EXPECT_STREQ(head->next->next->next->data,str3);

    i=add_to_list(head,str4);
   // display_list(head);
    EXPECT_EQ(head->next->next->next->next->index,4);
    EXPECT_EQ(i,4);
    EXPECT_STREQ(head->next->next->next->next->data,str4);

    i=add_to_list(head,str5);
   // display_list(head);
    EXPECT_EQ(head->next->next->next->next->next->index,5);
    EXPECT_EQ(i,5);
    EXPECT_STREQ(head->next->next->next->next->next->data,str5);

    i=add_to_list(head,str6);
    display_list(head);
    EXPECT_EQ(head->next->next->next->next->next->next->index,6);
    EXPECT_EQ(i,6);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);

}

/***************************************************************************/
TEST(search,normal)
{
    char str[15]="List Start";
    char str1[15]="second";
    char str2[15]="third";

    linked_list *found;
    struct linked_list *head;

    head = (struct linked_list*) malloc(sizeof(linked_list));
	head->prev=NULL; 
    head->data=str;
    head->index=0;


    head->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->data=str1;
    head->next->index=1;

    head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->next->index=2;
    head->next->next->data=str2;

    head->next->next->next->next = NULL;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ(found->index,2);
    EXPECT_STREQ(str2,found->data);
}

/***************************************************************************/
TEST(search,not_found)
{
    char str[15]="List Start";

    linked_list *found;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    found=search_from_list(head,(char *)"third");

    EXPECT_EQ((int *)found,(int *)NULL);
}

/***************************************************************************/
TEST(display_list,empty)
{
    int result;
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    display_list(head);

}

/***************************************************************************/
TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;


    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;



    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    display_list(head);
}

/***************************************************************************/
TEST(delete,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
	int del;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;
	

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

	display_list(head);
    del = delete_from_list(head,2);
	display_list(head);
	
	EXPECT_EQ(del,6);
	EXPECT_EQ(head->next, head->next->next->prev);
	EXPECT_STREQ(str3,head->next->next->data);

}

/***************************************************************************/
TEST(delete,multi) 
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);

    for(i=0; i<40; i++)
        add_to_list(head,str1);

	EXPECT_EQ(delete_from_list(head,12),46);
    EXPECT_EQ(delete_from_list(head,22),45);
	EXPECT_EQ(delete_from_list(head,25),44);
	EXPECT_EQ(delete_from_list(head,32),43);
	EXPECT_EQ(delete_from_list(head,38),42);
	
	EXPECT_EQ(delete_from_list(head,380),-1);
	
}

/***************************************************************************/
TEST(empty,normal) 
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
	EXPECT_EQ(empty_list(head),7);
	
}

/***************************************************************************/
TEST(empty,single_value) 
{
    char str[15]="List Start";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

	EXPECT_EQ(empty_list(head),1);
	
}

/***************************************************************************/
TEST(empty,null_pointer) 
{
	linked_list *head ={0};
	
	EXPECT_EQ(empty_list(head),-1);
	
}

/***************************************************************************/
TEST(swap,normal) 
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
    add_to_list(head,str3);

	
	EXPECT_EQ(swap_items(head->next, head->next->next), 0);
	EXPECT_STREQ(str2, head->next->data);
	
}

/***************************************************************************/
TEST(swap,not_in_the_list) 
{
    char str[15]="List Start";
    char str1[10]="zero";
  
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  
	linked_list *head1 = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

	head1->next=NULL;
	head1->prev=NULL; 
    head1->data=str1;
    head1->index=0;

	EXPECT_EQ(swap_items(head, head1), -1);
	
}

/***************************************************************************/
TEST(swap,null_pointer) 
{
	linked_list *head ={0};
	linked_list *head1 ={0};
	
	EXPECT_EQ(swap_items(head, head1),-1);
	
}

/***************************************************************************/
TEST(sort,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);
    
	EXPECT_EQ(sort_list(head),0);
	EXPECT_STREQ(str, head->data);
	EXPECT_STREQ(str6, head->next->data);
	EXPECT_STREQ(str2, head->next->next->data);

    //display_list(head);

}

/***************************************************************************/
TEST(sort,sorted_invertedly)
{
    char str[15]="fff";
    char str1[10]="eee";
    char str2[10]="ddd";
    char str3[10]="ccc";
    char str4[10]="bbb";
    char str5[10]="aaa";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);

    EXPECT_EQ(sort_list(head),0);
	EXPECT_STREQ(str5, head->data);
	EXPECT_STREQ(str4, head->next->data);
	EXPECT_STREQ(str3, head->next->next->data);
	EXPECT_STREQ(str2, head->next->next->next->data);
	
    //display_list(head);

}


/***************************************************************************/
TEST(sort,null_pointer)
{
	linked_list *head ={0};
	
	EXPECT_EQ(sort_list(head),-1);
	
}

/***************************************************************************/
TEST(status,normal)
{
	char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
	
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list)); 
	
	head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;

    add_to_list(head,str1);
    add_to_list(head,str2);
    add_to_list(head,str3);
    add_to_list(head,str4);
    add_to_list(head,str5);
	
	EXPECT_EQ(linkedlist_status(head),6);
	
}

/***************************************************************************/
TEST(status,one_element)
{
	char str[15]="List Start";
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list)); 
	
	head->next=NULL;
	head->prev=NULL; 
    head->data=str;
    head->index=0;
	
	EXPECT_EQ(linkedlist_status(head),1);
	
}

/***************************************************************************/
TEST(status,null_pointer)
{
	linked_list *head ={0};
	
	EXPECT_EQ(linkedlist_status(head),0);
	
}




