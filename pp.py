import requests
data='''------WebKitFormBoundary2I5f56ULhsAhWBfr
Content-Disposition: form-data; name="ip_addr"

129.126.102.10
------WebKitFormBoundary2I5f56ULhsAhWBfr
Content-Disposition: form-data; name="port"

4153
------WebKitFormBoundary2I5f56ULhsAhWBfr--'''
#r=requests.post('https://onlinechecker.proxyscrape.com/index.php',data=data)
#print(r.text)
#print(data)
#print(r.status_code)
p=requests.get('https://www.proxyscan.io/download?type=socks4')
f=open(r'/storage/emulated/0/proxy.txt','w+')
a=p.text
f.writelines(a)