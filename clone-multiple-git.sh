#!/bin/sh
file=git.list #put multiple git url's in this file and it will clone all the repo's for you. keep file name git.list
while read line
do
repo=$( echo "$line" |cut -d ' '  -f 1 )

  echo "clonning $element"
  git clone $repo
done < ${file} 
