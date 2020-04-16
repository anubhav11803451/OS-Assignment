# OS-Assignment

### Ouestion 26 :>
Design a file-copying program named filecopy using ordinary pipes. This program will be passed two parameters: the name of the file to be copied and the name of the copied file. The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The child process will read this file from the pipe and write it to the destination file. For example, if we invoke the program as follows:
filecopy input.txt copy.txt
The file input.txt will be written to the pipe. The child process will read the contents of this file and write it to the destination file copy.txt

### Output >>
Enter the following commands in terminal to run the code
# gcc -o Q26 Q26.c
# echo "enter any data here." > input.txt
# ./Q26 input.txt copy.txt
# cat copy.txt
![Screenshot (91)](https://user-images.githubusercontent.com/56965382/79423461-48d9fe00-7fdc-11ea-8bb4-0fd4dbae417a.png)
