//
//  Address.h
//  ProgrammingPractice
//
//  Created by CLogic on 2014. 7. 18..
//  Copyright (c) 2014년 Pooh. All rights reserved.
//

#ifndef ProgrammingPractice_Address_h
#define ProgrammingPractice_Address_h

typedef enum {false, true} bool;

typedef bool (*fp)(char*);

typedef struct address {
    
    bool (*setUserName)(struct address*, char*);
    bool (*setPhoneNum)(struct address*, char*);
    bool (*setHomeAddress)(struct address*, char*);
    
    struct address* node;
    
    int id;
    char* userName;
    char* phoneNum;
    char* homeAddress;
    
} Address;

bool _setUserName(Address*, char*);
bool _setPhoneNum(Address*, char*);
bool _setHomeAddress(Address*, char*);

#endif
