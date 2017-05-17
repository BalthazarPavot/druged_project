

#include "display.h"



static void _display_cylinder (float base, float top, float height, float slices, float stacks) {
  gluCylinder (context.quadObj, base, top, height, slices, stacks);

  /*
  GLUquadricObj *quadObj = gluNewQuadric();
  gluCylinder(quadObj, base, top, height, slices, stacks);
  * 
  * or
  * 
  *
  float radius, halfLength;
  int slices;
  for(int i=0; i<slices; i++) {
    float theta = ((float)i)*2.0*M_PI;
    float nextTheta = ((float)i+1)*2.0*M_PI;
    glBegin(GL_TRIANGLE_STRIP);
  *vertex at middle of end *
    glVertex3f(0.0, halfLength, 0.0);
  *vertices at edges of circle*
    glVertex3f(radius*cos(theta), halfLength, radius*sin(theta));
    glVertex3f (radius*cos(nextTheta), halfLength, radius*sin(nextTheta));
  * the same vertices at the bottom of the cylinder*
    glVertex3f (radius*cos(nextTheta), -halfLength, radius*sin(nextTheta));
    glVertex3f(radius*cos(theta), -halfLength, radius*sin(theta));
    glVertex3f(0.0, -halfLength, 0.0);
    glEnd();
  }
  */
}

static void _display_default_cylinder (float base, float top, float height) {
  _display_cylinder (base, top, height, height*2, 16) ;
}

static void _display_sphere () {
  /*
  GLUquadricObj *quadObj = gluNewQuadric();
  gluCylinder(quadObj, base, top, height, slices, stacks);
  */
}

