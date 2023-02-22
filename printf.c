#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// https://github.com/EcosElisa/Printf/blob/master/sources/ft_printf.c

/* Functions prototypes */
int ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_detect_format(char c, va_list args);
void	ft_min(int n, char *str);
int	ft_number_len(int n);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);

int main()
{
   //char f_str[50];
   //char name[] = "Johnson";
   //int height = 170;
   //formatStr(5, "Name: %% Height: %i", name, height);
   //char test[] = "coconut";
   //printf("%s\n", test);

   //ft_printf("%c %s %d %c\n", 'a', "hello", 1234567);
   ft_printf("Hola\n");
   ft_printf("%c %s\n", 'a', "Hello");
   printf("%c %c %c %c", 'a', 'b', 'c', 'd');
   //printf("%s", test);
   return (0);
}

void	ft_min(int n, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
	}	
}

int	ft_number_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	i = ft_number_len(n);
	size = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_min(n, str);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while ((n > 0) && i--)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	str[size] = '\0';
	return (str);
}

// prints char
int ft_putchar(char c)
{
   return (write(1, &c, 1));
}

// function that will detect the format specifier and redirects to 
// the function that will print the data type
int ft_detect_format(char c, va_list args) {
   
   int to_print;

   to_print = 0;
   if (c == 'c'){
    	ft_putchar(va_arg(args, int));
	} else if (c == 's'){
		ft_putstr(va_arg(args, char *));
	} else if (c == 'p'){
		// TODO: format specifier for pointer
		// need to have unsigned int for print	
   	} else if (c == 'd' || c == 'i'){
      to_print = va_arg(args, int);
      ft_putstr(ft_itoa(to_print));   
    } else if ( c == 'u'){
		// TO-DO: format specifier for unsigned int
	} else if ( c == 'x' || c == 'X'){
		//TO-DO: format specifiers for Hexadecimal representation
	}
   return (to_print);
}

// printf main body. Should call each data specifier function
int ft_printf(const char *str, ...){

   int i;
   int to_print;
   va_list args;
   
   i = 0;
   to_print = 0;
   va_start(args, str);

   if (str ==NULL)
   {
      return (-1);
   }

   while (str[i])
   {
      if (str[i] == '%')
      {
         to_print += ft_detect_format(str[i+1], args);
		 i++;
      }
      else
      {
         to_print += ft_putchar(str[i]);
      }
      i++;
   }
   va_end(args);
   return(to_print);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putptr(int n)
{
	int *ptr = &n;
	int** ptr_to_ptr = &ptr;

}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}	
	return (len);
}	
