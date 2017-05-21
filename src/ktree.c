#include "ktree.h"

p_tree new_tree () {
	p_tree tree ;
	
	if ((tree = malloc (sizeof(p_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
		exit(0) ;
	}
		
	return tree ;
}

void free_tree (p_tree tree) {

	if (tree != NULL) {
    for (int i=0 ; i < K ; i++)
      free_tree (tree->sub_tree[i]) ;
    free (tree) ;
  }
}

float distancef_3D (float x1, float y1, float z1,
                    float x2, float y2, float z2 ) {
  return sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2) + pow (z2 - z1, 2)) ;
}

void static _add_tree_to_object ( p_object_3D object,
                                  char      (*status)(p_object_3D, float, float, float),
                                  float       cube_x,
                                  float       cube_y,
                                  float       cube_z,
                                  float       size,
                                  char        depth) {
  
}


char cube_status (p_object_3D object,
                  char      (*status)(p_object_3D, float, float, float),
                  float       cube_x,
                  float       cube_y,
                  float       cube_z,
                  float       size) {
  int x, y, z, sum ;

  sum = 0 ;
  for (x=0 ; x <= size ; x+=size) {
    for (y=0 ; y <= size ; y+=size) {
      for (z=0 ; z <= size ; z+=size) {
        if (status (cube_x + x, cube_y + y, cube_z + z,
            sphere->position.x, sphere->position.y,
            sphere->position.z))
          sum+=1 ;
      }
    }
  }
  
  if (sum == 0)
    return OUT ;
  else if (sum == 8)
    return INTO ;
  return OVERLAP ;
}

char cube_status_sphere ( p_object_3D sphere,
                          float       cube_x,
                          float       cube_y,
                          float       cube_z) {
  return distancef_3D (
    cube_x + x, cube_y + y, cube_z + z,
    sphere->position.x, sphere->position.y,
    sphere->position.z) < sphere->dimensions.radius ;
}

void add_tree_to_sphere (p_object_3D sphere) {

  _add_tree_to_object (
    sphere,
    cube_status_sphere,
    sphere->position.x - sphere->dimensions.radius, 
    sphere->position.y - sphere->dimensions.radius, 
    sphere->position.z - sphere->dimensions.radius, 
    sphere->dimensions.radius * 2
  ) ;

}
