function auto(){
  var tableArr = document.querySelectorAll('#right .dataTable')
  if(!tableArr || tableArr.length != 2)
    return;
  const trArr = tableArr[1].getElementsByTagName("tr")
  // for(var i=1; i < trArr.length; i++){
  //   var td = trArr[i].querySelector("td:nth-child(3)");
  //   td.querySelector("a").onclick();
  // }
  // const progress = trArr[1].querySelector(".jindu")
  // const pArr = progress.title.split('/')
  // const curProgress = parseInt(pArr[0])
  // const allProgress = parseInt(pArr[1])
  // if(curProgress < allProgress){
  //   trArr[1].querySelector('a').onclick()
  // }
  autoPlay(trArr)
}

function autoPlay(trArr){
  const progress = trArr[1].querySelector(".jindu")
  const pArr = progress.title.split('/')
  const curProgress = parseInt(pArr[0])
  const allProgress = parseInt(pArr[1])
  if(curProgress < allProgress){
    trArr[1].querySelector('a').onclick()
  }

  const delay = (allProgress - curProgress) * 60 * 1000 + 10000;
  console.log(allProgress, curProgress, delay)
  if(trArr.length == 1)
    return;
  trArr.splice(0, 1)
  console.log(`output->trArr`,trArr)
  setTimeout(()=>{
    autoPlay(trArr)
  },delay)
}

function playVideo(){
  const ifm = document.querySelector('#course_frame')
  const doc = ifm.contentWindow.document;
  const mask = doc.querySelector(".continue")
  if(!mask)
    return;
  setTimeout(() => {
    mask.lastElementChild.click()
  }, 2000);
}

function openNewPage(){
  const ifm = document.querySelector('c>iframe')
  if(!ifm)
    return;
  window.location = ifm.src
}

window.addEventListener('load',()=>{
  auto()
  openNewPage()
  playVideo()
})