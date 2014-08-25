
#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "creature.h"
#include "combat.h"
#include "game_util.h"

int main(){
	Character *c = create_character("Thomas");
	print_stats(c);	
	printf("\n");

	Creature_Queue *q = create_creature_queue();
//	printf("num: %d\n", q->num_creatures);
	
	int i;
	for( i = 0; i < 4; i++){
		Creature *cr = create_creature(i);
		enque(q, cr);
		printf("\nBATTLE! %d\n", handle_combat(c, deque(q))); 
	}
	print_queue(q);
	printf("\n");

		

	//free(cr);
	free(c);
	free(q->front);		
	free(q->back);
	free(q);
	
	//properly frees when monster is killed. leaks when character dies.


	return 0;
}
