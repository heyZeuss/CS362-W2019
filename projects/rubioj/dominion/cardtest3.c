//José-Antonio D. Rubio
//CS 362-400
//cardtest3.c

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
  int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, playerHandCount = 0, playerDeckCount = 0;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  printf("adventurer, in a nutshell, allows player to draw cards from their deck until they have drawn two treasure cards.\n");

  for(i=0; i< numHandCards(&G); i++){
  	playerHandCount++;
  }

  printf("Current number of cards in Player 1's hand: %d\n", playerHandCount);

  for(i=0; i< G.deckCount[1]; i++){
    playerDeckCount++;
  }

  printf("Current number of cards in Player 1's deck: %d\n", playerDeckCount);


  printf("\nTESTING ADVENTURER\n\n");

  cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);

  for(i=0; i< numHandCards(&G); i++){
    playerHandCount++;
  }

  printf("Current number of cards in Player 1's hand: %d\n", playerHandCount);

  for(i=0; i< G.deckCount[1]; i++){
    playerDeckCount++;
  }

  printf("Current number of cards in Player 1's deck: %d\n", playerDeckCount);

  return 0;
}
