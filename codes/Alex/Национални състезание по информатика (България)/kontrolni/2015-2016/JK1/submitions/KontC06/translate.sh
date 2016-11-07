folder=$1
file=$2;
echo -e "`cat $folder/$file | tail -n +9 | head -n 1 | cut -c 3-`" | sed "s/\\\'/\'/g" | head -n -1 > edited/$folder/$file


