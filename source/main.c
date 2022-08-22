#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000

typedef struct 
{
    int EmployeeID;
    int ProjectID;
    float Progress;
} PROGRESS;

typedef struct 
{
    int EmployeeID;
    char FirstName[50];
    char LastName[50];
    char Gender[50];
    char DateBirth[50];
    int Department;
    char Country[50];
} EMPLOYEE;

void CountDepartment(EMPLOYEE EE[],int stt,int id)
{
    int d=0;
    for(int i=0;i<stt;i++)
    {
        if (EE[i].Department==id)
        {
            d++;
        }
    }
    
    FILE *file=fopen("result.csv","w");
    fprintf(file,"%d",d);
    fclose(file);
}

void ListMale(EMPLOYEE EE[],int stt)
{
    FILE *file=fopen("result.csv","w");
    for (int i=0;i<stt;i++)
    {
        char *s=strdup(EE[i].Gender);
        if (strcmp(strlwr(s),"male")==0)
        {
            fprintf(file,"%d,%s,%s,%s",EE[i].EmployeeID,EE[i].FirstName,EE[i].LastName,EE[i].Gender);
            fprintf(file,",%s,%d,%s\n",EE[i].DateBirth,EE[i].Department,EE[i].Country);
        }
    }
    fclose(file);
}

void ListFemale(EMPLOYEE EE[],int stt)
{
    FILE *file=fopen("result.csv","w");
    for (int i=0;i<stt;i++)
    {
        char *s=strdup(EE[i].Gender);
        if (strcmp(strlwr(s),"female")==0)
        {
            fprintf(file,"%d,%s,%s,%s",EE[i].EmployeeID,EE[i].FirstName,EE[i].LastName,EE[i].Gender);
            fprintf(file,",%s,%d,%s\n",EE[i].DateBirth,EE[i].Department,EE[i].Country);
        }
    }
    fclose(file);
}

void Report(PROGRESS EP[],int STT,float n)
{
    int luu[MAX];
    int d=0;
    FILE *file=fopen("result.csv","w");
    for (int i=0;i<STT;i++)
    {
        if (EP[i].Progress==n)
        {
            int j;
            for ( j=0;j<d;j++)
            {
                if (EP[i].EmployeeID==luu[j])
                {
                    break;
                }
            }
            if (j==d)
            {
                luu[d++]=EP[i].EmployeeID;
                fprintf(file,"%d\n",EP[i].EmployeeID);
            }
        }
    }
    fclose(file);
}

void Average(PROGRESS EP[],int STT,int x)
{
    FILE *file=fopen("result.csv","w");
    float sum=0;
    int d=0;
    for (int i=0;i<STT;i++)
    {
        if (EP[i].ProjectID==x)
        {
            sum=sum+EP[i].Progress;
            d++;
        }
    }
    fprintf(file,"%.3f",sum/d);
    fclose(file);
}

void swap(EMPLOYEE *a,EMPLOYEE *b)
{
    EMPLOYEE temp=*a;
    *a=*b;
    *b=temp;
}

void SortAsc(EMPLOYEE EE[],int stt)
{
    for (int i=0;i<stt-1;i++)
    {
        for (int j=i+1;j<stt;j++)
        {
            char *s1=strdup(EE[i].LastName);
            char *s2=strdup(EE[j].LastName);
            if (strcmp(strlwr(s1),strlwr(s2))>0)
            {
                swap(EE+i,EE+j);
            }
        }
    }
    for (int i=0;i<stt-1;i++)
    {
        for (int j=i+1;j<stt;j++)
        {
            char *s1=strdup(EE[i].LastName);
            char *s2=strdup(EE[j].LastName);
            if (strcmp(strlwr(s1),strlwr(s2))==0)
            {
                if (strcmp(EE[i].FirstName,EE[j].FirstName)>0)
                {
                    swap(EE+i,EE+j);
                }
            }
        }
    }
    FILE *file=fopen("result.csv","w");
    for (int i=0;i<stt;i++)
    {
        fprintf(file,"%d,%s,%s,%s",EE[i].EmployeeID,EE[i].FirstName,EE[i].LastName,EE[i].Gender);
        fprintf(file,",%s,%d,%s\n",EE[i].DateBirth,EE[i].Department,EE[i].Country);
    }
    fclose(file);
}

