/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:48:35 by hjacinto          #+#    #+#             */
/*   Updated: 2026/05/22 22:57:24 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 4096
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

/*
	Checks whether a character is an alphabetic letter. 
*/
int		ft_isalpha(int c);

/*
	Checks whether the given character is a decimal digit.
*/
int		ft_isdigit(int c);

/*
	Checks whether the given character is alphanumeric.
*/
int		ft_isalnum(int c);

/*
	Checks whether the given character is a valid ASCII character.
*/
int		ft_isascii(int c);

/*
	Checks if the given character is printable, including the space character.
*/
int		ft_isprint(int c);

/*
	Computes the length of a string, excluding the null terminator.
*/
size_t	ft_strlen(const char *s);

/*
	Fills memory with a constant byte value.
*/
void	*ft_memset(void *b, int c, size_t len);

/*
	Sets the first n bytes of memory to zero
*/
void	ft_bzero(void *s, size_t n);

/*
	Copies memory from source to destination. Does not handle overlap.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
	Moves memory from source to destination. Handles overlapping memory areas.
*/
void	*ft_memmove(void *dst, const void *src, size_t n);

/*
	Copies a string into a destination buffer with size protection.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
	Appends a string to another string with size protection.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
	Converts a lowercase letter to uppercase.
*/
int		ft_toupper(int c);

/*
	Converts an uppercase letter to lowercase.
*/
int		ft_tolower(int c);

/*
	Locates the first occurrence of a character in a string.
*/
char	*ft_strchr(const char *s, int c);

/*
	Locates the last occurrence of a character in a string.
*/
char	*ft_strrchr(const char *s, int c);

/*
	Compares two strings up to n characters.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
	Searches memory for the first occurrence of a byte value.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
	Compares two memory areas byte by byte.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	Searches for a substring within a string, limited to a maximum length.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*
*	Converts a string to an integer. Skips whitespaces and handles optional sign.
*/
int		ft_atoi(const char *str);

/*
	Allocates memory for an array and initializes it to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*
	Creates a duplicate of a string.
*/
char	*ft_strdup(const char *s1);

/*
	Returns a substring from the given string.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
	Returns a new string formed by concatenating two strings.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
	Returns a trimmed copy of the string.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
	Returns an array of strings resulting from splitting the string.
*/
char	**ft_split(char const *s, char c);

/*
	Converts an integer into a string representation.
*/
char	*ft_itoa(int n);

/*
	Applies a function to each character of a string and returns a new string.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
	Applies a function to each character of a string using its index.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
	Outputs a character to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd);

/*
	Outputs a string to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
	Outputs a string followed by a newline to the given file descriptor.
*/
void	ft_putendl_fd(char *s, int fd);

/*
	Outputs an integer to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd);

/*
	Allocates memory and returns a new list node.
*/
t_list	*ft_lstnew(void *content);

/*
	Adds a node at the beginning of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
	Counts the number of nodes in the list.
*/
int		ft_lstsize(t_list *lst);

/*
	Returns the last node of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/*
	Adds a node at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*
	Deletes a node and frees its content using the given function.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
	Clears and frees all nodes of the list using the given function.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/*
	Iterates through the list and applies a function to each node's content.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
	Creates a new list by applying a function to each node's content.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
	ft_printf
*/
int		ft_printf(const char *format, ...);
int		get_error(int size);
void	print_char(char c, int *len);
void	print_str(char *str, int *len);
void	print_num(int num, int *len);
void	print_unsigned(unsigned int num, int *len);
void	print_hex(uintptr_t num, int *len, char *base);
void	print_ptr(uintptr_t addr, int *len);

/*
	get_next_line
*/
char	*get_next_line(int fd);
size_t	line_length(char const *s);
int		has_newline(char const *s);
char	*join_buffer(char *s1, char const *s2);
void	update_buffer(char *buffer);

#endif