// rec_ft_memset
void *memset(void *s, int c, size_t n);
{
    char *p;
    
    p = (char *)s;
    while (n > 0)
    {
        p[n-1] = (char)c;
        n--;
    }
    return (s);
}




