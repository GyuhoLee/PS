#include <iostream>
using namespace std;

void star(int N, int i,int j)
{
  if( (i / N) % 3 == 1 && (j / N) % 3 == 1)
      printf(" ");
  else
  {
      if(N/3 == 0)
          printf("*");
      else
          star(N/3,i,j);
  }
}
int main()
{
  int N;
  scanf("%d", &N);

  for(int i=0;i<N;i++)
  {
      for(int j=0;j<N;j++)
          star(N,i,j);
      printf("\n");
  }
  return 0;
}