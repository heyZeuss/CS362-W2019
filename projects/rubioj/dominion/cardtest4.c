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

#define NUM_SECS 15
void delay(void); // function declaration


int main() 
{
  int i,j;
  int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, curseCount = 0;
  int currentPlayer=1;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  printf("Sea hag causes all other players to discard the top card of their deack and gain a curse.\n");

  for (i = 0; i < G.numPlayers; i++){
	if (i != currentPlayer){
		printf("Player %d discard count: %d\n", i, G.discardCount[i]);
		for(j=0; j<(G.deckCount[i] + G.discardCount[i] + G.handCount[i]); j++){
			if((getCost(G.deck[i][j]) || getCost(G.discard[i][j]) || getCost(G.hand[i][j])) == 0 ){
				curseCount++;
			}
		}
	  printf("Player %d curse count: %d\n\n", i, curseCount);
	  curseCount=0;
	}
}

	printf("Calling Sea Hag and then displaying discard count and curse card count\n\n");

	cardEffect(sea_hag, choice1, choice2, choice3, &G, handPos, &bonus);

 for (i = 0; i < G.numPlayers; i++){
	if (i != currentPlayer){
		printf("Player %d discard count: %d\n", i, G.discardCount[i]);
		for(j=0; j<(G.deckCount[i] + G.discardCount[i] + G.handCount[i]); j++){
			if((getCost(G.deck[i][j]) || getCost(G.discard[i][j]) || getCost(G.hand[i][j])) == 0 ){
				curseCount++;
			}
		}
	  printf("Player %d curse count: %d\n\n", i, curseCount);
	curseCount=0;
	}
}

return 0;
}