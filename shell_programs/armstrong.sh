#Armstrong number 
read num
temp=$num 
sum=0
i=0 
while [ $temp -gt 0 ] 
do
	digit=`expr $temp % 10`
	i=`expr $digit \* $digit \* $digit`	
	sum=`expr $sum + $i`
	temp=`expr $temp / 10`
done
if [ $num -eq $sum ] 
then
	echo $num is a armstrong number
else
	echo $num is not a armstrong number
fi
exit 0

