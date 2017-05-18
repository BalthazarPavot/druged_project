

#include "objects_3D.h"




static void _free_building_3D (void *building) {
  free_building_3D ((p_building_3D)building) ;
}

p_building_3D new_building_3D () {
  p_building_3D building ;

  if ((building = calloc (1, sizeof (t_building_3D))) == NULL)
    exit_game () ;
  building->objects = new_chained_list () ;
  set_chained_list_free_chain_value (building->objects, _free_building_3D) ;
  return building ;
}


void free_building_3D (p_building_3D building) {
  if (building != NULL) {
    free_chained_list (building->objects) ;
    free (building) ;
  }
}

static void _free_obstacle_3D (void *obstacle) {
  free_obstacle_3D ((p_obstacle_3D)obstacle) ;
}

p_obstacle_3D new_obstacle_3D () {
  p_obstacle_3D obstacle ;

  if ((obstacle = calloc (1, sizeof (t_obstacle_3D))) == NULL)
    exit_game () ;
  obstacle->objects = new_chained_list () ;
  set_chained_list_free_chain_value (obstacle->objects, _free_obstacle_3D) ;
  return obstacle ;
}


void free_obstacle_3D (p_obstacle_3D obstacle) {
  if (obstacle != NULL) {
    free_chained_list (obstacle->objects) ;
    free (obstacle) ;
  }
}


static void _free_bonus_3D (void *bonus) {
  free_bonus_3D ((p_bonus_3D)bonus) ;
}

p_bonus_3D new_bonus_3D () {
  p_bonus_3D bonus ;

  if ((bonus = calloc (1, sizeof (t_bonus_3D))) == NULL)
    exit_game () ;
  bonus->objects = new_chained_list () ;
  set_chained_list_free_chain_value (bonus->objects, _free_bonus_3D) ;
  return bonus ;
}


void free_bonus_3D (p_bonus_3D bonus) {
  if (bonus != NULL) {
    free_chained_list (bonus->objects) ;
    free (bonus) ;
  }
}