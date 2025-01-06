#!/bin/bash

filesdir=${1}
searchstr=${2}
if [ "$#" -ne 2 ]; then
    echo "Error: This script requires two arguments: <directory> <search string>"
    exit 1
fi
if [ ! -d "$filesdir" ]; then
echo "$filesdir Dircetory Not Found"
exit 1
fi
file_count=$(find ${filesdir} -type f | wc -l)
match_count=$(grep -r ${searchstr} ${filesdir}|wc -l)

echo "The number of files are ${file_count} and the number of matching lines are ${match_count}"

