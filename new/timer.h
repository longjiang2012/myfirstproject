#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "list1.h"


struct node{
	struct list_head list;
	int sendflag;
	time_t time;
	int retry_times;
	int data;
};

void create_node(struct node* node_ptr, int retry_times, int data, int timeout)
{
	node_ptr->data = data;
	node_ptr->retry_times = retry_times;
	node_ptr->time = 0;
	node_ptr->sendflag = 0;

};

void  time_out_handler( struct node* ptr )
{

	printf("%d \n", ptr->data );
	ptr->retry_times--;
	ptr->time = time(NULL);
};

void insert_data_to_timer( struct node*  recv_data_node )
{
	recv_data_node->time = time(NULL);
};



void timer( struct list_head **pptr )
{
	time_t timer;
	double diftime;
	struct list_head *i;
	struct node *node_ptr;
	void  time_out_handler( struct node* ptr );
	void print_node_list( struct list_head **pptr );

	
	while(1){
		list_for_each( i, *pptr ){
			node_ptr = list_entry( i, struct node, list);
			if( node_ptr->sendflag ){ // data have sent!
				continue;
			}else{				//data still left
				if( node_ptr->retry_times > 0 ){
					timer = time(NULL);
					diftime = difftime(timer, node_ptr->time);
					if ( diftime <  TIME_OUT ){
						continue;
					}else{
						time_out_handler( node_ptr );
					}

				}else{
					list_del( &(node_ptr->list) );

					//test list_del();
						printf("-----\n");
					list_for_each( i, *pptr ){
						node_ptr = list_entry( i, struct node, list);
						printf("%d\n", node_ptr->data);
					}
				}
			}
		}
	}
};


void print_node_list( struct list_head **pptr )
{
	struct list_head *i;
	struct node *node_ptr;

	printf("-----\n");
	list_for_each( i, *pptr ){
		node_ptr = list_entry( i, struct node, list);
		printf("%d \n", node_ptr->data);
		sleep(2);
	}
	printf("-----\n");
};



