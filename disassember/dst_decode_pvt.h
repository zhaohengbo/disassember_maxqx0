#ifndef DST_DECODE_PVT_H_INCLUDED
#define DST_DECODE_PVT_H_INCLUDED

#define DST_3NA_MASK        0b1110000
#define DST_3NB_MASK        0b0000111
#define DST_1NA_MASK        0b0010000
#define DST_1NB_MASK        0b1000000

#define DST_MASK3B          0b0001000
#define DST_MASK3_6B        0b0001111
#define DST_MASK1_6B        0b0111111
#define DST_MASK0_1_3_6B    0b1101111
#define DST_MASKALLB        0b1111111

#define DST_NUL             0b1110110
#define DST_MN_N            0b0000000//DST_MASK3B
#define DST_AP              0b0001000
#define DST_APC             0b0011000
#define DST_PSF             0b1001000
#define DST_IC              0b1011000
#define DST_IMR             0b1101000
#define DST_A_N             0b0001001//DST_MASK3_6B
#define DST_ACC             0b0001010
#define DST_PFX_N           0b0001011//DST_MASK3_6B
#define DST_A_PP_SP         0b0001101
#define DST_IV              0b0011101
#define DST_LC_N            0b1101101//DST_MASK0_1_3_6B
#define DST_BP_OFFS         0b0001110
#define DST_BP_PP_OFFS      0b0011110
#define DST_BP_DD_OFFS      0b0101110
#define DST_OFFS            0b0111110
#define DST_DPC             0b1001110
#define DST_GR              0b1011110
#define DST_GRL             0b1101110
#define DST_BP              0b1111110
#define DST_A_DP_N          0b0001111//DST_MASK1_6B
#define DST_A_PP_DP_N       0b0011111//DST_MASK1_6B
#define DST_A_DD_DP_N       0b0101111//DST_MASK1_6B
#define DST_DP_N            0b0111111//DST_MASK1_6B

//2-CYCLE DESTINATION ACCESS USING PFX[n] REGISTER
#define DST_SC              0b0001000
#define DST_CKCN            0b1101000
#define DST_WDCN            0b1111000
#define DST_A_N_2           0b0001001//DST_MASK3_6B
#define DST_GRH             0b0011110

#endif // DST_DECODE_PVT_H_INCLUDED
