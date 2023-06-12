#!/bin/bash

echo "Initialisation started..."
echo "Extracting the wallpapers..."

mkdir "Wallpapers"

cd assets

tar -xf clear.tar.xz
tar -xf cloudy.tar.xz
tar -xf misty.tar.xz
tar -xf partly.tar.xz
tar -xf rainy.tar.xz
tar -xf snowy.tar.xz

echo "Wallpapers are completely extracted"
echo "Removing compressed files..."

rm -rf clear.tar.xz
rm -rf cloudy.tar.xz
rm -rf misty.tar.xz
rm -rf partly.tar.xz
rm -rf rainy.tar.xz
rm -rf snowy.tar.xz

cd ..

echo "Installing modules..."

pip3 install pyowm

echo "Configuring files..."

python3 installer.py

echo "All files are configured"

echo "Calling 'make'..."

make

echo "Configuring permissions..."

chmod +x main
chmod +x main.sh

echo "Files are configured."

echo "Adding the program to ~/.config/autostart/..."

mkdir ~/.config/autostart/

mv DynamicWallpaper.desktop ~/.config/autostart/

echo "Program is added to autostart programs."

echo "Install finished."

python3 init.py
./main
