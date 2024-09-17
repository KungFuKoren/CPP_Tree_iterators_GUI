//kkorenn1@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <unordered_set>
#include <algorithm>
#include <SFML/Graphics.hpp>

template<typename gen, int k = 2>
class Tree {
public:
    Tree() : root(nullptr) {}

    ~Tree() {
    }

    void add_sub_node(Node<gen>& head, Node<gen>& to_add) {
        if (head.node_count() > k || k == 0) {
            throw std::runtime_error("Can't add! Already got k subnodes");
        }
        head.add_node(&to_add);
        tree_nodes.push_back(&to_add);
    }

    void add_root(Node<gen>& r_node) {
        root = &r_node;
        tree_nodes.push_back(root);
    }

    class PreOrderIterator {
    public:
        explicit PreOrderIterator(Node<gen>* node) {
            if (node) {
                stack.push(node);
            }
        }

        bool operator==(const PreOrderIterator& other) const {
            return stack == other.stack;
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !(*this == other);
        }

        Node<gen>* operator*() const {
            return stack.empty() ? nullptr : stack.top();
        }

        Node<gen>* operator->() const {
            return stack.empty() ? nullptr : stack.top();
        }

        PreOrderIterator& operator++() {
            if (!stack.empty()) {
                Node<gen>* node = stack.top();
                stack.pop();
                const auto& children = node->get_nodes();
                for (auto it = children.rbegin(); it != children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }

    private:
        std::stack<Node<gen>*> stack;
    };

    // Post-order Iterator
    class PostOrderIterator {
    public:
        explicit PostOrderIterator(Node<gen>* startNode) {
            if (startNode) {
                stack1.push(startNode);
                while (!stack1.empty()) {
                    Node<gen>* node = stack1.top();
                    stack1.pop();
                    stack2.push(node);
                    const auto& children = node->get_nodes();
                    for (const auto& child : children) {
                        stack1.push(child);
                    }
                }
            }
        }

        Node<gen>* operator*() {
            return stack2.empty() ? nullptr : stack2.top();
        }

        Node<gen>* operator->() {
            return stack2.empty() ? nullptr : stack2.top();
        }

        PostOrderIterator& operator++() {
            if (!stack2.empty()) {
                stack2.pop();
            }
            return *this;
        }

        bool operator==(const PostOrderIterator& other) const {
            return stack2 == other.stack2;
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !(*this == other);
        }

    private:
        std::stack<Node<gen>*> stack1;
        std::stack<Node<gen>*> stack2;
    };

    class DFSIterator {
    public:
        explicit DFSIterator(Node<gen>* startNode, bool is_end = false) : is_end(is_end) {
            if (!is_end && startNode) {
                stack.push(startNode);
                visited.insert(startNode);
            }
        }

        Node<gen>* operator*() {
            return stack.empty() ? nullptr : stack.top();
        }

        Node<gen>* operator->() {
            return stack.empty() ? nullptr : stack.top();
        }

        DFSIterator& operator++() {
            if (stack.empty()) {
                return *this;
            }

            Node<gen>* current = stack.top();
            stack.pop();

            const auto& children = current->get_nodes();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    stack.push(*it);
                    visited.insert(*it);
                }
            }

            return *this;
        }

        bool operator==(const DFSIterator& other) const {
            return (is_end && other.is_end) || (stack.empty() && other.stack.empty());
        }

        bool operator!=(const DFSIterator& other) const {
            return !(*this == other);
        }

    private:
        std::stack<Node<gen>*> stack;
        std::unordered_set<Node<gen>*> visited;
        bool is_end;  
    };

    class InOrderIterator {
    public:
        explicit InOrderIterator(Node<gen>* startNode) {
            if (startNode) {
                push_left(startNode);
            }
        }

        Node<gen>* operator*() const {
            return node_stack.empty() ? nullptr : node_stack.top();
        }

        Node<gen>* operator->() const {
            return node_stack.empty() ? nullptr : node_stack.top();
        }

        InOrderIterator& operator++() {
            if (node_stack.empty()) {
                return *this;
            }
            
            Node<gen>* current = node_stack.top();
            node_stack.pop();
            if (current) {
                const auto& children = current->get_nodes();
                
                if (children.size() > 1) { 
                    push_left(children[1]); 
                }
            }
            return *this;
        }

