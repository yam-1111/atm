# atm (source code)

Authors : Aaron Gabriel Silerio & Angelo Rodelas

### prerequisities & dependencies
* gcc compiler
* Cmake
* curses (linux)
## How to run?
clone the repo
```
git clone https://github.com/yam-1111/atm
```
### Windows
#### On your VSCODE Powershell

create a new folder name build
```
mkdir build
```
change directory to `build` folder
```
cd build
```
generate build files using CMake installed on you system
```
cmake ..
```
run the command below to have executable program
```
make
```
run the program, if the `exe` file located in `build` folder
```
./build/atm2
```
#### via vscode extension
you can install [cmake tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) on VSCODE 

click the build button on the status bar in VSCODE

select the `build with gcc 8.x.x`
run the program, if the `exe` file located in `build` folder with:
```
./build/atm2
```

### Linux (UBUNTU / DEBIAN)
install the `curses.h` library
```
sudo apt install libncurses5-dev -y 
```
install the cmake, if you dont have.
```
sudo apt install cmake -y
```
navigate to the directory and build it with cmake
```
cd atm
cmake .
make
```
run the program
```
./atm2
```


