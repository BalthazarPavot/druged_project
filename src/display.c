

#include "display.h"



static void _display_cylinder (float base, float top, float height, float slices, float stacks) {
  glMatrixMode(GL_PROJECTION);
  gluCylinder (context.quadObj, base, top, height, slices, stacks);
  glMatrixMode(GL_MODELVIEW);

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
  _display_cylinder (base, top, height, 16, 16) ;
}

static void _display_sphere (float radius, float slices, float stacks) {
   glutSolidSphere (radius, slices, stacks);
}

static void _display_default_sphere (float radius) {
   _display_sphere (radius, 20, 20);
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
  float y = context.player.position + VEHICLE_POS_Y ;
  float z = VEHICLE_POS_Z + context.player.height ;
  /* bottom */
  _display_cube (
    VEHICLE_POS_X, y, z,
    VEHICLE_WIDTH, VEHICLE_LENGTH, VEHICLE_THICKNESS
  ) ;
  /* left */
  _display_cube (
    VEHICLE_POS_X, y+VEHICLE_THICKNESS, z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_THICKNESS, VEHICLE_LENGTH-VEHICLE_THICKNESS*2, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* right */
  _display_cube (
    VEHICLE_POS_X+VEHICLE_WIDTH-VEHICLE_THICKNESS, y+VEHICLE_THICKNESS, z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_THICKNESS, VEHICLE_LENGTH-VEHICLE_THICKNESS*2, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* front */
  _display_cube (
    VEHICLE_POS_X, y+VEHICLE_LENGTH-VEHICLE_THICKNESS, z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_WIDTH, VEHICLE_THICKNESS, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;
  /* back */
  _display_cube (
    VEHICLE_POS_X, y, z+VEHICLE_HEIGHT-VEHICLE_THICKNESS,
    VEHICLE_WIDTH, VEHICLE_THICKNESS, VEHICLE_HEIGHT-VEHICLE_THICKNESS
  ) ;

  glPushMatrix () ;

  /* left wheel */
  glTranslatef (VEHICLE_POS_X-VEHICLE_THICKNESS-0.2, y+WHEEl_RAY/2, WHEEl_RAY + context.player.height) ;
  glRotatef ( 80, 0, 1, 0) ;
  _display_default_cylinder (WHEEl_RAY, WHEEl_RAY, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.95, 97./255*0.95, 41./255*0.95);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glTranslatef (0, 0, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.8, 97./255*0.8, 41./255*0.8);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glRotatef (-80, 0, 1, 0) ;

  glColor3f(170./255, 97./255, 41./255);
  /* right wheel */
  glTranslatef (VEHICLE_WIDTH+0.4, 0, 0) ;
  glRotatef ( 100, 0, 1, 0) ;
  _display_default_cylinder (WHEEl_RAY, WHEEl_RAY, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.95, 97./255*0.95, 41./255*0.95);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glTranslatef (0, 0, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.8, 97./255*0.8, 41./255*0.8);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glRotatef (-100, 0, 1, 0) ;

  glPopMatrix () ;

  glPushMatrix () ;

  glColor3f(170./255, 97./255, 41./255);
  /* left wheel */
  glTranslatef (VEHICLE_POS_X-VEHICLE_THICKNESS-0.2, y-WHEEl_RAY/2+VEHICLE_LENGTH, WHEEl_RAY+context.player.height) ;
  glRotatef ( 80, 0, 1, 0) ;
  _display_default_cylinder (WHEEl_RAY, WHEEl_RAY, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.95, 97./255*0.95, 41./255*0.95);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glTranslatef (0, 0, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.8, 97./255*0.8, 41./255*0.8);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glRotatef (-80, 0, 1, 0) ;

  glColor3f(170./255, 97./255, 41./255);
  /* right wheel */
  glTranslatef (VEHICLE_WIDTH+0.4, 0, 0) ;
  glRotatef ( 100, 0, 1, 0) ;
  _display_default_cylinder (WHEEl_RAY, WHEEl_RAY, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.95, 97./255*0.95, 41./255*0.95);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glTranslatef (0, 0, VEHICLE_THICKNESS) ;
  glColor3f(170./255*0.8, 97./255*0.8, 41./255*0.8);
  gluDisk (context.quadObj, 0, WHEEl_RAY, 16, 16) ;
  glRotatef (-100, 0, 1, 0) ;

  glPopMatrix () ;
}

static void _display_character_into_vehicle () {
  glColor3f (1.0f, 1.0f, 1.0f);
  glPushMatrix () ;

  /* body */
  glTranslatef (VEHICLE_POS_X + VEHICLE_WIDTH / 2,
    context.player.position + VEHICLE_POS_Y + VEHICLE_LENGTH / 2,
    VEHICLE_POS_Z+4 + context.player.height
  );
  _display_default_cylinder (3, 0, 12) ;

  /* left arm */
  glTranslatef (-4, 5, 7);
  glRotatef ( 95, 1, 0, 0) ;
  glRotatef ( 40, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 7) ;
  glRotatef (-40, 0, 1, 0) ;
  glRotatef (-95, 1, 0, 0) ;

  /* right arm */
  glTranslatef (8, 0, 0);
  glRotatef ( 95, 1, 0, 0) ;
  glRotatef (-40, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 7) ;
  glRotatef ( 40, 0, 1, 0) ;
  glRotatef (-95, 1, 0, 0) ;

  /* head */
  glTranslatef (-4, -5, 6);
  _display_default_sphere (2) ;
  glPopMatrix () ;
}

static void _display_character_on_left () {
  glColor3f (1.0f, 1.0f, 1.0f);
  glPushMatrix () ;

  /* body */
  glTranslatef (VEHICLE_POS_X + VEHICLE_WIDTH / 2,
    context.player.position + VEHICLE_POS_Y + VEHICLE_LENGTH / 2,
    VEHICLE_POS_Z+4 + context.player.height
  );
  glRotatef (-30, 0, 1, 0) ;
  _display_default_cylinder (3, 0, 15) ;
  glRotatef ( 20, 0, 1, 0) ;

  /* left arm */
  glTranslatef (-13, 1, 11);
  glRotatef ( 90, 1, 0, 0) ;
  glRotatef ( 90, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef (-90, 0, 1, 0) ;
  glRotatef (-90, 1, 0, 0) ;

  /* right arm */
  glTranslatef (8, 0, 8);
  glRotatef (170, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef (-170, 0, 1, 0) ;

  /* head */
  glTranslatef (-2, 0, -4);
  _display_default_sphere (2) ;
  glPopMatrix () ;
}

static void _display_character_on_right () {
  glColor3f (1.0f, 1.0f, 1.0f);
  glPushMatrix () ;

  /* body */
  glTranslatef (VEHICLE_POS_X + VEHICLE_WIDTH / 2,
    context.player.position + VEHICLE_POS_Y + VEHICLE_LENGTH / 2,
    VEHICLE_POS_Z+4 + context.player.height
  );
  glRotatef ( 30, 0, 1, 0) ;
  _display_default_cylinder (3, 0, 15) ;
  glRotatef (-20, 0, 1, 0) ;

  /* left arm */
  glTranslatef (13, 1, 11);
  glRotatef (-90, 1, 0, 0) ;
  glRotatef (-90, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef ( 90, 0, 1, 0) ;
  glRotatef ( 90, 1, 0, 0) ;

  /* right arm */
  glTranslatef (-8, 0, 8);
  glRotatef (-170, 0, 1, 0) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef ( 170, 0, 1, 0) ;

  /* head */
  glTranslatef (2, 0, -4);
  _display_default_sphere (2) ;
  glPopMatrix () ;
}

static void _display_character_hands_up () {
  glColor3f (1.0f, 1.0f, 1.0f);
  glPushMatrix () ;

  /* body */
  glTranslatef (VEHICLE_POS_X + VEHICLE_WIDTH / 2,
    context.player.position + VEHICLE_POS_Y + VEHICLE_LENGTH / 2,
    VEHICLE_POS_Z+4 + context.player.height
  );
  _display_default_cylinder (3, 0, 15) ;

  /* left arm */
  glTranslatef (-5, 6, 18);
  glRotatef (120, 1, 0, 0) ;
  glRotatef (30, 0, 1, 0) ;
  glRotatef (30, 0, 0, 1) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef (-30, 0, 0, 1) ;
  glRotatef (-30, 0, 1, 0) ;
  glRotatef (-120, 1, 0, 0) ;

  /* right arm */
  glTranslatef (10, 0, 0);
  glRotatef (120, 1, 0, 0) ;
  glRotatef (-30, 0, 1, 0) ;
  glRotatef (30, 0, 0, 1) ;
  _display_default_cylinder (1, 0, 8) ;
  glRotatef (-30, 0, 0, 1) ;
  glRotatef (30, 0, 1, 0) ;
  glRotatef (-120, 1, 0, 0) ;

  /* head */
  glTranslatef (-5, -6, 2);
  _display_default_sphere (2) ;
  glPopMatrix () ;
}

void *display_cylinder (p_object_3D cylinder) {
  glPushMatrix () ;
  if (cylinder->color.r || cylinder->color.g ||cylinder->color.b) {
    glColor3f(cylinder->color.r/255.0, cylinder->color.g/255.0, cylinder->color.b/255.0);
  }
  glTranslatef (cylinder->position.x, cylinder->position.y, cylinder->position.z) ;
  if (cylinder->transform.angle_x)
    glRotatef (cylinder->transform.angle_x, 1, 0, 0) ;
  if (cylinder->transform.angle_y)
    glRotatef (cylinder->transform.angle_y, 0, 1, 0) ;
  if (cylinder->transform.angle_z)
    glRotatef (cylinder->transform.angle_z, 0, 0, 1) ;
  _display_default_cylinder (cylinder->dimensions.radius, cylinder->dimensions.radius,
    cylinder->dimensions.height) ;
  gluDisk (context.quadObj, 0, cylinder->dimensions.radius, 16, 16) ;
  glTranslatef (0, 0, cylinder->dimensions.height);
  gluDisk (context.quadObj, 0, cylinder->dimensions.radius, 16, 16) ;
  glPopMatrix () ;
  return cylinder ;
}

void *display_cone (p_object_3D cone) {
  _display_cylinder (0, 0, 0, 0, 0) ;
  return cone ;
}

void *display_sphere (p_object_3D sphere) {
  _display_default_sphere (0) ;
  return sphere ;
}

void *display_cube (p_object_3D cube) {
  _display_real_cube (cube->position.x, cube->position.y, cube->position.z, cube->dimensions.width) ;
  return cube ;
}

void *display_tile (p_object_3D tile) {
  if (tile->color.r || tile->color.g ||tile->color.b) {
    glColor3f(tile->color.r/255.0, tile->color.g/255.0, tile->color.b/255.0);
  }
  _display_cube (tile->position.x, tile->position.y, tile->position.z,
    tile->dimensions.width, tile->dimensions.depth, tile->dimensions.height) ;
  return tile ;
}

void *display_text (p_object_3D text) {
  if (text->color.r || text->color.g ||text->color.b) {
    glColor3f(text->color.r/255.0, text->color.g/255.0, text->color.b/255.0);
  }
  print (text->position.x, text->position.y, text->position.z, (char*)text->tree) ;
  return text ;
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
  glColor3f(180./255, 90./255, 0.0f);
  if (fabs (building->position.y - context.player.position) > SIGHT)
    return ;
  _display_cube (building->position.x, building->position.y, building->position.z,
    building->dimensions.width, building->dimensions.depth, building->dimensions.height) ;
  for_chained_list_value (building->objects) {
    if (((p_object_3D)value)->display)
      ((p_object_3D)value)->display (value) ;
  }
}

void display_obstacle (p_obstacle_3D obstacle) {
  glColor3f(96./255, 96./255, 96/255.0f);
  if (fabs (obstacle->position.y - context.player.position) > SIGHT)
    return ;
  for_chained_list_value (obstacle->objects) {
    if (((p_object_3D)value)->display) {
      ((p_object_3D)value)->display (value) ;
    }
  }
}

void display_bonus (p_bonus_3D bonus) {
  if (fabs (bonus->position.y - context.player.position) > SIGHT)
    return ;
  for_chained_list_value (bonus->objects) {
    if (((p_object_3D)value)->display) {
      ((p_object_3D)value)->transform.angle_y += context.bonus_rotation ;
      ((p_object_3D)value)->display (value) ;
      ((p_object_3D)value)->transform.angle_y -= context.bonus_rotation ;
    }
  }
}

void display_buildings (void) {
  for_chained_list_value (context.buildings) {
    display_building (value) ;
  }
}

void display_obstacles (void) {
  for_chained_list_value (context.obstacles) {
    display_obstacle (value) ;
  }
}

void display_all_bonus (void) {
  for_chained_list_value (context.bonus) {
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

void print (int x, int y, int z, char *string) {
  size_t length = strlen (string);

  glRasterPos3f (x, context.player.position + y, z);
  for (size_t i = 0; i < length; i++)
    glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24 , string[i]) ;
}

char text_buffer[255] ;
void display_informations () {
  if (context.game_state.vrooming > 1) {
    glColor3f (1.0, 0.0, 0.0);
    context.game_state.vrooming -= 1 ;
    print (-4, 0, 20, "GO !!") ;
  } else if (context.game_state.vrooming == 0) {
    glColor3f (1.0, 0.0, 0.0);
    print (-4, 0, 20, "Ready..?") ;
  }
  glColor3f (1.0, 1.0, 1.0);
  sprintf (text_buffer, "Score: %d    Speed: %.2f    Distance: %.0f/%d",
    context.player.score, context.player.speed, context.player.position, context.parameters.road_length) ;
  print (-15, -50, 3, text_buffer) ;
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
  display_informations () ;
  glutSwapBuffers () ;
}

void animation (void) {
  if (!context.game_state.vrooming) {
    //context.game_state.road_begin_animation_y += context.parameters.road_length / 1500. ;
    //context.game_state.bg_begin_animation_x += context.parameters.road_length / 1500. ;
    //context.game_state.bg_begin_animation_y += context.parameters.road_length / 1500. ;
    //if (context.game_state.bg_begin_animation_x >= context.parameters.road_length)
    context.game_state.road_begin_animation_y = context.parameters.road_length ;
    context.game_state.bg_begin_animation_x = context.parameters.road_length ;
    context.game_state.bg_begin_animation_y = context.parameters.road_length ;
      context.game_state.vrooming = 100 ;
  } else {
    context.player.position += context.player.speed ;
    glTranslatef(0.0f, -context.player.speed , 0.0f);
    if (context.player.speed < MAX_SPEED && (int )context.player.position % 50 == 0)
      context.player.speed += SPEED_INCREASE ;
    if (context.player.position > context.parameters.road_length)
      exit_game () ;
  }
  if (context.player.jumping == JUMP_ASCENTION) {
    context.player.height += JUMP_HEIGHT/(40.0f/context.player.speed);
    if (context.player.height >= JUMP_HEIGHT) {
      context.player.height = JUMP_HEIGHT ;
      context.player.jumping = JUMP_DESCENT ;
      context.player.arms_position = ARMS_INTO_VEHICLE ;
    }
  } else if (context.player.jumping == JUMP_DESCENT) {
    context.player.height -= JUMP_HEIGHT/(40.0f/context.player.speed) ;
    if (context.player.height <= 0) {
      context.player.height = 0 ;
      context.player.jumping = NOT_JUMPING ;
    }
  }
  if ((int)context.player.position < (int)(context.player.position+context.player.speed) &&
      ((int)context.player.position) % 2 == 0) {
    //printf ("verif\n") ;
  }
  context.bonus_rotation += 0.1 * SPEED_MULTIPLIER ;
  glutPostRedisplay () ;
}
