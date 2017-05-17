
#ifndef _COMMON_H
#define _COMMON_H


#include "chained_list.h"
#include "display.h"


#define TITLE "Drug! Drug! Drug! Drug!"


typedef struct s_context t_context ;
typedef t_context* p_context ;

typedef struct s_parameters t_parameters ;
typedef t_parameters* p_parameters ;

typedef struct s_player t_player ;
typedef t_player* p_player ;

typedef struct s_key_down t_key_down ;
typedef t_key_down* p_key_down ;

typedef struct s_game_state t_game_state ;

t_context context ;

struct s_parameters {
  int building_velocity ;
  int obstacle_velocity ;
  int bonus_velocity ;
  int road_length ;
} ;

struct s_player {
  int score ;
  int score_multiplier ;
  int position ; /* relatively to the road length */
  t_player_object_3D object ;
  char arms_position ;
} ;

struct s_game_state {
  float road_begin_animation_y ;
  float bg_begin_animation_x ;
  float bg_begin_animation_y ;
  char vrooming ;
} ;

struct s_key_down {
  char rotate_left ;
  char rotate_right ;
  char rotate_up ;
  char rotate_down ;
} ;

struct s_context {
  char **argv ;
  GLUquadricObj *quadObj ;
  t_game_state game_state ;
  t_parameters parameters ;
  p_chained_list buildings ;
  p_chained_list obstacles ;
  p_chained_list bonus ;
  t_key_down key_down ;
  t_player player ;
  int argc ;
  int window_id ;
} ;


#endif
