<?php

FFMPEG=/usr/local/sbin/ffmpeg

COUNTER=0
str=""

foreach f 
for f in $(ls "$1"/*.MP4); do

        FIFO=fifo${COUNTER}
        rm -f $FIFO
        mkfifo $FIFO

        cmd=$cmd"$FFMPEG -i $f -c copy -bsf h264_mp4toannexb -f mpegts -y $FIFO 2> /dev/null & \ " 
        str=$str" -i $FIFO "

        COUNTER=$((COUNTER + 1)) 
done

echo $str


?>
