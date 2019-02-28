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

int checkVillage(int p, struct gameState *post) {
  int r, i;
  int bonus = 0, handPos=0;

  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
 
 for (i=0; i < 4; i++){
  post->whoseTurn=i;
  r = cardEffect(village, 0, 0, 0, post, 0, &bonus); 


      //+1 Card
      drawCard(p, &pre);
 
      //+2 Actions
      pre.numActions = pre.numActions + 2;

    //discard card from hand
    discardCard(handPos, p, &pre, 0);
  }

     // printf("Pre Hand count: %d\n", pre.handCount[p]);
     //  printf("Post Hand count: %d\n", post->handCount[p]);
 printf("Pre numActions: %d\tPost numActions: %d\n",pre.numActions, post->numActions);


  if (pre.numActions < post->numActions) {
    return 2;
  } else if (pre.numActions > post->numActions) {
    return 1;
  } else {

    assert (r == 0);

    if(memcmp(&pre, post, sizeof(struct gameState)) == 0) {
         return 3;
    }
  }
}

int main () {

  int result, r, p, deckCount, discardCount, handCount;
  int postFailure=0, preFailure=0, pass=0;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("RANDOM TEST FOR VILLAGE.\n");


  SelectStream(2);
  PutSeed(3);


  for (p = 0; p < 4; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
        for (handCount = 0; handCount < 5; handCount++) {
          memset(&G, 23, sizeof(struct gameState)); 
          r = initializeGame(4, k, 1, &G);
          G.deckCount[p] = deckCount;
          memset(G.deck[p], 0, sizeof(int) * deckCount);
          G.discardCount[p] = discardCount;
          memset(G.discard[p], 0, sizeof(int) * discardCount);
          G.handCount[p] = handCount;
          memset(G.hand[p], 0, sizeof(int) * handCount);
          result = checkVillage(p, &G);

          if(result == 2) {
            postFailure += (result/2);
          }else if(result == 1) {
            preFailure += result;
          } else {
            pass += (result/3);
          }
        }
      }
    }
  }
  printf("%d tests occured\n", (p*handCount*deckCount*discardCount));
  printf("%d test(s) failed where Post has more actions then Pre\n", postFailure);
  printf("%d test(s) failed where Pre has more actions then Post\n", preFailure);
  printf("%d test(s) passed where Post and Pre had equal number of actions\n", pass);
  
  return 0;
}
