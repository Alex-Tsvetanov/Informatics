#/bin/sh
for folder in `ls -d source_codes/*/` ;
do

points=0;
for taskName in {barcode,bullcode,cities,clown,rana,robots,scourge,wizard} ;
do
	case $taskName in
	barcode)
		tests=5
		maxpoints=50
		prefix="0"
		;;
	bullcode)
		tests=15
		maxpoints=80
		prefix=""
		;;
	cities)
		tests=8
		maxpoints=180
		prefix="0"
		;;
	clown)
		tests=5
		maxpoints=200
		prefix="0"
		;;
	rana)
		tests=5
		maxpoints=50
		prefix="0"
		;;
	robots)
		tests=15
		maxpoints=150
		prefix=""
		;;
	scourge)
		tests=5
		maxpoints=100
		prefix="0"
		;;
	wizard)
		tests=30
		maxpoints=320
		prefix=""
		;;
	esac
	localpoints=$maxpoints;
	g++ ${folder%?}/$taskName.cpp -o $taskName.exe -Wall -O3 -std=c++11;
	log="";
	for i in `seq -w 1 $tests` ;
	do
		ind="$prefix$i";
		cp Tests/$taskName/$taskName.$ind.in $taskName.in;
		timeout 1.0s ./$taskName.exe ;
		if [[ "`diff -w Tests/$taskName/$taskName.$ind.sol $taskName.out`" != "" ]];
		then
			log="$log X";
			localpoints=0;
		else
			log="$log v"
		fi
	done
	echo -e "$taskName: $localpoints\tTesting System log: $log";
	points=$(($points+$localpoints));
	rm $taskName.{in,out,exe}
done
echo -e "$folder:\n\tTotal: $points/$((50+80+180+50+100+150+200+320))";

done

