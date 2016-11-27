#!/bin/bash

for i in `seq 20`; do
	echo $(($RANDOM*$RANDOM % 1000000))
done
