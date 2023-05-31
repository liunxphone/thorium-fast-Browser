/*
 * Musepack decoder
 * Copyright (c) 2006 Konstantin Shishkov
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_MPC7DATA_H
#define AVCODEC_MPC7DATA_H

#include <stdint.h>

static const int8_t mpc7_idx30[] = { -1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1};
static const int8_t mpc7_idx31[] = { -1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1};
static const int8_t mpc7_idx32[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
static const int8_t mpc7_idx50[] = { -2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2,-2,-1, 0, 1, 2};
static const int8_t mpc7_idx51[] = { -2,-2,-2,-2,-2,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};

#define MPC7_SCFI_SIZE  4
#define MPC7_SCFI_BITS  3
static const uint8_t mpc7_scfi[MPC7_SCFI_SIZE * 2] = {
    0x03, 2, 0x00, 3, 0x02, 3, 0x01, 1,
};

#define MPC7_DSCF_SIZE 16
#define MPC7_DSCF_BITS  6
static const uint8_t mpc7_dscf[MPC7_DSCF_SIZE * 2] = {
    0x05, 3, 0x01, 5, 0x0D, 5, 0x0B, 4, 0x09, 3, 0x06, 3, 0x00, 6, 0x0E, 6,
    0x02, 5, 0x07, 4, 0x08, 3, 0x0F, 4, 0x04, 4, 0x0A, 4, 0x03, 5, 0x0C, 5,
};

#define MPC7_HDR_SIZE  10
#define MPC7_HDR_BITS   9
static const uint8_t mpc7_hdr[MPC7_HDR_SIZE * 2] = {
    0x04, 2, 0x03, 4, 0x02, 5, 0x07, 6, 0x00, 8,
    0x09, 9, 0x08, 9, 0x01, 7, 0x06, 3, 0x05, 1,
};

#define MPC7_QUANT_VLC_TABLES 7
static const uint8_t mpc7_quant_vlc_sizes[MPC7_QUANT_VLC_TABLES] = {
    27, 25, 7, 9, 15, 31, 63
};

static const int8_t mpc7_quant_vlc_off[MPC7_QUANT_VLC_TABLES] = {
    0, 0, -3, -4, -7, -15, -31
};

static const uint8_t mpc7_quant_vlcs[177 * 2 * 2] = {
    /* quant_vlc[0][0] - 27 entries */
    0x07,  5, 0x13,  5, 0x17,  5, 0x0F,  5, 0x0B,  5, 0x03,  5, 0x15,  5,
    0x05,  5, 0x19,  5, 0x01,  5, 0x09,  5, 0x11,  5, 0x0A,  4, 0x10,  4,
    0x02,  6, 0x18,  6, 0x12,  6, 0x08,  6, 0x16,  4, 0x04,  4, 0x0C,  4,
    0x0E,  4, 0x06,  6, 0x14,  6, 0x00,  6, 0x1A,  6, 0x0D,  3,
    /* quant_vlc[0][1] - 27 entries */
    0x0A,  4, 0x10,  4, 0x16,  4, 0x04,  4, 0x0C,  4, 0x0E,  4, 0x09,  6,
    0x14,  8, 0x06,  8, 0x1A,  8, 0x00,  8, 0x05,  7, 0x15,  7, 0x17,  7,
    0x03,  7, 0x18,  9, 0x02,  9, 0x12,  9, 0x08,  9, 0x13,  7, 0x19,  7,
    0x11,  7, 0x07,  7, 0x0B,  7, 0x01,  7, 0x0F,  7, 0x0D,  1,
    /* quant_vlc[1][0] - 25 entries */
    0x03,  5, 0x13,  5, 0x15,  5, 0x0F,  5, 0x05,  5, 0x09,  5, 0x10,  4,
    0x08,  4, 0x12,  4, 0x06,  4, 0x0E,  5, 0x02,  5, 0x0C,  3, 0x0A,  5,
    0x16,  5, 0x18,  7, 0x00,  7, 0x14,  7, 0x04,  7, 0x17,  6, 0x01,  6,
    0x0B,  4, 0x07,  4, 0x11,  4, 0x0D,  4,
    /* quant_vlc[1][1] - 25 entries */
    0x07,  3, 0x0B,  3, 0x11,  3, 0x0D,  3, 0x0C,  2, 0x16,  6, 0x0E,  6,
    0x0A,  6, 0x02,  6, 0x05,  7, 0x09,  7, 0x15,  7, 0x0F,  7, 0x10,  5,
    0x13,  7, 0x01,  7, 0x17,  7, 0x14, 10, 0x00, 10, 0x04, 10, 0x18, 10,
    0x03,  8, 0x08,  5, 0x06,  5, 0x12,  5,
    /* quant_vlc[2][0] - 7 entries */
    0x02,  2, 0x03,  2, 0x01,  3, 0x05,  3, 0x00,  4, 0x06,  4, 0x04,  3,
    /* quant_vlc[2][1] - 7 entries */
    0x05,  3, 0x00,  5, 0x06,  5, 0x01,  4, 0x04,  2, 0x02,  2, 0x03,  2,
    /* quant_vlc[3][0] - 9 entries */
    0x01,  3, 0x07,  3, 0x08,  4, 0x00,  4, 0x06,  3, 0x02,  3, 0x05,  3,
    0x03,  3, 0x04,  3,
    /* quant_vlc[3][1] - 9 entries */
    0x03,  2, 0x08,  5, 0x00,  5, 0x07,  4, 0x02,  3, 0x04,  2, 0x01,  4,
    0x06,  4, 0x05,  3,
    /* quant_vlc[4][0] - 15 entries */
    0x05,  3, 0x08,  3, 0x06,  3, 0x07,  3, 0x02,  4, 0x0B,  4, 0x03,  4,
    0x0D,  5, 0x01,  5, 0x0A,  4, 0x04,  4, 0x0E,  6, 0x00,  6, 0x0C,  5,
    0x09,  4,
    /* quant_vlc[4][1] - 15 entries */
    0x04,  3, 0x03,  4, 0x0C,  5, 0x02,  5, 0x09,  3, 0x05,  3, 0x08,  3,
    0x06,  3, 0x07,  3, 0x01,  6, 0x0E,  8, 0x00,  8, 0x0D,  7, 0x0B,  5,
    0x0A,  4,
    /* quant_vlc[5][0] - 31 entries */
    0x0C,  4, 0x1A,  5, 0x01,  6, 0x1D,  6, 0x0D,  4, 0x10,  4, 0x11,  4,
    0x0E,  4, 0x19,  5, 0x05,  5, 0x0F,  4, 0x1E,  7, 0x00,  7, 0x1C,  6,
    0x06,  5, 0x18,  5, 0x07,  5, 0x17,  5, 0x09,  5, 0x02,  6, 0x03,  6,
    0x08,  5, 0x16,  5, 0x14,  5, 0x0A,  5, 0x15,  5, 0x13,  5, 0x1B,  6,
    0x04,  6, 0x0B,  5, 0x12,  5,
    /* quant_vlc[5][1] - 31 entries */
    0x0F,  3, 0x0A,  4, 0x14,  4, 0x17,  5, 0x07,  5, 0x13,  4, 0x0B,  4,
    0x16,  5, 0x08,  5, 0x0C,  4, 0x12,  4, 0x11,  4, 0x0D,  4, 0x18,  6,
    0x06,  6, 0x1B,  8, 0x1A,  8, 0x02, 10, 0x00, 13, 0x1D, 13, 0x01, 13,
    0x1E, 13, 0x1C, 11, 0x03,  9, 0x04,  8, 0x05,  7, 0x19,  7, 0x0E,  4,
    0x10,  4, 0x15,  5, 0x09,  5,
    /* quant_vlc[6][0] - 63 entries */
    0x18,  5, 0x25,  5, 0x19,  5, 0x24,  5, 0x23,  5, 0x1B,  5, 0x1D,  5,
    0x1F,  5, 0x22,  5, 0x1C,  5, 0x1A,  5, 0x20,  5, 0x0B,  6, 0x3A,  7,
    0x3E,  8, 0x00,  8, 0x1E,  5, 0x33,  6, 0x0C,  6, 0x21,  5, 0x04,  7,
    0x05,  7, 0x32,  6, 0x39,  7, 0x38,  7, 0x0D,  6, 0x31,  6, 0x0E,  6,
    0x3D,  8, 0x01,  8, 0x06,  7, 0x30,  6, 0x37,  7, 0x07,  7, 0x0F,  6,
    0x2F,  6, 0x2E,  6, 0x10,  6, 0x3C,  8, 0x02,  8, 0x08,  7, 0x11,  6,
    0x2D,  6, 0x2C,  6, 0x13,  6, 0x36,  7, 0x35,  7, 0x12,  6, 0x2B,  6,
    0x29,  6, 0x14,  6, 0x15,  6, 0x0A,  7, 0x09,  7, 0x16,  6, 0x3B,  8,
    0x03,  8, 0x34,  7, 0x2A,  6, 0x17,  6, 0x28,  6, 0x27,  6, 0x26,  6,
    /* quant_vlc[6][1] - 63 entries */
    0x20,  4, 0x2A,  5, 0x15,  5, 0x1F,  4, 0x29,  5, 0x0F,  6, 0x2F,  6,
    0x28,  5, 0x16,  5, 0x07,  9, 0x36,  9, 0x08,  9, 0x39, 10, 0x38, 10,
    0x32,  7, 0x2E,  6, 0x17,  5, 0x10,  6, 0x11,  6, 0x27,  5, 0x26,  5,
    0x0C,  7, 0x0A,  8, 0x34,  8, 0x2D,  6, 0x18,  5, 0x12,  6, 0x2C,  6,
    0x31,  7, 0x0D,  7, 0x13,  6, 0x19,  5, 0x25,  5, 0x1A,  5, 0x24,  5,
    0x2B,  6, 0x05, 10, 0x06, 10, 0x35,  9, 0x33,  8, 0x30,  7, 0x1B,  5,
    0x23,  5, 0x1C,  5, 0x14,  6, 0x0E,  7, 0x09,  9, 0x3A, 12, 0x00, 14,
    0x3E, 14, 0x02, 14, 0x3C, 14, 0x04, 12, 0x3D, 14, 0x01, 14, 0x03, 14,
    0x3B, 14, 0x37, 10, 0x0B,  8, 0x22,  5, 0x1D,  5, 0x21,  5, 0x1E,  5,
};

#endif /* AVCODEC_MPC7DATA_H */