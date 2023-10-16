`事务`中的并发性问题:`脏读`、`可重复读`、`幻读`



##### 脏读

|                     事务A                     |                  事务B                   |
| :-------------------------------------------: | :--------------------------------------: |
|                    begin;                     |                                          |
|                                               |                  begin;                  |
|                                               | update set salary = 90 where name ='aaa' |
| select salary from employee where name ='aaa' |                                          |
|                    commit;                    |                                          |
|                                               |                 commit;                  |



此时事务A读了事务B未提交的数据

没有保证事务的隔离性

##### 可重复读

|                     事务A                     |                      事务B                      |
| :-------------------------------------------: | :---------------------------------------------: |
|                    begin;                     |                                                 |
| select salary from emplyee where name ='aaa'  |                                                 |
|                `此时工资是100`                |                                                 |
|                                               |                     begin;                      |
|                                               | update set salary = salary-10 where name ='aaa' |
|                                               |                     commit;                     |
| select salary from employee where name ='aaa' |                                                 |
|                `此时工资是90`                 |                                                 |
|                    commit                     |                                                 |

此时事务A读了事务B已提交的数据

没有保证事务的一致性

##### 幻读

|                 事务A                  |                         事务B                          |
| :------------------------------------: | :----------------------------------------------------: |
|                 begin;                 |                                                        |
| select * from employee where id >= '2' |                                                        |
|       `返回salary为2、3两条数据`       |                                                        |
|                                        |                         begin;                         |
|                                        | insert into employee(id,name,salary) value(4,'bbb',60) |
|                                        |                        commit;                         |
| select * from employee where id >= '2' |                                                        |
|     `返回salary为2、3、4三条数据`      |                                                        |
|                commit;                 |                                                        |

> 如何解决上述问题? :arrow_down:



##### 四大隔离级别

|          | 脏读 | 可重复读 | 幻读 |
| :------: | :--: | :------: | :--: |
| 读未提交 |  √   |    √     |  √   |
| 读已提交 |  ×   |    √     |  √   |
| 可重复读 |  ×   |    ×     |  √   |
|  串行化  |  ×   |    ×     |  ×   |



貌似串行化解决了问题...

但是 这里存在一些副作用

串行化是通过`加锁`的方式实现的

加上锁  性能问题就无法避免(比如读取数据时就无法修改、修改时就无法读取)

有么有更好的办法?

##### MVCC

> Multi-Version Concurrency Control

多版本并发控制