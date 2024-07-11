#!/usr/bin/bash

ARGS=`seq -249 250 | shuf`;
./push_swap $ARGS | ./checker_linux $ARGS

