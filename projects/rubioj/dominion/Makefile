CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: playdom
	gcc dominion.o rngs.o unittest1.c -o unittest1  $(CFLAGS)

unittest2: playdom
	gcc dominion.o rngs.o unittest2.c -o unittest2 $(CFLAGS)
	
unittest3:playdom
	gcc dominion.o rngs.o unittest3.c -o unittest3 $(CFLAGS)
	
unittest4: playdom
	gcc dominion.o rngs.o unittest4.c -o unittest4 $(CFLAGS)
	
cardtest1: playdom
	gcc dominion.o rngs.o cardtest1.c -o cardtest1 $(CFLAGS)

cardtest2: playdom
	gcc dominion.o rngs.o cardtest2.c -o cardtest2 $(CFLAGS)

cardtest3: playdom
	gcc dominion.o rngs.o cardtest3.c -o cardtest3 $(CFLAGS)

cardtest4: playdom
	gcc dominion.o rngs.o cardtest4.c -o cardtest4 $(CFLAGS)

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	
randomtestadventurer: playdom
	gcc dominion.o rngs.o randomtestadventurer.c -o randomtestadventurer $(CFLAGS)

randomtestcard1: playdom
	gcc dominion.o rngs.o randomtestcard1.c -o randomtestcard1 $(CFLAGS)

randomtestcard2: playdom
	gcc dominion.o rngs.o randomtestcard2.c -o randomtestcard2 $(CFLAGS)


randomresults: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestadventurer > randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	./randomtestcard1> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	./randomtestcard2> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
