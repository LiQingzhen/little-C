#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
double sort(double a[],double n);
double forluma(double figure[],char sign[],int q);
int main(void)
{
    printf("-----------------��ʮ�ĵ���Ϸ-----------------\n");
    printf("��Ϸ˵����\n��Ϸ������ĸ����֣�1--13��\n����Ҫ���ã������ظ�ʹ�ã����ĸ�����\n");
    printf("�����������㣨��������ţ��õ�24�Ľ��\n");
    printf("����������ֲ�������ĿҪ����Ϸ�����ѡ�����𰸡�\n"
           "�����ʽ���������ʽΪ��׼\n");
    printf("----------------------------------------------\n");
     //��Ϸ����

    int i,j,x=3,y=2,y1,cout,k,t1,t2=0,t3,p,countin;
    double data[4],figure[4],copy[4],figurebox[4],result,m[4];
    char start[3]={"YES"},start1[3],sign[7],signbox[4],answer[20],n[7];
    printf("���ڣ������롰YES��������Ϸ\n");
    gets(start1);
    if(start1[0]=='Y'&&start1[1]=='E'&&start1[2]=='S'){//�õ�����������Ž���Ϊdata��������
            srand(time(0));
            printf("��Ϸ��ʼ\n");
            printf("�������㽫�õ����ĸ�����\n");
        for(i=0;i<4;i++){
                data[i]=1+rand()%13;
                printf("%3g",data[i]);}
        printf("\n���������Ĵ�\n"); //�õ�����������Ž���Ϊdata��������
    }
TOP2:gets(answer);
    for(i=0;i<strlen(answer);i++){
        if(answer[i]=='('||answer[i]==')')y++;
    }y1=y;
    for(i=strlen(answer)-1;i>=0;i--){
        if(answer[i]>47&&answer[i]<58){
                if((answer[i-1]>47&&answer[i-1]<58)&&i>0){
                    figure[x]=answer[i]-38;i--;
                }
                else
                    figure[x]=answer[i]-48;x--;}
        else {
            sign[y]=answer[i];y--;}
    }                               //ʽ�ӵĲ��
    for(i=0;i<4;i++)copy[i]=figure[i];
    sort(data,4);sort(copy,4);
    for(i=0,j=0;i<4;i++){
        if(data[i]==copy[i])j++;
    }
    if(j==4){
        for(i=0,j=0;i<=y1;i++){
            if(sign[i]=='(')j=1;
        }if(j!=1){
            result=forluma(figure,sign,4);printf("=%g\n",result);//�ж�����������Ƿ����Ҫ��
            if(result==24)printf("��ϲ�㣬����ȷ��");
                else printf("���ź����𰸴��󡭡�");
            }
        else{
            for(i=0,j=0,k=0;i<strlen(sign);i++){
                    if(sign[i]=='('){
                        t1=i;t3=i;
                        while(sign[t1]!=')'){
                    figurebox[j]=figure[t1];
                    signbox[k]=sign[t1+1];
                    t1++;j++;k++;}
            if(sign[t1]==')')break;
           }
    }
    for(i=k-1;i<strlen(signbox);i++)signbox[i]='\0';
    figure[t3]=forluma(figurebox,signbox,j);
    for(i=t3+1;i<t1;i++)figure[i]=1e100;
    for(i=t3;i<=t1;i++)sign[i]='#';
    for(i=0,j=0;i<4;i++){
        if(figure[i]!=1e100){m[j]=figure[i];j++;}
    }for(i=j;i<4;i++)m[i]=1;
    for(i=0,k=0;i<=y1;i++){
        if(sign[i]!='#'){n[k]=sign[i];k++;}
    }for(i=0,t2=k;i<4-j;i++,t2++)n[t2]='+';n[t2-1]='\0';//ȥ����
        for(i=0,p=0;i<k;i++){if(n[i]=='(')p=1;}
        if(p==1){
            for(i=0;i<t2;i++)sign[i]=n[i];sign[t2-1]='\0';
            for(i=0;i<4;i++)figure[i]=m[i];
            for(i=0,j=0,k=0;i<strlen(sign);i++){
                    if(sign[i]=='('){
                        t1=i;t3=i;
                        while(sign[t1]!=')'){
                    figurebox[j]=figure[t1];
                    signbox[k]=sign[t1+1];
                    t1++;j++;k++;}
            if(sign[t1]==')')break;
           }
    }
    for(i=k-1;i<strlen(signbox);i++)signbox[i]='\0';
    figure[t3]=forluma(figurebox,signbox,j);
    for(i=t3+1;i<t1;i++)figure[i]=1e100;
    for(i=t3;i<=t1;i++)sign[i]='#';
    for(i=0,j=0;i<4;i++){
        if(figure[i]!=1e100){m[j]=figure[i];j++;}
    }for(i=j;i<4;i++)m[i]=1;
    for(i=0,k=0;i<=y1;i++){
        if(sign[i]!='#'){n[k]=sign[i];k++;}
    }for(i=0,t2=k;i<4-j;i++,t2++)n[t2]='+';n[t2-1]='\0';
    result=forluma(m,n,2);
        }
        else {result=forluma(m,n,j);}
        printf("=%g\n",result);
        if(result==24)printf("��ϲ�㣬����ȷ��");
        else printf("���ź����𰸴��󡭡�");}//�õ�ʽ�ӵĽ���������
        printf("\n������Ϸ�����롰1����������Ϸ�����롰0��\n");
        scanf("%d",&countin);
        if(countin==1){
                srand(time(0));
        for(i=0;i<4;i++){
            data[i]=1+rand()%13;
            printf("%3g",data[i]);
        }x=3;y=2;t2=0;
                goto TOP2;}
    }else {printf("\n�������\n");goto TOP2;}
    return 0;
}






double sort(double a[],double n)//����������
{
    double canshu;
    int sorti,sortj,sortm;

    for(sorti=0,sortm=n-1;sorti<n-1;sorti++,sortm--){
        for(sortj=0;sortj<sortm;sortj++){
            if(a[sortj]>=a[sortj+1]){
                canshu=a[sortj];
                a[sortj]=a[sortj+1];
                a[sortj+1]=canshu;
            }
        }
    }
    return 0;
}
double forluma(double figure[],char sign[],int q)//�������ŵ�ʽ�ӵļ���
{
    double answer;
    int i,j,cout=0;
    for(i=0;i<strlen(sign);i++){
        if(sign[i]=='/'){
            sign[i]='*';figure[i+1]=1/figure[i+1];//���ű�˺�
        }
    }
TOP1:for(i=0;i<strlen(sign);i++){
        if(sign[i]=='*'){
                answer=figure[i]*figure[i+1];
                figure[i]=answer;
                figure[i+1]=1e100;
                sign[i]='#';cout++;
                break;
        }
    }
    for(i=0,j=0;i<q;i++){
        if(figure[i]!=1e100){figure[j]=figure[i];j++;}
    }
    for(i=0,j=0;i<strlen(sign);i++){
        if(sign[i]!='#'){sign[j]=sign[i];j++;}
    }
    for(i=0;i<strlen(sign)-cout;i++){
        if(sign[i]=='*')goto TOP1;//����˷�
    }
    for(i=0;i<strlen(sign)-cout;i++){
        if(sign[i]=='-'){
            sign[i]='+';figure[i+1]=0-figure[i+1];//���ű�Ӻ�
        }
    }
    for(i=0,answer=0;i<q-cout;i++)answer+=figure[i];//����ӷ�
    return answer;
}

