//José-Antonio D. Rubio
//CS 362-400
//randomtestadventure.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h> 
#include <math.h>

#define NUM_SECS 15
// #define MAX_ITERATIONS 10
// void delay(void); // function declaration

int checkAdventurer(int p, struct gameState *post) {
  int r, i, cardDrawn;
  int bonus = 0, drawntreasure=0;
  int temphand[500];
  int z = 0;// this is the counter for the temp hand

  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
     
  r = cardEffect(adventurer, 0, 0, 0, post, 0, &bonus);

 for(i=0; i<2; i++){
  if (pre.deckCount[p] <1){//if the deck is empty we need to shuffle discard and add to deck
    shuffle(p, &pre);
  }
  drawCard(p, &pre);
  cardDrawn = pre.hand[p][pre.handCount[p]-1];//top card of hand is most recently drawn card.
  if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    drawntreasure++;
  else{
    temphand[z]=cardDrawn;
    pre.handCount[p]--; //this should just remove the top card (the most recently drawn one).
    z++;
  }
      }
      while(z-1>=0){
  pre.discard[p][pre.discardCount[p]++]=temphand[z-1]; // discard all cards in play that have been drawn
  z=z-1;
      }


  assert (r == 0);

  if(memcmp(&pre, post, sizeof(struct gameState)) != 0){
        //game states are not equal
        return 1;
  }

 return 0;
}

int main () {

  int r, p, deckCount, discardCount, handCount;
  int numFails = 0, totalRuns = 0;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("RANDOM TEST FOR ADVENTURER.\n");


  SelectStream(2);
  PutSeed(3);


  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
        for (handCount = 0; handCount < 5; handCount++) {
          memset(&G, 23, sizeof(struct gameState)); 
          r = initializeGame(2, k, 1, &G);
          G.deckCount[p] = deckCount;
          memset(G.deck[p], 0, sizeof(int) * deckCount);
          G.discardCount[p] = discardCount;
          memset(G.discard[p], 0, sizeof(int) * discardCount);
          G.handCount[p] = handCount;
          memset(G.hand[p], 0, sizeof(int) * handCount);
          numFails += checkAdventurer(p, &G);
        }
      }
    }
  }

  totalRuns = deckCount * discardCount * handCount * p;

  printf("%d test(s) ran\t\t%d test(s) failed for unequal gamestates\n", totalRuns, numFails);

  return 0;
}
