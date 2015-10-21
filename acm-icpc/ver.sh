#!/bin/bash

L=`ls`

for i in $L; do
	echo $i
	cat $i | grep -H -n -i $1
done
