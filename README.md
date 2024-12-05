### 用于ubuntu系统的键盘输入信息读取
使用方法
1. `sudo apt install evtest`
2. `sudo evtest`
3. 查看输出的事件列表，根据名字推断哪个是（无线）键盘输入（我的无线键盘名字是CX 2.4G Wireless Receiver，有线键盘是AT Translated Set 2 keyboard），然后查看前面的eventX中的X 
4. 将`const char* dev_path = "/dev/input/event14";`中的路径改为你需要的
5. 运行`sudo bash build.sh`
6. 如果出现权限问题，可以使用chmod赋予权限
7. 如果每次开机对应的event都不一样，可以通过创建软链接的方法：使用`cat /proc/bus/input/devices`查看并确定键盘事件的数据名和物理路径，然后`KERNEL=="event*", ATTRS{name}=="Your event name", ATTRS{phys}=="Your phys path", SYMLINK+="Your custom name"`，之后每次开机后都可以使用`const char* dev_path = "/dev/input/Your custom name"`来访问输入事件了
