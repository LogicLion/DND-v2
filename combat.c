#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "creature.h"
#include "player.h"

int handle_combat(Player *p, Creature *c){
	int combat_flag = 0;
	do{
		combat_flag = handle_attacking(p, c);
	}while(combat_flag != 1 && combat_flag != 2);
}

int handle_attacking(Player *p, Creature *c){

}}
