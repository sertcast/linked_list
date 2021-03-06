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
        }else if(i < place){
            printf("There is no value in the place you want\n");
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
//removes the last member of list. doesnt work if the list contains only one value
int pop_list(my_list *list){
    my_list *current = go_end(list);
    if(current->prev != NULL){
        current->prev->next = NULL;
        int value = current->value;
        free_node(current);
        return value;
        
    }else{
        printf("The list you want to pop contains only one value which means this function will not work.\n");
        return 0;
    }
}
//deletes a value. doesnt work if the list contains only one value
void delete_list(my_list *list, int place){
    my_list *del_node = go_value(list, place);
    if(del_node->next != NULL){
        if(del_node->prev != NULL){
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
            free_node(del_node);
        }else{
            my_list *current = list;
            while (current->next!= NULL) {
                current->value = current->next->value;
                current = current->next;
            }
            current->prev->next = NULL;
            free_node(current);
        }
    }else if(del_node->prev != NULL){
        pop_list(list);
    }else{
        printf("You can not delete a value if the list has only one value.");
        exit(1);
    }
}
//returns length of a list
int length_list(my_list* list){
    int counter = 0;
    my_list *current = list;
    do{
        counter++;
    }while(current->next != NULL);
    return counter;
}
//switches two value
void switch_list(my_list *list, int first_place, int second_place){
    if(first_place != second_place){
        my_list *first_node = go_value(list, first_place);
        my_list *second_node = go_value(list, second_place);
        int first_value = first_node->value, second_value = second_node->value;
        
        first_node->value = second_value;
        second_node->value = first_value;
        
    }
}
//copies a list to another
void cplist(my_list *list, my_list*cplist){
    my_list *current_list = list;
    while(current_list->next != NULL){
        append_list(cplist, current_list->value);
        current_list = current_list->next;
    }
}
