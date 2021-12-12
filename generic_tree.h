/**
 * @file: generic_tree.h
 * @author: Simone Arcari
 *
 * @abstract: header file
 * @discussion: This file contains the definitions of the structs and functions
 *		needed to work with tree data structures.
 */


#ifndef GENERIC_TREE_H_
#define GENERIC_TREE_H_


/**
 * @typedef: tree_t
 * @struct: tree
 * @abstract: Contains all node properties.
 * @discussion: Each node stores information and has pointers to be linked to 
 *		the other nodes to form a tree structure.
 *
 * @field data:		information that the node stores
 * @field parent:	link to the parent node
 * @field child:	link to the first child node
 * @field sibling:	link to the right brother node
*/
typedef struct tree {
	int data;
	struct tree *parent;
	struct tree *child;
	struct tree *sibling;
}tree_t;


/**
 * @typedef: stack_t
 * @struct: stack
 * @abstract: Contains all stack properties.
 * @discussion: The structure is that of a node in a list, but designed to be 
 *		of the LIFO type only.
 *
 * @field tree:		information that the node stores (it's a stack of trees)
 * @field next:		link to the next node in list
*/
typedef struct stack{
	tree_t *tree;
	struct stack *next;
}stack_t;

/**
 * @typedef: queue_t
 * @struct: queue
 * @abstract: Contains all queue properties.
 * @discussion: The structure is that of a node in a list, but designed to be 
 *		of the FIFO type only.
 *
 * @field tree:		information that the node stores (it's a queue of trees)
 * @field next:		link to the next node in list
*/
typedef struct queue {
	tree_t *tree;
	struct queue *next;
}queue_t;



/* functions for the stack_t structure */
stack_t **create_stack(void);
stack_t *push(stack_t **top, tree_t *T);
tree_t *pop(stack_t **top);

/* functions for the queue_t structure */
queue_t **create_queue(void);
queue_t *enqueue(queue_t **head, tree_t *T);
tree_t *dequeue(queue_t **head);

/* functions for the tree_t structure */
tree_t *Tree(int val);

tree_t *insert_child(tree_t *P, tree_t *T);
tree_t *insert_sibling(tree_t *P, tree_t *L, tree_t *T);

void delete_child(tree_t *P);
void delete_sibling(tree_t *P);
void delete_tree(tree_t *T);

void in_ampiezza(tree_t *T);
void pre_ordine_destro(tree_t *T);
void pre_ordine(tree_t *T);
void post_ordine(tree_t *T);
void in_ordine(tree_t *T,int i);


#endif /* GENERIC_TREE_H_ */