        bool operator==(const InOrderIterator& other) const {
            return node_stack == other.node_stack;
        }

        bool operator!=(const InOrderIterator& other) const {
            return !(*this == other);
        }

    private:
        std::stack<Node<gen>*> node_stack;

        void push_left(Node<gen>* node) {
            while (node) {
                node_stack.push(node);
                const auto& children = node->get_nodes();
                // Assuming the first child is the leftmost child
                node = (children.size() > 0) ? children[0] : nullptr;
            }
        }
    };

    // BFS Iterator
    class BFSIterator {
    public:
        explicit BFSIterator(Node<gen>* startNode) {
            if (startNode) {
                queue.push(startNode);
            }
        }
        Node<gen>* operator*() {
            return queue.empty() ? nullptr : queue.front();
        }

        Node<gen>* operator->() {
            return queue.empty() ? nullptr : queue.front();
        }

        BFSIterator& operator++() {
            if (queue.empty()) {
                return *this;
            }

            Node<gen>* current = queue.front();
            queue.pop();

            const auto& children = current->get_nodes();
            for (const auto& child : children) {
                queue.push(child);
            }
            return *this;
        }
        bool operator==(const BFSIterator& other) const {
            return queue == other.queue;
        }
        bool operator!=(const BFSIterator& other) const {
            return !(*this == other);
        }

    private:
        std::queue<Node<gen>*> queue;
    };

    InOrderIterator begin_in_order() const {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() const {
        return InOrderIterator(nullptr);
    }

    PreOrderIterator begin_pre_order() const {
        return PreOrderIterator(root);
    }
    
    PreOrderIterator end_pre_order() const {
        return PreOrderIterator(nullptr);
    }

    PostOrderIterator begin_post_order() const {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() const {
        return PostOrderIterator(nullptr);
    }

    DFSIterator begin_dfs_scan() const {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() const {
        return DFSIterator(nullptr);
    }

    BFSIterator begin_bfs_scan() const {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() const {
        return BFSIterator(nullptr);
    }

 
    DFSIterator begin() const {
        return begin_dfs_scan();
    }

    DFSIterator end() const {
        return end_dfs_scan(); 
    }

 

    void createHeap(){
        for(const auto& node : this->tree_nodes){
            heap.push_back(node);
            heapify(heap.size() -1);
        }
    }

    typename std::vector<Node<gen>*>::iterator make_heap(){
        if(k == 2){
            createHeap();
            return heap.begin();
        }
        else{
            throw std::runtime_error("Isnt a binary tree");
        }
    }



    friend std::ostream& operator<<(std::ostream& os , Tree& tree){
        tree.drawTreeGUI();
        return os;
    }
    

private:
    Node<gen>* root;
    std::vector<Node<gen>*> heap;
    std::vector<Node<gen>*> tree_nodes;

    void heapify(int i){
        while ( i > 0){
            int p_num = (i - 1)/2;
            if(heap[p_num]->get_value() > heap[i]->get_value()){
                std::swap(heap[p_num], heap[i]);
                i = p_num;
            }
            else{
                break;
            }
        }
    }


void drawTreeGUI(){
        // SFML setup
        sf::RenderWindow window(sf::VideoMode(1600, 900), "Tree Visualization");

        // Main loop
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawTree(window,this->root,400,50,150*k,100);
    
            window.display();
        }
    }

void drawTree(sf::RenderWindow& window, Node<gen>* node, float x, float y, float xOffset,float yOffset) {
        if (!node) return;

        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(x, y);
        window.draw(circle);

        sf::Font font;
        if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")) {
            
        }
        sf::Text text;
        text.setFont(font);    
        text.setString(node->to_str());
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + 10, y + 5);
        window.draw(text);

        float newX = x - xOffset / 2;
        for (auto* child : node->get_nodes()) {
            float childX = newX + xOffset / (node->node_count() + 1); //Child's X pos scales with it's parent's child amount
            float childY = y + yOffset;
            
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 20, y + 20),sf::Color::Black),
                sf::Vertex(sf::Vector2f(childX + 20, childY + 20),sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
            
            drawTree(window, child, childX, childY, xOffset / 2, yOffset);
            newX += xOffset / (node->node_count() + 1);
        }
    }
};




#endif // TREE_HPP


