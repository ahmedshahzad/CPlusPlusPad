
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

class node
{
public:
    char data;
    node *next;
    node *prev;
    node *up;
    node *down;
    node(char c)
    {
        data = c;
        next = NULL;
        prev = NULL;
        up = NULL;
        down = NULL;
    }
};

class TwoDDLLADT
{
    node *first, *cursor;

public:

    TwoDDLLADT()
    {
        first = NULL;
        cursor = NULL;
    }

    void Insert(char c)
    {
        node *temp = new node(c);
        if (first == NULL)
        {
            first = temp;
            cursor = temp;
        }
        else
        {
            if (cursor->next == NULL)
            {
                cursor->next = temp;
                temp->prev = cursor;
                cursor = temp;
            }
            else
            {
                temp->next = cursor->next;
                cursor->next->prev = temp;
                cursor->next = temp;
                temp->prev = cursor;
                cursor = temp;
            }
        }
    }

    void Print()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }

    void Save()
    {
        node *temp = first;
        FILE *fp = fopen("save.txt", "w");
        while (temp != NULL)
        {
            fprintf(fp, "%c", temp->data);
            temp = temp->next;
        }
        fclose(fp);
    }

    void Load()
    {
        FILE *fp = fopen("save.txt", "r");
        char c;
        while (fscanf(fp, "%c", &c) != EOF)
        {
            Insert(c);
        }
        fclose(fp);
    }

    

    void Up()
    {
        if (cursor->up != NULL)
        {
            cursor = cursor->up;
        }
    }

    void Down()
    {
        if
        (cursor->down != NULL)
        {
            cursor = cursor->down;
        }
    }

    void Left()
    {
        if (cursor->prev != NULL)
        {
            cursor = cursor->prev;
        }
    }

    void Right()
    {
        if (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
    }

    void PrintCursor()
    {
        node *temp = first;
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                cout << "|";
            }
            cout << temp->data;
            temp = temp->next;
        }
    }

    void PrintCursor(int x, int y)
    {
        node *temp = first;
        int i = 0;
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }

   

    void NewLine()
    {
        node *temp = new node('\n');
        if (cursor->next == NULL)
        {
            cursor->next = temp;
            temp->prev = cursor;
            cursor = temp;
        }
        else
        {
            temp->next = cursor->next;
            cursor->next->prev = temp;
            cursor->next = temp;
            temp->prev = cursor;
            cursor = temp;
        }
    }


    void PrintCursor(int x, int y, int start, int end)
    {
        node *temp = first;
        int i = 0;
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }


    void PrintAll(int x, int y, int start, int end)
    {
        node *temp = first;
        int i = 0;
        while (temp != NULL)
        {
            if (temp == cursor)
            {
                gotoxy(x + i, y);
                cout << "|";
            }
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }

    void PrintAll()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }

    void PrintAll(int x, int y)
    {
        node *temp = first;
        int i = 0;
        while (temp != NULL)
        {
            gotoxy(x + i, y);
            cout << temp->data;
            temp = temp->next;
            i++;
        }
    }



    void Delete()
    {
        if (cursor->next == NULL)
        {
            if (cursor->prev == NULL)
            {
                delete cursor;
                cursor = NULL;
                first = NULL;
            }
            else
            {
                cursor = cursor->prev;
                delete cursor->next;
                cursor->next = NULL;
            }
        }
        else
        {
            if (cursor->prev == NULL)
            {
                first = cursor->next;
                delete cursor;
                cursor = first;
                cursor->prev = NULL;
            }
            else
            {
                cursor->prev->next = cursor->next;
                cursor->next->prev = cursor->prev;
                node *temp = cursor;
                cursor = cursor->next;
                delete temp;
            }
        }
    }
};


int main()
{
    TwoDDLLADT t;
    t.Load();
    t.PrintAll();
    char c;
    while (1)
    {
        c = getch();
        if (c == 13)
        {
            t.NewLine();
        }
        else if (c == 8)
        {
            t.Delete();
        }
        else if (c == 27)
        {
            t.Save();
            break;
        }
        else if (c == 38)
        {
            t.Up();
        }
        else if (c == 80)
        {
            t.Down();
        }
        else if (c == 75)
        {
            t.Left();
        }
        else if (c == 77)
        {
            t.Right();
        }
        else
        {
            t.Insert(c);
        }
        system("cls");
        t.PrintAll();
    }
    return 0;
}
