g++ $3 -o $3.exe -O2 -lm -std=c++11;
points=0;
resultFile=results;
echo -n > $resultFile;
for i in `seq -w 1 20` ; 
do
#	timeout $4 ./$3.exe < test\&author/$1-$2/tests/$2.$i.in > a; 
	time ./$3.exe < test\&author/$1-$2/tests/$2.$i.in > a; 
	command_code=$?;
	if [[ "$command_code" = "0" ]]
	then
		if [[ "`diff -w a test\&author/$1-$2/tests/$2.$i.sol`" = "" ]]
		then
			points=$(($points+5));
			printf "  \x1b[32m✓\x1b[0m" >> $resultFile;
		else
			printf "  \x1b[33m✗\x1b[0m" >> $resultFile;
		fi
	else
		if [[ "$command_code" = "139" ]]
		then
			printf "  \x1b[31mF\x1b[0m" >> $resultFile;
		else
			if [[ "$command_code" = "134" ]]
			then
				printf " \x1b[31mME\x1b[0m" >> $resultFile;
			else
				printf "  \x1b[34mt\x1b[0m" >> $resultFile;
			fi
		fi
	fi
####if [[ "`diff -w a test\&author/$1-$2/tests/$2.$i.sol`" = "" ]];
####then
####	points=$(($points+5));
####	echo -n "OK "
####else
####	echo -n "Er ";
####fi
done
echo ""
echo -n "Points: $points -> "
cat results
echo -e "\n---------------------------------";




