//José-Antonio D. Rubio
//CS 362-400
//cardtest4.c

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


  initializeGame(2, k, 30, &G);

  printf("testing endTurn\n");


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count: %d\n", i, G.handCount[i]);
		printf("Player %d actions count: %d\n", i, G.numActions);
		printf("Player %d coin count: %d\n", i, G.coins);
		printf("Player %d buy count: %d\n", i, G.numBuys);

	}
	endTurn(&G);


	for(i=0; i<G.numPlayers; i++){
		printf("Player %d hand count after endTurn call: %d\n", i, G.handCount[i]);
		printf("Player %d actions count: %d\n", i, G.numActions);
		printf("Player %d coin count: %d\n", i, G.coins);
		printf("Player %d buy count: %d\n", i, G.numBuys);
	}
		
return 0;
}
