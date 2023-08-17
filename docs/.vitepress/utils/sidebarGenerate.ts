/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-05-31 23:05:37
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-17 13:43:22
 * @FilePath: sidebarGenerate.ts
 */
import { DefaultTheme } from "vitepress";
import fs from "fs";
import path from "path";
import { NavConfig } from "../configBuild";

const generateSidebar = () => {
  const url = import.meta.url; // 当前文件的完整目录
  let rootPath = url.split("///")[1].split("/.vitepress")[0]; // 切分 使其为docs目录
  if (rootPath.includes("/runner/work")) { // 处理github workflow目录问题
    // rootPath = rootPath.substring(0, rootPath.length - 5);
    rootPath = "/" + rootPath;
  }
  console.log(`output->rootPath`, rootPath);
  var sidebarM: DefaultTheme.SidebarMulti = {};
  const navs = NavConfig() as any[];
  navs.forEach((navItem) => {
    if (navItem.hasOwnProperty("items")) { // 二级菜单处理(不是多级菜单处理)
      (navItem.items as DefaultTheme.NavItemWithLink[]).forEach((item) => {
        // console.log(`${rootPath} \t ${item.link} \t ${sidebarM}`);
        getDocs(rootPath, item.link, sidebarM);
      });
    }
    if (navItem.hasOwnProperty("activeMatch")) {
      getDocs(rootPath, navItem.link, sidebarM);
    }
  });
  return sidebarM;
};

/**
 * 
 * @param rootPath 所有文档的根目录 也就是docs
 * @param docPath 每个模块的目录
 * @param sidebarMult 侧边菜单栏集合
 */
const getDocs = (
  rootPath: string,
  docPath: string,
  sidebarMult: DefaultTheme.SidebarMulti
) => {
  sidebarMult[docPath] = readAll(rootPath, docPath);
};

/**
 * 递归读取当前模块目录下的所有文件
 * @param rootPath 所有文档的根目录 也就是docs
 * @param docPath 单个模块的目录
 * @returns 返回文件项集合
 */
const readAll = (
  rootPath: string,
  docPath: string
): DefaultTheme.SidebarItem[] => {
  let files = fs.readdirSync(rootPath + docPath);
  // console.log("files before handle:", files);
  files = ignoreHandle(rootPath + docPath, files);
  // console.log("files after handle:", files);
  let sidebarItems: DefaultTheme.SidebarItem[] = [];
  files.forEach((item) => {
    let tempPath = path.join(rootPath + docPath, item);
    let stats = fs.statSync(tempPath);
    if (stats.isDirectory()) {
      if(item == "assets")
        return;

      // console.log(`output->stats`, tempPath);
      let dirItem: DefaultTheme.SidebarItem = {
        text: item,
        items: [],
        collapsed: true,
      };
      dirItem.items = readAll(rootPath, docPath + item + "/");
      sidebarItems.push(dirItem);
    } else if (stats.isFile()) {
      let index = item.lastIndexOf(".");
      let ext = item.substring(index + 1);
      if (ext.toLowerCase() == "md") {
        let barItem: DefaultTheme.SidebarItem = {
          text: item.substring(0, index),
          link: docPath + item,
        };
        sidebarItems.push(barItem);
        // currentDirSidebarItems.push(barItem);
        // console.log(`output->tempPath`, barItem);
      }
    } else {
    }
  });

  return sidebarItems;
};

const fileType = (fileName: string) => {
  var index = fileName.lastIndexOf(".");
  var ext = fileName.substring(index + 1);
  return ext.toLowerCase();
};

/**
 * 指定忽略某些文件
 * @param currentRootPath 当前要处理文件集合的所在目录
 * @param files 文件集合
 * @returns 过滤后的文件集合
 */
const ignoreHandle = (currentRootPath,files: string[]) =>{
  if(files.includes(".fileignore")){
    let data = fs.readFileSync(currentRootPath + "/.fileignore");
    let arr = data.toString().split('\n');
    arr = arr.map((value) => value = value.replace(/\s+$/, ""));
    arr.push('.fileignore');
    // console.log(arr)
    files = files.filter((value)=>{
      return !arr.includes(value);
    })
  }
  return files;
}

export { generateSidebar };
