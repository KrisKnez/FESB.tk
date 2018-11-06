#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "stack.h"
#include "cons.h"


typedef unsigned int UINT;

/* define S-expression characters */
#define  LEFT_BRACKET  '('
#define RIGHT_BRACKET  ')'
#define  DOUBLE_QUOTE  '\"'
#define  SINGLE_QUOTE  '\''
#define         SPACE  ' '

/* S-expression manipulation API */
bool   is_delimiter    (char);
char * get_next_atom   (UINT * , char [], bool);
void   print_cons_tree (CONS * tree_node);


int main() {
	/* levels stack */
	STACK levels;
	levels.data = NULL;
	levels.next = NULL;
	STACK * levels_top = &levels;

	/* cons tree */
	CONS cons_tree;
	cons_tree.type = CONS_TYPES::ROOT;
	cons_tree.car  = NIL;
	cons_tree.cdr  = NIL;
	CONS * last_node = &cons_tree;

	/* TODO: add dynamic input */
	char s_expr[] = "(after (\"looking at the\" (lizard man) (((jim)) \'\"asked for\" warp 9)))";

	char *       atom = NIL;
	bool   add_bellow = false;  /* add new CONS node bellow current?   */
	
	/* read char by char */
	UINT i = 0;
	while (i < strlen(s_expr))
	{
		/* switch current char */
		char c = s_expr[i];  
		switch (c) {
			case LEFT_BRACKET:
				add_node(&last_node, NIL, CONS_TYPES::LIST, add_bellow);
				push(&levels, &levels_top, last_node);
				add_bellow = true;
				break;

			case RIGHT_BRACKET:
				pop(&levels, &levels_top, last_node);
				break;

			case SPACE:
			case SINGLE_QUOTE:
				break;

			case DOUBLE_QUOTE:
				atom = get_next_atom(&(++i), s_expr, true);
				if (atom != NIL) {
					add_node(&last_node, atom, CONS_TYPES::ATOM, add_bellow);
					add_bellow = false;
				}
				break;

			default:
				atom = get_next_atom(&i, s_expr, false);
				if (atom != NIL) {
					add_node(&last_node, atom, CONS_TYPES::ATOM, add_bellow);
					add_bellow = false;
				}
		}
		
		i++;
	}

	/* print CONS tree */
	printf("\n :: CONS tree :: ");
	print_cons_tree(&cons_tree);
	printf("\n\n ");

	return EXIT_SUCCESS;
}

/* check if given char is S-expression delimiter */
bool is_delimiter(char c) {
	if (    c != LEFT_BRACKET 
		 && c != RIGHT_BRACKET
		 && c != DOUBLE_QUOTE
		 && c != SINGLE_QUOTE
		 && c != SPACE)
	{ return false; }

	/* else */ return true;
}

/* get next atom from S-expression */
char * get_next_atom(UINT * i, char s_expr[], bool string) {
	/* substring indices */
	UINT start = (*i)--;
	UINT end   = start;

	/* loop continuation flag */
	bool continue_loop = true;

	/* get substring */
	char c = 0;
	do {
		c = s_expr[++(*i)];
		continue_loop = string ? (c != DOUBLE_QUOTE) : !is_delimiter(c);
	} while (continue_loop);

	end = (*i);

	/* one step back for non-quoted atoms */
	if (!string) (*i)--;

	/* eliminate empty strings */
	if (end == start) return NULL;

	/* create atom */
	char * atom = (char *) malloc(end - start);

	if (atom == NULL) {
		/* TODO: set error flag */
		return NULL;
	}

	strncpy(atom, s_expr + start, end - start);
	atom[end - start] = '\0';

	return atom;
}

void print_cons_tree(CONS * tree_node) {

	/* ROOT and ATOM nodes */
	if (    tree_node->type == CONS_TYPES::ROOT && tree_node->cdr != NIL
		 || tree_node->type == CONS_TYPES::ATOM && tree_node->cdr != NIL)
	{
		print_cons_tree((CONS *) tree_node->cdr);
	}

	/* LIST nodes */
	if (tree_node->type == CONS_TYPES::LIST) {
		if (tree_node->car != NIL) print_cons_tree((CONS *) tree_node->car);
		if (tree_node->cdr != NIL) print_cons_tree((CONS *) tree_node->cdr);
	}

	/* print CONS address */ 
	printf("\n\n CONS address: @[0x%X]", tree_node);

	/* print CONS type */
	char * type;
	switch (tree_node->type) {
		case CONS_TYPES::ROOT   : type = "root";   break;
		case CONS_TYPES::ATOM   : type = "atom";   break;
		case CONS_TYPES::LIST   : type = "list";   break;

		default: type = "<unknown>";
	}
	printf("\n CONS    type: %s", type);

	/* print CAR and CDR fields */
	bool print_car = true;
	bool print_cdr = true;

	if(tree_node->car == 0) { printf("\n CAR    value: %s", "NIL"); print_car = false; }
	if(tree_node->cdr == 0) { printf("\n CDR    value: %s", "NIL"); print_cdr = false; }

	if (tree_node->type == CONS_TYPES::ATOM) {
		if (print_car) { printf("\n CAR    value: \"%s\"", (char *) tree_node->car); print_car = false; }
	}

	if (print_car) printf("\n CAR    value: points to --> @[0x%X]", tree_node->car);
	if (print_cdr) printf("\n CDR    value: points to --> @[0x%X]", tree_node->cdr);

	return;
}