#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
struct stu
{
    char name[50];
    int age;
    float gpa;
    int code;
    char dep[50];
    int year;
    int rolln;


};
int showInterface()
{
    int a;
 printf("\033[0;36m");
    printf("\t\t\t               ==============WELCOME===============\n\n");
    printf(" \t\t\t\t         1) ADD A STUDENT  \n\n");
    printf(" \t\t\t\t         2) FIND A STUDENT (by roll number)  \n\n");
    printf(" \t\t\t\t         3) FIND A STUDENT (by first name)  \n\n");
    printf(" \t\t\t\t         4) FIND A STUDENT (by department)  \n\n");
    printf(" \t\t\t\t         5) SHOW ALL STUDENT  \n\n");
    printf(" \t\t\t\t         6) EDIT A STUDENT DATA  \n\n");
    printf(" \t\t\t\t         7) DELETE A STUDENT   \n\n");

    printf("\t\t\t\t        ___________________________________\n\n");
    printf("\t\t\t\t         : ");
    scanf("%d",&a);

    return a;

}
void add()
{
    printf("\033[0;32m");

    FILE *s= fopen("students.txt","a");

    if(s==NULL)
    {

        printf("CANNOT BE OPENNED!!!!");

    }
    else
    {
        struct stu stu;
        char f;

        printf("\n \t\t\t\t\tENTER FIRST NAME OF THE STUDENT \n\n ");

        printf("\t\t\t\t         : ");
        scanf("%s",stu.name);
        printf("\n \t\t\t\t\tENTER AGE OF THE STUDENT \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%d",&stu.age);
        printf("\n \t\t\t\t\tENTER GPA OF THE STUDENT \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%f",&stu.gpa);
        printf("\n \t\t\t\t\tENTER CODE OF THE STUDENT \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%d",&stu.code);
        printf("\n \t\t\t\t\tENTER YEAR OF THE STUDENT \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%d",&stu.year);
        printf("\n \t\t\t\t\tENTER DEPARTMENT OF THE STUDENT \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%s",&stu.dep);
        printf("\n \t\t\t\t\tENTER ROLL NUMBER  \n\n ");
        printf("\t\t\t\t         : ");
        scanf("%d",&stu.rolln);
        fwrite(&stu,sizeof(struct stu),1,s);

        printf("\n\t\t\t\t\t[ STUDENT SAVED ]\n");


    }
    fclose(s);

}
void find()
{
    printf("\033[0;32m");
    int r=1;
    struct stu s1;
    int a;
    printf("\n\t\t\t\t\tENTER STUDENT ROLL NUMBER :\n\n");
    printf("\t\t\t\t         : ");
    scanf("\t\t\t\t%d",&a);
    FILE *h=fopen("students.txt","r");
    while(fread(&s1,sizeof(struct stu),1,h)!=0)
    {
        if(s1.rolln==a)
        {
            r=0;
            printf("\t\t\t\t\tName: %s\n\t\t\t\t\tAge: %d\n\t\t\t\t\tGPA: %0.1f\n\t\t\t\t\tCode: %d\n\t\t\t\t\tYear: %d\n\t\t\t\t\tDepartment: %s\n\t\t\t\t\tRoll Number: %d\n\n",s1.name,s1.age,s1.gpa,s1.code,s1.year,s1.dep,s1.rolln);
            printf("\t\t\t\t ___________________________________\n\n ");

        }

    }
    if(r!=0)
        printf("\t\t\t\t   CANT FIND \n");
    fclose(h);


}
void show()
{
    printf("\033[0;32m");
    int l=0;
    struct stu s1;
    FILE *j=fopen("students.txt","r");
    if (j!=NULL)
        while(fread(&s1,sizeof(struct stu),1,j)!=0)
        {
            l++;
            printf("\t\t\t\t _________________STUDENT[%d]______________\n\n",s1.rolln);
            printf("\t\t\t\t\tName: %s\n\t\t\t\t\tAge: %d\n\t\t\t\t\tGPA: %0.1f\n\t\t\t\t\tCode: %d\n\t\t\t\t\tYear: %d\n\t\t\t\t\tDepartment: %s\n\t\t\t\t\tRoll Number: %d\n\n",s1.name,s1.age,s1.gpa,s1.code,s1.year,s1.dep,s1.rolln);
            printf("\t\t\t\t ___________________________________\n\n ");
        }
    else
        printf("    EROR   ");
    fclose(j);
}
void find_By_Name()
{
printf("\033[0;32m");
    struct stu s1;
    char g,a[50];
    int r=1;
    printf("\n\t\t\t\t\tENTER STUDENT FIRST NAME :\n\n");
    printf("\t\t\t\t         : ");
    scanf("\t\t\t\t%s",&a);
    FILE *h=fopen("students.txt","r");
    while(fread(&s1,sizeof(struct stu),1,h)!=0)
    {
        if(strcmp(a,s1.name)==0)
        {
            r=0;
            printf("\t\t\t\t\tName: %s\n\t\t\t\t\tAge: %d\n\t\t\t\t\tGPA: %0.1f\n\t\t\t\t\tCode: %d\n\t\t\t\t\tYear: %d\n\t\t\t\t\tDepartment: %s\n\t\t\t\t\tRoll Number: %d\n\n",s1.name,s1.age,s1.gpa,s1.code,s1.year,s1.dep,s1.rolln);
            printf("\t\t\t\t ___________________________________\n\n ");

        }

    }

    if(r!=0)
        printf("\t\t\t\t   CANT FIND \n");
    fclose(h);

}
void find_By_Dep()
{
    printf("\033[0;32m");
    int r=1;
    struct stu s1;
    char a[50];
    printf("\n\t\t\t\t\tENTER STUDENT DEP :\n\n");
    printf("\t\t\t\t         : ");
    scanf("%\t\t\t\ts",&a);
    FILE *h=fopen("students.txt","r");
    while(fread(&s1,sizeof(struct stu),1,h)!=0)
    {
        if(strcmp(a,s1.dep)==0)
        {
            r=0;
            printf("\t\t\t\t\tName: %s\n\t\t\t\t\tAge: %d\n\t\t\t\t\tGPA: %0.1f\n\t\t\t\t\tCode: %d\n\t\t\t\t\tYear: %d\n\t\t\t\t\tDepartment: %s\n\t\t\t\t\tRoll Number: %d\n\n",s1.name,s1.age,s1.gpa,s1.code,s1.year,s1.dep,s1.rolln);
            printf("\t\t\t\t ___________________________________\n\n ");

        }

    }
    if(r!=0)
        printf("\t\t\t\t   CANT FIND \n");
    fclose(h);



}
int delete_Stu()
{
    printf("\033[0;32m");
    struct stu s1;
    char g,a[50];
    int r=1;
    printf("\n\t\t\t\t\tENTER STUDENT FIRST NAME :\n\n");
    printf("\t\t\t\t         : ");
    scanf("\t\t\t\t%s",&a);
    FILE *k=fopen("students1.txt","w");
    FILE *h=fopen("students.txt","r");

    while(fread(&s1,sizeof(struct stu),1,h)!=0)
    {
        if(strcmp(a,s1.name)!=0)
        {

            fwrite(&s1,sizeof(struct stu),1,k);
            printf("\t\t\t\t ___________________________________\n\n ");

        }
        else r=0;

    }
    fclose(k);
    fclose(h);
    if( rename("students.txt","stu.txt")==0)

        rename("students1.txt","students.txt");
    if(r=1)
    {
        printf("\t\t\t\t\t STUDENT DELETED \n\n");
    }

    remove("stu.txt");
}
void edit_Stu()
{
    printf("\033[0;32m");
    delete_Stu();
    add();
}
/// @brief

int main()
{



    int q, b= showInterface();
    switch (b)
    {

    case 1:
        system("cls");
        add();
        break;

    case 2:

        system("cls");
        find();
        break;
    case 5:
        system("cls");
        show();
        break;
    case 3:
        system("cls");
        find_By_Name();
        break;
    case 4:
        system("cls");
        find_By_Dep();
        break;
    case 6:
        system("cls");
        edit_Stu();
        break;
    case 7:
        system("cls");
        delete_Stu();
        break;


    }
    printf(" \t\t\t\t           ENTER (0) FOR MAIN LIST  \n\n");
    printf("\t\t\t\t         : ");
    scanf("%d",&q);
    if(q==0)
    {
        system("cls");
        main();
    }


}

