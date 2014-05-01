//
//  main.mm
//  testSort
//
//  Created by 金成日 on 14-5-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sortList.h"
#include "data.h"

int primaryData[MAXPRIMARY] = {22,3,6,9,7,2,13,42,64,31};

void insertSort(int data[],int cnt,enum sortType type);

class CSortList;

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        //数组 插入排序
//        for (int i=0; i<MAXPRIMARY; ++i) {
//            NSLog(@"primaryData[%d]:%d",i,primaryData[i]);
//        }
//        
//        insertSort(primaryData, MAXPRIMARY, DESC);
//        
//        NSLog(@"will do insertSort.");
//        for (int i=0; i<MAXPRIMARY; ++i) {
//            NSLog(@"newData[%d]:%d",i,primaryData[i]);
//        }
        
        //单链表 插入排序
        CSortList list;
    
        for (int i=0; i<MAXPRIMARY; ++i) {
            singleList *noteList = new singleList;
            noteList->value = primaryData[i];
            noteList->list = NULL;
        
            NSLog(@"addnote value:%d",noteList->value);
            list.addList(noteList,4,DESC);
        }
        
        NSLog(@"list count:%d",list.getCount());
        
        int cnt = 1;
        singleList *outnote = list.getFirstNote();
        while (outnote->list) {
            NSLog(@"list%d value:%d",cnt++,outnote->value);
            outnote = outnote->list;
            
            if (!outnote->list) {
                NSLog(@"list%d value:%d",cnt++,outnote->value);
            }
        }
    }
    return 0;
}

void insertSort(int data[],int cnt,enum sortType type)
{
    int i,j;
    for (i=1; i<cnt; ++i) {
        if (type == DESC ? data[i-1] < data[i] : data[i-1] > data[i]) {
            int temp = data[i];
            for (j = i; j>=1 && (type == DESC ? data[j-1] < temp : data[j-1] > temp); --j) {
                data[j] = data[j-1];
            }
            data[j] = temp;
        }
    }
}






