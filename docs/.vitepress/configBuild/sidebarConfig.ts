import { DefaultTheme } from "vitepress";
import { generateSidebar } from "../utils/sidebarGenerate";
const SidebarConfig = (): DefaultTheme.Sidebar => {
  return generateSidebar();
};

export default SidebarConfig;
