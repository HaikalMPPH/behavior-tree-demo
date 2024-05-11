NAME="main"
OUT_DIR="./bin/"

WARN="-Wall"

LIB_DIR="-L/usr/lib"
LIB="-lraylib"

HEAD="-Isrc"

SRC="src/*.cpp src/*/*.cpp src/*/*/*.cpp"

MODE="-g"

g++ -o $OUT_DIR$NAME $SRC $LIB_DIR $LIB $HEAD $WARN $MODE
