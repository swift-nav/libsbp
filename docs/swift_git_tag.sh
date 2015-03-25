#!/bin/bash
tag=`git describe --dirty`
if [ -z "$tag" ]
then
  tag=`git log --pretty=format:'%h' -n 1`
fi
echo '\gdef\gitdescribe{'$tag'}' > gitdescribe.tex
