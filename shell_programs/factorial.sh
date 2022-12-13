#Factorial of a number
echo enter a value
read x 
res=1
i=1
while [ $i -le $x ] 
do
	res=`expr $res \* $i`
	i=`expr $i + 1`
done
echo "Factorial = " $res
exit 0