/*
 * ewfinput
 * User input functions for the libewf tools
 *
 * Copyright (c) 2006-2008, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the creator, related organisations, nor the names of
 *   its contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER, COMPANY AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined( _EWFINPUT_H )
#define _EWFINPUT_H

#include <common.h>
#include <character_string.h>
#include <system_string.h>

#include <libewf/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

#define EWFINPUT_COMPRESSION_LEVELS_AMOUNT		3
#define EWFINPUT_COMPRESSION_LEVELS_DEFAULT		0

#define EWFINPUT_FORMAT_TYPES_AMOUNT			12
#define EWFINPUT_FORMAT_TYPES_DEFAULT			7

#if defined( LIBEWF_CD_SUPPORT )
#define EWFINPUT_MEDIA_TYPES_AMOUNT			3
#else
#define EWFINPUT_MEDIA_TYPES_AMOUNT			2
#endif
#define EWFINPUT_MEDIA_TYPES_DEFAULT			0

#define EWFINPUT_VOLUME_TYPES_AMOUNT			2
#define EWFINPUT_VOLUME_TYPES_DEFAULT			1

#define EWFINPUT_SECTOR_PER_BLOCK_SIZES_AMOUNT		10
#define EWFINPUT_SECTOR_PER_BLOCK_SIZES_DEFAULT		0

extern character_t *ewfinput_compression_levels[ 3 ];
extern character_t *ewfinput_format_types[ 12 ];
#if defined( LIBEWF_CD_SUPPORT )
extern character_t *ewfinput_media_types[ 3 ];
#else
extern character_t *ewfinput_media_types[ 2 ];
#endif
extern character_t *ewfinput_volume_types[ 2 ];
extern character_t *ewfinput_sector_per_block_sizes[ 10 ];
extern character_t *ewfinput_yes_no[ 2 ];

uint8_t ewfinput_determine_libewf_format(
         const character_t *argument );

uint8_t ewfinput_determine_libewf_format_char_t(
         const system_character_t *argument );

uint32_t ewfinput_determine_sectors_per_chunk(
          const character_t *argument );

uint32_t ewfinput_determine_sectors_per_chunk_char_t(
          const system_character_t *argument );

int8_t ewfinput_determine_compression_level(
        const character_t *argument );

int8_t ewfinput_determine_compression_level_char_t(
        const system_character_t *argument );

int8_t ewfinput_determine_media_type(
        const character_t *argument );

int8_t ewfinput_determine_volume_type(
        const character_t *argument );

int8_t ewfinput_determine_yes_no(
        const character_t *argument );

character_t *ewfinput_get_variable(
              FILE *stream,
              character_t *request_string );

system_character_t *ewfinput_get_variable_char_t(
                     FILE *stream,
                     character_t *request_string );

uint64_t ewfinput_get_size_variable(
          FILE *stream,
          character_t *request_string,
          uint64_t minimum,
          uint64_t maximum,
          uint64_t default_value );

uint64_t ewfinput_get_byte_size_variable(
          FILE *stream,
          character_t *request_string,
          uint64_t minimum,
          uint64_t maximum,
          uint64_t default_value );

character_t *ewfinput_get_fixed_value(
              FILE *stream,
              character_t *request_string,
              character_t **values,
              uint8_t amount,
              uint8_t default_value );

#if defined( __cplusplus )
}
#endif

#endif

