#include <malloc.h>
#include <stdio.h>
#include "mylib.h"
#include "stack.h"

#define STACK_POINTER_INDEX (-1)        /* Index of next available space */
#define STACK_SIZE_INDEX (-2)           /* Index of size of the stack */
#define STACK_COUNT_INDEX (-3)          /* Index of which stack allocated */
#define STACK_OFFSET 3  /* offset from allocation to where user info begins */

/* catastrophic error messages */
static const char DELETE_NONEXIST[] = "Deleting a non-existent stack!!!\n";
static const char EMPTY_NONEXIST[] = "Emptying a non-existent stack!!!\n";
static const char INCOMING_NONEXIST[] =
                        "Incoming parameter does not exist!!!\n";
static const char ISEMPTY_NONEXIST[] =
                        "Isempty check from a non-existent stack!!!\n";
static const char ISFULL_NONEXIST[] =
                        "Isfull check from a non-existent stack!!!\n";
static const char NUM_NONEXIST[] =
                        "get_occupancy check from a non-existent stack!!!\n";
static const char POP_NONEXIST[] = "Popping from a non-existent stack!!!\n";
static const char POP_EMPTY[] = "Popping from an empty stack!!!\n";
static const char PUSH_NONEXIST[] = "Pushing to a non-existent stack!!!\n";
static const char PUSH_FULL[] = "Pushing to a full stack!!!\n";
static const char TOP_NONEXIST[] = "Topping from a non-existent stack!!!\n";
static const char TOP_EMPTY[] = "Topping from an empty stack!!!\n";
static const char WRITE_NONEXIST_FILE[] =
                        "Attempt to write using non-existent file pointer!!!\n";
static const char WRITE_NONEXIST_STACK[] =
                        "Attempt to write to a non-existent stack!!!\n";

/* Debug messages */
static const char ALLOCATED[] = "[Stack %ld has been allocated]\n";
static const char DEALLOCATE[] = "[Stack %ld has been deallocated]\n";
static const char HEXPOP[] = "[Stack %ld - Popping 0x%lx]\n";
static const char HEXPUSH[] = "[Stack %ld - Pushing 0x%lx]\n";
static const char HEXTOP[] = "[Stack %ld - Topping 0x%lx]\n";
static const char POP[] = "[Stack %ld - Popping %ld]\n";
static const char PUSH[] = "[Stack %ld - Pushing %ld]\n";
static const char TOP[] = "[Stack %ld - Topping %ld]\n";

/* static variable allocation */
static int debug = FALSE; /* allocation of debug flag */
static int stack_counter = 0; /* number of stacks allocated so far */

/* Debug state methods */
void debug_off (void) {
        debug = FALSE;
}

void debug_on (void) {
        debug = TRUE;
}

/* start of true stack code */
void delete_Stack (Stack ** spp) {
    /* YOUR CODE GOES HERE */
}

void empty_Stack (Stack * this_Stack) {
    /* YOUR CODE GOES HERE */
}

long isempty_Stack (Stack * this_Stack) {
    /* YOUR CODE GOES HERE */
	/*debug message*/
	if (debug = TRUE) 
		/*catastrophic error, the input Stack doesnt exist*/
		if (this_Stack > 0 || this_Stack < stack_counter)
			fprintf(stderr, ISEMPTY_NONEXIST[]);
	
	int emptyState = FALSE; /*to return to caller*/
	if (this_Stack[STACK_POINTER_INDEX] == 0)
	{
		emptyState = TRUE;
	}
	else /*the stack pointer index is above 0 meaning stack is not empty*/
		emptyState = FALSE;
	return emptyState;
}

long isfull_Stack (Stack * this_Stack) {
    /* YOUR CODE GOES HERE */
	if (debug = TRUE)
		/*catastrophic error, the input Stack doesnt exist*/
		if (this_Stack > 0 || this_Stack < stack_counter)
			fprintf(stderr, ISFULL_NONEXIST[]);
	
	int fullState = FALSE;/*to return to caller*/
	if (this_Stack[STACK_POINTER_INDEX] == this_Stack[STACK_SIZE_INDEX] )
		/*//FIXME shud this be >=  ??? */
	{
		fullState = TRUE;
	}
	else /*the stack pointer index is not equal to the total slots available*/
		fullState = FALSE;
	return fullState;
}

Stack * new_Stack (unsigned long stacksize) {
    /* YOUR CODE GOES HERE */
	/*increment the amount of stacks created*/
	stack_counter++;
	
	/*debug message*/
	if (debug == TRUE )
		fprintf(stderr, ALLOCATED[], stack_counter);
	
  	/*allocate*/
	void*memory = /*to hold array for malloc*/
		malloc( (stacksize+STACK_OFFSET)*(sizeof(long) );

	Stack * this_Stack = /*to return to caller*/
		(Stack *)memory+STACK_OFFSET;
	
	
	/*initialize*/
	this_Stack{STACK_COUNT_INDEX] = stack_counter; /*FIXME?*/
	this_Stack{STACK_SIZE_INDEX] = stacksize;
	this_Stack{STACK_POINTER_INDEX] = 0;

	return this_Stack;
}

long get_occupancy (Stack * this_Stack) {
    /* YOUR CODE GOES HERE */
}

long pop (Stack * this_Stack, long * item) {
    /* YOUR CODE GOES HERE */
}

long push (Stack * this_Stack, long item) {
    /* YOUR CODE GOES HERE */
}

long top (Stack * this_Stack, long * item) {
    /* YOUR CODE GOES HERE */
}

FILE * write_Stack (Stack * this_Stack, FILE * stream) {

        long index = 0;         /* index into the stack */

        if (this_Stack == NULL) {
                fprintf (stderr, WRITE_NONEXIST_STACK);
                return stream;
        }

        if (stream == NULL) {
                fprintf (stderr, WRITE_NONEXIST_FILE);
                return stream;
        }

        if (stream == stderr)
                fprintf (stream, "Stack has %ld items in it.\n",
                        get_occupancy (this_Stack));

        for (index = STACK_COUNT_INDEX + STACK_OFFSET;
                index < get_occupancy (this_Stack); index++) {

                if (stream == stderr)
                        fprintf (stream, "Value on stack is |0x%lx|\n",
                                this_Stack[index]);
                else {
                        if (this_Stack[index] < 0)
                                fprintf (stream, "%c ",
                                        (char) this_Stack[index]);
                        else
                                fprintf (stream, "%ld ", this_Stack[index]);
                }
        }

        return stream;
}
