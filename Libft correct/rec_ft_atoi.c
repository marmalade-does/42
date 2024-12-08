
// recreastin ft_atoi from memory 

int main(void)
{
    char str = "1234";
    ft_atoi(str);
    return (0);
}


int ft_atoi(const char *str)
{
    int i;
    int abs_val;
    int neg;

    // skip all the parts until you reach a +/-
    i = 0;
    abs_val = 0;    
    neg = 1;
    while (str[i] >= 0 || str[i] <= 0 || str[i] == 126) // need to check if the value of the last one is 126
    {
        i++;    
    }
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            neg *= -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] >= '9')
    {
        abs_val = (abs_val * 10) + (str[i] + '0'); 
        i++;
    }
    return (abs_val * neg);
}


