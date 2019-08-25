#!/bin/bash
n=3
for((i=1;i<$n+1;i++));
do
    for((j=1;j<$n+1;j++));
    do
        for((k=1;k<$n+1;k++));
        do
            if(( i!=j && j!=k && i!=k ))
            then
                 echo $i $j $k
            fi
        done
    done
done
