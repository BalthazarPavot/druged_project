

#include "game.h"


void generate_default_context () {
  bzero (&context, sizeof (t_context)) ;
  context.buildings = new_chained_list () ;
  context.obstacles = new_chained_list () ;
  context.bonus = new_chained_list () ;
  context.parameters.bonus_velocity = 0.35 ;
  context.parameters.building_velocity = 0.3 ;
  context.parameters.obstacle_velocity = 0.25 ;
  context.parameters.road_length = 1000 ;
}

void initialize_opengl () {
  glutInit (&context.argc, context.argv) ;
  glutInitWindowSize (800, 600) ;
  glutInitWindowPosition (50, 50) ;
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH) ;
  context.window_id = glutCreateWindow (TITLE) ;
  glEnable (GL_DEPTH_TEST) ;
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void parse_arguments (int argc, char *argv[]) {
  context.argc = argc ;
  context.argv = argv ;
}

void generate_game () {
  srand(time(NULL)) ;
  
}

void play_game () {

  glutIdleFunc (animation) ;
  glutDisplayFunc (display_screen) ;

  glutMouseFunc (handle_mouse) ;
  glutKeyboardFunc (handle_keyboard);

  glutMainLoop ();
}


void exit_game () {
  //glXDestroyContext (context.window_id, )
  glutDestroyWindow (context.window_id) ;
  exit (0) ;
}