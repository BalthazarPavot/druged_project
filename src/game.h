
#ifndef _GAME_H
#define _GAME_H


#include <math.h>
#include <time.h>


#include "GL/gl.h"
#include "GL/glut.h"
#include "GL/freeglut.h" 



#include "chained_list.h"
#include "display.h"
#include "common.h"
#include "event_handler.h"
#include "objects_3D.h"

#define DISTANCE_REDUCTOR 1.


t_context context ;

void generate_default_context () ;
void parse_arguments (int argc, char *argv[]) ;
void initialize_opengl () ;
void generate_game () ;
void generate_buildings (float frequency, int length) ;
int add_new_building (int distance) ;
void generate_obstacles_n_bonus (float frequency, int length)  ;
int add_new_obstacle (int distance)  ;
int add_new_bonus (int distance) ;
void play_game () ;
void exit_game () ;


#endif
