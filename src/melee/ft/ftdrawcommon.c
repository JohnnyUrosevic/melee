#include "ftdrawcommon.h"
#include "variables.h"
#include <dolphin/types.h>
#include "sysdolphin/baselib/jobj.h"

typedef struct _Unk {
    u8 filler[0x20];
    HSD_GObj* data;
} Unk;

typedef struct _UnkMatrix {
    u8 x0_filler[0xC];
    Mtx xC;
    Mtx x38;
    u8 x48_filler[0x68-0x3C];
} UnkMatrix;

// TODO REMOVE THIS AND REBASE
#pragma always_inline on
inline BOOL HSD_JObjMtxIsDirty(HSD_JObj* jobj)
{
    BOOL result;

    if (jobj == NULL) {
        __assert("jobj.h", 564, "jobj");
    }
    result = FALSE;
    if ((jobj->flags & 0x800000) == 0 && (jobj->flags & 0x40) != 0) {
        result = TRUE;
    }
    return result;
}

inline void HSD_JObjSetMtxDirty(HSD_JObj* jobj)
{
    if (jobj != NULL && HSD_JObjMtxIsDirty(jobj) == 0) {
        HSD_JObjSetMtxDirtySub(jobj);
    }
}

inline HSD_JObjSetTranslate(HSD_JObj* jobj, Vec* vec)
{
    if (jobj == NULL) {
        __assert("jobj.h", 0x394, "jobj");
    }
    if (vec == NULL) {
        __assert("jobj.h", 0x395, "translate");
    }

    jobj->translate = *vec;

    if ((jobj->flags & 0x2000000) == 0) {
        HSD_JObjSetMtxDirty(jobj);
    }
}

static inline mtx_thing(MtxPtr mtx, Vec* ptr, f32 val, f32 val2)
{
    mtx[0][3] = ptr->x + val;
    mtx[1][3] = ptr->y + val;
    mtx[2][3] = ptr->z + val2;
}

extern Unk* lbl_804D782C;

MtxPtr func_8008051C(HSD_GObj* gobj, MtxPtr arg2) {
    u8 pad2[0x4];

    Vec sp54;

    u8 pad1[0xC];

    Mtx sp18;

    u8 pad0[0x8];

    f32 temp_f31;
    f32 temp_f0;

    s32 temp_r31;

    temp_f31 = temp_f0 = 0.0f;
    sp54.z = temp_f31;
    sp54.y = temp_f31;
    sp54.x = temp_f31;
    if (func_80087074(gobj, &sp54) != 0) {
        temp_r31 = func_8036A288() + 0x54;
        PSMTXIdentity(sp18);

        mtx_thing(sp18, &sp54, temp_f31, temp_f0);

        PSMTXConcat(temp_r31, sp18, arg2);
        return arg2;
    }

    return NULL;
}

void func_80080E18(HSD_GObj* gobj, s32 arg1) {
    UnkMatrix sp54;
    s32 ret;
    s32 flags;
    Vec* pos;
    HSD_JObj* jobj;
    MtxPtr returnedMtx;
    s32 arg2;
    MtxPtr matrix;

    Fighter* fighter2;
    Fighter* fighter;
    fighter = fighter2 = gobj->user_data;
    if (fighter->x221F_flag.bits.b3 == 0 && func_80086A8C(gobj)) {
        ret = func_80031060();

        switch (ret)
        {
        case 1:
            if (fighter->x2220_flag.bits.b7) {
                fighter2 = gobj->user_data;
                jobj = (HSD_JObj *) gobj->hsd_obj;

                func_800310B8();
                matrix = func_80369808();
                PSMTXMultiVec(matrix, &fighter->x2350_stateVar5, &fighter2->xB0_pos);
                pos = &fighter2->xB0_pos;

                HSD_JObjSetTranslate(jobj, pos);
            }
            if (fighter->x5C8 != NULL) {
                fighter = gobj->user_data;
                if ((fighter->x21FC_flag.bits.b7) != 0) {
                    if ((fighter->x221E_flag.bits.b0 == 0) && (fighter->x221E_flag.bits.b5 == 0) && (fighter->x2226_flag.bits.b5 == 0)) {
                        func_800750C8(fighter, 0, 0);
                        func_800750C8(fighter, 1, 0);
                        func_800750C8(fighter, 2, 0);
                        func_800750C8(fighter, 4, 1);
                        fighter->x2223_flag.bits.b2 = 1;
                        fighter->x2223_flag.bits.b3 = 0;
                        fighter = (Fighter*) gobj->hsd_obj;
                        ret = func_80390EB8(arg1);
                        returnedMtx = func_8008051C(gobj, sp54.x38);
                        func_803709DC(fighter, returnedMtx, ret, 0);
                    }
                }
                func_800805C8(gobj, arg1, 1);
                fighter = gobj->user_data;
                if (fighter->x21FC_flag.bits.b7 != 0) {
                    if ((fighter->x221E_flag.bits.b0 == 0) && (fighter->x221E_flag.bits.b5 == 0) && (fighter->x2226_flag.bits.b5 == 0)) {
                        func_800750C8(fighter, 0, 0);
                        func_800750C8(fighter, 1, 0);
                        func_800750C8(fighter, 2, 0);
                        func_800750C8(fighter, 4, 1);
                        fighter->x2223_flag.bits.b2 = 1;
                        fighter->x2223_flag.bits.b3 = 1;
                        fighter = (Fighter*) gobj->hsd_obj;
                        ret = func_80390EB8(arg1);
                        returnedMtx = func_8008051C(gobj, sp54.xC);
                        func_803709DC(fighter, returnedMtx, ret, 0);
                    }
                }
            }
            break;
        case 0:
            fighter->x2223_flag.bits.b3 = 0;
            if (fighter->x5C8 != 0U) {
                arg2 = 0;
            }
            else {
                arg2 = 1;
            }
            func_800805C8(gobj, arg1, arg2);
        }
    }
}

void func_80081118(void) {
    HSD_GObj* gobj = lbl_804D782C->data;

    while (gobj != NULL) {
        gobj->render_cb = &func_80080E18;
        gobj = gobj->next;
    }
}

void func_80081140(void)
{
    HSD_GObj* gobj = lbl_804D782C->data;

    while (gobj != NULL) {
        gobj->render_cb = &func_80080C28;
        gobj = gobj->next;
    }
}

void func_80081168(void)
{
    HSD_GObj* gobj = lbl_804D782C->data;
    Fighter* fighter = gobj->user_data; // why load this twice?

    u32 unused[3];

    while (gobj != NULL) {
        fighter = gobj->user_data;
        if (fighter->x5BC != 0U) {
            func_800750C8(fighter, 1, 0);
            func_800750C8(fighter, 2, 0);
            func_800750C8(fighter, 4, 0);
            func_800750C8(fighter, 0, 1);
        }
        gobj = gobj->next;
    }
}

void func_80081200(void)
{
    HSD_GObj* gobj = lbl_804D782C->data;
    Fighter* fighter = gobj->user_data; // why load this twice?

    u32 unused[3];

    while (gobj != NULL) {
        fighter = gobj->user_data;
        if (fighter->x5BC != 0U) {
            func_800750C8(fighter, 0, 0);
            func_800750C8(fighter, 2, 0);
            func_800750C8(fighter, 4, 0);
            func_800750C8(fighter, 1, 1);
        }
        gobj = gobj->next;
    }
}
