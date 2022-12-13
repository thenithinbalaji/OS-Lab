#Calculator Menu driven
echo "------Menu Driven Calculator------"
echo "1: add"
echo "2: sub"
echo "3: mul"
echo "4: div"
read -p "enter your choice: " num
read -p "enter first number: " num1
read -p "enter second number: " num2
add(){
 sum=`expr $num1 + $num2`
 echo the sum of the two given numbers is $sum.
}

sub(){
 sub=`expr $num1 - $num2`
 echo the difference of the two given numbers is $sub.
}

mul(){
 mul=`expr $num1 \* $num2`
 echo the multiplication of the two given numbers is $mul.
}

div(){
 div=`expr $num1 / $num2`
 echo the division between the two given numbers is $div.
}

if [ $num = 1 ]
then 
 add
fi

if [ $num = 2 ]
then 
 sub
fi

if [ $num = 3 ]
then 
 mul
fi

if [ $num = 4 ]
then 
 div
fi

exit 0
