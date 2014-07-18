//
//  main.c
//  ProgrammingPractice
//
//  Created by Pooh on 2014. 7. 16..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Address.h"
#include <curses.h>

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
    
    char letter = '0';
    while(letter != 'q') {
        printScene(letter);
        letter = getchar();
        printf("\n");
        //system("clear");
    }
    
    printf("종료되었습니다. \n");
    
    return 0;
}

void mainScene(char letter) {
    printf("0. 초기 화면으로.\n");
    printf("1. 주소록 추가\n");
    printf("2. 주소록 삭제\n");
    printf("3. 주소록 검색\n");
    printf("4. 주소록 조회\n");
    printf("q. 종료\n");
    
    if(letter == '0') {
        sceneChange(&mainScene);
    } else if(letter == '1') {
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
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
    
    if(letter == '0') {
        sceneChange(&mainScene);
    }
}

void removeScene(char letter) {
    
}

void searchScene(char letter) {
    
}

void showAllAddressScene(char letter) {
    
}

void sceneChange(void (*fParameter)(char)) {
    printScene = fParameter;
    //system("clear");
    printf("\n");
}









