#include "HashTable.cpp"
int main() {
    HashTable ht;

    ht.insert(10, "Apple");
    ht.insert(30, "Banana");
    ht.insert(50, "Cherry");

    ht.print();

    Node result = ht.find(30);
    if (result.key != -1) cout << "Found: " << result.value << endl;
    else cout << "Not found!" << endl;

    ht.delet(30);
    result = ht.find(30);
    if (result.key != -1) cout << "Found: " << result.value << endl;
    else cout << "Not found!" << endl;

    return 0;
}
