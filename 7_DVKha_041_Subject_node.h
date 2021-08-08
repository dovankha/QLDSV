#include "7_DVKha_041_Subject.h"
class Subject_node
{
public:
    Subject data;
    Subject_node *left;
    Subject_node *right;

    Subject_node(Subject subject);
    Subject_node();
    ~Subject_node();
};

Subject_node::Subject_node(Subject data)
{
    this->data = data;
    this->left = this->right = nullptr;
}

Subject_node::Subject_node()
{
    this->data = nullptr;
    this->left = this->right = nullptr;
}

Subject_node::~Subject_node()
{
}
