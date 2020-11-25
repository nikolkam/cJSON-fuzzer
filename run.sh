rm -rf build/
mkdir build
cd build
cmake ..
make

./fuzzing ../inputs -print_final_stats=1 -jobs=8 -workers=8
