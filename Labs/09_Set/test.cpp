#include "pch.h"
#include"C:\Users\rosti\source\repos\set\set\main.cpp"

TEST(BitSetTest, AddFunction) {
    BitSet set;
    set.add('a');
    EXPECT_TRUE(set.contain('a'));
    EXPECT_FALSE(set.contain('b'));
}

TEST(BitSetTest, RemoveFunction) {
    BitSet set;
    set.add('a');
    set.remove('a');
    EXPECT_FALSE(set.contain('a'));
}

TEST(BitSetTest, ContainFunction) {
    BitSet set;
    set.add('z');
    EXPECT_TRUE(set.contain('z'));
    EXPECT_FALSE(set.contain('a'));
}

TEST(BitSetTest, IsEmptyFunction) {
    BitSet set;
    EXPECT_TRUE(set.isEmpty());
    set.add('a');
    EXPECT_FALSE(set.isEmpty());
}


TEST(BitSetTest, UnionWithFunction) {
    BitSet set1;
    BitSet set2;
    set1.add('a');
    set1.add('b');
    set2.add('b');
    set2.add('c');
    BitSet unionSet = set1.unionWith(set2);
    EXPECT_TRUE(unionSet.contain('a'));
    EXPECT_TRUE(unionSet.contain('b'));
    EXPECT_TRUE(unionSet.contain('c'));
}


TEST(BitSetTest, IntersectionOfFunction) {
    BitSet set1;
    BitSet set2;
    set1.add('a');
    set1.add('b');
    set2.add('b');
    set2.add('c');
    BitSet intersectionSet = set1.IntersectionOf(set2);
    EXPECT_FALSE(intersectionSet.contain('a'));
    EXPECT_TRUE(intersectionSet.contain('b'));
    EXPECT_FALSE(intersectionSet.contain('c'));
}


TEST(BitSetTest, DistinctionWithFunction) {
    BitSet set1;
    BitSet set2;
    set1.add('a');
    set1.add('b');
    set2.add('b');
    set2.add('c');
    BitSet distinctionSet = set1.DistinctionWith(set2);
    EXPECT_TRUE(distinctionSet.contain('a'));
    EXPECT_FALSE(distinctionSet.contain('b'));
    EXPECT_FALSE(distinctionSet.contain('c'));
}

