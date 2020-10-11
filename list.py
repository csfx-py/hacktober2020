list1=[1,2,3,4,4]
#list is a collection which is ordered and changeable. Allows duplicate members.


print(list1[1])#by providing index no getting the element return

print(list1.index(3))#by providing the element we can get the index of the elment

list1.append(9)#addition of element at the end of the list 

print(list1)

print(list1.count(4))#counts the number of elements present in the list

a=list1.copy()#returns a copy of list 
print(a)

list1.extend([1,3,4])#Extends the the list from end adding more than one elements
print(list1)

list1.insert(2,34)#Inserts element at specified index by moving the remaining list right side
print(list1)

print(list1.pop(2))#Eradicates(removes) and returns the element of the specified index and by default removes the rightmost element
print(list1)

list1.remove(2)#removes the first occrance of that specified element and deletes it
print(list1)

list1.reverse()#reverses the list without taking any argument or returning any thing 
print(list1)

list1.sort()#sorts the list
print(list1)

#Few built in functions
print(min(list1))
print(max(list1))
print(len(list1))

list1.clear()#clears the whole list 
print(list1)


    
