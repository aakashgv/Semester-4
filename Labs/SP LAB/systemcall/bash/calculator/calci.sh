#!/bin/bash
echo enter the numbers
read n m
echo enter the operator
read op
echo $op
if [ $op -eq + ]
then 
    echo $(( $n + $m )) 
elif (( $op=='-' ))
then 
    echo $(( $n - $m ))  
elif (( $op=='*' ))
then 
    echo $(( $n * $m ))
elif (( $op=='/' ))
then 
    echo $(( $n / $m ))
else
    echo invalid operation
fi
