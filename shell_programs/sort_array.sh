echo " Enter an array "
read -a array
n=${#array[@]}
i=0
while [ $i -le `expr $n - 1` ] 
do
    j=`expr $i + 1`
    while [ $j -le $n ] 
    do
        if [[ ${array[i]} -gt ${array[j]} ]] 
        then
            temp=${array[i]}
            array[i]=${array[j]}
            array[j]=$temp
        fi
        j=`expr $j + 1`
    done
    i=`expr $i + 1`
done
echo "${array[@]}"