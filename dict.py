dict={'apple':5,'ball':2,'orange':3,'guava':4,'peach':69}
#A dictionary is a collection which is unordered, changeable and indexed. In Python dictionaries are written with curly brackets, and they have keys and values.

print(dict)#simple printing of all dict values and keys

for keys in dict:
    print(keys)

print(dict['apple'])
a=dict.copy()#simple coping of the whole dictionary in a variable
print(a)

val=1
b=dict.fromkeys(dict,val)#generates new dictionary with with values set to value and keys from seq(here dict)
print(b)

c=dict.copy()#simple copying of of the dictionary
print(c)

print(dict.get('ball'))#fetches the value for the key, If the is not in the dictionary then returns default
print(dict.get('g'))

#print(dict.has_key('g'))
#has been removed in python3 used to be attribute in python2


a=dict.items()
print(a)

print(dict.keys())#returns the keys

print(dict.pop('orange'))#removes the provided key and its value from the dictionary and also returns the value of key
print(dict)

print(dict.popitem())#pops and returns the value and key of the last element 
print(dict)

print(dict.setdefault('aloo',47))#adds new key and value to the existing dictionary
print(dict)

dict1={'a':1,'b':2}
dict.update(dict1)#appends the key-value pair from one dict to another
print(dict)

print(dict.values())#returns al the values present in the dictionary
print(dict.keys())#returns all the keys present in the dictionary

print(dict.clear())#remove all the keys and values from the dictionary

