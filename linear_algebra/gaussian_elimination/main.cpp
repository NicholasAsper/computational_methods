#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const int N = 5;




void print_Matrix(double ** matrix)
{
  cout << "\n";
  for (int i=0; i<N; i++)
    {
      for (int j=0; j<N;j++)
	{
	  cout << matrix[i][j] << " " ;
	}
      cout << endl;
    }
}


double** getRandom_Array()
{
  double** arr = new double*[N];
  for (int i=0; i<N; i++)
    {
      arr[i] = new double[N];
      for (int j=0; j<N;j++)
	{
	  arr[i][j] = fmod(rand(),10)-5.0;
	  cout << arr[i][j] << " " ;
	}
      cout << endl;
    }
  return arr;
}

double** add_Row(double ** matrix, int row1, int row2, double scalar)
{

  for(int j=0; j<N;j++)
    {
      matrix[row2][j] = matrix[row1][j]*scalar +  matrix[row2][j];
    }
  
  return matrix;
}

double** getGauss_Elim(double** matrix)
{
  double scalar;
  for(int j=0; j<N; j++)
    {
      for(int i=0; i<N; i++)
	{
	  if (matrix[i][j] ==0)
	    {
	      continue;
	    }
	  else if (i != j)
	    {
	      scalar = matrix[i][j]/matrix[j][j]*-1;

	      matrix = add_Row(matrix,j,i,scalar);
	    }
	  else
	    {
	      continue;
	    }

	}
      
    }
  
  
  return matrix;

}
int main()
{
  double** arr;
  arr = getRandom_Array();
  arr = getGauss_Elim(arr);
  print_Matrix(arr);
  return 0;
}

