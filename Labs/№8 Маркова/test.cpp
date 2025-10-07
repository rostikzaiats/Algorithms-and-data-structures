#include "pch.h"
#include"C:\Users\rosti\source\repos\Markova\Markova\main.cpp"
TEST(StringTest, DefaultConstructor) {
    String s;
    EXPECT_EQ(s.getLength(), 0);
    EXPECT_EQ(s[0], '\0');
}

TEST(StringTest, CharArrayConstructor) {
    const char* text = "hello";
    String s(text);
    EXPECT_EQ(s.getLength(), 5);
    EXPECT_EQ(s[0], 'h');
    EXPECT_EQ(s[4], 'o');
}

TEST(StringTest, CopyConstructor) {
    String s1("hello");
    String s2(s1);
    EXPECT_EQ(s1.getLength(), s2.getLength());
    EXPECT_EQ(s1[0], s2[0]);
    EXPECT_EQ(s1[s1.getLength() - 1], s2[s2.getLength() - 1]);
}

TEST(StringTest, AssignmentOperator) {
    String s1("hello");
    String s2;
    s2 = s1;
    EXPECT_EQ(s1.getLength(), s2.getLength());
    EXPECT_EQ(s1[0], s2[0]);
    EXPECT_EQ(s1[s1.getLength() - 1], s2[s2.getLength() - 1]);
}

TEST(StringTest, Substring) {
    String s("hello world");
    String sub = s.substr(6, 5);
    EXPECT_EQ(sub, "world");
}

TEST(StringTest, Replace) {
    String s("hello world");
    s.replace(6, 5, "universe");
    EXPECT_EQ(s, "hello universe");
}


TEST(MarkovChangeTest, Constructor) {
    MarkovChange change("hello", "hi");
    EXPECT_EQ(change.GetDeletePart(), "hello");
    EXPECT_EQ(change.GetChangingPart(), "hi");
}
TEST(MarkovStepTest, NoChange) {
    String main_str("hello world");
    MarkovChange change("hi", "hey");
    EXPECT_FALSE(MarkovStep(main_str, change));
    EXPECT_EQ(main_str, "hello world");
}

TEST(MarkovStepTest, Change) {
    String main_str("hello world");
    MarkovChange change("hello", "hi");
    EXPECT_TRUE(MarkovStep(main_str, change));
    EXPECT_EQ(main_str, "hi world");
}


TEST(MarcovAlgorithmTest, NoChanges) {
    String main_str("hello world");
    MarkovChange production[] = {
        {"hi", "hey"},
        {"hey", "hi"}
    };
    int production_size = sizeof(production) / sizeof(production[0]);
    MarcovAlgorithm(main_str, production, production_size);
    EXPECT_EQ(main_str, "hello world");
}

TEST(MarcovAlgorithmTest, Changes) {
    String main_str("hello world");
    MarkovChange production[] = {
        {"hello", "hi"},
        {"world", "universe"}
    };
    int production_size = sizeof(production) / sizeof(production[0]);
    MarcovAlgorithm(main_str, production, production_size);
    EXPECT_EQ(main_str, "hi universe");
}
