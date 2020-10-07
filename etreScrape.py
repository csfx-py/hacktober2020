import requests
from bs4 import BeautifulSoup
import json

url = 'https://www.cestfacile.eu/nl/werkwoorden/5-hulpwerkwoord-etre.html'
page = requests.get(url)
soup = BeautifulSoup(page.content, 'html.parser')

infList = []

#ophalen van werkwoord link naar vervoeging
for result in soup.find_all('ul', class_='list-unstyled columns notranslate'):
    for li in result.find_all('li'):
        for a in li.find_all('a'):
            infList.append(a.text)
print(infList)



with open('etreVerbs.json', 'w') as jsonfile:
    json.dump(infList, jsonfile, ensure_ascii=False)
