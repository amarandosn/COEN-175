int main(void)
{
    int x, *p;

    x = foo();
    x = bar(1, 2, 3);
    p = malloc(4);		/* invalid operands to binary = */
}
