#!/bin/sh

if ! [ -d decNumber ]; then
    WGET=`which wget`
    if [ ! -f "$WGET" ]; then
        printf "\n*** getdn.sh: error: could not find wget. In order to run the decNumber tests,\n"
        printf "    download http://download.icu-project.org/files/decNumber/decNumber-icu-368.zip\n"
        printf "    and extract the archive into mpdecimal-x.y/tests/decNumber.\n\n"
        exit 1
    fi
    printf "\nGetting decNumber ... \n\n"
    $WGET -nv http://download.icu-project.org/files/decNumber/decNumber-icu-368.zip &&
    unzip -qq decNumber-icu-368.zip &&
    cd decNumber && patch < ../dnloop.patch
fi


