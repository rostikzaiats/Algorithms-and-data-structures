#include"pch.h"
#include "C:\Users\rosti\source\repos\Stack\Stack\Stack.cpp"
#include "C:\Users\rosti\source\repos\Stack\Stack\ZPZ.cpp"
#include <gtest/gtest.h>


TEST(EvaluateV1Tests, SimpleAddition) {
    EXPECT_EQ(evaluate_v1("3 4 +"), 7);
}

TEST(EvaluateV1Tests, SimpleSubtraction) {
    EXPECT_EQ(evaluate_v1("10 4 -"), 6);
}

TEST(EvaluateV1Tests, SimpleMultiplication) {
    EXPECT_EQ(evaluate_v1("3 4 *"), 12);
}

TEST(EvaluateV1Tests, SimpleDivision) {
    EXPECT_EQ(evaluate_v1("12 4 /"), 3);
}

TEST(EvaluateV1Tests, DivisionByZero) {
    EXPECT_ANY_THROW(evaluate_v1("12 0 /")); // ловимо виняток
}
TEST(ToPostfixV1Tests, SimpleExpression) {
    EXPECT_EQ(to_Postfix_v1("3 + 4"), "3 4 + ");
}

TEST(ToPostfixV1Tests, ExpressionWithParentheses) {
    EXPECT_EQ(to_Postfix_v1("(3 + 4) * 2"), "3 4 + 2 * ");
}

TEST(ToPostfixV1Tests, ComplexExpression) {
    EXPECT_EQ(to_Postfix_v1("10 + 2 * 3"), "10 2 3 * + ");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}