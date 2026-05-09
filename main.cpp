#include <iostream>
#include <string>
using namespace std;

struct Queue {
    char data[100];
    int front, rear;

    Queue() { front = 0; rear = 0; }

    void enqueue(char c) { data[rear++] = c; }

    char dequeue() { return data[front++]; }

    bool isEmpty() { return front == rear; }
};

struct Stack {
    char data[100];
    int top;

    Stack() { top = -1; }

    void push(char c) { data[++top] = c; }

    char pop() { return data[top--]; }

    bool isEmpty() { return top == -1; }

    void display() {
        cout << "Stack: [ ";
        for (int i = 0; i <= top; i++)
            cout << data[i] << " ";
        cout << "]" << endl;
    }
};

bool isMatch(char a, char b) {
    return (a=='A' && b=='T') || (a=='T' && b=='A') ||
           (a=='C' && b=='G') || (a=='G' && b=='C');
}

int main() {
    string dna;

    cout << "==============================" << endl;
    cout << "     DNA Sequence Checker     " << endl;
    cout << "     Using Stack + Queue      " << endl;
    cout << "==============================" << endl;
    cout << endl;

    cout << "Enter DNA sequence (e.g. ATCGGCTA): ";
    cin >> dna;

    if (dna.length() % 2 != 0) {
        cout << "\nError! DNA length must be even!" << endl;
        return 0;
    }

    for (int i = 0; i < dna.length(); i++) {
        dna[i] = toupper(dna[i]);
        if (dna[i]!='A' && dna[i]!='T' && dna[i]!='C' && dna[i]!='G') {
            cout << "\nError! Invalid character '" << dna[i] << "'!" << endl;
            cout << "Only A, T, C, G are allowed!" << endl;
            return 0;
        }
    }

    Queue q;
    Stack s;

    cout << "\nStep 1: Loading DNA into Queue..." << endl;
    for (int i = 0; i < dna.length(); i++)
        q.enqueue(dna[i]);

    cout << "Queue: [ ";
    for (int i = 0; i < dna.length(); i++)
        cout << dna[i] << " ";
    cout << "]" << endl;

    int half = dna.length() / 2;

    cout << "\nStep 2: Pushing first half into Stack..." << endl;
    for (int i = 0; i < half; i++) {
        s.push(q.dequeue());
        s.display();
    }

    cout << "\nStep 3: Checking pairs..." << endl;
    bool valid = true;

    while (!q.isEmpty() && !s.isEmpty()) {
        char fromQueue = q.dequeue();
        char fromStack = s.pop();
        cout << "Comparing: " << fromStack << " with " << fromQueue;
        if (isMatch(fromStack, fromQueue))
            cout << " -> Match! OK" << endl;
        else {
            cout << " -> No Match! ERROR" << endl;
            valid = false;
        }
    }

    cout << "\n==============================" << endl;
    if (valid)
        cout << "Result: Valid DNA Sequence! :)" << endl;
    else
        cout << "Result: Invalid DNA Sequence! :(" << endl;
    cout << "==============================" << endl;

    return 0;
}

