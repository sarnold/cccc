#!/bin/sh

source SFCvsEnv.sh

if [ -z "$2" ]
then
   echo Usage: $0 major minor
   exit 1
fi

release_tag=V$1_$2
release_name=cccc-$1.$2
release_number=$1.$2

cvs rtag $release_tag .
cvs -z9 export -r $release_tag -d $release_name ccccdist
echo "#define CCCC_VERSION $release_number" > $release_name/cccc/cccc_ver.h
tar czvf $release_name.tar.gz $release_name
su -c cp $release_name.tar.gz /mnt/win_c

