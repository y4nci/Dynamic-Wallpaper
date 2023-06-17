#ifndef _wallpaper_H
#define _wallpaper_H

#include <string>
#include <ctime>

#define SEC_PER_MIN 60
#define SEC_PER_HOUR 3600
#define SEC_PER_DAY 86400
#define SEC_PER_MON 2592000

#define CLOUDY_THRESHOLD 803

class TIME{
public:
    TIME();
    int sec;
    int min;
    int hour;
    int day;
    int mon;
    int year;
    char timeData [32];

    bool operator<(const TIME &rhs) const;
    bool operator>(const TIME &rhs) const;
    void initData();
};

class WeatherException : public std::exception{
    [[nodiscard]] const char* what() const noexcept override{
        return "An error occurred while fetching the weather.";
    }
};

std::string getWeather(char* json);
std::string getTimeOfDay(TIME*, TIME*, TIME*, TIME*);
bool thereIsAChange(const char*, const char*, const char*, const char*);
void init();
void writeRecord(const std::string& weather, const std::string& time, TIME* beforeSunrise, TIME* afterSunrise, TIME* beforeSunset, TIME* afterSunset);
bool isNewDay(TIME * day);
int randint();

#endif
