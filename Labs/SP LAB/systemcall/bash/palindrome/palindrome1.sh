#!/bin/bash
echo enter the string
read s
c=0
for((i=0,j=${#s}-1;i<=${#s}\/2,j>=${#s}\/2;i++,j--));
do
    echo  ${s:$i:1} ${s:$j:1}
    if((${s:$i:1}!=${s:$j:1}))
    then
        c=1
        break
    fi
 done   
if((c==1))
then
    echo string is not pallindrome
else
    echo string is pallindrome
fi
