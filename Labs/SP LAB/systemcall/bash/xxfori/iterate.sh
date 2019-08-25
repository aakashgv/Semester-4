#!/bin/bash
a=0
while [ $a -lt 10 ]
 do
 	b=$a
        while (( $b >= 0 ))
	 do
	 	echo -n $b
	 	b=$( expr $b - 1 )
	 done
    a=$( expr $a + 1 )
    echo -e
 done
