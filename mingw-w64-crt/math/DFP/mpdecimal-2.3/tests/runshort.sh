#!/bin/sh


./gettests.sh || exit 1

echo ""
printf "Running official tests ... "

if ./runtest official.decTest
then
    printf "PASS\n"
fi

printf "Running additional tests ... "

if ./runtest additional.decTest
then
    printf "PASS\n"
fi
echo ""


