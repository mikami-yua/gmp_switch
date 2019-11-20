#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include "stdio.h"
using namespace std;

typedef unsigned __int64 uint64 ;
void get_gmparray(int arraylength,mpz_t *a)
{
    cout << "GMP PRETREATMENT BEGIN!" << endl;
    for(int i=0;i<arraylength;i++){
        cout<<"aaa["<<i<<"]= ";
        mpz_init2(a[i],256);
        mpz_random(a[i],4);
        gmp_printf ("%Zd\n", a[i]);
    }
    cout<<"review start!"<<endl;
    for(int i=0;i<arraylength;i++){
        for(int j=i+1;j<arraylength;j++)
            if(a[i]==a[j])
                cout<<"aaa["<<i<<"]=aaa["<<j<<"]"<<endl;
    }
    cout<<"review over!"<<endl;
    //return *a;
}
void display_mpzarray(int length,mpz_t *temp){
    for(int i=0;i<length;i++){
        cout<<"temp["<<i<<"]= ";
        gmp_printf ("%Zd\n", temp[i]);
    }
}

void get_64bit(mpz_t *temp,mp_limb_t *temp1,int length,mpz_t divd){
    gmp_printf ("divde number is %Zd\n", divd);
    for(int i=0;i<length;i++){
        //�õ�һ��limb��
        const mp_limb_t *pre;
        pre=mpz_limbs_read(temp[i]);
        const mp_limb_t *modd=mpz_limbs_read(divd);
        mp_limb_t modd1=*modd;
        temp1[i]=mpn_mod_1(pre,4,modd1);
        gmp_printf("b1 array is  %Md\n",temp1[i]);
    }
//��������ֻ��һ��������������Ҫ�ĸ�������ÿ������ʹ��һ���������ҳ�����Ҫ����
    //������ȷ��
    for(int i=0;i<length;i++){
        mpz_t ddd;
        mpz_init2(ddd,64);
        mpz_mod(ddd, temp[i], divd);
        gmp_printf("test mod is %Zd\n",ddd);
    }
    //������ȷ

}

int main()
{
    int x=10;
    mpz_t a[x];
    get_gmparray(x,a);
    //display_mpzarray(x,a);

    //��������Ҫ��ÿ������256������Ų��Ϊ4����ÿ������Ϊ64������
    //��ʼ���ĸ�����
    mpz_t divd[8];
    for(int i=0;i<8;i++){
        mpz_init2(divd[i],64);
        mpz_random(divd[i],1);
        gmp_printf ("divde number is %Zd\n", divd[i]);
    }

    mp_limb_t a1[x],a2[x],a3[x],a4[x];
    get_64bit(a,a1,x,divd[7]);
    get_64bit(a,a2,x,divd[1]);
    get_64bit(a,a3,x,divd[2]);
    get_64bit(a,a4,x,divd[0]);
//ʹ���й�ʣ�ඨ����֤�Ƿ��ܺ�һ��
//ʣ�ඨ��Ҫ��ģ�����ʣ�������ͨ����չŷ����ò�����
//���ַ��� 1.�������ܲ���ѧ��      2.�ҵ����ʵ�divd��Ϊ����
    mpz_t b[x];



}

