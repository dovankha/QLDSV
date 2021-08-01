#pragma once
#include "Subject_node.h"

class Subject_tree
{

public:
    Subject_node *root;
    int size = 0;

    Subject_node *get_root() const;
    void set_root(Subject_node *root);
    Subject_node *insert(Subject_node *, Subject);
    Subject_node *search(Subject_node *, Subject);
    Subject_node *deleteNode(Subject_node *, Subject);
    Subject_node *minValueNode(Subject_node *);
    void free_memory(Subject_node *node);
    int get_size();
    void show_subject_data(Subject_node *root);
    void show_subject_tree(Subject_node *);

    Subject_tree();
    ~Subject_tree();
};

Subject_node *Subject_tree::get_root() const
{
    return root;
}

void Subject_tree::set_root(Subject_node *root)
{
    this->root = root;
}

int Subject_tree::get_size()
{
    return size;
}

Subject_node *Subject_tree::insert(Subject_node *root, Subject data)
{
    if (!root)
    {
        return new Subject_node(data);
    }
    if (data.get_subject_id() > root->data.get_subject_id())
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

Subject_node *Subject_tree::search(Subject_node *root, Subject data)
{
    if (root != NULL)
    {
        if (data.get_subject_id() == root->data.get_subject_id())
        {
            return root;
        }
        if (data.get_subject_id() < root->data.get_subject_id())
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }
    else
    {
        return nullptr;
    }
}

void Subject_tree::show_subject_data(Subject_node *root)
{
    cout << "\nSubject ID is " << root->data.get_subject_id();
    cout << "\nSubject name is " << root->data.get_subject_name();
    cout << "\nSTCLT of subject: " << root->data.get_STCLT();
    cout << "\nSTCTH of subject: " << root->data.get_STCTH();
}

void Subject_tree::show_subject_tree(Subject_node *root)
{
    if (!root)
        return;
    show_subject_tree(root->left);
    show_subject_data(root);
    show_subject_tree(root->right);
}

Subject_node *Subject_tree::minValueNode(Subject_node *node)
{
    Subject_node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Subject_node *Subject_tree::deleteNode(Subject_node *root, Subject data)
{
    if (root == NULL)
        return root;
    if (data.get_subject_id() < root->data.get_subject_id())
        root->left = deleteNode(root->left, data);
    else if (data.get_subject_id() > root->data.get_subject_id())
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            Subject_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Subject_node *temp = root->left;
            free(root);
            return temp;
        }
        Subject_node *temp = Subject_tree::minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void Subject_tree::free_memory(Subject_node *node)
{
    if (node == nullptr)
    {
        return;
    }
    free_memory(node->left);
    free_memory(node->right);

    delete node;
}

Subject_tree::Subject_tree()
{
}

Subject_tree::~Subject_tree()
{
}
