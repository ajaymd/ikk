#!/bin/sh

set -e

FFMPEG=/usr/local/sbin/ffmpeg

if [ $# -ne 3 ]
then
        echo "Usage: concatenate-mp4s.sh source_directory output_filename.mp4 unique-string"
        exit 1
fi

ts=$(date +%s)
FILE_LIST_NAME=./file_list_$3_$ts.txt
printf "file '%s'\n" "$1"/*.MP4 > $FILE_LIST_NAME

rm -f "$2"
mkdir -p "$2" #creates all intermediate directories to create the output file
rmdir "$2" #deletes the last directory created above, which is the directory by name of the output file which we don't need. Benefit being that we create all directories required in between

$FFMPEG -f concat -i $FILE_LIST_NAME -c copy "$2" -y
rm $FILE_LIST_NAME

exit 0
