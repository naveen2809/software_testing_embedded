#include <stdio.h>

int add_num(int x, int y)
{
    return x + y;
}

int add10(int x)
{
    return (x + 10);
}

int check_even(int x)
{
    if(x%2 == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int my_range(int a)
{

    if(a>-100 && a<100)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

int num_to_word(int x, char *output)
{

    if(x >=0 && x <=9)
    {
        switch(x)
        {
            case 0:
                sprintf(output,"zero");
                break;
            case 1:
                sprintf(output,"one");
                break;
            case 2:
                sprintf(output,"two");
                break;
            case 3:
                sprintf(output,"three");
                break;
            case 4:
                sprintf(output,"four");
                break;                
            case 5:
                sprintf(output,"five");
                break;
            case 6:
                sprintf(output,"six");
                break;
            case 7:
                sprintf(output,"seven");
                break;
            case 8:
                sprintf(output,"eight");
                break;
            case 9:
                sprintf(output,"nine");
                break;
            default:
                break;                                
        }

        return 0;
    }
    else
    {
        return -1;
    }

}