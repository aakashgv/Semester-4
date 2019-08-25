#!/bin/bash
echo "Enter lower limit: "
read n1 
echo "Enter the Upper limit"
read n2
for((i=$n1;i<=$n2;i++));
do
a=i
s=0
while((a>0))
do
    k=$((a%10))
    ((a\/=10))
   # ((s+=$[$k**3]))
   ((s+=$((k**3))))
done
if((i==s))
then
    echo Armstrong Number is $s
fi
done
