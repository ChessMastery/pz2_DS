#ifndef PROTOTYPES_H
#define PROTOTYPES_H
#include <stdlib.h>
struct slist
{
   slist *next;
   int elem;
   slist(slist *_next = NULL, int _elem = 0) : next(_next), elem(_elem) {};
};

typedef slist stack;

inline bool SEmptiness(const stack *p)
{
   return p == NULL;
}

void SPush(stack *&p, int num);

int SPop(stack *&p, int &num);

void SPrint(const stack *p);

struct qlist
{
   char elem;
   qlist *next;
   qlist(int _elem, qlist *_next = NULL) : elem(_elem), next(_next) {};
};

struct queue
{
   qlist *beg, *end;
   queue() : beg(NULL), end(NULL) {};
};

inline bool QEmptiness(queue *Q)
{
   return Q == NULL;
}

void QPush(queue *&Q, int elem);

int QPop(queue *Q, int elem);

void QPrint(queue *const Q);

#endif