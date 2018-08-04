while read line
do
    cut -f -3 <<< "$line"
done