
#include "pch.h"
#include"C:\Users\rosti\source\repos\Table\Table\Table.h"
TEST(TableTest, PutAndFind) {
    Table table;
    table.put(1, "Value1");
    table.put(2, "Value2");

    EXPECT_EQ(table.find(1), "Value1");
    EXPECT_EQ(table.find(2), "Value2");
}

TEST(TableTest, Contain) {
    Table table;
    table.put(1, "Value1");

    EXPECT_TRUE(table.contain(1));
    EXPECT_FALSE(table.contain(2));  
}

TEST(TableTest, Size) {
    Table table;
    EXPECT_EQ(table.Size(), 0);

    table.put(1, "Value1");
    EXPECT_EQ(table.Size(), 1);

    table.put(2, "Value2");
    EXPECT_EQ(table.Size(), 2);
}

TEST(TableTest, Del) {
    Table table;
    table.put(1, "Value1");
    table.put(2, "Value2");

    table.del(1);
    EXPECT_FALSE(table.contain(1));
    EXPECT_EQ(table.Size(), 1);

    table.del(2);
    EXPECT_FALSE(table.contain(2));
    EXPECT_EQ(table.Size(), 0);
}

TEST(TableTest, GetAllKeys) {
    Table table;
    table.put(1, "Value1");
    table.put(2, "Value2");

    size_t* keys = table.getAllKeys();
    EXPECT_EQ(keys[0], 1);
    EXPECT_EQ(keys[1], 2);
    delete[] keys; 
}

TEST(TableTest, GetAllData) {
    Table table;
    table.put(1, "Value1");
    table.put(2, "Value2");

    string* data = table.getAllData();
    EXPECT_EQ(data[0], "Value1");
    EXPECT_EQ(data[1], "Value2");
    delete[] data; 
}
