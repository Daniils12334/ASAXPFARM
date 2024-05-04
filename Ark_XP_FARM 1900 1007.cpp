#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;
mutex mtx;
bool stopCrafting = false;

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

// Функция для крафта динамита
void craftDynamite() {

    this_thread::sleep_for(chrono::seconds(4));

    cout << "Crafting dynamite..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));


    //DYNAMITE SEARCH/CRAFT
    clickAt(330, 200);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('D');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('Y');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('N');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    this_thread::sleep_for(chrono::seconds(1)); // Пример задержки

    for (int i = 0; i < 2; ++i) {
        //DYNAMITECORDS
        clickAt(245, 245);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    pressKeyMultipleTimes('A', 3);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    for (int i = 0; i < 2; ++i) {
        //OPEN COSMETICS
        clickAt(443, 150);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    for (int i = 0; i < 2; ++i) {
        //drop all cords YOU CAN CHANGE CORDS FOR PERSONAL YOU MONITOR RESOLUTION
        clickAt(443, 200);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    for (int i = 0; i < 2; ++i) {
        //OPEN CRAFT
        clickAt(650, 150);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    this_thread::sleep_for(chrono::seconds(1));
}

// Функция для потребления еды и воды
void consumeFoodAndWater() {

    cout << "Consuming food and water..." << endl;
    this_thread::sleep_for(chrono::seconds(4)); 

    //INVENTORY
    clickAt(330, 150);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //SEARCH
    clickAt(330, 200);
    //NEW RECIPE eat
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('C');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('A');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('N');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    clickAt(245, 245);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('E');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    //SEARCH
    clickAt(330, 200);
    //DELETE
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    //FOOD eat
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('F');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('O');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('O');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('D');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    clickAt(245, 245);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('E');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    //SEARCH
    clickAt(330, 200);
    //DELETE
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    //OPEN CRAFT
    clickAt(650, 150);
    this_thread::sleep_for(chrono::seconds(1)); 
}

// Функция для потребления супа
void consumeSoup() {
    this_thread::sleep_for(chrono::seconds(4)); 

    //INVENTORY
    clickAt(330, 150);
    //SEARCH
    clickAt(330, 200);
    //CHILI eat
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('F');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('O');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('C');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    clickAt(245, 245);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    pressKey('E');
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    //SEARCH
    clickAt(330, 200);
    //DELETE
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_BACK, 0x38, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    keybd_event(VK_BACK, 0x38, KEYEVENTF_KEYUP, 0);
    //OPEN CRAFT
    clickAt(650, 150);
    this_thread::sleep_for(chrono::seconds(1)); // Пример задержки
    cout << "Consuming soup for crafting boost..." << endl;
}

// Функция для выполнения цикла крафта динамита
void craftDynamiteLoop() {
    while (true) {
        {
            lock_guard<mutex> guard(mtx);
            if (!stopCrafting)
                craftDynamite();
        }
        this_thread::sleep_for(chrono::minutes(15));
    }
}

// Функция для выполнения цикла потребления еды и воды
void consumeFoodAndWaterLoop() {
    while (true) {
        {
            lock_guard<mutex> guard(mtx);
            stopCrafting = true;
            consumeFoodAndWater();
            stopCrafting = false;
        }
        this_thread::sleep_for(chrono::minutes(60));
    }
}

// Функция для выполнения цикла потребления супа
void consumeSoupLoop() {
    while (true) {
        {
            lock_guard<mutex> guard(mtx);
            stopCrafting = true;
            consumeSoup();
            stopCrafting = false;
        }
        this_thread::sleep_for(chrono::minutes(15));
    }
}

// Функция для выполнения крафта динамита между потреблениями
void craftDynamiteBetweenConsumptions() {
    while (true) {
        {
            lock_guard<mutex> guard(mtx);
            if (!stopCrafting)
                craftDynamite();
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}



int main() {
    // Запускаем потоки для каждого цикла
    thread dynamiteThread(craftDynamiteLoop);
    thread foodAndWaterThread(consumeFoodAndWaterLoop);
    thread soupThread(consumeSoupLoop);
    thread craftDynamiteThread(craftDynamiteBetweenConsumptions);

    // Ждем завершения работы потоков
    dynamiteThread.join();
    foodAndWaterThread.join();
    soupThread.join();
    craftDynamiteThread.join();

    return 0;
}
