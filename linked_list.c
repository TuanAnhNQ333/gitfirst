#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// s.push_back('x') : them x vao cuoi string
// s.pop_back() : xoa ky tu cuoi
// s.append('x') : noi ky tu hoac string vao cuoi string
// s.insert(2, 'x') : chen xau x vao vi tri 2 
// s.erase(6) : xoa ky tu thu 6
// s.erase(pos) : xoa tat ca ky tu trong xau s tu chi so pos toi cuoi
// s.erase(pos, n) : xoa n ky tu trong xau s tu chi so pos
// s.subtr(pos) : tra ve xau con cua s tu pos
// s.substr(pos, n) : tra ve xau con n ky tu tu chi so pos
// s.find("x") : tim kiem su xuat hien cua xau con

// struct 1 node trong linked list
struct Node 
{
    int data;
    struct Node* next;
};
// ham tao node moi
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
// ham them phan tu vao cuoi danh sach
void addLast(struct Node ** head, int k)
{
    // neu danh sach rong, them phan tu vao lam phan tu dau tien
    if(*head == NULL)
    {
        *head = createNode(k);
        return ;
    }
    // duyet den cuoi danh sach de them phan tu
    struct Node * temp = *head;
    while(temp -> next != NULL)
    {
        if(temp -> data == k)
            return;
        temp = temp -> next;
    }
    // kiem tra phan tu cuoi cung cua danh sach
    if(temp -> data == k)
        return ;
    temp -> next = createNode(k);

}
// ham them phan tu vao dau danh sach
void addFirst(struct Node ** head, int k)
{
    // kiem tra xem phan tu da ton tai chua
    struct Node * temp = *head;
    while (temp != NULL)
    {
        if(temp -> data == k)
        {
            return ;
        }
        temp = temp -> next;
    }
    // tao nut moi va them vao dau danh sach
    struct Node * newNode = createNode(k);
    newNode -> next = *head;
    *head = newNode;
}
// ham them phan tu vao sau 1 phan tu co gia tri v
void addAfter(struct Node ** head, int u, int v)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;
    // duyet danh sach de tim phan tu co gia tri v
    while (temp != NULL)
    {
        if(temp -> data == u)
        {
            return ;
        }
        if(temp -> data == v)
        {
            prev = temp;
        }
        temp = temp -> next;
    }
    // neu tim thay node co gia tri v, them u vao sau no
    if(prev != NULL)
    {
        struct Node* newNode = createNode(u);
        newNode -> next = prev -> next;
        prev -> next = newNode;
    }
}
// ham them phan tu vao truoc 1 phan tu co gia tri v
void addBefore(struct Node ** head, int u, int v)
{
    if(*head == NULL || (*head) -> data == v)
    {
        addFirst(head, u);
        return;
    }
    struct Node * temp = *head;
    struct Node * prev = NULL;
    // duyet danh sach de tim phan tu co gia tri v
    while (temp != NULL && temp -> data != v)
    {
        if(temp -> data == u) return;
        prev = temp;
        temp = temp -> next;
    }
    // neu tim thay v, them u vao truoc no
    if(temp != NULL)
    {
        struct Node * newNode = createNode(u);
        newNode -> next = temp;
        prev -> next = newNode;
    }
}
// ham xoa phan tu co gia tri k khoi danh sach
void removeNode(struct Node ** head, int k)
{
    if(*head == NULL) return;
    if((*head) -> data == k)
    {
        struct Node * temp = *head;
        *head = (*head) -> next;
        free(temp);
        return;
    }
    struct Node * temp = *head;
    struct Node * prev = NULL;
    // duyet danh sach de tim phan tu co gia tri k
    while (temp != NULL && temp -> data != k)
    {
        prev = temp;
        temp = temp -> next;
    }
    // neu tim thay k thi xoa k
    if(temp != NULL)
    {
        prev -> next = temp -> next;
        free(temp);
    }
}
// ham dao nguoc linked list
void reverse(struct Node ** head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    // duyet qua list va dao nguoc con tro tung node
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
// ham in linked list
void printList(struct Node * head)
{
    struct Node * temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}
int main()
{
    int n, k;
    scanf("%d", &n);
    struct Node * head = NULL; // khoi tao list rong
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &k);
        addLast(&head, k);
    }
    char command[20];
    while(1)
    {
        scanf("%s", command);
    if(command[0] == '#') 
    if(strcmp(command, "addlast") == 0)
    {
        scanf("%d", &k);
        addLast(&head, k);
    }
    else if(strcmp(command, "addfirst") == 0)
    {
        scanf("%d", &k);
        addFirst(&head, k);
    }
    else if(strcmp(command, "addafter") == 0)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addAfter(&head, u, v);
    }
    else if(strcmp(command, "addbefore") == 0)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addBefore(&head, u, v);
    }
    else if(strcmp(command, "remove") == 0)
    {
        scanf("%d", &k);
        removeNode(&head, k);
    }
    else if(strcmp(command, "reverse") == 0)
    {
        reverse(&head);
    }
    printList(head);
    return 0;
}