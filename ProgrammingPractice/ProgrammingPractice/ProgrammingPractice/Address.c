//
//  Address.c
//  ProgrammingPractice
//
//  Created by Pooh on 2014. 7. 17..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#include <stdio.h>

typedef enum {false, true} bool;

typedef struct address {
    void (*init)(struct address* this);
    bool (*setUserName)(char* _userName);
    bool (*setPhoneNum)(char* _phoneNum);
    bool (*setHomeAddress)(char* _homeAddree);

    struct address* node;
    
    char* userName;
    char* phoneNum;
    char* homeAddress;
    
} Address;

void init(Address* address) {
    address->setUserName = &setUserName;
    address->setPhoneNum = &setPhoneNum;
    address->setHomeAddress = &setHomeAddress;
    
    address->node = NULL;
    
    address->userName = NULL;
    address->phoneNum = NULL;
    address->homeAddress = NULL;
}

bool setUserName(char* _userName) { // 한글인지 아닌지 검사.
    int i=0;
    for(i=0; i<sizeof(_userName); i++) {
    }
    return false;
}

bool setPhoneNum(char* _phoneNum) {
    if(sizeof(_phoneNum) != 13) { // 배열의 길이 수 검사
        return false;
    }
    
    int i=0;
    for(i=0; i<sizeof(_phoneNum); i++) {
        char letter = _phoneNum[i];
        if(!(letter >= '0' && letter <= '9')) { // _phoneNum 안의 글자가 숫자가 아닐 때 조건문 진입
            if(letter != '-') { // 숫자도 아니고, 번호 인식 표시인 '-'도 아닐 때 false 반환
                return false;
            }
        }
        
    }
    
    return false;
}

bool setHomeAddress(char* _homeAddress) {
    return false;
}