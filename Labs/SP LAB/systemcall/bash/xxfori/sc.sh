#!/bin/bash

echo "enter any number-"
read a

echo "MAIN MENU"
echo "1.find -ve or +ve"
echo "2.find whether even or odd"

echo "enter your choice"
read ch

case $ch in
	1)
		if(( $a >= 0))
		 then
		 echo "+ve"
		else
		 echo "-ve"
		fi
	    ;;
	2)
	    
        if (( $a % 2 == 0 )) 
         then
 	     	echo "even number"
 	 
        else
     		echo "odd number"
	    fi
	    ;; 
   *)
      echo "wrong choice"
	
esac

