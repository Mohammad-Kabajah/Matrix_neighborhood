#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void init();
int search(int i , int j , int x[]);
int check(int ia , int ja , int x);
int neighbor(int x, int y);
void print();
int newRow(int i , int j);
int newColumn (int i , int j);
int sol();
void  newx(int i , int j,int x[]);
int in(int i, int a[]);
void rearrange (int x[]);

int array[3][4];
