#it can check if your all braces is balanced or not like {[()]} is balanced
#and [{]} is not balanced
p=input("Input Your paragraph :")
symbollist=["{","}","[","]","(",")"]
opensymbol=["[","{","("]
closesymbol=["]","}",")"]
templist=[]
for word in p:
	for char in word:
		if char in symbollist:
			templist.append(char)
def check():
	global templist
	tlen=len(templist)
	if tlen==0:
		return 0
	elif(tlen==1):
		return	
	for i in range(len(templist)):
		#item
		try:
			I=templist[i]
		except:
			break
		if I in opensymbol:
			continue
		#previousitem
		pI=templist[i-1]
		if I in closesymbol and i==0:
			break
		if I in closesymbol:
			op=closesymbol.index(I)
			#oppositeitem
			opI=opensymbol[op]
			if pI==opI:
				templist.pop(i)
				templist.pop(i-1)
			else:
				print("not Balanced")
				return
		check()	
check()
if len(templist)==0:
	print("balanced")
