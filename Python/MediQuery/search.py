import sqlite3
import pandas
import math
import os
import json
import xlrd


class Medi:
    def __init__(self):
        self.conn = sqlite3.connect(":memory:")
        self.cursor = self.conn.cursor()

    def CreateTable(self):
        self.cursor.execute(
            """
                CREATE TABLE hospital(
                    ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                    patient  TEXT      NOT NULL,
                    medicine TEXT      NOT NULL,
                    count    INTEGER   NOT NULL
                );
            """
        )

    def Print(self):
        value = self.cursor.execute(
            """
                SELECT * FROM hospital
        """
        )
        print(value.fetchall())

    def InsertRecord(self, data):
        self.cursor.executemany(
            """
             INSERT INTO hospital (PATIENT,MEDICINE,COUNT)
             VALUES(?, ?, ?);
             """,
            data,
        )

    def Quit(self):
        self.conn.commit()
        self.conn.close()

    def ReadExcel(self, folder, file):
        isCNMediCounted = 0
        patient = file[:-4]
        mediRecords = []
        wb = xlrd.open_workbook(folder + "/" + file, logfile=open(os.devnull, "w"))
        mediSheet = pandas.read_excel(wb, index_col="项目代码", usecols="A, B, D")
        for record in mediSheet.values:
            lrecord = record.tolist()
            lrecord.insert(0, patient)
            if not math.isnan(lrecord[2]):
                lrecord[2] = int(lrecord[2])
                mediRecords.append(lrecord)
            elif "中成药" in lrecord[1]:
                isCNMediCounted = 1
            else:
                pass
        if not isCNMediCounted:
            print("{} 未统计".format(patient))
        else:
            print("{} 统计中成药".format(patient))
        self.InsertRecord(mediRecords)

    def ReadFolder(self):
        basefolder = "yao"
        sheetlist = []
        for sheet in os.listdir(basefolder):
            sheetlist.append(sheet)
            self.ReadExcel(basefolder, sheet)

    def Query(self, listfile):
        with open(listfile, encoding="utf-8") as file:
            with open("result.txt", "a+", encoding="utf-8") as result:
                result.truncate(0)
                for line in file:
                    queryMedi = line.strip()
                    countSum = 0
                    value = self.cursor.execute(
                        """
                            SELECT patient,medicine,count FROM hospital WHERE medicine LIKE '%{}%';
                    """.format(
                            queryMedi
                        )
                    )
                    for row in value:
                        print(row)
                        result.write(str(row) + "\n")
                        countSum += row[2]
                    print("{} 总计: {}\n".format(queryMedi, countSum))
                    result.write("{} 总计: {}\n".format(queryMedi, countSum) + "\n")


m = Medi()
m.CreateTable()
m.ReadFolder()
m.Query("yao.txt")
m.Quit()
os.system("pause")
