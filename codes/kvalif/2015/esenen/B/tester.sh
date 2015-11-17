for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/B1.cpp -o ${folder%%/}/B1.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/B1.exe < ../Tests/B/green/green.$i.in > a;
		if [[ "`diff -w a ../Tests/B/green/green.$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	g++ ${folder%%/}/B2.cpp -o ${folder%%/}/B2.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/B2.exe < ../Tests/B/skok/skok.$i.in > a;
		if [[ "`diff -w a ../Tests/B/skok/skok.$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

