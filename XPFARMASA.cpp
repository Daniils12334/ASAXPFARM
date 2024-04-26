#include <Windows.h>
#include <iostream>
#include <thread>
#include <atomic>

void altTab() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_TAB, 0x8f, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_TAB, 0x8f, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void clickAt(int x, int y) {
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

void pressKeyMultipleTimes(BYTE keyCode, int times) {
    for (int i = 0; i < times; ++i) {
        keybd_event(keyCode, 0, 0, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
    }
}

void pressKey(BYTE keyCode) {

    keybd_event(keyCode, 0, 0, 0);

    keybd_event(keyCode, 0, KEYEVENTF_KEYUP, 0);
}

void clickThread(std::atomic<bool>& running) {
    while (running) {
        clickAt(680, 1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        pressKey('E');
        clickAt(720, 1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        pressKey('E');
        std::this_thread::sleep_for(std::chrono::minutes(30));
    }
}

int main() {
    std::atomic<bool> running(true);
    std::thread clickerThread(clickThread, std::ref(running));

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        for (int i = 0; i < 2; ++i) {
            //CRAFT CORDS
            clickAt(245, 245);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }


        std::this_thread::sleep_for(std::chrono::seconds(2));

        pressKeyMultipleTimes('A', 3);

        std::this_thread::sleep_for(std::chrono::seconds(5));

        for (int i = 0; i < 2; ++i) {
            //OPEN COSMETICS
            clickAt(443, 150);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        for (int i = 0; i < 2; ++i) {
            //drop all cords
            clickAt(443, 200);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        for (int i = 0; i < 2; ++i) {
            //OPEN CRAFT
            clickAt(650, 150);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        if (GetAsyncKeyState(VK_ESCAPE)) {
            running = false;
        }
    }

    // Join the clicker thread
    if (clickerThread.joinable()) {
        clickerThread.join();
    }

    return 0;
}
