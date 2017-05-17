

#include "event_handler.h"


void handle_keyboard (unsigned char key, int x, int y) {
  switch (key) {
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

void handle_mouse (int button, int state, int x, int y) {
  printf ("Button: %d ; State; %d at : %d %d \n", button, state, x, y) ;
}