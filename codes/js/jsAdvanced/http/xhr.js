/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-23 19:29:03
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-23 19:32:03
 * @FilePath: xhr.js
 */
const xhr = new XMLHttpRequest()
xhr.open("GET", "api_url")
xhr.addEventListener("loadend",()=>{
    // do something when server response after.
})
// send request.
xhr.send()