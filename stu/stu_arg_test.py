def story(**kwds):
    return 'Once upon a time,there was a '\
        '%(job)s called %(name)s.' % kwds

def power(x,y,*others):
    if others:
        print("Received redun parameter :",others)
    return pow(x,y)
def interval(start,stop=None,step=1):
    'Imitates range() for step>0'
    if stop is None:
        start,stop=0,start
    result=[]
    i=start
    while i<stop:
        result.append(i)
        i+=step
    return result

print (story(job='king',name='gming'))
while True:
    com=input("please input command:\n")
    if com:
        exec(com)
    else:
        break

