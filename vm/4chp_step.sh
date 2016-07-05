#!/bin/sh

let "i=1"

while [ 1 ]
do
	echo "cycle" $i
./corewar -d $i $1 $2 $3 $4
read -p "test"
((i=i+$5))
done
