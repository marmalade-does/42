

// function that finds first instance of a char ina string nad returns pointer 

char	*ft_strchr(const char *s, int i)
{
    while(*s)
    {
        if (*s == i)
            return ((char *)s);
        s++;
    }
    if (i == '\0')
        return ((char *)s)
    return(0);
}