#include "VecStack.h"
#include "LinkedStack.h"

#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

#define ARRAY_SIZE 8096
#define MAX_STACK 8096
#define POP_STACK 4096

typedef struct {
    int data[ARRAY_SIZE];
} bigArray;

auto
timeFunc(const std::function<void()>& f, const string& name) {
    auto start = high_resolution_clock::now();

    f();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "| " << name << " | " << duration.count() << " |" << endl;

    return duration;
}

int main() {

    cout << "| Vector Stack | Time (ms) |" << endl;
    cout << "|:-------|:------|" << endl;

    timeFunc([]() {
        VecStack<bigArray> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            bigArray b = {};
            stack.push(b);
        }

        for (int i = 0; i < POP_STACK; i++) {
            bigArray b = {};
            stack.push(b);
            stack.pop();
            stack.pop();
        }
    }, "Big data");

    timeFunc([]() {
        VecStack<int> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            int b = {};
            stack.push(b);
        }

        for (int i = 0; i < POP_STACK; i++) {
            int b = {};
            stack.push(b);
            stack.pop();
            stack.pop();
        }
    }, "Small data");

    timeFunc([]() {
        VecStack<bigArray> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            bigArray b = {};
            stack.push(b);
        }

        while (!stack.empty()) {
            stack.pop();
        }
    }, "Big data fill and empty");

    timeFunc([]() {
        VecStack<int> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            int b = {};
            stack.push(b);
        }

        while (!stack.empty()) {
            stack.pop();
        }
    }, "Small data fill and empty");

    cout << endl;
    cout << "| Linked List Stack | Time (ms) |" << endl;
    cout << "|:-------|:------|" << endl;

    timeFunc([]() {
        LinkedStack<bigArray> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            bigArray b = {};
            stack.push(b);
        }

        for (int i = 0; i < POP_STACK; i++) {
            bigArray b = {};
            stack.push(b);
            stack.pop();
            stack.pop();
        }
    }, "Big data");

    timeFunc([]() {
        LinkedStack<int> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            int b = {};
            stack.push(b);
        }

        for (int i = 0; i < POP_STACK; i++) {
            int b = {};
            stack.push(b);
            stack.pop();
            stack.pop();
        }
    }, "Small data");

    timeFunc([]() {
        LinkedStack<bigArray> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            bigArray b = {};
            stack.push(b);
        }

        while (!stack.empty()) {
            stack.pop();
        }
    }, "Big data fill and empty");

    timeFunc([]() {
        LinkedStack<int> stack;

        for (int i = 0; i < MAX_STACK; i++) {
            int b = {};
            stack.push(b);
        }

        while (!stack.empty()) {
            stack.pop();
        }
    }, "Small data fill and empty");
}