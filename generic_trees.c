#include <stdio.h>
#include <stdlib.h>
#include "generic_trees.h"



stack_t **create_stack(void) {

	stack_t **top = malloc(sizeof(stack_t *));
	if(top==NULL) {
		fprintf(stderr, "ERR in malloc: [stack_t **top = malloc(sizeof(stack_t *));].\n");
	        return NULL;  
	}
	
	*top = NULL;
	return top;
}

stack_t *push(stack_t **top, tree_t *T) {

	stack_t *new_top = malloc(sizeof(stack_t));
	if(new_top==NULL) {
		fprintf(stderr, "ERR in malloc: [stack_t *new_top = malloc(sizeof(stack_t));].\n");
		return NULL;
	}
	
	new_top->next = *top;
	new_top->tree = T;
	
	*top = new_top;
	
	return new_top;
}

tree_t *pop(stack_t **top) {

	if(top==NULL) {
		fprintf(stderr, "ERR top: punta a NULL");
		return NULL;
	}
	
	if(*top==NULL) return NULL;	// la coda è vuota
	
	tree_t *T = (*top)->tree;
	*top = (*top)->next;
	return T;
}

queue_t **create_queue(void) {

	queue_t **head = malloc(sizeof(queue_t *));
	if(head==NULL) {
		fprintf(stderr, "ERR in malloc: [queue_t **head = malloc(sizeof(queue_t *));].\n");
	        return NULL;  
	}
	
	*head = NULL;
	return head;
}

queue_t *enqueue(queue_t **head, tree_t *T) {
/*
	@descr: inserisce sempre in coda
	@param head: sentinella
	@param T: albero da inserire in coda
*/
	queue_t *new_tail = malloc(sizeof(queue_t));
	if(new_tail==NULL) {
		fprintf(stderr, "ERR in malloc: [queue_t *new_tail = malloc(sizeof(queue_t));].\n");
		return NULL;
	}
	new_tail->tree = T;
	new_tail->next = NULL;

	queue_t *c = *head;	// c punta al primo nodo
    	queue_t *pos = NULL;

	while (c != NULL) {
		pos = c;
		c = c->next;	
	}
	
	if (pos == NULL)
		*head = new_tail;
	else
		pos->next = new_tail;
	
	return new_tail;
}

tree_t *dequeue(queue_t **head) {

	if(head==NULL) {
		fprintf(stderr, "ERR head == NULL in function dequeue()");
		return NULL;
	}
	
	if(*head==NULL) return NULL;	// la coda è vuota
	
	tree_t *T = (*head)->tree;
	*head = (*head)->next;
	return T;
}

tree_t *Tree(int val) {
	
	tree_t *new = malloc(sizeof(tree_t));
	
	new->parent = NULL;
	new->child = NULL;
	new->sibling = NULL;
	new->data = val;
	
	return new;
}

tree_t *insert_child(tree_t *P, tree_t *T) {
/*
	@descr: P è il nodo padre che avrà come primo figlio il nodo T
		a sua volta T avrà come padre P
	@param P: puntatore ad un nodo (padre)
	@param T: puntatore ad un nodo (figlio)
*/
	if(P->child == NULL) {
		P->child = T;
		T->parent = P;
		return T;
	}
	
	return NULL;
}

tree_t *insert_sibling(tree_t *P, tree_t *L, tree_t *T) {
/*
	@descr: P è il nodo padre che avrà come figlio n-essimo il nodo T
		quindi T è sibling del nodo alla sua sinistra L che è figlio
		n-1-esimo di P
	@param P: puntatore ad un nodo (padre)
	@param L: puntatore ad un nodo (figlio n-1-esimo)(fratello di T)
	@param T: puntatore ad un nodo (figlio n-esimo)(sibling di L)
*/
	if(L->sibling == NULL) {
		L->sibling = T;
		T->parent = P;
		return T;
	}
	
	return NULL;
}


