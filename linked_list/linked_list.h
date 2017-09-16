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

struct my_list {
    int value;
    struct my_list *next, *prev;
    bool added_value;
};
typedef struct my_list my_list;

my_list *create_list();
void print_list(my_list *list);
void change_value(my_list *the_node, int value);
void append_list(my_list *the_list,int value);
my_list *go_value(my_list *list, int place);


#endif /* linked_list_h */
