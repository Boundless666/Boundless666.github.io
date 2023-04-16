import { DefaultTheme } from "vitepress";
import { generateSidebar } from "../utils/sidebarGenerate";
const SidebarConfig = (): DefaultTheme.Sidebar => {
  return generateSidebar();
  // return {
  //   "/front/vue": [
  //     { text: "test", link: "/001_vue/001_test/001_test.md", collapsed: true },
  //   ],
  // };
};

export default SidebarConfig;
