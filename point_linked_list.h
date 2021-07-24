#pragma once
#include "point_node.h"

class point_linked_list
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

    point_linked_list();
    ~point_linked_list();
};

bool point_linked_list::empty()
{
    return head == NULL; //nullptr
}



