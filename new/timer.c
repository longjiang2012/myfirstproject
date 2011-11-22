#include "timer.h"

int main( )
{
	int n = 0;
	struct list_head  *i;
	struct node 	*node_ptr, *list;
	struct list_head **j;

	//
	LIST_HEAD(head);
	list = (struct node*)malloc(sizeof(struct node) * 1000);
	

		//create 3 nodes
		create_node( &(list[n]), RETRY_TIME, n*n  , TIME_OUT );
		INIT_LIST_HEAD( &(list[n].list) );
		list_add_tail( &(list[n].list), &(head) );
		n++;
		create_node( &(list[n]), RETRY_TIME, n*n  , TIME_OUT );
		INIT_LIST_HEAD( &(list[n].list) );
		list_add_tail( &(list[n].list), &(head) );
		n++;
		create_node( &(list[n]), RETRY_TIME, n*n  , TIME_OUT );
		INIT_LIST_HEAD( &(list[n].list) );
		list_add_tail( &(list[n].list), &(head) );
		n++;

		//print node
		printf("-----\n");
  		list_for_each( i, &head ){
			node_ptr = list_entry( i, struct node, list);
			printf("%d \n", node_ptr->data);
		}
		printf("-----\n");
	
		//insert nodes
		i = &head;
		j = &i;
		insert_data_to_timer( &(list[0]) );
		insert_data_to_timer( &(list[1]) );
		insert_data_to_timer( &(list[2]) );

		//check timer
		timer( j ); 

	return 0;
}

