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
 * @abstract    Allocate a data structure of type stack.
 * @discussion  This function allocates a pointer to stack_t (* tail) in the 
 *		heap and returns the pointer to pointer to stack_t (** tail).
 *		
 * @param 	void	No parameters.
 * @result	A double pointer to stack.
*/
stack_t **create_stack(void);

/**
 * @function    push
 * @abstract    Push the data on the stack.
 * @discussion  This function always inserts a node at the top, it's like normal
 *		insertion in the head for the lists.
 *		
 * @param 	top	Double pointer to stack.
 * @param 	T	Pointer to tree to be inserted on top.
 * @result 	A pointer to new node pushed.
*/
stack_t *push(stack_t **top, tree_t *T);

/**
 * @function    pop
 * @abstract    Pop the data on the stack.
 * @discussion  This function always takes a node at the top, it's like normal
 *		remove from the head for the lists.
 *		
 * @param 	top	Double pointer to stack.
 * @result 	A pointer to the extracted node, if empty return NULL.
*/
tree_t *pop(stack_t **top);





/* FUNCTIONS FOR THE QUEUE STRUCTURE */

/**
 * @function    create_queue
 * @abstract    Allocates a data structure of type queue.
 * @discussion  This function allocates a pointer to queue_t (* head) in the
 *		heap and returns the pointer to pointer to queue_t (** head).
 *		
 * @param 	void	No parameters.
 * @result	A double pointer to queue.
*/
queue_t **create_queue(void);

/**
 * @function    enqueue
 * @abstract    Puts the data at the end of the queue structure.
 * @discussion  This function always inserts a node at the end, it's like normal
 *		insertion in the tail for the lists.
 *		
 * @param 	head	Double pointer to queue.
 * @param 	T	Pointer to tree to be inserted in the queue.
 * @result 	A pointer to new node inserted.
*/
queue_t *enqueue(queue_t **head, tree_t *T);

/**
 * @function    dequeue
 * @abstract    Puts the data at the end of the queue structure.
 * @discussion  This function always takes a node at the head, it's like normal
 *		remove from the head for the lists.
 *		
 * @param 	head	Double pointer to queue.
 * @result 	A pointer to the extracted node, if empty return NULL.
*/
tree_t *dequeue(queue_t **head);





/**** FUNCTIONS FOR THE TREE STRUCTURE ****/

/**
 * @function    Tree
 * @abstract    Create a node of a tree.
 * @discussion  This function allocates in the heap the memory area needed to
 *		hold a tree_t type. Set links (parent, child, sibling) to NULL.
 *		Sets the value passed (val) to the function in the data field of
 *		the node.
 *		
 * @param 	val	Integer.
 * @result 	A pointer to the created node, if the malloc fails return NULL.
*/
tree_t *Tree(int val);

/**
 * @function    insert_child
 * @abstract    Inserts the first child of the node.
 * @discussion  This function sets the child link of P to C.
 *		
 * @param 	P	Pointer to tree (PARENT).
 * @param 	C	Pointer to tree (CHILD).
 * @result 	A pointer to C, if P's first child already existed return NULL.
*/
tree_t *insert_child(tree_t *P, tree_t *C);

/**
 * @function    insert_sibling
 * @abstract    Inserts child number n+1°.
 * @discussion  This function sets the sibling link of L to C. The node L is
 *		the n° child of P but also the left brother of C.
 *		
 * @param 	P	Pointer to tree (PARENT).
 * @param 	L	Pointer to tree (LEFT brother of T)(n°).
 * @param 	C	Pointer to tree (CHILD)(n+1°).
 * @result 	A pointer to C, if L's sibling already existed return NULL.
*/
tree_t *insert_sibling(tree_t *P, tree_t *L, tree_t *C);

/**
 * @function    delete_child
 * @abstract    Delete the first child of the node.
 * @discussion  This function sets the child link of P to NULL and deallocates
 *		the memory area of the subtree associated with the child of P.
 *		All child nodes of the subtree will be deleted.
 *		
 * @param 	P	Pointer to tree (PARENT).
 * @result 	Return void function.
*/
void delete_child(tree_t *P);

/**
 * @function    delete_sibling
 * @abstract    Delete right brother.
 * @discussion  This function sets the sibling link of P to NULL and deallocates
 *		the memory area of the subtree associated with the sibling of P.
 *		All child nodes of the subtree will be deleted.
 *		
 * @param 	P	Pointer to tree (PARENT).
 * @result 	Return void function.
*/
void delete_sibling(tree_t *P);

/**
 * @function    delete_tree
 * @abstract    Delete the whole tree.
 * @discussion  This function deallocates the memory area of T. All of T's
 *		children will be deleted.
 *		
 * @param 	T	Pointer to tree.
 * @result 	Return void function.
*/
void delete_tree(tree_t *T);

/**
 * @function    in_breadth
 * @abstract    Visit all nodes.
 * @discussion  This function visits (prints) the nodes of T in breadth.
 *		The visit in breadth is a visit in levels from left to right.
 *		
 * @param 	T	Pointer to tree.
 * @result 	Return void function.
*/
void in_breadth(tree_t *T);

/**
 * @function    pre_order_right
 * @abstract    Visit all nodes.
 * @discussion  This function visits (prints) the nodes of T in right pre-order.
 *		The right pre-order visit begins by visiting the root and then
 *		the rightmost subtree, continue by visiting the adjacent tree on
 *		the left, etc... and finally the leftmost subtree.
 *		
 * @param 	T	Pointer to tree.
 * @result 	Return void function.
*/
void pre_order_right(tree_t *T);

/**
 * @function    pre_order
 * @abstract    Visit all nodes.
 * @discussion  This function visits (prints) the nodes of T in (left)pre-order.
 *		The pre-order visit begins by visiting the root and then the
 *		leftmost subtree, continue by visiting the adjacent tree on
 *		the right, etc... and finally the rightmost subtree.
 *		
 * @param 	T	Pointer to tree.
 * @result 	Return void function.
*/
void pre_order(tree_t *T);

/**
 * @function    post_order
 * @abstract    Visit all nodes.
 * @discussion  This function visits (prints) the nodes of T in post-order.
 *		The post-order visit begins by visiting the leaves from left and
 *		right and rising to parent, so until the root is printed.
 *		
 * @param 	T	Pointer to tree.
 * @result 	Return void function.
*/
void post_order(tree_t *T);

/**
 * @function    in_order
 * @abstract    Visit all nodes.
 * @discussion  This function visits (prints) the nodes of T in post-order.
 *		The in-order visit begins by visiting the left subtree, in the 
 *		middle the root is visited and finally the right subtree.
 *		
 * @param 	T	Pointer to tree.
 * @param 	i	determines how many subtrees there are before the visit
 *			of parent.
 * @result 	Return void function.
*/
void in_order(tree_t *T, int i);


#endif /* GENERIC_TREES_H_ */
