#! /usr/bin/env bash
# release.sh
# set the release version in the header file before building
#

set -e

PATH=/usr/bin:/bin:/usr/sbin:/sbin
export LC_ALL=C

DATE=$(date +%Y%m%d-%H%M%S)
UNAME_N=$(uname -n)

if [[ $1 == "--version" ]]; then
	RELEASE_VERSION="${2}"
elif [[ -n $VERSION ]]; then
	RELEASE_VERSION="${VERSION}"
else
	RELEASE_VERSION=$(git describe --tags | cut -d- -f1)
fi

RELEASE_VERSION_GIT=$(git describe --tags --dirty --always)

echo "// This version built on ${UNAME_N} at ${DATE}" > cccc/cccc_ver.h
echo "#define CCCC_VERSION ${RELEASE_VERSION}" >> cccc/cccc_ver.h
echo "#define CCCC_VERSION_STRING \"${RELEASE_VERSION}\"" >> cccc/cccc_ver.h
echo "#define CCCC_VERSION_DEV \"${RELEASE_VERSION_GIT}\"" >> cccc/cccc_ver.h
