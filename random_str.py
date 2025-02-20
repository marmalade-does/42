import random
import string

def generate_random_string():
    # Generate 2 random special characters
    special_chars = random.choices('!@#$%^&*()-_=+', k=2)

    # Generate 2 random alphanumeric characters for the start
    start_chars = random.choices(string.ascii_letters + string.digits, k=4)

    # Generate 2 random alphanumeric characters for the end
    end_chars = random.choices(string.ascii_letters + string.digits, k=4)
    obliged_num = random.choices(string.digits, k=1)

    # Construct the final string: start + special + end
    result = ''.join(start_chars) + ''.join(special_chars) + ''.join(end_chars) + ''.join(obliged_num)

    return result

# Generate and print the random string
random_string = generate_random_string()
print(random_string)
