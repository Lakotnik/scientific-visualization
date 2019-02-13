#!/bin/bash

echo "Installing GLUT"
sudo apt-get install freeglut3-dev -y
echo "Installing glew"
sudo apt-get install libglew-dev -y

echo "Requirements met, proceeding with install"
cd fftw-2.1.5/sourceAndDoc

echo "Configuring and making FFTW"
./configure
make

echo "Copying some files"
cp fftw/.libs/libfftw.a ../lib
cp rfftw/.libs/librfftw.a ../lib

cd ../..
echo "Making Smoke"
make
echo "Done"
