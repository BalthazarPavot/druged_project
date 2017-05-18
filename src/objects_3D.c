

#include "objects_3D.h"





p_object_3D new_object_3D () {
  p_object_3D object ;

  if ((object = calloc (1, sizeof (t_object_3D))) == NULL)
    exit_game () ;
  fprintf (stderr, "[Warning] implement new_object_3D and free_object_3D") ;
  return object ;
}

static void _free_object_3D (p_object_3D object) {
  if (object != NULL) {
    free (object) ;
  }
}

void free_object_3D (void *object) {
  _free_object_3D (*(p_object_3D*)object) ;
}



p_building_3D new_building_3D () {
  p_building_3D building ;

  if ((building = calloc (1, sizeof (t_building_3D))) == NULL)
    exit_game () ;
  building->objects = new_chained_list () ;
  set_chained_list_free_chain_value (building->objects, free_object_3D) ;
  return building ;
}

static void _free_building_3D (p_building_3D building) {
  printf ("_free_object_3D: %p\n", (void*)building) ;
  if (building != NULL) {
    free_chained_list (building->objects) ;
    free (building) ;
  }
}

void free_building_3D (void *building) {
  _free_building_3D (*(p_building_3D*)building) ;
  free (building) ;
}


p_obstacle_3D new_obstacle_3D () {
  p_obstacle_3D obstacle ;

  if ((obstacle = calloc (1, sizeof (t_obstacle_3D))) == NULL)
    exit_game () ;
  obstacle->objects = new_chained_list () ;
  set_chained_list_free_chain_value (obstacle->objects, free_object_3D) ;
  return obstacle ;
}

static void _free_obstacle_3D (p_obstacle_3D obstacle) {
  if (obstacle != NULL) {
    free_chained_list (obstacle->objects) ;
    free (obstacle) ;
  }
}

void free_obstacle_3D (void *obstacle) {
  _free_obstacle_3D ((p_obstacle_3D)obstacle) ;
}



p_bonus_3D new_bonus_3D () {
  p_bonus_3D bonus ;

  if ((bonus = calloc (1, sizeof (t_bonus_3D))) == NULL)
    exit_game () ;
  bonus->objects = new_chained_list () ;
  set_chained_list_free_chain_value (bonus->objects, free_object_3D) ;
  return bonus ;
}

static void _free_bonus_3D (p_bonus_3D bonus) {
  if (bonus != NULL) {
    free_chained_list (bonus->objects) ;
    free (bonus) ;
  }
}

void free_bonus_3D (void *bonus) {
  _free_bonus_3D ((p_bonus_3D)bonus) ;
}