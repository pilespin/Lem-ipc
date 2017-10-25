#!/bin/sh

team=$1
nb_in_team=$2

a=0
while [ $a -lt $nb_in_team ]
do
	./lemipc $team &
	((a++))
done
