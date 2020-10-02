d={1:2,3:4}
v=int(input())
for i in d.keys():
        if v in d.values() and d[i]==v:
            print("the key for the given value ",v,"is",i)
        else:
            print("value is not present in the dict")
            break
