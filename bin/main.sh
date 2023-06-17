#!/bin/bash

cd '{PWD}'

python3 '{PWD}/src/scripts/init.py'

while :
do
	'{PWD}/bin/dynamic-wallpaper'
	sleep 60
done
