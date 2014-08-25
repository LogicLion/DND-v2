#include <stdlib.h>
#include "creature.h"
#include <time.h>
#include <stdio.h>
#include "game_util.h"
#include <string.h>

/*
 This is the code that represents a 'creature' inside of the game.
 Author: Thomas Hocking
*/

Creature *create_creature(int creature_type){
	Creature *c = malloc(sizeof(Creature));
	if(creature_type == ZOMBIE){
		c->name = "Zombie";
		c->attack = generate_random_num(1, 6, 1);
		c->health = generate_random_num(2, 12, 1);
		c->exp_to_give = generate_random_num(20, 40, 1);
	}else if(creature_type == ZOMBIE_SPIDER){
		c->name = "Zombie Spider";
		c->attack = generate_random_num(3, 8, 1);
		c->health = generate_random_num(1, 5, 1);
		c->exp_to_give = generate_random_num(30, 50, 1);
	}else if(creature_type == RAVAGE_DOG){
		c->name = "Ravage Dog";
		c->attack = generate_random_num(3, 5, 1);
		c->health = generate_random_num(4 ,8, 1);
		c->exp_to_give = generate_random_num(20, 40, 1);
	}
	else{
		c->name = "Horde of Rats";
		c->attack = generate_random_num(1, 2, 1);
		c->health = generate_random_num(6, 17, 1);
		c->exp_to_give = generate_random_num(25, 45, 1);
	}
	return c;	
}

Creature_Queue *create_creature_queue(){
	Creature_Queue *q = malloc(sizeof(Creature_Queue));
	q->num_creatures = 0;
	q->creaturesz = sizeof(Creature);
	q->front = NULL;
	q->back = NULL;
	return q;
}

void enque(Creature_Queue *q, Creature *add){
	Node *node = malloc(sizeof(Node));
	Creature *t = malloc(sizeof(Creature));
	memcpy(t, add, q->creaturesz);
	node->creature = t;
	
	//check if first one otherwise attach to back.
	if(q->front == NULL && q->back == NULL){
		q->front = node;
		q->back = node;
		q->back->next = NULL;
	}else{
		q->back = node;
		Node *cur = q->front;
		Node *prev = NULL;
		while(cur != NULL){
			prev = cur;
			cur = (Node *)cur->next;;
		}	
		prev->next = node;
	}
	q->num_creatures++;
}

Creature *deque(Creature_Queue *q){
	if(q->front == q->back) q->back = NULL;
	if(q->front != NULL){
		Creature *t = q->front->creature;
		q->front = q->front->next;
		q->num_creatures--;
		return t;
	}
	return NULL;
}

void print_queue(Creature_Queue *q){
	Node *cur = q->front;
	int i;
	for(i = 0; i < q->num_creatures; i++){
		print_creature_stats(cur->creature);
		cur = (Node *)cur->next;
	}
}


void print_creature_stats(Creature *c){
	printf("A %s appears!\n", c->name);
	printf("Attack: %d\n", c->attack);
	printf("Health: %d\n", c->health);
}
