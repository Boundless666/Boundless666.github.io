/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-22 22:27:58
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-23 00:17:04
 * @FilePath: throttle.js
 */
function throttle(fun, wait){
    let timer = null;
    return function(){
        if(!timer){
            timer = setTimeout(function(){
                fun()
                timer = null
            }, wait)
        }
    }
}

function addHandle(){
    console.log(this);
    iLab = this.nextElementSibling.children[0]
    iLab.innerText = parseInt(iLab.innerText) + 1;
}


window.addEventListener("load",()=>{
    // document.querySelector(".add").addEventListener("click",function(){
    //     addHandle = addHandle.bind(this)
    //     throttle(addHandle,3000)
    // })
    const btn = document.querySelector(".add")
    addHandle = addHandle.bind(btn)
    btn.addEventListener("click",throttle(addHandle,2000))
})