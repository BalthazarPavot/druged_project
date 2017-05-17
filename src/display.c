

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
  /*
  _display_cylinder ()...
  */
  return NULL ;
}

void *display_cone (p_object_3D cone) {
  /*
  _display_cylinder ()...
  */
  return NULL ;
}

void *display_sphere (p_object_3D sphere) {
  /*
  _display_sphere ()...
  */
  return NULL ;
}

void *display_cube (p_object_3D cube) {
  /*
  _display_cube ()...
  */
  return NULL ;
}

void display_background (void) {
}

void display_road (void) {
}

void display_buildings (void) {
}

void display_obstacle (void) {
}

void display_bonus (void) {
}

void display_character (void) {
}

void display_screen (void) {
  display_background () ;
  display_road () ;
  display_buildings () ;
  display_obstacle () ;
  display_bonus () ;
  display_character () ;
}

void animation (void) {
  glutPostRedisplay () ;
}