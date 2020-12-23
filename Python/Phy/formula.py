import math
cod = (0.831, 0.834, 0.832, 0.833, 0.834, 0.825, 0.826)
coD = (141.29, 141.20, 141.34, 141.33)
coB = (7.350, 7.340, 7.360, 7.340)
coC = (88.10, 88.11, 88.10, 88.10)
coX = (1.47, 1.62, 1.25, 1.46, 1.56)

class Phy:
    def __init__(self, datas, b):
        self.tn = (0, 0, 0, 2.48, 1.59, 1.24, 1.05, 0.926, 0.834)
        self.datas = datas

        self.sdstr = ""
        self.astr = ""
        self.udstr = ""

        self.sd = 0
        for i in range(1, len(datas)):
            self.sd += pow((datas[i] - datas[0]), 2)
        self.sd /= (len(datas)-2)
        self.sd = math.sqrt(self.sd)

        self.a = self.tn[len(datas)-1] * self.sd

        self.b = b

        self.ud = math.sqrt(pow(self.a, 2)+pow(self.b, 2))

    def printave(self):
        print(self.datas[0])

    def printsd(self):
        tmp = ""
        for i in range(1, len(self.datas)):
            tmp += f"({self.datas[i]} - {self.datas[0]})² + "
        tmp = tmp[:-2]
        space = len(tmp)
        self.sdstr = 3 * " "  + (space) * "_" + "\n" + \
                    "  /  " + tmp + "\n" + \
                    " / " + space * "-" + " = " + str(self.sd) + "\n" + \
                    "/" + int(space/2-1) * " " + f"{len(self.datas)-2}" + int(space/2-1) * " "
        print(self.sdstr)

    def printa(self):
        self.astr += f"{self.tn[len(self.datas)-1]} * {self.sd} = {self.a}"
        print(self.astr)

    def printud(self):
        tmp = ""
        tmp += f"{self.a}² + {self.b}²"
        space = len(tmp)
        self.udstr = " "  + (space) * "_" + "\n" + \
                    "/" + tmp + " = " + str(self.ud)
        print(self.udstr)



newda = Phy(coX, 0.01)
newda.printave()
newda.printsd()
newda.printa()
newda.printud()