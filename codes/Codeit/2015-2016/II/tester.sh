points=0;
for taskName in {barcode,bullcode,cities,clown,rana,robots,scourge,wizard} ;
do
	g++ -Wall -O3 -std=c++11 -о $taskName.exe source_codes/$taskName.cpp

	case $taskName in
	barcode)
		tests=5
		maxpoints=50
		;;
	bullcode)
		tests=15
		maxpoints=80
		;;
	cities)
		tests=8
		maxpoints=180
		;;
	clown)
		tests=5
		maxpoints=200
		;;
	rana)
		tests=5
		maxpoints=50
		;;
	robots)
		tests=15
		maxpoints=150
		;;
	scourge)
		tests=5
		maxpoints=100
		;;
	wizard)
		tests=30
		maxpoints=320
		;;
	esac
	localpoints=$maxpoints;
	for i in `seq -w 1 $tests` ;
	do
		ind="$i";
		if [[ $i < 10 ]] ; 
		then 
			ind="0$ind";
		fi
		cp ./Tests/$taskName/$taskName.$ind.in $taskName.in;
		./$taskName.exe ;
		if [[ "`diff -w $taskName.$ind.sol $taskName.out`" != "" ]];
		then
			localpoints=0;
		fi
	done
	echo "$taskName: $localpoints";
	points=$(($points+$localpoints));
done
echo "Total: $points";
