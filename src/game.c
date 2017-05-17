

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
  context.game_state.road_begin_animation_y = -52.5 ;
}

void initialize_opengl () {
  glutInit (&context.argc, context.argv) ;
  glutInitWindowSize (800, 600) ;
  glutInitWindowPosition (50, 50) ;
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH) ;
  context.window_id = glutCreateWindow (TITLE) ;
  glEnable (GL_DEPTH_TEST) ;
  glClearColor(91./255, 40./255, 225.0f/255, 1.0f);
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
  glutSpecialFunc (handle_special) ;

  glutSetWindow (context.window_id) ;

  glFrustum (-2, 2, -2, 2, 2, 1500) ;
  gluLookAt (0, -60, 40, 0, 0, 0, 0, 0, 1) ;

  context.quadObj = gluNewQuadric();

  glutMainLoop ();
  
  exit_game () ;
}

void destroyContext () {
  for_chained_list_value_of_type (context.buildings, p_building_3D) {
    free_chained_list (value->objects) ;
    value->objects = NULL ;
  }
  free_chained_list (context.buildings) ;
  context.buildings = NULL ;
  for_chained_list_value_of_type (context.obstacles, p_obstacle_3D) {
    free_chained_list (value->objects) ;
    value->objects = NULL ;
  }
  free_chained_list (context.obstacles) ;
  context.obstacles = NULL ;
  for_chained_list_value_of_type (context.bonus, p_bonus_3D) {
    free_chained_list (value->objects) ;
    value->objects = NULL ;
  }
  free_chained_list (context.bonus) ;
  context.bonus = NULL ;
  if (context.quadObj != NULL)
    gluDeleteQuadric(context.quadObj);
}

void exit_game () {
  destroyContext () ;
  glutLeaveMainLoop () ;
  glutDestroyWindow (context.window_id) ;
  exit (0) ;
}