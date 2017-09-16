//
//  main.c
//  linked_list
//
//  Created by Mert Kaya on 2017-09-16.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *list = create_list();
    append_list(list, 2);
    append_list(list, 4);
    append_list(list, 5);
    append_list(list, 6);
    append_list(list, 9);
    //print_list(list);
    

      
    return 0;
}
