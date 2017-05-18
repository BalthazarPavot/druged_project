
#ifndef _KTREE_H
#define _KTREE_H

#define FULL ((void*)1)
#define EMPTY NULL

#define K 8
#define MAX_DEPTH 8

#define LTF 0
#define LTR 1
#define LBF 2
#define LBR 3
#define RTF 4
#define RTR 5
#define RBF 6
#define RBR 7

#include <stdlib.h>
#include <stdio.h>

#include "display.h"


typedef struct s_tree t_tree ;
typedef t_tree* p_tree ;

struct s_tree {
        p_tree *sub_tree ;
} ;

p_tree new_tree () ;
void free_tree (p_tree tree) ;
p_tree ball_to_tree_bis (t_object_3D sphere, t_position_3D v1, t_position_3D v2, int depth) ;
p_tree ball_to_tree (t_object_3D sphere) ;


#endif
