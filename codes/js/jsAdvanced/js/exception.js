/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-20 21:53:59
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-20 22:03:25
 * @FilePath: exception.js
 */
function test(x, y){
    try {
        const p = document.querySelector(".notExist")
        p.style.color = "red"
    } catch (error) {
        console.log("aa");
        throw new Error("occur an exception")
    }
    finally{
        alert("一个弹框")
    }
    console.log("a log record after finally sentence");
}

test()