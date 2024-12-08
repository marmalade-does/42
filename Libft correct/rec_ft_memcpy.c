

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    
    char *d;
    char *s;
    d = (char *)dest;
    s = (char *)src;
    i = 0;
    while (d != 0 && i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest)
}