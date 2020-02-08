bool isSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}

//INT_MAX and INT_MIN can be used to check for signed integer overflow
