
#ifndef _OBJECTS_3D_H
#define _OBJECTS_3D_H


#include "chained_list.h"
#include "ktree.h"


typedef struct s_player_object_3D t_player_object_3D ;
typedef t_player_object_3D* p_player_object_3D ;

typedef struct s_bonus_3D t_bonus_3D ;
typedef t_bonus_3D* p_bonus_3D ;

typedef struct s_obstacle_3D t_obstacle_3D ;
typedef t_obstacle_3D* p_obstacle_3D ;

typedef struct s_building_3D t_building_3D ;
typedef t_building_3D* p_building_3D ;

typedef struct s_object_3D t_object_3D ;
typedef t_object_3D* p_object_3D ;

typedef struct s_position_3D t_position_3D ;
typedef t_position_3D* p_position_3D ;

typedef struct s_dimension_3D t_dimension_3D ;
typedef t_dimension_3D* p_dimension_3D ;

typedef void *(*p_display_object_3D_method) (void *) ;


struct s_position_3D {
  int x ;
  int y ;
  int z ;
} ;

struct s_dimension_3D {
  int width ;
  int height ;
  int depth ;
  int radius ;
  int second_radius ;
} ;

struct s_object_3D {
  p_tree tree ;
  p_display_object_3D_method display ;
  t_position_3D position ;
  t_dimension_3D dimensions ;
  char type ;
} ;

struct s_building_3D {
  p_chained_list objects ;
  t_position_3D position ;
  t_dimension_3D dimensions ;
  char type ;
} ;

struct s_obstacle_3D {
  p_chained_list objects ;
  t_position_3D position ;
  t_dimension_3D dimensions ;
  char type ;
} ;

struct s_bonus_3D {
  p_chained_list objects ;
  t_position_3D position ;
  t_dimension_3D dimensions ;
  char type ;
} ;

struct s_player_object_3D {
  t_object_3D body ;
  t_object_3D left_arm ;
  t_object_3D right_arm ;
  t_object_3D head ;
  t_object_3D vehicle ;
} ;

p_object_3D new_object_3D () ;
void free_object_3D (void *object) ;

p_building_3D new_building_3D ()  ;
void init_random_building_3D (p_building_3D building) ;
void init_building_3D (p_building_3D building) ;
void generate_building (p_building_3D building) ;
void generate_building_0 (p_building_3D building) ;
void generate_building_1 (p_building_3D building) ;
void generate_building_2 (p_building_3D building) ;
void set_random_building_3D_position (p_building_3D building, int x, int y, int z) ;
void free_building_3D (void *building) ;

p_obstacle_3D new_obstacle_3D () ;
void init_obstacle_3D (p_obstacle_3D obstacle) ;
void init_random_obstacle_3D (p_obstacle_3D obstacle) ;
void set_random_obstacle_3D_position (p_obstacle_3D obstacle, int x, int y, int z) ;
void free_obstacle_3D (void *obstacle) ;

p_bonus_3D new_bonus_3D () ;
void init_bonus_3D (p_bonus_3D bonus) ;
void init_random_bonus_3D (p_bonus_3D bonus) ;
void set_random_bonus_3D_position (p_bonus_3D bonus, int x, int y, int z) ;
void free_bonus_3D (void *bonus) ;


#include "game.h"

#endif
