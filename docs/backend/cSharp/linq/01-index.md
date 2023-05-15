##### IEnumerable

> 可枚举类型

```c#
using Test;

foreach (var str in Temp.GetStrings())
    Console.WriteLine(str);

namespace Test
{
    public class Temp
    {
        internal static IEnumerable<string> GetStrings()
        {
            yield return "hello";
            yield return "mxl";
            yield return "atman.wiki";
        }
    }
}
```

yield 顺序迭代



##### 扩展Linq

```c#
// ...
var res = Temp.GetStrings().CWhere(c => c.Length < 4);
foreach(var item in res)
    Console.WriteLine(item);

namespace Test
{
    //...
    public static class TempExtend
    {
        internal static IEnumerable<string> CWhere(this IEnumerable<string> enums, Func<string, bool> func)
        {
            foreach(var item in enums)
            {
                if (func(item))
                    yield return item;
            }
        }
    }
}
```



泛型扩展

```c#
// ...
var secRes = Temp.GetStrings().CWhere<string>(c => c.Length > 4);
foreach(var item in secRes)
    Console.WriteLine(item);

namespace Test
{
    //...
    public static class TempExtend
    {
        internal static IEnumerable<T> CWhere<T>(this IEnumerable<T> enums, Func<T, bool> func)
        {
            foreach (var item in enums)
            {
                if (func(item))
                    yield return item;
            }
        }
    }
}
```

###### 完整代码

[LinqDemo/AIndex/AIndex.cs · 无涯/growth_c-sharp_2023 - 码云 - 开源中国 (gitee.com)](https://gitee.com/giteemxl/growth_c-sharp_2023/blob/master/LinqDemo/AIndex/AIndex.cs)
