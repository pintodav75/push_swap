#!/usr/bin/bash

ARGS=`seq -250 249 | shuf`;
./push_swap $ARGS | ./checker_linux $ARGS

