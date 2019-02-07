//José-Antonio D. Rubio
//CS 362-400
//cardtest1.c

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
  int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


  initializeGame(2, k, 30, &G);

  delay();

  printf("TESTING SMITHY\n\n");

  cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);


  return 0;
}


//Refernece: https://www.quora.com/How-can-I-end-a-function-after-predefined-period-of-time-seconds-in-C
//delay will delay for 2.5 minutes before exiting out of the program
//this was done because the smithy function is a never ending loop
void delay()

{

clock_t delay = NUM_SECS * CLOCKS_PER_SEC; // convert seconds to clock ticks

clock_t start = clock(); // get starting clock ticks

while((clock() - start) < delay);

printf("TIMING OUT\t\tExitingProgram\n");
exit(0);

}// end delay()


// void playSmithy(int currentPlayer, struct gameState *state, int handPos){ 
//       //+3 Cards
//   //  for (int i = 0; i < 3; i++)
//   while(1)
//   {
//     drawCard(currentPlayer, state);
//   }
      
//       //discard card from hand
//       discardCard(handPos, currentPlayer, state, 0);
//   }