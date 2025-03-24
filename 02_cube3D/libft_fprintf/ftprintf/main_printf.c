#include <fcntl.h>   // Per open()
#include <unistd.h>  // Per close()
#include <stdio.h>   // Per fprintf()
#include <limits.h>  // Per INT_MAX, INT_MIN
#include <stdint.h>  // Per uint32_t

int main(void)
{
    int ft_ret, std_ret;
    int fd;

    // Apriamo un file (stderr) con open()
    fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); // Apriamo un file per scrivere i risultati
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }
    fd2 = 200;
    
    if (ft_fprintf(fd2, "Char test: %c\n", 'A') == -1)
	    write(1, "Error\n", 6);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    ft_ret += ft_fprintf(fd, "Char test: %c\n", 'A');
    ft_ret += ft_fprintf(fd, "");
    std_ret += fprintf(fd, "Char test: %c\n", 'A');
    std_ret += fprintf(fd, "");
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST X [STR]\n");
    ft_ret += ft_fprintf(fd, "String test: %s\n", "Hello, world!");
    ft_ret += ft_fprintf(fd, "Null char test: '%s'\n", "Hello\0World");
    ft_ret += ft_fprintf(fd, "String test NULL: %s\n", (char *)NULL);
    ft_ret += ft_fprintf(fd, "String test NULL: %s\n", "");
    std_ret += fprintf(fd, "String test: %s\n", "Hello, world!");
    std_ret += fprintf(fd, "Null char test: '%s'\n", "Hello\0World");
    std_ret += fprintf(fd, "String test NULL: %s\n", (char *)NULL);
    std_ret += fprintf(fd, "String test NULL: %s\n", "");
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [INTEGER]\n");
    ft_ret += ft_fprintf(fd, "Integer test: %d\n", 12345);
    ft_ret += ft_fprintf(fd, "Integer test MAX %d\n", INT_MAX);
    ft_ret += ft_fprintf(fd, "integer test MIN %d\n", INT_MIN);
    ft_ret += ft_fprintf(fd, "Incompatible modifier test: %d\n", "StringInsteadOfInt");
    std_ret += fprintf(fd, "Integer test: %d\n", 12345);
    std_ret += fprintf(fd, "integer test MAX %d\n", INT_MAX);
    std_ret += fprintf(fd, "integer test MIN %d\n", INT_MIN);
    std_ret += fprintf(fd, "Incompatible modifier test: %d\n", "StringInsteadOfInt");
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [BASE 10N {i}]\n");
    ft_ret += ft_fprintf(fd, "Signed int test: %i\n", -12345);
    std_ret += fprintf(fd, "Signed int test: %i\n", -12345);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [UNSIGNED INTEGER]\n");
    ft_ret += ft_fprintf(fd, "Unsigned int test: %u\n", 12345U);
    ft_ret += ft_fprintf(fd, "Unsigned test INTMIN: %u\n", INT_MIN);
    ft_ret += ft_fprintf(fd, "Unsigned int test MAX: %u\n", UINT_MAX);
    std_ret += fprintf(fd, "Unsigned int test: %u\n", 12345U);
    std_ret += fprintf(fd, "Unsigned test INTMIN: %u\n", INT_MIN);
    std_ret += fprintf(fd, "Unsigned int test MAX: %u\n", UINT_MAX);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [HEXADECIMAL x]\n");
    ft_ret += ft_fprintf(fd, "Hexadecimal lowercase: %x\n", 0xabcdef);
    ft_ret += ft_fprintf(fd, "Hexadecimal lowercase: %x\n", UINT_MAX);
    ft_ret += ft_fprintf(fd, "Hexadecimal lowercase: %x\n", 16);
    std_ret += fprintf(fd, "Hexadecimal lowercase: %x\n", 0xabcdef);
    std_ret += fprintf(fd, "Hexadecimal lowercase: %x\n", UINT_MAX);
    std_ret += fprintf(fd, "Hexadecimal lowercase: %x\n", 16);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [HEXADECIMAL X]\n");
    ft_ret += ft_fprintf(fd, "Hexadecimal uppercase: %X\n", 0xABCDEF);
    std_ret += fprintf(fd, "Hexadecimal uppercase: %X\n", 0xABCDEF);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    int a = 42;
    char *s = "str random";
    fprintf(fd, "TEST [POINTER]\n");
    ft_ret += ft_fprintf(fd, "Pointer test: %p\n", (void *) &a);
    std_ret += fprintf(fd, "Pointer test: %p\n", (void *) &a);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [PERCENTAGE]\n");
    ft_ret += ft_fprintf(fd, "Percentage test: %%\n");
    ft_ret += ft_fprintf(fd, "Percentage test: %%%%%%%%%%%%%%%%\n");
    ft_ret += ft_fprintf(fd, "%");
    std_ret += fprintf(fd, "Percentage test: %%\n");
    std_ret += fprintf(fd, "Percentage test: %%%%%%%%%%%%%%%%\n");
    std_ret += fprintf(fd, "%");
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [NO ARG]\n");
    ft_ret += ft_fprintf(fd, " NO ARG TEST\n");
    ft_ret += ft_fprintf(fd, "");
    std_ret += fprintf(fd, " NO ARG TEST\n");
    std_ret += fprintf(fd, "");
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n", ft_ret, std_ret);

    /***********/////////////////////////////////////////////////////////////////****
    std_ret = 0;
    ft_ret = 0;
    fprintf(fd, "TEST [MIXED]\n");
    ft_ret += ft_fprintf(fd, "Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",'A', "Hello, world!", 12345, 0xabc, (void*)0, INT_MAX, 12312312);
    ft_ret += ft_fprintf(fd, "Mixed test: pointer='%p', unsigned='%u\n",(void*)0, UINT_MAX);
    ft_ret += ft_fprintf(fd, "Mixed test: char='%c', string='%s', hex='%x',unsigned='%u', percent='%%'\n",'A', "Hello, world!", 0xabc, UINT_MAX);
    std_ret += fprintf(fd, "Mixed test: char='%c', string='%s', int='%d', hex='%x', pointer='%p', unsigned='%u', percent='%%'\n",'A', "Hello, world!", 12345, 0xabc, (void*)0, INT_MAX, 123123123);
    std_ret += fprintf(fd, "Mixed test: pointer='%p', unsigned='%u\n",(void*)0, UINT_MAX);
    std_ret += fprintf(fd, "Mixed test: char='%c', string='%s', hex='%x',unsigned='%u', percent='%%'\n",'A', "Hello, world!", 0xabc, UINT_MAX);
    printf("Return values: ft_fprintf = %d, fprintf = %d\n\n\n", ft_ret, std_ret);

    fprintf(fd, "TEST FINISH WEWEW  \n\n");

    // Chiudiamo il file descriptor
    close(fd);

    return 0;
}

