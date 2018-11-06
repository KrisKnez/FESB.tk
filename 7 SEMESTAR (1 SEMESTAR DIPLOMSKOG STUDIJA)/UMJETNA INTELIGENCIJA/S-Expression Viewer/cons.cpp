#include <cstdlib>
#include "cons.h"

bool add_node (CONS ** last_node, char * atom, UINT node_type, bool add_bellow) {
	/* allocate new CONS slot */
    CONS * cell = (CONS *) malloc(sizeof(CONS));

	/* handle allocation errors */
    if (cell == NULL){
		perror("Error creating CONS node");
        return false;
    } 
	
	cell->type   = node_type;
	cell->car    = (void *) atom;
	cell->cdr    = NIL;

	if (add_bellow) (*last_node)->car = cell;
	else            (*last_node)->cdr = cell;
		
	*last_node = cell;

	return true;
}