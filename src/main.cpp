#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <libevdev/libevdev.h>

struct KeyStatus {
    bool W;  // W键
    bool A;  // A键
    bool S;  // S键
    bool D;  // D键
    bool Up; // 上方向键
    bool Down; // 下方向键
    bool Left; // 左方向键
    bool Right; // 右方向键
};

void printKeyStatus(const KeyStatus& status) {
    std::cout << "W: " << (status.W ? "Pressed" : "Released") << ", ";
    std::cout << "A: " << (status.A ? "Pressed" : "Released") << ", ";
    std::cout << "S: " << (status.S ? "Pressed" : "Released") << ", ";
    std::cout << "D: " << (status.D ? "Pressed" : "Released") << ", ";
    std::cout << "Up: " << (status.Up ? "Pressed" : "Released") << ", ";
    std::cout << "Down: " << (status.Down ? "Pressed" : "Released") << ", ";
    std::cout << "Left: " << (status.Left ? "Pressed" : "Released") << ", ";
    std::cout << "Right: " << (status.Right ? "Pressed" : "Released") << std::endl;
}

int main() {
    const char* dev_path = "/dev/input/event6";  // 输入设备路径，根据实际情况修改
    int fd = open(dev_path, O_RDONLY);
    if (fd == -1) {
        perror("打开设备失败");
        return 0;
    }

    struct libevdev* dev = nullptr;
    if (libevdev_new_from_fd(fd, &dev) != 0) {
        std::cerr << "初始化 libevdev 失败" << std::endl;
        close(fd);
        return 0;
    }

    std::cout << "设备名称: " << libevdev_get_name(dev) << std::endl;

    struct input_event ev;
    KeyStatus keyStatus = {false, false, false, false, false, false, false, false};  // 初始化所有标志位为 false

    while (true) {
        if (libevdev_next_event(dev, LIBEVDEV_READ_FLAG_BLOCKING, &ev) == 0) {
            if (ev.type == EV_KEY) {
                // 检查按键事件，并更新相应的标志位
                switch (ev.code) {
                                        case KEY_W:
                        if (ev.value == 1) {  // 按下
                            keyStatus.W = true;
                        } else if (ev.value == 0) {  // 松开
                            keyStatus.W = false;
                        } else if (ev.value == 2) {  // 按住
                            // 持续按住时不需要改变状态
                        }
                        break;
                    case KEY_A:
                        if (ev.value == 1) {  // 按下
                            keyStatus.A = true;
                        } else if (ev.value == 0) {  // 松开
                            keyStatus.A = false;
                        } else if (ev.value == 2) {  // 按住
                            // 持续按住时不需要改变状态
                        }
                        break;
                    case KEY_S:
                        if (ev.value == 1) {  // 按下
                            keyStatus.S = true;
                        } else if (ev.value == 0) {  // 松开
                            keyStatus.S = false;
                        } else if (ev.value == 2) {  // 按住
                            // 持续按住时不需要改变状态
                        }
                        break;
                    case KEY_D:
                        if (ev.value == 1) {  // 按下
                            keyStatus.D = true;
                        } else if (ev.value == 0) {  // 松开
                            keyStatus.D = false;
                        } else if (ev.value == 2) {  // 按住
                            // 持续按住时不需要改变状态
                        }
                        break;
                    case KEY_UP:
                        keyStatus.Up = (ev.value == 1);
                        break;
                    case KEY_DOWN:
                        keyStatus.Down = (ev.value == 1);
                        break;
                    case KEY_LEFT:
                        keyStatus.Left = (ev.value == 1);
                        break;
                    case KEY_RIGHT:
                        keyStatus.Right = (ev.value == 1);
                        break;
                    default:
                        break;
                }
                
                // 打印当前状态
                printKeyStatus(keyStatus);
            }
        }
        usleep(1000);
    }

    libevdev_free(dev);
    close(fd);
    return 0;
}
