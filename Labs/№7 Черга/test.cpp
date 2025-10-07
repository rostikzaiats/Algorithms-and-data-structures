#include "pch.h"
#include"..//queue/main.cpp"

TEST(QueueTest, BasicOperations) {
    Queue<int> q;

    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.sizeOf(), 0);

    q.enqueue(10);
    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.sizeOf(), 1);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 10);

    q.enqueue(20);
    EXPECT_EQ(q.sizeOf(), 2);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 20);

    EXPECT_EQ(q.dequeue(), 10);
    EXPECT_EQ(q.sizeOf(), 1);
    EXPECT_EQ(q.front(), 20);

    q.clear();
    EXPECT_TRUE(q.isEmpty());
}

TEST(QueueTest, EmptyQueueExceptions) {
    Queue<int> q;

    EXPECT_THROW(q.front(), const char*);
    EXPECT_THROW(q.back(), const char*);
    EXPECT_THROW(q.dequeue(), const char*);
}


TEST(PriorityQueueTest, PriorityOrder) {
    priorityQueue<string> pq;

    pq.enqueue("Low", 3);
    pq.enqueue("High", 1);
    pq.enqueue("Medium", 2);

    EXPECT_EQ(pq.front(), "High");
    pq.dequeue();

    EXPECT_EQ(pq.front(), "Medium");
    pq.dequeue();

    EXPECT_EQ(pq.front(), "Low");
}

TEST(PriorityQueueTest, SamePriority) {
    priorityQueue<string> pq;

    pq.enqueue("First", 1);
    pq.enqueue("Second", 1);
    EXPECT_EQ(pq.front(), "First");
}

TEST(PriorityQueueTest, ComplexOperations) {
    priorityQueue<int> pq;

    for (int i = 10; i >= 1; i--) {
        pq.enqueue(i, i);
    }

    for (int i = 1; i <= 10; i++) {
        EXPECT_EQ(pq.front(), i);
        pq.dequeue();
    }

    EXPECT_TRUE(pq.isEmpty());
}



TEST(StlQueueTest, BasicOperations) {
    std::queue<int> q;

    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);

    q.push(10);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 10);

    q.push(20);
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 20);

    q.pop();
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 20);

   
    while (!q.empty()) {
        q.pop();
    }
    EXPECT_TRUE(q.empty());
}


TEST(CompareTest, SameBehavior) {
    Queue<int> myQ;
    std::queue<int> stlQ;

  
    for (int i = 1; i <= 5; ++i) {
        myQ.enqueue(i);
        stlQ.push(i);
    }

    EXPECT_EQ(myQ.sizeOf(), stlQ.size());

    while (!myQ.isEmpty() && !stlQ.empty()) {
        EXPECT_EQ(myQ.front(), stlQ.front());
        EXPECT_EQ(myQ.back(), stlQ.back());

        myQ.dequeue();
        stlQ.pop();
    }

    EXPECT_TRUE(myQ.isEmpty());
    EXPECT_TRUE(stlQ.empty());
}
int main(int argc, char** argv) {
	// ²í³ö³àë³çàö³ÿ Google Test
	::testing::InitGoogleTest(&argc, argv);
    int test_result = RUN_ALL_TESTS();
	return 0;
}