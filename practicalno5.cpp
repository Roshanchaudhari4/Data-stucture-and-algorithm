/*A book consists of chapters, chapters consist of sections Construct a tree and print 
the nodes.*/


#include<iostream>
#include<vector>

class Node {
    public:
    std::string data;
    std::vector<Node*>children;

    Node(std::string value) : data(value) {}

    void addchild(Node* child) {
        children.push_back(child);
    }
};

void printNodes(Node* node) {
    std::cout << node->data <<std::endl;
    for(Node* child : node->children) {
        printNodes(child);
    }
}

int main() {
    Node* book = new Node("Book");

    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    Node* chapter3 = new Node("Chapter 3");

    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");

    Node* section2_1 = new Node("Section 2.1");
    Node* section2_2 = new Node("Section 2.2");
    Node* section2_3 = new Node("Section 2.3");

    Node* section3_1 = new Node("Section 3.1");

    book->addchild(chapter1);
    book->addchild(chapter2);
    book->addchild(chapter3);

    chapter1->addchild(section1_1);
    chapter1->addchild(section1_2);

    chapter2->addchild(section2_1);
    chapter2->addchild(section2_2);
    chapter2->addchild(section2_3);

    chapter3->addchild(section3_1);

    printNodes(book);

    delete book;
    delete chapter1;
    delete chapter2;
    delete chapter3;
    delete section1_1;
    delete section1_2;
    delete section2_1;
    delete section2_2;
    delete section2_3;
    delete section3_1;
   
    return 0;
}