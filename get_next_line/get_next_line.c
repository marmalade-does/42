/* 

Things that need to improve this code: 
* I don't think -- (need to test) that this code works for when tehre are >1 '\n' in a biven BUFFER_LEN read
* Need to do the extra things that are mentioned in the pdf 
* ---> read the pdf :)
*/


#ifndef BUFFER_LEN // make sure this is ok defined in your header file
#define BUFFER_LEN 1024 
#endif

/*
 ** @brief      Takes data until \n from file and appends it to end of buffer -- Returns until a \n from the front (eg a a line of text) 
 **
 ** @param fd   The file descriptor that you want to read line-to-line from
 ** @return     A dynamically allocated string with a '\0' behind the '\n' (allow for eg printf() usage)
 ** @remarks    You need to free the return in the caller function 
*/

char	*get_next_line(int fd)
{
    static char *backup;
    char        *line;
    char        *temp;
    // char *temp;
    // here the malloc some size into buffer, and then pass the buffer that is stupid
    
    if(fd < 0 || BUFFER_LEN <= 0)
        return (NULL);
    backup = append_backup(backup, fd);
    if (backup == NULL)
        return (NULL);
    line = cut_line(backup); // extracts the line and updates backup with line removed.
    if (line == NULL)
        return (NULL);
    temp = backup; // check if this swap is necesaiy/needed
    backup = line;
    line = temp;
    temp = NULL;
    return (line);
}

/*
 ** @brief      Appends data, on the end of backup until '\n', from fd.
 **
 ** @param fd           File descriptor
 ** @param char *backup The static buffer that contains the data from fd.  
 ** @return             Backup with the appended data
 ** @remarks            The memory is dynamically allocated useing ft_strjoin, caller function needs to free() afterwards
*/

static char *append_backup(char *backup , int fd) // they also pass buffer here; they is stupid
{
    char buffer[BUFFER_LEN + 1]; // they dynamically allocate this? why?
    char *temp; // needed fro the movment from one to another
    int red;
    
    red = 1;
    while(red > 0)
    {
        red = read(fd, buffer, BUFFER_LEN);
        if (red == 0) //
            break;
        if (red == -1)
            return (NULL);   // all these conditionals are really gross, fix it
        if (backup == NULL)
            backup = ft_strdup("");
        if (backup == NULL)
            return (NULL);
        
        buffer[red] = '\0';
        temp = strjoin(buffer, backup);
        free(backup);
        if(temp == NULL)
            return (NULL);
        backup = temp;
        if(ft_strchr(buffer, '\n'))
            break;    
    }
    return(backup); 
}

/*
 ** @brief              Appends data, on the end of backup until '\n', from fd.
 **
 ** @param char *backup The buffer with the data from file.   
 ** @return             Backup without the first line.
 ** @remarks            It cuts new line of backup, by placin '\0' + from '\n' 
 */

char *cut_line(char *backup)
{
    char *new_backup;
    int i;

    i = 0;
    while(backup[i] != '\0' && backup[i] != '\n')
        i++;
    if (backup[i] == '\0')
        return (NULL); // becuase your at the end of the code
    new_backup = ft_substr(backup, (unsigned int)i, (strlen(backup) - i));
    if(new_backup == NULL)
        return(NULL);
    backup[i + 1] = '\0';   // This cuts back up right after the \n 
                            // You avoid the '\0' error becuase things that end in '\0' are taken out earlier 
    return(new_backup);
}
