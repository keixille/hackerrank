count=0
for line in `cat`
do
    count=$(( $count+1 ))
done

echo $count