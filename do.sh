#!/usr/bin/env bash

set -euo pipefail

ROOT=$(dirname $(realpath $0))
SCRIPTS=${ROOT}/scripts

COMMAND=${1:-}

if [[ -z ${COMMAND} ]]; then
    echo "No command is provided. See README.md for proper usage." >&2
    exit 1
fi

SCRIPT=${SCRIPTS}/${COMMAND}.sh

if [[ ! -x ${SCRIPT} ]]; then
    echo "The given command is not valid." >&2
    exit 1
fi

if [[ (${COMMAND} == clean || ${COMMAND} == format) && ${2} == --all ]]; then
    exec ${SCRIPT} --all
fi

PROGRAM=${2:-}
VERSION=${3:-}

if [[ -z ${PROGRAM} ]]; then
    echo "No program is specified. See README.md for proper usage." >&2
    exit 1
fi

if [[ -n ${VERSION} ]]; then
    DIR=$(find ${ROOT} -type d -path */${PROGRAM}/${VERSION})
else
    DIR=$(find ${ROOT} -type d -name ${PROGRAM})
fi

if [[ -z ${DIR} ]]; then
    echo "Program was not found." >&2
    exit 1
fi

exec ${SCRIPT} ${DIR}
