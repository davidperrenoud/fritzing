#!/bin/bash
set -xe

if [ ! -d "/c/Qt" ]; then
    echo "Qt not found in cache. Downloading..."
    curl -L \
        http://download.qt-project.org/official_releases/online_installers/qt-unified-windows-x86-online.exe \
        --output "${TRAVIS_BUILD_DIR}/qt-installer.exe"

    echo "Running Qt installer in headless mode..."
    "${TRAVIS_BUILD_DIR}/qt-installer.exe" \
        --script "${TRAVIS_BUILD_DIR}/tools/qt_installer_noninteractive.qs"
fi

if [ ! -d "${TRAVIS_BUILD_DIR}/../libgit2" ]; then
    echo "LibGit2 not found in cache. Downloading..."
    curl -fsSL \
        https://github.com/libgit2/libgit2/archive/v0.28.1.zip \
        -o libgit2.zip
    7z x libgit2.zip
    mv libgit2-0.28.1 "${TRAVIS_BUILD_DIR}/../libgit2"

    echo "Building LibGit2..."
    mkdir "${TRAVIS_BUILD_DIR}/libgit2/build64"
    cd "${TRAVIS_BUILD_DIR}/libgit2/build64"
    cmake -G "Visual Studio 15 2017 Win64" "${TRAVIS_BUILD_DIR}"
    cmake --build . --config Release
    cd "${TRAVIS_BUILD_DIR}"
fi

# No point in putting Boost in cache since it would be downloading it from the cache server
# So there is no speed improvement.
echo "Fetching Boost..."
cd "${TRAVIS_BUILD_DIR}/src/lib"
curl -L \
    https://dl.bintray.com/boostorg/release/1.70.0/source/boost_1_70_0.tar.bz2 \
    | tar xj

