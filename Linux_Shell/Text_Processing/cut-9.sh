while read line
do
    cut -f 2- <<< "$line" 
done