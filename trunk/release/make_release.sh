#!/bin/sh

source SFCvsEnv.sh

if [ -z "$3" ]
then
   echo Usage: $0 major minor patch
   exit 1
fi

release_tag=V$1_$2_$3
release_name=cccc-$1.$2.$3
release_number=$1.$2.$3

cvs rtag $release_tag .
cvs export -r $release_tag -d $release_name ccccdist
echo "#define CCCC_VERSION_STRING \"$release_number\"" > $release_name/cccc/cccc_ver.h
tar czvf $release_name.tar.gz $release_name

