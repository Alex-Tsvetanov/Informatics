for i in `seq -w 1 10`;
do
	timeout 0.6s ../esenen2012C3.exe < ./tests/tvgame.$i.in > output;
	currPoints=`./checker/tvgame.checker.exe ./tests/tvgame.$i.in ./tests/tvgame.$i.sol output 10`;
#echo $currPoints;
	totalPoints=$(($totalPoints+$currPoints));
done

echo $totalPoints;
