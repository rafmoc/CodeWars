//https://www.codewars.com/kata/5b2c2c95b6989da552000120

using namespace std;

int tv_remote(const string &word)
{
    int i, j, k=0, sum=0, isup = 0;
    int length = word.length();
    
    int x=0, y=0; //x and y are location we are at.
    
    char tab[6][8]={
        {'a', 'b', 'c', 'd', 'e', '1', '2', '3'},
        {'f', 'g', 'h', 'i', 'j', '4', '5', '6'},
        {'k', 'l', 'm', 'n', 'o', '7', '8', '9'},
        {'p', 'q', 'r', 's', 't', '.', '@', '0'},
        {'u', 'v', 'w', 'x', 'y', 'z', '_', '/'},
        {'+', ' ', '-', '-', '-', '-', '-', '-'}
    };
    
    cout<<word<<endl;
    
    for(k=0; k<length; k++)
    {
      if((isupper(word[k])==256)&&(isup==0)&&(word[k]!='/')&&(word[k]!='.')&&(word[k]!='_')&&(word[k]!=' ')&&(word[k]!='@')&&(isdigit(word[k])==0))
      {
        if(abs(y-5)>(6-abs(y-5))){y=5+abs(6-abs(y-5));}
        if(abs(x-0)>(8-abs(x-0))){x=0+abs(8-abs(x-0));}
        sum=sum + abs(y-5) + abs(x-0) + 1;
        y=5; x=0; isup=1;
      }
      if((isupper(word[k])==0)&&(isup==1)&&(word[k]!='/')&&(word[k]!='.')&&(word[k]!='_')&&(word[k]!=' ')&&(word[k]!='@')&&(isdigit(word[k])==0))
      {
        if(abs(y-5)>(6-abs(y-5))){y=5+abs(6-abs(y-5));}
        if(abs(x-0)>(8-abs(x-0))){x=0+abs(8-abs(x-0));}
        sum=sum + abs(y-5) + abs(x-0) + 1;
        y=5; x=0; isup=0;
      }
      
      for(i=0; i<5; i++)
      {
        for(j=0; j<8; j++)
        {
          if(word[k]==' ')
          {
            if(abs(y-5)>(6-abs(y-5))){y=5+abs(6-abs(y-5));}
            if(abs(x-1)>(8-abs(x-1))){x=1+abs(8-abs(x-1));}
            sum=sum + abs(y-5) + abs(x-1) + 1;
            y=5; x=1;
            i=6; j=8;
          }
          else if(tab[i][j]==word[k])
          {
            if(abs(y-i)>(6-abs(y-i))){y=i+abs(6-abs(y-i));}
            if(abs(x-j)>(8-abs(x-j))){x=j+abs(8-abs(x-j));}
            sum=sum + abs(y-i) + abs(x-j) + 1;
            y=i; x=j;
            i=6; j=8;
          }
          else if(toupper(tab[i][j])==toupper(word[k]))
          {
            if(abs(y-i)>(6-abs(y-i))){y=i+abs(6-abs(y-i));}
            if(abs(x-j)>(8-abs(x-j))){x=j+abs(8-abs(x-j));}
            sum=sum + abs(y-i) + abs(x-j) + 1;
            y=i; x=j;
            i=6; j=8;
          }
        }
      }
      cout<<word[k]<<" "<<isdigit(word[k])<<" "<<isupper(word[k])<<" "<<toupper(word[k])<<" "<<y<<" "<<x<<" "<<sum<<endl;
    }
    
    return sum;
}
