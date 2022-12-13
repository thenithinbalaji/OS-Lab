echo "Enter number of terms"
read n
first=0
second=1
if [[ $n =~ [0-9] ]] 
then
    count=`expr $n - 2`
    if [ $n -eq 1 ] 
    then
        echo "$first"
    elif [ $n -eq 2 ] 
    then
        echo "$first"
        echo "$second"
    else
        echo "$first"
        echo "$second"
        while [ $count -gt 0 ] 
        do
            temp=`expr $second`
            second=`expr $first + $second`
            first=`expr $temp`
            echo "$second"
            count=`expr $count - 1`
        done
    fi
else
    echo "Enter number of terms in integer"
fi