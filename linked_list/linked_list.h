//
//  linked_list.h
//  linked_list
//
//  Created by Mert Kaya on 2017-09-16.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *next, *prev;
    bool added_value;
};

struct node *create_list();
void print_list(struct node *list);
void change_value(struct node *the_node, int value);
void append_list(struct node *the_list,int value);
struct node *go_value(struct node *list, int place);


#endif /* linked_list_h */
