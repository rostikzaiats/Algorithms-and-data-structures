#include <iostream>
using namespace std;

struct Node {
    size_t row, column, val;
    Node* left, * up;
    Node() : row(0), column(0), val(0), left(nullptr), up(nullptr) {}
    Node(int v, size_t r, size_t c) : row(r), column(c), val(v), left(nullptr), up(nullptr) {}
};

class SpareMatrix {
private:
    size_t C_size, R_size;
    Node* columns, * rows;

    Node* getPrev_byRow(size_t rowI, size_t colJ) {
        Node* current = &rows[rowI - 1];
        while (current->left != nullptr && current->left != &rows[rowI - 1] && current->left->column < colJ) {
            current = current->left;
        }
        return current;
    }

    Node* getPrev_byCol(size_t rowI, size_t colJ) {
        Node* current = &columns[colJ - 1];
        while (current->up != nullptr && current->up != &columns[colJ - 1] && current->up->row < rowI) {
            current = current->up;
        }
        return current;
    }

public:
    SpareMatrix(size_t RS, size_t CS) :R_size(RS), C_size(CS) {
        columns = new Node[CS];
        rows = new Node[RS];
        for (size_t i = 0; i < CS; ++i) {
            columns[i].column = i + 1;
            columns[i].up = &columns[i];
        }
        for (size_t i = 0; i < RS; ++i) {
            rows[i].row = i + 1;
            rows[i].left = &rows[i];
        }
    }

    ~SpareMatrix() {
        for (size_t i = 0; i < R_size; ++i) {
            Node* current = rows[i].left;
            while (current != &rows[i]) {
                Node* to_delete = current;
                current = current->left;
                delete to_delete;
            }
        }
        delete[] rows;
        delete[] columns;
        rows = nullptr; columns = nullptr;
    }
    SpareMatrix(const SpareMatrix& other) : R_size(other.R_size), C_size(other.C_size) {
        columns = new Node[C_size];
        rows = new Node[R_size];

        for (size_t i = 0; i < C_size; ++i) {
            columns[i].column = i + 1;
            columns[i].up = &columns[i];
        }
        for (size_t i = 0; i < R_size; ++i) {
            rows[i].row = i + 1;
            rows[i].left = &rows[i];
        }

        for (size_t i = 1; i <= R_size; ++i) {
            Node* current = other.rows[i - 1].left;
            while (current != &other.rows[i - 1]) {
                addElement(current->row, current->column, current->val);
                current = current->left;
            }
        }
    }


    void addElement(size_t rowI, size_t colJ, int value) {
        if (rowI < 1 || rowI > R_size || colJ < 1 || colJ > C_size) return;
        if (value == 0) {
            delElement(rowI, colJ);
            return;
        }

        Node* prevByRow = getPrev_byRow(rowI, colJ);
        Node* prevByCol = getPrev_byCol(rowI, colJ);

        if (prevByCol->up != &columns[colJ - 1] && prevByCol->up->row == rowI && prevByCol->up->column == colJ) {
            prevByCol->up->val = value;
            return;
        }

        Node* newNode = new Node(value, rowI, colJ);
        newNode->left = prevByRow->left;
        prevByRow->left = newNode;
        newNode->up = prevByCol->up;
        prevByCol->up = newNode;
    }
    SpareMatrix& operator=(const SpareMatrix& other) {
        if (this == &other) return *this;

        for (size_t i = 0; i < R_size; ++i) {
            Node* current = rows[i].left;
            while (current != &rows[i]) {
                Node* to_delete = current;
                current = current->left;
                delete to_delete;
            }
        }
        delete[] rows;
        delete[] columns;

     
        R_size = other.R_size;
        C_size = other.C_size;


        columns = new Node[C_size];
        rows = new Node[R_size];

    
        for (size_t i = 0; i < C_size; ++i) {
            columns[i].column = i + 1;
            columns[i].up = &columns[i];
        }
        for (size_t i = 0; i < R_size; ++i) {
            rows[i].row = i + 1;
            rows[i].left = &rows[i];
        }

        for (size_t i = 1; i <= R_size; ++i) {
            Node* current = other.rows[i - 1].left;
            while (current != &other.rows[i - 1]) {
                addElement(current->row, current->column, current->val);
                current = current->left;
            }
        }

        return *this;
    }

