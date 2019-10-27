'''
Author: @vinuthegr8
Submission Link: https://codeforces.com/gym/101856/submission/58209101
'''

import sys
import math
input = sys.stdin.readline
 
f = open("katryoshka.in",'r')
flag=True
case = 1
for i in f:
	if flag:
		flag=False
		t=int(i)
	else:
		n,m,k=map(int,i.split())
		b=min(n,m,k)
		n-=b
		m-=b
		k-=b
		b+=min(n//2,k)
		print("Case " + str(case) + ": " + str(b))
		case += 1
