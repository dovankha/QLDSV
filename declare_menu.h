#pragma once
#include <conio.h>
#include "Database_Manager.h"

int choice; // choice of menu
Database_Manager DM;
Class clas;
string class_list_file_path = "Data/Classes/classes_list.csv";
string subject_list_file_path = "Data/subject_list.csv";
Classes_list *class_list = DM.read_classes_list(class_list_file_path);
Subject_tree *subject_tree = DM.read_subject_tree(subject_list_file_path);
