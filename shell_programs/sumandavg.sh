echo 'Enter first number '
read a
echo 'Enter first number '
read b
echo 'Enter first number '
read c
echo 'Enter first number '
read d

if [[ "$a" =~ [0-9] ]] && [[ "$b" =~ [0-9] ]] && [[ "$c" =~ [0-9] ]] && [[ "$d" =~ [0-9] ]]
then
    sum=`expr $a + $b + $c + $d`
    avg=`expr $sum / 4`
    echo "Sum $sum"
    echo "Avg $avg"

else
    echo "sorry only integers"    
fi
