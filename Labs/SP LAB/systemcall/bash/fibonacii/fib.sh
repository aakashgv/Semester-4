#!/bin/bash

echo "Enter end number:  "
read a

b=0
c=1
d=0
echo -n $b   $c
while(( $d <= $a ))
 do
   d=$( expr $b + $c )
  echo -n "  " $d
    b=$c
    c=$d
 done

echo -e

