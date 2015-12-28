#/bin/bash
echo "" > resultsTwoStr;
for i in `ls ./twostr.cpp` ;
do
	g++ ./twostr.cpp/$i -O2 -std=c++11 -o a.exe;
	result=0;
	system_log="";
	for j in `seq -w 1 50` ;
	do
		timeout 3s ./a.exe < ./Tests/twostr/tests/twostr.$j.in > a.out
		if [[ "`diff Tests/twostr/tests/swap.$j.sol a.out`" = "" ]]
		then
			result=$(($result+4));
			system_log="$system_log 1";
		else
			system_log="$system_log 0";
		fi;
	done
	printf "swap.cpp/$i %s %3d\n" $system_log $result >> resultsTwoStr;
done

rm a.exe a.out
