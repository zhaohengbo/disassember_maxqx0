#include "decode.h"

#include "src_decode.h"
#include "src_decode_pvt.h"

static inline bool determine_masked_src(uint16_t code,uint16_t src_code,uint16_t mask)
{
    return ((code & mask) == src_code);
}

static inline uint16_t get_src_4n(uint16_t code)
{
    code &= SRC_4N_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_src_3n(uint16_t code)
{
    code &= SRC_3N_MASK;
    return code;
}

static inline uint16_t get_src_1na(uint16_t code)
{
    code &= SRC_1NA_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_src_1nb(uint16_t code)
{
    code &= SRC_1NB_MASK;
    code = code >> 6;
    return code;
}

decode_status maxqx0_src_decode(uint16_t code,char * buf)
{
    if(determine_masked_src(code,SRC_CONSTANT,SRC_MASK0B))
    {
        sprintf(buf,"#%02X",code);
        return decode_success;
    }

    if(determine_masked_src(code,SRC_MN_N,SRC_MASK0_5B))
    {
        if(get_src_3n(code) == 2)
        {
            if(get_src_4n(code) == 0)
            {
                sprintf(buf,"MCNT");
            }
            else if(get_src_4n(code) == 1)
            {
                sprintf(buf,"MA");
            }
            else if(get_src_4n(code) == 2)
            {
                sprintf(buf,"MB");
            }
            else if(get_src_4n(code) == 4)
            {
                sprintf(buf,"MC0");
            }
            else if(get_src_4n(code) == 5)
            {
                sprintf(buf,"MC1");
            }
            else if(get_src_4n(code) == 11)
            {
                sprintf(buf,"MC0R");
            }
            else if(get_src_4n(code) == 12)
            {
                sprintf(buf,"MC1R");
            }
            else
            {
                sprintf(buf,"M%d[%d]",get_src_3n(code),get_src_4n(code));
            }
        }
        else
        {
            sprintf(buf,"M%d[%d]",get_src_3n(code),get_src_4n(code));
        }
        return decode_success;
    }

    if(determine_masked_src(code,SRC_AP,SRC_MASKALLB))
    {
        sprintf(buf,"AP");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_APC,SRC_MASKALLB))
    {
        sprintf(buf,"APC");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_PSF,SRC_MASKALLB))
    {
        sprintf(buf,"PSF");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_IC,SRC_MASKALLB))
    {
        sprintf(buf,"IC");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_IMR,SRC_MASKALLB))
    {
        sprintf(buf,"IMR");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_SC,SRC_MASKALLB))
    {
        sprintf(buf,"SC");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_IIR,SRC_MASKALLB))
    {
        sprintf(buf,"IIR");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_CKCN,SRC_MASKALLB))
    {
        sprintf(buf,"WDCN");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_N,SRC_MASK0_5_9B))
    {
        sprintf(buf,"A[%d]",get_src_4n(code));
        return decode_success;
    }

    if(determine_masked_src(code,SRC_ACC,SRC_MASKALLB))
    {
        sprintf(buf,"ACC");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_AP,SRC_MASKALLB))
    {
        sprintf(buf,"A[AP]");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_IP,SRC_MASKALLB))
    {
        sprintf(buf,"IP");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_SP_DD,SRC_MASKALLB))
    {
        sprintf(buf,"@SP--");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_SP,SRC_MASKALLB))
    {
        sprintf(buf,"SP");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_IV,SRC_MASKALLB))
    {
        sprintf(buf,"IV");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_LC_N,SRC_MASK0_3_5_9B))
    {
        sprintf(buf,"LC[%d]",get_src_1na(code));
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_SPI_DD,SRC_MASKALLB))
    {
        sprintf(buf,"@SPI--");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_BP_OFFS,SRC_MASKALLB))
    {
        sprintf(buf,"@BP[Offs]");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_BP_OFFS_DD,SRC_MASKALLB))
    {
        sprintf(buf,"@BP[Offs]--");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_BP_OFFS_PP,SRC_MASKALLB))
    {
        sprintf(buf,"@BP[Offs]++");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_OFFS,SRC_MASKALLB))
    {
        sprintf(buf,"OFFS");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_DPC,SRC_MASKALLB))
    {
        sprintf(buf,"DPC");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_GR,SRC_MASKALLB))
    {
        sprintf(buf,"GR");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_GRL,SRC_MASKALLB))
    {
        sprintf(buf,"GRL");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_BP,SRC_MASKALLB))
    {
        sprintf(buf,"BP");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_GRS,SRC_MASKALLB))
    {
        sprintf(buf,"GRS");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_GRH,SRC_MASKALLB))
    {
        sprintf(buf,"GRH");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_GRXL,SRC_MASKALLB))
    {
        sprintf(buf,"GRXL");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_FP,SRC_MASKALLB))
    {
        sprintf(buf,"FP");
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_DP_N,SRC_MASK0_1_3_9B))
    {
        sprintf(buf,"@DP[%d]",get_src_1nb(code));
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_DP_N_DD,SRC_MASK0_1_3_9B))
    {
        sprintf(buf,"@DP[%d]--",get_src_1nb(code));
        return decode_success;
    }

    if(determine_masked_src(code,SRC_A_DP_N_PP,SRC_MASK0_1_3_9B))
    {
        sprintf(buf,"@DP[%d]++",get_src_1nb(code));
        return decode_success;
    }

    if(determine_masked_src(code,SRC_DP_N,SRC_MASK0_1_3_9B))
    {
        sprintf(buf,"DP[%d]",get_src_1nb(code));
        return decode_success;
    }

    return decode_unknown;
}
