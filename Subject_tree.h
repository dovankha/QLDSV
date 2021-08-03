#pragma once
#include "Subject_node.h"

class Subject_tree
{
private:
    Subject_node *root;
    int size = 0;

    Subject_node *insert_r(Subject_node *, Subject data);
    Subject_node *search(Subject_node *, Subject data);
    Subject_node *deleteNode(Subject_node *, string subject_id);
    Subject_node *minValueNode(Subject_node *);
    void free_memory(Subject_node *node);
    void show_subject_data(Subject_node *node);
    void show_subject_tree(Subject_node *);
    
    

public:
    void insert(Subject data);
    void remove(string subject_id);
    int contain_id(string id);
    void replace_subject_by_id(string id, Subject subject);
    void showTree();
    int get_size();
    Subject_node *get_root() const;
    void set_root(Subject_node *root);
    Subject_tree();
    ~Subject_tree();
};

void Subject_tree::showTree()
{
    cout << "\n\t\t\t    ====== SUBJECT LIST =======" << endl;
    cout << "\t"
         << "+------------+-----------------------------+---------+---------+" << endl;
    cout << "\t" << left << setw(13) << "| Subject ID" << left << setw(30) << "|            Name" << left << setw(10) << "|  STCLT" << left << setw(10) << "|  STCTH  |\n";
    cout << "\t"
         << "+------------+-----------------------------+---------+---------+" << endl;
    show_subject_tree(root);
    cout << "\t"
         << "+------------+-----------------------------+---------+---------+" << endl;
}

// bị fail
void Subject_tree::replace_subject_by_id(string id, Subject subject)
{
    int position;
    for (int i = 0; i < size; i++)
    {
        if (root->data.get_subject_id() == id)
        {
            break;
        }
    }
}

int Subject_tree::contain_id(string id)
{
    for (int i = 0; i < size; i++)
    {
        if (root->data.get_subject_id() == id)
        {
            return i;
        }
    }
    return -1;
}

void Subject_tree::insert(Subject data)
{
    this->root = insert_r(root, data);
    size++;
}

void Subject_tree::remove(string subject_id)
{
    this->root = deleteNode(root, subject_id);
    size--;
}

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

Subject_node *Subject_tree::insert_r(Subject_node *node, Subject data)
{
    if (!node)
    {
        return new Subject_node(data);
    }
    if (data.get_subject_name() > node->data.get_subject_name())
    {
        node->right = insert_r(node->right, data);
    }
    else
    {
        node->left = insert_r(node->left, data);
    }
    return node;
}

Subject_node *Subject_tree::search(Subject_node *node, Subject data)
{
    if (node != NULL)
    {
        if (data.get_subject_id() == node->data.get_subject_id())
        {
            return node;
        }
        if (data.get_subject_id() < node->data.get_subject_id())
        {
            return search(node->left, data);
        }
        else
        {
            return search(node->right, data);
        }
    }
    else
    {
        return nullptr;
    }
}

void Subject_tree::show_subject_data(Subject_node *node)
{
    cout << "\t|" << left << setw(12) << node->data.get_subject_id();
    cout << "|" << left << setw(29) << node->data.get_subject_name();
    cout << "|    " << left << setw(5) << node->data.get_STCLT();
    cout << "|    " << left << setw(5) << node->data.get_STCTH() << "|\n";
}

void Subject_tree::show_subject_tree(Subject_node *node)
{
    if (!node)
        return;
    show_subject_tree(node->left);
    show_subject_data(node);
    show_subject_tree(node->right);
}

Subject_node *Subject_tree::minValueNode(Subject_node *node)
{
    Subject_node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Subject_node *Subject_tree::deleteNode(Subject_node *node, string subject_id)
{
    if (node == nullptr)
        return node;
    if (subject_id < node->data.get_subject_id())
        node->left = deleteNode(node->left, subject_id);
    else if (subject_id < node->data.get_subject_id())
        node->right = deleteNode(node->right, subject_id);
    else
    {
        if (node->left == NULL and node->right == NULL)
            return NULL;
        else if (node->left == NULL)
        {
            Subject_node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            Subject_node *temp = node->left;
            free(node);
            return temp;
        }
        Subject_node *temp = Subject_tree::minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data.get_subject_id());
    }
    return node;
}

// Subject_node *Subject_tree::deleteNode(Subject_node *node, Subject data)
// {
//     if (node == NULL)
//         return node;
//     if (data.get_subject_id() < node->data.get_subject_id())
//         node->left = deleteNode(node->left, data);
//     else if (data.get_subject_id() > node->data.get_subject_id())
//         node->right = deleteNode(node->right, data);
//     else
//     {
//         if (node->left == NULL and node->right == NULL)
//             return NULL;
//         else if (node->left == NULL)
//         {
//             Subject_node *temp = node->right;
//             free(node);
//             return temp;
//         }
//         else if (node->right == NULL)
//         {
//             Subject_node *temp = node->left;
//             free(node);
//             return temp;
//         }
//         Subject_node *temp = Subject_tree::minValueNode(node->right);
//         node->data = temp->data;
//         node->right = deleteNode(node->right, temp->data);
//     }
//     return node;
// }

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
    root = nullptr;
}

Subject_tree::~Subject_tree()
{
}
