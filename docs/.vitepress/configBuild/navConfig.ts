/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-05-31 23:05:37
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-17 11:20:06
 * @FilePath: navConfig.ts
 */
import { DefaultTheme } from "vitepress";

/**
 * 导航配置  只有在这里面配置大模块  才会去读取相应模块下面的文件
 * @returns 导航项数组
 */
const NavConfig = (): DefaultTheme.NavItem[] => {
  return [
    { text: "Home", link: "/" },
    {
      text: "c 语言",
      link: "/computer_basic/c_language/",
      activeMatch: "/computer_basic/c_language",
    },
    {
      text: "c#",
      link: "/backend/cSharp/",
      activeMatch: "/backend/cSharp",
    },
    {
      text: "工作经历",
      items: [
        { text: "excel", link: "/other/Excel/", activeMatch: "/other/Excel" },
        {
          text: "python",
          link: "/other/python/",
          activeMatch: "/other/python",
        },
      ],
    },
    // {
    //   text: "前端",
    //   items: [
    //     { text: "vue", link: "/front/vue/", activeMatch: "/front/vue" },
    //     {
    //       text: "other",
    //       link: "/front/other/",
    //       activeMatch: "/front/other",
    //     },
    //   ],
    // },
    // {
    //   text: "后端",
    //   items: [
    //     {
    //       text: "dotnetCore",
    //       link: "/backend/dotnetCore/",
    //       activeMatch: "/backend/dotnetCore",
    //     },
    //   ],
    // },
    // {
    //   text: "计算机基础",
    //   items: [
    //     {
    //       text: "组成原理",
    //       link: "/computer_basic/composition_principle/",
    //       activeMatch: "/computer_basic/composition_principle",
    //     },
    //     {
    //       text: "操作系统",
    //       link: "/computer_basic/operation_system/",
    //       activeMatch: "/computer_basic/operation_system",
    //     },
    //     {
    //       text: "数据结构",
    //       link: "/computer_basic/data_structure/",
    //       activeMatch: "/computer_basic/data_structure",
    //     },
    //     {
    //       text: "网络",
    //       link: "/computer_basic/network/",
    //       activeMatch: "/computer_basic/network",
    //     },
    //   ],
    // },
    // {
    //   text: "Linux",
    //   link: "/linux/",
    //   activeMatch: "/linux",
    // },
  ];
};

export default NavConfig;
