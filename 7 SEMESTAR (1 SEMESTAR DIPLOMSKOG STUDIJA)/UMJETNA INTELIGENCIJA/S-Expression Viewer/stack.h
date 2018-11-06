#ifndef __STACK_H__
#define __STACK_H__

/* define stack structure */
typedef struct t_stack STACK;

struct t_stack {
    void  * data;
    STACK * next;
};

/* stack API */
bool push (STACK * , STACK ** , void * );
bool pop  (STACK * , STACK ** , void * );

#endif