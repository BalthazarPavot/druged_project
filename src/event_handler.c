

#include "event_handler.h"


void handle_keyboard (unsigned char key, int x, int y) {
  switch (key) {
    case '8':
      glRotatef(-0.1, 1, 0, 0);
      break ;
    case '2':
      glRotatef(0.1, 1, 0, 0);
      break ;
    case '4':
      glRotatef(-0.1, 0, 1, VEHICLE_POS_Z);
      break ;
    case '6':
      glRotatef(0.1, 0, 1, VEHICLE_POS_Z);
      break ;
    case 'w':
    case 'z':
    case 'h':
      break ;
    case 'q':
    case 'a':
    case 'j':
      break ;
    case 'd':
    case 'k':
      break ;
    case 's':
    case 'l':
      break ;
    case '\x1b': /* escape = '' = '\x1b' */
      exit_game () ;
      exit (0) ;
    default:
      printf ("Unknown key: %c\n", key) ;
      x += y ;  /* not to be bitten for unused variables */
      break ;
  }
}

void handle_special (int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_RIGHT:
      context.player.arms_position = ARMS_ON_RIGHT ;
      break ;
    case GLUT_KEY_LEFT:
      context.player.arms_position = ARMS_ON_LEFT ;
      break ;
    case GLUT_KEY_UP:
      context.player.arms_position = PUT_YOUR_HANDS_UP ;
      break ;
    case GLUT_KEY_DOWN:
      context.player.arms_position = ARMS_INTO_VEHICLE ;
      break ;
    default:
      printf ("Unknown key: %c\n", key) ;
      x += y ;  /* not to be bitten for unused variables */
      break ;
  }
}

void handle_mouse (int button, int state, int x, int y) {
  printf ("Button: %d ; State; %d at : %d %d \n", button, state, x, y) ;
}
