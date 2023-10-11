/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-23 19:32:10
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-23 19:54:09
 * @FilePath: customAxios.js
 */

function MyAxios(config){
    return new Promise((resolve, reject)=>{
        // 一个http请求对象
        const xhr = new XMLHttpRequest()

        if(config.params){
            const paramsObj = new URLSearchParams(config.params)
            const queryString = paramsObj.toString()
            config.url = config.url + `?${queryString}`
        }

        // 以GET方式请求config.url这个路径
        xhr.open(config.method || "GET", config.url)

        // 服务器响应后的操作
        xhr.addEventListener("loadend", ()=>{
            if(xhr.status >= 200 && xhr.status <300)
                resolve(JSON.parse(xhr.response))
            else
                reject(new Error(xhr.response))
        })

        // 发起请求
        if(config.data){ // 如果请求体传递了参数
            const jsonStr = JSON.stringify(config.data)
            xhr.setRequestHeader("Content-Type", "application/json")
            xhr.send(jsonStr)
        }else{
            xhr.send()
        }
    })
}

MyAxios({url:"https://hmajax.itheima.net/api/register"})
    .then(result =>{
        console.log(result);
    }).catch(result =>{
        console.log(result);
    })