//distance between line and point
double dist(double a,double b,double c,double x,double y){
	return abs((a*x+b*y+c)/sqrt(a*a+b*b));
}

//given points find slope
double slope(double x1,double x2,double y1,double y2){
  return (y2-y1)/(x2-x1);
}

//find a,b,c of ax+by+c given slope of line and point it passes through
void calc(double m,double x,double y,double &a,double &b,double &c){
	b=-1;
	a=m;
	c=y-m*x;
}
