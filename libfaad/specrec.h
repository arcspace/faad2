/*
** FAAD2 - Freeware Advanced Audio (AAC) Decoder including SBR decoding
** Copyright (C) 2003 M. Bakker, Ahead Software AG, http://www.nero.com
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
**
** Any non-GPL usage of this software or parts of this software is strictly
** forbidden.
**
** Commercial non-GPL licensing of this software is possible.
** For more info contact Ahead Software through Mpeg4AAClicense@nero.com.
**
** $Id: specrec.h,v 1.21 2003/12/17 14:43:16 menno Exp $
**/

#ifndef __SPECREC_H__
#define __SPECREC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "syntax.h"

uint8_t window_grouping_info(faacDecHandle hDecoder, ic_stream *ics);
static void quant_to_spec(ic_stream *ics, real_t *spec_data, uint16_t frame_len);
static void inverse_quantization(real_t *x_invquant, const int16_t *x_quant, const uint16_t frame_len);
void apply_scalefactors(faacDecHandle hDecoder, ic_stream *ics, real_t *x_invquant,
                        uint16_t frame_len);
#ifdef USE_SSE
void apply_scalefactors_sse(faacDecHandle hDecoder, ic_stream *ics, real_t *x_invquant,
                            uint16_t frame_len);
#endif
void reconstruct_channel_pair(faacDecHandle hDecoder, ic_stream *ics1, ic_stream *ics2,
                              element *cpe, int16_t *spec_data1, int16_t *spec_data2);
void reconstruct_single_channel(faacDecHandle hDecoder, ic_stream *ics, element *sce,
                                int16_t *spec_data);

#ifdef __cplusplus
}
#endif
#endif
