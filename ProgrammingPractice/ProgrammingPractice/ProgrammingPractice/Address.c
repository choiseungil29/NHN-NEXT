//
//  Address.c
//  ProgrammingPractice
//
//  Created by Pooh on 2014. 7. 17..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#include <stdio.h>
#include "Address.h"

bool init(Address*, char*, char*, char*);
bool _setUserName(Address*, char*);
bool _setPhoneNum(Address*, char*);
bool _setHomeAddress(Address*, char*);
bool _insertNode(Address* address, char*, char*, char*);

bool init(Address* address, char* _userName, char* _phoneNum, char* _homeAddress) {
    
    address = (Address*)malloc(sizeof(Address*));
    address->setUserName = _setUserName;
    address->setPhoneNum = _setPhoneNum;
    address->setHomeAddress = _setHomeAddress;
    address->insertNode = _insertNode;
    
    address->node = NULL;
    
    if(!address->setUserName(address, _userName)) {
        return false;
    }
    if(!address->setPhoneNum(address, _phoneNum)) {
        return false;
    }
    if(!address->setHomeAddress(address, _homeAddress)) {
        return false;
    }
    
    return true;
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

bool _insertNode(Address* address, char* userName, char* phoneNum, char* homeAddress) { // 노드를 추가해준다.
    Address* node = address->node;
    if(!init(node, userName, phoneNum, homeAddress)) {
        return false;
    }
    return true;
}













