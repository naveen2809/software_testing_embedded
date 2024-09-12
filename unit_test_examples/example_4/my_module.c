#include <stdint.h>

static void fill_array(uint8_t value, uint8_t *barray, int len);

int write_byte_array(int type, uint8_t *barray, int len)
{

    if(len <=0)
    {
        return -1;
    }

    if(type > 0)
    {
        fill_array(0xaa, barray, len);
    }
    else if(type < 0)
    {
        fill_array(0xbb, barray, len);
    }
    else if(type == 0)
    {
        fill_array(0xcc, barray, len);
    }

    return 0;
}

static void fill_array(uint8_t value, uint8_t *barray, int len)
{
    for(int i=0; i < len; i++)
    {
        barray[i] = value;
    }
}