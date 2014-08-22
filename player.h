#include <stdlib.h>
#include <string.h>

typedef struct{
	char *name;
	int health;
	int mana;
	int attack;
	int exp;
	int exp_cap;
} Character;


Character *create_character(char *nameseise);
int did_level(Character *character);
void level_up(Character *character);
void print_stats(Character *character);


