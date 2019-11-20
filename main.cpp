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
        //得到一个limb数
        const mp_limb_t *pre;
        pre=mpz_limbs_read(temp[i]);
        const mp_limb_t *modd=mpz_limbs_read(divd);
        mp_limb_t modd1=*modd;
        temp1[i]=mpn_mod_1(pre,4,modd1);
        gmp_printf("b1 array is  %Md\n",temp1[i]);
    }
//存在问题只有一个除数不够，需要四个除数，每个数组使用一个除数，且除数需要保存
    //检验正确性
    for(int i=0;i<length;i++){
        mpz_t ddd;
        mpz_init2(ddd,64);
        mpz_mod(ddd, temp[i], divd);
        gmp_printf("test mod is %Zd\n",ddd);
    }
    //方案正确

}

int main()
{
    int x=10;
    mpz_t a[x];
    get_gmparray(x,a);
    //display_mpzarray(x,a);

    //接下来需要把每个分量256的数组才拆分为4个，每个分量为64的数组
    //初始化四个除数
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
//使用中国剩余定理验证是否能和一起
//剩余定理要求模数互质，但可以通过拓展欧几里得不互质
//两种方案 1.不互质能不能学会      2.找到互质的divd改为互质
    mpz_t b[x];



}

