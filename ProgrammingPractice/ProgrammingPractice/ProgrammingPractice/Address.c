//
//  Address.c
//  ProgrammingPractice
//
//  Created by Pooh on 2014. 7. 17..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#include <stdio.h>
#include "Address.h"

void init(Address** address) {
    (*address) = (Address*)malloc(sizeof(Address*));
    
    (*address)->setUserName = &_setUserName;
    (*address)->setPhoneNum = &_setPhoneNum;
    (*address)->setHomeAddress = &_setHomeAddress;
    
    (*address)->node = NULL;
    
    (*address)->userName = NULL;
    (*address)->phoneNum = NULL;
    (*address)->homeAddress = NULL;
}

bool _setUserName(Address* address, char* _userName) { // 한글인지 아닌지 검사.
    int i=0;
    for(i=0; i<sizeof(_userName); i++) {
    }
    
    address->userName = _userName;
    
    return true;
}

bool _setPhoneNum(Address* address, char* _phoneNum) {
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
    
    address->phoneNum = _phoneNum;
    
    return true;
}

bool _setHomeAddress(Address* address, char* _homeAddress) { // 집 주소를 저장함.
    
    address->homeAddress = _homeAddress;
    
    return true;
}





