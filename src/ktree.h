#ifndef ktree_h
#define ktree_h

#define FULL ((void*)1)
#define EMPTY NULL

#define K 8
#define MAX_DEPTH 8


#include <stdlib.h>
#include <stdio.h>

typedef struct s_tree t_tree ;
typedef t_tree* p_tree ;

struct s_tree {
	p_tree *sub_tree ;
} ;

p_tree new_tree () ;


#endif
