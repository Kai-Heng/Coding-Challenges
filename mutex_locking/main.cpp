#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <functional>

using namespace std;

class Foo {
    mutex mtx;
    condition_variable cv;
    int stage;
public:
    Foo() {
        stage = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        stage = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return stage == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        stage = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return stage == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};