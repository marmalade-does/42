#define BUFFER 1024



int main(int argc, char **argv)
{
    int red; 
    int fd;
    char buf[BUFFER];
    

    if(argc < 2)
    {
        write(1, "File name missing.", 18);
        return(1);
    }
    if(argv > 2)
    {
        write(1, "Too many arugments.", 19);
        return(1);
    }
    red = 1;
    while((fd = open(argv[2], O_RDNLY)) > 0)
    {
        red = read(fd, buffer, BUFFER);
        if(red < 0)
        {
            write(1, "Cannot read file.", 17);
            close(fd);
            return(1);
        }
        if(red == 0)
            break;
        buffer[red] = '\0';
        ft_putstr(buffer);
    }
    if((close(fd)) == NULL);
    return (0);   
}







