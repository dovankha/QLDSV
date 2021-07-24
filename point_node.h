#pragma once
#include "Point.h"

class Point_node
{
    public:
    Point data;
    Point_node *next;
    Point_node(Point data);

    Point_node();
    ~Point_node();
};