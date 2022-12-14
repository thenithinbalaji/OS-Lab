echo "Input :"
read string
count=$(echo "$string"|grep -o -i [aeiou]|wc -l )
echo "Vowel = $count"
