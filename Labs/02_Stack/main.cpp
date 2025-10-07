//#include "Stack.h"
//#include <stack>
//
//using namespace std;
//
//    int main(){
//
//
//        cout << "----------------MY OWN STACK----------------" << endl;
//        MyStack S1(5);
//
//        cout << "Is stack empty? " << endl;
//        if (S1.isEmpty())
//        {
//            cout << "Yes!" << endl;
//        }
//        else { cout << "NO" << endl; }
//        cout << "Let's push some elements " << endl;
//        S1.push(10);
//        S1.push(20);
//        S1.push(30);
//        cout << "Is stack full? " << endl;
//        if (S1.isFull())
//        {
//            cout << "Yes!" << endl;
//        }
//        else { cout << "NO" << endl; }
//        cout << "Current occupancy: " << S1.GetOccupancy() << endl;
//        cout << "Stack capacity: " << S1.GetCapacity() << endl;
//        cout << "Top element: " << S1.pop() << endl;
//        cout << "Let's full stack!" << endl;
//        S1.push(23);
//        S1.push(25);
//        S1.push(88);
//        cout << "Is stack full? " << endl;
//        if (S1.isFull())
//        {
//            cout << "Yes!" << endl;
//        }
//        else { cout << "NO" << endl; }
//        cout << "Current occupancy: " << S1.GetOccupancy() << endl;
//        cout << "Stack capacity: " << S1.GetCapacity() << endl;
//        cout << "Top element: " << S1.pop() << endl;
//        cout << "Popping elements..." << endl;
//        cout << "Popped: " << S1.pop() << endl;
//        cout << "Popped: " << S1.pop() << endl;
//        cout << "Popped: " << S1.pop() << endl;
//        cout << "Popped: " << S1.pop() << endl;
//        cout << "Is stack empty? " << endl;
//        if (S1.isEmpty())
//        {
//            cout << "Yes!" << endl;
//        }
//        else { cout << "NO" << endl; }
//        cout << "Attempting to pop from an empty stack..." << endl;
//        int poppedValue = S1.pop();
//        if (poppedValue == -1) {
//            cout << "Stack is empty, cannot pop." << endl;
//        }
//        else {
//            cout << "Popped: " << poppedValue << endl;
//        }
//
//        cout << "----------------STL STACK----------------" << endl;
//        stack<int> S2;
//
//        cout << "Let's push: 10, 20, 30" << endl;
//        S2.push(10);
//        S2.push(20);
//        S2.push(30);
//
//        cout << "Top : " << S2.top() << endl;
//
//        cout << "Now, pop this elements:" << endl;
//        while (!S2.empty()) {
//            cout << "Poped: " << S2.top() << endl;
//            S2.pop();
//        }
//
//        if (S2.empty()) {
//            cout << "Stack is empty." << endl;
//        }
//
//
//        return 0;
//}
