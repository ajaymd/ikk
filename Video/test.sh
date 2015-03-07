#!/bin/bash

set -e

FFMPEG=/usr/local/sbin/ffmpeg

COUNTER=0
str="concat:"
cmd=""
ts=$(date +%s)

for f in $(ls "$1"/*.MP4); do

	FIFO=/tmp/fifo${COUNTER}_${ts} #ts uniquifies the fifos just in case multiple of these are running

	rm -f $FIFO
	mkfifo $FIFO

	# Writing to FIFO happens in the background
	$FFMPEG -i $f -c copy -bsf h264_mp4toannexb -f mpegts -y $FIFO 2>/dev/null &

	# This is required in the reader command that follows
	str="${str}${FIFO}|"

	COUNTER=$((COUNTER + 1))
done

str=${str%?} #remove last character which is a pipe

# Reader command
$FFMPEG -f mpegts -i "$str" -c copy -absf aac_adtstoasc "$2" -y

# Remove all FIFOs to not cause clutter. Each can hold a large amount of video data if lying around
for c in `seq 1 $COUNTER`; do
	rm -f "/tmp/fifo${c}_${ts}"
done

exit 0