    void delElement(size_t rowI, size_t colJ) {
        if (rowI < 1 || rowI > R_size || colJ < 1 || colJ > C_size) return;

        Node* prevByCol = getPrev_byCol(rowI, colJ);
        if (prevByCol->up != &columns[colJ - 1] && prevByCol->up->row == rowI && prevByCol->up->column == colJ) {
            Node* elemToDelete = prevByCol->up;
            prevByCol->up = elemToDelete->up;

            Node* prevByRow = getPrev_byRow(rowI, colJ);
            prevByRow->left = elemToDelete->left;

            delete elemToDelete;
        }
    }

    int GetValue(size_t rowI, size_t colJ) const {
        if (rowI < 1 || rowI > R_size || colJ < 1 || colJ > C_size) return 0;

        Node* current = rows[rowI - 1].left;
        while (current != &rows[rowI - 1]) {
            if (current->column == colJ) {
                return current->val;
            }
            current = current->left;
        }
        return 0;
    }
    SpareMatrix AddMatrix(SpareMatrix& to_add) {
        SpareMatrix result(R_size, C_size);

        // M1
        for (size_t i = 1; i <= R_size; ++i) {
            Node* current = rows[i - 1].left;
            while (current != &rows[i - 1]) {
                int sum = current->val + to_add.GetValue(current->row, current->column);
                result.addElement(current->row, current->column, sum);
                current = current->left;
            }
        }

        // M2
        for (size_t i = 1; i <= to_add.R_size; ++i) {
            Node* current = to_add.rows[i - 1].left;
            while (current != &to_add.rows[i - 1]) {
                if (GetValue(current->row, current->column) == 0) {
                    result.addElement(current->row, current->column, current->val);
                }
                current = current->left;
            }
        }

        return result;
    }

    void print() const {
        for (size_t i = 1; i <= R_size; ++i) {
            for (size_t j = 1; j <= C_size; ++j) {
                cout << GetValue(i, j) << "\t";
            }
            cout << endl;
        }
    }

    SpareMatrix MultiplyMatrix(const SpareMatrix& to_multiply) const {
        if (C_size != to_multiply.R_size) {
            cerr << "Error: Cannot multiply matrices with incompatible dimensions.\n";
            return SpareMatrix(0, 0);
        }

        SpareMatrix result(R_size, to_multiply.C_size);

        for (size_t j = 1; j <= to_multiply.C_size; ++j) {
            for (size_t i = 1; i <= R_size; ++i) {
                int sum = 0;
                for (size_t k = 1; k <= C_size; ++k) {
                    sum += GetValue(i, k) * to_multiply.GetValue(k, j);
                }
                if (sum != 0) {
                    result.addElement(i, j, sum);
                }
            }
        }

        return result;
    }

    void showSize() { cout << "Your matrix is: [" << R_size << "x" << C_size << "]\n"; }
};

//int main() {
//   SpareMatrix M1(5, 5), M2(5, 5);
//
//    M1.addElement(1, 1, 1); M1.addElement(1, 2, 0); M1.addElement(1, 3, 2);
//    M1.addElement(2, 1, 0); M1.addElement(2, 2, 3); M1.addElement(2, 3, 0);
//    M1.addElement(3, 1, 4); M1.addElement(3, 2, 0); M1.addElement(3, 3, 5);
//    M2.addElement(1, 1, 1); M2.addElement(1, 2, 0); M2.addElement(1, 3, 0);
//    M2.addElement(2, 1, 0); M2.addElement(2, 2, 2); M2.addElement(2, 3, 0);
//    M2.addElement(3, 1, 0); M2.addElement(3, 2, 0); M2.addElement(3, 3, 3);
//    cout << "Matrix 1:\n"; M1.print();
//    cout << "\nMatrix 2:\n"; M2.print();
//        cout << "Added matrix: \n";
//    SpareMatrix M3 = M1.AddMatrix(M2);
//    M3.print();
//    cout << "\nProduct of matrices:\n";
//    M3 = M1.MultiplyMatrix(M2);
// M3.print();
//   return 0;
//}