#include "pch.h"
#include"C:\Users\rosti\source\repos\AVL_Tree\AVL_Tree\main.cpp"
TEST(AVLTreeTest, InsertAndBalance) {
    Tree* root = nullptr;

    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

        EXPECT_EQ(root->value, 20);  

    
    EXPECT_EQ(root->height, 2);

    
    EXPECT_EQ(root->left->value, 10);
    EXPECT_EQ(root->right->value, 30);
}

TEST(AVLTreeTest, LeftRotation) {
    Tree* root = nullptr;

    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    
    EXPECT_EQ(root->value, 20);
    EXPECT_EQ(root->left->value, 10);
    EXPECT_EQ(root->right->value, 30);
}

TEST(AVLTreeTest, RightRotation) {
    Tree* root = nullptr;

    
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);

    
    EXPECT_EQ(root->value, 20);
    EXPECT_EQ(root->left->value, 10);
    EXPECT_EQ(root->right->value, 30);
}

TEST(AVLTreeTest, DoubleRotation) {
    Tree* root = nullptr;

        root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);

    EXPECT_EQ(root->value, 20);
    EXPECT_EQ(root->left->value, 10);
    EXPECT_EQ(root->right->value, 30);
}

TEST(AVLTreeTest, HeightUpdate) {
    Tree* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    EXPECT_EQ(root->height, 2);
    EXPECT_EQ(root->left->height, 1);
    EXPECT_EQ(root->right->height, 1);
}