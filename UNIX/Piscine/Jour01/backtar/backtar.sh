#!/bin/bash
for directory in "$@"
do
	tar -czf "$directory"_$(date '+%d-%m-%Y-%H-%M').tar.gz $directory 

done
