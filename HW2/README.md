# Set Operations Program

This Java program allows users to perform set operations on two sets (Set A and Set B). Users can input elements for each set, and the program will display the union, intersection, and difference of the sets.

## How to Use

1. **Compile the Program:**
- Make sure you have Java installed on your machine.
- Save the provided Java code in a file, e.g., HW2.java.
- Open a terminal and navigate to the directory containing the file.
  
**Compile the program using the following command:**
```bash
javac HW2.java
```

**Run the Program:**
```bash
java HW2
```
**Input Set Elements:**
- Follow the on-screen instructions to input elements for Set A and Set B.
- Enter -1 to stop entering elements for each set.

**View Set Operations:**
- After entering the sets, the program will display the union, intersection, and difference of Set A and Set B.

## Program Logic
- The program uses bitwise operations to represent sets as bitsets. It then performs set operations based on the user's input.

## Sample Output

```plaintext
Please enter numbers for set A (enter -1 to stop):
1
3
5
7
-1
Please enter numbers for set B (enter -1 to stop):
3
6
8
-1

Set A:         1010101000
Set B:         0010010100

Union:         1010111100
Intersection:  0010000000
Difference:    1000101000
```

## Contributing
Feel free to contribute to the development of this program. If you encounter issues or have suggestions, please open an issue on GitHub.

## License

This project is licensed under the [MIT License].
