/*-----------------------------------------------------------------------------------------------------*/

/*计算明文中每一个字母在加密表中的位置*/

int pos(char s, char t)
{
    if (t =='e') /*从明文字表获取位置*/
    {
       char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu Vv\nWw+Xx=Yy%Zz@";
       int i;
       for ( i = 0; i < 78; i++)
       {
          if (s==*(table+i))
          {
            break;
          }
       }
       return i; 
    }

    else if (t =='d') /*从密文字表获取位置*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
        int i;
        for ( i = 0; i < 78; i++)
        {
            if (s==*(table+i))
            {
                break;
            }
        }
        return i;
    }
}
/*-----------------------------------------------------------------------------------------------------*/

/*对明文实现n阶凯撒加密  （当m=0时采用无空格和换行字母表进行加密）*/

void E(int n, char *s, int m)
{
    if (m==1) /*明文的首次加密*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@"
        "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
        if (n<=77)
        {
            n=n;
        }
        else n=n%77;
       *s=*(table+pos(*s,'e')+n);
    }
    else if (m==0) /*初级密文的再加密*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@"
        "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
        if (n<=77)
        {
            n=n;
        }
        else n=n%77;
       *s=*(table+pos(*s,'d')+n);
    }
}
/*-----------------------------------------------------------------------------------------------------*/

/*对明文实现n阶凯撒还原*/

void D(int n, char *s, int m) 
{
    if (m==1) /*密文的非末次解密*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@"
        "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
        int i;
        if (n<=77)
        {
            n=n;
        }
        else n=n%77;
        *s=*(table+pos(*s,'d')+78-n);
    }
    else if (m==0) /*密文的末次解密*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu Vv\nWw+Xx=Yy%Zz@"
        "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu Vv\nWw+Xx=Yy%Zz@";
        int i;
        if (n<=77)
        {
            n=n;
        }
        else n=n%77;
        *s=*(table+pos(*s,'d')+78-n);
    }
}
/*-----------------------------------------------------------------------------------------------------*/

/*生成一定范围m,n间的随机数*/

int Rand(int m, int n)
{
    int x;
    srand(getpid()+rand()+time(NULL));
    x=m+rand()%(n-m+1);
    return x;
}
/*-----------------------------------------------------------------------------------------------------*/

/*加密反射函数*/

void R(char *s)
{
    char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@"
    "Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
    *s=*(table+pos(*s,'d')+39);
}
/*-----------------------------------------------------------------------------------------------------*/

/*定位反值函数*/

char S(int n, int m)
{
    if (m==1) /*返回明文字符*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu Vv\nWw+Xx=Yy%Zz@";
        char x;
        x=*(table+n);
        return x;
    }
    else if (m==0) /*返回密文字符*/
    {
        char *table="Aa0Bb1Cc2Dd3Ee4Ff5Gg6Hh7Ii8Jj9Kk?Ll!Mm.Nn:Oo\"Pp'Qq-Rr,Ss(Tt)Uu*Vv$Ww+Xx=Yy%Zz@";
        char x;
        x=*(table+n);
        return x;
    }
    
}

/*-----------------------------------------------------------------------------------------------------*/

/*数组自重复检测函数*/

int exm(int p[], int n)
{
    int i, j;
    for ( i = 1; i < n; i++)
    {
        for ( j = 0; j < i; j++)
        {
            if (p[i]==p[j])
            {
                break;
            }
            
        }
        if (j < i)
        {
            break;
        }
    }
    
    if (i==n && j==n-1)
    {
        return 1; /*数组无重号*/
    }
    else return 0;
}
/*-----------------------------------------------------------------------------------------------------*/

/*整数数组与字符串的转换函数*/

void I_s(int *arr, char *str, int size) 
{
    if (size <= 0) return;
 
    *str = *arr + '+';
    I_s(arr + 1, str + 1, size - 1);
    *(str + size) = '\0';
}                                       //将整数数组arr按ASCII码转换为字符，存入字符串str中

void S_i(char *str, int *arr) 
{
    int i;
    for (i = 0; i < strlen(str); i++) 
    {
        arr[i] = (int)str[i]-(int)'+';
    }
}                                       //将字符串str按ASCII码转换为整数值，存入整数数组arr中

/*-----------------------------------------------------------------------------------------------------*/

/*双数组异位重复检测函数*/

int Double_Exm(int *x, int *y, int n)
{
    int z[n], i;
    for ( i = 0; i < n; i++)
    {
        z[i]=x[i];
    }
    
    for ( i = 0; i < n; i++)
    {
        z[i]=y[i];
        if (exm(z, n)==0)
        {
            break;
        }
        else z[i]=x[i];
    }
    if (i == n)
    {
        return 1; /*无异位重复*/
    }
    else return 0;
}

/*-----------------------------------------------------------------------------------------------------*/