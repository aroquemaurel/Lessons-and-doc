#!/bin/sh




if [ ! $# -eq 2 ]
then
	echo "Le nombre d'arguments est incorrect" >&2
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "$1 n'est pas un fichier" >&2
	exit 2
fi

if [ ! -r "$1" ]
then
	echo "Vous n'avez pas les droits de lecture sur $1" >&2
	exit 3
fi

if [ ! -w "$1" ]
then
	echo "Vous n'avez pas les droits d'écriture sur le fichier" >&2
	exit 4
fi

exiv2 -M"set Exif.Image.ImageDescription $2" "$1" 


