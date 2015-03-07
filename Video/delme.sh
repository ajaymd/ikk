#!/bin/bash

set -e

rm -f fifo0
rm -f fifo1
mkfifo fifo0 fifo1

#/usr/local/sbin/ffmpeg -i /Volumes/CHRYSLER/VIDEO/100VIDEO/HDV_0448.MP4 -c copy -bsf h264_mp4toannexb -f mpegts -y fifo0 & \
#/usr/local/sbin/ffmpeg -i /Volumes/CHRYSLER/VIDEO/100VIDEO/HDV_0449.MP4 -c copy -bsf h264_mp4toannexb -f mpegts -y fifo1 & \
#/usr/local/sbin/ffmpeg -f mpegts -i "concat:fifo0|fifo1" -c copy -absf aac_adtstoasc ~/Desktop/ffmpegoutput.mp4

/usr/local/sbin/ffmpeg -i /Volumes/CHRYSLER/VIDEO/100VIDEO/HDV_0448.MP4 -c copy -bsf h264_mp4toannexb -f mpegts -y fifo0 &
/usr/local/sbin/ffmpeg -i /Volumes/CHRYSLER/VIDEO/100VIDEO/HDV_0449.MP4 -c copy -bsf h264_mp4toannexb -f mpegts -y fifo1 &
#/usr/local/sbin/ffmpeg -f mpegts -i "concat:fifo0|fifo1" -c copy -absf aac_adtstoasc ~/Desktop/ffmpegoutput.mp4 -y

