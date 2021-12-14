#!/bin/bash

echo "Initialisation started..."
echo "Extracting the wallpapers..."

mkdir "Wallpapers"

cd Resources

tar -xf clear.tar.xz -C ../Wallpapers
tar -xf cloudy.tar.xz -C ../Wallpapers
tar -xf misty.tar.xz -C ../Wallpapers
tar -xf partly.tar.xz -C ../Wallpapers
tar -xf rainy.tar.xz -C ../Wallpapers
tar -xf snowy.tar.xz -C ../Wallpapers

echo "Wallpapers are completely extracted"
echo "Removing compressed files..."

rm -rf clear.tar.xz
rm -rf cloudy.tar.xz
rm -rf misty.tar.xz
rm -rf partly.tar.xz
rm -rf rainy.tar.xz
rm -rf snowy.tar.xz

cd ..
rm -rf Resources

echo "Configuring files..."

python3 installer.py

echo "All files are configured"

echo "Calling 'make'..."

make

chmod +x main

echo "Adding the program to ~/.config/autostart/..."

mv DynamicWallpaper.desktop ~/.config/autostart/

echo "Program is added to autostart programs."

echo "Install finished."
