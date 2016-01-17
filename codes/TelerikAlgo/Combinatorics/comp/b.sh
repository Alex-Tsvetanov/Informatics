fact=1;
for i in `seq 1 20` ;
do
	fact=$(($fact*$i));
	for j in `seq 1 $fact`;
	do
		echo "$i $j" > input;
		./permutation_slow.exe < input > output2;
		./permutation.exe < input > output1;
		if [[ "`diff -w output1 output2`" == "" ]]
		then
			echo "\n" > /dev/null;
		else
			echo -e "$i $j\n--------------------";
		fi
	done
done