void SortDesc(EMPLOYEE EE[],int stt)
{
    for (int i=0;i<stt-1;i++)
    {
        for (int j=i+1;j<stt;j++)
        {
            char *s1=strdup(EE[i].LastName);
            char *s2=strdup(EE[j].LastName);
            if (strcmp(strlwr(s1),strlwr(s2))<0)
            {
                swap(EE+i,EE+j);
            }
        }
    }
    for (int i=0;i<stt-1;i++)
    {
        for (int j=i+1;j<stt;j++)
        {
            char *s1=strdup(EE[i].LastName);
            char *s2=strdup(EE[j].LastName);
            if (strcmp(strlwr(s1),strlwr(s2))==0)
            {
                if (strcmp(EE[i].FirstName,EE[j].FirstName)>0)
                {
                    swap(EE+i,EE+j);
                }
            }
        }
    }
    FILE *file=fopen("result.csv","w");
    for (int i=0;i<stt;i++)
    {
        fprintf(file,"%d,%s,%s,%s",EE[i].EmployeeID,EE[i].FirstName,EE[i].LastName,EE[i].Gender);
        fprintf(file,",%s,%d,%s\n",EE[i].DateBirth,EE[i].Department,EE[i].Country);
    }
    fclose(file);

}

void Country(EMPLOYEE EE[],int stt,char s[])
{
    FILE *file =fopen("result.csv","w");
    for (int i=0;i<stt;i++)
    {
        char *p=strdup(EE[i].Country);
        if (strcmp(strlwr(p),strlwr(s))==0)
        {
            fprintf(file,"%d,%s,%s,%s",EE[i].EmployeeID,EE[i].FirstName,EE[i].LastName,EE[i].Gender);
            fprintf(file,",%s,%d,%s\n",EE[i].DateBirth,EE[i].Department,EE[i].Country);
        }
    }
    fclose(file);
}

//  Hàm chuyển xâu thành số thực

float stof(char s[])
{
    float so=0.0;
    int i;
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]=='.')
        {
            break;
        }
    }
    if (i==strlen(s))
    {
        return atoi(s);
    }
    bool am=false;
    if (s[0]=='-' && s[1]=='0')
    {
        am=true;
    }
    char *p=s;
    p=strtok(p,".");
    so=so+atoi(p);
    p=strtok(NULL," \n");
    char s1[10];
    strcpy(s1,p);
    int sl=strlen(s1);
    so=so+(atoi(s1))/(pow(10,sl));
    if (am)
    {
        return -1.0*so;
    }
    else
    {
        return so;
    }
}

