/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2019-2021 Paul Cercueil <paul@crapouillou.net>
 */

#ifndef __LIGHTREC_INTERPRETER_H__
#define __LIGHTREC_INTERPRETER_H__

#include "lightrec.h"

struct block;

u32 lightrec_emulate_block(struct block *block, u32 pc);

#endif /* __LIGHTREC_INTERPRETER_H__ */
