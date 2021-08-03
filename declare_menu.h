#pragma once
#include <conio.h>
#include "Database_Manager.h"

int choice; // choice of menu
Database_Manager DM;
Class clas;
Point point;
string class_list_file_path = "Data/Classes/classes_list.csv";
string subject_list_file_path = "Data/subject_list.csv";
string point_list_file_path = "Data/Classes/Students/points_list/";
Classes_list *class_list = DM.read_classes_list(class_list_file_path);
Subject_tree *subject_tree = DM.read_subject_tree(subject_list_file_path);
Point_linked_list *point_list = DM.read_points_linked_list(point_list_file_path);
