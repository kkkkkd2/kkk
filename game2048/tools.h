#ifndef TOOLS_H
#define TOOLS_H
#include <stdbool.h>
#include <stdio.h>


#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...)
#endif

bool is_die(void);
void show_view(void);
void rand_two(void);
#endif//TOOLS_H
