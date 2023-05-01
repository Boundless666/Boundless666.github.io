```c
# ErLang 20.2
# RabbitMQ 3.7.3
```

[Otp 20.2 - Erlang/OTP](https://www.erlang.org/patches/otp-20.2)

> 本文以 erlang.exe 方式安装

在安装过程中注意安装文件路径位置 后续需要在环境变量中配置

1. 进入环境变量 在系统变量中新增变量 变量名:ERLANG_HOME  变量值:上一步安装的路径目录

2. 将下方的内容添加到Path中

   ```c
   %ERLANG_HOME%\bin
   ```

   



##### 安装Rabbit MQ

> 以 exe 方式安装

1. 安装完成后 cmd进入安装目录下的sbin/

2. 输入

   ```shell
   rabbitmq-plugins enable rabbitmq_management
   ```

3. 输入

   ```shell
   rabbitmqctl status #查看状态
   ```

**报错很有可能 由于elang.cookie 与 rabbit mq依赖的elang.cookie这两个文件不一致**

将 C:\Windows\System32\config\systemprofile\\.erlang.cookie 复制一份到

C:\Users\Administrator\\.erlang.cookie

再次执行rabbitmqctl status就行了