#!/usr/bin/bash
g++ -Wall -Ofast -c cpp/main.cpp
for alg in stdsort quicksort selection insertion stablesort modifquicksort
do
    echo Algorithm: $alg
    g++ -Wall -Ofast -c cpp/$alg.cpp -o o/$alg.o
    g++ -Wall -Ofast -o $alg main.o o/$alg.o
    for t in 1 2 3
    do
        rm data/$alg$t.data
        for i in $(seq 1 100)
        do
            n=${i}000
            echo $alg $n $t
            timeout 10m ./$alg $n $t >> data/$alg$t.data
            ret=$?
            if [[ $ret -gt 120 ]]
            then
                echo TIMEOUT OR CORE DUMP ON $alg $t
                break
            fi
        done
    done
done

echo Creating plots
sage plot.sage