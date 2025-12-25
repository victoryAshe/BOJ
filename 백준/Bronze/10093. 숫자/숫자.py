import sys
A, B = map(int, input().split())
if A>B: A,B = B,A
if A!=B: print(B-A-1)
else: print(0)

for i in range(A+1, B):
  print(i, end=' ')