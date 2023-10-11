const obj = {
    age: 18
}

function test(x, y){
    console.log(this);
    console.log(x, y);
}
// 1. call
// test()
// test.call(obj, 12, 30)

// 2. apply
// test.apply(obj, [12, 30])

// 3. bind
// bind this that in call function pointer to obj

// window.addEventListener("load",function(){
//     document.querySelector(".btn").addEventListener("click", function(){
//         this.disabled = true;
//         Window.setTimeout(function(){
//             this.disabled = false;  // this pointer to Window
//         }, 2000)
//     })
// })

window.addEventListener("load",function(){
    document.querySelector(".btn").addEventListener("click", function(){
        this.disabled = true;
        setTimeout(function(){
            this.disabled = false;
        }.bind(this), 2000)
    })
})