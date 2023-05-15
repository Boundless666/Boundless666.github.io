##### 配置中心

配置中心服务器	//在集群中很有用   统一配置  只需要改配置中心的配置就行

本地环境变量

本地配置文件



按照上方的顺序添加配置  由于后面的会覆盖掉前面的

所以优先级最高的为**本地配置文件**   最低的为**配置中心服务器**

这样做的好处是 若需要在某一台应用上单独配置  只需要在那台应用的本地配置一下配置文件  不会对其它的造成影响

###### ConfigServices

新增

```c#
public interface IConfigReader
{
    string? GetValue(string name);
}

internal class CenterConfigImpl : IConfigReader
{
    private readonly IEnumerable<IConfigService> services;

    public CenterConfigImpl(IEnumerable<IConfigService> services)
    {
        this.services = services;
    }

    public string? GetValue(string name)
    {
        string value = null;
        foreach(var service in services)
        {
            var newVal = service.GetValue(name);
            if (newVal != null) //若下一个 Config实现中有此配置 就会更新值   越后面注册的配置优先级越高
                value = newVal;
        }
        return value;
    }
}
```

```c#
public static class ConfigServiceExtend
{
    public static IServiceCollection AddConfigService(this IServiceCollection services,string filename)
    {
        return services
            .AddScoped<IConfigService, EnvVarConfigImpl>()
            .AddScoped(typeof(IConfigService), sp => new IniFileConfigImpl() { FilePath = filename })
            .AddScoped<IConfigReader, CenterConfigImpl>(); //修改这里
    }
}
```



###### MailServices

```c#
public class MailImpl : IMailService
{
    private readonly ILogService logService;
    private readonly IConfigReader configService; //修改这里

    public MailImpl(IConfigReader configService, ILogService logService)
    {
        this.configService = configService;
        this.logService = logService;
    }

    public void Send(string title, string to, string body)
    {
        this.logService.LogInfo("开始发送...");
        var addr = this.configService.GetValue("addr");
        var username = this.configService.GetValue("username");
        var password = this.configService.GetValue("password");
        Console.WriteLine($"配置信息:{addr},{username},{password}");
        Console.WriteLine($"发送信息:{title},{to},{body}");
        this.logService.LogInfo("发送完成");
    }
}
```



###### 完整代码

[ConsoleAppMailSender/Program.cs · 无涯/growth_c-sharp_2023 - 码云 - 开源中国 (gitee.com)](https://gitee.com/giteemxl/growth_c-sharp_2023/blob/master/ConsoleAppMailSender/Program.cs)
