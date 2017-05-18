
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

#define ROAD_SPAN 60
#define ROAD_MID_SPAN ROAD_SPAN / 2

#define WHEEl_RAY 1
#define WHEEl_HEIGHT WHEEL_RAY * 2

#define VEHICLE_WIDTH ROAD_SPAN / 6
#define VEHICLE_LENGTH ROAD_SPAN / 4
#define VEHICLE_HEIGHT 10

#define VEHICLE_POS_X -VEHICLE_WIDTH/2
#define VEHICLE_POS_Y -40
#define VEHICLE_POS_Z VEHICLE_HEIGHT+WHEEl_RAY

#define VEHICLE_THICKNESS 1.5

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
