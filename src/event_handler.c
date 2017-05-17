

#include "event_handler.h"


void handle_keyboard (unsigned char key, int x, int y) {
  switch (key) {
    case '8':
      context.key_down.rotate_down = 0 ;
      context.key_down.rotate_up = 1 ;
      break ;
    case '5':
      context.key_down.rotate_down = 0 ;
      context.key_down.rotate_up = 0 ;
      context.key_down.rotate_right = 0 ;
      context.key_down.rotate_left = 0 ;
      break ;
    case '2':
      context.key_down.rotate_down = 1 ;
      context.key_down.rotate_up = 0 ;
      break ;
    case '4':
      context.key_down.rotate_right = 0 ;
      context.key_down.rotate_left = 1 ;
      break ;
    case '6':
      context.key_down.rotate_right = 1 ;
      context.key_down.rotate_left = 0 ;
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
      break ;
    case GLUT_KEY_LEFT:
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
