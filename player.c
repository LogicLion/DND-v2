#include <stdlib.h>
#include "player.h"
#include <time.h>
#include <stdio.h>
#include "game_util.h"

/*
 This is the code that represents the main character of the game.
 Author: Thomas Hocking.
*/


//returns a semi random number with given range. 1 for inclusive, 0 for exclusive.

Character *create_character(char *name){

	srand(time(NULL));
	Character *c = malloc(sizeof(Character));
	c->name = name;
	c->health = generate_random_num(5, 20, 1);
	c->mana = generate_random_num(2, 10, 1);
	c->attack = generate_random_num(1, 10,1);
	c->exp = 0;
	c->exp_cap = 100;
	return c;
}

int did_level(Character *c){
	return c->exp >= c->exp_cap ? 0:-1;
}

void level_up(Character *c){
	
	c->health++;
	c->mana++;
	c->attack++;
	c->exp = 0;
	c->exp_cap += 25;
}

void print_stats(Character *c){
	printf("|-----------------------------|\n");
	printf("    ****  %s **** \n", c->name);
	printf(" Health: %d\n", c->health);
	printf(" Mana: %d\n", c->mana);
	printf(" Attack: %d\n", c->attack);
	printf(" EXP: %d\n", c->exp);
	printf(" EXP until next level: %d\n", c->exp_cap - c->exp);
	printf("|-----------------------------|\n");
}
