import os.path
import re

url = "F:/Codes/Python/RemDuplicate/mockdata/"

filelist = []


# def CheckSame(check, exist):


def IsInTheList(filename):
    for existfile in filelist:
        if filename[0:1] == existfile[0:1]:
            return existfile


def FindDup(url):
    for filename in os.listdir(url):
        duplicatefile = IsInTheList(filename)
        if duplicatefile:
            print("%s\n%s\n\n" % (duplicatefile, filename))
        else:
            filelist.append(filename)


def ReMovePrefix(url):
    for filename in os.listdir(url):
        if "[异步图书]." in filename:
            oldname = url+filename
            newname = url+filename.replace("[异步图书].", "")
            os.rename(oldname, newname)

    # FindDup(url)


def TraverseFolder(baseurl):
    for dir in os.listdir(baseurl):
        ReMovePrefix(baseurl+dir+'/')


TraverseFolder("F:/计算机书籍/")
