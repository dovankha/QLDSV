#pragma once
#include "Point_node.h"

class Point_linked_list
{
    Point_node *head;
    int size = 0;

public:
    bool empty();
    int get_size();
    void push_back(Point data);
    void push_front(Point data);
    void pop_back();
    void pop_front();
    void insert_at(int position, Point data);
    void remove_at(int position);
    void remove_by_id(string id);
    void remove_by_subject_id(string id);
    void replace_id(string id);

    Point_node *get_head();
    float get_point(string subject_id);

    Point_linked_list();
    ~Point_linked_list();
};


bool Point_linked_list::empty()
{
    return head == nullptr;
}

int Point_linked_list::get_size()
{
    return size;
}

void Point_linked_list::push_back(Point data)
{
    Point_node *new_node = new Point_node(data);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Point_node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
}

void Point_linked_list::pop_back()
{
    if (empty())
    {
        cout << "point list empty";
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Point_node *temp = head;
        for (temp; temp->next->next != nullptr; temp = temp->next)
            ;

        delete temp->next;
        temp->next = nullptr;
    }
    size--;
}

void Point_linked_list::push_front(Point data)
{
    Point_node *new_node = new Point_node(data);
    new_node->next = head;
    head = new_node;
    size++;
}

void Point_linked_list::pop_front()
{
    if (empty())
    {
        cout << " invalid position";
        return;
    }
    Point_node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

void Point_linked_list::insert_at(int position, Point data)
{
    if (position > size || position < 0)
    {
        cout << " invalid position";
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
    Point_node *current = head;
    int count = 0;
    while (current != nullptr && (count < position - 1))
    {
        current = current->next;
        count++;
    }
    Point_node *new_node = new Point_node(data);
    new_node->next = current->next;
    current->next = new_node;
    size++;
}

void Point_linked_list::remove_at(int position)
{
    if (empty())
    {
        cout << " point list empty";
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
    Point_node *previous = head;
    Point_node *delete_node = head->next;

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

void Point_linked_list::remove_by_id(string id)
{
    if (empty())
    {
        cout << " point list empty";
        return;
    }
    if (id == head->data.get_subject_id())
    {
        pop_front();
        return;
    }
    Point_node *previous = head;
    Point_node *temp = head->next;
    for (temp; temp != nullptr; previous = temp, temp = temp->next)
    {
        if (temp->data.get_subject_id() == id)
        {
            break;
        }
    }
    if (temp == nullptr)
    {
        cout << "Not fount id";
    }
    else
    {
        previous->next = temp->next;
        delete temp;
        size--;
    }
}

void Point_linked_list::replace_id(string id)
{
    for (Point_node *temp = head; temp != nullptr; temp = temp->next)
    {
        if (temp->data.get_subject_id() == id)
        {
            temp->data.set_subject_id(id);
            break;
        }
    }
}

void Point_linked_list::remove_by_subject_id(string id)
{
    if (empty())
    {
        cout << " point list empty";
        return;
    }
    if (id == head->data.get_subject_id())
    {
        pop_front();
        return;
    }
    Point_node *previous = head;
    Point_node *temp = head->next;
    for (temp; temp != nullptr; previous = temp, temp = temp->next)
    {
        if (temp->data.get_subject_id() == id)
        {
            break;
        }
    }

    if (temp == nullptr)
    {
        cout << "Not found id";
    }
    else
    {
        previous->next = temp->next;
        delete temp;
        size--;
    }
}

Point_node *Point_linked_list::get_head()
{
    return head;
}

float Point_linked_list::get_point(string subject_id)
{
    for (Point_node *temp = head; temp != nullptr; temp = temp->next)
    {
        if (temp->data.get_subject_id() == subject_id)
        {
            return temp->data.get_point();
        }
    }
    return -1;
}

Point_linked_list::Point_linked_list()
{
    head = nullptr;
}

Point_linked_list::~Point_linked_list()
{
    Point_node *temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}