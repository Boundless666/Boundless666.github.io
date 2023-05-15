模拟一个邮件服务

> 可以发送邮件
>
> 发送邮件时进行日志记录
>
> 发送邮件前需要读取相应的配置

###### ConfigServices

```c#
public interface IConfigService
{
    string GetVaule(string name);
}

public class EnvVarConfigImpl : IConfigService
{
    public string GetValue(string name)
    {
        return Environment.GetEnvironmentVariable(name);
    }
}
```

###### LogServices

```c#
public interface ILogService
{
    void LogInfo(string msg);

    void LogError(string msg);
}

public class ConsoleLogImpl : ILogService
{
    public void LogError(string msg)
    {
        Console.WriteLine($"Log Error:{msg}");
    }

    public void LogInfo(string msg)
    {
        Console.WriteLine($"Log Info:{msg}");
    }
}
```

###### MailServices

```c#
public interface IMailService
{
    void Send(string title, string to, string body);
}

public class MailImpl : IMailService
{
    private readonly ILogService logService;
    private readonly IConfigService configService;

    public MailImpl(IConfigService configService, ILogService logService)
    {
        this.configService = configService;
        this.logService = logService;
    }

    public void Send(string title, string to, string body)
    {
        this.logService.LogInfo("开始发送...");
        var addr = this.configService.GetValue("addr");
        var username = this.configService.GetValue("userName");
        var password = this.configService.GetValue("password");
        Console.WriteLine($"配置信息:{addr},{username},{password}");
        Console.WriteLine($"发送信息:{title},{to},{body}");
        this.logService.LogInfo("发送完成");
    }
}
```

###### ConsoleAppMailSender 控制台模拟发送

```c#
using ConfigServices;
using LogServices;
using MailServices;
using Microsoft.Extensions.DependencyInjection;

//下面这一坨是顶级语句的写法  没有命名空间 和 Main这些   但是这些最终都会包含在Main中
ServiceCollection services = new ServiceCollection();
services.AddScoped<ILogService, ConsoleLogImpl>();
services.AddScoped<IConfigService, EnvVarConfigImpl>();
services.AddScoped<IMailService, MailImpl>();

using(var serviceProvider= services.BuildServiceProvider())
{
    var mailService = serviceProvider.GetRequiredService<IMailService>();
    mailService.Send("Hello", "future", "nice to meet you");
}
```



依赖注入并不止于此...

你会发现在**ConsoleAppMailSender**中同时引入了Service以及相应的实现

那这依然没有做到解耦  **应该依赖于其抽象而不依赖其具体**

解决方案在下一篇