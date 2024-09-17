//kkorenn1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include <vector>
#include <stdexcept>

// Function to print a vector of nodes (for debugging purposes)
template<typename gen>
void print_node_vector(const std::vector<Node<gen>*>& nodes) {
    for (const auto& node : nodes) {
        std::cout << node->get_value() << " ";
    }
    std::cout << std::endl;
}

// Test basic tree operations
TEST_CASE("Basic tree operations") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);

    Tree<int, 3> tree;
    tree.add_root(root);
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);

    CHECK(root.get_nodes().size() == 2); // root should have 2 children
    CHECK(child1.get_nodes().empty()); // child1 should have no children
    CHECK(child2.get_nodes().empty()); // child2 should have no children

    CHECK(root.node_count() == 1); // root has 2 children, so node count should be 1 (for sub-nodes)
    CHECK(child1.node_count() == -1); // child1 has no sub-nodes
    CHECK(child2.node_count() == -1); // child2 has no sub-nodes
}

// Test traversal iterators
TEST_CASE("Traversal iterators with output") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> grandchild1(4);
    Node<int> grandchild2(5);

    Tree<int, 3> tree;
    tree.add_root(root);
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    // Test Pre-order Iterator
    SUBCASE("Pre-order traversal") {
        std::vector<int> result;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result.push_back((*it)->get_value());
        }
        CHECK(result == std::vector<int>{1,2,4,5,3});
    }

    // Test Post-order Iterator
    SUBCASE("Post-order traversal") {
        std::vector<int> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back((*it)->get_value());
        }
        CHECK(result == std::vector<int>{4, 5, 2, 3, 1});
    }

    // Test In-order Iterator
    SUBCASE("In-order traversal") {
        std::vector<int> result;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result.push_back((*it)->get_value());
        }
        CHECK(result == std::vector<int>{4, 2, 5, 1, 3}); // This assumes the in-order traversal is implemented correctly.
    }

    // Test DFS Iterator
    SUBCASE("DFS traversal") {
        std::vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back((*it)->get_value());
        }
        CHECK(result == std::vector<int>{1, 2, 4, 5, 3}); // DFS may differ based on implementation details.
    }

    // Test BFS Iterator
    SUBCASE("BFS traversal") {
        std::vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back((*it)->get_value());
        }
        CHECK(result == std::vector<int>{1, 2, 3, 4, 5});
    }
}

// Test heap functionality
TEST_CASE("Heap functionality") {
   Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    SUBCASE("Create heap") {
        tree.make_heap();

        const auto& heap = tree.get_heap(); 

        for (size_t i = 0; i < heap.size(); ++i) {
            int parentIndex = (i - 1) / 2;
            if (parentIndex >= 0) {
                CHECK(heap[parentIndex]->get_value() <= heap[i]->get_value());
            }
        }
    }
}

// Test large tree
TEST_CASE("Large tree") {
    Tree<int, 50> largeTree;
    Node<int> root(0);
    largeTree.add_root(root);

    // Add 50 nodes in a single level
    std::vector<Node<int>*> nodes;
    for (int i = 1; i <= 50; ++i) {
        nodes.push_back(new Node<int>(i));
        largeTree.add_sub_node(root, *nodes.back());
    }

    // Test large tree structure
    CHECK(root.get_nodes().size() == 50);
    for (const auto& node : nodes) {
        CHECK(node->get_nodes().empty());
    }

    // Clean up nodes
    for (auto node : nodes) {
        delete node;
    }
}
