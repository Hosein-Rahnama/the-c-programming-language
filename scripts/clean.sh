#!/usr/bin/env bash

set -euo pipefail

ROOT=$(realpath $(dirname ${0})/..)

echo "Cleaning ..."
if [[ ${1} == --all ]]; then
    find ${ROOT} -type f -name main -executable -delete
else
    DIR=${1}
    find ${DIR} -type f -name main -executable -delete
fi
echo "Cleaning is done."
