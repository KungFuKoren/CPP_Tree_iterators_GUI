//kkorenn1@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>
#include <sstream>

template <typename gen>
class Node {
public:
    // Constructors
    Node(const gen& val) : val(val), str(to_string(val)) {}
    Node(const gen& val, const std::string& str) : val(val), str(str) {}

    // Getters
    const gen& get_value() const { return val; }
    const std::vector<Node<gen>*>& get_nodes() const { return nodes; }
    int node_count() const { return nodes.size()-1; }
    std::string to_str() const { return str; }

    // Add a child node
    void add_node(Node<gen>* new_node) {
        nodes.push_back(new_node);
    }

private:
    gen val; // Value stored in the node
    std::string str; // String representation of the value
    std::vector<Node<gen>*> nodes; // Vector to store child nodes

    // Helper function to convert gen to string
    std::string to_string(const gen& value) const {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
};

#endif // NODE_HPP
