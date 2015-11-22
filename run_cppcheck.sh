#!/bin/bash
reset
cppcheck --enable=all --suppress=missingIncludeSystem -I inc .
