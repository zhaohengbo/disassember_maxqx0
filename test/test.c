#include <stdio.h>
#include <stdlib.h>

#include "decode.h"
#include "ins_decode.h"

int main()
{
    FILE *fp = NULL;
    char buf[512];
    int counter1 = 0,counter2 = 0;
    uint16_t code = 0;
    bool prefix;
    decode_status status;

    fp = fopen("D:\\workspcae\\cw\\crt0.o","rb");

    if(fp != NULL)
    {
        while(!feof(fp))
        {
            if(counter1 == 0)
            {
                counter1 = 1;
                code = fgetc(fp);
            }
            else
            {
                counter1 = 0;
                code = code | ((int16_t)fgetc(fp) << 8);
                status = maxqx0_ins_decode(code,buf,&prefix);
                if(status == decode_success)
                {
                    printf("%05X\t%04X\t%s\n",counter2,code,buf);
                }
                else if(status == decode_unknown)
                {
                    printf("%05X\t%04X\tunknown\n",counter2,code);
                }
                else
                {
                    printf("%05X\t%04X\terror!\n",counter2,code);
                    break;
                }
                counter2++;
            }
        }
        fclose(fp);
    }

    return 0;
}
