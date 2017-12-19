#!/bin/bash
groups $MY_USER | cut -f3 -n -d' ' | sed -e 's/ /,/g'
