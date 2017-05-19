

#include "event_handler.h"


void handle_keyboard (unsigned char key, int x, int y) {
  switch (key) {
    case '8':
      if (context.game_state.vrooming == 1)
        glRotatef(-0.1, 1, 0, 0);
      break ;
    case '2':
      if (context.game_state.vrooming == 1)
        glRotatef(0.1, 1, 0, 0);
      break ;
    case '4':
      if (context.game_state.vrooming == 1)
        glRotatef(-0.1, 0, 1, VEHICLE_POS_Z);
      break ;
    case '6':
      if (context.game_state.vrooming == 1)
        glRotatef(0.1, 0, 1, VEHICLE_POS_Z);
      break ;
    case '\x1b': /* escape = '' = '\x1b' */
      exit_game () ;
      exit (0) ;
    default:
      x += y ; // not to be bitten by gcc
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
      if (context.player.jumping != NOT_JUMPING)
        break;
      context.player.arms_position = PUT_YOUR_HANDS_UP ;
      context.player.jumping = JUMP_ASCENTION ;
      context.player.height = 0 ;
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
