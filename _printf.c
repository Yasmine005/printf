#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Custom printf function that handles precision for non-custom conversion specifiers
 *
 * @format: The format string
 * @...: Additional arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
int precision = -1;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '.')
{
format++;
precision = 0;
while (*format >= '0' && *format <= '9')
{
precision = precision * 10 + (*format - '0');
format++;
}
}
switch (*format)
{
case 'd':
case 'i':
printed_chars += printf("%.*d", precision, va_arg(args, int));
break;
case 'u':
printed_chars += printf("%.*u", precision, va_arg(args, unsigned int));
break;
case 'o':
printed_chars += printf("%.*o", precision, va_arg(args, unsigned int));
break;
case 'x':
printed_chars += printf("%.*x", precision, va_arg(args, unsigned int));
break;
case 'X':
printed_chars += printf("%.*X", precision, va_arg(args, unsigned int));
break;
case 'c':
printed_chars += putchar(va_arg(args, int));
break;
case 's':
printed_chars += printf("%.*s", precision, va_arg(args, char *));
break;
default:
putchar('%');
putchar(*format);
printed_chars += 2;
break;
}
precision = -1;
}
else
{
putchar(*format);
printed_chars++;
}
format++;
}
va_end(args);
return (printed_chars);
}
