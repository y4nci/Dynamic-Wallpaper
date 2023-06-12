#include "wallpaper.h"
#include "rapidjson/document.h"
#include <iostream>
#include <cctype>
#include <random>

using namespace rapidjson;
using u32 = uint_least32_t;
using engine = std::mt19937;

TIME::TIME() {
    sec = min = hour = day = mon = year = 0;
}

bool TIME::operator<(const TIME &rhs) const {
    if (rhs.year > year) return true;
    if (rhs.year < year) return false;

    int val, rhsVal;

    val = sec + 100* min + 10000 * hour + 1000000* day + 100000000* mon;
    rhsVal = rhs.sec + 100* rhs.min + 10000 * rhs.hour + 1000000* rhs.day + 100000000* rhs.mon;

    if (val < rhsVal) return true;
    return false;
}

bool TIME::operator>(const TIME &rhs) const {
    return !(*this < rhs);
}

void TIME::initData(){
    sprintf(this->timeData, "%d %d %d %d %d %d", this->year, this->mon, this->day, this->hour, this->min, this->sec);
}

std::string getWeather(char* json){
    /*
    char* json = new char [1024];
    std::cin >> json;
     */
    std::string weather;
    int id;

    Document document;
    document.Parse(json);
    Value& w = document["weather"][0]["main"];
    Value& i = document["weather"][0]["id"];

    id = i.GetInt();
    weather = w.GetString();

    if (weather == "Clear") return "clear";
    else if (weather == "Drizzle" || weather == "Rain" || weather == "Thunderstorm") return "rainy";
    else if (weather == "Snow") return "snowy";
    else if (weather == "Mist" || weather == "Fog") return "misty";
    else if (weather == "Clouds"){
        if (id < 803) return "partly";
        return "cloudy";
    }
    return "";
}

std::string getTimeOfDay(TIME* beforeSunrise, TIME* afterSunrise, TIME* beforeSunset, TIME* afterSunset){
    time_t timeData = time(nullptr);
    tm* time = localtime(&timeData);
    TIME* now = new TIME;

    now->day = time->tm_mday;
    now->hour = time->tm_hour;
    now->min = time->tm_min;
    now->sec = time->tm_sec;
    now->mon = time->tm_mon;
    now->year = time->tm_year;

    if (*now < *beforeSunrise || *now > *afterSunset) return "night";
    else if (*now < *afterSunrise) return "morning";
    else if (*now < *beforeSunset) return "day";
    return "evening";
}

bool thereIsAChange(const char* lastWeather, const char* lastTime, const char* currentWeather, const char* currentTime){
    if (strcmp(lastWeather, currentWeather) || strcmp(lastTime, currentTime)) return true;
    return false;
}

void init(){
    system("python3 {PWD}/init.py");
}

void writeRecord(const std::string& weather, const std::string& time, TIME* beforeSunrise, TIME* afterSunrise, TIME* beforeSunset, TIME* afterSunset){
    char command [256];
    sprintf(command, "echo ");
    beforeSunrise->initData();
    beforeSunset->initData();
    afterSunrise->initData();
    afterSunset->initData();
    sprintf(command, "echo %s %s %s %s %s %s > {PWD}/../temp/lastRecord", weather.data(), time.data(), beforeSunrise->timeData, afterSunrise->timeData, beforeSunset->timeData, afterSunset->timeData);
    system(command);
}

bool isNewDay(TIME * day){
    time_t timeData = time(nullptr);
    tm* time = localtime(&timeData);

    if (time->tm_mday != day->day) return true;
    return false;
}

int randint(){
  std::random_device os_seed;
  const u32 seed = os_seed();

  engine generator(seed);
  std::uniform_int_distribution<u32> distribute(1, 2);

  return distribute(generator);
}

