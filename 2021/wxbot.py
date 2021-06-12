'''
Created on 2018年5月18日
@author: Administrator
'''
"#codeing=utf-8"
import json  
import requests  
from wxpy import *  

def reply(text):
    print('条条：',text)
    url = "http://www.tuling123.com/openapi/api"  
    api_key="0ff6e901b0744234997032c0c55a7a63"  
    payload={  
        "key":api_key,  
        "info":text,  
        "userid":"666"  
        }  
    r = requests.post(url,data=json.dumps(payload))  
    result = json.loads(r.content)  
    if ('url' in result.keys()):  
        return ""+result["text"]+result["url"]  
    else:  
        return ""+result["text"]  


bot = Bot(cache_path=True) #登录缓存  
print('小明上线')  

found = bot.friends().search('条条')
print(found)
# found.send("智障上线")
@bot.register(found)
def message(msg): 
    ret = reply(msg.text)  
    return ret
embed()

# print(reply("你好"))