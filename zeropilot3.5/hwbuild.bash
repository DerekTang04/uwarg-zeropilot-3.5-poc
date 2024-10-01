#!/usr/bin/env bash

set -e

script_dir=$( cd -- "$( dirname -- "${bash_source[0]}" )" &> /dev/null && pwd )
clean="false"
board="l552"

usage() {
    echo "Usage: $0 [-c]"
    exit 1
}

while getopts "b:c" opt; do
    case "${opt}" in
        b)
            if [[ "$OPTARG" == "l552" || "$OPTARG" == "l562" ]]; then
                board="$OPTARG"
            fi
            ;;
        c)
            clean="true"
            ;;
        *)
            usage
            ;;
    esac
done

if [[ -d "${script_dir}/build" ]]; then
    if [[ "$clean" == "true" ]]; then
        rm -rf "${script_dir}/build"
        mkdir "${script_dir}/build"
    fi
else
    mkdir "${script_dir}/build"
fi

cd "${script_dir}/build"
if [[ "$board" == "l552" ]]; then
    tc_file="../../nucleol552ze/nucleol552ze.cmake"
else
    # TODO: update to reflect l562 boardfile in real repo
    tc_file="../../nucleol552ze/nucleol552ze.cmake"
fi

if [[ ! -f "CMakeCache.txt" ]]; then
    echo "generating cmake..."
    echo "toolchain: $tc_file"
    cmake -G "Ninja" -DCMAKE_BUILD_TYPE="Debug" -DCMAKE_TOOLCHAIN_FILE="$tc_file" ..
fi

echo && echo "building..."
cmake --build .

echo && echo "copying headers..."
mkdir -p "${script_dir}/build/include"
find "${script_dir}/include" -name "*.hpp" -exec echo "{}" \; -exec cp {} "${script_dir}/build/include" \;
