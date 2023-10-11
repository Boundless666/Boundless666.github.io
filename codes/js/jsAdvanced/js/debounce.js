/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-21 23:17:08
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-23 00:11:02
 * @FilePath: debounce.js
 */
/**
 * only execute once finally in wait time.
 * @param {exec fun} fun 
 * @param {wait mill-seconds} wait 
 */
function debounce(fun, wait){
    let timer = null;
    return function(){
        timer && clearTimeout(timer);
        timer = setTimeout(()=>{
            fun()
        }, wait)
    }
}

function Label(msg){
    this.labelEle = document.createElement("label");
    this.labelEle.className = "create " + (msg == "" ? "success" : "error")
    this.labelEle.innerText = `${msg}`
}
Label.prototype.open = function(){
    const isExist = document.querySelector(".create")
    isExist && isExist.remove()

    return this.labelEle;
}

function validate(){
    const val = this.value
    console.log(val);
    const regx = /^(13[0-9]|15[0-35-9]|17[0-8]|19[0-35-9])\d{8}$/
    let tipMsg = ""
    if(val == "")
        tipMsg = "手机号不能为空"
    else if(!regx.test(val))
        tipMsg = "手机号不合法"
    console.log(regx.test(val));
    this.parentNode.append(new Label(tipMsg).open())
}
window.addEventListener("load",function(){
    const input = document.querySelector("#input")
    validate = validate.bind(input)
    input.addEventListener("input",debounce(validate, 300))
})
