count=0
for line in `cat`
do
    arr[$count]=`echo $line`
    count=$(( $count+1 ))
done

concatenatedArr=`echo ${arr[@]} ${arr[@]} ${arr[@]}`
echo $concatenatedArr

