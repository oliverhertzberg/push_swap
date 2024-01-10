#!/bin/bash

integers=()

while [ ${#integers[@]} -lt 500 ]; do

	random_int=$((($RANDOM * 32768 + $RANDOM) % 4294967296 - 2147483648))

	if [[ ! " ${integers[@]} " =~ " $random_int " ]]; then
		integers+=($random_int)
	fi
done

ARG=${integers[@]}
#./bin/push_swap $ARG | ./checker_Mac $ARG

./bin/push_swap $ARG | wc -l
