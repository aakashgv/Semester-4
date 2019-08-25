#!/bin/bash
echo "Enter two numbers" 
read a b 
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read c
d=0
if((c==3))
then
    d=$(( a * b ))
    echo $d
fi

if((c==1))
then 
    d=$(( a + b ))
    echo $d
fi

if((c==4))
then
    d=$(( a / b ))
    echo $d
fi

if((c==2))
then
    d=$(( a - b ))
    echo $d
fi


