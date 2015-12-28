#/bin/bash
echo "" > resultsAgrain;

for j in `seq -w 1 30` ;
do
	printf " " >> resultsAgrain;
done
for j in `seq -w 1 25` ;
do
	printf " $j" >> resultsAgrain;
done;

printf "\n" >> resultsAgrain;

for i in `ls -d ./agrain.cpp/*.cpp` ;
do
	g++ $i -O2 -std=c++11 -o a.exe;
	result=0;
	system_log="";
	printf "%30s" "$i" >> resultsAgrain;
	for j in `seq -w 1 25` ;
	do
		echo "$j:";
		timeout 5s ./a.exe < ./Tests/agrain/Tests/Agrain.$j.in > a.out
		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a.out ./Tests/agrain/Tests/Agrain.$j.sol`" = "" ]]
			then
				result=$(($result+4));
				system_log="$system_log  1";
				printf "  \x1b[32m✓\x1b[0m" >> resultsAgrain;
			else
				system_log="$system_log  0";
				printf "  \x1b[33m✗\x1b[0m" >> resultsAgrain;
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				system_log="$system_log  F";
				printf "  \x1b[31mF\x1b[0m" >> resultsAgrain;
			else
				system_log="$system_log  t";
				printf "  \x1b[34mt\x1b[0m" >> resultsAgrain;
			fi
		fi

	done
	printf "%3d\n" $result >> resultsAgrain;
done

rm a.exe a.out
