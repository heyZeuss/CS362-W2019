//José-Antonio D. Rubio
//CS 362-400
//unittest1.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"




int main() {
  int i, j;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);


    printf("TESTING SHUFFLE\n\n");

    printf("Display current deck order\n");

    for(i=0; i< G.deckCount[1]; i++){
      printf("%d, ", G.deck[1][i]);
    }
  
     for(j=0; j<20; j++){ 
         printf("\nCalling Shuffle\n");
     
           shuffle(1, &G);
     
         // printf("Display shuffled deck order\n");
     
           for(i=0; i< G.deckCount[1]; i++){
             printf("%d, ", G.deck[1][i]);
           }
        }

  printf("\n\n\nCreating a deck of cards numbered 0-9 and displaying them.\n\n");

    for(i=0; i< G.deckCount[1]; i++){
      G.deck[1][i] = i;
    }

    for(i=0; i< G.deckCount[1]; i++){
      printf("%d, ", G.deck[1][i]);
    }

    for(j=0; j<20; j++){ 
      printf("\nCalling Shuffle\n");

      shuffle(1, &G);

      // printf("Display shuffled deck order\n");

        for(i=0; i< G.deckCount[1]; i++){
          printf("%d, ", G.deck[1][i]);
        }
    }

   printf("\n\n\nTESTING SHUFFLE with a different seed for game initialization\n\n");

     initializeGame(2, k, 200, &G);

    printf("Display current deck order\n");

    for(i=0; i< G.deckCount[1]; i++){
      printf("%d, ", G.deck[1][i]);
    }
  
    
    for(j=0; j<20; j++){ 
      printf("\nCalling Shuffle\n");

      shuffle(1, &G);

      // printf("Display shuffled deck order\n");

      for(i=0; i< G.deckCount[1]; i++){
        printf("%d, ", G.deck[1][i]);
      }
    }
    printf("\n");

  return 0;
}