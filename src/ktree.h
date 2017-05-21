#ifndef ktree_h
#define ktree_h

#define FULL ((void*)1)
#define EMPTY NULL

#define K 8

#define INTO 1
#define OUT  2
#define OVERLAP 3


#include <stdlib.h>
#include <stdio.h>

typedef struct s_tree t_tree ;
typedef t_tree* p_tree ;

struct s_tree {
	p_tree sub_tree[K] ;
} ;

p_tree new_tree () ;
void free_tree (p_tree) ;


#endif
