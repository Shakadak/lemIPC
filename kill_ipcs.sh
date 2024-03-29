#!/bin/bash

ME=`whoami`

IPCS_S=`ipcs -s | egrep "[0-9]+ [0-9]+" | grep $ME | sed 's/  */\ /g' | cut -f2 -d' ' `
IPCS_M=`ipcs -m | egrep "[0-9]+ [0-9]+" | grep $ME | sed 's/  */\ /g' | cut -d ' ' -f 2`
IPCS_Q=`ipcs -q | egrep "[0-9]+ [0-9]+" | grep $ME | sed 's/  */\ /g' | cut -d ' ' -f 2`


for id in $IPCS_M; do
	ipcrm -m $id;
done

for id in $IPCS_S; do
	ipcrm -s $id;
done

for id in $IPCS_Q; do
	ipcrm -q $id;
done
