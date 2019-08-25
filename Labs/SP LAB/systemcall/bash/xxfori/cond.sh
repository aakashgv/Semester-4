#!/bin/bash

b="enter any number-"
echo $b
read a

if (( $a % 2 == 0 )) 
 then
 	echo "even number"
 	 
else
	echo "odd number"
	 
fi
