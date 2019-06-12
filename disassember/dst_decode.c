#include "decode.h"

#include "dst_decode.h"
#include "dst_decode_pvt.h"

static inline bool determine_masked_dst(uint16_t code,uint16_t dst_code,uint16_t mask)
{
    return ((code & mask) == dst_code);
}

static inline uint16_t get_dst_3na(uint16_t code)
{
    code &= DST_3NB_MASK;
    return code;
}

static inline uint16_t get_dst_3nb(uint16_t code)
{
    code &= DST_3NA_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_dst_1na(uint16_t code)
{
    code &= DST_1NA_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_dst_1nb(uint16_t code)
{
    code &= DST_1NB_MASK;
    code = code >> 6;
    return code;
}

decode_status maxqx0_dst_decode(uint16_t code,char * buf,bool *prefix_on)
{
    bool prefix_old = *prefix_on;
    *prefix_on = false;

    if(prefix_old)
    {
        if(determine_masked_dst(code,DST_SC,DST_MASKALLB))
        {
            sprintf(buf,"SC");
            return decode_success;
        }

        if(determine_masked_dst(code,DST_CKCN,DST_MASKALLB))
        {
            sprintf(buf,"CKCN");
            return decode_success;
        }

        if(determine_masked_dst(code,DST_WDCN,DST_MASKALLB))
        {
            sprintf(buf,"WDCN");
            return decode_success;
        }

        if(determine_masked_dst(code,DST_A_N_2,DST_MASK3_6B))
        {
            sprintf(buf,"A[%d]",8 + get_dst_3nb(code));
            return decode_success;
        }

        if(determine_masked_dst(code,DST_GRH,DST_MASKALLB))
        {
            sprintf(buf,"GRH");
            return decode_success;
        }
    }
    else
    {
        if(determine_masked_dst(code,DST_AP,DST_MASKALLB))
        {
            sprintf(buf,"AP");
            return decode_success;
        }

        if(determine_masked_dst(code,DST_IMR,DST_MASKALLB))
        {
            sprintf(buf,"IMR");
            return decode_success;
        }

        if(determine_masked_dst(code,DST_A_N,DST_MASK3_6B))
        {
            sprintf(buf,"A[%d]",get_dst_3nb(code));
            return decode_success;
        }

        if(determine_masked_dst(code,DST_BP_PP_OFFS,DST_MASKALLB))
        {
            sprintf(buf,"@BP[++Offs]");
            return decode_success;
        }
    }

    if(determine_masked_dst(code,DST_NUL,DST_MASKALLB))
    {
        sprintf(buf,"NUL");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_MN_N,DST_MASK3B))
    {
        sprintf(buf,"M[%d][%d]",get_dst_3na(code),get_dst_3nb(code));
        return decode_success;
    }

    if(determine_masked_dst(code,DST_APC,DST_MASKALLB))
    {
        sprintf(buf,"APC");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_PSF,DST_MASKALLB))
    {
        sprintf(buf,"PSF");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_IC,DST_MASKALLB))
    {
        sprintf(buf,"IC");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_ACC,DST_MASKALLB))
    {
        sprintf(buf,"ACC");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_PFX_N,DST_MASK3_6B))
    {
        sprintf(buf,"PFX[%d]",get_dst_3nb(code));
        *prefix_on = true;
        return decode_success;
    }

    if(determine_masked_dst(code,DST_A_PP_SP,DST_MASKALLB))
    {
        sprintf(buf,"@++SP");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_IV,DST_MASKALLB))
    {
        sprintf(buf,"IV");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_LC_N,DST_MASK0_1_3_6B))
    {
        sprintf(buf,"LC[%d]",get_dst_1na(code));
        return decode_success;
    }

    if(determine_masked_dst(code,DST_BP_OFFS,DST_MASKALLB))
    {
        sprintf(buf,"@BP[Offs]");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_BP_DD_OFFS,DST_MASKALLB))
    {
        sprintf(buf,"@BP[--Offs]");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_OFFS,DST_MASKALLB))
    {
        sprintf(buf,"OFFS");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_DPC,DST_MASKALLB))
    {
        sprintf(buf,"DPC");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_GR,DST_MASKALLB))
    {
        sprintf(buf,"GR");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_GRL,DST_MASKALLB))
    {
        sprintf(buf,"GRL");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_BP,DST_MASKALLB))
    {
        sprintf(buf,"BP");
        return decode_success;
    }

    if(determine_masked_dst(code,DST_A_DP_N,DST_MASK1_6B))
    {
        sprintf(buf,"@DP[%d]",get_dst_1nb(code));
        return decode_success;
    }

    if(determine_masked_dst(code,DST_A_PP_DP_N,DST_MASK1_6B))
    {
        sprintf(buf,"@++DP[%d]",get_dst_1nb(code));
        return decode_success;
    }

    if(determine_masked_dst(code,DST_A_DD_DP_N,DST_MASK1_6B))
    {
        sprintf(buf,"@--DP[%d]",get_dst_1nb(code));
        return decode_success;
    }

    if(determine_masked_dst(code,DST_DP_N,DST_MASK1_6B))
    {
        sprintf(buf,"DP[%d]",get_dst_1nb(code));
        return decode_success;
    }

    return decode_unknown;
}
