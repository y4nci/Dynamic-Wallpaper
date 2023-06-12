# Dynamic-Wallpaper
A program which sets the background image according to the local time and weather.

This program is aimed for Linux distributions, mainly the ones that utilise GNOME Shell -like Ubuntu. The weather is fetched by using API calls to OpenWeatherMap and in order to use OpenWeatherMap's API, the user needs to get an API key from OWM.

Required packages:
  - [RapidJSON](https://github.com/Tencent/rapidjson)
  - make
  - g++

To install, simply run

```
git clone https://github.com/y4nci/Dynamic-Wallpaper
cd Dynamic-Wallpaper/bin
chmod +x install.sh
./install.sh
```

