#include "decode.h"

#include "ins_decode.h"
#include "ins_decode_pvt.h"

#include "src_decode.h"
#include "dst_decode.h"

static inline bool determine_masked_code(uint16_t code,uint16_t ins_code,uint16_t mask)
{
    return ((code & mask) == ins_code);
}

static inline uint16_t get_ins_src(uint16_t code)
{
    uint8_t up,down;
    uint16_t src_code;
    code &= ISN_SRC_MASK;
    up = code >> 15;
    down = code;
    src_code = ((uint16_t)up << 8) | down;
    return src_code;
}

static inline uint16_t get_ins_dst(uint16_t code)
{
    code &= ISN_DST_MASK;
    code = code >> 8;
    return code;
}

static inline uint16_t get_ins_4b(uint16_t code)
{
    code &= ISN_4B_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_ins_3ba(uint16_t code)
{
    code &= ISN_3BA_MASK;
    code = code >> 4;
    return code;
}

static inline uint16_t get_ins_3bb(uint16_t code)
{
    code &= ISN_3BB_MASK;
    code = code >> 12;
    return code;
}

static inline uint16_t get_ins_1n(uint16_t code)
{
    code &= ISN_1N_MASK;
    code = code >> 12;
    return code;
}

decode_status maxqx0_ins_decode(uint16_t code,char * buf,bool *prefix_on)
{
    char src_buf[128];
    char dst_buf[128];
    bool prefix_old = *prefix_on;
    bool prefix_temp = *prefix_on;
    *prefix_on = false;

    if(determine_masked_code(code,INS_NOP,INS_MASKALLB))
    {
        sprintf(buf,"NOP");
        return decode_success;
    }

    if(determine_masked_code(code,INS_CPL,INS_MASKALLB))
    {
        sprintf(buf,"CPL\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_NEG,INS_MASKALLB))
    {
        sprintf(buf,"NEG\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SLA,INS_MASKALLB))
    {
        sprintf(buf,"SLA\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SLA2,INS_MASKALLB))
    {
        sprintf(buf,"SLA2\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SLA4,INS_MASKALLB))
    {
        sprintf(buf,"SLA4\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RL,INS_MASKALLB))
    {
        sprintf(buf,"RL\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RL,INS_MASKALLB))
    {
        sprintf(buf,"RLC\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SRA,INS_MASKALLB))
    {
        sprintf(buf,"SRA\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SRA2,INS_MASKALLB))
    {
        sprintf(buf,"SRA2\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SRA4,INS_MASKALLB))
    {
        sprintf(buf,"SRA4\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_SR,INS_MASKALLB))
    {
        sprintf(buf,"SR\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RR,INS_MASKALLB))
    {
        sprintf(buf,"RR\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_MOVE_C_0,INS_MASKALLB))
    {
        sprintf(buf,"MOVE\tC,#0");
        return decode_success;
    }

    if(determine_masked_code(code,INS_MOVE_C_1,INS_MASKALLB))
    {
        sprintf(buf,"MOVE\tC,#1");
        return decode_success;
    }

    if(determine_masked_code(code,INS_CPL_C,INS_MASKALLB))
    {
        sprintf(buf,"CPL\tC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET,INS_MASKALLB))
    {
        sprintf(buf,"RET");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET_C,INS_MASKALLB))
    {
        sprintf(buf,"RET\tC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET_NC,INS_MASKALLB))
    {
        sprintf(buf,"RET\tNC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET_Z,INS_MASKALLB))
    {
        sprintf(buf,"RET\tZ");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET_NZ,INS_MASKALLB))
    {
        sprintf(buf,"RET\tNZ");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RET_S,INS_MASKALLB))
    {
        sprintf(buf,"RET\tS");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI,INS_MASKALLB))
    {
        sprintf(buf,"RETI");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI_C,INS_MASKALLB))
    {
        sprintf(buf,"RETI\tC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI_NC,INS_MASKALLB))
    {
        sprintf(buf,"RETI\tNC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI_Z,INS_MASKALLB))
    {
        sprintf(buf,"RETI\tZ");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI_NZ,INS_MASKALLB))
    {
        sprintf(buf,"RETI\tNZ");
        return decode_success;
    }

    if(determine_masked_code(code,INS_RETI_S,INS_MASKALLB))
    {
        sprintf(buf,"RETI\tS");
        return decode_success;
    }

    if(determine_masked_code(code,INS_XCH,INS_MASKALLB))
    {
        sprintf(buf,"XCH\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_XCHN,INS_MASKALLB))
    {
        sprintf(buf,"XCHN\tACC");
        return decode_success;
    }

    if(determine_masked_code(code,INS_AND_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"AND\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_OR_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"OR\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_XOR_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"XOR\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_MOVE_C_ACC_B,INS_MASK0_7_12_15B))
    {
        sprintf(buf,"MOVE\tC,ACC.<%d>",get_ins_4b(code));
        return decode_success;
    }

    if(determine_masked_code(code,INS_MOVE_ACC_B_C,INS_MASK0_7_12_15B))
    {
        sprintf(buf,"MOVE\tACC.<%d>,C",get_ins_4b(code));
        return decode_success;
    }

    if(determine_masked_code(code,INS_AND_ACC_B,INS_MASK0_7_12_15B))
    {
        sprintf(buf,"AND\tC,ACC.<%d>",get_ins_4b(code));
        return decode_success;
    }

    if(determine_masked_code(code,INS_OR_ACC_B,INS_MASK0_7_12_15B))
    {
        sprintf(buf,"OR\tC,ACC.<%d>",get_ins_4b(code));
        return decode_success;
    }

    if(determine_masked_code(code,INS_XOR_ACC_B,INS_MASK0_7_12_15B))
    {
        sprintf(buf,"XOR\tC,ACC.<%d>",get_ins_4b(code));
        return decode_success;
    }

    if(determine_masked_code(code,INS_MOVE_DST_B_1,INS_MASK0_7_12_15B))
    {
        prefix_temp = prefix_old;
        if(maxqx0_dst_decode(get_ins_dst(code),dst_buf,&prefix_temp) == decode_success)
        {
            sprintf(buf,"MOVE\t%s.<%d>, #1",dst_buf,get_ins_3ba(code));
            *prefix_on = prefix_temp;
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_MOVE_DST_B_0,INS_MASK0_7_12_15B))
    {
        prefix_temp = prefix_old;
        if(maxqx0_dst_decode(get_ins_dst(code),dst_buf,&prefix_temp) == decode_success)
        {
            sprintf(buf,"MOVE\t%s.<%d>, #0",dst_buf,get_ins_3ba(code));
            *prefix_on = prefix_temp;
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_MOVE_C_SRC_B,INS_MASK4_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"MOVE\tC,%s.<%d>",src_buf,get_ins_3bb(code));
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_ADD_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"ADD\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_ADDC_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"ADDC\tACC,%s",src_buf);;
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_SUB_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"SUB\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_SUBC_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"SUBC\tACC,%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\t%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\t%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_C_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tC,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tC,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_NC_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tNC,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tNC,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_Z_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tZ,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tZ,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_NZ_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tNZ,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tNZ,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_E_SRC,INS_MASK0_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tE,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tE,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_NE_SRC,INS_MASK0_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tNE,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tNE,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_JUMP_S_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LJUMP\tS,%s",src_buf);
            }
            else
            {
                sprintf(buf,"SJUMP\tS,%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_DJNZ_LC_N_SRC,INS_MASK1_2_4_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LDJNZ\tLC[%d],%s",get_ins_1n(code),src_buf);
            }
            else
            {
                sprintf(buf,"SDJNZ\tLC[%d],%s",get_ins_1n(code),src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_CALL_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            if(prefix_old)
            {
                sprintf(buf,"LCALL\t%s",src_buf);
            }
            else
            {
                sprintf(buf,"SCALL\t%s",src_buf);
            }
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_PUSH_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"PUSH\t%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_POP_DST,INS_MASK0_8_15B))
    {
        prefix_temp = prefix_old;
        if(maxqx0_dst_decode(get_ins_dst(code),dst_buf,&prefix_temp) == decode_success)
        {
            sprintf(buf,"POP\t%s",dst_buf);
            *prefix_on = prefix_temp;
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_POPI_DST,INS_MASK0_8_15B))
    {
        prefix_temp = prefix_old;
        if(maxqx0_dst_decode(get_ins_dst(code),dst_buf,&prefix_temp) == decode_success)
        {
            sprintf(buf,"POPI\t%s",dst_buf);
            *prefix_on = prefix_temp;
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_CMP_SRC,INS_MASK1_7B))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            sprintf(buf,"CMP\t%s",src_buf);
            return decode_success;
        }
    }

    if(determine_masked_code(code,INS_MOVE_DST_SRC,INS_MASKNONEB))
    {
        if(maxqx0_src_decode(get_ins_src(code),src_buf) == decode_success)
        {
            prefix_temp = prefix_old;
            if(maxqx0_dst_decode(get_ins_dst(code),dst_buf,&prefix_temp) == decode_success)
            {
                sprintf(buf,"MOVE\t%s,%s",dst_buf,src_buf);
                *prefix_on = prefix_temp;
                return decode_success;
            }
        }
        return decode_unknown;
    }
    return decode_error;
}

