#include "ktree.h"


void print_coord (t_position_3D pos) {
  printf ("(%d ; %d ; %d)", pos.x, pos.y, pos.z) ;
}


p_tree new_tree () {
	p_tree tree ;
	
	if ((tree = calloc (1, sizeof(t_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
    exit_game () ;
		exit(0) ;
	}
  /*
	if ((tree->sub_tree = calloc (K, sizeof(t_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create sub_tree field (file:ktree.c)\n") ;
    exit_game () ;
		exit(0) ;
	}*/
		
	return tree ;
}



void free_tree (p_tree tree) {

	if (tree != NULL) {
		free_tree (tree->sub_tree) ;
    free (tree) ;
  }
}

/* Balls */

p_tree ball_to_tree_bis (t_object_3D sphere, t_position_3D v1, t_position_3D v2, int depth) {

  t_position_3D  v1_new, v2_new ;
  int n ;
  
  n = (v1.x - v2.x) / 2 ;
  
  fprintf(stderr, "Depth = %d/%d\n", depth, MAX_DEPTH) ;
  if (depth >= MAX_DEPTH)
    return tree;

  for (int i=0 ; i<K ; i++) {
    switch (i) {
      case LTF :
        v2_new.x = v2.x - n ;
        v1_new.y = v1.y + n ;
        v2_new.z = v2.z - n ;
        break;
      case LTR :
        v2_new.x = v2.x - n ;
        v1_new.y = v1.y + n ;
        v1_new.z = v1.z + n ; 
        break;
      case LBF :
        v2_new.x = v2.x - n ;
        v2_new.y = v2.y - n ;
        v2_new.z = v2.z - n ;
        break;
      case LBR :
        v2_new.x = v2.x - n ;
        v2_new.y = v2.y - n ;
        v2_new.z = v2.z - n ;
        break;
      case RTF :
        v1_new.x = v1.x + n ;
        v1_new.y = v1.y + n ;
        v2_new.z = v2.z - n ;
        break;
      case RTR :
        v1_new.x = v1.x + n ;
        v1_new.y = v1.y + n ;
        v1_new.z = v1.z + n ;
        break;
      case RBF :
        v1_new.x = v1.x + n ;
        v2_new.y = v2.y - n ;
        v2_new.z = v2.z - n ;
        break;
      case RBR :
        v1_new.x = v1.x + n ;
        v2_new.y = v2.y - n ;
        v1_new.z = v1.z + n ;
        break;
      }
      printf ("i = %d :\n", i) ;
      print_coord(v1_new) ;
      print_coord(v2_new) ;
      /*
    if(is_out_of_the_ball (radius, depth, center, vertex2))
      tree->sub_tree[i] = EMPTY ;
    else if (is_in_the_ball (diameter, center, depth, accuracy))
      tree->sub_tree[i] = FULL ;
    else {
      
      tree->sub_tree[i] = ball_to_tree_bis (radius, ++depth, tree->sub_tree[i], center, vertex1, vertex2) ;
    }*/
  }
  return tree;
}


p_tree ball_to_tree (t_object_3D sphere) {
  p_tree tree ;
  tree = new_tree () ;
  
  t_position_3D v1, v2 ;
  
  v1.x = sphere.position.x - sphere.dimensions.radius ;
  v1.y = sphere.position.y - sphere.dimensions.radius ;
  v1.z = sphere.position.z - sphere.dimensions.radius ;
  v2.x = sphere.position.x - sphere.dimensions.radius ;
  v2.y = sphere.position.y - sphere.dimensions.radius ;
  v2.z = sphere.position.z - sphere.dimensions.radius ;
  
  return ball_to_tree_bis (sphere, v1, v2, 1) ;
}





