#!/bin/sh

cd include &&
    find core -type f |
    LANG=C sort |
    sed -e "s/\(.*\)/#include <\1>/"\
    > core.h
