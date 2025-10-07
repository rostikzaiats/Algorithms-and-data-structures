
#include"pch.cpp"
#include "pch.h"

TEST(HashTableTest, Initialization) {
    HashTable ht;
    EXPECT_EQ(ht.Rozmir(), 0);
}


TEST(HashTableTest, InsertAndFind) {
    HashTable ht;
    ht.insert(10, "Apple");
    ht.insert(20, "Banana");

    Node res1 = ht.find(10);
    Node res2 = ht.find(20);
    Node res3 = ht.find(30);

    EXPECT_EQ(res1.key, 10);
    EXPECT_EQ(res1.value, "Apple");

    EXPECT_EQ(res2.key, 20);
    EXPECT_EQ(res2.value, "Banana");

    EXPECT_EQ(res3.key, -1); 
}


TEST(HashTableTest, Delete) {
    HashTable ht;
    ht.insert(10, "Apple");
    ht.insert(20, "Banana");

    ht.delet(10);
    Node res1 = ht.find(10);
    Node res2 = ht.find(20);

    EXPECT_EQ(res1.key, -1);
    EXPECT_EQ(res2.key, 20); 
}


TEST(HashTableTest, ClearTable) {
    HashTable ht;
    ht.insert(10, "Apple");
    ht.insert(20, "Banana");
    ht.clear();

    EXPECT_EQ(ht.Rozmir(), 0);
    EXPECT_EQ(ht.find(10).key, -1);
    EXPECT_EQ(ht.find(20).key, -1);
}


TEST(HashTableTest, Resize) {
    HashTable ht;
    for (int i = 0; i < 21; i++) {
        ht.insert(i, "Value" + to_string(i));
    }
    EXPECT_GT(ht.Rozmir(), 20);

    Node res = ht.find(20);
    EXPECT_EQ(res.key, 20);
    EXPECT_EQ(res.value, "Value20");
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}