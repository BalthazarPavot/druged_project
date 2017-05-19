

#include "objects_3D.h"





p_object_3D new_object_3D () {
  p_object_3D object ;

  if ((object = calloc (1, sizeof (t_object_3D))) == NULL)
    exit_game () ;
  fprintf (stderr, "[Warning] implement new_object_3D and free_object_3D") ;
  return object ;
}

void init_object_3D_tile (p_object_3D object, int x, int y, int z, int w, int d, int h) {
  object->display = display_tile ;
  object->position.x = x ;
  object->position.y = y ;
  object->position.z = z ;
  object->dimensions.width = w ;
  object->dimensions.depth = d ;
  object->dimensions.height = h ;
  object->type = TILE ;
}

void init_object_3D_cylinder (p_object_3D object, int x, int y, int z, int radius, int height) {
  object->display = display_cylinder ;
  object->position.x = x ;
  object->position.y = y ;
  object->position.z = z ;
  object->dimensions.radius = radius ;
  object->dimensions.height = height ;
  object->type = CYLINDRE ;
}

void init_object_3D_text (p_object_3D object, int x, int y, int z, char *text, unsigned char r, unsigned char g, unsigned char b) {
  object->display = display_text ;
  object->position.x = x ;
  object->position.y = y ;
  object->position.z = z ;
  object->color.r = r ;
  object->color.g = g ;
  object->color.b = b ;
  object->tree = (p_tree)strdup (text) ;
  object->type = TEXT ;
}

