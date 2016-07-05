#!/bin/sh

let "i=1"

while [ 1 ]
do
	echo "cycle" $i
./corewar -d $i $2 $1 $2 $2
read -p "test"
((i=i+$3))
done
