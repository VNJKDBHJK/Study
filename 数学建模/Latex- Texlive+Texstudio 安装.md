# Latex- Texlive 安装

[下载地址](https://mirrors.tuna.tsinghua.edu.cn/CTAN/systems/texlive/Images/)

![image-20240226133652877](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261337077.png)

将.iso文件解压，以管理员身份打开**install-tl-windows.bat**

![image-20240226133818911](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261338027.png)

![image-20240226133920307](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261339354.png)

更改安装地址，安装
安装完成后查看命令行中是否可以运行`tex -v` ,可以运行即可
不能运行说明没有添加环境变量
打开安装路径
![image-20240226134206860](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261342956.png)
点击`windows`
复制该路径
`win+R`打开运行输入`sysdm.cpl`->高级->环境变量
![image-20240226134502438](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261345555.png)
双击->新建
将复制好的路径贴上去

![image-20240226134555448](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261345539.png)
双击->新建
粘贴路径
![image-20240226134648912](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261346046.png)
![image-20240226134700843](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261347967.png)

![image-20240226134710950](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202402261347052.png)

Texlive安装完成
[借鉴](https://zhuanlan.zhihu.com/p/389394015)