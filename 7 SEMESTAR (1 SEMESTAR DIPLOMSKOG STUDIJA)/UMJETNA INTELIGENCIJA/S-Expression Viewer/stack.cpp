#include <cstdlib>
#include "stack.h"

/* create new record on stack */
bool push(STACK * base, STACK ** top, void * in_value) {
	/* allocate new record */
    STACK * slot = (STACK *) malloc(sizeof(STACK));
 
	/* handle allocation error */
    if (slot == NULL){
		perror("Error creating STACK slot");
        return false;
    } 

	slot->data = in_value;
    slot->next = NULL;

	/* empty stack*/
	if (base->next == NULL) {
		base->next = slot;
		*top       = slot;
	}
	/* non-empty stack */
	else {
		(*top)->next = slot;
		*top         = slot;
	}
}

/* get top most record */
bool pop(STACK * base, STACK ** top, void * out_value)
{
	/* empty stack */
    if (base == *top) {
		perror("Error accessing empty stack");
        return false;
	}
	
	/* find previous element */
	STACK * prev = base;
	while (prev->next != *top) {
		prev = prev->next;
	}

	/* preserve requested data */
	out_value = (*top)->data;

	/* degrade top pointer */
	prev->next = NULL;
	free(*top);
	*top = prev;
}