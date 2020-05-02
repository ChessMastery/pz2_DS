#include "prototypes.h"
#include <stdio.h>

void QPush(queue *&Q, int elem)
{
   if (QEmptiness(Q))
   {
      Q = new queue();
      Q->beg = new qlist(elem);
      Q->end = Q->beg;
   }
   else
   {
      Q->end->next = new qlist(elem);
      Q->end = Q->end->next;
   }
}

int QPop(queue *Q, int elem)
{
   elem = Q->beg->elem;
   qlist *q = Q->beg;
   Q->beg = Q->beg->next;
   delete q;
   q = NULL;
   return(elem);
}

void QPrint(queue *const Q)
{
   printf_s("Содержимое очереди: ");
   if (Q)
   {
      const qlist *p = Q->beg;
      do
      {
         printf_s("%d ", p->elem);
         p = p->next;
      } while (p);
   }
   printf_s("\n");
}
