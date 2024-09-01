#!/usr/bin/env bash
set -e

script_dir=$( cd -- "$( dirname -- "${bash_source[0]}" )" &> /dev/null && pwd )

clean=false

usage() {
    echo "Usage: $0 [-c]"
    exit 1
}

while getopts "c" opt; do
    case "${opt}" in
        c)
            clean=true
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

if [[ ! -f "CMakeCache.txt" ]]; then
    echo "generating cmake..."
    cmake -G "Ninja" \
        -DCMAKE_BUILD_TYPE="Debug" \
        -DCMAKE_TOOLCHAIN_FILE="../../nucleol552ze/nucleol552ze.cmake" \
        -DCMAKE_INSTALL_PREFIX="$(pwd)" \
        ..
fi

echo && echo "building..."
cmake --build .

echo && echo "installing..."
cmake --install .
