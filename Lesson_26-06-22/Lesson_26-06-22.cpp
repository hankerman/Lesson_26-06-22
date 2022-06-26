#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
    enum{EMPTY = -1, FULL = 20};
    char st[FULL + 1];
    int top;

public:
    Stack();
    void Push(char c);
    char Pop();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    bool IsAny();
};

Stack::Stack() {
    top = EMPTY;
}

bool Stack::IsEmpty() {
    return top == EMPTY;
}

bool Stack::IsFull() {
    return top == FULL;
}

bool Stack::IsAny() {
    return !IsEmpty();
}

int Stack::GetCount() {
    return top + 1;
}

void Stack::Clear() {
    top = EMPTY;
}

void Stack::Push(char c) {
    if (!IsFull())
        st[++top] = c;
}

char Stack::Pop() {
    if (!IsEmpty())
        return st[top--];
    else
        return 0;
}

void main()
{
    
    srand(time(0));
    Stack st;
    char c;
    while (!st.IsFull()) {
        c = rand() % 4 + 2;
        st.Push(c);
    }

    while (c = st.Pop()) {
        cout << c << ' ';
    }
    cout << endl;
}
