import os

KEY = input("Please enter your OpenWeatherMap API Key: ")
LAT = input("Please enter the latitude: ")
LON = input("Please enter longitude: ")

main = open("main.cpp", "r", encoding="utf-8")
main_content = main.read()
main.close()

mainsh = open("main.sh", "r", encoding="utf-8")
mainsh_content = mainsh.read()
mainsh.close()

desktop = open("DynamicWallpaper.desktop", "r", encoding="utf-8")
desktop_content = desktop.read()
desktop.close()

init = open("init.py", "r", encoding="utf-8")
init_content = init.read()
init.close()

print("Configuring 'init.py'...")
init_content = init_content.replace("{KEY}", KEY)
init_content = init_content.replace("{PWD}", os.getcwd())

print("Configuring 'DynamicWallpaper.desktop'...")
desktop_content = desktop_content.replace("{PWD}", os.getcwd())

print("Configuring 'main.cpp'...")
main_content = main_content.replace("{LAT}", LAT)
main_content = main_content.replace("{LON}", LON)
main_content = main_content.replace("{KEY}", KEY)
main_content = main_content.replace("{PWD}", os.getcwd())

print("Configuring 'main.sh'...")
mainsh_content = mainsh_content.replace("{PWD}", os.getcwd())

main = open("main.cpp", "w", encoding="utf-8")
main.write(main_content)
main.close()

init = open("init.py", "w", encoding="utf-8")
init.write(init_content)
init.close()

desktop = open("DynamicWallpaper.desktop", "w", encoding="utf-8")
desktop.write(desktop_content)
desktop.close()

mainsh = open("main.sh", "w", encoding="utf-8")
mainsh.write(mainsh_content)
mainsh.close()
