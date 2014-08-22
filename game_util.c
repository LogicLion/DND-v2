#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Provides game utilites such as generating random numbers for a given range...

int generate_random_num(int start, int end, int inclusive){
	int weight = 0;
	if(start == 0 && inclusive == 1) weight = 1;
	if(end > start){
		if(inclusive == 0 || inclusive == 1) return (rand() % end) + start + weight;
	}
	return -1;
}
