#!/usr/bin/env bash

lb=1

for i in $(seq 1 10); do
    for s in $(seq 1 100); do
        n=$(python -c "import random; print random.randint($lb, $(expr $lb '*' 10))")
        ans_sol=$(echo $i | java Main)
        ans_ref=$(echo $i | python test.py)
        if [ "$ans_sol" -ne "$ans_ref" ]
        then
            echo "Oops... $i"
        fi
    done
    lb=$(expr $lb '*' 10)
done

echo "Done"
