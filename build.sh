rm -rf build
mkdir build # 创建一个文件夹
cd build    # 进入这个文件夹
cmake -DCMAKE_BUILD_TYPE=Debug ..
   # 由于当前在build文件夹里，所以使用..来且切换到工程文件夹，并使用工程文件夹下的CMakeLists.txt配置编译Make
make -j4    # 使用Make调用GCC进行编译，使用4个线程进行编译
./Key_input