### 用于ubuntu系统的键盘输入信息读取
使用方法
1. `sudo apt install evtest`
2. `sudo evtest`
3. 查看输出的事件列表，根据名字推断哪个是（无线）键盘输入（我的无线键盘名字是CX 2.4G Wireless Receiver，有线键盘是AT Translated Set 2 keyboard），然后查看前面的eventX中的X 
4. 将`const char* dev_path = "/dev/input/event14";`中的路径改为你需要的
5. 运行`sudo bash build.sh`
6. 如果出现权限问题，可以使用chmod赋予权限