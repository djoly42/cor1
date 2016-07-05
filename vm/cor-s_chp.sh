#!/bin/sh

let "i=1"

while [ 1 ]
do
	echo "cycle" $i
./corewar -d $i $1 $1
read -p "test"
((i++))
done
