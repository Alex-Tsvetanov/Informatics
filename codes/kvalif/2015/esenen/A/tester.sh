for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/A1.cpp -o ${folder%%/}/A1.exe -std=c++11 -O2;
	for i in `seq -w 0 9`;
	do
		timeout 1 ./${folder%%/}/A1.exe < ../Tests/A/A1/rays.0$i.in > a;
		if [[ "`diff -w a ../Tests/A/A1/rays.0$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	g++ ${folder%%/}/A2.cpp -o ${folder%%/}/A2.exe -std=c++11 -O2;
	for i in `seq -w 0 9`;
	do
		timeout 1 ./${folder%%/}/A2.exe < ../Tests/A/A2/fast.0$i.in > a;
		if [[ "`diff -w a ../Tests/A/A2/fast.0$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

