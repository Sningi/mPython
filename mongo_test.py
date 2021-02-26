"""pip3 install pymongo"""

import pymongo

myclient = pymongo.MongoClient("mongodb://localhost:27017/")
# mydb = myclient["runoobdb"]
dblist = myclient.list_database_names()
if "runoobdb" in dblist:
    print("数据库已存在！")
else:
    print(dblist)
    print("数据库不存在！")
     
