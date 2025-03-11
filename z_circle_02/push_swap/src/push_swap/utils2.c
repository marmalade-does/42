#include "../../includes/push_swap.h"

/**
 * @brief Extracts the values from the stack into an array.
 * 
 * @param stack The head of the stack.
 * @param values The array to store the values.
 */
static void extract_values(t_digit **stack, int *values)
{
    t_digit *current;
    int i;

    current = *stack;
    i = 0;
    while (i < 4)
    {
        values[i] = current->num;
        current = current->next;
        i++;
    }
}

/**
 * @brief Determines the order of the values.
 * 
 * @param values The array of values.
 * @param order The array to store the order.
 */
static void determine_order(int *values, int *order)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        order[i] = 1;
        j = 0;
        while (j < 4)
        {
            if (values[i] < values[j])
                order[i]++;
            j++;
        }
        i++;
    }
}

/**
 * @brief Converts the order array to a string.
 * 
 * @param order The array of order.
 * @param result The string to store the result.
 */
static void order_to_string(int *order, char *result)
{
    int i;

    i = 0;
    while (i < 4)
    {
        result[i] = order[i] + '0';
        i++;
    }
    result[4] = '\0';
}

/**
 * @brief Reads the permutation of four numbers in the stack and returns a string representing their order.
 * 
 * @param stack The head of the stack.
 * @return char* A 4-character string representing the order of the numbers.
 */
char	*ft_read_perm(t_digit **stack)
{
    int values[4];
    int order[4];
    char *result;

    result = (char *)malloc(5 * sizeof(char));
    if (!result)
        return (NULL);

    extract_values(stack, values);
    determine_order(values, order);
    order_to_string(order, result);

    return (result);
}