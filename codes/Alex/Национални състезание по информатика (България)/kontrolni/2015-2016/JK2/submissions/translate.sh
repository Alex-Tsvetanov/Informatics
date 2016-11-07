fileIn=$1;
fileOut=$2;
echo -e "`cat $fileIN | tail -n +9 | head -n 1 | cut -c 3-`" | sed "s/\\\'/\'/g" | head -n -1 > $fileOut


