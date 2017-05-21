#include "ktree.h"

p_tree new_tree () {
  p_tree tree ;
  
  if ((tree = calloc (1, sizeof(t_tree))) == NULL) {
    fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
    exit_game() ;
  }
  
  return tree ;
}

void free_tree (p_tree tree) {

  if (tree != EMPTY && tree != FULL) {
    for (int i=0 ; i < K ; i+=1)
      free_tree (tree->sub_tree[i]) ;
    free (tree) ;
  }
}

float distancef_3D (float x1, float y1, float z1,
                    float x2, float y2, float z2 ) {
  return sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2) + pow (z2 - z1, 2)) ;
}

float distancef_2D (float x1, float y1,
                    float x2, float y2) {
  return sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2)) ;
}

static void _add_tree_to_object ( p_object_3D object,
                                  p_tree      curent_tree,
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

  size /= 2. ;
  for (x=0 ; x <= 1 ; x+=1) {
    for (y=0 ; y <= 1 ; y+=1) {
      for (z=0 ; z <= 1 ; z+=1) {
        status = cube_status (
          object, object_status, cube_x+x*size,
          cube_y+y*size, cube_z+z*size, size
        ) ;
        if (status != OUT) {
          curent_tree->sub_tree[x + y*2 + z*4] = FULL ;
          if (status == OVERLAP && depth < MAX_DEPTH) {
            curent_tree->sub_tree[x + y*2 + z*4] = new_tree () ;
            _add_tree_to_object (
              object,
              curent_tree->sub_tree[x + y*2 + z*4],
              object_status, cube_x+x*size,
              cube_y+y*size, cube_z+z*size, size, depth+1
            ) ;
          }
        } else
          curent_tree->sub_tree[x + y*2 + z*4] = EMPTY ;
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
  float x, y, z ;
  int sum ;

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


  if (sphere->tree != NULL) {
    free_tree (sphere->tree) ;
    sphere->tree = NULL ;
  }
  sphere->tree = new_tree () ;
  _add_tree_to_object (
    sphere,
    sphere->tree,
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

  if (tile->tree != NULL) {
    free_tree (tile->tree) ;
    tile->tree = NULL ;
  }
  tile->tree = new_tree () ;

  cube_size = fmax (tile->dimensions.width, tile->dimensions.depth) ;
  cube_size = fmax (cube_size, tile->dimensions.height) ;
  _add_tree_to_object (
    tile,
    tile->tree,
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
  return (
    distancef_2D (cube_x, cube_y, cylinder->position.x,
      cylinder->position.y) < cylinder->dimensions.radius &&
    cube_z >= cylinder->position.z &&
      cube_z <= cylinder->position.z + cylinder->dimensions.height
  ) ;
}

void add_tree_to_cylinder (p_object_3D cylinder) {
  float cube_size ;

  if (cylinder->tree != NULL) {
    free_tree (cylinder->tree) ;
    cylinder->tree = NULL ;
  }
  cylinder->tree = new_tree () ;
  cube_size = fmax (cylinder->dimensions.radius*2, cylinder->dimensions.height) ;
  _add_tree_to_object (
    cylinder,
    cylinder->tree,
    cube_status_cylinder,
    cylinder->position.x - cylinder->dimensions.radius, 
    cylinder->position.y - cylinder->dimensions.radius, 
    cylinder->position.z,// - cylinder->dimensions.height, 
    cube_size,
    0
  ) ;
}
