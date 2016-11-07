num=0;
for task in {best,spaceship,exchange};
do
	num=$(($num+1));
	for folder in `ls -d submitions/*/` ;
	do
		echo $folder;
		string="${folder%?}";
		for i in `ls $string/edited/$task/` ;
		do
			cp $string/edited/$task/$i test.cpp ;
			echo $i; 
			bash test.sh $num $task test.cpp `cat timeout_$task`; 
		done;
	done;
done
