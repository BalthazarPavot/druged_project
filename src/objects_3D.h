
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

p_building_3D new_building_3D ()  ;
void free_building_3D (p_building_3D building) ;
p_obstacle_3D new_obstacle_3D () ;
void free_obstacle_3D (p_obstacle_3D obstacle) ;
p_bonus_3D new_bonus_3D () ;
void free_bonus_3D (p_bonus_3D bonus) ;


#include "game.h"

#endif
