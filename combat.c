#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "creature.h"

typedef enum{ATTACK = 1, MAGIC = 2, STATS = 3}Combat_Option;

static int dead_check(Character *p, Creature *c){
	
		if(p->health <= 0) return 1;
		if(c->health <= 0) return 2;
		return 0;
}

static void print_damage(int health, int p_dam, int c_health, int c_dam){
	printf("\nYou've done %d damage, and received %d damage!\n", p_dam, c_dam);
	if(health < 0) health = 0;
	if(c_health < 0) c_health = 0;
	printf("Your health: %d, Enemy's health: %d\n", health, c_health);
}

static int attack(Character *p, Creature *c){
	c->health -= p->attack;
	p->health -= c->attack;
	print_damage(p->health, p->attack, c->health, c->attack);
	return dead_check(p,c);
}


static int magic(Character *p, Creature *c){
	if(p->mana == 0){
		printf("Out of mana!!\n");
	}else{
		int mana_amount = 0;
		do{
			printf("How much mana would you like to use?\n");
			printf("Total mana: %d\n", p->mana);
			printf("input: ");
			scanf("%d", &mana_amount);
			if(p->mana - mana_amount < 0) printf("Not enough mana!\n");
		}while(p->mana - mana_amount < 0);
		
		p->mana -= mana_amount;
		c->health -= mana_amount;
		p->health -= c->attack;
		print_damage(p->health, mana_amount, c->health, c->attack);
		return dead_check(p,c);
	}	
	return 0;
}

static int print_battle_stats(Character *p, Creature *c){
	print_stats(p);
	printf("\n");
	print_creature_stats(c);
	return 0;
}

static int draw_menu(){
	int val = 0;
	printf("-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("Choose your action.\n");
	printf("Attack: 1\n");
	printf("Magic: 2\n");
	printf("Stats: 3\n");
	printf("-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("input: ");
	scanf("%d", &val);
	return val;
}

static int handle_battle(Character *p, Creature *c){
	int player_opt = 0;
	do{
		player_opt = draw_menu();
	}while(player_opt < 1 || player_opt > 3);
	if(player_opt == ATTACK) return attack(p, c);
	if(player_opt == MAGIC) return magic(p,c);
	return print_battle_stats(p,c);
}

int handle_combat(Character *p, Creature *c){
	int combat_flag = 0;
	do{
		combat_flag = handle_battle(p, c);
	}while(combat_flag != 1 && combat_flag != 2);
	if(combat_flag == 2){
		printf("The %s had fallen!\n", c->name);
		printf("You gain %d experience!\n", c->exp_to_give);
		printf("Total exp: %d", p->exp + c->exp_to_give);
		p->exp += c->exp_to_give;
		free(c);
	}else{
		printf("You have fallen!!\n");
	}
	return combat_flag;
}



