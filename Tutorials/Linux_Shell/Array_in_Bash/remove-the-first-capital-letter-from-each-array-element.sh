count=0
for line in `cat`
do
    arr[$count]=`echo $line`
    arr[$count]='.'${arr[$count]:1}' '
    count=$(( $count+1 ))
done

echo ${arr[@]}