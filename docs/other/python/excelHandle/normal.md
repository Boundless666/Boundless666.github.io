##### Excel 批量修改

> 涉及点

1. excel 读取写入
2. 文件名排序
3. python字典使用

```python
import pandas as pd
import os
import openpyxl
import functools

files = '/mnt/d/work/task/001所有测试脚本/'
file_root = files+'具体目录/'
file_list = os.listdir(file_root)
file_list

# 排序操作 比如这里是根据文件名 倒数第7个字符~倒数第5个字符 进行比较排序
def compare(x,y):
    if(x[-7:-5]>y[-7:-5]):
        return 1
    elif x[-7:-5]<y[-7:-5]:
        return -1
    return 0

# for file in file_list:
#     print(file[-8:-5])
file_list.sort(key=functools.cmp_to_key(compare)) # 这里就是调用上方的比较器
file_list

# 设置更新excel中的日期字典   比如满足第一个规则的时候 值就为'2023-07-25'
dateDict = {0:['2023-07-25','2023-07-26'],1:['2023-07-26','2023-07-27'],2:['2023-07-27','2023-07-28'],3:['2023-07-28','2023-07-28']}

def update_date(file,index):
    xlsfile = openpyxl.load_workbook(file) # 打开excel   一个excel里面可能包含多个sheet
    print(xlsfile.sheetnames)
    sheet1 = xlsfile[xlsfile.sheetnames[0]] # 选取第1个sheet
#     print(sheet1['H28'].value)
#     print(sheet1['H29'].value)
    p = int(index / 3)
    sheet1['H28'].value = dateDict[p][0] # 更新指定工作簿的单元格中的日期
    sheet1['H29'].value = dateDict[p][1] # 更新指定工作簿的单元格中的日期
    
    sheet2 = xlsfile[xlsfile.sheetnames[1]] # 选取第2个sheet
    sheet2['C3'].value = dateDict[p][0] # 更新第二个工作簿的c3单元格的值
    print(sheet2['C3'].value)
    
    xlsfile.save(file) # 保存上述更新

for index,file in enumerate(file_list): # 循环遍历文件夹
    print(index)
    update_date(file_root + file,index)
```


