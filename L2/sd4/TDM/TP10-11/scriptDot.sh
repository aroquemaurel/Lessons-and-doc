#!/bin/bash
# -*- coding: UTF8 -*-
if [ ! $# -eq 1 ]
then
	echo "Erreur nombre arguments" >&2
	exit 1
fi
i=1
files=""
while [ -f "$1$i.dot" ]
do
	dot -Tpng "$1$i.dot" -o "$1$i.png"
	files="$files"" ""$1$i.png"
	i=`expr $i + 1`
done
i=`expr $i - 1`
size_temp=`identify "$1$i.png" | cut -d " " -f 3`
size_temp_x=`echo $size_temp | cut -d 'x' -f1`
size_temp_y=`echo $size_temp | cut -d 'x' -f2`

convert -loop 0 -extent ${size_temp_x}x${size_temp_y} -dispose Background -background white -delay 150 $files "animation.gif"
