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
Address* head = NULL;

int main(int argc, const char * argv[])
{
    
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
    
    printf("초기 화면\n");
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
    
    Address* address = NULL;
    if(head == NULL) {
        init(&head);
        address = head;
    } else {
        address = head;
        while(address->node!= NULL) {
            address = address->node;
        }
        init(&address->node);
        address = address->node;
    }
    
    char* name = NULL;
    char* phoneNum = NULL;
    char* homeAddress = NULL;
    
    do {
        system("clear");
        printf("이름을 입력해주세요 : ");
        scanf("%s", name);
        printf("asdasd");
    } while(!address->setUserName(address, name));
    
    do {
        system("clear");
        printf("이름 : %s\n", address->userName);
        printf("전화번호를 입력해주세요 : ");
        scanf("%s", phoneNum);
    } while(!address->setPhoneNum(address, phoneNum));
    
    do {
        system("clear");
        printf("이름 : %s\n", address->userName);
        printf("전화번호 : %s\n", address->phoneNum);
        printf("주소를 입력해주세요 : ");
        scanf("%s", homeAddress);
    } while(!address->setHomeAddress(address, homeAddress));
    
    system("clear");
    printf("이름 : %s\n", address->userName);
    printf("전화번호 : %s\n", address->phoneNum);
    printf("주소 : %s\n", address->homeAddress);
}

void removeScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("주소록 삭제\n");
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void searchScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("주소록 검색\n");
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void showAllAddressScene() {
    if(letter == '0') {
        sceneChange(&mainScene);
    }
    
    printf("주소록 조회\n");
    printf("0. 초기 화면으로.\n");
    printf("q. 종료\n");
}

void sceneChange(void (*fParameter)()) {
    system("clear");
    printScene = fParameter;
    //printf("\n");
}




