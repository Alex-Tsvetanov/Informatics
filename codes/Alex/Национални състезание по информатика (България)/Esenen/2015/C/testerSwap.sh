#/bin/bash
echo "" > resultsSwap;
for i in `ls ./swap.cpp` ;
do
	g++ ./swap.cpp/$i -O2 -std=c++11 -o a.exe;
	result=0;
	system_log="";
	for j in `seq -w 1 25` ;
	do
		timeout 3s ./a.exe < ./Tests/swap/tests/swap.$j.in > a.out
		if [[ "`./Tests/swap/check/check_swap.exe Tests/swap/tests/swap.$j.in x a.out`" = "1" ]]
		then
			result=$(($result+4));
			system_log="$system_log 1";
		else
			system_log="$system_log 0";
		fi;
	done
	printf "swap.cpp/$i $system_log %3d\n" $result >> resultsSwap;
done

rm a.exe a.out
