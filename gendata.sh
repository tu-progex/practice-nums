#!/bin/bash -x
perl gen_rands.pl 10 10 0 > nums10.txt
perl gen_rands.pl 1000 1000 0 > nums1k.txt
perl gen_rands.pl 1000000 1000000 0 > nums1M.txt
perl gen_rands.pl 10000000 10000000 0 > nums10M.txt
for i in 10 1k 1M 10M
do
    sort -n nums$i.txt > sort$i.txt
done
