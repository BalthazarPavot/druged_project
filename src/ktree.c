#include "ktree.h"

p_tree new_tree () {
	p_tree tree ;
	
	if ((tree = malloc (sizeof(p_tree))) == NULL) {
		fprintf (stderr, "Not enough memory to create a tree (file:ktree.c)\n") ;
		exit(0) ;
	}
		
	return tree ;
}
/*
p_tree init_tree () {


}*/

void free_tree (p_tree tree) {

	if (tree != NULL)
		free_tree (*tree->sub_tree) ;
	free (tree) ;
}

