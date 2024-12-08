// move n bytes from src to dest.

rec_ft_memmove(void *dest, static void* src, size_t n)
{
    while (n > 0) // I don't remember there
    {
        n--;
        ((unsigned char *)dest)[n] = ((unsigned char *)src[n]);
    }
    return (dest);
}
// Can optimise this with a if..else block. 
// If the src is before the dest. then copy bcak to front (to avoid overwritting issues) 
// If the src is behind the destination, then copy front-to-back
// Front to back memory calling is more efficient (because of how GPU is designed)
// if you have to use this ft_librairy later good idea to optimise
