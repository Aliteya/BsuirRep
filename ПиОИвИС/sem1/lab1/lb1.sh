#!/bin/bash

if [[ "$(wc -l < $1 )" -eq "$(wc -l < $2)" ]] ; then 
     echo "Количество строк одинаковое"

else 

   echo "Количество строк разное"
 

     if [[ "$(wc -w < $1 )" -eq "$(wc -w < $2)" ]] ; then
        echo "Количество слов одинаковое"
      else 
        echo "Количество слов разное"

     fi
fi
sleep 7s