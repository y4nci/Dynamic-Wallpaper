#include "wallpaper.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string input, jsonData, lastWeather, lastTime, currentWeather, currentTime;
    char command [256];
    TIME *beforeSunrise = new TIME (), *afterSunrise = new TIME (), *beforeSunset = new TIME (), *afterSunset = new TIME ();
    ifstream file ("{PWD}/.lastrecord");

    getline(file, input);
    file.close();

    sscanf(input.data(), "%s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
           lastWeather.data(), lastTime.data(), &beforeSunrise->year, &beforeSunrise->mon, &beforeSunrise->day, &beforeSunrise->hour,
           &beforeSunrise->min, &beforeSunrise->sec, &afterSunrise->year, &afterSunrise->mon, &afterSunrise->day,
           &afterSunrise->hour, &afterSunrise->min, &afterSunrise->sec, &beforeSunset->year, &beforeSunset->mon,
           &beforeSunset->day, &beforeSunset->hour, &beforeSunset->min, &beforeSunset->sec, &afterSunset->year,
           &afterSunset->mon, &afterSunset->day, &afterSunset->hour, &afterSunset->min, &afterSunset->sec);

    if (isNewDay(afterSunrise)) init();
    currentTime = getTimeOfDay(beforeSunrise, afterSunrise, beforeSunset, afterSunset);

    try {
        system("curl 'https://api.openweathermap.org/data/2.5/weather?lat={LAT}&lon={LON}&appid={KEY}' > '{PWD}'/.tmp");
        ifstream jsonFile ("{PWD}/.tmp");
        getline(jsonFile, jsonData);
        jsonFile.close();
        system("rm -rf '{PWD}'/.tmp");
        if (jsonData.empty() || jsonData[0] != '{') {
            throw WeatherException();
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
        delete afterSunrise;
        delete afterSunset;
        delete beforeSunset;
        delete beforeSunrise;
        return 0;
    }

    char* json = const_cast<char*>(jsonData.c_str());

    currentWeather = getWeather(json);

    if (thereIsAChange(lastWeather.data(), lastTime.data(), currentWeather.data(), currentTime.data())){
        sprintf(command, "gsettings set org.gnome.desktop.background picture-uri 'file:///{PWD}/Wallpapers/%s%s/%d.jpg'",
                currentWeather.data(), currentTime.data(), randint());
        system(command);
        writeRecord(currentWeather, currentTime, beforeSunrise, afterSunrise, beforeSunset ,afterSunset);
    }

    delete afterSunrise;
    delete afterSunset;
    delete beforeSunset;
    delete beforeSunrise;
    return 0;
}

