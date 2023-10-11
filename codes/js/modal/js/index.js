/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-20 20:16:05
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-22 00:10:17
 * @FilePath: index.js
 */
function Modal(title, msg){
    // 创建模态框
    this.modalDiv = document.createElement("div");
    this.modalDiv.className = "modal";
    this.modalDiv.innerHTML = `
        <div class="title">${title}<i>X</i></div>
        <div class="msg">${msg}</div>
    `;
}

Modal.prototype.open = function(){
    // 防止出现多个模态框
    const hasModal = document.querySelector(".modal");
    hasModal && hasModal.remove();

    document.body.append(this.modalDiv);

    this.modalDiv.querySelector("i").addEventListener("click",()=>{
        this.close();
    })
}

Modal.prototype.close = function(){
    this.modalDiv.remove();
}

// 因为脚本在html前加载 此时页面中还没有add元素 所以需要load时再绑定事件
window.addEventListener('load',()=>{
    document.querySelector(".add").addEventListener("click", () => {
        new Modal("添加提示","这是一条添加提示").open();
    })
    
    document.querySelector(".del").addEventListener("click", () => {
        new Modal("删除提示","这是一条删除提示").open();
    })
})