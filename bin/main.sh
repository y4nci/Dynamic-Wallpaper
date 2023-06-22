#!/bin/bash

cd '{PWD}'

python3 '{PWD}/init.py'

while :
do
	'{PWD}/../../bin/dynamic-wallpaper'
	sleep 60
done
