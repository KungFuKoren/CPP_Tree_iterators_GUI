#include "tree.hpp"
#include "node.hpp" // Ensure this includes your Node class definition
#include "complex.hpp"
#include <iostream>


void createAndPrintComplexTree() {
    // Create a tree with Complex nodes
    Tree<Complex, 2> complexTree;

    // Create Complex nodes
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3(5.0, 6.0);
    Complex c4(7.0, 8.0);
    Complex c5(9.0, 10.0);

    Node<Complex> root(c1);
    Node<Complex> child1(c2);
    Node<Complex> child2(c3);
    Node<Complex> child3(c4);
    Node<Complex> child4(c5);

    // Build the tree structure
    complexTree.add_root(root);
    complexTree.add_sub_node(root, child1);
    complexTree.add_sub_node(root, child2);
    complexTree.add_sub_node(child1, child3);
    complexTree.add_sub_node(child1, child4);

    // Print the tree using std::cout
    std::cout << "Complex Tree:" << std::endl;
    std::cout << complexTree << std::endl;
}

void createAndPrintTree1() {
    // Create first tree
    Tree<double, 2> tree1;

    // Create nodes
    Node<double> root1(10);
    Node<double> child1_1(20);
    Node<double> child1_2(30);
    Node<double> child1_3(40);

    // Build the tree structure
    tree1.add_root(root1);
    tree1.add_sub_node(root1, child1_1);
    tree1.add_sub_node(root1, child1_2);
    tree1.add_sub_node(root1, child1_3);

    // Print the tree using std::cout (this will use drawTreeGUI method)
    std::cout << "Tree 1:" << std::endl;
    std::cout << tree1 << std::endl;

    // Create heap and print (if k == 2, it will create and display the heap)
    try {
        tree1.make_heap();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Visualize the tree using SFML
    // The tree visualization will happen in the drawTreeGUI method
}

void createAndPrintTree2() {
    // Create second tree
    Tree<double, 2> tree2;

    // Create nodes
    Node<double> root2(50);
    Node<double> child2_1(60);
    Node<double> child2_2(70);
    Node<double> child2_3(80);
    Node<double> child2_4(90);

    // Build the tree structure
    tree2.add_root(root2);
    tree2.add_sub_node(root2, child2_1);
    tree2.add_sub_node(root2, child2_2);
    tree2.add_sub_node(child2_1, child2_3);
    tree2.add_sub_node(child2_1, child2_4);

    // Print the tree using std::cout (this will use drawTreeGUI method)
    std::cout << "Tree 2:" << std::endl;
    std::cout << tree2 << std::endl;

    // Create heap and print (if k == 2, it will create and display the heap)
    try {
        tree2.make_heap();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Visualize the tree using SFML
    // The tree visualization will happen in the drawTreeGUI method
}

void createAndPrintTree3() {
    // Create third tree
    Tree<double, 3> tree3;

    // Create nodes
    Node<double> root3(5);
    Node<double> child3_1(15);
    Node<double> child3_2(25);
    Node<double> child3_3(35);
    Node<double> child3_4(45);
    Node<double> child3_5(55);

    // Build the tree structure
    tree3.add_root(root3);
    tree3.add_sub_node(root3, child3_1);
    tree3.add_sub_node(root3, child3_2);
    tree3.add_sub_node(root3, child3_3);
    tree3.add_sub_node(root3, child3_4);
    tree3.add_sub_node(root3, child3_5);

    // Print the tree using std::cout (this will use drawTreeGUI method)
    std::cout << "Tree 3:" << std::endl;
    std::cout << tree3 << std::endl;

    // Create heap and print (if k == 3, it will create and display the heap)
    try {
        tree3.make_heap();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Visualize the tree using SFML
    // The tree visualization will happen in the drawTreeGUI method
}

void createAndPrintTree4() {
    // Create fourth tree
    Tree<double, 3> tree4;

    // Create nodes
    Node<double> root4(100);
    Node<double> child4_1(110);
    Node<double> child4_2(120);
    Node<double> child4_3(130);
    Node<double> child4_4(140);
    Node<double> child4_5(150);
    Node<double> child4_6(160);

    // Build the tree structure
    tree4.add_root(root4);
    tree4.add_sub_node(root4, child4_1);
    tree4.add_sub_node(root4, child4_2);
    tree4.add_sub_node(root4, child4_3);
    tree4.add_sub_node(child4_1, child4_4);
    tree4.add_sub_node(child4_1, child4_5);
    tree4.add_sub_node(child4_2, child4_6);

    // Print the tree using std::cout (this will use drawTreeGUI method)
    std::cout << "Tree 4:" << std::endl;
    std::cout << tree4 << std::endl;

    // Create heap and print (if k == 3, it will create and display the heap)
    try {
        tree4.make_heap();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Visualize the tree using SFML
    // The tree visualization will happen in the drawTreeGUI method
}

int main() {
    createAndPrintTree1();
    createAndPrintTree2();
    createAndPrintTree3();
    createAndPrintTree4();
    createAndPrintComplexTree();

    return 0;
}
