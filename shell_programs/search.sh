#search keyword in a file

read -p "enter the word to search:" search
read -p "enter the file name:" name
res=`grep $search $name.txt`
len=${#res}

if [ $len -ne 0 ]
then
 echo "the word is present in the file."
else
 echo "the word is not present in the file."
fi

exit 0