bool isSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}

-------------------------------------------------------------------------------------------

int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
} //returns 1 for monday,2 for tuesday,0 for sunday... 

--------------------------------------------------------------------------------------------

  //INT_MAX and INT_MIN can be used to check for signed integer overflow, also sign change can be used to identify overflow

--------------------------------------------------------------------------------------------

// ENCODING TWO NUMBERS INTO ONE:- https://en.wikipedia.org/wiki/Pairing_function
//let the number by x,y and they are encoded into z 
// condition x*y should not overflow
// x should be bigger of two

int encode(int x,int y){
  int z;
  z=((x+y)*(x+y+1))/2+y;
  return z;
}

void decode(int z,int x,int y){
  int w=floor(((sqrt(8*z+1))-1)/2);
  int t=(w*w+w)/2;
  y=z-t;
  x=w-y;
}

//another way
/*Now, we will do a slight trick to encode 2 numbers in one index.
This trick assumes that N * N does not overflow.

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.
Given a number as

   A = B + C * N   if ( B, C < N )
   A % N = B
   A / N = C
We use this fact to encode 2 numbers into each element of Arr.*/

---------------------------------------------------------------------------------------------

  
