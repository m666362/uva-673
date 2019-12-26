/*Bismillahir Rahmanir Rahim*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//todo: declaring global variable
char arrayBrackets[128], stackBrackets[128];
int arrayPointer, stackPointer, flag;

//todo: code for pushCharacter() into stack
void pushCharacter() {
    stackBrackets[stackPointer++] = arrayBrackets[arrayPointer];
}

//todo: code for popCharacter() from stack
void popCharacter() {
    if(stackPointer == 0){
        flag = 0;
    }
    else if((arrayBrackets[arrayPointer] == ')' && stackBrackets[--stackPointer]!='(') || (arrayBrackets[arrayPointer] == ']' && stackBrackets[--stackPointer]!='[')){
        flag = 0;
    }
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    getc(stdin);
    while (testcase--){
        fgets(arrayBrackets, 128, stdin);
        //gets(arrayBrackets);
        flag = 1;
        stackPointer = 0;
        for (arrayPointer = 0; arrayPointer < strlen(arrayBrackets); ++arrayPointer) {
            if (arrayBrackets[arrayPointer] == '(' || arrayBrackets[arrayPointer] == '['){
                pushCharacter();
            }
            else if (arrayBrackets[arrayPointer] == ')' || arrayBrackets[arrayPointer] == ']'){
                popCharacter();
                if(flag == 0){
                    break;
                }
            }
        }
        if(stackPointer>0){
            flag = 0;
        }
        if(flag == 0){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}

