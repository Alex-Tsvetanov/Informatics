for folder in `ls -d */` ;
do
	declare -x result=0;
	g++ ${folder%%/}/E1.cpp -o ${folder%%/}/E1.exe -std=c++11 -O2;
	for i in `seq -w 1 10`;
	do
		timeout 1 ./${folder%%/}/E1.exe < ../Tests/E/E1/sign.$i.in > a;
		if [[ "`diff -w a ../Tests/E/E1/sign.$i.sol`" == "" ]];
		then
			result=$(($result + 10));
		fi
	done
	result=$(($result+`cat res${folder%%/}`));
	printf "%3d\t%s\n" $result $folder >> results;
done
rm a;

