mkdir originals;
mv * originals;
mv originals/do_all.sh .;
mkdir -p edited edited/{best,exchange,spaceships} {best,exchange,spaceships};
for name in {best,exchange,spaceships};
do
	for i in `ls originals/` ; 
	do 
		if [[ "`cat originals/$i | grep $name`" != "" ]] ; 
		then 
			cp originals/$i $name ; 
		fi ; 
	done;
done
rm -rf originals
cp ../translate.sh .;
for folder5 in {best,exchange,spaceships}; 
do 
	for i in `ls $folder5` ; 
	do 
		bash translate.sh $folder5 $i ; 
	done ; 
done

