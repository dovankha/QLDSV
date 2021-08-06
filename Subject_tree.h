#pragma once
#include "Subject_node.h"

class Subject_tree
{
private:
    Subject_node *root;
    int size = 0;

    Subject_node *insert_r(Subject_node *, Subject data);
    Subject_node *search(Subject_node *, Subject data);
    Subject_node *delete_recursive(Subject_node *, string subject_id);
    Subject_node *find_min(Subject_node *);
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

void Subject_tree::replace_subject_by_id(string id, Subject subject)
{
    Subject_node *node = search(root, subject);
    if (node != nullptr)
    {
        node->data.getDataFromInput(true);
    }
}

int Subject_tree::contain_id(string id)
{
    Subject c;
    c.set_subject_id(id);
    Subject_node *node = search(root, c);
    if (node == nullptr)
    {
        return -1;
    }
    return 1;
}

void Subject_tree::insert(Subject data)
{
    this->root = insert_r(root, data);
}

void Subject_tree::remove(string subject_id)
{
    if (get_size() == 0)
    {
        return;
    }

    int current_size = size;
    this->root = delete_recursive(root, subject_id);
    if (current_size == size)
    {
        throw string("Not found subject id!!\n");
    }
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
        size++;
        return new Subject_node(data);
    }
    if (data.get_subject_id().compare(node->data.get_subject_id()) > 0)
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
        if (data.get_subject_id().compare(node->data.get_subject_id()) == 0)
        {
            return node;
        }
        if (data.get_subject_id().compare(node->data.get_subject_id()) < 0)
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

Subject_node *Subject_tree::find_min(Subject_node *node)
{
    auto temp = node;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
// id
// tat ca  bat id
// sapxep : duyet cay ,

// push du lieu vao 1 cai mang, sap xep ca mang đó, in mảng đó ra

// vector<Subject> sorteSubject;
/// chay ham duyt cay
// sorSubjetc : tim gg sort vector c++
// in vector ra

// hamduyetCay(vector<Subject> &sorteSbject){

//     sorSubject.push_back(Subject);

// }

Subject_node *Subject_tree::delete_recursive(Subject_node *node, string subject_id)
{
    if (!node)
    {
        return nullptr;
    }
    else if (subject_id.compare(node->data.get_subject_id()) < 0)
    {
        node->left = delete_recursive(node->left, subject_id);
    }

    else if (subject_id.compare(node->data.get_subject_id()) > 0)
    {
        node->right = delete_recursive(node->right, subject_id);
    }
    else
    {
        if (!node->left && !node->right) // leaf node
        {
            delete node;
            node = nullptr;
            size--;
        }
        else if (!node->left) // left null , right oke
        {
            auto temp = node;
            node = node->right;
            delete temp;
            size--;
        }
        else if (!node->right) // right null, left ok
        {
            auto temp = node;
            node = node->left;
            delete temp;
            size--;
        }
        else
        {
            auto temp = find_min(node->right);

            node->data = temp->data;
            node->right = delete_recursive(node->right, temp->data.get_subject_id());
        }
    }

    return node;
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
    root = nullptr;
}

Subject_tree::~Subject_tree()
{
}
