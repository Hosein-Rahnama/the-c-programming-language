#!/usr/bin/env bash

set -euo pipefail

DIR=$1
INPUT=${DIR}/input.txt

gcc ${DIR}/*.c -o ${DIR}/main

if [[ -e ${INPUT} ]]; then
    cat ${DIR}/input.txt | ${DIR}/main
else
    ${DIR}/main
fi
