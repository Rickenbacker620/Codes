import requests
import re
import os
from lxml import etree


class ComDown:
    def __init__(self, cname, cnum, start, end):
        self.baseurl = "https://www.bnmanhua.com/comic/"
        self.imgbaseurl = 'https://img.yaoyaoliao.com/'
        self.cname = cname
        self.cnum = cnum
        self.start = start
        self.end = end

    def savepage(self, imgurl, imgnum, curpage):
        with requests.get(imgurl, stream=True) as resp:
            imgpath = curpage+"/"+str(imgnum)+".jpg"
            if not os.path.exists(imgpath):
                with open(imgpath, 'wb') as fd:
                    for chunk in resp.iter_content():
                        fd.write(chunk)

    def traverse_page(self):
        if not os.path.exists(self.cname):
            os.mkdir(self.cname)
        for i in range(self.start, self.end+1):
            pagepath = self.cname+"/"+str(i-self.start+1)
            if not os.path.exists(pagepath):
                os.makedirs(pagepath)
            episodeurl = self.baseurl+str(self.cnum)+"/"+str(i)+".html?p="
            res = requests.get(episodeurl)
            theweb = res.text
            z_img = re.search(r"z_img='.*'", theweb).group(0)
            z_img = z_img.replace("\/", "/")
            z_img = z_img.split("'")[1]
            pages = eval("("+z_img+")")
            for i, page in enumerate(pages):
                self.savepage(self.imgbaseurl+page, i+1, pagepath)


# cc = ComDown("Attack on Titan", 2393, 882342, 882344)
# cc.traverse_page()

# url = "https://manhua.fzdm.com/39/"
res = requests.get("https://manhua.fzdm.com/39/")
content = res.text

html = etree.HTML(content)

titles = html.xpath('//li/a')
result = html.xpath('//li/a')

for r in result:
    print(r.text)
