#include "conio.h"
#include "stdio.h"
#define list struct spisok
#define dr struct sv

list
{ int info;
list* next;
};

dr
{
  list * down;
  dr* right;
  dr* left;
};

dr* t, * s, * p;
list* t2, * p2, * p1, * t1;
int  main()
{
    int a, n = 0, l = 0;
    char y, c;
    printf("Vvedite a ili 0 dlya exit\n");
    scanf_s("%d", &a);
    if (a == 0)
        printf("list pust");
    else
    {
        while (a != 0)
        {
            t1 = new list;
            t1->next = 0;
            t1->info = a;
            t = new dr;
            t->down = t1;
            t->right = 0;
            if (l == 0)
            {
                t->left = 0; l++;
            }
            else
                t->left = p;
            if (s == 0)
                s = t;
            else
            {
                p->right = t;
                p1->next = t1;
                //p->left = t;
            }
            printf("Vvedite a ");
            scanf_s("%d", &a);
            p = t; p1 = t1;
        }
        y = 'y';
        while (y == 'y')
        {
            p = s; p1 = 0;
            printf("\nDlya upravleniya use:\n");
            printf("2-down 4-left 6-right 1-exit\n");
            c = _getch();
            while (c != '1')
            {
                if (c == '2') //down
                    if (n == 0)
                    {
                        if (p->down != 0)
                        {
                            p1 = p->down;
                            printf("\n|\nv\n%d", p1->info);
                        }
                        else printf(" Pusto down\n");
                        n = 1;
                    }
                    else printf(" Pusto down ");
                if (c == '6') // right
                {
                    if (n == 1)
                        if (p1->next != 0)
                        {
                            p1 = p1->next;
                            printf("->%d", p1->info);
                        }
                        else
                            printf(" Pusto right ");
                    if (n != 1)
                        if (p->right != 0)
                        {
                            printf("->");
                            p = p->right;
                        }
                        else
                            printf(" Pusto right ");
                }
                if (c == '4') // left
                {
                    if (n == 1)
                        printf(" Error: odno naprovleniye ");
                    else
                    {
                        if (p->left != 0)
                        {
                            p = p->left;
                            printf("<-");
                        }
                        else
                            printf(" Error: pusto left ");
                    }
                }
                c = _getch();
            }
            printf("\nbegin ?(y/n)");
            y = _getch();
        }
    }
    return 0;
}
