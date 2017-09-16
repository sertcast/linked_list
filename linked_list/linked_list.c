//
//  linked_list.c
//  linked_list
//
//  Created by Mert Kaya on 2017-09-16.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"
struct node *create_node(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->added_value = false;
    newNode->value = 0;
    return newNode;
}
struct node *create_list(){
    return create_node();
}
struct node *go_end(struct node *the_list){
    struct node *current = the_list;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}
void change_value(struct node *the_node, int value){
    the_node->value = value;
    the_node->added_value = true;
}
void print_list(struct node *list){
    struct node *current = list;
    if(current->added_value){
        printf("%d\n", current->value);
        while(current->next != NULL){
            current = current->next;
            printf("%d\n", current->value);
        }
    }
}
void append_list(struct node *the_list,int value){
    struct node *current = go_end(the_list);
    if(current->added_value){
        struct node *newNode = create_node();
        current->next = newNode;
        newNode->prev = current;
        change_value(newNode,value);
    }
    else{
        change_value(current,value);
    }
}
struct node *go_value(struct node *list, int place){
    struct node *current = list;
    int i = 0;
    for(i = 0; i < place; i++){
        if(current->next != NULL){
            current = current->next;
        }else{
            printf("There is no value in the place you want.\n");
            return current;
        }
    }
    return current;
}



