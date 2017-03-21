#include<stdio.h>
#include<string.h>
int main()
{

    char ara[21],ch='0';
    int i;

    while(scanf("%s",ara)!=EOF)
    {
        ch='0';
      for(i=0;ara[i]!='\0';i++)
      {
          switch (ara[i])
          {
            case 'B':
            case 'F':
            case 'P':
            case 'V':
            if('1'!=ch)printf("1");ch='1';
            break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
            if('2'!=ch)printf("2");ch='2';
            break;
            case 'D':
            case 'T':
            if('3'!=ch)printf("3");ch='3';
            break;
            case 'L':
            if('4'!=ch)printf("4");ch='4';
            break;
            case 'M':
            case 'N':
            if('5'!=ch)printf("5");ch='5';
            break;
            case 'R':
            if('6'!=ch)printf("6");ch='6';
            break;
            default:
                ch='0';
                break;

          }

      }
      printf("\n");
    }

    return 0;
}
