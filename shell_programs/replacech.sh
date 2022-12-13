echo "Enter a string"
read string
echo "Enter a character to be replaced"
read a
echo "Enter a character to be replaced with"
read b
string=$(echo "$string" | tr "$a" "$b")
echo "New string $string"