void delete_child(tree_t *P) {
/*
	@descr:  elimina il sottoalbero con radice il primo figlio corrente
	@param P: puntatore ad un nodo (padre)
*/
	if(P==NULL){
		fprintf(stderr, "ERR P == NULL in function delete_child()");
		return;
	}
	
	tree_t *child = P->child;
	tree_t *new_child = child->sibling;
	
	delete_tree(child);
	
	P->child = new_child;
}

void delete_sibling(tree_t *L) {
/*
	@descr:   elimina il sottoalbero con radice il prossimo figlio
	@param L: puntatore ad un nodo (fratello sinistro)
*/
	if(L==NULL){
		fprintf(stderr, "ERR L == NULL in function delete_sibling()");
		return;
	}
	
	tree_t *first_sibling = L->sibling;
	tree_t *new_sibling = first_sibling->sibling;
	
	delete_tree(first_sibling);
	
	L->sibling = new_sibling;
}

void delete_tree(tree_t *T) {
/*
	@descr: elimina tutto l'albero radice T compresa
	@param P: puntatore ad un nodo (radice)
*/
	tree_t *pos = T->child;
	while(pos!=NULL) {
		tree_t *next = pos->sibling;
		delete_tree(pos);
		pos = next;
	}
	free(T);
	
}

void in_ampiezza(tree_t *T) {
/*
	@descr: visita tutti i nodi
	@param: puntatore ad un nodo (albero)
*/
	queue_t **head = create_queue();	// creo la queue
	
	if(head == NULL)
		fprintf(stderr, "ERR head == NULL in function in_ampiezza()");
		
	tree_t *pos;
	enqueue(head, T);	// metto T nella queue
	
	while(*head != NULL)
	{
		pos = dequeue(head);	// estraggo un nodo dalla queue
		printf("data: %d\n", pos->data);
		pos = pos->child;
		
		while(pos!=NULL)
		{
			enqueue(head, pos);	// metto nella queue pos 
			pos = pos->sibling;
		}
	}
}

void pre_ordine_destro(tree_t *T) {
/*
	@descr: visita tutti i nodi
	@param: puntatore ad un nodo (albero)
*/
	stack_t **top = create_stack();	// creo lo stack
	
	if(top == NULL)
		fprintf(stderr, "ERR top == NULL in function pre_ordine_destro()");
		
	tree_t *pos;
	push(top, T);	// metto T nello stack
	
	while(*top != NULL)
	{
		pos = pop(top);	// estraggo un nodo dallo stack
		printf("data: %d\n", pos->data);
		pos = pos->child;
		
		while(pos!=NULL)
		{
			push(top, pos);	// metto nello stack pos 
			pos = pos->sibling;
		}
	}
}

void pre_ordine(tree_t *T) {
/*
	@descr: visita tutti i nodi
	@param: puntatore ad un nodo (albero)
*/
	if(T==NULL) {
		fprintf(stderr, "ERR T == NULL in function pre_ordine()");
		return;
	}
	
	printf("data: %d\n", T->data);
	tree_t *pos = T->child;
	
	while(pos!=NULL){
		pre_ordine(pos);
		pos = pos->sibling;	// pos = next
	}

}

void post_ordine(tree_t *T) {
/*
	@descr: visita tutti i nodi
	@param: puntatore ad un nodo (albero)
*/
	if(T==NULL) {
		fprintf(stderr, "ERR T == NULL in function post_ordine()");
		return;
	}
	
	tree_t *pos = T->child;
	
	while(pos!=NULL){
		post_ordine(pos);
		pos = pos->sibling;	// pos = next
	}
	
	printf("data: %d\n", T->data);
}

void in_ordine(tree_t *T, int i) {
/*
	@descr: visita tutti i nodi
	@param: puntatore ad un nodo (albero)
*/
	if(T==NULL) {
		fprintf(stderr, "ERR T == NULL in function in_ordine()");
		return;
	}

	tree_t *pos = T->child;
	int k = 0;
	
	while(pos!=NULL && k<i) {
		k++;
		in_ordine(pos, i);
		pos = pos->sibling;	// pos = next
	}	
	
	printf("data: %d\n", T->data);
	
	while(pos!=NULL) {
		in_ordine(pos, i);		
		pos = pos->sibling;	// pos = next	
	}
}

