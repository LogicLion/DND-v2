#include <stdlib.h>
#include <stdio.h>
#include "game_util.h"

typedef enum{ZOMBIE, ZOMBIE_SPIDER, RAVAGE_DOG, HORDE_OF_RATS} creature_type;

typedef struct{
	char *name;
	int attack;
	int health;
	int exp_to_give;
	creature_type c;
}Creature;

typedef struct{
	Creature *creature;
	void *next;
}Node;

typedef struct{
	int num_creatures;
	int creaturesz;
	Node *front;
	Node *back;
}Creature_Queue;

Creature *create_creature(int creature_type);
Creature_Queue *create_creature_queue();
Creature *deque(Creature_Queue *q);
void enque(Creature_Queue *q, Creature *add);
void print_queue(Creature_Queue *q);
void print_creature_stats(Creature *c);

