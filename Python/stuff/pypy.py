# import requests

# file = open("save.txt", "w")


# session = requests.Session()

# headers = {
# "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36 Edg/85.0.564.68"}

# resp = session.get(url)

# print(resp.content)

# file.write(resp.content.decode())

import json
import requests
import random

fo = open("header.txt", "r")

buffer = '{'

for line in fo:
    buffer += ("'" + line.replace('\n', "',").replace(': ', "':'"))

url = "http://jw1.yzu.edu.cn/"

buffer = buffer[:-1] + '}'
headers = eval(buffer)

session = requests.Session()
def save_code():
    validcode_url = url + "validateCodeAction.do?random=+Math.random()"
    validcode = session.get(validcode_url)
    if (validcode.status_code == 200):
        with open('codepic.png', 'wb') as f:
            f.write(validcode.content)
        print("验证码保存成功！")
    else:
        print("验证码保存失败！")

def login(username, password, validcode):
    data = {
        "zjh" : username,
        "mm" : password,
        "v_yzm" : validcode
    }
    res = session.post(url+"loginAction.do", data=data)
    print(res.status_code)
    print(res.text)

save_code()

valid = input("valid")

login(191304324, 191304324, valid)
