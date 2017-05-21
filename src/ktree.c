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

static void _add_tree_to_object ( p_object_3D object,
                                  char      (*object_status)(p_object_3D, float, float, float),
                                  float       cube_x,
                                  float       cube_y,
                                  float       cube_z,
                                  float       size,
                                  char        depth) {
  int x ;
  int y ;
  int z ;
  char status ;

  if (depth >= MAX_DEPTH)
    return ;
  size /= 2. ;
  for (x=0 ; x <= 1 ; x+=1) {
    for (y=0 ; y <= 1 ; y+=1) {
      for (z=0 ; z <= 1 ; z+=1) {
        status = cube_status (
          object, object_status, cube_x+x*size,
          cube_y+y*size, cube_z+z*size, size
        ) ;
        if (status == OUT)
          object->tree->sub_tree[x*4 + y*2 + z] = EMPTY ;
        else {
          object->tree->sub_tree[x*4 + y*2 + z] = FULL ;
          if (status == OVERLAP)
            _add_tree_to_object (
              object, object_status, cube_x+x*size,
              cube_y+y*size, cube_z+z*size, size, depth+1
            ) ;
        }
      }
    }
  }
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
        if (status (object, cube_x + x, cube_y + y, cube_z + z))
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

/* Sphere */

char cube_status_sphere ( p_object_3D sphere,
                          float       cube_x,
                          float       cube_y,
                          float       cube_z) {
  return distancef_3D (
    cube_x, cube_y, cube_z,
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
    sphere->dimensions.radius * 2,
    0
  ) ;

}

/* Tile */

char cube_status_tile ( p_object_3D tile,
                          float       cube_x,
                          float       cube_y,
                          float       cube_z) {
  return  (
    cube_x >= tile->position.x && cube_x <= tile->position.x + tile->dimensions.width &&
    cube_y >= tile->position.y && cube_y <= tile->position.y + tile->dimensions.depth &&
    cube_z >= tile->position.z && cube_z <= tile->position.z + tile->dimensions.height
  ) ;
}

void add_tree_to_tile (p_object_3D tile) {
  float cube_size ;

  cube_size = fmax (tile->dimensions.width, tile->dimensions.depth) ;
  cube_size = fmax (cube_size, tile->dimensions.height) ;
  _add_tree_to_object (
    tile,
    cube_status_tile,
    tile->position.x - tile->dimensions.width, 
    tile->position.y - tile->dimensions.depth, 
    tile->position.z - tile->dimensions.height, 
    cube_size,
    0
  ) ;
}

/* Cylinder */

char cube_status_cylinder ( p_object_3D cylinder,
                          float       cube_x,
                          float       cube_y,
                          float       cube_z) {
  return  (
    cube_x >= cylinder->position.x - cylinder->dimensions.radius && 
      cube_x <= cylinder->position.x + cylinder->dimensions.radius &&
    cube_y >= cylinder->position.y - cylinder->dimensions.radius &&
      cube_y <= cylinder->position.y + cylinder->dimensions.radius &&
    cube_z >= cylinder->position.z &&
      cube_z <= cylinder->position.z + cylinder->dimensions.height
  ) ;
}

void add_tree_to_cylinder (p_object_3D cylinder) {
  float cube_size ;

  cube_size = fmax (cylinder->dimensions.width, cylinder->dimensions.depth) ;
  cube_size = fmax (cube_size, cylinder->dimensions.height) ;
  _add_tree_to_object (
    cylinder,
    cube_status_cylinder,
    cylinder->position.x - cylinder->dimensions.width, 
    cylinder->position.y - cylinder->dimensions.depth, 
    cylinder->position.z - cylinder->dimensions.height, 
    cube_size,
    0
  ) ;
}
