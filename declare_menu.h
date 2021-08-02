#pragma once
#include <conio.h>
#include "Database_Manager.h"

int choice; // choice of menu

string class_list_file_path = "Data/Classes/classes_list.csv";
string subject_list_file_path = "Data/subject_list.csv";
Database_Manager DM;
Classes_list *class_list = DM.read_classes_list(class_list_file_path);
Subject_tree *subject_tree = DM.read_subject_tree(subject_list_file_path);