int main()
{
    //  Đọc tệp và lưu vào mảng cấu trúc:

    //  Đọc tệp Progress.csv

    PROGRESS EP[MAX];
    int STT=0;
    FILE *file1=fopen("Progress.csv","r");
    char pr[100];
    fgets(pr,100,file1);
    while ((fgets(pr,100,file1))!=NULL)
    {
        char *p=pr;
        p=strtok(p,", ");
        EP[STT].EmployeeID=atoi(p);
        p=strtok(NULL,", ");
        EP[STT].ProjectID=atoi(p);
        p=strtok(NULL," \n");
        float so=stof(p);
        EP[STT].Progress=so;
        STT++;
    }
    fclose(file1);

    //  Đọc tệp Employee.csv

    EMPLOYEE EE[MAX];
    int stt=0;
    FILE *file2=fopen("Employee.csv","r");
    char text[200];
    fgets(text,200,file2);
    while ((fgets(text,200,file2))!=NULL)
    {
        char *p=strtok(text,",");
        EE[stt].EmployeeID=atoi(text);
        p=strtok(NULL,",");
        strcpy(EE[stt].FirstName,p);
        p=strtok(NULL,",");
        strcpy(EE[stt].LastName,p);
        p=strtok(NULL,",");
        strcpy(EE[stt].Gender,p);
        p=strtok(NULL,",");
        strcpy(EE[stt].DateBirth,p);
        p=strtok(NULL,",");
        EE[stt].Department=atoi(p);
        p=strtok(NULL," \n");
        strcpy(EE[stt].Country,p);
        stt++;
    }
    fclose(file2);


    //  Nhập và thực hiện

    char s[100];
    fgets(s,MAX,stdin);
    if (s[strlen(s)-1]=='\n')
    {
        s[strlen(s)-1]='\0';
    }

    //  Kiểm tra cú pháp:

    //  Nếu kí tự đầu tiên là khoảng cách hay \n thì sai cú pháp

    if (s[0]==32 || s[0]=='\n')
    {
        FILE *file=fopen("check.txt","w");
        fprintf(file,"wrong syntax");
        fclose(file);
        return 22;
    }

    //  Nếu khoảng trống sau câu lệnh lớn hơn 1 thì sai cú pháp

    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]==32)
        {
            if (s[i+1]==32)
            {
                FILE *file=fopen("check.txt","w");
                fprintf(file,"wrong syntax");
                fclose(file);
                return 22;
            }
            break;
        }
    }

    //  Nếu nhiều hoặc ít hơn 2 từ thì sai cú pháp

    char *kt=strdup(s);
    int dem=0;
    while ((kt=strtok(kt," \n"))!=NULL)
    {
        dem++;
        kt=NULL;
    }
    fflush(stdin);
    if (dem!=2)
    {
        FILE *file=fopen("check.txt","w");
        fprintf(file,"wrong syntax");
        fclose(file);
        return 22;
    }

    

    char *p=NULL;
    p=strdup(s);
    p=strtok(p," ");

    if (strcmp(strlwr(p),"count")==0)
    {
        //  Lệnh 1:
        p=strtok(NULL," \n");
        int department=atoi(p);
        CountDepartment(EE,stt,department);

        return 22;
    }

    if (strcmp(strlwr(s),"list male")==0)
    {
        //  Lệnh 3:
        ListMale(EE,stt);
    
        return 22;
    }

    if (strcmp(strlwr(s),"list female")==0)
    {
        //  Lệnh 4:
        ListFemale(EE,stt);

        return 22;
    }

    if (strcmp(strlwr(p),"report")==0)
    {
        //  Lệnh 5:
        p=strtok(NULL," \n");

        //  Kiểm tra xem có phải xâu số thực hay không
        char kiemtra[MAX];
        strcpy(kiemtra,p);
        bool dung=true;
        for (int i=0;i<strlen(kiemtra);i++)
        {
            if (kiemtra[i]=='.' || (kiemtra[i]>=0 && kiemtra[i]<=9))
            {
                dung=true;
            }
            else
            {
                dung=false;
                break;
            }
        }
        int _dem=0;
        for (int i=0;i<strlen(kiemtra);i++)
        {
            if (kiemtra[i]=='.')
            {
                _dem++;
            }
        }
        if (_dem>1)
        {
            dung=false;
        }
        if (!dung)
        {
            FILE *file=fopen("check.txt","w");
            fprintf(file,"wrong syntax");
            fclose(file);
            return 22;
        }

        float n=stof(p);
        if (n<0 || n>1)
        {
            FILE *file=fopen("check.txt","w");
            fprintf(file,"wrong syntax");
            fclose(file);
        }
        else
        {
            Report(EP,STT,n);
        }
        return 22;
    }

    if (strcmp(strlwr(p),"average")==0)
    {
        //  Lệnh 6:
        p=strtok(NULL," \n");
        int x=atoi(p);
        Average(EP,STT,x);
        
        return 22;
    }

    if (strcmp(strlwr(s),"sort asc")==0)
    {
        //  Lệnh 7.1:
        SortAsc(EE,stt);
        
        return 22;
    }

    if (strcmp(strlwr(s),"sort desc")==0)
    {
        //  Lệnh 7.2:
        SortDesc(EE,stt);
        
        return 22;
    }

    if (strcmp(strlwr(p),"country")==0)
    {
        //  Lệnh 8:
        p=strtok(NULL," \n");
        Country(EE,stt,p);
        
        return 22;
    }

    FILE *file=fopen("check.txt","w");
    fprintf(file,"wrong syntax");
    fclose(file);
    
    return 22;
}