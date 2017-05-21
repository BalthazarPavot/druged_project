

#include "game.h"



void generate_default_context () {
  bzero (&context, sizeof (t_context)) ;
  context.buildings = new_chained_list () ;
  context.obstacles = new_chained_list () ;
  context.bonus = new_chained_list () ;
  set_chained_list_free_chain_value (context.buildings, free_building_3D) ;
  set_chained_list_free_chain_value (context.obstacles, free_obstacle_3D) ;
  set_chained_list_free_chain_value (context.bonus, free_bonus_3D) ;
  context.parameters.bonus_frequency = 0.1 ;
  context.parameters.building_frequency = 0.3 ;
  context.parameters.obstacle_frequency = 0.007 + context.parameters.bonus_frequency;
  context.parameters.road_length = 50000 ;
  context.game_state.road_begin_animation_y = -52.5 ;
  context.player.speed = BASE_SPEED ;
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
    context.parameters.road_length = fmax (atoi (argv[1]), 1000) ;
  else
    context.parameters.road_length = 50000 ;
}

void generate_game () {
  srand(time(NULL)) ;
  generate_buildings (context.parameters.building_frequency, context.parameters.road_length) ;
  generate_obstacles_n_bonus (context.parameters.obstacle_frequency, context.parameters.road_length) ;
  //generate_bonus (context.parameters.bonus_frequency, context.parameters.road_length) ;
  printf ("%d buildings\n%d obstacles\n%d bonus\n",
    length_chained_list (context.buildings), 
    length_chained_list (context.obstacles), 
    length_chained_list (context.bonus)
  ) ;
}

void generate_buildings (float frequency, int length) {
  for (int distance=100 ; distance < length ; distance += 1)
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

void generate_obstacles_n_bonus (float frequency, int length) {
  for (int distance=100 ; distance < length ; distance += 1)
    if ((double)rand() / (double)RAND_MAX < frequency)
      distance += rand () % 2 ? add_new_obstacle (distance) : add_new_bonus (distance) ;
}

int add_new_obstacle (int distance) {
  t_obstacle_3D obstacle ;
  p_chain last_obstacle ;

  last_obstacle = chained_list_last (context.obstacles) ;
  if (last_obstacle != NULL &&
      ((p_obstacle_3D)last_obstacle->value)->type == SIGN)
    init_random_obstacle_3D (&obstacle) ;
  else
    init_random_sign (&obstacle) ;
  set_random_obstacle_3D_position (&obstacle, -1, distance, -1) ;
  push_chained_list (context.obstacles, &obstacle, sizeof (t_obstacle_3D)) ;
  //return obstacle.dimensions.depth ;
  return (obstacle.type == SIGN ? 20 : 50) / DISTANCE_REDUCTOR ;
}

int add_new_bonus (int distance) {
  t_bonus_3D bonus ;

  init_random_bonus_3D (&bonus) ;
  set_random_bonus_3D_position (&bonus, -1, distance, -1) ;
  push_chained_list (context.bonus, &bonus, sizeof (t_bonus_3D)) ;
  return 20 / DISTANCE_REDUCTOR ;
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
  free_chained_list (context.buildings) ;
  context.buildings = NULL ;
  free_chained_list (context.obstacles) ;
  context.obstacles = NULL ;
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
