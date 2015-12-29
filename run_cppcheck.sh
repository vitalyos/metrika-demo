#!/bin/bash
reset
cppcheck -j4 --enable=all --language=c++ --suppress=missingIncludeSystem -I inc .
