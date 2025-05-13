import sys
A= int(input())
B = int(input())
C = int(input())
num = str(A*B*C)
dic = map(lambda x:num.count(x), ['0', '1','2','3','4','5','6','7','8','9'])
for x in dic: print(x)