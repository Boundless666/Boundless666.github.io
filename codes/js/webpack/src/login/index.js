/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-24 20:51:24
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-24 22:10:47
 * @FilePath: index.js
 */
import {checkPhone, checkCode} from '../utils/check.js'

console.log(checkPhone("1111111111"));
console.log(checkCode("abcde1"));

document.querySelector(".btn").addEventListener("click", ()=> {
    const phone = document.querySelector(".login-form [name=phone]").value
    const code = document.querySelector(".login-form [name=code]").value
    if(!checkPhone(phone)){
        console.log("你输入的手机号长度不对");
        return
    }
    if(!checkCode(code)){
        console.log("你的验证码不对");
        return
    }

    console.log("提交请求到服务器...");
})

import 'bootstrap/dist/css/bootstrap.min.css'
import './index.css'