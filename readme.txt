Student name: Yong Piao
Project: CS4732 Project 0
Platform: Windows


How to build:
1. Install cmake from http://www.cmake.org/download/, choose "cmake-3.1.0-rc1-win32-x86.exe".
2. Run cmake-gui.exe.
3. Find CMakeLists.txt in the project root folder, and drag it onto the cmake window.
   It should now have filled out the "where is the source code:" and "where to build the binaries:"
   boxes for you.
   
   One more thing before building, since the visual studio solution will likely
   contain lots of files, it is better to build the binaries in a seperate folder inside the project
   root directory.
   An example would be:
   Where is the source code:    D:/Github/OpenGLTestbed
   Where to build the binaries: D:/Github/OpenGLTestbed/Build
   
4. Click generate and locate the solution inside the build folder.
5. Build and run, the executable should be located in the bin_debug folder.

How to use the program:
WASD or arrow keys to move the camera, also Q and E to elevate and lower the camera.
Click and drag the left mouse button to change the view angle.
