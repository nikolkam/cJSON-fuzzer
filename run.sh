rm -rf build/
mkdir build
cd build
cmake ..
make

./fuzz ../input -only_ascii=1 -print_final_stats=1
