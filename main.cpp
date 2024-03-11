// Samuel Castro
// Lab 4 
// SP2024
/* Description: Write a program that will reverse the order of a stack. For this lab, you will
use your stack class and you’re not allowed to use any C++ loops. You must use
recursion.*/

#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element
void insertAtBottom(stack<int>& stk, int item) {
    // Base case: if stack empty, then push the item
    if (stk.empty()) {
        stk.push(item);
    }
    else {
        // Recursive call insert item
        int temp = stk.top();
        stk.pop();
        insertAtBottom(stk, item);
        stk.push(temp);
    }
}

// Function reverse the order of elements
void reverseStack(stack<int>& stk) {
    // Base case: if stack is not empty
    if (!stk.empty()) {
        // Remove the top element
        int temp = stk.top();
        stk.pop();

        // Reverse remaining elements
        reverseStack(stk);

        // Insert removed element
        insertAtBottom(stk, temp);
    }
}

int main() {
    stack<int> stk;

    // Push elements in stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // Display original stack
    cout << "Original Stack:" << endl;
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    // Push elements in stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // Reverse the stack
    reverseStack(stk);

    // Display reversed stack
    cout << "Reversed Stack:" << endl;
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}
