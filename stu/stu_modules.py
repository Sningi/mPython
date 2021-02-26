import sys
import re
co=1
str = re.compile(r'.*enu.*')
for s in help("modules"):
    if str.match(s) != None:
        print(s)
    else:
        co+=1
        print("no",co)
