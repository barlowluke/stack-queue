#pragma once

#include <string>
#include <stack>
#include <queue>

/*
Remove Adjacent Duplicates Using Stack
Goal: Remove all adjacent duplicate characters until none remain
Example:
"abbaca" -> "ca"
"abccba" -> ""
Stack Logic:
Iterate over string s:
If stack top = current character, pop from stack (remove pair).
Else, push character onto stack.
Final stack gives the result string.
*/
std::string removeDuplicates(std::string s) {
    std::stack<char> charStack;
    for (char c : s) {
        if (!charStack.empty() && charStack.top() == c) {
            charStack.pop();
        } else {
            charStack.push(c);
        }
    }
    std::string result = "";
    while (!charStack.empty()) {
        result.insert(0, 1, charStack.top());
        charStack.pop();
    }
    return result;
}

/*
clean string with Backspace char as <
Use stack to simulate typing
< = backspace -> pop from stack
Typing = push characters onto stack
Edge case: backspace on empty stack
Example:
s = "ab<c" -> stack = ['a', 'c']
t = "ad<c" -> stack = ['a', 'c']
*/
std::string clean_backspace_string(std::string s) {
    std::stack<char> charStack;
    for (char c : s) {
        if (charStack.empty() && c == '<') {
            ;;
        } else if (!charStack.empty() && c == '<') {
            charStack.pop();
        } else {
            charStack.push(c);
        }
    }
    std::string result = "";
    while (!charStack.empty()) {
        result.insert(0, 1, charStack.top());
        charStack.pop();
    }
    return result;
}

/*
Suppose you have a stack S containing n elements and a queue Q that is
initially empty.
Describe how you can use Q to scan S to see if it contains a certain element x,
with the additional constraint that your algorithm must return the elements back
to S in their original order. You may not use an array or linked list—only S and
Q and a constant number of reference variables.

Scanning a Stack Using a Queue (While Preserving Order)
Goal: Check if element x is in stack S using only:
Stack S, empty queue Q, and constant variables
Preserve original order of S after scan
Steps:

Step 1: Pop from S, enqueue into Q, check for x
Step 2: After scanning, dequeue from Q, push into S
Step 3: Repeat: Pop from S, enqueue into Q (restores original order)
Step 4: Finally, dequeue from Q, push into S

Example:
S = [3, 1, 4] (top to bottom)
x = 1
After scan: S = [3, 1, 4], Q = [], and x found
*/

template <typename T>
bool stack_contains_restore(std::stack<T>& S, std::queue<T>& Q, const T& x) {
    if (!Q.empty()) {
        throw std::invalid_argument("Q must be initially empty.");
    }
    bool exists = false;
    // step 1
    while (!S.empty()) {
        if (S.top() == x) {
            exists = true;
        }
        Q.push(S.top());
        S.pop();
    }
    // step 2
    while (!Q.empty()) {
        S.push(Q.back());
        Q.pop();
    }
    // step 3
    while (!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
    // step 4
    while (!Q.empty()) {
        S.push(Q.back());
        Q.pop();
    }
    return exists;
}
