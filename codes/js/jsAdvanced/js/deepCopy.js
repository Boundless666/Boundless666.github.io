/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-09-20 21:26:51
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-20 21:48:35
 * @FilePath: deepCopy.js
 */
// 1. copy reference address.
// const o = {
//     uname: "history",
//     age: 18
// }

// const obj = o;
// o.age = 19;
// console.log("1. copy reference address");
// console.log(o.age);
// console.log(obj.age);

// 2. shallow copy.
// const o = {
//     uname: "history",
//     age: 18,
//     hobby: ['eating food', 'play games']
// }

// const obj = {...o}; // Object.assign(obj, o)
// o.age = 19;
// o.hobby[0] = "lala";
// console.log("2. shallow copy");
// console.log(o);
// console.log(obj);

// 3. deep copy.
const o = {
    uname: "history",
    age: 18,
    hobby: ['eating food', 'play games'],
    family: {
        mother: "a mother",
        wife: "a girl",
    }
}

const obj = {};
deepCopy(obj, o);
o.age = 19;
o.hobby[0] = "lala";
o.family.wife = "girl";
console.log("3. deep copy");
console.log(o);
console.log(obj);

// function deepCopy(newObj, oldObj){
//     for(let k in oldObj){
//         if(oldObj[k] instanceof Array){
//             newObj[k] = []
//             deepCopy(newObj[k], oldObj[k])
//         }else
//             newObj[k] = oldObj[k];
//     }
// }

// need handle Object property in Object o
function deepCopy(newObj, oldObj){
    for(let k in oldObj){
        if(oldObj[k] instanceof Array){
            newObj[k] = []
            deepCopy(newObj[k], oldObj[k])
        }else if(oldObj[k] instanceof Object){
            newObj[k] = {}
            deepCopy(newObj[k], oldObj[k])
        }else
            newObj[k] = oldObj[k];
    }
}