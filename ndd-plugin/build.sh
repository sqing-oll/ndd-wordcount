#!/bin/bash
set -e

echo "=== WordCount Plugin Build Script ==="
echo ""

# Check if Qt6 is installed
if [ ! -d "/usr/local/opt/qt" ]; then
    echo "❌ Qt6 not found. Please install with: brew install qt"
    echo ""
    echo "Checking for Qt5..."
    if [ -d "/usr/local/opt/qt@5" ]; then
        echo "Found Qt5 at /usr/local/opt/qt@5"
        QTPATH="/usr/local/opt/qt@5"
    else
        echo "Qt5 not found either. Please install Qt."
        exit 1
    fi
else
    QTPATH="/usr/local/opt/qt"
fi

echo "✅ Using Qt at: $QTPATH"
echo ""

# Get Qt frameworks path
QTDIR="$QTPATH/lib/cmake"
echo "✅ Qt cmake modules: $QTDIR"
echo ""

# Create build directory
rm -rf build
mkdir -p build
cd build

# Display system info
echo "=== System Information ==="
echo "macOS: $(sw_vers -productVersion)"
echo "Architecture: $(uname -m)"
echo "CPU Cores: $(sysctl -n hw.ncpu)"
echo ""

# Configure CMake
echo "=== Configuring CMake ==="
cmake -S .. -B . \
    -DCMAKE_PREFIX_PATH="$QTDIR" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_VERBOSE_MAKEFILE=ON

echo ""
echo "=== Building Plugin ==="
cmake --build . --config Release --verbose

echo ""
echo "=== Build Artifacts ==="
echo "Looking for .dylib files..."
find . -name "*.dylib" -type f -exec ls -lh {} \;

echo ""
echo "=== Checking Plugin File ==="
DYLIB_PATH=$(find . -name "libWordCount.dylib" -type f)
if [ -f "$DYLIB_PATH" ]; then
    FILE_SIZE=$(stat -f%z "$DYLIB_PATH")
    echo "Plugin size: $FILE_SIZE bytes"
    echo "File type:"
    file "$DYLIB_PATH"
    echo ""
    echo "Dynamic libraries linked:"
    otool -L "$DYLIB_PATH"
    echo ""
    echo "Symbols (first 20):"
    nm -g "$DYLIB_PATH" | head -20
else
    echo "❌ libWordCount.dylib not found!"
    exit 1
fi

echo ""
echo "=== Build Complete ==="
echo "Plugin location: $DYLIB_PATH"
