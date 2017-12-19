#!/bin/bash
cat passwd | awk -F: '$3 % 42 == 0' | cut -f1 -n -d: | sort
