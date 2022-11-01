#!/bin/bash

declare -i a
declare -i point=0
declare -i mouse1=0
declare -i mouse2=0

IFS=$'\n'

while [ true ]
do
	clear

	echo "______                     _    _ "
	echo "| ___ \                   | |  (_) "
	echo "| |_/ / _ __   __ _   ___ | |_  _   ___   ___ "
	echo "|  __/ |  __| / _  | / __|| __|| | / __| / _ \ "
	echo "| |    | |   | (_| || (__ | |_ | || (__ |  __/ "
	echo "\_|    |_|    \__,_| \___| \__||_| \___| \___| "
	echo " "
	echo "(_)       | |    (_) "
	echo " _  _ __  | |     _  _ __   _   _ __  __ "
	echo "| ||  _ \ | |    | ||  _ \ | | | |\ \/ / "
	echo "| || | | || |___ | || | | || |_| | >  < "
	echo "|_||_| |_|\_____/|_||_| |_| \__,_|/_/\_\ "
	echo " "

	echo "-NAME-----------------CMD--------------------PID-----STIME-----"	
	
	pid=(`ps -o pid -u ${name[$mouse1]} | grep -v "PID" `)
	declare -i length=${#pid[*]}-1
	time=(`ps -o time -u ${name[$mouse1]} | grep -v "STIME" `)
	time=`sed '1d' <<< "${time}"`
	cmd=(`ps -o cmd -u ${name[$mouse1]} | grep -v "CMD" `)
	ps=`ps aux`
	ps=`sed '1d' <<< "${ps}"`
	name=(`echo "$ps" | awk '{print $1}' | sort -u`)

	for (( n=0; n<20; n++ ))
	do
		a=${point}+${n}

		printf "|"
		if [ ${n} -eq ${mouse1} ];
		then
			printf '\e[41m'
		fi

		printf '%20s\e[0m|' ${name[$n]:0:20}
		if [ ${n} -eq ${mouse2} ];
		then
			printf '\e[42m'
		fi

		printf "  %-20s|%7s|%9s\e[0m|\n" ${cmd[$a]:0:20} ${pid[$a]:0:7} ${time[$a]:1:10}
	done

	echo "---------------------------------------------------------------"

	echo "If you want to exit, please type 'q' or 'Q'"

	if read -n 3 -t 3 key;
	then
		"${name[$mouse1]}" = `whoami`
	fi

	if [ "${key}" = 'q' -o "${key}" = 'Q' ];
	then
		exit
	
	elif [ "${key}" = $'\e[D' ];
	then
		if [ ${mouse2} -ge 0 ];
		then
			mouse2=-1
		fi
	
	elif [ "${key}" = $'\e[C' ];
	then
		if [ ${mouse2} -eq -1 ];
		then
			mouse2=0
		fi	

	elif [ "${key}" = $'\e[B' ];
	then
		if [ ${mouse2} -eq -1 ];
		then
			if [ ${mouse1} -lt $((${#name[@]} - 1)) -a ${mouse1} -lt 19 ];
			then
				mouse1=${mouse1}+1
				point=0
			fi
		else
			if [ ${mouse2} -lt $((${length} - 1)) -a ${mouse2} -lt 19 ];
			then
				mouse2=${mouse2}+1
			else
				if [ ${point} -lt $((${length} - 20)) ];
				then
					point=${point}+1
				fi
			fi
		fi

	elif [ "${key}" = $'\e[A' ];
	then
		if [ ${mouse2} -eq -1 ];
		then
			if [ ${mouse1} -gt 0 ];
			then
				mouse1=${mouse1}-1
				point=0
			fi
		else
			if [ ${mouse2} -gt 0 ];
			then
				mouse2=${mouse2}-1
			else
				if [ ${point} -gt 0 ];
				then
					point=${point}-1
				fi
			fi
		fi
	fi
done
