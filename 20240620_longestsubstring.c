/*
 * Link to the problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct charList {
    char val;
    struct charList * next;
};

struct charList * new_list (char input){
    struct charList * output = malloc(sizeof(struct charList));
    output->val = input;
    output->next = NULL;
    return output;
}

void add_to_list (struct charList * input, char value){
    struct charList * current = input;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = malloc (sizeof (struct charList));
    current = current->next;
    current->val = value;
    current->next = NULL;

}

bool is_in_list (struct charList * input, char value){
    struct charList * current = input;
    bool result = false;
    while (result == false && current != NULL){
        result = current->val == value;
        current = current->next;
        if (result){
            break;
        }
    }
    return result;
}

struct charList* destroy_list (struct charList * input){
    struct charList* kill_me = input;
    struct charList* aux = input;
    while (aux->next != NULL){
        kill_me = aux;
        aux = aux->next;
        free(kill_me);
    }

    input = NULL;
    return input;
}


int lengthOfLongestSubstring(char* s) {
    int max = 1;
    int current_count = 1;
    int i = 1;

    struct charList* list = new_list(s[0]);

    for (unsigned int i = 1u; s[i] != '\0'; i++){
        if (is_in_list(list, s[i])){
            list = destroy_list(list);
            list = new_list(s[i]);
            current_count = 1;
        }
        else{
            add_to_list(list, s[i]);
            current_count += 1;
        }

        if (current_count > max){
            max = current_count;
        }

    }

    list = destroy_list(list);
    return max;
}


int main (){
    char * test1 = "abcabcbb";
    char * test2 = "bbbbb";
    char * test3 = "pwwkew";

    fprintf(stdout,"Test 1\n");
    fprintf(stdout, "Expected: 3  ");
    fprintf(stdout, "Result: %i\n", lengthOfLongestSubstring(test1));

    fprintf(stdout,"Test 2\n");
    fprintf(stdout, "Expected: 1  ");
    fprintf(stdout, "Result: %i\n", lengthOfLongestSubstring(test2));
    
    fprintf(stdout,"Test 3\n");
    fprintf(stdout, "Expected: 3  ");
    fprintf(stdout, "Result: %i\n", lengthOfLongestSubstring(test3));
    
    return 0;
}
