sum=0
read count
for ((i=1; i<=$count; i++))
do
    read number
    sum=$(($sum + $number))
done

long_number=$(($sum*10000/$count))
if (($long_number%10 >= 5));
then
    long_number=$((($long_number/10)+1))
else
    long_number=$(($long_number/10))
fi

integer=$(($long_number/1000))
fractal=$(echo $long_number | rev | cut -c -3 | rev)
echo $integer.$fractal