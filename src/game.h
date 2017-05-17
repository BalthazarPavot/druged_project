
#ifndef _GAME_H
#define _GAME_H


#include "GL/gl.h"
#include "GL/glut.h"


#include "common.h"
#include "display.h"
#include "event_handler.h"


t_context context ;

void parse_arguments (int argc, char *argv[]) ;
void initialize_opengl () ;
void generate_game () ;
void play_game () ;
void exit_game () ;


#endif
