#ifndef ktree_h
#define ktree_h

#define FULL ((void*)1)
#define EMPTY NULL

#define K 8
#define MAX_DEPTH 2

#define INTO 1
#define OUT  2
#define OVERLAP 3


#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct s_tree t_tree ;
typedef t_tree* p_tree ;

struct s_tree {
  p_tree sub_tree[K] ;
} ;


#include "objects_3D.h"

p_tree new_tree () ;
void free_tree (p_tree) ;
float distancef_3D (float x1, float y1, float z1, float x2, float y2, float z2) ;
float distancef_2D (float x1, float y1, float x2, float y2) ;
char cube_status (p_object_3D object,
  char (*status)(p_object_3D, float, float, float),
  float cube_x, float cube_y, float cube_z, float size) ;
char cube_status_sphere (p_object_3D sphere, float cube_x,
  float cube_y, float cube_z) ;
void add_tree_to_sphere (p_object_3D sphere) ;
char cube_status_cylinder (p_object_3D cylinder, float cube_x, float cube_y,
  float cube_z) ;
void add_tree_to_cylinder (p_object_3D cylinder) ;

#endif
