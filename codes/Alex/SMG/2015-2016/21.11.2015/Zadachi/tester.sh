for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/names.cpp -o ${folder%%/}/names.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/names.exe < ../Tests/names.$i.in > a;
		if [[ "`diff -w a ../Tests/names.$i.sol`" == "" ]];
		then
			result=$(($result + 20));
		fi
	done
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

