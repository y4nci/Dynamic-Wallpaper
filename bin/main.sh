#!/bin/bash

cd '{PWD}'

python3 '{PWD}/src/scripts/init.py'

while :
do
	'{PWD}/main'
	sleep 60
done
