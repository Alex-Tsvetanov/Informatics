for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/c1.cpp -o ${folder%%/}/c1.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/c1.exe < ../Tests/C/school/school.$i.in > a;
		if [[ "`diff -w a ../Tests/C/school/school.$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	g++ ${folder%%/}/c2.cpp -o ${folder%%/}/c2.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/c2.exe < ../Tests/C/number/number.$i.in > a;
		if [[ "`diff -w a ../Tests/C/number/number.$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

