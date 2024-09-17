//kkorenn1@gmail.com

Tree Data Structure
Overview - 

This repository contains a C++ implementation of a tree data structure with a variety of iterators and visualization features. The implementation includes the following components:

    Node Class: Represents a node in the tree. Each node stores a value, a string representation of the value, and pointers to its child nodes.
    Tree Class: Represents a tree structure where each node can have up to k children. It supports various traversal methods, heap operations, and visualizations using SFML.



Node Class
Header File: node.hpp

The Node class template defines a node in the tree with the following features:

    Constructors:
        Node(const gen& val): Initializes a node with a value.
        Node(const gen& val, const std::string& str): Initializes a node with a value and a string representation.

    Getters:
        const gen& get_value() const: Returns the value of the node.
        const std::vector<Node<gen>*>& get_nodes() const: Returns the child nodes.
        int node_count() const: Returns the number of child nodes (subtracts 1 from the actual count).
        std::string to_str() const: Returns the string representation of the value.

    Methods:
        void add_node(Node<gen>* new_node): Adds a child node.



Tree Class
Header File: tree.hpp

The Tree class template provides a tree structure with various iterators and features:

    Constructors & Destructor:
        Tree(): Initializes an empty tree.
        ~Tree(): Destructor (currently empty).

    Methods:
        void add_sub_node(Node<gen>& head, Node<gen>& to_add): Adds a child node to a given node.
        void add_root(Node<gen>& r_node): Sets the root of the tree.

    Iterators:
        PreOrderIterator: Iterates over nodes in pre-order traversal.
        PostOrderIterator: Iterates over nodes in post-order traversal.
        DFSIterator: Iterates over nodes in depth-first search (DFS) traversal.
        InOrderIterator: Iterates over nodes in in-order traversal.
        BFSIterator: Iterates over nodes in breadth-first search (BFS) traversal.

    Heap Operations:
        void createHeap(): Creates a heap from the tree nodes.
        typename std::vector<Node<gen>*>::iterator make_heap(): Builds a heap if the tree is binary (k == 2).

    Visualization:
        void drawTreeGUI(): Opens an SFML window to visualize the tree.
        void drawTree(sf::RenderWindow& window, Node<gen>* node, float x, float y, float xOffset, float yOffset): Draws the tree structure using SFML.

    Friends:
        friend std::ostream& operator<<(std::ostream& os, Tree& tree): Prints the tree using the drawTreeGUI method.

Requirements - 

    SFML: The visualization requires SFML for graphical output.




Tree Visualization Example


This project includes an example of how to use the Tree and Node classes to create and visualize trees with different configurations. The example demonstrates trees with both double and Complex types, visualized using std::cout and SFML.
Overview of main.cpp

The main.cpp file contains functions to create and print four different trees, as well as a tree with Complex nodes. Here's a brief overview of each function:

    createAndPrintComplexTree:
        Creates a tree of Complex nodes.
        Builds a tree structure with complex number nodes.
        Prints the tree using std::cout, and visualizes it using SFML.

    createAndPrintTree1:
        Creates a binary tree of double nodes.
        Builds a tree structure and prints it.
        Attempts to create a heap from the tree (only works if k == 2).
        Visualizes the tree using SFML.

    createAndPrintTree2:
        Similar to createAndPrintTree1, but with different node values.
        Builds a tree structure and attempts to create a heap.
        Visualizes the tree using SFML.

    createAndPrintTree3:
        Creates a ternary tree of double nodes.
        Builds a tree structure, prints it, and attempts to create a heap (only works if k == 3).
        Visualizes the tree using SFML.

    createAndPrintTree4:
        Creates a larger ternary tree of double nodes.
        Builds a tree structure, prints it, and attempts to create a heap.
        Visualizes the tree using SFML.




To operate : 
g++ -Wall -std=c++17 -o main main.cpp complex.cpp -lsfml-graphics -lsfml-window -lsfml-system
make run
