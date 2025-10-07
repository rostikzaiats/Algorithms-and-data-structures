//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"
//#include "Stack.h"
//#include <stack>
//using namespace std;
//TEST_CASE("Test #1: Create stack, Capacity & Size. ")
//{
//	size_t size = 5;
//	MyStack S1(size);
//	CHECK(S1.GetCapacity() == size);
//	CHECK(S1.isEmpty() == true);
//	S1.push(31);
//	CHECK(S1.isEmpty() == false);
//	CHECK(S1.GetOccupancy() == 1);
//	int value = S1.pop();
//	CHECK(S1.isEmpty() == true);
//	CHECK(value == 31);
//}
//TEST_CASE("Test #2: Full & Empty stack")
//{
//	size_t size = 3;
//	MyStack S1(size);
//	CHECK(S1.isEmpty() == true);
//	S1.push(111);
//	S1.push(222);
//	S1.push(333);
//	CHECK(S1.GetOccupancy() == 3);
//	CHECK(S1.isFull() == true);
//	S1.pop();
//	S1.pop();
//	S1.pop();
//	CHECK(S1.GetOccupancy() == 0);
//	CHECK(S1.isEmpty() == true);
//
//}
//TEST_CASE("Test #3: Push to full stack")
//{
//	size_t size = 2;
//	MyStack S1(size);
//	CHECK(S1.isEmpty() == true);
//	S1.push(10);
//	S1.push(20);
//	CHECK(S1.isFull() == true);
//	S1.push(30);
//	CHECK(S1.pop() == 20);
//}
//
//TEST_CASE("Test #4: Pop from empty stack")
//{
//	size_t size = 3;
//	MyStack S1(size);
//	CHECK(S1.isEmpty() == true);
//	CHECK(S1.pop() == -1);
//}
//
//TEST_CASE("Test #STL stack")
//{
//	std::stack<int> s1;
//	CHECK(s1.empty() == true);
//	s1.push(21);
//	CHECK(s1.size() == 1);
//	s1.push(22);
//	CHECK(s1.size() == 2);
//	CHECK(s1.empty() == false);
//	CHECK(s1.top() == 22);
//	s1.pop();
//	CHECK(s1.top() == 21);
//	s1.pop();
//	CHECK(s1.empty() == true);
//	
//	for (int i = 0; i < 1000; ++i) {
//		s1.push(i);
//	}
//
//	CHECK(s1.size() == 1000);
//
//	for (int i = 999; i >= 0; --i) {
//		CHECK(s1.top() == i);
//		s1.pop();
//	}
//	CHECK(s1.empty() == true);
//}
