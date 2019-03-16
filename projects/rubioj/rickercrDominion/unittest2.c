//José-Antonio D. Rubio
//CS 362-400
//unittest2.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void testGameOver(struct gameState G){
	int result;

	printf("Testing to see if game is over\n");

	result = isGameOver(&G);

	if(result){
		printf("\nGame is over.\n-------------\n");
	}
	else {
		printf("\nGame is not over.\n------------------\n");
	}
}

int main() {
  int i;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  testGameOver(G);
  
  printf("Changing supply count of province to 0.\n");
  G.supplyCount[province] = 0;

  testGameOver(G);

 printf("Setting supply count of province to be more than 0.\n");
  G.supplyCount[province] = 10;

  testGameOver(G);

 printf("changing the supply count of 2 supply piles to 0");

  for (i = 0; i < 2; i++)
    {
     G.supplyCount[i] = 0;
	}

 testGameOver(G);

 printf("changing the supply count of 3 supply piles to 0");

  for (i = 0; i < 3; i++)
    {
     G.supplyCount[i] = 0;
	}

 testGameOver(G);

 return 0;
}