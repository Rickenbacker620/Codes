import requests
import os
import re
from lxml import etree


def ParseHTML(url):
    rawDoc = requests.get(url).text
    html = etree.HTML(rawDoc)
    return html


class Comic():
    def __init__(self):
        self.baseurl = "https://manhua.fzdm.com/39/"
        self.baseimgurl = "https://p5.manhuapan.com/"
        self.name = "Attack On Titan"
        self.chapters = []

    def GetChapters(self):
        html = ParseHTML(self.baseurl)
        nodes = html.xpath('//div[@id="content"]/li/a')

        for node in nodes:
            title = node.text
            url = self.baseurl + node.attrib['href']
            self.chapters.append({'title': title, 'url': url})
        return self

    def GetImgIter(self, url):
        idx = 0
        while True:
            pageurl = f"{url}index_{str(idx)}.html"
            try:
                yield {self.ExtractImg(pageurl), idx}
            except IndexError:
                return
            idx += 1

    def ExtractImg(self, pageurl):
        res = requests.get(pageurl)
        if res.status_code == 404:
            raise IndexError

        regexp = re.compile(r'(?<=mhurl=").*?(?=";)')
        rawDoc = res.text
        imgurl = self.baseimgurl + regexp.search(rawDoc).group(0)
        return imgurl

    def SaveChapter(self, chapter):
        title = chapter['title']
        url = chapter['url']
        path = f"{self.name}/{title}/"

        os.makedirs(path, exist_ok=True)

        imgurls = self.GetImgIter(url)

        for index, imgurl in imgurls:
            print(imgurl)
            # with requests.get(imgurl, stream=True) as res:
            #     with open(f"{path}{str(idx)}.jpg", "wb") as pic:
            #         for chunk in res.iter_content():
            #             pic.write(chunk)

    def Run(self):
        self.GetChapters()
        for chapter in self.chapters:
            self.SaveChapter(chapter)


c = Comic()

c.SaveChapter({'title': "test", 'url': "https://manhua.fzdm.com/39/001/"})
# c.ExtractImg("https://manhua.fzdm.com/39/001/index_100.html")

# img = c.ExtractImg("https://manhua.fzdm.com/39/001/index_1.html")

# print(img)

# for chp in c.GetChapters().chapters:
#     print(chp)
