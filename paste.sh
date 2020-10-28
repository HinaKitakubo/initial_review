#!/bin/bash

paste -d " " vmax_10000.dat v_10000.dat | awk '{print $1, $2, $3, $4, $5, $9, $10, $11, $6, $12, $7}' > ini_10000.dat
