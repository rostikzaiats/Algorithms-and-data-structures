#include "pch.h"
#include"C:\Users\rosti\source\repos\DejkstraAlghorithm\DejkstraAlghorithm\main.cpp"
TEST(GraphTest, AddEdgeAndGetWeight) {
    Graph g(3);
    g.addEdge(0, 1, 5);
    EXPECT_EQ(g.getWeight(0, 1), 5);
    EXPECT_EQ(g.getWeight(1, 0), 5);
}


TEST(GraphTest, RemoveEdge) {
    Graph g(3);
    g.addEdge(0, 1, 10);
    g.removeEdge(0, 1);
    EXPECT_EQ(g.getWeight(0, 1), 0);
    EXPECT_EQ(g.getWeight(1, 0), 0);
}


TEST(GraphTest, DijkstraSimple) {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 3, 4);
    g.addEdge(3, 2, 1);

    int* dist = g.dejkstra(0);
    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 1);
    EXPECT_EQ(dist[2], 3); // ← Виправлено!
    EXPECT_EQ(dist[3], 4);

    delete[] dist;
}

TEST(GraphTest, DijkstraDisconnected) {
    Graph g(3);
    g.addEdge(0, 1, 3);
    int* dist = g.dejkstra(0);

    EXPECT_EQ(dist[0], 0);
    EXPECT_EQ(dist[1], 3);
    EXPECT_EQ(dist[2], INT_MAX); // Нема шляху

    delete[] dist;
}


TEST(GraphTest, ClearGraph) {
    Graph g(2);
    g.addEdge(0, 1, 8);
    g.clear();
    EXPECT_EQ(g.getWeight(0, 1), 0);
    EXPECT_EQ(g.getWeight(1, 0), 0);
}