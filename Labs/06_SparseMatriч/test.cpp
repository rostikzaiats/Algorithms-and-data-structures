#include "pch.h"
#include "..//Spare Matrix/main.cpp"
TEST(SparseMatrixTest, ConstructorAndBasicOperations) {
    SpareMatrix m(3, 3);

    EXPECT_EQ(m.GetValue(1, 1), 0);
    EXPECT_EQ(m.GetValue(2, 2), 0);
    EXPECT_EQ(m.GetValue(3, 3), 0);

    m.addElement(1, 1, 5);
    m.addElement(2, 2, 10);
    m.addElement(3, 3, 15);

    EXPECT_EQ(m.GetValue(1, 1), 5);
    EXPECT_EQ(m.GetValue(2, 2), 10);
    EXPECT_EQ(m.GetValue(3, 3), 15);

    m.addElement(1, 2, 0);
    EXPECT_EQ(m.GetValue(1, 2), 0);
}

TEST(SparseMatrixTest, CopyConstructor) {
    SpareMatrix original(3, 3);
    original.addElement(1, 1, 1);
    original.addElement(2, 2, 2);
    original.addElement(3, 3, 3);

    SpareMatrix copy(original);

    EXPECT_EQ(copy.GetValue(1, 1), 1);
    EXPECT_EQ(copy.GetValue(2, 2), 2);
    EXPECT_EQ(copy.GetValue(3, 3), 3);

    original.addElement(1, 1, 10);
    EXPECT_EQ(copy.GetValue(1, 1), 1);
}

TEST(SparseMatrixTest, AssignmentOperator) {
    SpareMatrix m1(3, 3);
    m1.addElement(1, 1, 1);
    m1.addElement(2, 2, 2);
    m1.addElement(3, 3, 3);

    SpareMatrix m2(1, 1);
    m2 = m1;

    EXPECT_EQ(m2.GetValue(1, 1), 1);
    EXPECT_EQ(m2.GetValue(2, 2), 2);
    EXPECT_EQ(m2.GetValue(3, 3), 3);

    m2 = m2;
    EXPECT_EQ(m2.GetValue(1, 1), 1);
}

TEST(SparseMatrixTest, AddMatrix) {
    SpareMatrix m1(3, 3);
    m1.addElement(1, 1, 1);
    m1.addElement(2, 2, 2);
    m1.addElement(3, 3, 3);

    SpareMatrix m2(3, 3);
    m2.addElement(1, 1, 4);
    m2.addElement(2, 2, 5);
    m2.addElement(3, 3, 6);

    SpareMatrix result = m1.AddMatrix(m2);

    EXPECT_EQ(result.GetValue(1, 1), 5);
    EXPECT_EQ(result.GetValue(2, 2), 7);
    EXPECT_EQ(result.GetValue(3, 3), 9);


    m1.addElement(1, 2, 7);
    m2.addElement(2, 1, 8);
    result = m1.AddMatrix(m2);

    EXPECT_EQ(result.GetValue(1, 2), 7);  // Тільки в m1
    EXPECT_EQ(result.GetValue(2, 1), 8);  // Тільки в m2
    EXPECT_EQ(result.GetValue(1, 1), 5);  // В обох матрицях
}

TEST(SparseMatrixTest, MultiplyMatrix) {
    SpareMatrix m1(3, 3);
    m1.addElement(1, 1, 1); m1.addElement(1, 3, 2);
    m1.addElement(2, 2, 3);
    m1.addElement(3, 1, 4); m1.addElement(3, 3, 5);

    SpareMatrix m2(3, 3);
    m2.addElement(1, 1, 1);
    m2.addElement(2, 2, 2);
    m2.addElement(3, 3, 3);

    SpareMatrix result = m1.MultiplyMatrix(m2);

    EXPECT_EQ(result.GetValue(1, 1), 1);
    EXPECT_EQ(result.GetValue(1, 2), 0);
    EXPECT_EQ(result.GetValue(1, 3), 6);
    EXPECT_EQ(result.GetValue(2, 2), 6);
    EXPECT_EQ(result.GetValue(3, 1), 4);
    EXPECT_EQ(result.GetValue(3, 3), 15);

   
    SpareMatrix m3(2, 2);
    SpareMatrix badResult = m1.MultiplyMatrix(m3);
    EXPECT_EQ(badResult.GetValue(1, 1), 0);
}

TEST(SparseMatrixTest, DeleteElement) {
    SpareMatrix m(3, 3);
    m.addElement(1, 1, 1);
    m.addElement(2, 2, 2);
    m.addElement(3, 3, 3);

    EXPECT_EQ(m.GetValue(1, 1), 1);
    m.delElement(1, 1);
    EXPECT_EQ(m.GetValue(1, 1), 0);

    EXPECT_NO_THROW(m.delElement(1, 2));
}

TEST(SparseMatrixTest, BoundaryConditions) {
    SpareMatrix m(3, 3);

    EXPECT_EQ(m.GetValue(0, 1), 0);
    EXPECT_EQ(m.GetValue(1, 0), 0);
    EXPECT_EQ(m.GetValue(4, 1), 0);
    EXPECT_EQ(m.GetValue(1, 4), 0);

    EXPECT_NO_THROW(m.addElement(0, 1, 1));
    EXPECT_NO_THROW(m.addElement(1, 0, 1));
    EXPECT_NO_THROW(m.delElement(0, 1));
    EXPECT_NO_THROW(m.delElement(1, 0));
}

TEST(SparseMatrixTest, ZeroHandling) {
    SpareMatrix m(3, 3);
    m.addElement(1, 1, 1);
    m.addElement(1, 2, 0); 

    EXPECT_EQ(m.GetValue(1, 1), 1);
    EXPECT_EQ(m.GetValue(1, 2), 0);

    m.addElement(1, 1, 0);
    EXPECT_EQ(m.GetValue(1, 1), 0);
}

TEST(SparseMatrixTest, LargeMatrix) {
    const size_t size = 100;
    SpareMatrix m(size, size);

    for (size_t i = 1; i <= size; i++) {
        m.addElement(i, i, static_cast<int>(i));
    }

    for (size_t i = 1; i <= size; i++) {
        EXPECT_EQ(m.GetValue(i, i), static_cast<int>(i));
    }

    EXPECT_EQ(m.GetValue(1, 2), 0);
    EXPECT_EQ(m.GetValue(size, size - 1), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}