#!/bin/bash

for i in `seq 10`; do
	k=$(($RANDOM % 1000))
	echo $k
	for i in `seq $k`; do
		echo -n "$(($RANDOM % 1000000)) "
	done
	echo
done
