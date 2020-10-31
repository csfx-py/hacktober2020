#Tuple are similar to lists .... Its just cannot be changed
#A tuple is a collection which is ordered and unchangeable.
#In Python tuples are written with round brackets.

tup=(12,11,2,1,2,2)
# tupples are declared as tup=()no square brackets

print(tup)
#used to print the whope tuple

print(tup[1])
#used to print particular element in the tuple

print(len(tup))
#Length of the tuple 

print(tup.count(2))
#used to count number of times element occured

print(tup.index(11))
#Shows the Index where the given element is located

print(tup.index(2))
#In case of repetative elements where the 1st time the element is occurred 

#Joining of 2 Tuples
tuple1 = ("a", "b" , "c")
tuple2 = (1, 2, 3)

tuple3 = tuple1 + tuple2
print(tuple3)

#Another method of creating tupple using Tuple constructor
thistuple = tuple(("apple", "banana", "cherry")) # note the double round-brackets
print(thistuple)


##In tuple values can't be changed so iteration is easy.. tuple is used in proects where values cant be changed 

#Method of to workaround for chaing the value of tuple using lists
x = ("apple", "banana", "cherry")
y = list(x)
y[1] = "kiwi"
x = tuple(y)

print(x)

