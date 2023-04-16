import { defineConfig } from "vitepress";
import * as Config from "./configBuild";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "Atman Docs",
  description: "Record my learn.",
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: Config.NavConfig(),

    sidebar: Config.SidebarConfig(),

    socialLinks: [
      { icon: "github", link: "https://github.com/vuejs/vitepress" },
    ],
  },
});