static void _display_cube (float x, float y, float z, float dx, float dy, float dz) {
  float currentColor[4];
  glGetFloatv (GL_CURRENT_COLOR, currentColor);
  glBegin(GL_QUADS);
  dz = -dz ;

  /* up OK */
  glVertex3f(x, y, z);
  glVertex3f(x+dx, y, z);
  glVertex3f(x+dx, y+dy, z);
  glVertex3f(x, y+dy, z); 

  glColor3f(currentColor[0]*0.9, currentColor[1]*0.9, currentColor[2]*0.9);
  /* front OK */
  glVertex3f(x, y, z);
  glVertex3f(x+dx, y, z);
  glVertex3f(x+dx, y, z+dz);
  glVertex3f(x, y, z+dz);

  glColor3f(currentColor[0]*0.8, currentColor[1]*0.8, currentColor[2]*0.8);
  /* right */
  glVertex3f(x+dx, y, z);
  glVertex3f(x+dx, y+dy, z);
  glVertex3f(x+dx, y+dy, z+dz);
  glVertex3f(x+dx, y, z+dz);

  glColor3f(currentColor[0]*0.95, currentColor[1]*0.95, currentColor[2]*0.95);
  /* left */
  glVertex3f(x, y, z);
  glVertex3f(x, y+dy, z);
  glVertex3f(x, y+dy, z+dz);
  glVertex3f(x, y, z+dz);

  glColor3f(currentColor[0]*0.5, currentColor[1]*0.5, currentColor[2]*0.5);
  /* back */
  glVertex3f(x, y+dy, z);
  glVertex3f(x+dx, y+dy, z);
  glVertex3f(x+dx, y+dy, z+dz);
  glVertex3f(x, y+dy, z+dz);

  glColor3f(currentColor[0]*0.3, currentColor[1]*0.3, currentColor[2]*0.3);
  /* bottom */
  glVertex3f(x, y, z+dz);
  glVertex3f(x+dx, y, z+dz);
  glVertex3f(x+dx, y+dy, z+dz);
  glVertex3f(x, y+dy, z+dz);

  glEnd();
  glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

static void _display_real_cube (float x, float y, float z, float w) {
  _display_cube (x, y, z, w, w, w) ;
}

static void _display_vehicle () {
  glColor3f(170./255, 97./255, 41./255);
  
  /* bottom */
  _display_cube (
    VEHICLE_POS_X, VEHICLE_POS_Y, VEHICLE_POS_Z,
    VEHICLE_WIDTH, VEHICLE_LENGTH, VEHICLE_THICKNESS
  ) ;
  /* left */
  _display_cube (
    VEHICLE_POS_X, VEHICLE_POS_Y+VEHICLE_THICKNESS, VEHICLE_POS_Z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_THICKNESS, VEHICLE_LENGTH-VEHICLE_THICKNESS*2, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* right */
  _display_cube (
    VEHICLE_POS_X+VEHICLE_WIDTH-VEHICLE_THICKNESS, VEHICLE_POS_Y+VEHICLE_THICKNESS, VEHICLE_POS_Z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_THICKNESS, VEHICLE_LENGTH-VEHICLE_THICKNESS*2, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* front */
  _display_cube (
    VEHICLE_POS_X, VEHICLE_POS_Y+VEHICLE_LENGTH-VEHICLE_THICKNESS, VEHICLE_POS_Z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_WIDTH, VEHICLE_THICKNESS, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* back */
  _display_cube (
    VEHICLE_POS_X, VEHICLE_POS_Y, VEHICLE_POS_Z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_WIDTH, VEHICLE_THICKNESS, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
}

static void _display_character_into_vehicle () {
  glPushMatrix (); //remember current matrix
  glTranslatef (VEHICLE_POS_X+VEHICLE_WIDTH/2,
    VEHICLE_POS_Y+VEHICLE_LENGTH/2, 10);
  glColor3f(1.0f, 1.0f, 1.0f);
  _display_default_cylinder (3, 0, 15) ;
  glPopMatrix (); //restore matrix
}

static void _display_character_on_left () {
  
}

static void _display_character_on_right () {
  
}

static void _display_character_hands_up () {
  
}

void *display_cylinder (p_object_3D cylinder) {
  _display_cylinder (0, 0, 0, 0, 0) ;
  return cylinder ;
}

void *display_cone (p_object_3D cone) {
  _display_cylinder (0, 0, 0, 0, 0) ;
  return cone ;
}

void *display_sphere (p_object_3D sphere) {
  _display_sphere () ;
  return sphere ;
}

void *display_cube (p_object_3D cube) {
  _display_real_cube (0, 0, 0, 0) ;
  return cube ;
}

void display_background (void) {
  glColor3f(91./255, 40./255, 0.0f);
  glBegin(GL_QUADS);
  glVertex3f(-context.game_state.bg_begin_animation_x, context.game_state.bg_begin_animation_y,  -0.1f);
  glVertex3f(context.game_state.bg_begin_animation_x, context.game_state.bg_begin_animation_y,  -0.1f);
  glVertex3f(50.0f, ROAD_BEGINNING_Y, -0.1f);
  glVertex3f(-50.0f, ROAD_BEGINNING_Y, -0.1f);
  glEnd();
}

void display_road (void) {
  glColor3f(145./255, 63./255, 0.0f);
  glBegin(GL_QUADS);
  glVertex3f(-ROAD_MID_SPAN, context.game_state.road_begin_animation_y,  0.0f);
  glVertex3f(ROAD_MID_SPAN, context.game_state.road_begin_animation_y,  0.0f);
  glVertex3f(ROAD_MID_SPAN, ROAD_BEGINNING_Y, 0.0f);
  glVertex3f(-ROAD_MID_SPAN, ROAD_BEGINNING_Y, 0.0f);
  glEnd();
}

void display_building (p_building_3D building) {
  for_chained_list_value_of_type (building->objects, p_object_3D) {
    if (value->position.x - context.player.position > 100)
      return ;
  }
}

void display_obstacle (p_obstacle_3D obstacle) {
  for_chained_list_value_of_type (obstacle->objects, p_object_3D) {
    if (value->position.x - context.player.position > 100)
      return ;
  }
}

void display_bonus (p_bonus_3D bonus) {
  for_chained_list_value_of_type (bonus->objects, p_object_3D) {
    if (value->position.x - context.player.position > 100)
      return ;
  }
}

void display_buildings (void) {
  for_chained_list_value_of_type (context.buildings, p_building_3D) {
    display_building (value) ;
  }
}

void display_obstacles (void) {
  for_chained_list_value_of_type (context.obstacles, p_obstacle_3D) {
    display_obstacle (value) ;
  }
}

void display_all_bonus (void) {
  for_chained_list_value_of_type (context.bonus, p_bonus_3D) {
    display_bonus (value) ;
  }
}

void display_character (void) {
  _display_vehicle () ;
  if (context.player.arms_position == ARMS_INTO_VEHICLE) 
    _display_character_into_vehicle () ;
  else if (context.player.arms_position == ARMS_ON_RIGHT) 
    _display_character_on_right () ;
  else if (context.player.arms_position == ARMS_ON_LEFT) 
    _display_character_on_left () ;
  else if (context.player.arms_position == PUT_YOUR_HANDS_UP) 
    _display_character_hands_up () ;
}

void display_screen (void) {

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
  glMatrixMode (GL_MODELVIEW) ;

  display_background () ;
  display_road () ;
  display_buildings () ;
  display_obstacles () ;
  display_all_bonus () ;
  display_character () ;

  glutSwapBuffers () ;
}

void animation (void) {
  if (!context.game_state.vrooming) {
    context.game_state.road_begin_animation_y += 0.5 ;
    context.game_state.bg_begin_animation_x += 0.5 ;
    context.game_state.bg_begin_animation_y += 0.5 ;
    if (context.game_state.bg_begin_animation_x >= 1500) {
      context.game_state.vrooming = 1 ;
    }
  }
  if (context.key_down.rotate_left)
    glRotatef(-0.1, 0, 1, VEHICLE_POS_Z);
  else if (context.key_down.rotate_right)
    glRotatef(0.1, 0, 1, VEHICLE_POS_Z);
  if (context.key_down.rotate_up) {
    glRotatef(-0.1, 1, 0, 0);
  } else if (context.key_down.rotate_down) {
    glRotatef(0.1, 1, 0, 0);
  }
  sleep (0.5) ;
  glutPostRedisplay () ;
}
