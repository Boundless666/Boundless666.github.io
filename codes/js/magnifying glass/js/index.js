window.addEventListener('load', () => {
    // 1. 设置鼠标移入时显示遮罩层 以及右边放大图片
    var preview_img = document.querySelector('.preview_img');
    var magnify_img = document.querySelector('.magnify_img');
    var mask = preview_img.querySelector('.mask');
    var img = magnify_img.querySelector('.img');
    preview_img.addEventListener('mouseover', () =>{
        mask.style.display = 'block';
        magnify_img.style.display = 'block';
    })
    preview_img.addEventListener('mouseout', () =>{
        mask.style.display = 'none';
        magnify_img.style.display = 'none';
    })

    // 2. 设置移动遮罩层处理
    preview_img.addEventListener('mousemove', function(e){
        // 鼠标在预览盒子中的距离
        let x = e.pageX - this.offsetLeft;
        let y = e.pageY - this.offsetTop;
        
        // 计算盒子偏移距离
        let maskX = x - mask.offsetWidth / 2;
        let maskY = y - mask.offsetHeight / 2;
        if(maskX <= 0)
            maskX = 0;
        else if(maskX >= this.offsetWidth - mask.offsetWidth)
            maskX = this.offsetWidth - mask.offsetWidth;
        if(maskY <= 0)
            maskY = 0;
        else if(maskY >= this.offsetHeight - mask.offsetHeight)
            maskY = this.offsetHeight - mask.offsetHeight;
        mask.style.left = maskX + 'px';
        mask.style.top = maskY + 'px';

        // 3. 设置右边盒子中图片随着遮罩层移动 反向 移动
        // 计算公式: 遮罩层偏移比例  == 右边大图反向偏移比例
        // 遮罩层偏移比例 = 遮罩层移动距离 / 遮罩层最大可移动距离
        // 右边大图反向偏移比例 = 大图移动距离 / 大图最大可移动距离 * -1
        // 大图移动距离 = 遮罩层移动距离 * 大图最大可移动距离 / 遮罩层最大可移动距离 * -1
        let bigX = img.offsetWidth - magnify_img.offsetWidth;
        let bigY = img.offsetHeight - magnify_img.offsetHeight;

        let bigOffsetX = maskX * bigX / (this.offsetWidth - mask.offsetWidth) * -1;
        let bigOffsetY = maskY * bigY / (this.offsetHeight - mask.offsetHeight) * -1;
        img.style.left = bigOffsetX + 'px';
        img.style.top = bigOffsetY + 'px';
    })
})