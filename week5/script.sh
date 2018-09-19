#!/bin/sh

while : 
do
if ln input.txt input.txt.lock; then

	value=$(tail -1 input.txt)
	result=$(expr $value + 1)
	echo $result>>input.txt
	rm input.txt.lock
	sleep 1
else
	sleep 1
fi
done
