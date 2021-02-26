def flatten(nested):
    res=[]
    try:
        try:nested+''
        except TypeError:pass
        else:raise TypeError
        for subl in nested:
            for el in flatten(subl):
                res.append(el)
    except TypeError:
        res.append(nested)
    return res
n=[[1,2],[3,4],[5]]
print(flatten(n))
