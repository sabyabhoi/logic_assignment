#!/bin/bash

get_time() {
	time ( for (( i = 0; i < 1000; i++ )); do
		../bin/Release/proParser < ./in/150k.in > /dev/null
	done )
}

for (( i = 0; i < 10; i++ )); do
	get_time
done
