import requests
import json
def city():
    city=input("Enter the city: ")
    print("\n")
    url="http://api.openweathermap.org/data/2.5/weather?q={}&appid=c30847ca8fcaa7fc60fc83a2032fad55&units=metric".format(city)
    response=requests.get(url)
    data=response.json()
    show_data(data)
def location():
    response=requests.get("https://ipinfo.io/")
    data=response.json()
    location=data["loc"].split(",")
    name=data["city"]
    print("CURRENT LOCATION :{}\n".format(name))
    latitude=location[0]
    longitude=location[1]
    url="http://api.openweathermap.org/data/2.5/weather?lat={}&lon={}&appid=c30847ca8fcaa7fc60fc83a2032fad55&units=metric".format(latitude,longitude)
    response=requests.get(url)
    data=response.json()
    show_data(data)
def show_data(data):
    temp=data["main"]["temp"]
    pres=data["main"]["pressure"]
    humidity=data["main"]["humidity"]
    speed=data["wind"]["speed"]
    lat=data["coord"]["lat"]
    long=data["coord"]["lon"]
    description=data["weather"][0]["description"]
    print("TEMPERATURE:{} degree celcius\n".format(temp))
    print("PRESSURE :{} hPa\n".format(pres))
    print("HUMIDITY :{}%\n".format(humidity))
    print("WIND SPEED:{}m/s\n".format(speed))
    print("LATITUDE:{}\n".format(lat))
    print("LONGITUDE:{}\n".format(long))
    print("DESCRIPTION:{}\n".format(description))

    
print("-" * 50," WeatherWiz! ","-" * 50,"\n")
print("1.Get details by city\n")
print("2.Get details by location\n")
choice=int(input("Enter your choice:"))
print("\n")
if choice==1:
    city()
elif choice==2:
    location()
else:
    print("Enter valid choice")
