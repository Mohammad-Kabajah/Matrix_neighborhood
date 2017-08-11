#include "header.h"

int main()
{
  init();
  int x[8] = {0};
  int i;
  for(i = 0 ; i < 8 ; i ++)
    {
      x[0]=i+1;
      search(0,1,x);
    }
  return 0;
}

/**
   initialize the matrix fill it with zeros where we will work and -10 in the other locations
**/
void init()
{
  int i=0,j=0;
  for(i = 0 ; i < 3 ; i ++)
    for(j = 0 ; j < 4 ; j++)
      array[i][j]=0;
  array[0][0]=-10;
  array[2][0]=-10;
  array[0][3]=-10;
  array[2][3]=-10;
}

/**
   start with initial state and keep searching to find a solution to that state or return without a solution
**/
int search(int i , int j , int x[] )
{
  array[i][j]=x[0];
  if(sol()==1)
    {
      printf("solution !!! \n");
      print();
      return 1;
    }
  int inew = newRow(i,j);
  int jnew = newColumn(i,j);
  i = inew;
  j = jnew;
  int a[8] ={0,0,0,0,0,0,0,0};
  newx(i,j,a);
  while(a[0]!=0)
    {
      if(search(i,j,a)==1)
	break;
      a[0]=0;
      rearrange(a);
    }
  array[i][j]=0;
  return -1;
}

/**
   rearrange takes an array as a parameter and arrange the elements so that zero elements put last
**/
void rearrange (int x[])
{
  int z[8]= {0,0,0,0,0,0,0,0};
  int i,index=0;
  for(i=0; i<8; i++)
    {
      if(x[i]!=0)
	z[index++]=x[i];
    }
  for(i=0; i<8; i++)
    x[i]=z[i];
}


/**
   check function is used to check if it is possible to the element to be inserted in the matrix in the specific row and column by checking the surrounding elements
   return -1 if the number can fit in the specific location
   return 1 if the number cant fit in the specific location
**/
int check(int ia , int ja , int x)
{
  int z = x;
  int flag=-1;
  if(ja+1 < 4)
    {
      if(ia+1 < 3)
        {
	  if(neighbor(array[ia+1][ja+1],z)==1)
            {
	      flag = 1;
	      return flag;
            }
        }
      if(ia-1 > -1)
        {
	  if(neighbor(array[ia-1][ja+1],z)==1)
            {
	      flag = 1;
	      return flag;
            }
        }
      if(neighbor(array[ia][ja+1],z)==1)
	{
	  flag = 1;
	  return flag;
	}
    }
  if(ja-1 > -1)
    {
      if(ia+1 < 3)
        {
	  if(neighbor(array[ia+1][ja-1],z)==1)
            {
	      flag = 1;
	      return flag;
            }
        }
      if(ia-1 > -1)
	{
	  if(neighbor(array[ia-1][ja-1],z)==1)
	    {
	      flag = 1;
	      return flag;
	    }
        }
      if(neighbor(array[ia][ja-1],z)==1)
	{
	  flag = 1;
	  return flag;
	}
    }
  if(ia+1 < 3)
    {
      if(neighbor(array[ia+1][ja],z)==1)
        {
	  flag = 1;
	  return flag;
        }
    }
  if(ia-1 > -1)
    {
      if(neighbor(array[ia-1][ja],z)==1)
	{
	  flag = 1;
	  return flag;
        }
    }
  return flag;
}

/**
   neighbor is function used to check if the two integers is successive numbers or not
   return -1 if not successive numbers
   return 1 if successive numbers or both numbers are equal
**/
int neighbor(int x, int y)
{
  int flag = -1;
  if(x==-10 || y==-10 || x==0 || y==0)
    return flag;
  if(x==y)
    {
      flag=1;
    }
  if(abs(x-y)==1)
    {
      flag = 1;
      return flag;
    }
  return flag;
}

/**
   print the matrix
**/
void print()
{
  int i , j ;
  for(i = 0 ; i < 3 ; i ++)
    {
      for(j = 0 ; j < 4 ; j++)
        {
	  if(array[i][j]!=-10)
	    printf("%d\t",array[i][j]);
	  else
	    printf("\t");
        }
      printf("\n");
    }
  printf("\n");
}

/**
   generate the new row number to go to when moving to the next state
**/
int newRow(int i , int j)
{
  if(i == 0)
    {
      if(j == 2)
	return i+1;
      else
	return i;
    }
  else if(i == 1)
    {
      if(j==3)
	return i+1;
      else
	return i;
    }
  else if(i == 2 )
    {
      if (j == 2)
	return -1;
      else
	return i;
    }
  return -1;
}

/**
   generate the new column number to go to when moving to the next state
**/
int newColumn (int i , int j)
{
  if(i == 0)
    {
      if(j == 2)
	return 0;
      else
	return j+1;
    }
  else if(i == 1)
    {
      if(j==3)
	return 1;
      else
	return j+1;
    }
  else if(i == 2 )
    {
      if (j == 2)
	return -1;
      else
	return j+1;
    }
  return -1;
}

/**
   check if the current state in the matrix is solution
   return -1 if not solution
   return 1 if the state is solution
**/
int sol()
{
  int sol = 1,j,i;
  for(i = 0 ; i < 3 ; i++)
    {
      for(j = 0 ; j < 4 ; j ++)
        {
	  if(check(i,j,array[i][j])==1 || array[i][j]==0 )
            {
	      sol = -1;
	      return sol;
            }
        }
    }
  return sol;
}

/**
   generate all the possible numbers that can be in the specific location of the matrix
**/
void newx(int i,int j ,int x[])
{
  int a[8]= {0,0,0,0,0,0,0,0};
  if(array[i][j]==-10)
    return ;
  int ia,ja,index=0;
  for(ia = 0 ; ia < 3 ; ia ++)
    {
      for(ja = 0 ; ja < 4 ; ja ++)
        {
	  if(array[ia][ja]==-10)
	    continue;
	  else
	    a[index++]=array[ia][ja];
        }
    }
  index=0;
  for(ia = 0 ; ia < 8 ; ia ++)
    {
      if(in(ia+1,a)!=1)
        {
	  x[index++]=ia+1;
        }
    }
  for(ia=0; ia<8; ia++)
    {
      if(check(i,j,x[ia])==1)
	x[ia]=0;
    }
  rearrange(x);
}

/**
   check if the an integer exists in an array
**/
int in(int i, int a[])
{
  int j = 0;
  for(j =0 ; j < 8 ; j++)
    {
      if(a[j]==i)
	return 1;
    }
  return -10;
}
