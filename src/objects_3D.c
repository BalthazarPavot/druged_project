

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
  free (object) ;
}



p_building_3D new_building_3D () {
  p_building_3D building ;

  if ((building = calloc (1, sizeof (t_building_3D))) == NULL)
    exit_game () ;
  init_building_3D (building) ;
  return building ;
}
void init_building_3D (p_building_3D building) {
  if (building == NULL)
    return ;
  building->objects = new_chained_list () ;
  set_chained_list_free_chain_value (building->objects, free_object_3D) ;
}

void init_random_building_3D (p_building_3D building) {
  if (building == NULL)
    return ;
  init_building_3D (building) ;
  building->type = rand () % 3 ;
  generate_building (building) ;
}

void generate_building (p_building_3D building) {
  if (building == NULL)
    return ;
  switch (building->type) {
    case 0:
      generate_building_0 (building) ;
      break ;
    case 1:
      generate_building_1 (building) ;
      break ;
    case 2:
    default:
      generate_building_2 (building) ;
      break ;
  }
}

void generate_building_0 (p_building_3D building) {
  if (building == NULL)
    return ;
  building->dimensions.depth = 10 ;
  building->dimensions.width = 10 ;
  building->dimensions.height = 10 ;
}

void generate_building_1 (p_building_3D building) {
  if (building == NULL)
    return ;
  building->dimensions.depth = 30 ;
  building->dimensions.width = 30 ;
  building->dimensions.height = 30 ;
}

void generate_building_2 (p_building_3D building) {
  if (building == NULL)
    return ;
  building->dimensions.depth = 20 ;
  building->dimensions.width = 20 ;
  building->dimensions.height = 20 ;
}

void set_random_building_3D_position (p_building_3D building, int x, int y, int z) {
  if (building == NULL)
    return ;
  if (x == -1) {
    if (rand () % 2) {
      building->position.x = -ROAD_MID_SPAN - 5 - building->dimensions.width ;
    } else {
      building->position.x = ROAD_MID_SPAN + 5 ;
    }
  } else
    building->position.x = x ;
  //building->position.x = x == -1 ? (ROAD_SPAN/2 + 5) * (rand ()%2 ? 1 : -1) : x ;
  building->position.y = y == -1 ? rand () % context.parameters.road_length : y ;
  building->position.z = z == -1 ? building->dimensions.height : z ;
}


static void _free_building_3D (p_building_3D building) {
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
  init_obstacle_3D (obstacle) ;
  return obstacle ;
}

void init_obstacle_3D (p_obstacle_3D obstacle) {
  obstacle->objects = new_chained_list () ;
  set_chained_list_free_chain_value (obstacle->objects, free_object_3D) ;
}

void init_random_obstacle_3D (p_obstacle_3D obstacle) {
  init_obstacle_3D (obstacle) ;
}

void set_random_obstacle_3D_position (p_obstacle_3D obstacle, int x, int y, int z) {
  if (obstacle == NULL)
    return ;
  obstacle->position.x = x == -1 ? (ROAD_SPAN/2 + 5) * (rand ()%2 ? 1 : -1) : x ;
  obstacle->position.y = y == -1 ? rand () % context.parameters.road_length : y ;
  obstacle->position.z = z == -1 ? 0 : z ;
}

static void _free_obstacle_3D (p_obstacle_3D obstacle) {
  if (obstacle != NULL) {
    free_chained_list (obstacle->objects) ;
    free (obstacle) ;
  }
}

void free_obstacle_3D (void *obstacle) {
  _free_obstacle_3D (*(p_obstacle_3D*)obstacle) ;
  free (obstacle) ;
}



p_bonus_3D new_bonus_3D () {
  p_bonus_3D bonus ;

  if ((bonus = calloc (1, sizeof (t_bonus_3D))) == NULL)
    exit_game () ;
  init_bonus_3D (bonus) ;
  return bonus ;
}

void init_bonus_3D (p_bonus_3D bonus) {
  bonus->objects = new_chained_list () ;
  set_chained_list_free_chain_value (bonus->objects, free_object_3D) ;
}

void init_random_bonus_3D (p_bonus_3D bonus) {
  init_bonus_3D (bonus) ;
}

void set_random_bonus_3D_position (p_bonus_3D bonus, int x, int y, int z) {
  if (bonus == NULL)
    return ;
  bonus->position.x = x == -1 ? (ROAD_SPAN/2 + 5) * (rand ()%2 ? 1 : -1) : x ;
  bonus->position.y = y == -1 ? rand () % context.parameters.road_length : y ;
  bonus->position.z = z == -1 ? 0 : z ;
}

static void _free_bonus_3D (p_bonus_3D bonus) {
  if (bonus != NULL) {
    free_chained_list (bonus->objects) ;
    free (bonus) ;
  }
}

void free_bonus_3D (void *bonus) {
  _free_bonus_3D (*(p_bonus_3D*)bonus) ;
  free (bonus) ;
}