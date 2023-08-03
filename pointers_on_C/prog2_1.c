#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned short  UINT16;
typedef unsigned char   UINT8;
typedef signed  char    INT8;
typedef short           INT16;

typedef struct item_s {
    char index;
    char *desc;
    void (*func)(void);
} item_t;

#define ARRAY_SIZE(x)   (sizeof(x) / sizeof((x)[0]))

static void hello_world(void)
{
    printf("hello world");
}

static const item_t FIU_item[] = {
    { /* Flash device selection */
        .index = 'a',
        .desc = "Flash device selection",
        .func = hello_world, 
    },
};

static const UINT16 fiu_item_size = ARRAY_SIZE(FIU_item);

static void flu_print_line(void)
{
    printf("+-----------------------------+\r\n");
}

static void fiu_show_item(void)
{
    UINT16 i;
    printf("\r\n\r\n");
    flu_print_line();
    printf("\t FIU Validation Module\t\r\n");

    for(i=0; i<fiu_item_size; i++)
		printf(" %c: %s\r\n", FIU_item[i].index, FIU_item[i].desc);
}

static INT16 fiu_do_cmd(void)
{
    UINT8  cmd;
    UINT16  i;
    printf(" Please enter your cmd: ");
    scanf("%c",&cmd);

    cmd = tolower(cmd);
	for(i=0; i<fiu_item_size; i++)
	{
		if(_tolower(FIU_item[i].index) == cmd)
		{
			if(FIU_item[i].func){
				FIU_item[i].func();
				break;
			}
			else
				return -1;
		}
	}
}

int main()
{
    unsigned short ret;
    
    do
    {
        fiu_show_item();
        ret = fiu_do_cmd();
    }while(ret >= 0);
    
}
