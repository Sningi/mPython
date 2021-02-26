from math import sqrt
for n in range(99,81,-1):
	root=sqrt(n)
	if root==int (root):
		print ("max is "+str(n))
		break
else:
	print("not find")
while True:
	word=input("please input word\n")
	if not word :break
	print ("word is "+word)
print("not input ,end !")
s=input()
