#!/bin/bash
echo "Enter string"
read a

b=${#a}
echo $b

for ((i=$b-1;$i>=0;i--))
do
c="$c${a:i:1}"
done
echo $c
if [ $c = $a ]
then
echo "yes,its a pallindrome"
else
echo "no,its not a pallindrome"
fi

