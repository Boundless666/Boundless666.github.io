###### ConfigServices

新增一个扩展  注意**命名空间**

```c#
using ConfigServices;

namespace Microsoft.Extensions.DependencyInjection
{
    public static class ConfigServiceExtend
    {
        public static IServiceCollection AddConfigService(this IServiceCollection services,string filename)
        {
            return services
                .AddScoped<IConfigService, EnvVarConfigImpl>()//下方还有一个IConfigService  这个会被下方的覆盖掉
                .AddScoped(typeof(IConfigService), sp => new IniFileConfigImpl() { FilePath = filename });
        }
    }
}
```



###### LogServices

```c#
using LogServices;

namespace Microsoft.Extensions.DependencyInjection
{
    public static class LogServiceExtend
    {
        public static IServiceCollection AddLogService(this IServiceCollection services)
        {
            return services.AddScoped<ILogService, ConsoleLogImpl>();
        }
    }
}
```



###### MailServices

```c#
using MailServices;

namespace Microsoft.Extensions.DependencyInjection
{
    public static class MailServiceExtend
    {
        public static IServiceCollection AddMailService(this IServiceCollection services)
        {
            return services.AddScoped<IMailService, MailImpl>();
        }
    }
}
```



###### ConsoleAppMailSender

```c#
using MailServices;	//你会发现这一版相对于第一版  少了一些引用  就是少了对具体实现类的引用
using Microsoft.Extensions.DependencyInjection;

IServiceCollection services = new ServiceCollection();
services.AddLogService(); //调用扩展就行
services.AddConfigService("mail.ini");
services.AddMailService();

using(var serviceProvider= services.BuildServiceProvider())
{
    var mailService = serviceProvider.GetRequiredService<IMailService>();
    mailService.Send("Hello", "future", "nice to meet you");
}
```