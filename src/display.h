
#ifndef _DISPLAY_H
#define _DISPLAY_H


#include <unistd.h>
#include <math.h>

#include "GL/gl.h"
#include "GL/glut.h"
#include "ktree.h"
#include "chained_list.h"
#include "objects_3D.h"


#define SPHERE    0x01
#define CYLINDRE  0x02
#define CUBE      0x03
#define CONE      0x04

#define ARMS_INTO_VEHICLE 0
#define ARMS_ON_RIGHT 1
#define ARMS_ON_LEFT 2
#define PUT_YOUR_HANDS_UP 3

#define ROAD_BEGINNING_Y -100.0f

void *display_cylinder (p_object_3D cylinder) ;
void *display_cone (p_object_3D cone) ;
void *display_sphere (p_object_3D sphere) ;
void *display_cube (p_object_3D cube) ;
void display_building (p_building_3D building) ;
void display_obstacle (p_obstacle_3D obstacle) ;
void display_bonus (p_bonus_3D bonus) ;
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
