echo "Enter a five digit number"
read num
size=${#num}
if [ $size -eq 5 ] && [[ $num =~ ^[0-9] ]]
then
    echo "Yes its a five digit number"
    echo "pos 1 ${num:0:1}"
    echo "pos 3 ${num:2:1}"
    echo "pos 5 ${num:4:1}"
else
    echo "Wrong input"
fi
