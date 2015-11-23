#!/bin/bash
reset
cppcheck -j4 --enable=all --suppress=missingIncludeSystem -I inc .
