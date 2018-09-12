#!/bin/bash
cp /dev/null output_exer_1.txt
echo "Run 10 times">>output_exer_1.txt
for x in 1 2 3 4 5 6 7 8 9 10
do 
 ./ex1 >> output_exer_1.txt
done
