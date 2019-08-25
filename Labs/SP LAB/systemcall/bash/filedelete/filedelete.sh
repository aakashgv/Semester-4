#!/bin/bash
diff $1 $2 >file.txt
if [ -s file.txt ]
then 
    echo files inputed are different
    
else
    echo files inputed are same
    rm $2
    
fi
