//José-Antonio D. Rubio
//CS 362-400
//cardtest.2c

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
  int i;
  int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, playerDeckCount = 0;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  printf("village will allow a player to draw 1 card and give them 2 extra actions.\n");

  for(i=0; i< G.deckCount[1]; i++){
  	playerDeckCount++;
  }

  printf("Current number of cards in Player 1's deck: %d\n", playerDeckCount);
  printf("Number of actions for player 1: %d\n", G.numActions);


  printf("\nTESTING VILLAGE\n\n");

  cardEffect(village, choice1, choice2, choice3, &G, handPos, &bonus);

  for(i=0; i< G.deckCount[1]; i++){
  	playerDeckCount++;
  }

  printf("Current number of cards in Player 1's deck: %d\n", playerDeckCount);
  printf("Number of actions for player 1: %d\n", G.numActions);


  return 0;
}
