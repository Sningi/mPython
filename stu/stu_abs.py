def init(data):
    data['first'] = {}
    data['middle'] = {}
    data['last'] = {}


def lookup(data, lable, name):
    return data[lable].get(name)


def store(data, full_name):
    names = full_name.split()
    if len(names) == 2:
        names.insert(1, '')
    lables = 'first', 'middle', 'last'
    for lable, name in zip(lables, names):
        people = lookup(data, lable, name)
        if people:
            people.append(full_name)
        else:
            data[lable][name] = [full_name]


storage = {}
init(storage)
#store(storage,'magus li het')
# print(lookup(storage,'middle','li'))
while True:
    word = input("please input command\n")
    if not word:
        break
    exec(word)
print("not input ,end !")
