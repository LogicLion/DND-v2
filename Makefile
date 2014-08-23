game: player.o testplayer.o game_util.o creature.o combat.o
	gcc -Wall -g -o game player.c testplayer.c game_util.c creature.c combat.c -I .
