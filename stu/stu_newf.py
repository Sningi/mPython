def fibs(num):
    "计算获得裴济数列"
    arr= [0,1]
    for i in range(num-2):
        arr.append(arr[-2]+arr[-1])
    return arr
help(fibs)
#num=int(input("num:\n"))
#print(fibs(num))
