
#ifndef _GAME_H
#define _GAME_H


#include <time.h>


#include "GL/gl.h"
#include "GL/glut.h"
#include "GL/freeglut.h" 



#include "chained_list.h"
#include "common.h"
#include "display.h"
#include "event_handler.h"


t_context context ;

void generate_default_context () ;
void parse_arguments (int argc, char *argv[]) ;
void initialize_opengl () ;
void generate_game () ;
void play_game () ;
void exit_game () ;


#endif
