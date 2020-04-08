#!/bin/bash

for i in {1..$1}
do
	echo $(($RANDOM % $2))
done
