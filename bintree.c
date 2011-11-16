#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int 

typedef struct node *tree_pointer;

typedef struct node {
	DATATYPE 	data;
	tree_pointer 	left_child, right_child;
	} *BinTree;


BinTree create( );
int isempty( BinTree  ptr_to_root );
BinTree makeBT( BinTree bt_left, DATATYPE data, BinTree bt_right );
BinTree	lchild( BinTree bt );
BinTree rchild( BinTree bt );
DATATYPE data( BinTree bt ); 
void inorder( tree_pointer ptr );
BinTree init_ptr_to_root();

BinTree create()
{
	struct node *ptr;

	ptr = (BinTree)malloc( sizeof(struct node) );
	ptr->left_child = NULL;
	ptr->right_child = NULL;
	ptr->data = 0;
}

int isempty( BinTree ptr_to_root )
{
	if ( ptr_to_root )
		return 1;
	return 0;
}

BinTree makeBT( BinTree bt_left, DATATYPE data, BinTree bt_right )
{
	struct node *ptr;

	ptr = (BinTree)malloc( sizeof(struct node) );
	ptr->left_child = bt_left;
	ptr->right_child = bt_right;
	ptr->data = data;
	return ptr;
}

BinTree lchild( BinTree bt )
{
	if ( isempty( bt ) ){
		return NULL;
	}else{
		return bt->left_child;
	}
}

BinTree rchild( BinTree bt )
{
	if ( isempty( bt ) ){
		return NULL;
	}else{
		return bt->right_child;
	}
}


DATATYPE data( BinTree bt ) 
{
	if ( isempty( bt ) ){
		return 0;
	}else{
		return bt->data;
	}
}


BinTree init_ptr_to_root( )
{
	struct node *ptr;
	ptr = NULL;

	return ptr;
}

void inorder( tree_pointer ptr )
{
	if ( ptr ) {
		inorder( ptr->left_child );
		printf("%d ", ptr->data);
		fflush( NULL);
		inorder( ptr->right_child );
	}
}

void preorder( tree_pointer ptr )
{
	if ( ptr ) {
		printf("%d ", ptr->data);
		preorder( ptr->left_child );
		preorder( ptr->right_child );
	}
}

void postorder( tree_pointer ptr )
{
	if ( ptr ) {
		postorder( ptr->left_child );
		postorder( ptr->right_child );
		printf("%d ", ptr->data);
	}
}


int main()
{
	struct node * ptr_to_root;
	struct node * left_child;
	struct node * left_left_child;
	struct node * left_right_child;
	struct node * right_child;
	struct node * right_left_child;
	struct node * right_right_child;


	//init root pointer;
	ptr_to_root = init_ptr_to_root( );

	
	left_left_child = makeBT( (BinTree)NULL , 3, (BinTree)NULL );	
	left_right_child = makeBT( (BinTree)NULL , 5, (BinTree)NULL );	
	right_right_child = makeBT( (BinTree)NULL , 6, (BinTree)NULL );	
	right_left_child = makeBT( (BinTree)NULL , 4, (BinTree)NULL );	

	left_child = makeBT( left_left_child , 1, left_right_child );	
	right_child = makeBT( right_left_child, 2, right_right_child );

	//create a root node;
	ptr_to_root = makeBT( left_child, 0, right_child );
	//show the bintree;	
	inorder( ptr_to_root );
	printf("\n");
	preorder( ptr_to_root );
	printf("\n");
	postorder( ptr_to_root );
	printf("\n");

	return 0;
}



	



	








