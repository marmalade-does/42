// recreaste memset again 

void *memset(void *s, int c, size_t n);
{
    char *b;

    b = (char* )s;
    while (n > 0)
    {
        b[n - 1] = (char)c
        n--;
    }
    return (s);
}

