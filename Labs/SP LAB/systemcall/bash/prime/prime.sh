#!/bin/bash

echo "enter a number- "
read a


if (( $a == 2 ))
 then
 	echo "the number entered is prime"


else

 count=0
 i=2
 while (( i < a ))
  do
 	if(( a % i == 0 ))
 	 then
 	    ((count++))
 	    ((i++))
	else
    ((i++))
    fi
 done

	 if(( count == 0 ))
 	 	then 
 		echo -e "prime nos"
	 else
		echo -e "not a prime number"
	 fi
 	
fi
