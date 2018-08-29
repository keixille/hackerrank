count=0
for line in `cat`
do
    arr[$count]=`echo $line | grep -v a`
    count=$(( $count+1 ))
done

echo ${arr[@]}