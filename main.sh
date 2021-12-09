#!/bin/bash

cd '{PWD}'

python3 '{PWD}/init.p'

while :
do
	'{PWD}/main'
	sleep 60
done