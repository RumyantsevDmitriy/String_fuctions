#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>

int puts1 (const char* str)
{
    if (*str != '\0')
    {
        for ( ; *str != '\0' ; )
        {
            putchar(*str++);
        }
        putchar('\n');
        return 0;
    }

    return EOF;
}

const char* strchr1 (const char* str, int symbol)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == symbol)
            return &(str[i]);
    }

    return NULL;
}

size_t strlen1 (const char* str)
{
    size_t i = 0;
    for (i; *str++ != '\0'; i++) {;}

    return i;
}

char* strcpy1 (char* destptr, const char* srcptr)
{
    size_t i = 0;
    for (i; srcptr[i] != '\0'; i++)
    {
        destptr[i] = srcptr[i];
    }
    destptr[i] = '\0';

    return destptr;
}

char* strncpy1 (char* destptr, const char* srcptr, size_t num)
{
    size_t i = 0;
    for (i; i < num; i++)
    {
        destptr[i] = srcptr[i];
    }
    destptr[i] = '\0';

    return destptr;
}

char* strcat1 (char* destptr, const char* srcptr)
{
    size_t i = strlen(destptr), j = 0;
    for (i, j; srcptr[j] != '\0'; i++, j++)
    {
        destptr[i] = srcptr[j];
    }
    destptr[i] = '\0';

    return destptr;
}

char* strncat1 (char* destptr, const char* srcptr, size_t num)
{
    size_t i = strlen(destptr), j = 0;
    for (i, j; j < num; i++, j++)
    {
        destptr[i] = srcptr[j];
    }
    destptr[i] = '\0';

    return destptr;
}

char* fgets1 (char* str, int num, FILE* filestream)
{
    size_t i = 0;
    for (i; i < num; i++)
    {
        char c = fgetc(filestream);
        if (c == EOF && i == 0)
            return NULL;

        if (c == '\n')
        {
            str[i] = '\n';
            break;
        }

        str[i] = c;
    }
    str[i] = '\0';

    return str;
}

char* strdup1 (const char* str)
{
    char* strd = (char*) calloc(strlen(str), sizeof(char));
    if (strd == NULL)
        return NULL;

    for (size_t i = 0; i < strlen(str); i++)
    {
        strd[i] = str[i];
    }

    return strd;
}

ssize_t getline1 (char** lineptr, size_t* N, FILE* stream)
{
    size_t n = *N;
    char * mas = (char*) calloc(n, sizeof(char));
    if (mas == NULL)
        return -1;

    ssize_t i = 0;
    char c = fgetc(stream);
    for (i = 0; c != '\n'; i++)
    {
        if (i + 1 >= n)
        {
            n++;
            mas = (char*) realloc(mas, n);
            if (mas == NULL)
                return -1;

            mas[i] = '\0';
        }
        mas[i] = c;
        c = fgetc(stream);
    }
    mas[i] = '\0';
    *N = n;
    free(*lineptr);
    *lineptr = mas;

    return i;
}

int main(void)
{
    /*char str[10] = "hello";
    char str1[] = "world!!!\0";
    char s1[50] = "He\0llo ";
    char s[20] ="";
    char s2[50] = "world!!!\0"; */

    /*int check = puts1(str);
    printf("\ncheck = %d", check);*/

    /*char* check1 = strchr(str, 'h');
    printf("%s", check1);*/

    /*printf("%d\n",strlen1(s1));
    printf("%d",strlen(s1)); */

    /*printf("%s\n", strcpy1(s2, str));
    printf("%s", strcpy(s2, str));  */

    /*char str5[50] = "";
    strcpy1( str5, "Эти " );
    strcat1( str5, "стр\0оки "          );
    strcat1( str5, "объединены "    );
    strcat1( str5, "операцией "      );
    strcat1( str5, "конкатенации." );
    printf("1 - %s", str5);
    strcpy( str5, "Эти " );
    strcat( str5, "стр\0оки "          );
    strcat( str5, "объединены "    );
    strcat( str5, "операцией "      );
    strcat( str5, "конкатенации." );
    printf("\n2 - %s", str5); */

    /*char str1[50] = "Быть или не быть \0";
    char str5[50] = "Быть или не быть \0";
    char str2[50] = "Вот в чем вопрос\0";
    char str4[50] = {};

    strncat1(str1, str2,5);
    printf("%s!\n", str1);
    strncat(str5, str2,5);
    printf("%s!\n", str5);*/

    /*FILE * ptrFile = fopen("file.txt" , "r");
    char mystring [100]={};

    if (ptrFile == NULL) perror("Ошибка открытия файла");
    else
    {
        if ( fgets1(mystring, 100, ptrFile) != NULL ) // считать символы из файла
            puts1(mystring);  // вывод на экран
        fclose (ptrFile);
    }

    FILE * ptrFile1 = fopen("file.txt" , "r");
    char mystring1 [100]={};

    if (ptrFile1 == NULL) perror("Ошибка открытия файла");
    else
    {
        if ( fgets(mystring1, 100, ptrFile1) != NULL ) // считать символы из файла
            puts(mystring1);  // вывод на экран
        fclose (ptrFile1);
   } */

   /*char *istr;
   istr = strdup1 (str1);
   printf ("Дубликат: %s\n", istr);
   free (istr);

   istr = strdup (str1);
   printf ("Дубликат: %s\n", istr);
   free (istr);*/


   /*char mstring[10] = {};
   char *str123=&(mstring[0]);

   size_t msize = 5;

   ssize_t st = 0;
   st = getline1(&str123, &msize, stdin);
   printf("N = %d\nst = %d\n", msize, st);
   for(int i = 0; i < msize; i++)
   {
        printf("m[%d] = '%c'\n", i, str123[i]);
   }*/


    return 0;
}
