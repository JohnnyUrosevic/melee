#include "ftdrawcommon.h"
#include "variables.h"
#include <dolphin/types.h>

typedef struct _Unk {
    u8 filler[0x20];
    HSD_GObj* data;
} Unk;

extern Unk* lbl_804D782C;

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
