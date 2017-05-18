

#include "game.h"



void generate_default_context () {
  bzero (&context, sizeof (t_context)) ;
  context.buildings = new_chained_list () ;
  context.obstacles = new_chained_list () ;
  context.bonus = new_chained_list () ;
  set_chained_list_free_chain_value (context.buildings, free_building_3D) ;
  set_chained_list_free_chain_value (context.obstacles, free_object_3D) ;
  set_chained_list_free_chain_value (context.bonus, free_bonus_3D) ;
  context.parameters.bonus_frequency = 0.35 ;
  context.parameters.building_frequency = 0.3 ;
  context.parameters.obstacle_frequency = 0.25 ;
  context.parameters.road_length = 50000 ;
  context.game_state.road_begin_animation_y = -52.5 ;
  context.player.speed = 0.1 ;
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
  if (argc > 1)
    context.parameters.road_length = atoi (argv[1]) ;
  else
    context.parameters.road_length = 50000 ;
}

void generate_game () {
  srand(time(NULL)) ;
  generate_buildings (context.parameters.building_frequency, context.parameters.road_length) ;
  generate_obstacles (context.parameters.obstacle_frequency, context.parameters.road_length) ;
  generate_bonus (context.parameters.bonus_frequency, context.parameters.road_length) ;
  printf ("%d buildings\n%d obstacles\n%d bonus\n",
    length_chained_list (context.buildings), 
    length_chained_list (context.obstacles), 
    length_chained_list (context.bonus)
  ) ;
}

void generate_buildings (float frequency, int length) {
  for (int distance=0 ; distance < length ; distance += 1)
    if ((double)rand() / (double)RAND_MAX < frequency)
      distance += add_new_building (distance) + BUILDING_STEP_DIMENSION * 2 ;
}

int add_new_building (int distance) {
  t_building_3D building ;

  init_random_building_3D (&building) ;
  set_random_building_3D_position (&building, -1, distance, -1) ;
  generate_details (&building) ;
  push_chained_list (context.buildings, &building, sizeof (t_building_3D)) ;
  return building.dimensions.depth ;
}

void generate_obstacles (float frequency, int length) {
  for (int distance=0 ; distance < length ; distance += 1)
    if ((double)rand() / (double)RAND_MAX < frequency)
      distance += add_new_obstacle (distance) ;
}

int add_new_obstacle (int distance) {
  t_obstacle_3D obstacle ;

  init_random_obstacle_3D (&obstacle) ;
  set_random_obstacle_3D_position (&obstacle, -1, distance, -1) ;
  push_chained_list (context.obstacles, &obstacle, sizeof (t_obstacle_3D)) ;
  obstacle.dimensions.depth = 10 ;
  return obstacle.dimensions.depth ;
}

void generate_bonus (float frequency, int length) {
  for (int distance=0 ; distance < length ; distance += 1)
    if ((double)rand() / (double)RAND_MAX < frequency)
      distance += add_new_bonus (distance) ;
}

int add_new_bonus (int distance) {
  t_bonus_3D bonus ;

  init_random_bonus_3D (&bonus) ;
  set_random_bonus_3D_position (&bonus, -1, distance, -1) ;
  push_chained_list (context.bonus, &bonus, sizeof (t_bonus_3D)) ;
  bonus.dimensions.depth = 10 ;
  return bonus.dimensions.depth ;
}

void play_game () {

  glutIdleFunc (animation) ;
  glutDisplayFunc (display_screen) ;

  glutMouseFunc (handle_mouse) ;
  glutKeyboardFunc (handle_keyboard);
  glutSpecialFunc (handle_special) ;

  glutSetWindow (context.window_id) ;

  glFrustum (-2, 2, -2, 2, 2, context.parameters.road_length) ;
  gluLookAt (0, -60, 40, 0, 0, 0, 0, 0, 1) ;

  context.quadObj = gluNewQuadric();

  glutMainLoop ();
  
  exit_game () ;
}

void destroyContext () {
  //for_chained_list_value_of_type (context.buildings, p_building_3D) {
    //free_chained_list (value->objects) ;
    //value->objects = NULL ;
  //}
  free_chained_list (context.buildings) ;
  context.buildings = NULL ;
  //for_chained_list_value_of_type (context.obstacles, p_obstacle_3D) {
    //free_chained_list (value->objects) ;
    //value->objects = NULL ;
  //}
  free_chained_list (context.obstacles) ;
  context.obstacles = NULL ;
  //for_chained_list_value_of_type (context.bonus, p_bonus_3D) {
    //free_chained_list (value->objects) ;
    //value->objects = NULL ;
  //}
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