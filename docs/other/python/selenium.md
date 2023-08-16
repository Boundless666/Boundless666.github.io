```python
from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.by import By
import time
import pandas
from selenium.webdriver.support.wait import WebDriverWait

url='https://www3.hkexnews.hk/sdw/search/searchsdw_c.aspx'
file = 'D:\桌面\sheet.xlsx'

df = pandas.read_excel(file,sheet_name="Sheet1") # 第二个参数是读取excel里面的第一个工作簿

driver = webdriver.Edge()

# 防止被监测出是爬虫
driver.execute_cdp_cmd("Page.addScriptToEvaluateOnNewDocument", {
    "source": """
    Object.defineProperty(navigator, 'webdriver', {
      get: () => undefined
    })
  """
})


# 上述是模拟一个用户查询一个股票代码的操作
# 下面就是将查询后的网页中的数据读取出来
# 当前页面只有一个table标签
def hasReady(driver):
    data_input = driver.find_element(By.ID, "txtShareholdingDate")
    if(len(data_input.text)>0):
        return False
    return  True

def setAttribute(driver, elementobj, attributeName, value):
    '''
    封装设置页面对象的属性值的方法
    调用JS代码修改页面元素的属性值，arguments[0]~arguments[1]分别
    会用后面的element，attributeName和value参数进行替换
    '''
    driver.execute_script("arguments[0].setAttribute(arguments[1],arguments[2])", elementobj, attributeName, value)

res = []
def spider(code):
    js = "document.getElementById('txtShareholdingDate').removeAttribute('readonly')"
    driver.execute_script(js) #执行脚本  脚本中是删除日历的只读属性
    stockCode_input = driver.find_element(By.ID, "txtStockCode")  # 获取股票代码输入框

    clickable = driver.find_element(By.ID, "btnSearch")  # 获取搜索按钮
    date_input = driver.find_element(By.ID, "txtShareholdingDate")  # 获取日期输入框
    # date_input.send_keys("2023/6/30")  # 模拟向日期输入框输入值
    setAttribute(driver, date_input, 'value', '2023/06/30')
    setAttribute(driver, date_input, 'data-reset', '2023/06/30')

    stockCode_input.send_keys(code)  # 模拟向股票输入框输入值
    print(f"输入code:{code} 当前日期:{date_input.get_property('value')}\n")

    ActionChains(driver) \
        .click(clickable) \
        .perform()  # 执行点击搜索动作
    print(f"执行点击\n")
    trs = driver.find_elements(By.CSS_SELECTOR, "#pnlResultNormal tbody tr") # 获取下方显示的详细持股量数据 一个集合
    sum = 0
    for tr in trs:
        tds = tr.find_elements(By.TAG_NAME, "td") # 找到这一行的几个格子
        sum = sum + int(tds[3].text.replace(",","")) # 第4个格子的内容是持股量数据 做累加操作
    res.append(sum) # 追加到一个集合中 (这个集合作为最后一列 也就是持股量那一列)
    print(f"统计完成{(code,sum)}\n")

for index,row in df.iterrows():
    driver.get(url)
    WebDriverWait(driver, timeout=10).until(hasReady)
    spider(int(row[4]))
    #spider(int(row[4])) # 索引从0开始 4是第五列
    #time.sleep(1)

if 'SUM(持股量)' in df.columns:
    df['SUM(持股量)'] = res
else:
    df.insert(loc=5, column='SUM(持股量)', value=res)
df = df.reset_index(drop=True)
print(df)
df = df[['行业','SUM(持股量)']]
df.to_excel('D:\桌面\sheet结果.xlsx',index=False)

time.sleep(15) # 执行完上述步骤后停留15s
driver.quit()
```

