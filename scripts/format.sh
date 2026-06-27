#!/usr/bin/env bash

set -euo pipefail

ROOT=$(realpath $(dirname ${0})/..)

echo "Formatting ..."
if [[ ${1} == --all ]]; then
    find ${ROOT} -name "*.c" -o -name "*.h" | xargs clang-format -i
else
    DIR=${1}
    find ${DIR} -name "*.c" -o -name "*.h" | xargs clang-format -i
fi
echo "Fomatting is done."
