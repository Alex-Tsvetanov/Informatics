tasks={"grid","leaders","maxnotice"};
for folder in `ls -d ./Sources/D/*`;
do
	echo "$folder:";
	points=0;
	point1=0;
	log1="";
	task="candies";
	OUTPUT_FILE=$task.exe;
	SOURCE_FILE=$folder/$task.cpp;
	g++ -o $OUTPUT_FILE -O2 -s -static -lm -x c++ $SOURCE_FILE -std=gnu++03
	for i in `seq -w 1 20`;
	do
		timeout `cat time_$task` ./$OUTPUT_FILE < Tests/D/$task/tests/$task.$i.in > a;
		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w Tests/D/$task/tests/$task.$i.sol a`" = "" ]]
			then
				points=$(($points+5));
				point1=$(($point1+5));
				log1="$log1  \x1b[32m✓\x1b[0m";
			else
				log1="$log1  \x1b[33m✗\x1b[0m";
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				log1="$log1  \x1b[31mF\x1b[0m";
			else
				if [[ "$command_code" = "134" ]]
				then
					log1="$log1  \x1b[31mME\x1b[0m";
				else
					log1="$log1  \x1b[34mt\x1b[0m";
				fi
			fi
		fi
	done
	point2=0;
	log2="";
	task="code";
	OUTPUT_FILE=$task.exe;
	SOURCE_FILE=$folder/$task.cpp;
	g++ -o $OUTPUT_FILE -O2 -s -static -lm -x c++ $SOURCE_FILE -std=gnu++03
	for i in `seq -w 1 20`;
	do
		timeout `cat time_$task` ./$OUTPUT_FILE < Tests/D/$task/tests/$task.$i.in > a;		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a Tests/D/$task/tests/$task.$i.sol`" = "" ]]
			then
				points=$(($points+5));
				point2=$(($point2+5));
				log2="$log2  \x1b[32m✓\x1b[0m";
			else
				log2="$log2  \x1b[33m✗\x1b[0m";
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				log2="$log2  \x1b[31mF\x1b[0m";
			else
				if [[ "$command_code" = "134" ]]
				then
					log2="$log2  \x1b[31mME\x1b[0m";
				else
					log2="$log2  \x1b[34mt\x1b[0m";
				fi
			fi
		fi
	done
	point3=0;
	log3="";
	task="rect";
	OUTPUT_FILE=$task.exe;
	SOURCE_FILE=$folder/$task.cpp;
	g++ -o $OUTPUT_FILE -O2 -s -static -lm -x c++ $SOURCE_FILE -std=gnu++03
	for i in `seq -w 1 25`;
	do
		timeout `cat time_$task` ./$OUTPUT_FILE < Tests/D/$task/tests/$task.$i.in > a;		command_code=$?;
		if [[ "$command_code" = "0" ]]
		then
			if [[ "`diff -w a Tests/D/$task/tests/$task.$i.sol`" = "" ]]
			then
				points=$(($points+4));
				point3=$(($point3+4));
				log3="$log3  \x1b[32m✓\x1b[0m";
			else
				log3="$log3  \x1b[33m✗\x1b[0m";
			fi
		else
			if [[ "$command_code" = "139" ]]
			then
				log3="$log3  \x1b[31mF\x1b[0m";
			else
				if [[ "$command_code" = "134" ]]
				then
					log3="$log3  \x1b[31mME\x1b[0m";
				else
					log3="$log3  \x1b[34mt\x1b[0m";
				fi
			fi
		fi
	done
	printf "%3d | %3d | %3d | %3d | %20s\n" $points $point1 $point2 $point3 $folder >> resultsD_bez_log;
	echo "--------------------------------------";
done
