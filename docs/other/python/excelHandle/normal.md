```python
import pandas as pd
import os
import openpyxl
import functools

files = '/mnt/d/work/task/001所有测试脚本/'
file_root = files+'谢晓敏/SX-SAP-UT-SD-单元测试脚本1060-V2.0-黄晨洪/'
file_list = os.listdir(file_root)
file_list

def compare(x,y):
    if(x[-7:-5]>y[-7:-5]):
        return 1
    elif x[-7:-5]<y[-7:-5]:
        return -1
    return 0

# for file in file_list:
#     print(file[-8:-5])
file_list.sort(key=functools.cmp_to_key(compare))
file_list

dateDict = {0:['2023-07-25','2023-07-26'],1:['2023-07-26','2023-07-27'],2:['2023-07-27','2023-07-28'],3:['2023-07-28','2023-07-28']}
def update_date(file,index):
    xlsfile = openpyxl.load_workbook(file)
    print(xlsfile.sheetnames)
    sheet1 = xlsfile[xlsfile.sheetnames[0]]
#     print(sheet1['H28'].value)
#     print(sheet1['H29'].value)
    p = int(index / 3)
    sheet1['H28'].value = dateDict[p][0]
    sheet1['H29'].value = dateDict[p][1]
    
    sheet2 = xlsfile[xlsfile.sheetnames[1]]
    sheet2['C3'].value = dateDict[p][0]
    print(sheet2['C3'].value)
    
    xlsfile.save(file)
for index,file in enumerate(file_list):
    print(index)
    update_date(file_root + file,index)
```





| Sales  Office |      | Sales Group |      | Sales  Organization | Sales  Organization Name |      | Sold-to Party | Sold-To Party  Name | Material number | Material  Description | Contact | Sales  Document     / Order | Sales Document  Type     / | Sales Document  Item | Order  Quantity(Item) | Sales Unit(     canister/cv) |      | Document  Currency     / Doc. Currency | Confirmed  Quantity | Billing Document     / Bill. Doc. | Billing Type | Created By | User Name | Stock | Created On |      |      | Overall Status |
| ------------- | ---- | ----------- | ---- | ------------------- | ------------------------ | ---- | ------------- | ------------------- | --------------- | --------------------- | ------- | --------------------------- | -------------------------- | -------------------- | --------------------- | ---------------------------- | ---- | -------------------------------------- | ------------------- | --------------------------------- | ------------ | ---------- | --------- | ----- | ---------- | ---- | ---- | -------------- |
|               |      |             |      |                     |                          |      |               |                     |                 |                       |         |                             |                            |                      |                       |                              |      |                                        |                     |                                   |              |            |           |       |            |      |      |                |
