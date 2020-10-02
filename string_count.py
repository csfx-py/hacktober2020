def string_features(S1, S2):
 a=[]
 for s1 in S1.split():
 for s2 in S2.split():
 if s1==s2:
 a.append(s1)
 print(len(a))
 b=set(S1.split())-set(S2.split())
 print(list(b))
 c=set(S2.split())-set(S1.split())
 print(list(c))

S1= "the first column F will contain only 5 uniques values"
S2= "the second column S will contain only 3 uniques values"
string_features(S1, S2)
