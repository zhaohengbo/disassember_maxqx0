#ifndef SRC_DECODE_PVT_H_INCLUDED
#define SRC_DECODE_PVT_H_INCLUDED

#define SRC_4N_MASK         0b011110000
#define SRC_3N_MASK         0b000000111
#define SRC_1NA_MASK        0b000010000
#define SRC_1NB_MASK        0b001000000

#define SRC_MASK0B          0b100000000
#define SRC_MASK0_5B        0b100001000
#define SRC_MASK0_3_5_9B    0b111101111
#define SRC_MASK0_1_3_9B    0b110111111
#define SRC_MASK0_5_9B      0b100001111
#define SRC_MASKALLB        0b111111111

#define SRC_CONSTANT        0b000000000//SRC_MASK0B
#define SRC_MN_N            0b100000000//SRC_MASK0_5B
#define SRC_AP              0b100001000
#define SRC_APC             0b100011000
#define SRC_PSF             0b101001000
#define SRC_IC              0b101011000
#define SRC_IMR             0b101101000
#define SRC_SC              0b110001000
#define SRC_IIR             0b110111000
#define SRC_CKCN            0b111101000
#define SRC_WDCN            0b111111000
#define SRC_A_N             0b100001001//SRC_MASK0_5_9B
#define SRC_ACC             0b100001010
#define SRC_A_AP            0b100011010
#define SRC_IP              0b100001100
#define SRC_A_SP_DD         0b100001101
#define SRC_SP              0b100011101
#define SRC_IV              0b100101101
#define SRC_LC_N            0b101101101//SRC_MASK0_3_5_9B
#define SRC_A_SPI_DD        0b110001101
#define SRC_A_BP_OFFS       0b100001110
#define SRC_A_BP_OFFS_PP    0b100011110
#define SRC_A_BP_OFFS_DD    0b100101110
#define SRC_OFFS            0b100111110
#define SRC_DPC             0b101001110
#define SRC_GR              0b101011110
#define SRC_GRL             0b101101110
#define SRC_BP              0b101111110
#define SRC_GRS             0b110001110
#define SRC_GRH             0b110011110
#define SRC_GRXL            0b110101110
#define SRC_FP              0b110111110
#define SRC_A_DP_N          0b100001111//SRC_MASK0_1_3_9B
#define SRC_A_DP_N_PP       0b100011111//SRC_MASK0_1_3_9B
#define SRC_A_DP_N_DD       0b100101111//SRC_MASK0_1_3_9B
#define SRC_DP_N            0b100111111//SRC_MASK0_1_3_9B

#endif // SRC_DECODE_PVT_H_INCLUDED
