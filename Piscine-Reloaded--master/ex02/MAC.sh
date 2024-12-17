#!/bin/sh
ifconfig | grep -E "^\tether" | cut -d " " -f 2

# grep -E "^\tether"    --> filters lines that have *tab* "ethter"
# cut -d " "    <--> cut line on " " delimeter
# -f 2   <-->  give back the second field
# 