//
//  data.h
//  testSort
//
//  Created by 金成日 on 14-5-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#ifndef testSort_data_h
#define testSort_data_h

#define MAXPRIMARY 10

extern int primaryData[MAXPRIMARY];// = {22,3,6,9,7,2,13,42,64,31};

struct singleList
{
    int value;
    struct singleList *list;
};

enum sortType{ASC,DESC};


#endif
