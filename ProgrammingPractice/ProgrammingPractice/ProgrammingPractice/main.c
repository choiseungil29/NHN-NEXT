//
//  main.c
//  ProgrammingPractice
//
//  Created by Pooh on 2014. 7. 16..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#include <stdio.h>
#include "Address.h"

void (*printScene)(char);
void mainScene(char);
void addScene(char);
void removeScene(char);
void searchScene(char);
void showAllAddressScene(char);
void sceneChange(void(*fParameter)(char));


int main(int argc, const char * argv[])
{
    Address* head = (Address*)malloc(sizeof(Address*)); // 최초 초기화.
    
    printScene = &mainScene;
    
    char letter;
    do {
        printf("0. 초기 화면으로.\n");
        printScene(letter);
        printf("5. 종료\n");
        
        
        if(letter == '0') {
            printScene = &mainScene;
        } else if(letter == '5') {
            exit(0);
        }
        
        printf("\n");
        
    } while((letter = getchar()) != '5');
    return 0;
}

void mainScene(char letter) {
    printf("1. 주소록 추가\n");
    printf("2. 주소록 삭제\n");
    printf("3. 주소록 검색\n");
    printf("4. 주소록 조회\n");
    
    if(letter == '1') {
        sceneChange(&addScene);
    } else if(letter == '2') {
        sceneChange(&removeScene);
    } else if(letter == '3') {
        sceneChange(&searchScene);
    } else if(letter == '4') {
        sceneChange(&showAllAddressScene);
    } else {
        printf("잘못된 입력입니다. 다시 입력해주세요.\n");
    }
}

void addScene(char letter) {
    
}

void removeScene(char letter) {
    
}

void searchScene(char letter) {
    
}

void showAllAddressScene(char letter) {
    
}

void sceneChange(void (*fParameter)(char)) {
    printScene = fParameter;
}









