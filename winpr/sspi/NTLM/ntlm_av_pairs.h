/**
 * WinPR: Windows Portable Runtime
 * NTLM Security Package (AV_PAIRs)
 *
 * Copyright 2011-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINPR_SSPI_NTLM_AV_PAIRS_H
#define WINPR_SSPI_NTLM_AV_PAIRS_H

#include "ntlm.h"

#include <winpr/stream.h>

void ntlm_av_pair_list_init(NTLM_AV_PAIR* pAvPairList);
ULONG ntlm_av_pair_list_size(ULONG AvPairsCount, ULONG AvPairsValueLength);
PBYTE ntlm_av_pair_get_value_pointer(NTLM_AV_PAIR* pAvPair);
int ntlm_av_pair_get_next_offset(NTLM_AV_PAIR* pAvPair);
NTLM_AV_PAIR* ntlm_av_pair_get_next_pointer(NTLM_AV_PAIR* pAvPair);
NTLM_AV_PAIR* ntlm_av_pair_get(NTLM_AV_PAIR* pAvPairList, AV_ID AvId, LONG AvPairListSize);
NTLM_AV_PAIR* ntlm_av_pair_add(NTLM_AV_PAIR* pAvPairList, AV_ID AvId, PUNICODE_STRING pValue, LONG AvPairListSize);

void ntlm_construct_server_target_info(NTLM_CONTEXT* context);

void ntlm_input_av_pairs(NTLM_CONTEXT* context, PStream s);
void ntlm_output_av_pairs(NTLM_CONTEXT* context, PSecBuffer buffer);
void ntlm_populate_av_pairs(NTLM_CONTEXT* context);
void ntlm_populate_server_av_pairs(NTLM_CONTEXT* context);
void ntlm_print_av_pairs(NTLM_CONTEXT* context);
void ntlm_free_av_pairs(NTLM_CONTEXT* context);

#endif /* WINPR_SSPI_NTLM_AV_PAIRS_H */
