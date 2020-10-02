import requests
import urllib3
from bs4 import BeautifulSoup
from pyrogram import Client
import time
import sys
from __banner__.banner import banner
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)


######## This is only for educational purpose ########
######## I'm not responsible for any loss or damage caused to you ########
######## using this script. ########
######## YOU ARE USING THIS SCRIPT ON YOUR OWN RISK ########

def ordinal(n):
    suffix = ['th', 'st', 'nd', 'rd', 'th', 'th', 'th', 'th', 'th', 'th']

    if n < 0:
        n *= -1

    n = int(n)

    if n % 100 in (11,12,13):
        s = 'th'
    else:
        s = suffix[n % 10]

    return str(n) + s

def main():
    sys.stdout.write(banner())

    time.sleep(0.8)
    
    last_l = len('chk_list_urls')

    head = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Safari/537.36',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    }

    chk_list_urls = []
    no = 1
    input_an = True

    while input_an != False:
        inp_urls = input('Paste ' + ordinal(no) + ' url, When you are done adding urls input "next" to start script: ')
        no += 1
        if inp_urls != 'next':
            chk_list_urls.append(inp_urls)
        else:
            input_an = False

    while True:
        for index, url in enumerate(chk_list_urls):
            r = requests.get(url, headers=head, verify=False)
            soup = BeautifulSoup(r.content, 'html.parser')

            try:
                if soup.find('span', class_ = 'a-color-price a-text-bold').text == 'Currently unavailable.':
                        title = soup.find('span', class_='a-size-large product-title-word-break').text
                        print(title +'is out of stock')
                        if index == last_l - 1:
                            time.sleep(5) #You can change it as per your Requirement (Only in seconds)
                    # product is oos
                
            except:
                try:
                    if soup.find('td',class_="a-color-secondary a-size-base a-text-right a-nowrap").text == 'Price:':
                        title = soup.find('span',class_ = 'a-size-large product-title-word-break').text
                        print(title+'is in stock')
                        # print('in stock')

                        
                        ######## SENDING A MESSAGE TO YOUR TELEGEGRAM ########
                        ######## Get below details from my.telegram.org ########
                        ######## Add api_id and api_hash from my.telegram.org ########
                        
                        app = Client(
                            "tg_ac",
                            api_id=1756008, ######## YOUR API_ID ########
                            api_hash="9e5d85c133e3c4082cead584d03790e5" ######## YOUR API_HASH ########
                        )

                        msg = title + ' is in stock LINK - ' + url ######## You can customize this ########

                        with app:
                            app.send_message("sinhandsons", msg)  ######## Sending msg To @your_tg_username (set urs) ########
                            if index == last_l - 1:
                                time.sleep(5) #You can change it as per your Requirement (Only in seconds)
                except:
                    if soup.find('button', class_ = '_2AkmmA _2Npkh4 _2MWPVK _18WSRq')['disabled']:
                        print('disabled')

if __name__ == '__main__':
    main()