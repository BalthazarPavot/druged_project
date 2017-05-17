

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
float y = 10.0f ;
void display_background (void) {
  glColor3f(91./255, 40./255, 0.0f);
  glBegin(GL_QUADS);
  glVertex3f(-50.0f, 1500.0f,  -1.1f);
  glVertex3f(50.0f, 1500.0f,  -1.1f);
  glVertex3f(50.0f, -10.0f, -1.1f);
  glVertex3f(-50.0f, -10.0f, -1.1f);
  glEnd();
}

void display_road (void) {
  glColor3f(145./255, 63./255, 0.0f);
  glBegin(GL_QUADS);
  glVertex3f(-20.0f, y,  0.0f);
  glVertex3f(20.0f, y,  0.0f);
  glVertex3f(20.0f, -10.0f, 0.0f);
  glVertex3f(-20.0f, -10.0f, 0.0f);
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
}


void display_axes () {

  glBegin(GL_LINES);

  glColor3f (0.9, 0, 0) ;
  glVertex3f(0.0, 0.0, 1.0);
  glVertex3f(500, 0, 1);

  glColor3f (0, 0.9, 0) ;
  glVertex3f(0.0, 0.0, 1.0);
  glVertex3f(0, 500, 1);

  //glColor3f (0, 0, 0.9) ;
  //glVertex3f(0.0, 0.0, 0.0);
  //glVertex3f(0, 0, 50);

  glEnd();

}

void display_screen (void) {

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
  glMatrixMode (GL_PROJECTION) ;

  display_background () ;
  display_road () ;
  display_buildings () ;
  display_obstacles () ;
  display_all_bonus () ;
  display_character () ;

  glBegin (GL_QUADS) ;

/*
  // top face
  glColor3f(0.9, 0.9, 0.9) ;
  glVertex3f(0, 0, 2) ;
  glVertex3f(2, 0, 2) ;
  glVertex3f(2, 0, 0) ;
  glVertex3f(0, 0, 0) ;

  // front right face
  glColor3f(0.8, 0.8, 0.8) ;
  glVertex3f(0, 0, 2) ;
  glVertex3f(2, 0, 2) ;
  glVertex3f(2, 2, 2) ;
  glVertex3f(0, 2, 2) ;

  // front left face
  glColor3f(0.4, 0.4, 0.4) ;
  glVertex3f(0, 0, 0) ;
  glVertex3f(0, 0, 2) ; // ok
  glVertex3f(0, 2, 2) ; // ok
  glVertex3f(0, 2, 0) ; // ok

  // botton face
  glColor3f(0.5, 0.5, 0.5) ;
  glVertex3f(-2000, -2000, 0) ;
  glVertex3f(2000, -20000, 0) ;
  glVertex3f(2000, 2000, 0) ;
  glVertex3f(-2000, 2000, 0) ;
  * */

  glEnd () ;

  display_axes() ;

  glutSwapBuffers () ;
}

void animation (void) {
  sleep (0.5) ;
  glutPostRedisplay () ;
  y+=0.1 ;
}
