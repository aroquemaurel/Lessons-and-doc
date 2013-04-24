#!/bin/bash
# -*- coding: UTF8 -*-
if [ ! $# -eq 1 ]
then
	echo "Erreur nombre arguments" >&2
	exit 1
fi
i=1
files=""
dir=`dirname $1`
while [ -f "$1$i.dot" ]
do
	dot -Tpng "$1$i.dot" -o "$1$i.png"
	files="$files"" ""$1$i.png"
	i=`expr $i + 1`
done
i=`expr $i - 1`
taille=`identify "$1$i.png" | cut -d " " -f 3`
x=`echo $taille|cut -d 'x' -f1`
y=`echo $taille|cut -d 'x' -f2`

x=`expr $x + 150`
y=`expr $y + 700`

convert -loop 0 -extent 1000x1000 -delay 150 -dispose Background -background white $files "$dir/animation.gif"
