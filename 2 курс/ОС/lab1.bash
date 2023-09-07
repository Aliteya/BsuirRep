#!/bin/bash
 
for i in $(find "$1" -type f)
do
        ls -lh "$i" | awk '{print "name: " $9, "weight: " $5, "access: " $1 }' 
done