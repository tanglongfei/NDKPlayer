# NDKPlayer
Android NDK直播框架，使用熊猫直播流（仅用于学习交流）
## 要点： 
- 1.使用Cmake构建
- 2.FFmpeg作为底层播放框架
- 3.在Linux系统中编写shell脚本，根据个人需求添加相应功能(例如本项目只是播放，所以无编码功能)
- 4.在Linux系统上使用Liunx-NDK中的arm-linux-androideabi-gcc将FFmpeg编译成为Android可用.a静态库(可选择动态库，但本人更倾向于静态库，好处可自行百度)
- 5.静态库的形式对FFmpeg进行依赖
- 6.线程安全的线程安全的队列
## JNI包结构：
![image](https://github.com/tanglongfei/NDKPlayer/blob/master/image/ndk%E5%8C%85%E7%BB%93%E6%9E%84.png?raw=true)
## 时间节点：
- 2018-09-05 项目上传

## 项目初期，后续将不断完善......
