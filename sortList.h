//
//  sortList.h
//  testSort
//
//  Created by 金成日 on 14-5-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#ifndef __testSort__sortList__
#define __testSort__sortList__

#include <iostream>
#include "data.h"

class CSortList
{
public:
    CSortList();
    ~CSortList();
    
    int addList(singleList *list,unsigned int maxcnt,enum sortType type = ASC);
    
    unsigned int getCount() const {return count;}
    singleList* getFirstNote() const {return pFirstNote;}
    
private:
    void removeLastNote(unsigned int maxcnt);
    
    unsigned int count;
    singleList *pFirstNote;
    
};

#endif /* defined(__testSort__sortList__) */
