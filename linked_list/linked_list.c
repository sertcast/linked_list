//
//  linked_list.c
//  linked_list
//
//  Created by Mert Kaya on 2017-09-16.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"
//creates a node
my_list *create_node(){
    my_list *newNode = (my_list*)malloc(sizeof(my_list));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->added_value = false;
    newNode->value = 0;
    return newNode;
}
//creates a list
my_list *create_list(){
    return create_node();
}
//returns the node that is at the end of the list
my_list *go_end(my_list *the_list){
    my_list *current = the_list;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}
//removes the node from memory
void free_node(my_list *the_node){
    the_node->next = NULL;
    the_node->prev = NULL;
    the_node->value = 0;
    the_node->added_value = false;
    free(the_node);
}
//removes the list from memory
void free_list(my_list *the_list){
    if(go_end(the_list)->prev != NULL){
        my_list *current = (go_end(the_list))->prev;
        while(current->prev != NULL){
            free_node(current->next);
            current = current->prev;
        }
        free_node(current);
    }else{
        free_node(the_list);
    }
}
//changes the value that is in the node given
void change_value(my_list *the_node, int value){
    the_node->value = value;
    the_node->added_value = true;
}
//prints the values that the list has
void print_list(my_list *list){
    my_list *current = list;
    if(current->added_value){
        printf("%d\n", current->value);
        while(current->next != NULL){
            current = current->next;
            printf("%d\n", current->value);
        }
    }
}
//adds a value to the end
void append_list(my_list *the_list,int value){
    my_list *current = go_end(the_list);
    if(current->added_value){
        my_list *newNode = create_node();
        current->next = newNode;
        newNode->prev = current;
        change_value(newNode,value);
    }
    else{
        change_value(current,value);
    }
}
//returns the node that is in place given
my_list *go_value(my_list *list, int place){
    my_list *current = list;
    int i = 0;
    for(i = 0; i < place; i++){
        if(current->next != NULL){
            current = current->next;
        }else{
            printf("There is no value in the place you want.\n");
            exit(1);
        }
    }
    return current;
}
//inserts a value to the list. cant add a value to end.
void insert_list(my_list *list, int value, int place){
    my_list *current = go_value(list, place);

    if(current->prev == NULL){
        my_list *nextNode = create_node();
        nextNode->next = current->next;
        nextNode->prev = current;
        change_value(nextNode, current->value);
        current->next = nextNode;
        change_value(current, value);
        
    }else{
        my_list *newNode = create_node();
        
        newNode->next = current;
        newNode->prev = current->prev;
        change_value(newNode, value);
        current->prev->next = newNode;
        current->prev = newNode;

    }
}
//removes the last member of list. Doesnt work if the list contains only one value
void pop_list(my_list *list){
    my_list *current = go_end(list);
    if(current->prev != NULL){
        current->prev->next = NULL;
        current->value = 0;
        current->next = current->prev = NULL;
        current->added_value = false;
        free_node(current);
    }else{
        printf("The list you want to pop contains only one value which means this function will not work.\n");
    }
}
/*    UPCOMING!!!!
void slice_list(my_list *list, int place){
    
}
*/



















