#on linux/Mac/windows
#under c-sandbox folder
cmake . -B out   #creates cmake caches
make -C out      #builds

#on IDE - clion
#load CMakeLists.txt file in IDE. So that you can run manually.
#If error occurs, delete cmake-build-debug folder...
#cmake --build cmake-build-debug --target all -- -j 30  ????not working some parameters anymore.