#pragma once
#include "Class_list.h"
#include "Subject_tree.h"


class Manager
{
    Subject_tree *subject_tree;
    Classes_list *classes_list;
    
    static Manager *instance;

public:
    static Manager *get_instance();
    void destroy ();

    Subjects_tree* get_subjects_tree() const;
	void set_subjects_tree(Subjects_tree* subjects_list);
	Classes_list* get_classes_list() const;
	void set_classes_list(Classes_list* classes_list);
	Question_tree* get_question_tree() const;
	void set_question_tree(Question_tree* question_tree);

    Manager();
};

Manager::~Manager()
