import multiply_array
print(multiply_array.__file__)  # This will print the path to the .so file

# Create a list of numbers
numbers = [1.5, 2.5, 3.5, 4.5]

# Call the multiply_array function
result1 = multiply_array.multiply_by_factor(numbers, 20)  # Multiplies all elements by 2
# result2 = multiply_array.add_to_each(numbers, 20.0)  # Multiplies all elements by 2

print(result1)
