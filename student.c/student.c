#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STUDENT 100
#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 50

typedef struct 
{
    int stt;
    char mssv[20];
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    float score;
} student ;
// doc thong tin sinh vien tu file
void readfromfile(const char *fn, student s[], int *cnt)
{
    FILE *file = fopen(fn, "r");
    if(file == NULL)
    {
        printf("cannot open file %s", fn);
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (fscanf(file, "%d %s %s %s", &s[i].stt, s[i].mssv, s[i].name, s[i].phone) != EOF)
    {
        i ++;
    }
    *cnt = i;
    fclose(file);
}
// nhap diem vao file cho sinh vien
void inputscore(student s[], int cnt)
{
    for(int i = 0; i < cnt; i ++)
    {
        printf("nhap diem cho sinh vien %s (%s)", s[i].name, s[i].mssv);
        scanf("%f", &s[i].score);
    }

}
// viet them thong tin diem vao file cho sinh vien
void writetofile(const char *fn, student s[], int cnt)
{
    FILE *file = fopen(fn, "w");
    if(file == NULL)
    {
        printf("cannot open file %s", fn);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < cnt; i ++)
    {
        fprintf(file, "%d %s %s %s %.2f\n", s[i].stt, s[i].mssv, s[i].name, s[i].phone, s[i].score);
    }
    fclose(file);
}

// in file thong tin cho sinh vien
void printfile(student s[], int cnt)
{
    for(int i = 0; i < cnt; i ++)
    {
        printf("%d %s %s %s %.2f\n", s[i].stt, s[i].mssv, s[i].name, s[i].phone, s[i].score);
    }
    printf("\n");

}
int main()
{
    student s[MAX_STUDENT];
    int cnt = 0; 
    readfromfile("student_read.txt", s, &cnt);
    inputscore(s, cnt);
    writetofile("student_write.txt", s, cnt);
    printfile (s, cnt);
    return 0;
}