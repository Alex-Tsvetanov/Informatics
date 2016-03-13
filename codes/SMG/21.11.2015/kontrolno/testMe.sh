g++ src/$1/$1_1.cpp -o a.exe -std=c++11 -O2

points=0;
testingoutput="";

for i in `seq -w 1 1`;
do
	timeout 1s ./a.exe < ./test_1_input/$i.in > a;
	if [[ "`diff -w a ./test_1_output/$i.sol`" = "" ]];
	then
		points=$(($points+100));
		testingoutput="$testingoutput 1";
	else
		testingoutput="$testingoutput 0";
	fi
done
testingoutput="$testingoutput   |   "
g++ src/$1/$1_2.cpp -o a.exe -std=c++11 -O2
for i in `seq -w 1 20`;
do
	timeout 1s ./a.exe < ./test_2_input/$i.in > a;
	if [[ "`diff -w a ./test_2_output/$i.sol`" = "" ]];
	then
		points=$(($points+5));
		testingoutput="$testingoutput 1";
	else
		testingoutput="$testingoutput 0";
	fi
done

printf "%20s: \t$testingoutput   |   %3d\n" $1 $points >> scoreFromAlex;
printf "%20s: \t$testingoutput   |   %3d\n" $1 $points;

rm a a.exe

