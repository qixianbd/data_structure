/*
 * skiplistwithc.h
 *
 *  Created on: 2014年11月6日
 *      Author: qmwx
 */

#ifndef SKIPLISTWITHC_H_
#define SKIPLISTWITHC_H_



#define SKIPLIST_MAXLEVEL 8

typedef struct skiplistNode {
    double score;
    struct skiplistNode *backward;
    struct skiplistLevel {
        struct skiplistNode *forward;
    }level[];
}skiplistNode;

typedef struct skiplist {
    struct skiplistNode *header, *tail;
    unsigned long length;
    int level;
}skiplist;




#endif /* SKIPLISTWITHC_H_ */
