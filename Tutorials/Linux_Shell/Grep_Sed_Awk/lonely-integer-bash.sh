unique_elmt=0

read n
for val in `cat`
do
    unique_elmt=$(($unique_elmt^$val))
done

echo $unique_elmt