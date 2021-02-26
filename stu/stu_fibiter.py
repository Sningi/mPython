def Fib():
  f=[0,1]
  for i in range(2000):
    f.append(f[-2]+f[-1])
  return f
#  print(f[1000])
fibs=Fib()
for fb in fibs:
  if fb>1000:
    print(fb)
    break 
while True:
  word=input("please input command\n")
  if not word :break
  exec(word)
print("not input ,end !")

