int main(void)
{
    int x, y, z, *p;

    if (main) x = y;		/* invalid type for test expression */
    if (x) 0;
    if (x) 0; else 1;

    while (main)		/* invalid type for test expression */
	x = 0;

    for (x = 1; main; x = y) 0;	/* invalid type for test expression */

    return x;
    return main;		/* invalid return type */
    return p;			/* invalid return type */
}
