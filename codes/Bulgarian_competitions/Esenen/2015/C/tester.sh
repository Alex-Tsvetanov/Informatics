echo -ne "" > results;
for i in `ls ./twostr.cpp` ;
do
	g++ ./twostr.cpp/$i -O2 -std=c++11 -o a.exe;
	result=0;
	for j in `seq -w 1 50` ;
	do
		timeout 0.5s ./a.exe < ./Tests/twostr/tests/twostr.$j.in > a.out
		if [[ "`diff -w a.out ./Tests/twostr/tests/twostr.$j.sol`" = "" ]]
		then
			result=$(($result+2));
		fi;
	done
	printf "twostr.cpp/$i %3d\n" $result >> results;
done
echo "" >> results;
echo "" >> results;
for i in `ls ./swap.cpp` ;
do
	g++ ./swap.cpp/$i -O2 -std=c++11 -o a.exe;
	result=0;
	for j in `seq -w 1 25` ;
	do
		timeout 3s ./a.exe < ./Tests/swap/tests/swap.$j.in > a.out
		if [[ "`diff -w a.out ./Tests/swap/tests/swap.$j.sol`" = "" ]]
		then
			result=$(($result+4));
		fi;
	done
	printf "swap.cpp/$i %3d\n" $result >> results;
done
echo "" >> results;
echo "" >> results;
for i in `ls ./agrain.cpp` ;
do
	g++ ./agrain.cpp/$i -O2 -std=c++11 -o a.exe;
	result=0;
	for j in `seq -w 1 25` ;
	do
		timeout 3s ./a.exe < ./Tests/agrain/Tests/Agrain.$j.in > a.out
		if [[ "`diff -w a.out ./Tests/agrain/Tests/Agrain.$j.sol`" = "" ]]
		then
			result=$(($result+4));
		fi;
	done
	printf "agrain.cpp/$i %3d\n" $result >> results;
done

rm a.exe a.out
		
