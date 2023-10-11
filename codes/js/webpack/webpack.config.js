const HtmlWebpackPlugin = require('html-webpack-plugin');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const CssMinimizerPlugin = require("css-minimizer-webpack-plugin");
const path = require('path')

module.exports = {
    mode: 'development',
    devServer: {
        static: './dist',
    },
    // 入口
    entry: path.resolve(__dirname, 'src/login/index.js'),

    // 出口
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: './login/index.js',
        clean: true
    },

    plugins: [
        new HtmlWebpackPlugin({
            template: path.resolve(__dirname, 'public/index.html'), // 模板文件  指定要用哪个
            filename: path.resolve(__dirname, 'dist/login/index.html') // 复制到哪去
        }),
        new MiniCssExtractPlugin({
            filename: './login/login.css'
        })
    ],

    module: {
        rules: [
          {
            test: /\.css$/i,
            // use: ["style-loader", "css-loader"],
            use: [MiniCssExtractPlugin.loader, "css-loader"],
          },
        ],
    },
    optimization: {
        minimizer: [
          // For webpack@5 you can use the `...` syntax to extend existing minimizers (i.e. `terser-webpack-plugin`), uncomment the next line
          `...`,
          new CssMinimizerPlugin(),
        ],
      },
}