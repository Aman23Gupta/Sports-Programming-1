bool isSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}


int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
} //returns 1 for monday,2 for tuesday,0 for sunday... 

//INT_MAX and INT_MIN can be used to check for signed integer overflow, also sign change can be used to identify overflow
