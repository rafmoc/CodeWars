//https://www.codewars.com/kata/5765870e190b1472ec0022a2

#include <iostream>
#include <string>

using namespace std;

bool path_finder(string maze) {
  
  int i, j, k, n;
  for(i=0; i<20; i++)
  {
    if(maze[i]=='\n')
    {
      n=i;
      i=20;
    }
  }
  int end = 0;
  int tab[n][n];
  
  k=0;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      if(maze[k]=='.'){tab[j][i]=1;}
      else{tab[j][i]=2;}
      k++;
    }
    k++;
  }
  
  int x=0, y=0;
  
  cout<<maze<<endl<<endl;
  
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      cout<<tab[j][i];
    }
    cout<<endl;
  }
  cout<<endl;
  
  if((tab[1][0]==2)&&(tab[0][1]==2)){return false;}
  
  tab[x][y]=3;
  int check;
  while(end==0)
  {
    check = 0;
    for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        if((tab[j][i]==3)&&(tab[j+1][i]==1)&&(j+1<n)&&(j+1>=0)){tab[j+1][i]=3;check=1;}
        if((tab[j][i]==3)&&(tab[j][i+1]==1)&&(i+1<n)&&(i+1>=0)){tab[j][i+1]=3;check=1;}
        if((tab[j][i]==3)&&(tab[j-1][i]==1)&&(j-1<n)&&(j-1>=0)){tab[j-1][i]=3;check=1;}
        if((tab[j][i]==3)&&(tab[j][i-1]==1)&&(i-1<n)&&(i-1>=0)){tab[j][i-1]=3;check=1;}
      }
    }
    if(check==0){end=1;}
  }
  
  //cout<<endl<<endl<<n<<endl;
  
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      cout<<tab[j][i];
    }
    cout<<endl;
  }
  cout<<endl;
  
  if(tab[n-1][n-1]==3){return true;}
  else{return false;}
}
