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
    void (*init)(struct address* this);
    
    bool (*setUserName)(struct address*, char*);
    bool (*setPhoneNum)(struct address*, char*);
    bool (*setHomeAddress)(struct address*, char*);
    
    bool (*insertNode)(struct address*);
    
    struct address* node;
    
    char* userName;
    char* phoneNum;
    char* homeAddress;
    
} Address;

#endif
