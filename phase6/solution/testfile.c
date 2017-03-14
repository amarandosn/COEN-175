int main(void)
{
  int num;
  int neg;
  int num2;
  int not;
  int a, b, c, d, e;
  int lt, gt;
  int leq, geq, eq, neq;
  int ZERO;
  ZERO = 48;
  a = 2 + 3;
  putchar(a + ZERO);
  b = 5 - 2;
  putchar(b + ZERO);
  c = 9/3;
  putchar(c + ZERO);
  d = 8%3;
  putchar(d + ZERO);
  e = 2*3;
  putchar(e + ZERO);
  lt = d < e;
  putchar(!lt + ZERO);
  gt = a > b;
  putchar(!gt + ZERO);
  leq = d <= e;
  putchar(!leq + ZERO);
  geq = a >= b;
  putchar(!geq + ZERO);
  eq = b == c;
  putchar(!eq + ZERO);
  neq = b != a;
  putchar(!neq + ZERO);
  
  num = 1;
  neg = -num;
  num2 = -neg;
  not = !num;
} 
