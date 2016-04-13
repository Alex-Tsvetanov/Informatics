#/bin/bash
taskName=$1;
numberOfTests=$2;
folderWithSources=$3;
folderWithTests=$4;
pointsToTest=$5;
resultFile=$6;
timelimit=$7;
compile_command=$8;
if [[ "$compile_command" = "" ]] then compile_command="g++ -O2 -std=c++11"; fi

echo "" > $resultFile;

for j in `seq -w 1 30` ;
do
	printf " " >> $resultFile;
done
for j in `seq -w 1 $numberOfTests` ;
do
	printf " $j" >> $resultFile;
done;

printf "\n" >> $resultFile;

for i in `ls -d $folderWithSources/*.cpp` ;
do
	$compile_command $i -o a.exe;
	result=0;
	printf "%30s" "$i" >> $resultFile;
	for j in `seq -w 1 $numberOfTests` ;
	do
		echo "$j:";
		timeout $timelimit ./a.exe < $folderWithTests/$taskName.$j.in > a.out
		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a.out $folderWithTests/$taskName.$j.sol`" = "" ]]
			then
				result=$(($result+$pointsToTest));
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

	done
	printf "%4d\n" $result >> $resultFile;
done

rm a.exe a.out
