```c#
using System.Diagnostics;
using Temp;

string[] files = Directory.GetFiles("./files");
CancellationTokenSource cts = new CancellationTokenSource();
List<Task<int>> taskList = new List<Task<int>>();
Stopwatch stopwatch = new Stopwatch();
stopwatch.Start();
foreach (var filename in files)
{
    taskList.Add(TempClass.StatisticCharCounts(filename, cts.Token));
}
var resArr = await Task.WhenAll(taskList.ToArray());//等待所有任务完成
var res = resArr.Sum();
Console.WriteLine($"{res}");
//while(Console.ReadLine() != "q") { }
//cts.Cancel();
stopwatch.Stop();
Console.WriteLine($"耗时: {stopwatch.ElapsedMilliseconds} ms");
Console.ReadLine();

namespace Temp
{
    class TempClass
    {
        internal static async Task<int> StatisticCharCounts(string filename, CancellationToken token)
        {
            Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId}");
            string text =await File.ReadAllTextAsync(filename,token);
            Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId}");
            await Task.Delay(3000);//模拟耗时任务
            Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId}");
            return text.Length;
        }
    }
}
```



完整代码:

[asyncDemo/Program.cs · 无涯/growth_c-sharp_2023 - 码云 - 开源中国 (gitee.com)](https://gitee.com/giteemxl/growth_c-sharp_2023/blob/master/asyncDemo/Program.cs)
