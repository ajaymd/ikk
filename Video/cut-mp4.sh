#!/bin/bash

set -e

FFMPEG=/usr/local/sbin/ffmpeg
FFPROBE=/usr/local/sbin/ffprobe

if [ $# -lt 4 ]
then
        echo "Usage: cut-mp4.sh input_filename.mp4 output_filename.mp4 start_hh:mm:ss end_hh:mm:ss"
        exit 1
fi

if [ "$3" == "start" ]
then
	start_hh="00:00:00"
else
	start_hh="$3"
fi


if [ "$4" == "end" ]
then
	end=$($FFPROBE "$1" -show_format 2>&1 | grep Duration | tr -s " " " " | cut -f 3 -d ' ' | cut -f 1 -d '.')
	end_hh="$end"
else
	end_hh="$4"
fi

rm -f "$2"
mkdir -p "$2" #creates all intermediate directories to create the output file
rmdir "$2" #deletes the last directory created above, which is the directory by name of the output file which we don't need. Benefit being that we create all directories required in between

$FFMPEG -ss $start_hh -i "$1" -to $end_hh -c copy "$2" -y

exit 0
