*This project has been created as part of the 42 curriculum by mabd-elh.*

## Description
This project is a replacement of standard library with additional functions, it will be used for feature 42 projects.

## Instructions
- Clone the repository into your device
``` bash
git clone https://github.com/MoMaimon/libft.git libft
```
- Compile and add the function into the library
```bash
make
```
- To use the library copy `libft.a` and `libft.h` into your project
- Compile your project using the library
```bash
gcc -Wall -Wextra -Werror -c main.c -o main.o
gcc main.o -L. -lft -o my_program
```

## Resources
- [Makefile Tutorial](https://makefiletutorial.com/)  
- [Medium: Makefile](https://swarnakar-ani24.medium.com/a-noobs-guide-to-using-make-and-writing-makefile-f718135d816b) 
- [Manual: for most functions](https://linux.die.net/man/)  
- [GeeksForGeeks: for more advanced explaination](https://www.geeksforgeeks.org/)  
#### **AI** usage:
- Was used to explain some "weird" behaviors of the original functions.
- Helped with formatting the `README.md` file.


## Library Description
| Function | Prototype | Description |
| :--- | :--- | :--- |
|**ft_atoi** | `int ft_atoi(const char *nptr);` | Converts the initial portion of the string pointed to by `nptr` to int. |
| **ft_bzero** | `void ft_bzero(void *s, size_t n);` | Erases the data in the `n` bytes of the memory starting at the location pointed to by `s`, by writing zeros (`\0`) to that area. |
| **ft_calloc** | `void *ft_calloc(size_t nmemb, size_t size);` | Allocates memory for an array of `nmemb` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is set to zero. |
| **ft_isalnum** | `int ft_isalnum(int c);` | Checks for an alphanumeric character; it is equivalent to `(isalpha(c) || isdigit(c))`. |
| **ft_isalpha** | `int ft_isalpha(int c);` | Checks for an alphabetic character. |
| **ft_isascii** | `int ft_isascii(int c);` | Checks whether `c` is a 7-bit unsigned char value that fits into the ASCII character set. |
| **ft_isdigit** | `int ft_isdigit(int c);` | Checks for a digit (0 through 9). |
| **ft_isprint** | `int ft_isprint(int c);` | Checks for any printable character including space. |
| **ft_itoa** | `char *ft_itoa(int n);` | Allocates (with malloc) and returns a string representing the integer received as an argument. |
| **ft_lstadd_back** | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. |
| **ft_lstadd_front** | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the beginning of the list. |
| **ft_lstclear** | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the given node and every successor of that node, using the function `del` and `free(3)`. |
| **ft_lstdelone** | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Takes as a parameter a node and frees the memory of the node’s content using the function `del` given as a parameter and free the node. |
| **ft_lstiter** | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates the list `lst` and applies the function `f` on the content of each node. |
| **ft_lstlast** | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. |
| **ft_lstmap** | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));` | Iterates the list `lst` and applies the function `f` on the content of each node. Creates a new list resulting of the successive applications of the function `f`. |
| **ft_lstnew** | `t_list *ft_lstnew(void *content);` | Allocates (with malloc) and returns a new node. The member variable `content` is initialized with the value of the parameter `content`. The variable `next` is initialized to NULL. |
| **ft_lstsize** | `unsigned int ft_lstsize(t_list *lst);` | Counts the number of nodes in a list. |
| **ft_memchr** | `void *ft_memchr(const void *s, int c, size_t n);` | Scans the initial `n` bytes of the memory area pointed to by `s` for the first instance of `c`. |
| **ft_memcmp** | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares the first `n` bytes of the memory areas `s1` and `s2`. |
| **ft_memcpy** | `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes from memory area `src` to memory area `dest`. The memory areas must not overlap. |
| **ft_memmove** | `void *ft_memmove(void *dest, const void *src, size_t n);` | Copies `n` bytes from memory area `src` to memory area `dest`. The memory areas may overlap. |
| **ft_memset** | `void *ft_memset(void *s, int c, size_t n);` | Fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`. |
| **ft_putchar_fd** | `void ft_putchar_fd(char c, int fd);` | Outputs the character `c` to the given file descriptor. |
| **ft_putendl_fd** | `void ft_putendl_fd(char *s, int fd);` | Outputs the string `s` to the given file descriptor followed by a newline. |
| **ft_putnbr_fd** | `void ft_putnbr_fd(int n, int fd);` | Outputs the integer `n` to the given file descriptor. |
| **ft_putstr_fd** | `void ft_putstr_fd(char *s, int fd);` | Outputs the string `s` to the given file descriptor. |
| **ft_split** | `char **ft_split(char const *s, char c);` | Allocates (with malloc) and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a NULL pointer. |
| **ft_strchr** | `char *ft_strchr(const char *s, int c);` | Returns a pointer to the first occurrence of the character `c` in the string `s`. |
| **ft_strdup** | `char *ft_strdup(const char *s);` | Returns a pointer to a new string which is a duplicate of the string `s`. |
| **ft_striteri** | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies the function `f` on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to `f` to be modified if necessary. |
| **ft_strjoin** | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates (with malloc) and returns a new string, which is the result of the concatenation of `s1` and `s2`. |
| **ft_strlcat** | `size_t ft_strlcat(char *dst, const char *src, size_t size);` | Appends string `src` to the end of `dst`. It will append at most `size - strlen(dst) - 1` characters, NUL-terminating the result. |
| **ft_strlcpy** | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies up to `size - 1` characters from the NUL-terminated string `src` to `dst`, NUL-terminating the result. |
| **ft_strlen** | `size_t ft_strlen(const char *s);` | Calculates the length of the string `s`, excluding the terminating null byte (`\0`). |
| **ft_strmapi** | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies the function `f` to each character of the string `s`, and passing its index as first argument to create a new string (with malloc) resulting from successive applications of `f`. |
| **ft_strncmp** | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares at most the first `n` bytes of the two strings `s1` and `s2`. |
| **ft_strnstr** | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Locates the first occurrence of the null-terminated string `little` in the string `big`, where not more than `len` characters are searched. |
| **ft_strrchr** | `char *ft_strrchr(const char *s, int c);` | Returns a pointer to the last occurrence of the character `c` in the string `s`. |
| **ft_strtrim** | `char *ft_strtrim(char const *s1, char const *set);` | Allocates (with malloc) and returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string. |
| **ft_substr** | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates (with malloc) and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`. |
| **ft_tolower** | `int ft_tolower(int c);` | Converts an uppercase letter to lowercase. |
| **ft_toupper** | `int ft_toupper(int c);` | Converts a lowercase letter to uppercase. |
