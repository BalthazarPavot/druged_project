#include "ktree.h"


void print_t_position (t_position_3D pos) {
  printf ("(%d ; %d ; %d)\n", pos.x, pos.y, pos.z) ;
}

t_position_3D copy_t_position (t_position_3D pos) {
  t_position_3D new ;
  
  new.x = pos.x ;
  new.y = pos.y ;
  new.z = pos.z ;

  return new;
}

float distance (t_position_3D a, t_position_3D b) {
  return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2));
}

t_position_3D translate_t_position (t_position_3D pos_in, int x, int y, int z) {
  
  t_position_3D pos_out ;
  
  pos_out.x = pos_in.x + x ;
  pos_out.y = pos_in.y + y ;
  pos_out.z = pos_in.z + z ;
  
  return pos_out ;
}

t_position_3D copy_t_position_add (t_position_3D pos, int add) {
  t_position_3D new ;
  
  new.x = pos.x + add ;
  new.y = pos.y + add ;
  new.z = pos.z + add ;

  return new;
}


t_tree *new_tree () {
	t_tree *tree ;
	
	if ((tree = calloc (1, sizeof(t_tree))) == NULL) { /* TODO change it */ 
		fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
    exit_game () ;
		exit(0) ;
	}
  		
	return tree ;
}

t_tree *new_empty () {
	t_tree *tree ;
  fprintf(stderr, "empty 1\n") ;
	tree = new_tree () ;
  fprintf(stderr, "empty 2\n") ;
  tree->sub_tree = EMPTY ;
  fprintf(stderr, "empty 3\n") ;
  
	return tree ;
}



void free_tree (t_tree *tree) {

	if (tree != NULL) {
		free_tree (*(tree->sub_tree)) ;
    free (tree) ;
  }
}

/* Balls */

int is_out_of_the_ball (int radius, t_position_3D center, t_position_3D v1, t_position_3D v2) {
  if (radius < distance (center, v1) && radius < distance (center, v2))
    return 1 ;
  return 0 ;
}

int is_in_the_ball (int radius, t_position_3D center, t_position_3D v1, t_position_3D v2) {
  if (radius >= distance (center, v1) &&   radius >= distance (center, v2))
    return 1 ;
  return 0 ;
}

p_tree ball_to_tree_bis (t_object_3D sphere, t_position_3D v1, t_position_3D v2, int depth) {

  print_t_position(v1) ;
  print_t_position(v2);
  fprintf(stderr, "Depth = %d/%d         %d       \n", depth, MAX_DEPTH, sphere.dimensions.radius) ;
  if (depth >= MAX_DEPTH) {
    return FULL;
  }
  
  t_position_3D  v1_old, v2_old ;
  int n ;

  p_tree tree ;
  tree = new_tree () ;

  v1_old = copy_t_position (v1) ;
  v2_old = copy_t_position (v2) ;
  
  n = (v2_old.x - v1_old.x) / 2 ;
  
  for (int i=0 ; i<K ; i++) {
    fprintf(stderr, "switch\n") ;

    switch (i) {
      case LTF :
        fprintf (stderr, "LTF\n");
        v1 = translate_t_position (v1_old, 0, n, 0) ;
        break;
      case LTR :
        fprintf (stderr, "LTR\n");
        v1 = translate_t_position (v1_old, 0, n, n) ;
        break;
      case LBF :
        fprintf (stderr, "LBF\n");
        v1 = translate_t_position (v1_old, 0, 0, 0) ;
        break;
      case LBR :
        fprintf (stderr, "LBR\n");
        v1 = translate_t_position (v1_old, 0, 0, n) ;
        break;
      case RTF :
        fprintf (stderr, "RTF\n");
        v1 = translate_t_position (v1_old, n, n, 0) ;
        break;
      case RTR :
        fprintf (stderr, "RTR\n");
        v1 = translate_t_position (v1_old, n, n, n) ;
        break;
      case RBF :
        fprintf (stderr, "RBF\n");
        v1 = translate_t_position (v1_old, n, 0, 0) ;
        break;
      case RBR :
        fprintf (stderr, "RBR\n");
        v1 = translate_t_position (v1_old, n, 0, n) ;
        break;
    }
      
    v2 = copy_t_position_add (v1, n) ;
    print_t_position(v1) ;

    if(is_out_of_the_ball (sphere.dimensions.radius, sphere.position, v1, v2)) {
      fprintf(stderr, "out 1\n") ;
      tree->sub_tree[i] = new_empty () ;
      fprintf(stderr, "out 3\n") ;
    } else if (is_in_the_ball (sphere.dimensions.radius, sphere.position, v1, v2)) {
      fprintf(stderr, "in\n") ;
      tree->sub_tree[i] = FULL ;
    } else {
      fprintf(stderr, "Sub_tree\n") ;
      tree->sub_tree[i] = ball_to_tree_bis (sphere, v1, v2, ++depth) ;
//    }
    }
  }
  return tree ;
}


p_tree ball_to_tree (t_object_3D sphere) {
  
  t_position_3D v1, v2 ;
  
  v1.x = sphere.position.x - sphere.dimensions.radius ;
  v1.y = sphere.position.y - sphere.dimensions.radius ;
  v1.z = sphere.position.z - sphere.dimensions.radius ;
  v2.x = sphere.position.x + sphere.dimensions.radius ;
  v2.y = sphere.position.y + sphere.dimensions.radius ;
  v2.z = sphere.position.z + sphere.dimensions.radius ;
  return ball_to_tree_bis (sphere, v1, v2, 1) ;
}





