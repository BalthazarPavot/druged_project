#ifndef ktree_h
#define ktree_h

#define FULL ((void*)1)
#define EMPTY NULL

#define K 8

typedef struct s_tree t_tree ;
typedef t_tree* p_tree ;

struct s_tree {
	p_tree *sub_tree ;
} ;

p_tree new_tree () ;


#endif
