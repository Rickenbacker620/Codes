import requests
import os
from lxml import etree


class Comic():
    def __init__(self):
        self.baseurl = "https://manhua.fzdm.com/39/"
        self.name = "Attack On Titan"
        self.chapters = []

    def GetChapters(self):
        rawDoc = requests.get(self.baseurl).text
        html = etree.HTML(rawDoc)
        nodes = html.xpath('//div[@id="content"]/li/a')

        for node in nodes:
            title = node.text
            url = self.baseurl + node.attrib['href']
            self.chapters.append({'title': title, 'url': url})
        return self

    def GetPages(self, url):
        # TODO
        pages = []
        urls = []
        for url in urls:
            pass
        return ["pages", 'pages2']

    def SaveChapter(self, chapter):
        title = chapter['title']
        url = chapter['url']
        location = f"{self.name}/{title}/"

        os.makedirs(location, exist_ok=True)

        pages = self.GetPages(url)

        for index, page in enumerate(pages):
            with open(location + str(index) + '.txt', "w") as pic:
                pic.write(page)

    def Run(self):
        self.GetChapters()
        for chapter in self.chapters:
            self.SaveChapter(chapter)


c = Comic()

c.Run()

# for chp in c.GetChapters().chapters:
#     print(chp)
