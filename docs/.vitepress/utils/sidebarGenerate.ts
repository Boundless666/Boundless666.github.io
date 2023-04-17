import { DefaultTheme } from "vitepress";
import fs from "fs";
import path from "path";
import { NavConfig } from "../configBuild";

const generateSidebar = () => {
  const url = import.meta.url;
  console.log(`output->url`, url);
  let rootPath = url.split("///")[1].split("/.vitepress")[0];
  if (rootPath.includes("/runner/work")) {
    console.log(`output->a`, 100);
    rootPath = rootPath.substring(0, rootPath.length - 5);
  }
  console.log(`output->rootPath`, rootPath);
  var sidebarM: DefaultTheme.SidebarMulti = {};
  const navs = NavConfig() as any[];
  navs.forEach((navItem) => {
    if (navItem.hasOwnProperty("items")) {
      (navItem.items as DefaultTheme.NavItemWithLink[]).forEach((item) => {
        // console.log(`output->item.`, item.link);
        // sidebarM[item.link] = [];
        getDocs(rootPath, item.link, sidebarM);
      });
      // console.log(`output->`, navItem.items);
    }
  });
  // var sidebarItems: DefaultTheme.Sidebar = [];

  // console.log(`output->`, sidebarM);
  // readAll("D:/documents/computer/computer/docs", "/front/vue/", sidebarItems);
  // console.log(`output->url`, url.split("/docs"));
  // fs.writeFileSync(
  //   rootPath + "/.vitepress/configBuild/sidebar.json",
  //   JSON.stringify(sidebarM)
  // );
  return sidebarM;
};

const getDocs = (
  rootPath: string,
  docPath: string,
  sidebarMult: DefaultTheme.SidebarMulti
) => {
  sidebarMult[docPath] = readAll(rootPath, docPath);
};

const readAll = (
  rootPath: string,
  docPath: string
): DefaultTheme.SidebarItem[] => {
  let files = fs.readdirSync(rootPath + docPath);
  let sidebarItems: DefaultTheme.SidebarItem[] = [];
  files.forEach((item) => {
    let tempPath = path.join(rootPath + docPath, item);
    let stats = fs.statSync(tempPath);
    if (stats.isDirectory()) {
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

export { generateSidebar };
