
#include <stdlib.h>
#include <stdio.h>
#include "player.h"
#include "creature.h"

int main(){
	Character *c = create_character("Thomas");
	print_stats(c);	

	Creature_Queue *q = create_creature_queue();
	printf("num: %d\n", q->num_creatures);
	
	int i;
	for( i = 0; i < 4; i++){
		Creature *cr = create_creature(i);
		enque(q, cr);
	}
	print_queue(q);
	printf("\n Now printing queue\n");
	for(i = 0; i < 4; i++){
		printf("%d\n", q->num_creatures);
		print_creature_stats(deque(q));
	}
	
	return 0;
}
