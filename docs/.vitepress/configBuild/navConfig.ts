import { DefaultTheme } from "vitepress";

const NavConfig = (): DefaultTheme.NavItem[] => {
  return [
    { text: "Home", link: "/" },
    {
      text: "前端",
      items: [
        { text: "vue", link: "/front/vue/", activeMatch: "/front/vue" },
        {
          text: "other",
          link: "/front/other/",
          activeMatch: "/front/other",
        },
      ],
    },
    {
      text: "后端",
      items: [
        {
          text: "dotnetCore",
          link: "/backend/dotnetCore/",
          activeMatch: "/backend/dotnetCore",
        },
      ],
    },
  ];
};

export default NavConfig;
