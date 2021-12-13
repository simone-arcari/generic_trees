/**
 * @file	main.c
 * @author	Simone Arcari
 *
 * @abstract	main file
 * @discussion	This file contains some examples of use of the generic_tree 
 *		library.
 */



#include <stdio.h>
#include "generic_trees.h"



/**
 * @function 	visits
 * @abstract 	Visit tree.
 * @discussion	Performs the visit of T in the 4 different ways implemented in
 *		generic_tree library. the visit operation consists in printing
 *		the integers contained in each node of the tree.
 *
 * @param 	T	Pointer to a node (tree).
 * @result	No return (void function).
 */
void visits(tree_t *T) {

	printf("visit in breadth:\n");
	in_breadth(T);
	puts("");

	printf("visit in pre-order right:\n");
	pre_order_right(T);
	puts("");
	
	printf("visit in pre-order:\n");
	pre_order(T);
	puts("");
	
	printf("visit in post-order:\n");
	post_order(T);
	puts("");
	
	printf("visit in order:\n");
	in_order(T, 1);
	puts("");
}



int main(void) {
	
	/* make some node */
	tree_t *A = Tree(1);
	tree_t *B = Tree(2);
	tree_t *C = Tree(3);
	tree_t *D = Tree(4);
	tree_t *E = Tree(5);
	tree_t *F = Tree(6);
	tree_t *G = Tree(7);
	tree_t *H = Tree(8);
	
	/* make tree */
	insert_child(A, B);
	insert_sibling(A, B, E);
	insert_child(B, C);
	insert_sibling(B, C, D);
	insert_child(E, F);
	insert_sibling(E, F, G);
	insert_sibling(E, G, H);

	visits(A);	// visit all the nodes of the tree in various ways
	
	
	/* other operations */
	printf("remove sub-tree H containing value 8\n\n");
	delete_sibling(G);	// remove H (G->H)
	
	printf("visit in breadth:\n");
	in_breadth(A);
	puts("");
	
	
	/* other operations */
	printf("remove sub-tree B containing the values 2->(3,4)\n\n");
	delete_child(A);	// remove B (A->B)

	printf("visit in post-order:\n");
	post_order(A);
	puts("");
	
	
	
	return 0;
}
