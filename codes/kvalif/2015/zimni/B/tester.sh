declare -x tests="../tests/B"
for folder in `ls -d */` ;
do
	declare -x result=0;
	declare -x text="";
	g++ ${folder%%/}/b1.cpp -o ${folder%%/}/b1.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 2s ./${folder%%/}/b1.exe < $tests/b1.$i.in > a;
		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a $tests/b1.$i.sol`" = "" ]]
			then
				result=$(($result+10));
				text="$text  \x1b[32m✓\x1b[0m";
			else
				text="$text  \x1b[33m✗\x1b[0m";
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				text="$text  \x1b[31mF\x1b[0m";
			else
				if [[ "$command_code" = "134" ]]
				then
					text="$text \x1b[31mME\x1b[0m";
				else
					text="$text  \x1b[34mt\x1b[0m";
				fi
			fi
		fi
	done
	g++ ${folder%%/}/b2.cpp -o ${folder%%/}/b2.exe -std=c++11 -O2;
	text="$text | "
	for i in `seq -w 1 20`;
	do
		timeout 2s ./${folder%%/}/b2.exe < $tests/b2.$i.in > a;
		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a $tests/b2.$i.sol`" = "" ]]
			then
				result=$(($result+ 5));
				text="$text  \x1b[32m✓\x1b[0m";
			else
				text="$text  \x1b[33m✗\x1b[0m";
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				text="$text  \x1b[31mF\x1b[0m";
			else
				if [[ "$command_code" = "134" ]]
				then
					text="$text \x1b[31mME\x1b[0m";
				else
					text="$text  \x1b[34mt\x1b[0m";
				fi
			fi
		fi
	done
	printf "%3d\t%s\t$text\n" $result $folder >> results;
done
rm a;

