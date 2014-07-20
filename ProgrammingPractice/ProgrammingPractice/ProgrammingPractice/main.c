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

void (*printScene)();
void mainScene();
void addScene();
void removeScene();
void searchScene();
void showAllAddressScene();
void sceneChange(void(*fParameter)());

char letter = '0';

int main(int argc, const char * argv[])
{
    Address* head = (Address*)malloc(sizeof(Address*)); // 최초 초기화.
    
    sceneChange(&mainScene);
    do {
        printScene();
        scanf("%c", &letter);
        system("clear");
        //printf("clear success : %d\n", letter);
    } while(letter != 'q');
    
    printf("종료되었습니다. \n");
    
    return 0;
}

void mainScene() {
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
    }
    
    printf("0. 초기 화면으로.\n");
    printf("1. 주소록 추가\n");
    printf("2. 주소록 삭제\n");
    printf("3. 주소록 검색\n");
    printf("4. 주소록 조회\n");
    printf("q. 종료\n");
}

void addScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void removeScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void searchScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void showAllAddressScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void sceneChange(void (*fParameter)()) {
    system("clear");
    printScene = fParameter;
    //printf("\n");
}




