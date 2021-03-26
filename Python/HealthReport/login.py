import requests
import os
import re

session = requests.Session()
headers = {'Content-Type': 'application/x-www-form-urlencoded'}


def login():
    res = session.get(
        "https://uaaap.yzu.edu.cn/cas/login?service=http%3A%2F%2Fmy.yzu.edu.cn%2Fportal_main%2FtoPortalPage")
    ltcode = re.search(r"(?<=parse\(').*(?=')", res.text, re.M).group(0)

    payload = 'lt={ltcode}&execution=e1s1&_eventId=submit&isQrSubmit=false&qrValue=%20&isMobileLogin=false&username=191304324&password=LUCIFERxyc200062&authCode='.format(
        ltcode=ltcode)  # execution maybe e1s1 or e2s2
    session.post(
        "https://uaaap.yzu.edu.cn/cas/login?service=http%3A%2F%2Fmy.yzu.edu.cn%2Fportal_main%2FtoPortalPage", headers=headers, data=payload, allow_redirects=False)
    res = session.get(
        "https://uaaap.yzu.edu.cn/cas/login?service=http%3A%2F%2Fmy.yzu.edu.cn%2Fportal_main%2FtoPortalPage", allow_redirects=True)  # need to follow redirect twice
    return res


def request_form():
    res = session.get("https://ehall.yzu.edu.cn/infoplus/form/XNYQSB/start?")
    csrf = re.search(r"(?<=csrfToken\" content=\").*(?=\")",
                     res.text, re.M).group(0)

    payload = "idc=XNYQSB&release=&csrfToken={csrf}&formData=%7B%22_VAR_ACTION_ACCOUNT%22%3A%22191304324%22%2C%22_VAR_ACTION_INDEP_ORGANIZES_Codes%22%3A%225013%22%2C%22_VAR_ACTION_REALNAME%22%3A%22%E8%82%96%E9%80%B8%E7%A8%8B%22%2C%22_VAR_ACTION_INDEP_ORGANIZES_Names%22%3A%22%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2(%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD%E5%AD%A6%E9%99%A2)%22%2C%22_VAR_OWNER_ACCOUNT%22%3A%22191304324%22%2C%22_VAR_ACTION_ORGANIZES_Names%22%3A%22%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2(%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD%E5%AD%A6%E9%99%A2)%22%2C%22_VAR_ACTION_ORGANIZE%22%3A%225013%22%2C%22_VAR_OWNER_USERCODES%22%3A%22191304324%22%2C%22_VAR_NOW_DAY%22%3A%2226%22%2C%22_VAR_ACTION_INDEP_ORGANIZE%22%3A%225013%22%2C%22_VAR_OWNER_REALNAME%22%3A%22%E8%82%96%E9%80%B8%E7%A8%8B%22%2C%22_VAR_ACTION_INDEP_ORGANIZE_Name%22%3A%22%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2(%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD%E5%AD%A6%E9%99%A2)%22%2C%22_VAR_NOW%22%3A%221616763097%22%2C%22_VAR_ACTION_ORGANIZE_Name%22%3A%22%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2(%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD%E5%AD%A6%E9%99%A2)%22%2C%22_VAR_OWNER_ORGANIZES_Codes%22%3A%225013%22%2C%22_VAR_ADDR%22%3A%2210.135.132.238%22%2C%22_VAR_URL_Attr%22%3A%22%7B%7D%22%2C%22_VAR_ENTRY_NUMBER%22%3A%22-1%22%2C%22_VAR_POSITIONS%22%3A%225013%3A2%3A191304324%5Cn5013%3A16%3A191304324%22%2C%22_VAR_OWNER_ORGANIZES_Names%22%3A%22%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2(%E4%BA%BA%E5%B7%A5%E6%99%BA%E8%83%BD%E5%AD%A6%E9%99%A2)%22%2C%22_VAR_URL%22%3A%22https%3A%2F%2Fehall.yzu.edu.cn%2Finfoplus%2Fform%2FXNYQSB%2Fstart%3F%22%2C%22_VAR_RELEASE%22%3A%22true%22%2C%22_VAR_TODAY%22%3A%221616688000%22%2C%22_VAR_NOW_MONTH%22%3A%223%22%2C%22_VAR_ACTION_USERCODES%22%3A%22191304324%22%2C%22_VAR_ACTION_ORGANIZES_Codes%22%3A%225013%22%2C%22_VAR_NOW_YEAR%22%3A%222021%22%2C%22_VAR_ENTRY_NAME%22%3A%22%22%2C%22_VAR_ENTRY_TAGS%22%3A%22%22%7D&lang=zh".format(csrf=csrf)

    formurl = session.post(
        "https://ehall.yzu.edu.cn/infoplus/interface/start", headers=headers, data=payload).json()["entities"][0]
    stepid = formurl.split('/')[-2]

    res = session.post(formurl)

    payload = "stepId={stepid}&instanceId=&admin=false&rand=707.3723742747038&width=612&lang=zh&csrfToken={csrf}".format(
        stepid=stepid, csrf=csrf)

    payload = "stepId={stepid}&includingTop=true&csrfToken={csrf}&lang=zh".format(
        stepid=stepid, csrf=csrf)

    print(res.text)


login()

request_form()
