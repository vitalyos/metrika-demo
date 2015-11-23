#!/bin/bash
reset
cppcheck --xml -j4 --enable=all --suppress=missingIncludeSystem -I inc .
