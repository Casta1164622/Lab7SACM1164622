#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Lista
{
    struct node
    {
        T data;
        node* next;
    };
private:
    node* head, * tail;

    void front(T n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }

    void after(node* a, T value)
    {
        node* p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }

    void remove(node* del)
    {
        node* temp;
        if (del->next != nullptr)
        {
            temp = del->next;
            del->next = temp->next;
            delete temp;
        }
        else
        {
            node* newTail = head;
            while (newTail->next->next != NULL)
            {
                newTail = newTail->next;
                delete (newTail->next);
                newTail->next = NULL;
                tail = newTail;
            }

        }

    }

    node* gethead()
    {
        return head;
    }

public:
    Lista()
    {
        head = NULL;
        tail = NULL;
    }


    void Add(T n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void Clear()
    {
        node* temp = new node();
        node* heads = gethead();
        while (heads != NULL)
        {
            temp = heads;
            heads = heads->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    int GetCount()
    {
        node* head = gethead();
        int counter = 0;

        while (head != NULL)
        {
            head = head->next;
            counter++;
        }
        return counter;
    }

    bool Contains(T item)
    {
        node* head = gethead();

        while (head != NULL)
        {
            if (head->data == item)
            {
                return true;
            }
            head = head->next;
        }
    }

    int IndexOf(T item)
    {
        node* head = gethead();
        int index = 0;

        while (head != NULL)
        {
            if (head->data == item)
            {
                return index;
            }
            head = head->next;
            index++;
        }
        return -1;
    }

    void Insert(int index, T item)
    {
        if (index < 0 || index >= GetCount()) return;
        if (index == 0) Add(item);
        if (index > 0)
        {
            node* head = gethead();
            for (int i = 0; i < index; i++)
            {
                if (i == index - 1)
                {
                    after(head, item);
                }
                head = head->next;

            }
        }

    }

    node* GetItem(int index)
    {
        if (index < 0 || index >= GetCount()) return NULL;
        node* head = gethead();
        int stop = 0;

        while (head != NULL)
        {
            if (stop == index)
            {
                return head;
            }
            head = head->next;
            stop++;
        }
    }

    void SetItem(int index, T item)
    {
        if (index < 0 || index >= GetCount()) return;
        node* node = GetItem(index);
        node->data = item;
    }

    int LastIndexOf(T item)
    {
        node* head = gethead();
        int index = 0;
        int result;
        while (head != NULL)
        {
            if (head->data == item)
            {
                result = index;
            }
            head = head->next;
            index++;
        }
        return result;
    }

    bool Remove(T item)
    {
        if (IndexOf(item) != -1)
        {
            remove(GetItem(IndexOf(item)));
            return true;
        }
        return false;

    }

    void RemoveAt(int index)
    {
        if (index == 0 && GetCount() == 1)
        {
            Clear();
        }

        if (GetItem(index) != NULL)
        {
            remove(GetItem(index));
        }
    }
};