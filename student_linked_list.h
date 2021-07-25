#pragma once
#include "Student_node.h"

class Student_linked_list
{

    Student_node *head;
    int size = 0;

public:
    bool empty();
    int get_size();
    void push_back(Student data);
    void push_front(Student data);
    void pop_back();
    void pop_front();
    void insert_at(int position, Student data);
    void remove_at(int position);
    void remove_by_id(string id);

    void set_points_linked_list(Point_linked_list *point_linked_list, int pos);
    int is_contain_id(string id);
    int is_contain_id_except(string id, string except);

    void sort(); // chua cai dat

    Student_node *get_head() const;
    Student_node *get_node_at(int index);
    void set_head(Student_node *head);

    Student_linked_list();
    ~Student_linked_list();
};

bool Student_linked_list::empty()
{
    return head == nullptr;
}

int Student_linked_list::get_size()
{
    return size;
}

void Student_linked_list::push_back(Student data)
{
    Student_node *new_node = new Student_node(data);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Student_node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
}

void Student_linked_list::push_front(Student data)
{
    Student_node *new_node = new Student_node(data);
    new_node->next = head;
    head = new_node;
    size++;
}

void Student_linked_list::pop_back()
{
    if (empty())
    {
        throw string(" point list empty");
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Student_node *temp = head;
        for (temp; temp->next->next != nullptr; temp = temp->next)
            ;
        delete temp->next;
        temp->next = nullptr;
    }
    size--;
}

void Student_linked_list::pop_front()
{
    if (empty())
    {
        throw string(" point list empty");
        return;
    }
    Student_node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

void Student_linked_list::insert_at(int position, Student data)
{
    if (position > size || position < 0)
    {
        throw string("invalid position");
        return;
    }
    if (head == nullptr && position == 0)
    {

        push_front(data);
        return;
    }
    if (position == size)
    {
        push_back(data);
        return;
    }
    Student_node *current = head;
    int count = 0;
    while (current != nullptr && (count < position - 1))
    {
        current = current->next;
        count++;
    }

    Student_node *new_node = new Student_node(data);
    new_node->next = current->next;
    current->next = new_node;
    size++;
}

void Student_linked_list::remove_at(int position)
{
    if (empty())
    {
        throw string(" point list empty");
        return;
    }
    if (position > size - 1 || position < 0)
    {
        return;
    }
    if (position == 0)
    {
        pop_front();
        return;
    }
    if (position == size - 1)
    {
        pop_back();
        return;
    }
    int count = 0;
    Student_node *previous = head;
    Student_node *delete_node = head->next;

    while (delete_node != nullptr && (count < position - 1))
    {
        previous = previous->next;
        delete_node = delete_node->next;
        count++;
    }

    previous->next = delete_node->next;
    delete delete_node;
    size--;
}

void Student_linked_list::remove_by_id(string id)
{
    if (empty())
    {
        throw string(" point list empty");
        return;
    }
    if (id == head->data.get_id())
    {
        pop_front();
        return;
    }

    Student_node *previous = head;
    Student_node *temp = head->next;
    for (temp; temp != nullptr; previous = temp, temp = temp->next)
    {
        if (temp->data.get_id() == id)
        {
            break;
        }
    }

    if (temp == nullptr)
    {
        throw string("not found id");
    }
    else
    {
        previous->next = temp->next;
        delete temp;
        size--;
    }
}

void Student_linked_list::set_points_linked_list(Point_linked_list *point_linked_list, int pos)
{
    if (pos < 0 || pos > size - 1)
        return;
    if (head == nullptr)
        return;

    int count = 0;
    auto temp = head;
    while (temp != nullptr && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->data.set_points_list(point_linked_list);
}

int Student_linked_list::is_contain_id(string id)
{
    int count = 0;
    for (auto temp = head; temp != nullptr; temp = temp->next)
    {
        if (temp->data.get_id() == id)
        {
            return count;
        }
        count++;
    }
    return -1;
}

int Student_linked_list::is_contain_id_except(string id, string except)
{
    int count = 0;
    for (auto temp = head; temp != nullptr; temp = temp->next)
    {
        if (temp->data.get_id() == id && temp->data.get_id() != except)
        {
            return count;
        }
        count++;
    }
    return -1;
}

Student_node *Student_linked_list::get_head() const
{
    return head;
}

Student_node *Student_linked_list::get_node_at(int index)
{
    if (index < 0 || index > size - 1)
        return nullptr;
    if (!head)
        return nullptr;
    int count = 0;
    auto temp = head;
    while (temp != nullptr && count != index)
    {
        count++;
        temp = temp->next;
    }
    if (temp != nullptr)
    {
        return temp;
    }
    return nullptr;
}

void Student_linked_list::set_head(Student_node *head)
{
    this->head = head;
}

Student_linked_list::Student_linked_list()
{
    head = nullptr;
}

Student_linked_list::~Student_linked_list()
{
    auto temp = head;

    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
