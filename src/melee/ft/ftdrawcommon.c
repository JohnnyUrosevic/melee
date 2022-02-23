#include "ftdrawcommon.h"
#include "variables.h"
#include <dolphin/types.h>
#include "sysdolphin/baselib/jobj.h"

typedef struct _Unk {
    u8 filler[0x20];
    HSD_GObj* data;
} Unk;

typedef struct _Unk2 {
    u8 x0_filler[0x14];
    u32 x14;
    u8 x18_filler[0x44-0x18];
    u32 x44;
    u8 x48_filler[0x6C-0x3C];
} Unk2;

extern Unk* lbl_804D782C;

void func_80080E18(HSD_GObj* gobj, s32 arg1) {
    Unk2 sp54;
    s32 ret;
    s32 flags;
    Vec* pos;
    HSD_JObj* jobj;
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
                if (jobj == NULL) {
                    __assert("jobj.h", 0x394, "jobj");
                }
                if (pos == NULL) {
                    __assert("jobj.h", 0x395, "translate");
                }
                __memcpy(&jobj->translate.x, &pos->x, 8);
                __memcpy(&jobj->translate.z, &pos->z, 4);

                if ((jobj->flags & 0x02000000) == 0 && jobj != NULL) { 
                    if (jobj == NULL) // why...
                    {
                        __assert("jobj.h", 0x234, "jobj");
                    }

                    flags = jobj->flags;
                    arg2 = 0;
                    if (((flags & 0x800000) == 0) && ((flags & 0x40) != 0)) {
                        arg2 = 1;
                    }
                    if (arg2 == 0) {
                        HSD_JObjSetMtxDirtySub(jobj, jobj->flags);
                    }
                }
            }
            if (fighter->x5C8 != 0U) {
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
                        arg2 = func_8008051C(gobj, &sp54.x44);
                        func_803709DC(fighter, arg2, ret, 0);
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
                        arg2 = func_8008051C(gobj, &sp54.x14);
                        func_803709DC(fighter, arg2, ret, 0);
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
            break;
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
