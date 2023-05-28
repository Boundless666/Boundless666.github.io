#### SQL分类

1. DDL(Data Definition Language)

   > CREATE \ ALTER \ DROP \ TRUNCATE \ RENAME

2. DML(Data Manipulation Language)

   > INSERT \ UPDATE \ DELETE \ SELECT

3. DCL(Data Control Language)

   > COMMIT \ ROLLBACK \ SAVEPOINT \ GRANT \ REVOKE



#### 约束

##### 什么是约束

约束是一种表级条件限定

##### 为什么需要约束

为了保证数据的完整性 防止数据库中出现不符合语义规定的数据以及防止因错误信息的输入输出造成无效操作或错误信息。

从以下四个方面考虑数据的完整性:

> 1. 实体完整性(Entity Integrity)  如：同一个表中不能存在两条一样的数据
> 2. 域完整性(Domain Integrity)  如：年龄的范围应该在一定的范围内
> 3. 引用完整性(Referential Integrity)  如：员工表中的部门id要在部门表中找到
> 4. 用户自定义完整性(User-defined Integrity)  如：某些字段不能为空 用户名 密码这些

##### 有哪些约束

1. NOT NULL  非空约束  某个字段不为空
2. UNIQUE  唯一约束  某列不能存在相同值
3. PRIMARY KEY  主键约束(自带唯一约束)
4. FORIGN KEY  外键约束
5. CHECK  检查约束  检查某个字段值是否符合一定的要求 参考域完整性
6. DEFAULT  默认约束  某个字段若未赋值则由设置的默认值填补

#### 视图

##### 什么是视图

一种虚拟表，本身不具有数据 占用很少的内存空间

建立在已有表的基础之上

##### 为什么使用视图

可以帮助我们使用表的一部分 而不是表的全部

可以做更细粒度的权限控制

在大型数据库中挺有用

#### 存储过程

##### 什么是存储过程

Stored Procedure一组`预先编译`的SQL语句的封装

存储在数据库服务器上  客户端使用的时候只需要调用相应的执行命令即可

##### 存储过程的优点

1. 简化操作 提高SQL语句的复用性
2. 减少操作过程的失误
3. 减少网络传输消耗  客户端不需要传输很长的SQL
4. 减少SQL暴露的风险 提高了数据操作的安全性