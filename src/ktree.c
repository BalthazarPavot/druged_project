#include "ktree.h"

p_tree new_tree () {
	p_tree tree ;
	
	if ((tree = calloc (1, sizeof(t_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
    exit_game () ;
		exit(0) ;
	}
	if ((tree->sub_tree = calloc (K, sizeof(t_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create sub_tree field (file:ktree.c)\n") ;
    exit_game () ;
		exit(0) ;
	}
		
	return tree ;
}



void free_tree (p_tree tree) {

	if (tree != NULL) {
		free_tree (tree->sub_tree) ;
    free (tree) ;
  }
}

/* Balls */

  switch (i) {
    case :

p_tree ball_to_tree_bis (int radius, int depth, p_tree tree, s_position_3D center, s_position_3D vertex1, s_position_3D vertex2) {
  fprintf(stderr, "Depth = %d/%d\n", depth, MAX_DEPTH) ;
  if (depth >= MAX_DEPTH)
    return tree;
  
    
  for (int i=0 ; i<K ; i++) {
    if(is_out_of_the_ball (radius, depth, center, vertex2))
      tree->sub_tree[i] = EMPTY ;
    else if (is_in_the_ball (diameter, center, depth, accuracy))
      tree->sub_tree[i] = FULL ;
    else
      tree->sub_tree[i] = ball_to_tree_bis (radius, ++depth, tree->sub_tree[i], center, vertex1, vertex2) ;
  }
  return tree;
}


p_tree ball_to_tree (int radius, t_position_3D center) {
  p_tree tree ;
  tree = new_tree () ;
  
  return ball_to_tree_bis (radius, 1, tree, center, center) ;
}





