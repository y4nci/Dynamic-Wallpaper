#!/usr/bin/python3
import os
import time
import datetime
from pyowm.owm import OWM

owm = OWM("{KEY}")
manager = owm.weather_manager()
wait = 1
sunset_time = None
sunrise_time = None

while wait < 31:
    try:
        data = manager.weather_at_coords({LAT}, {LON})
        weather = data.weather

        beforeSunrise = weather.sunrise_time(timeformat='date') + datetime.timedelta(hours=1, minutes=30)
        afterSunrise = weather.sunrise_time(timeformat='date') + datetime.timedelta(hours=4, minutes=30)
        beforeSunset = weather.sunset_time(timeformat='date') + datetime.timedelta(hours=1, minutes=30)
        afterSunset = weather.sunset_time(timeformat='date') + datetime.timedelta(hours=4, minutes=30)

        file = open("{PWD}/.lastrecord", "w", encoding="utf-8")

        file.write("null null ")
        file.write(f"{beforeSunrise.year - 1900} {beforeSunrise.month - 1} {beforeSunrise.day} {beforeSunrise.hour} {beforeSunrise.hour} {beforeSunrise.minute} ")
        file.write(f"{afterSunrise.year - 1900} {afterSunrise.month - 1} {afterSunrise.day} {afterSunrise.hour} {afterSunrise.hour} {afterSunrise.minute} ")
        file.write(f"{beforeSunset.year - 1900} {beforeSunset.month - 1} {beforeSunset.day} {beforeSunset.hour} {beforeSunset.hour} {beforeSunset.minute} ")
        file.write(f"{afterSunset.year - 1900} {afterSunset.month - 1} {afterSunset.day} {afterSunset.hour} {afterSunset.hour} {afterSunset.minute} ")

        print("sunset and sunrise times are fetched successfully")
        file.close()
        break

    except:
        wait += 5
        time.sleep(wait * 60)

exit()
