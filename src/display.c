

#include "display.h"


static void _display_cylinder () {
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

static void _display_sphere () {
  /*
  GLUquadricObj *quadObj = gluNewQuadric();
  gluCylinder(quadObj, base, top, height, slices, stacks);
  */
}

static void _display_cube () {
  /*
  GLUquadricObj *quadObj = gluNewQuadric();
  gluCylinder(quadObj, base, top, height, slices, stacks);
  */
}

void *display_cylinder (p_object_3D cylinder) {
  _display_cylinder () ;
  return cylinder ;
}

void *display_cone (p_object_3D cone) {
  _display_cylinder () ;
  return cone ;
}

void *display_sphere (p_object_3D sphere) {
  _display_sphere () ;
  return sphere ;
}

void *display_cube (p_object_3D cube) {
  _display_cube () ;
  return cube ;
}

void display_background (void) {
  glColor3f(0.039f, 0.341f, 0.078f);
  glNormal3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);
  glVertex3f(-1500.0f, -8.0f, -1500.0f);
  glVertex3f(-1500.0f, -8.0f,  1500.0f);
  glVertex3f( 1500.0f, -8.0f,  1500.0f);
  glVertex3f( 1500.0f, -8.0f, -1500.0f);
  glEnd();
}

void display_road (void) {
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
}

void display_screen (void) {
  display_background () ;
  display_road () ;
  display_buildings () ;
  display_obstacles () ;
  display_all_bonus () ;
  display_character () ;
}

void animation (void) {
  glutPostRedisplay () ;
}
