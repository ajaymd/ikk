#!/bin/sh

set -e

if [ $# -ne 2 ]
then
        echo "Usage: concatenate-mp4s.sh source_directory output_filename.mp4"
        exit 1
fi

FFMPEG=/usr/local/sbin/ffmpeg
COUNTER=0
str="concat:"
cmd=""

for f in $(ls "$1"/*.MP4); do

	ts=$(date +%s)
        FIFO=/tmp/fifo${COUNTER}_${ts} #ts uniquifies the fifos just in case multiple of these are running

        rm -f $FIFO
        mkfifo $FIFO

        # Writing to FIFO happens in the background
        $FFMPEG -i $f -c copy -bsf h264_mp4toannexb -f mpegts -y $FIFO 2>/dev/null &
	sleep 1

        # This is required in the reader command that follows
        str="${str}${FIFO}|"

        COUNTER=$((COUNTER + 1))
done

str=${str%?} #remove last character which is a pipe

rm -f "$2"
mkdir -p "$2" #creates all intermediate directories to create the output file
rmdir "$2" #deletes the last directory created above, which is the directory by name of the output file which we don't need. Benefit being that we create all directories required in between

# Reader command
$FFMPEG -f mpegts -i "$str" -c copy -absf aac_adtstoasc "$2" -y

# Remove all FIFOs to not cause clutter. Each can hold a large amount of video data if lying around
for c in `seq 1 $COUNTER`; do
        rm -f "/tmp/fifo${c}_${ts}"
done

exit 0
