    #   method: "GET",
    #   url:
    #     scriptdata.baseurl + "api/domoocstatus?version=" + scriptdata.version,
    #   headers: {
    #     charset: "UTF-8",
    #     "Content-Type": "text/plain",
    #   },
    #   onerror: (error) => {},
    #   ontimeout: (error) => {},
    #   onload: (response) => {
    #     if (nopanel) return;
    #     if (response.status == 200) {
    #       let res = JSON.parse(response.responseText);
    #       if (typeof res.url === "string" && res.url.startsWith("http")) {
    #         window.open(res.url);
    #       }
    #       if (typeof res.msg === "string") {
    #         if (domooc.failed) {
    #           window.alert(
    #             "脚本出了点问题\n请勿使用“自动填写答案”和“刷课”功能\n你可以单个查看答案，然后自己填写\n重新打开当前网页也许能解决"
    #           );
    #         } else {
    #           window.alert(res.msg);
    #         }
    #       }
    #       if (typeof res.antiantiscript === "string") {
    #         if (res.antiantiscript !== antiantiscript) {
    #           GM_setValue("antiantiscript", res.antiantiscript);
    #           window.location.reload();
    #         }
    #       }
    #     }
    #   },
    # });

import requests
import json

baseurl = "https://lolzyx.xyz/"

res = requests.get(baseurl + "api/domoocstatus?version=" + "1911")
resjs = json.loads(res.text)
print(resjs["msg"])
