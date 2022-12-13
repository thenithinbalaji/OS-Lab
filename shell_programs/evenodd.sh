#Even or odd
echo give an input
read x 
if [ `expr $x % 2` = 0 ]  
then
	echo $x is even number
else
	echo $x is odd number
fi
exit 0 