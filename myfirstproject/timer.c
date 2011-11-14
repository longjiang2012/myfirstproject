#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list1.h"


struct node{
	struct list_head list;
	int sendflag;
	int timeout;
	int retry_times;
	int data;
};

void create_node(struct node* node_ptr, int retry_times, int data, int timeout)
{
	node_ptr->data = data;
	node_ptr->retry_times = retry_times;
	node_ptr->timeout = timeout;
	node_ptr->sendflag = 0;

}

int main( )
{
	int n = 0;
	struct list_head  *i;
	struct node 	*node_ptr, *list;

	//declear list head;    
	LIST_HEAD(head);
	//insert from head
	list = (struct node*)malloc(sizeof(struct node) * 10);
	

	while( 1 ){	
		//create 2 node 
		create_node( &(list[n]), RETRY_TIME, n, TIME_OUT );
		INIT_LIST_HEAD( &(list[n].list) );
		list_add( &(list[n].list), &(head) );
		n++;
		create_node( &(list[n]), RETRY_TIME, n, TIME_OUT );
		INIT_LIST_HEAD( &(list[n].list) );
		list_add( &(list[n].list), &(head) );
		n++;

		//print node
  		list_for_each( i, &head ){
			node_ptr = list_entry( i, struct node, list);
			printf("%d \n", node_ptr->data);
		}
		printf("-----\n");

		//timer
		sleep(3);

		//node n-1 has been sent.
		list[n-1].sendflag = 1;
		list_del( &(list[n-1].list) );
		
		//check node
		list_for_each( i, &head ){
			node_ptr = list_entry( i, struct node, list);
			if( node_ptr->sendflag == 0 ){
				if ( node_ptr->retry_times == 0 ){
					//del the node
					list_del( &(node_ptr->list) );
					break;
				}
				node_ptr->retry_times--;
				printf("%d\n", node_ptr->data);
			}
			
		}
		printf("-----\n");
	}

	return 0;
}

