#include "VecStack.h"
#include "LinkedStack.h"
#include "DequeStack.h"

#include <chrono>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::chrono;

#define ARRAY_SIZE 8096
#define MAX_STACK 100000
#define POP_STACK 50000

typedef struct {
    int data[ARRAY_SIZE];
} bigArray;

auto
timeFunc(const std::function<void()>& f, const string& name) {
    auto start = high_resolution_clock::now();

    f();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "| " << name << " | " << duration.count() / 1000.0 << " |" << endl;

    return duration;
}

template<typename T>
void
addData(Stack<T> & stack) {
    for (int i = 0; i < MAX_STACK; i++) {
        T b = {};
        stack.push(b);
    }

    for (int i = 0; i < POP_STACK; i++) {
        T b = {};
        stack.push(b);
        stack.pop();
        stack.pop();
    }
}

template<typename T>
void
fillAndEmpty(Stack<T> & stack) {
    for (int i = 0; i < MAX_STACK; i++) {
        T b = {};
        stack.push(b);
    }

    while (!stack.empty()) {
        stack.pop();
    }
}

//template void bigData<bigArray>(Stack<bigArray> &stack);

int main() {

    cout << "| Vector Stack | Time (ms) |" << endl;
    cout << "|:-------|:------|" << endl;

    timeFunc([]() {
        VecStack<bigArray> s;
        addData(s);
    }, "Big data");

    timeFunc([]() {
        VecStack<bigArray> stack;
        fillAndEmpty(stack);
    }, "Big data fill and empty");

    timeFunc([]() {
        VecStack<int> s;
        addData(s);
    }, "Small data");

    timeFunc([]() {
        VecStack<int> s;
        fillAndEmpty(s);
    }, "Small data fill and empty");

    cout << endl;
    cout << "| Linked List Stack | Time (ms) |" << endl;
    cout << "|:-------|:------|" << endl;

    timeFunc([]() {
        LinkedStack<bigArray> s;
        addData(s);
    }, "Big data");

    timeFunc([]() {
        LinkedStack<bigArray> stack;
        fillAndEmpty(stack);
    }, "Big data fill and empty");

    timeFunc([]() {
        LinkedStack<int> s;
        addData(s);
    }, "Small data");

    timeFunc([]() {
        LinkedStack<int> s;
        fillAndEmpty(s);
    }, "Small data fill and empty");
    cout << endl;

    cout << "| Deque Stack | Time (ms) |" << endl;
    cout << "|:-------|:------|" << endl;

    timeFunc([]() {
        DequeStack<bigArray> s;
        addData(s);
    }, "Big data");

    timeFunc([]() {
        DequeStack<bigArray> stack;
        fillAndEmpty(stack);
    }, "Big data fill and empty");

    timeFunc([]() {
        DequeStack<int> s;
        addData(s);
    }, "Small data");

    timeFunc([]() {
        DequeStack<int> s;
        fillAndEmpty(s);
    }, "Small data fill and empty");
}
