
#ifndef _DISPLAY_H
#define _DISPLAY_H


#include "GL/gl.h"
#include "GL/glut.h"
#include "ktree.h"
#include "chained_list.h"

#define SPHERE    0x01
#define CYLINDRE  0x02
#define CUBE      0x03
#define CONE      0x04


typedef struct s_player_object_3D t_player_object_3D ;
typedef t_player_object_3D* p_player_object_3D ;

typedef struct s_object_3D t_object_3D ;
typedef t_object_3D* p_object_3D ;

typedef struct s_position_3D t_position_3D ;
typedef t_position_3D* p_position_3D ;

typedef void *(*p_display_object_3D_method) (void *) ;


struct s_position_3D {
  int x ;
  int y ;
  int z ;
} ;

struct s_object_3D {
  p_tree tree ;
  p_display_object_3D_method display ;
  t_position_3D position ;
  char type ;
} ;

struct s_player_object_3D {
  t_object_3D body ;
  t_object_3D left_arm ;
  t_object_3D right_arm ;
  t_object_3D head ;
  t_object_3D vehicle ;
} ;

void *display_cylinder (p_object_3D cylinder) ;
void *display_cone (p_object_3D cone) ;
void *display_sphere (p_object_3D sphere) ;
void *display_cube (p_object_3D cube) ;
void display_background (void) ;
void display_road (void) ;
void display_buildings (void) ;
void display_obstacles (void) ;
void display_all_bonus (void) ;
void display_character (void) ;
void display_screen (void) ;
void animation (void) ;


#include "common.h"


#endif
