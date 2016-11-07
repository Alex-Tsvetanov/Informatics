#!/bin/bash
g++ -Wall -O3 -std=c++11 -o strip.exe ./Solutions/strip_BG.cpp;
for i in `seq -w 1 10` ;
do
	cp ./PreliminaryTests/strip.$i.in strip.in;
	timeout 1s ./strip.exe;
	if [[ "`diff -w strip.out ./PreliminaryTests/strip.$i.sol`" = "" ]];
	then
		echo "OK";
	else
		echo "Wrong Answer";
		cat strip.out ./PreliminaryTests/strip.$i.sol ;
	fi
	echo "------------------------------------------------------";
done

