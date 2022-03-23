#!/bin/bash

cd '{PWD}'

python3 '{PWD}/init.py'

while :
do
	'{PWD}/main'
	sleep 60
done
