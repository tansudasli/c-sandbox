#on linux/Mac/windows
#under ansi-c folder
cmake . -B out   #creates cmake caches
make -C out      #builds

#on IDE - clion
#cmake --build cmake-build-debug --target all -- -j 30