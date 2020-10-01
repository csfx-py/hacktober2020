import requests
import re

def find_links(page_source):
	regex = re.compile(r'<a href="(.+?)" target')
	result=regex.findall(page_source)
	return result
Website=input("Enter your domain:-")
res = requests.get("https://webiplookup.com/"+Website+"/domain.htm")

links=find_links(res.text)
for link in links:
	print(link)
