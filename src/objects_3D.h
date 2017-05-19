
#ifndef _OBJECTS_3D_H
#define _OBJECTS_3D_H


#include "chained_list.h"
#include "ktree.h"

#define BUILDING_MIN_DIMENSION 20
#define BUILDING_MAX_DIMENSION 60
#define BUILDING_STEP_DIMENSION 5
#define BUILDING_MIN_ROAD_SPACE 10
#define BUILDING_MAX_ROAD_SPACE 20
#define BUILDING_DOOR_HEIGHT 15
#define BUILDING_DOOR_WIDTH 5
#define BUILDING_DOOR_DEPTH 1


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

typedef struct s_color t_color ;
typedef t_color* p_color ;

typedef struct s_dimension_3D t_dimension_3D ;
typedef t_dimension_3D* p_dimension_3D ;

typedef struct s_transform_3D t_transform_3D ;
typedef t_transform_3D* p_transform_3D ;

typedef void *(*p_display_object_3D_method) (p_object_3D) ;


struct s_position_3D {
  float x ;
  float y ;
  float z ;
} ;

struct s_dimension_3D {
  int width ;
  int height ;
  int depth ;
  int radius ;
  int second_radius ;
} ;

struct s_transform_3D {
  float angle_x ;
  float angle_y ;
  float angle_z ;
} ;

struct s_color {
  unsigned char r ;
  unsigned char g ;
  unsigned char b ;
} ;

struct s_object_3D {
  p_tree tree ;
  p_display_object_3D_method display ;
  t_position_3D position ;
  t_dimension_3D dimensions ;
  t_color color ;
  t_transform_3D transform ;
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
void init_object_3D_tile (p_object_3D object, int x, int y, int z, int w, int d, int h) ;
void init_object_3D_cylinder (p_object_3D object, int x, int y, int z, int radius, int height) ;
void free_object_3D (void *object) ;

p_building_3D new_building_3D ()  ;
void init_random_building_3D (p_building_3D building) ;
void init_building_3D (p_building_3D building) ;
void generate_building (p_building_3D building) ;
int generate_building_dimension () ;
void set_random_building_3D_position (p_building_3D building, int x, int y, int z) ;
int generate_building_road_space () ;
void generate_details (p_building_3D building) ;
void generate_door (p_building_3D building) ;
void generate_window (p_building_3D building) ;
void generate_chimney (p_building_3D building) ;
void free_building_3D (void *building) ;

p_obstacle_3D new_obstacle_3D () ;
void init_obstacle_3D (p_obstacle_3D obstacle) ;
void init_random_obstacle_3D (p_obstacle_3D obstacle) ;
void generate_obstacle (p_obstacle_3D obstacle) ;
void generate_stop_sign (p_obstacle_3D obstacle) ;
void set_random_obstacle_3D_position (p_obstacle_3D obstacle, int x, int y, int z) ;
void free_obstacle_3D (void *obstacle) ;

p_bonus_3D new_bonus_3D () ;
void init_bonus_3D (p_bonus_3D bonus) ;
void init_random_bonus_3D (p_bonus_3D bonus) ;
void set_random_bonus_3D_position (p_bonus_3D bonus, int x, int y, int z) ;
void set_object_3D_color (p_object_3D object, unsigned char r, unsigned char g, unsigned char b) ;
void free_bonus_3D (void *bonus) ;


#include "game.h"

#endif
