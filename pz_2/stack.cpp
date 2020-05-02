#include "prototypes.h"
#include <stdio.h>

void SPush(stack *&p, int num)
{
   if (p)
   {
      stack *q = new stack(p, num);
      p = q;
   }
   else
   {
      p = new stack(NULL, num);
   }
}
int SPop(stack *&p, int &num)
{
   if (!SEmptiness(p))
   {
      num = p->elem;
      if (p->next == NULL)
      {
         delete p;
         p = NULL;
      }
      else
      {
         stack *q = p;
         p = p->next;
         delete q;
      }
      return 0;
   }
   return 1;
}
void SPrint(const stack *p)
{
   printf_s("Содержимое стека: ");
   if (p)
   {
      const stack *q = p;
      do
      {
         printf_s("%d ", q->elem);
         q = q->next;
      } while (q);
   }
   printf_s("\n");
}
