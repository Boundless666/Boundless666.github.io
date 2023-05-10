双色球 demo

同时间段内产生 6 个红色不重复的小球号码 以及一个蓝色的小球号码

```c#
private readonly string[] redNumbers = new string[] { "01", "02", "03", "04", "05",
    "06", "07", "08", "09", "10", "11",
    "12", "13", "14", "15", "16", "17",
    "18", "19", "20", "21", "22", "23"};

private readonly string[] blueNumbers = new string[] { "01", "02", "03", "04", "05",
    "06", "07", "08", "09", "10", "11",
    "12", "13", "14", "15", "16"};
```

```c#
private void Start()
{
    TaskFactory taskFactory = new TaskFactory();
    foreach(var control in this.groupBox1.Controls)
    {
        if(control is Label lab)
        {
            if (lab.Name.Contains("Blue"))
            {
                taskFactory.StartNew(() =>
                {
                    while (true)
                    {
                        var res = GetNumber(blueNumbers);//假设这是一个比较耗时的任务
                        lab.Text = redNumbers[res];
                    }
                });
            }
            else if (lab.Name.Contains("Red"))
            {
                taskFactory.StartNew(() =>
                {
                    while (true)
                    {
                        var res = GetNumber(redNumbers);//假设这是一个比较耗时的任务
                        lab.Text = redNumbers[res];	//.net中会有线程间操作无效的问题 在下文描述如何解决
                    }
                });
            }
        }
    }
}
private int GetNumber(string[] arrs)
{
    Random r = new Random(GetRandomSeed());
    int index = r.Next(0, arrs.Length);
    Thread.Sleep(r.Next(500, 1500));
    return index;
}

private int GetRandomSeed()
{
    byte[] buffer = Guid.NewGuid().ToByteArray();
    int iSeed = BitConverter.ToInt32(buffer, 0);
    return iSeed;
}
```

##### 线程间操作无效问题

[如何对控件进行线程安全的调用 - Windows Forms .NET | Microsoft Learn](https://learn.microsoft.com/zh-cn/dotnet/desktop/winforms/controls/how-to-make-thread-safe-calls?view=netdesktop-7.0#safe-cross-thread-calls)

```c#
...
while (true)
{
    var resIndex = GetNumber(blueNumbers);//假设这是一个比较耗时的任务
    WriteTextSafe(lab, blueNumbers[resIndex]);
}
...


private void WriteTextSafe(Label lab, string text)
{
    if (lab.InvokeRequired)
    {
        lab.Invoke(() =>
        {
            lab.Text = text;
        });
    }
    else
        lab.Text = text;
}
```

##### 控制停止

> |            | 开始按钮状态 |                              | 停止按钮状态 |
> | ---------- | :----------: | :--------------------------: | :----------: |
> | 默认无操作 |     启用     |                              |     禁用     |
> | 点击开始   |     禁用     | --》所有球号码都生成之后--》 |     启用     |
> | 点击结束   |     启用     |   《--所有线程都停止后《--   |     禁用     |

```c#
private void Start(){
    ResetLabels();
    btnStart.Enabled = false;	//点击开始后  开始按钮被禁用

    ...
        else if (lab.Name.Contains("Red"))
        {
            taskFactory.StartNew(() =>
            {
                while (!btnStart.Enabled)
                {
                    var resIndex = GetNumber(redNumbers);//假设这是一个比较耗时的任务
                    if (IsRedExists(redNumbers[resIndex])) //红色号码球去重处理  如果存在就再随机一个号码
                    {
                        continue;
                    }
                    WriteTextSafe(lab, redNumbers[resIndex]);
                }
            });
        }
    ...

    // 运行工作线程  后台一直判断:  如果7个号码都开始产生出来了(都不为初始值)  那么此时 停止按钮启用
    Task.Run(() =>
    {
        while(!btnStop.Enabled)
        {
            if (!IsRedExists("00") && !labBlue01.Text.Equals("00"))
                BtnStatusSafe(btnStop, true);
        }
    });
}

private bool IsRedExists(string number)
{
    foreach(var control in groupBox1.Controls)
    {
        if (control is Label lbl
            && lbl.Name.Contains("Red")
            && lbl.Text.Equals(number))
            return true;
    }
    return false;
}

private void BtnStatusSafe(Button btn, bool status)
{
    if (btn.InvokeRequired)
        btn.Invoke(() =>
        {
            btn.Enabled = status;
        });
    else
        btn.Enabled = status;
}

private void btnStop_Click(object sender, EventArgs e)
{
    btnStop.Enabled = false;
    btnStart.Enabled = true;
}
```

... 还没完 ...

生成一堆号码后...展示结果

此时还会有新的问题

> 1. 未处理红色去重
>
> 2. 点击停止 线程 while 循环停止 但是循环里面的还有可能继续执行 导致停止时的数据 与展示的数据不一致

有好几处改动 未贴代码...去我的仓库里面看吧

完整项目代码:

[MultipleThreadDemo/Form1.cs · 无涯/growth_c-sharp_2023 - 码云 - 开源中国 (gitee.com)](https://gitee.com/giteemxl/growth_c-sharp_2023/blob/master/MultipleThreadDemo/Form1.cs)

##### Random 生成随机数重复

[(4 条消息) 解决 C# Random 生成随机数重复的问题\_c# random 重复\_zhenufo 的博客-CSDN 博客](https://blog.csdn.net/zhenufo/article/details/79373124)
