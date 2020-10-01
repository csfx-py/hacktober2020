import requests
import math
import sys, argparse

apiUrl = "http://api.openweathermap.org/data/2.5/weather"   #base url
apiKey = "652c3faf2c011946c60c3236f257e779" # api key of openweathermap 
units = "metric" 

# just things for commnad line arguments
description = "I am just gonna tell your weather details\n Based on City Name, Lattitude & Longitude, City ID or Zip Code"
parser = argparse.ArgumentParser(prog=sys.argv[0],
                                usage='%(prog)s [options] Details',
                                description=description)
parser.add_argument("-c", "--city", help="City Name")
parser.add_argument("-i", "--cityid", help="City ID")
parser.add_argument("-z", "--zipcode", help="Zip Code")
parser.add_argument("-lat", "--latitude", help="Latitude")
parser.add_argument("-lon", "--longitude", help="Longitude")
args = parser.parse_args()

if(len(sys.argv) == 1): # if no argument is given
    parser.print_help() # print help
    sys.exit()  #and exit
    
#assembling all the parameters for getting data
payload = {'q':vars(args)['city'], 'id':vars(args)['cityid'],
         'lat': vars(args)['latitude'], 'lon':vars(args)['longitude'],
        'zip':vars(args)['zipcode'], 'appid':apiKey, 'units':units}

# getting the actual data
r = requests.get(apiUrl, params=payload)
data = r.json() # and json format to dict

if r.status_code != 200: # upon error we gets error code and message 
    print(f"{data['cod']}: {data['message']}")  #print the code and the message
    sys.exit()  # and exit
   
def inFarenhaeit(temp):
    return round((temp* 9/5) + 32, 2)

cityName = data['name']
latitude = data['coord']['lat']
longitude = data['coord']['lon']
weatherState = data['weather'][0]['description']
temp = data['main']['temp']
tempInF = inFarenhaeit(temp)
tempMin = data['main']['temp_min']
tempMinInF = inFarenhaeit(tempMin)
tempMax = data['main']['temp_max']
tempMaxInF = inFarenhaeit(tempMax)
humidity = data['main']['humidity']
pressure = data['main']['pressure']

print(f'''City: {cityName}
Latitude & Longitude: {latitude}, {longitude}
Weather: {weatherState}
Temperatures: {temp}°C / {tempInF}°F
         min: {tempMin}°C / {tempMinInF}°F
         max: {tempMax}°C / {tempMaxInF}°F
Humdity: {humidity}%
Pressure: {pressure}hpa''' )