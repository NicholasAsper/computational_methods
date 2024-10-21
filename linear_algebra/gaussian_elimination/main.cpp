#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const int N = 5;


double x_vector [N] = {1.0,1.0,1.0,1.0,1.0};


void print_Matrix(double ** matrix)
{
  cout << "\n";
  for (int i=0; i<N; i++)
    {
      for (int j=0; j<N+1;j++)
	{
	  if (j==N)
	    {
	      cout << x_vector[i] << " " ;
	    }
	  else
	    {
	     cout << matrix[i][j] << " " ;
	    }
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
	}
    }
  return arr;
}

double** add_Row(double ** matrix, int row1, int row2, double scalar)
{
  if (row2 >= N)
    {
      scalar = matrix[row1][row1];
      for(int j=0; j<N;j++)
	{
	  if (j==0) x_vector[row1] = x_vector[row1]/scalar;
	  matrix[row1][j] = matrix[row1][j]/scalar;
	}
    }
  else
    {
      for(int j=0; j<N;j++)
	{
	  
	  if (j==0) x_vector[row2] = x_vector[row1]*scalar + x_vector[row2]; 
	  matrix[row2][j] = matrix[row1][j]*scalar +  matrix[row2][j];
	}
    }
  return matrix;
}

double** getGauss_Elim(double** matrix)
{
  double scalar;
  print_Matrix(matrix);
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

	      print_Matrix(matrix);
	    }
	  else
	    {
	      matrix = add_Row(matrix,j,N,1.0);

	      print_Matrix(matrix);
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

