
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
import re

cout = open("save.txt", "w")

def procform(formpath):
    formfile = open(formpath, "r")
    buffer = '{'
    for line in formfile:
        buffer += ("'" + line.replace('\n', "',").replace(': ', "':'"))
    buffer = buffer[:-1] + '}'
    return eval(buffer)

url = "https://uaaap.yzu.edu.cn/cas/login?service=http%3A%2F%2Fmy.yzu.edu.cn%2Fportal_main%2FtoPortalPage"


session = requests.Session()

def login():
    data = procform("form")
    params = {
        "service": "http://my.yzu.edu.cn/portal_main/toPortalPage"
    }
    token = session.get(url)
    data["lt"] = re.search(r'LT-.*cn/cas', token.text, re.M|re.I).group()
    main_page = session.post(url, data=data, params=params)
    form_url = "https://ehall.yzu.edu.cn/infoplus/form/XNYQSB/start"
    form_page = session.get(form_url)
    cout.write(form_page.text)


# save_code()

# valid = input("valid")

login()
