//José-Antonio D. Rubio
//CS 362-400
//unittest3.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> 



int main() 
{
 
  int i;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(4, k, 30, &G);

  printf("testing endTurn\n");


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count: %d\n", i, G.handCount[i]);
	}
	
		printf("-----------------\n");
		endTurn(&G);


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count after endTurn call: %d\n", i, G.handCount[i]);
	}
	
		printf("-----------------\n");
		endTurn(&G);


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count after endTurn call: %d\n", i, G.handCount[i]);
	}
	
		printf("-----------------\n");
		endTurn(&G);


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count after endTurn call: %d\n", i, G.handCount[i]);
	}
	
		printf("-----------------\n");
		endTurn(&G);


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count after endTurn call: %d\n", i, G.handCount[i]);
	}
		
return 0;
}
