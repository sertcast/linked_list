//
//  main.c
//  linked_list
//
//  Created by Mert Kaya on 2017-09-16.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#include "linked_list.h"

int main(int argc, const char * argv[]) {
    my_list *list = create_list();
    append_list(list, 2);
    append_list(list, 4);
    append_list(list, 5);
    append_list(list, 6);
    append_list(list, 7);
    pop_list(list);
    print_list(list);
    free_list(list);
    
    return 0;
}
