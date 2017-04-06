/*
 * main.c
 * 
 * Copyright 2017 balto <balto@lain>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */
 
/**
 * 
 * 
 * 
 * TLDR ;
 * Utiliser implémenter quand on parle de coder un algo/programme,
 *  et non implanter.
 * On implante un logiciel dans un ordinateur = installation + configuration.
 * On implémente un logiciel/algo/programme = réalisation des spec. produisant
 *  ledit logiciel/algo/programme.
 * 
 * 
 * 
 * CF: www.larousse.fr, www.academie-francaise.fr
 * 
 * 
 * Il signifie, en parlant d’un logiciel, l’« installer en réalisant les
 *  adaptations nécessaires à son fonctionnement ». On le traduit dans ce cas
 *  par implanter (implanter un logiciel).
 * Il signifie d’autre part « effectuer l’ensemble des opérations qui permettent
 *  de définir un projet et de le réaliser ». On le traduit alors par
 *  implémenter (implémenter un système d’exploitation).
 * 
 * 
 * implanter
 *  verbe transitif 
 *   Planter, fixer, insérer quelque chose dans autre chose :
 *      Le lierre implante ses crampons dans l'écorce des arbres.
 *   Mettre en place quelque chose, une entreprise, les installer à demeure
 *    quelque part :
 *      Implanter une centrale nucléaire dans une région.
 *   Établir solidement un groupe, un produit, etc. :
 *      Implanter un nouveau produit sur le marché.
 *   Introduire une idée, un usage, etc., quelque part et l'établir durablement
 *    dans l'esprit des gens, dans un milieu :
 *      Implanter une mode.
 *   Matérialiser le tracé d'un bâtiment à construire, sur un sol aplani, à
 *    l'aide de cordeaux tendus entre des piquets.
 *   Pratiquer une implantation chirurgicale.
 * 
 * implémenter
 *  verbe transitif
 *   Conjugaison
 *   Réaliser l'implémentation.
 * 
 * implémentation:
 *  nom féminin
 *   Mise en place sur un ordinateur d'un système d'exploitation ou d'un
 *    logiciel adapté aux besoins et à la configuration informatique de
 *    l'utilisateur.
 *  
 */


#include "main.h"


int main (int argc, char *argv[]) {
  int window_id ;

  glutInit (&argc, argv) ;
  glutInitWindowSize (800, 600) ;
  glutInitWindowPosition (50, 50) ;
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH) ;
  window_id = glutCreateWindow ("Drug! Drug! Drug! Drug!") ;
  glEnable(GL_DEPTH_TEST) ;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glutSetWindow (window_id) ;

  

  glutMouseFunc (handle_mouse) ;
  glutKeyboardFunc (handle_keyboard);

  glutMainLoop ();


  return 0 ;
}