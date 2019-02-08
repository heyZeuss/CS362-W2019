//José-Antonio D. Rubio
//CS 362-400
//unittest4.c

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

  for(i=0; i<G.numPlayers; i++){
    printf("Player %d hand count: %d\n", i, G.handCount[i]);
    printf("Player %d discard count: %d\n", i, G.discardCount[i]);
  }
  printf("testing discardCard\n");

  discardCard(0, 0, &G, 1);

  for(i=0; i<G.numPlayers; i++){
    printf("Player %d hand count after discardCard: %d\n", i, G.handCount[i]);
    printf("Player %d discard count: %d\n", i, G.discardCount[i]);
  }

  return 0;
}
