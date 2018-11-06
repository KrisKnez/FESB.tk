#ifndef __CONS_H__
#define __CONS_H__

typedef unsigned int UINT;

/* define NIL */
#define NIL  NULL

/* define CONS types */
enum t_cons_types {
	ROOT = 0,
	ATOM,
	LIST
};
typedef enum t_cons_types CONS_TYPES;

/* define CONS cell */
struct t_cons_cell {
	UINT   type; 
	void * car;
	void * cdr;
};
typedef struct t_cons_cell CONS;

/* cons tree API */
bool add_node (CONS ** , char * , UINT, bool);

#endif