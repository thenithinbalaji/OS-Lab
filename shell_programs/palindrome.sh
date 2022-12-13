echo "Enter a string"
read string

pal=$(echo "$string"| rev)

if [ $pal = $string ] 
then
    echo "$pal"
    echo "palindrome"
else
    echo "$pal"
    echo "not a palindorf"
fi