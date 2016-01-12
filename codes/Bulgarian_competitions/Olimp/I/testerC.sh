#!/bin/bash
for FOLDER in `ls -d ./C/*/` ;
do
	./testerC++.sh tetris 40 $FOLDER ./Tests/C/tetris/tests/ 2.5 resultTetris 1s default true 2>&1
	./testerC++.sh stepen 10 $FOLDER ./Tests/C/stepen/tests/ 10 resultStepen 1s default false 2>&1
	./testerC++.sh prime 10 $FOLDER ./Tests/C/prime/tests/ 10 resultPrime 1s default false 2>&1

	cat resultPrime > $FOLDER/resultC;
#	echo "" >> $FOLDER/resultC;
	cat resultStepen >> $FOLDER/resultC;
#	echo "" >> $FOLDER/resultC;
	cat resultTetris >> $FOLDER/resultC;
#	echo "" >> $FOLDER/resultC;
	rm resultPrime resultStepen resultTetris;
done


