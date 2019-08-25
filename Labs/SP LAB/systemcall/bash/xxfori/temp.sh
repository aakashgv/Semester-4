#!/bin/bash
a=2
b=3

d=$(expr 5 \* 6)
c=$(expr $a \* $b)
echo -e $d
echo -e $c
