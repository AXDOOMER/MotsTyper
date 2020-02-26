#!/usr/bin/env bash

# Unit testing

COLOR_RED='\033[0;31m'
COLOR_GREEN='\033[0;32m'
COLOR_YELLOW='\033[0;33m'
COLOR_YELLOW2='\033[0;93m'
COLOR_BLUE='\033[0;34m'
NO_COLOR='\033[0m'

logError() {
	echo -e "$COLOR_RED$1$NO_COLOR"
}

logSuccess() {
	echo -e "$COLOR_GREEN$1$NO_COLOR"
}

writeProg() {
	echo $2 >&"$1"
	echo -e "$COLOR_YELLOW$2$NO_COLOR"
}

readProg() {
	read output <&"$1"
	echo -e "$COLOR_YELLOW2$output$NO_COLOR"
}

coproc ./MotsTyper

# Test 1
readProg ${COPROC[0]}
retval1=$output

writeProg ${COPROC[1]} "$retval1"
# FIXME: phrases are random, if unlucky, the same phrase is selected.
readProg ${COPROC[0]}
retval2=$output

writeProg ${COPROC[1]} "$retval2"

if [ "$retval1" != "$retval2" ]; then
	logSuccess "Right answer test successful."
else
	logError "Right answer test failed."
fi

# Test 2
readProg ${COPROC[0]}
retval1=$output

writeProg ${COPROC[1]} "($retval1--"
writeProg ${COPROC[1]} "$retval1="

writeProg ${COPROC[1]} "$retval1"

readProg ${COPROC[0]}
retval2=$output
# FIXME: the test will not complete if there's a bug.
writeProg ${COPROC[1]} "$retval2"

if [ "$retval1" != "$retval2" ]; then
	logSuccess "Right answer test successful."
else
	logError "Right answer test failed."
fi

# Kill program
echo $(kill $COPROC_PID)





