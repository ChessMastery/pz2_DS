#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "prototypes.h"

int MStack()
{
   enum SComands { CMD_SPUSH = 1, CMD_SPRINT, CMD_SPOP, CMD_SCLEAR, CMD_SBACK };

   int n = 0, exitFlag = 0, m = 0;
   stack *st = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - поместить элемент в стек\n");
      printf_s("<2> - распечатать содержимое стека\n");
      printf_s("<3> - извлечь элемент из стека\n");
      printf_s("<4> - очистить данные\n");
      printf_s("<5> - вернуться к предыдущему меню\n");
      int repeatFlag = 0;
      do {
         printf_s("Введите номер команды (от 1 до 4): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("ошибка ввода");
            _getch();
            return 0;
         }
         switch (n)
         {
         case CMD_SPUSH: printf_s("Введите число: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("ошибка ввода");
               _getch();
               return 0;
            }
            SPush(st, m);
            break;
         case CMD_SPRINT: if (SEmptiness(st))
            printf_s("Стек пуст\n");
                        else
            SPrint(st);
            break;
         case CMD_SPOP: SPop(st, m) ?
            printf_s("Стек пуст\n") :
            printf_s("Из стека извлечен элемент: %d\n", m);
            break;
         case CMD_SCLEAR: delete st;
            st = NULL;
            break;
         case CMD_SBACK: delete st;
            st = NULL;
            exitFlag = 1;
            break;
         default: printf_s("ОШИБКА: неверный номер команды\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MQueue()
{

   enum Comands { CMD_QPUSH = 1, CMD_QPRINT, CMD_QPOP, CMD_QCLEAR, CMD_QBACK };

   int n = 0, exitFlag = 0, m = 0;
   queue *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - поместить элемент в очередь\n");
      printf_s("<2> - распечатать содержимое очереди\n");
      printf_s("<3> - извлечь элемент из очереди\n");
      printf_s("<4> - очистить данные\n");
      printf_s("<5> - вернуться к предыдущему меню\n");
      int repeatFlag = 0;
      do {
         printf_s("Введите номер команды (от 1 до 4): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("ошибка ввода");
            _getch();
            return 0;
         }
         switch (n)
         {
         case CMD_QPUSH: printf_s("Введите число: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("ошибка ввода");
               _getch();
               return 0;
            }
            if (QEmptiness(Q))
               QCreation(Q, m);
            else
               QPush(Q, m);
            break;
         case CMD_QPRINT: if (QEmptiness(Q))
            printf_s("Очередь пуста\n");
                        else
            QPrint(Q);
            break;
         case CMD_QPOP: QEmptiness(Q) ?
            printf_s("Очередь пуста\n") :
            printf_s("Из очереди извлечен элемент: %d\n", QPop(Q, Q->beg->elem));
            break;
         case CMD_QCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_QBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("ОШИБКА: неверный номер команды\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int main()
{
   enum Comands { CMD_STACK = 1, CMD_QUEUE, CMD_EXIT };

   int n = 0, exitFlag = 0, m = 0;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("Выберите структуру данных:\n");
      printf_s("<1> - стек\n");
      printf_s("<2> - очередь\n");
      printf_s("<3> - выход\n");
      int repeatFlag = 0;
      do {
         printf_s("Введите номер команды (от 1 до 3): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("ошибка ввода");
            _getch();
            return 0;
         }
         switch (n)
         {
         case CMD_STACK: MStack();
            repeatFlag = 1;
            break;
         case CMD_QUEUE: MQueue();
            repeatFlag = 1;
            break;
         case CMD_EXIT: exitFlag = 1;
            break;
         default: printf_s("ОШИБКА: неверный номер команды\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);

   return 0;
}
