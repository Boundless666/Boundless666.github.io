![image-20230428083455376](D:\documents\computer\computer\docs\public\assets\image-20230428083455376.png)



PLC工具手动模拟发送任务  ---》 产生一条**WCS_PlanTask**消息到MQ队列中 ---》Wcs.Service 消费

Wcs.Service 轮询查看有没有未处理的任务 ---》 推送给WMS 更新任务处理状态 ---》





![image-20230430134719657](D:\documents\computer\computer\docs\public\assets\image-20230430134719657.png)

