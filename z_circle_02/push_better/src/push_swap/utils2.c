#include "../../includes/push_swap.h"

static int rank_values(int *values, int *sorted, char *ranked);
static void sort_values(int *values, int *sorted);
static void extract_values(t_digit **stack, int *values);
static void	swap_ints(int *a, int *b);

/**
 * @brief Reads the permutation of four numbers in the stack and returns a string representing their order.
 * 
 * @param stack The head of the stack.
 * @return char* A 4-character string representing the order of the numbers.
 */
char	*ft_read_perm(t_digit **stack)
{
    int values[4];
    int sorted[4];
    char *ranked;

    ranked = (char *)malloc(5 * sizeof(char));
    if (!ranked)
        return (NULL);

    extract_values(stack, values);
    sort_values(values, sorted);
    if (!rank_values(values, sorted, ranked))
    {
        free(ranked);
        return (NULL);
    }
    return (ranked);
}

/**
 * @brief Assigns ranks to the values based on their positions in the sorted array.
 * 
 * @param values The original array of values.
 * @param sorted The sorted array of values.
 * @param ranked The output string representing the ranks.
 * @return int 1 if successful, 0 if an error occurs.
 */
static int rank_values(int *values, int *sorted, char *ranked)
{
    int i;
    int j;

    j = 0;
    while (j < 4) // Iterate through the "values" array
    {
        i = 0;
        while (i < 4 && sorted[i] != values[j]) // Find the position of values[j] in "sorted"
            i++;
        if (i == 4) // If the value is not found in the sorted array, return 0
            return (0);
        ranked[j] = i + '1'; // Assign the rank (1-based index) as a character
        j++;
    }
    ranked[j] = '\0'; // Null-terminate the ranked string
    return (1);
}

/**
 * @brief Sorts the values into the sorted array using Bubble Sort.
 * 
 * @param values The original array of values.
 * @param sorted The output array to store the sorted values.
 */
static void sort_values(int *values, int *sorted)
{
    int i;
    int j;

    // Copy values into the sorted array
    i = 0;
    while (i < 4)
    {
        sorted[i] = values[i];
        i++;
    }

    // Perform Bubble Sort on the sorted array
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 3 - i)
        {
            if (sorted[j] > sorted[j + 1])
                swap_ints(&sorted[j], &sorted[j + 1]);
            j++;
        }
        i++;
    }
}

/**
 * @brief Extracts the integer values from the stack into an array.
 * 
 * @param stack The head of the stack.
 * @param values The array to store the extracted values.
 */
static void extract_values(t_digit **stack, int *values)
{
    t_digit *current;
    int i;

    current = *stack;
    i = 0;
    while (i < 4)
    {
        values[i] = current->num; // Extract the integer value directly
        current = current->next;
        i++;
    }
}

/**
 * @brief Swaps two integers.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
static void	swap_ints(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}



