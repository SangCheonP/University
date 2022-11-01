#!/bin/bash

declare -i point=0
declare -i mouse1=0
declare -i mouse2=0

IFS=$'\n'

while [ true ]
do
	clear

	echo '______                     _    _             '
	echo '| ___ \                   | |  (_)            '
	echo '| |_/ / _ __   __ _   ___ | |_  _   ___   ___ '
	echo '|  __/ |  __| / _  | / __|| __|| | / __| / _ \'
	echo '| |    | |   | (_| || (__ | |_ | || (__ |  __/'
	echo '\_|    |_|    \__,_| \___| \__||_| \___| \___|'
	echo '                                              '
	echo '(_)       | |    (_)                          '
	echo ' _  _ __  | |     _  _ __   _   _ __  __      '
	echo '| ||  _ \ | |    | ||  _ \ | | | |\ \/ /      '
	echo '| || | | || |___ | || | | || |_| | >  <       '
	echo '|_||_| |_|\_____/|_||_| |_| \__,_|/_/\_\      '
	echo '                                              '

	echo '-NAME-----------------CMD------------------PID-----STIME----'

	process=`ps aux`
	process=`sed '1d' <<< "$process"`
	name=(`echo "$process" | awk '{print $1}' | sort -${NAME_SORT}u`)

	for (( n=0; n<20; n++ ))
	do
		printf '|'

		if [ $n -eq $mouse1 ];
		then
			printf '\e[41m'
		fi

		printf '%20s\e[0m|' ${name[$n]:0:20}

		if [ $n -eq $mouse2 ];
		then
			printf '\e[42m'
		fi

		printf '%-20s|%7s|%8s\e[0m|\n'
	done

	echo '------------------------------------------------------------'
	
	echo "If you want to exit, please type 'q' or 'Q'"

	if read -n 3 -t 3 key;
	then
		"${name[$mouse1]}" = `whoami`
	fi

	if [ "$key" = 'Q' -o "$key" = 'q' ];
	then
		exit

	elif [ "$key" = $'\e[D' ];
	then
		mouse2=-1

	elif [ "$key" = $'\e[C' ];
	then
		mouse2=0

	elif [ "$key" = $'\e[A' ];
	then
		if [ $mouse2 -eq -1 ];
		then
			if [ $mouse1 -gt 0 ];
			then
				mouse1=$mouse1-1
				point=0
			fi
		fi

	elif [ "$key" = $'\e[B' ];
	then
		if [ $mouse1 -lt $((${#name[@]} - 1)) -a $mouse1 -lt 19 ];
			then
				mouse1=$mouse1+1
				point=0
			fi
	fi
done
