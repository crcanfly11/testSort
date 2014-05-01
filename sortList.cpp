//
//  sortList.cpp
//  testSort
//
//  Created by 金成日 on 14-5-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#include "sortList.h"

CSortList::CSortList()
{
    count = 0;
    pFirstNote = NULL;
}

CSortList::~CSortList()
{
    singleList *dltNote,*note = pFirstNote;
    while (note->list) {
        dltNote = note;
        note = note->list;
        delete dltNote;
    }
}

int CSortList::addList(singleList *list,unsigned int maxcnt,enum sortType type)
{
    if (!list) return -1;
    
    if (!pFirstNote) {
        pFirstNote = list;
        count++;
    }
    else {
        if (type == ASC ? list->value <= pFirstNote->value : list->value >= pFirstNote->value) {
            list->list = pFirstNote;
            pFirstNote = list;
            count++;
            removeLastNote(maxcnt);
            return 0;
        }
        
        singleList *temp = pFirstNote->list; //只有一个节点的时候 pFirstNote->list是空值
        singleList *preNote = pFirstNote;
        for (int i=1;i<count;++i) {
            if (type == ASC ? list->value <= temp->value : list->value >= temp->value) {
                preNote->list = list;
                list->list = temp;
                count++;
                removeLastNote(maxcnt);
                return 0;
            }
            else if (temp->list == NULL) {
                temp->list = list;
                count++;
                removeLastNote(maxcnt);
                return 0;
            }
            preNote = temp;
            temp = temp->list;
        }
        
        //升序/降序时 添加的第二个参数 大于/小于第一个参数 就直接添加
        if (type == ASC ? preNote->value < list->value : preNote->value > list->value) {
            preNote->list = list;
            count++;
            removeLastNote(maxcnt);
            return 0;
        }
    }
    
    return 0;
}

//if (temp == pFirstNote ) {
//    if (list->value <= temp->value) {
//        list->list = temp;
//        pFirstNote = list;
//        count++;
//        return 0;
//    }
//    else if (temp->list == NULL) {
//        temp->list = list;
//        count++;
//        return 0;
//    }
//}
//else {
//    if (list->value <= temp->value) {
//        prenNote->list = list;
//        list->list = temp;
//        count++;
//        return 0;
//    }
//    else if (temp->list == NULL) {
//        temp->list = list;
//        count++;
//        return 0;
//    }
//}

void CSortList::removeLastNote(unsigned int maxcnt)
{
    if (count > maxcnt) {
        singleList *temp = pFirstNote;
        while (temp->list) {
            temp = temp->list;
            if (!temp->list->list) {
                delete temp->list;
                temp->list = NULL;
            }
        }
    }
}
