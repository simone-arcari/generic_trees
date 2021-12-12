/**
 * @file: main.c
 * @author: Simone Arcari
 *
 * @abstract: main file
 * @discussion: This file contains some examples of use of the generic_tree 
 *		library.
 */



#include <stdio.h>
#include "generic_tree.h"



/**
 * @function: visits
 * @abstract: visit tree
 * @discussion: Performs the visit of T in the 4 different ways implemented in
 *		generic_tree library. the visit operation consists in printing
 *		the integers contained in each node of the tree.
 *
 * @param[in] T: pointer to a node (tree)
 */
void visits(tree_t *T) {

	printf("visit in breadth:\n");
	in_ampiezza(T);
	puts("");

	printf("visit in pre-order right:\n");
	pre_ordine_destro(T);
	puts("");
	
	printf("visit in pre-order:\n");
	pre_ordine(T);
	puts("");
	
	printf("visit in post-order:\n");
	post_ordine(T);
	puts("");
	
	printf("visit in order:\n");
	in_ordine(T, 1);
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
	in_ampiezza(A);
	puts("");
	
	
	/* other operations */
	printf("remove sub-tree B containing the values 2->(3,4)\n\n");
	delete_child(A);	// remove B (A->B)

	printf("visit in post-order:\n");
	post_ordine(A);
	puts("");
	
	
	
	return 0;
}
