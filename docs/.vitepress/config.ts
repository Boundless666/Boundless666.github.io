import { defineConfig } from "vitepress";
import * as Config from "./configBuild";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "Atman Docs",
  description: "Record my learn.",
  base: "/docs/",
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: Config.NavConfig(),
    logo: "/logo.png",
    sidebar: Config.SidebarConfig(),

    socialLinks: [{ icon: "github", link: "https://github.com/boundless666" }],
  },
  head: [
    ["link", { rel: "shortcut icon", href: "/logo.png", type: "image/x-icon" }],
  ],
});
