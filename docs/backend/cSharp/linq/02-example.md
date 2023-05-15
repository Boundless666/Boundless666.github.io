1. ##### 分割字符串

   > 有一个用逗号分隔的表示成绩的字符串，如
   >
   > "61,90,100,99,18,22,38,66,80,93,55,50,89"
   >
   > 计算这些成绩的平均值

   ```c#
   string exStr = "61,90,100,99,18,22,38,66,80,93,55,50,89";
   var res = exStr.Split(',').Select(s => Convert.ToInt32(s)).Average();
   Console.WriteLine(res);
   ```

   

2. ##### 频率统计

   > 统计一个字符串中每个字母出现的频率（忽略大小写）
   >
   > 然后按照从高到低的顺序输出出现频率高于2次的单词和其出现的频率。
   >
   > "Hello world! My name is hah. hey huo"
   >
   ```c#
   string exStr = "Hello world! My name is hah. hey huo";
   var res = exStr.Where(c => char.IsLetter(c))
       .Select(c => char.ToLower(c))
       .GroupBy(c => c)
       .Select(g => new { g.Key, Count = g.Count() })
       .OrderByDescending(g => g.Count)
       .Where(g => g.Count > 2);
   foreach(var item in res)
       Console.WriteLine($"key:{item.Key} \t count:{item.Count}");
   ```

