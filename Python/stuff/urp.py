import json
import requests
import random
import re


baseUrl = "http://jw1.yzu.edu.cn/"

session = requests.Session()

session.headers = {
    'Connection': 'Keep-Alive',
    'Accept-Language': 'zh-CN,zh;q=0.8',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36 SE 2.X MetaSr 1.0',
    'Accept-Encoding': 'gzip, deflate',
    'Upgrade-Insecure-Requests': '1',
    'Referer': 'http://jw1.yzu.edu.cn',
    'X-Requested-With': 'XMLHttpRequest',
    'Host': 'jw1.yzu.edu.cn'}


def GetCode():
    validcodeUrl = baseUrl + "validateCodeAction.do?random=+Math.random()"
    validcode = session.get(validcodeUrl)
    if (validcode.status_code == 200):
        with open('codepic.png', 'wb') as f:
            f.write(validcode.content)
        print("验证码保存成功！")
    else:
        print("验证码保存失败！")


def Login(validcode):
    data = {
        "zjh": 191304324,
        "mm": 191304324,
        "v_yzm": validcode
    }
    res = session.post(baseUrl+"loginAction.do", data=data)
    if "学分制综合教务" in res.text:
        print("登录成功\n")


def GetSessionId():
    res = session.get("http://jw1.yzu.edu.cn/dwr/engine.js")
    start = res.text.find("dwr.engine._origScriptSessionId")
    w1 = "dwr.engine._origScriptSessionId = "
    w2 = ";"

    pat = re.compile(w1+'(.*?)'+w2, re.S)
    sessionId = pat.findall(res.text)[0][1:-1] + \
        str(random.randint(0, 1000))
    return sessionId


def ClassScript():
    GetCode()
    validCode = input("输入验证码:\n")
    Login(validCode)
    queryClass = {
        "kch": 17038002,
        "kcm": "",
        "actionType": 3,
        "pageNumber": -1
    }
    classData = {
        "kcId": 17018001_01,
        # "kcId": 17038002_01,
        "preActionType": 3,
        "actionType": 9
    }

    res = session.get(
        "http://jw1.yzu.edu.cn/xkAction.do?actionType=-1&fajhh=3440")
    res = session.get(
        "http://jw1.yzu.edu.cn/xkAction.do?actionType=3&pageNumber=-1")
    # res = session.post(baseUrl+"xkAction.do", data=queryClass)

    sessionId = GetSessionId()
    jSessionId = session.cookies["JSESSIONID"]
    payloadData = "callCount=1\npage=/xkAction.do?actionType=-1&fajhh=3440\nhttpSessionId=" + jSessionId + \
        "\nscriptSessionId="+sessionId + \
        "\nc0-scriptName=ajaxtool\nc0-methodName=reCall\nc0-id=0\nbatchId=0 "

    ajaxUrl = "http://jw1.yzu.edu.cn/dwr/call/plaincall/ajaxtool.reCall.dwr"

    res = session.post(ajaxUrl, data=payloadData)
    # print(res.text)

    res = session.post(
        baseUrl+"xkAction.do", data=classData)
    res = session.post(
        baseUrl+"xkAction.do", data=classData)
    file = open("text.html", mode="w")
    file.write(res.text)


ClassScript()
