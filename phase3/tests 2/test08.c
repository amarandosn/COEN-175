void y, bar(void);		/* 'y' has type void */

void foo(int a, int *b)
{
    b[a] = 1;
    x[a] = 1;			/* 'x' undeclared */
}

void bar(void)
{
}
