for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/D1.cpp -o ${folder%%/}/D1.exe -std=c++11 -O2;
	for i in `seq -w 1 5`;
	do
		timeout 1 ./${folder%%/}/D1.exe < ../Tests/D/task1/task1.0$i.in > a;
		if [[ "`diff -w a ../Tests/D/task1/task1.0$i.sol`" == "" ]];
		then
			result=$(($result + 20));
		fi
	done
	g++ ${folder%%/}/D2.cpp -o ${folder%%/}/D2.exe -std=c++11 -O2;
	for i in `seq -w 1 20`;
	do
		timeout 1 ./${folder%%/}/D2.exe < ../Tests/D/task2/task2.$i.in > a;
		if [[ "`diff -w a ../Tests/D/task2/task2.$i.sol`" == "" ]];
		then
			result=$(($result + 5));
		fi
	done
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

