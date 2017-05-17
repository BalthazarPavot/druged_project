
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
} ;

struct s_context {
  char **argv ;
  t_parameters parameters ;
  t_chained_list buildings ;
  t_chained_list obstacles ;
  t_chained_list bonus ;
  t_player player ;
  int argc ;
  int window_id ;
} ;


#endif
