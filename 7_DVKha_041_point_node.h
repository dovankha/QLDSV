#pragma once
#include "7_DVKha_041_Point.h"

class Point_node
{
public:
    Point data;
    Point_node *next;
    Point_node(Point data);

    Point_node();
    ~Point_node();
};

Point_node::Point_node(Point data)
{
    this->data = data;
    this->next = nullptr;
}

Point_node::Point_node()
{
}

Point_node::~Point_node()
{
}