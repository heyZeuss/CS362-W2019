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

// int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
// {
	
//   //if card is not trashed, added to Played pile 
//   if (trashFlag < 1)
//     {
//       //add card to played pile
//       state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
//       state->playedCardCount++;
//     }
	
//   //set played card to -1
//   state->hand[currentPlayer][handPos] = -1;
	
//   //remove card from player's hand
//   if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
//     {
//       //reduce number of cards in hand
//       state->handCount[currentPlayer]--;
//     }
//   else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
//     {
//       //reduce number of cards in hand
//       state->handCount[currentPlayer]--;
//     }
//   else 	
//     {
//       //replace discarded card with last card in hand
//       state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
//       //set last card to -1
//       state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
//       //reduce number of cards in hand
//       state->handCount[currentPlayer]--;
//     }
	
//   return 0;
// }