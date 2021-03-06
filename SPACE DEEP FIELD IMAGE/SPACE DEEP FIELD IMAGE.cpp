﻿#include<stdio.h> 

#define MAX_SIZE (1000) 

char x_c[MAX_SIZE][MAX_SIZE];
int x[MAX_SIZE][MAX_SIZE];
int M_values, N_values, i, j;
int planet = 0, fixed_star = 0, comet = 0;

int calculate();
int process();
int Check_Step1(int, int);
int Check_Step2_1(int, int);
int Check_Step2_2(int, int);
int Check_Step3(int, int);
int Check_Step4(int, int);
int Reset(int, int);

int main()
{
    if (scanf_s("%d", &N_values) != 1) {
        printf("ERROR\n");
        return 1;
    }
    else if (N_values < 3 || N_values > 1000) {
        printf("ERROR \n10 <= N <= 1000\n");
        return 1;
    }

    if (scanf_s("%d", &M_values) != 1) {
        printf("ERROR\n");
        return 1;
    }
    else if (M_values < 3 || M_values > 1000) {
        printf("ERROR \n10 <= M <= 1000\n");
        return 1;
    }

    for (i = 1; i <= M_values; i++) 
    {
        for (j = 1; j <= N_values; j++) {
            scanf_s("%c", &x_c[i][j]);
            x[i][j] = x_c[i][j];
            if (x[i][j] == 10)
            {
                j--;
            }
            else
            {
                x[i][j] -= 48;
            }
        }
    }

    calculate();
    process();

    return 0;
}

int process()
{
    printf("\n%d %d %d", planet, fixed_star, comet);
    return 0;
}

int calculate()
{
    for (i = 1; i <= M_values; i++)
    {
        for (j = 1; j <= N_values; j++) {
            if (x[i][j] == 1)
            {
                Check_Step1(i, j);
            }
        }
    }
    return 0;
}

int Check_Step1(int k, int l)
{
    if (x[k][l +1 ] == 1)
    {
        Check_Step2_1(k, l);
    }
    else
    {
        Check_Step2_2(k, l);
    }
    return 0;
}

int Check_Step2_1(int m, int n)
{
    if (x[m + 1][n] == 1)
    {
        planet += 1;
        for (int o = m; o <= M_values; o++)
        {
            for (int p = n; p <= N_values; p++)
            {
                if (x[o][p] == 1)
                {
                    Reset(o, p);
                }
                else
                {
                    if (x[o + 1][n] == 0)
                    {
                        o = 2000;
                    }
                    p = 2000;
                }
            }
        }
    }
    else
    {
        comet += 1;
        int q = 0;
        for (int o = m; o <= M_values; o++)
        {
            for (int p = n + q; p <= N_values; p++)
            {
                if (x[o][p] == 1)
                {
                    Reset(o, p);
                }
                else
                {
                    if (x[m + q + 1][n + q + 1] == 0)
                    {
                        o = 2000;
                    }
                    p = 2000;
                }
            }
            q++;
        }
    }
    return 0;
}

int Check_Step2_2(int m, int n)
{
    if (x[m + 1][n - 1] == 1)
    {
        Check_Step3(m, n);
    }
    else
    {
        comet += 1;
        int q = 0;
        for (int p = n; p <= N_values; p++)
        {
            for (int o = m + q; o <= M_values; o++)
            {
                if (x[o][p] == 1)
                {
                    Reset(o, p);
                }
                else
                {
                    if (x[m + q + 1][n + q + 1] == 0)
                    {
                        p = 2000;
                    }
                    o = 2000;
                }
            }
            q++;
        }
    }
    return 0;
}

int Check_Step3(int m, int n)
{
    if (x[m + 1][n + 1] == 1)
    {
        Check_Step4(m, n);
    }
    else
    {
        comet += 1;
        int q = 0;
        for (int p = n; p > 0; p--)
        {
            for (int o = m + q; o <= M_values; o++)
            {
                if (x[o][p] == 1)
                {
                    Reset(o, p);
                }
                else
                {
                    if (x[m + q + 1][n - q -1] == 0)
                    {
                        p = 0;
                    }
                    o = 2000;
                }
            }
            q++;
        }
    }
    return 0;
}

int Check_Step4(int m, int n)
{
    for (int r = m; r <= M_values + 1 ; r++)
    {
        if (x[r][n] != 1)
        {
            if (x[r - 1][n + 1] == 0)
            {
                fixed_star += 1;
                int q = 0;
                for (int o = m; o <= M_values; o++)
                {
                    for (int p = n + q; p > 0; p--)
                    {
                        if (x[o][p] == 1)
                        {
                            Reset(o, p);
                        }
                        else
                        {
                            if (x[m + q + 1][n - q - 1] == 0)
                            {
                                comet -= 1;
                                o = 2000;
                                r = 2000;
                            }
                            p = 0;
                        }
                    }
                    q++;
                }
            } 
            else
            {
                comet += 1;
                int q = 0;
                for (int o = m; o <= M_values; o++)
                {
                    for (int p = n + q; p > 0; p--)
                    {
                        if (x[o][p] == 1)
                        {
                            Reset(o, p);
                        }
                        else
                        {
                            if (x[m + q + 1][n - q - 1] == 0)
                            {
                                o = 2000;
                                r = 2000;
                            }
                            p = 0;
                        }
                    }
                    q++;
                }
            }
        }
    }
    return 0;
}

int Reset(int ti, int tj)
{
    x[ti][tj] = 0;
    return x[ti][tj];
}