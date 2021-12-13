/**
 * @file	generic_tree.h
 * @author	Simone Arcari
 *
 * @abstract	header file
 * @discussion	This file contains the definitions of the structs and functions
 *		needed to work with tree data structures.
 */



#ifndef GENERIC_TREES_H_
#define GENERIC_TREES_H_



/**
 * @typedef	tree_t
 *		Contains all node properties. Each node stores information and 
 *		has pointers to be linked to the other nodes to form a tree 
 *		structure.
 *
 * @field	data	information that the node stores
 * @field	parent	link to the parent node
 * @field	child	link to the first child node
 * @field	sibling	link to the right brother node
*/
typedef struct tree {
	int data;
	struct tree *parent;
	struct tree *child;
	struct tree *sibling;
}tree_t;


/**
 * @typedef	stack_t
 *		Contains all stack properties. The structure is that of a node
 *		in a list, but designed to be of the LIFO type only.
 *
 * @field	tree	information that the node stores (it's a stack of trees)
 * @field	next	link to the next node in list
*/
typedef struct stack{
	tree_t *tree;
	struct stack *next;
}stack_t;

/**
 * @typedef	queue_t
 *		Contains all queue properties. The structure is that of a node
 *		in a list, but designed to be of the FIFO type only.
 *
 * @field	tree	information that the node stores (it's a queue of trees)
 * @field	next	link to the next node in list
*/
typedef struct queue {
	tree_t *tree;
	struct queue *next;
}queue_t;



/* FUNCTIONS FOR THE STACK STRUCTURE */

/**
 * @function    create_stack
 * @abstract    Allocates a data structure of type stack.
 * @discussion  Allocates a pointer to stack_t (* tail) in the heap and returns
 *		the pointer to pointer to stack_t (** tail).
 *		
 * @param 	void	No parameters.
 * @result	A double pointer to stack.
*/
stack_t **create_stack(void);

/**
 * @function    push
 * @abstract    Push the data on the stack.
 * @discussion  Always inserts a node at the top, it's like normal insertion in
 *		the head for the lists.
 *		
 * @param 	top	Double pointer to stack.
 * @param 	T	Tree to be inserted on top.
 * @result 	A pointer to new node pushed.
*/
stack_t *push(stack_t **top, tree_t *T);

/**
 * @function    pop
 * @abstract    Pop the data on the stack.
 * @discussion  Always takes a node at the top, it's like normal remove from
 *		the head for the lists.
 *		
 * @param 	top	Double pointer to stack.
 * @result 	A pointer to the extracted node, if empty return NULL.
*/
tree_t *pop(stack_t **top);



/* FUNCTIONS FOR THE QUEUE STRUCTURE */

/**
 * @function    create_queue
 * @abstract    Allocates a data structure of type queue.
 * @discussion  Allocates a pointer to queue_t (* head) in the heap and returns
 *		the pointer to pointer to queue_t (** head).
 *		
 * @param 	void	No parameters.
 * @result	A double pointer to queue.
*/
queue_t **create_queue(void);

/**
 * @function    enqueue
 * @abstract    Puts the data at the end of the queue structure.
 * @discussion  Always inserts a node at the end, it's like normal insertion in
 *		the tail for the lists.
 *		
 * @param 	head	Double pointer to queue.
 * @param 	T	Tree to be inserted in the queue.
 * @result 	A pointer to new node inserted.
*/
queue_t *enqueue(queue_t **head, tree_t *T);

/**
 * @function    dequeue
 * @abstract    Puts the data at the end of the queue structure.
 * @discussion  Always takes a node at the head, it's like normal remove from
 *		the head for the lists.
 *		
 * @param 	head	Double pointer to queue.
 * @result 	A pointer to the extracted node, if empty return NULL.
*/
tree_t *dequeue(queue_t **head);



/* FUNCTIONS FOR THE TREE STRUCTURE */
tree_t *Tree(int val);

tree_t *insert_child(tree_t *P, tree_t *T);
tree_t *insert_sibling(tree_t *P, tree_t *L, tree_t *T);

void delete_child(tree_t *P);
void delete_sibling(tree_t *P);
void delete_tree(tree_t *T);

void in_breadth(tree_t *T);
void pre_order_right(tree_t *T);
void pre_order(tree_t *T);
void post_order(tree_t *T);
void in_order(tree_t *T,int i);


#endif /* GENERIC_TREES_H_ */
