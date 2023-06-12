#!/bin/bash

echo "Initialisation started..."
echo "Extracting the wallpapers..."

cd ../assets

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

echo "Configuring files..."

mkdir temp

cd src/scripts
python3 config.py
cd ../..

echo "All files are configured"

echo "Satisfying dependencies..."

pip3 install pyowm

mkdir modules
cd modules
git clone --filter=blob:none --sparse https://github.com/Tencent/rapidjson/
cd rapidjson
git sparse-checkout add include/rapidjson
cd ../..

echo "Dependencies are satisfied."

echo "Calling 'make'..."

make

echo "Configuring permissions..."

chmod +x main
chmod +x bin/main.sh

echo "Files are configured."

echo "Adding the program to ~/.config/autostart/..."

mkdir ~/.config/autostart/

mv DynamicWallpaper.desktop ~/.config/autostart/

echo "Program is added to autostart programs."

echo "Install finished."

python3 src/scripts/init.py
./main
