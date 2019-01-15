/*
Sophia Fondell
9/27/18
CS 410: Assignment 0 -Task C - copysection.c
*/

#include "objcopy.h"

int main(int argc, char *argv[]) {
	// Filename cmd line arg
	char *filename = argv[1];
	// Call library function, which is void and does all of the work itself
	copysec(filename);
	// So we're done !
	return 0;
}