static void _free_object_3D (p_object_3D object) {
  if (object != NULL) {
    if (object->type == TEXT && object->tree != NULL)
      free (object->tree) ;
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
  bzero (building, sizeof (t_building_3D)) ;
  building->objects = new_chained_list () ;
  set_chained_list_free_chain_value (building->objects, free_object_3D) ;
}

void init_random_building_3D (p_building_3D building) {
  if (building == NULL)
    return ;
  init_building_3D (building) ;
  generate_building (building) ;
}

void generate_building (p_building_3D building) {
  if (building == NULL)
    return ;
  building->dimensions.depth = generate_building_dimension () ;
  building->dimensions.width = generate_building_dimension () ;
  building->dimensions.height = generate_building_dimension () ;
}

int generate_building_dimension () {
  return (rand() % (BUILDING_MAX_DIMENSION / BUILDING_STEP_DIMENSION -
    BUILDING_MIN_DIMENSION / BUILDING_STEP_DIMENSION)) * BUILDING_STEP_DIMENSION +
    BUILDING_MIN_DIMENSION ;
}

void set_random_building_3D_position (p_building_3D building, int x, int y, int z) {
  if (building == NULL)
    return ;
  if (x == -1) {
    if (rand () % 2) {
      building->position.x = - ROAD_SPAN / 2 - generate_building_road_space () -
        building->dimensions.width ;
    } else {
      building->position.x = ROAD_SPAN / 2 + generate_building_road_space () ;
    }
  } else
    building->position.x = x ;
  building->position.y = y == -1 ? rand () % context.parameters.road_length : y ;
  building->position.z = z == -1 ? building->dimensions.height : z ;
}

int generate_building_road_space () {
  return (rand () % (BUILDING_MAX_DIMENSION - BUILDING_MIN_ROAD_SPACE)) + BUILDING_MIN_ROAD_SPACE ;
}

void generate_details (p_building_3D building) {
  generate_door (building) ;
  if (rand () % 2) 
    generate_window (building) ;
  if (rand () % 2) 
    generate_chimney (building) ;
}

void generate_door (p_building_3D building) {
  if (building == NULL)
    return ;
  t_object_3D door ;
  int door_pos ;

  bzero (&door, sizeof (t_object_3D)) ;
  switch (rand () % 2) {
    case 0:
      door_pos = rand () % (building->dimensions.depth - BUILDING_DOOR_WIDTH - 2) + 1 ;
      if (building->position.x > 0)
        init_object_3D_tile (&door, building->position.x-BUILDING_DOOR_DEPTH,
          building->position.y+door_pos, building->position.z-
          building->dimensions.height+1+BUILDING_DOOR_HEIGHT,
          BUILDING_DOOR_DEPTH, BUILDING_DOOR_WIDTH,
          BUILDING_DOOR_HEIGHT) ;
      else
        init_object_3D_tile (&door, building->position.x+building->dimensions.width+BUILDING_DOOR_DEPTH,
          building->position.y+door_pos, building->position.z-
          building->dimensions.height+1+BUILDING_DOOR_HEIGHT,
          BUILDING_DOOR_DEPTH, BUILDING_DOOR_WIDTH, 
          BUILDING_DOOR_HEIGHT) ;
      break ;
    case 1:
    default:
      door_pos = rand () % (building->dimensions.width - BUILDING_DOOR_WIDTH - 2) + 1 ;
      init_object_3D_tile (&door, building->position.x+door_pos,
        building->position.y-BUILDING_DOOR_DEPTH, building->position.z-
        building->dimensions.height+1+BUILDING_DOOR_HEIGHT,
        BUILDING_DOOR_WIDTH, BUILDING_DOOR_DEPTH,
        BUILDING_DOOR_HEIGHT) ;
      break ;
  }
  set_object_3D_color (&door, 145, 63, 0) ;
  push_chained_list (building->objects, &door, sizeof (t_object_3D)) ;
}

void generate_window (p_building_3D building) {
  if (building == NULL)
    return ;
  
}

void generate_chimney (p_building_3D building) {
  if (building == NULL)
    return ;
  
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
  bzero (obstacle, sizeof (t_obstacle_3D)) ;
  obstacle->objects = new_chained_list () ;
  set_chained_list_free_chain_value (obstacle->objects, free_object_3D) ;
}

void init_random_obstacle_3D (p_obstacle_3D obstacle) {
  if (obstacle == NULL)
    return ;
  init_obstacle_3D (obstacle) ;
  generate_obstacle (obstacle) ;
}

void generate_obstacle (p_obstacle_3D obstacle) {
  if (obstacle == NULL)
    return ;
  switch (rand () % 3) {
    //case 0:
      //break ;
    //case 1:
      //break ;
    case 2:
    default:
      generate_stop_sign (obstacle) ;
      break ;
  }
}

void generate_stop_sign (p_obstacle_3D obstacle) {
  t_object_3D pipe ;
  t_object_3D sign1 ;
  t_object_3D sign2 ;
  t_object_3D sign3 ;

  if (obstacle == NULL)
    return ;
  init_object_3D_cylinder (&pipe, 0, 0, 0, 1, 40) ;
  init_object_3D_cylinder (&sign1, 0, -2, 35, 8, 0.5) ;
  init_object_3D_cylinder (&sign2, 0, -3, 35, 7.5, 0.5) ;
  init_object_3D_tile (&sign3, -4, -4, 37, 8, 1, 3) ;
  set_object_3D_color (&pipe, 96, 96, 96) ;
  set_object_3D_color (&sign1, 96, 96, 96) ;
  set_object_3D_color (&sign2, 250, 0, 0) ;
  set_object_3D_color (&sign3, 255, 255, 255) ;
  sign1.transform.angle_x = 90 ;
  sign1.transform.angle_z = 90 ;
  sign2.transform.angle_x = 90 ;
  sign2.transform.angle_z = 90 ;
  sign3.transform.angle_x = 90 ;
  sign3.transform.angle_z = 90 ;
  push_chained_list (obstacle->objects, &pipe, sizeof (t_object_3D)) ;
  push_chained_list (obstacle->objects, &sign1, sizeof (t_object_3D)) ;
  push_chained_list (obstacle->objects, &sign2, sizeof (t_object_3D)) ;
  push_chained_list (obstacle->objects, &sign3, sizeof (t_object_3D)) ;
  
}

void set_random_obstacle_3D_position (p_obstacle_3D obstacle, int x, int y, int z) {
  if (obstacle == NULL)
    return ;
  obstacle->position.x = x == -1 ? -ROAD_SPAN / 4 + ROAD_SPAN / 2 * (rand () % 2) : x ;
  obstacle->position.y = y == -1 ? rand () % context.parameters.road_length : y ;
  obstacle->position.z = z == -1 ? 0 : z ;
  for_chained_list_value (obstacle->objects) {
    ((p_object_3D) value)->position.x += obstacle->position.x ;
    ((p_object_3D) value)->position.y += obstacle->position.y ;
    ((p_object_3D) value)->position.z += obstacle->position.z ;
  }
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

void set_object_3D_color (p_object_3D object, unsigned char r, unsigned char g, unsigned char b) {
  object->color.r = r ;
  object->color.g = g ;
  object->color.b = b ;
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