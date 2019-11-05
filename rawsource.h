/*
  rawsource.h: Raw Format Reader for VapourSynth

  This file is a part of vsrawsource

  Copyright (C) 2016  Oka Motofumi et al

  Authors: Oka Motofumi (chikuzen.mo at gmail dot com)
           Skylar Moore (github.com/IFeelBloated)
           Fredrik Mellbin (github.com/myrsloik)
           Darrell Walisser (my.name at gmail dot com)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with Libav; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/


#ifndef VS_RAW_SOURCE_H
#define VS_RAW_SOURCE_H

#define VS_RAWS_VERSION "0.3.5"

#ifdef _WIN32
#ifdef __MINGW32__
#define rs_fseek fseeko64
#define rs_ftell ftello64
#else
#pragma warning(disable:4996)
#define rs_fseek _fseeki64
#define rs_ftell _ftelli64
#define strcasecmp _stricmp
#define S_IFIFO _S_IFIFO
#endif
#define WINVER       0x0500
#define _WIN32_WINNT 0x0500
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <io.h>       /* _setmode() */
#include <fcntl.h>    /* _O_BINARY */
#include <string.h>
#else
#include <strings.h>
#endif

#include <stdio.h>

#ifndef rs_fseek
#define rs_fseek fseek
#define rs_ftell ftell
#endif

#include <stdlib.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <inttypes.h>

typedef struct {
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t num_planes;
    uint16_t bits_per_pixel;
    uint32_t fourcc;
    uint32_t image_size;
    int32_t pix_per_meter_h;
    int32_t pix_per_meter_v;
    uint32_t num_palette;
    uint32_t indx_palette;
} bmp_info_header_t;


#endif /* VS_RAW_SOURCE_H */
