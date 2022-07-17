#ifndef _ftdrawcommon_h_
#define _ftdrawcommon_h_

#include <global.h>

#include <dolphin/types.h>

#include "sysdolphin/baselib/gobj.h"

#include "melee/ft/fighter.h"

MtxPtr func_8008051C(HSD_GObj* gobj, MtxPtr arg2);
void func_800805C8(HSD_GObj* gobj, u32 arg1, u32 arg2);
void func_80080C28(HSD_GObj* gobj, s32 arg1);
void func_80080C28(HSD_GObj* arg0, s32 arg1);
void func_80080E18(HSD_GObj* arg0, s32 arg1);

void func_80081118(void);
void func_80081140(void);
void func_80081168(void);
void func_80081200(void);

#endif
