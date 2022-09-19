#include <melee/ft/chara/ftYoshi/ftyoshi.h>
#include <melee/it/itkind.h>

extern f32 lbl_804D9A28;

void lbl_8012C030(HSD_GObj* fighter_gobj) {
    Fighter* fp;
    s32 bone_idx;
    Fighter* fp2;
    s32* x1CC;
    HSD_JObj* jobj;
    u32 unused[4];

    fp = getFighter(fighter_gobj);
    fp->x2340_f32 += lbl_804D9A28;
    func_80092BCC(fighter_gobj);
    if (func_800925A4(fighter_gobj) != 0) {

        fp = getFighter(fighter_gobj);
        func_80074B0C(fighter_gobj, 0, 0);
        func_8007B0C0(fighter_gobj, 0);

        x1CC = &fp->x110_attr.x1CC;
        bone_idx = func_8007500C(fp, 4);
        fp2 = getFighter(fighter_gobj);
        jobj = fp->x5E8_fighterBones[bone_idx].x0_jobj;

        efAsync_Spawn(fighter_gobj, &fp2->x60C, 4U, 0x4CFU, jobj, x1CC);
    }
    else if (ftAnim_IsFramesRemaining(fighter_gobj) == 0) {
        func_800928CC(fighter_gobj);
    }
    else {
        func_8012B8A4(fighter_gobj);
    }
}

void lbl_8012C114(HSD_GObj* fighter_gobj) {
    if (!func_80093694() &&
        !func_8009515C(fighter_gobj) &&
        !func_80099794(fighter_gobj) &&
        !func_8009917C(fighter_gobj) &&
        !func_800D8990(fighter_gobj) &&
        !func_8009A080(fighter_gobj)) {
        return;
    }
}

void lbl_8012C194(void) {
    func_80092870();
}

void lbl_8012C1B4(void) {
    func_800928AC();
}

extern f32 lbl_804D9A2C;
extern u8 lbl_803B75C0[];
void func_80091D58();
void func_80092450();
void func_8007B5AC();
void func_8006FA58();

#pragma push
asm unk_t func_8012C1D4()
{ // clang-format off
    nofralloc
func_8012C1D4:
/* 8012C1D4 00128DB4  7C 08 02 A6 */	mflr r0
/* 8012C1D8 00128DB8  38 80 01 56 */	li r4, 0x156
/* 8012C1DC 00128DBC  90 01 00 04 */	stw r0, 4(r1)
/* 8012C1E0 00128DC0  38 A0 00 00 */	li r5, 0
/* 8012C1E4 00128DC4  38 C0 00 00 */	li r6, 0
/* 8012C1E8 00128DC8  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 8012C1EC 00128DCC  93 E1 00 64 */	stw r31, 0x64(r1)
/* 8012C1F0 00128DD0  93 C1 00 60 */	stw r30, 0x60(r1)
/* 8012C1F4 00128DD4  7C 7E 1B 78 */	mr r30, r3
/* 8012C1F8 00128DD8  93 A1 00 5C */	stw r29, 0x5c(r1)
/* 8012C1FC 00128DDC  C0 22 A0 4C */	lfs f1, lbl_804D9A2C(r2)
/* 8012C200 00128DE0  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8012C204 00128DE4  FC 60 08 90 */	fmr f3, f1
/* 8012C208 00128DE8  C0 42 A0 48 */	lfs f2, lbl_804D9A28(r2)
/* 8012C20C 00128DEC  4B F3 D1 A1 */	bl Fighter_ActionStateChange_800693AC
/* 8012C210 00128DF0  80 BF 01 08 */	lwz r5, 0x108(r31)
/* 8012C214 00128DF4  38 7F 00 00 */	addi r3, r31, 0
/* 8012C218 00128DF8  38 80 00 01 */	li r4, 1
/* 8012C21C 00128DFC  80 A5 00 08 */	lwz r5, 8(r5)
/* 8012C220 00128E00  4B F4 38 39 */	bl func_8006FA58
/* 8012C224 00128E04  38 7E 00 00 */	addi r3, r30, 0
/* 8012C228 00128E08  38 80 00 00 */	li r4, 0
/* 8012C22C 00128E0C  38 A0 00 01 */	li r5, 1
/* 8012C230 00128E10  4B F4 88 DD */	bl func_80074B0C
/* 8012C234 00128E14  83 BE 00 2C */	lwz r29, 0x2c(r30)
/* 8012C238 00128E18  38 7E 00 00 */	addi r3, r30, 0
/* 8012C23C 00128E1C  38 80 00 02 */	li r4, 2
/* 8012C240 00128E20  4B F4 EE 81 */	bl func_8007B0C0
/* 8012C244 00128E24  80 9D 01 0C */	lwz r4, 0x10c(r29)
/* 8012C248 00128E28  3C 60 80 3B */	lis r3, lbl_803B75C0@ha
/* 8012C24C 00128E2C  38 00 00 01 */	li r0, 1
/* 8012C250 00128E30  C0 02 A0 48 */	lfs f0, lbl_804D9A28(r2)
/* 8012C254 00128E34  80 84 00 08 */	lwz r4, 8(r4)
/* 8012C258 00128E38  38 E3 75 C0 */	addi r7, r3, lbl_803B75C0@l
/* 8012C25C 00128E3C  88 A4 00 11 */	lbz r5, 0x11(r4)
/* 8012C260 00128E40  38 7D 00 00 */	addi r3, r29, 0
/* 8012C264 00128E44  38 9D 11 A0 */	addi r4, r29, 0x11a0
/* 8012C268 00128E48  90 A1 00 24 */	stw r5, 0x24(r1)
/* 8012C26C 00128E4C  38 A1 00 24 */	addi r5, r1, 0x24
/* 8012C270 00128E50  90 01 00 28 */	stw r0, 0x28(r1)
/* 8012C274 00128E54  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8012C278 00128E58  80 C7 00 00 */	lwz r6, 0(r7)
/* 8012C27C 00128E5C  80 07 00 04 */	lwz r0, 4(r7)
/* 8012C280 00128E60  90 C1 00 3C */	stw r6, 0x3c(r1)
/* 8012C284 00128E64  90 01 00 40 */	stw r0, 0x40(r1)
/* 8012C288 00128E68  80 07 00 08 */	lwz r0, 8(r7)
/* 8012C28C 00128E6C  90 01 00 44 */	stw r0, 0x44(r1)
/* 8012C290 00128E70  80 C1 00 3C */	lwz r6, 0x3c(r1)
/* 8012C294 00128E74  80 01 00 40 */	lwz r0, 0x40(r1)
/* 8012C298 00128E78  90 C1 00 30 */	stw r6, 0x30(r1)
/* 8012C29C 00128E7C  90 01 00 34 */	stw r0, 0x34(r1)
/* 8012C2A0 00128E80  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8012C2A4 00128E84  90 01 00 38 */	stw r0, 0x38(r1)
/* 8012C2A8 00128E88  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 8012C2AC 00128E8C  4B F4 F3 01 */	bl func_8007B5AC
/* 8012C2B0 00128E90  7F C3 F3 78 */	mr r3, r30
/* 8012C2B4 00128E94  4B F6 61 9D */	bl func_80092450
/* 8012C2B8 00128E98  88 1F 22 1E */	lbz r0, 0x221e(r31)
/* 8012C2BC 00128E9C  38 60 00 00 */	li r3, 0
/* 8012C2C0 00128EA0  50 60 1F 38 */	rlwimi r0, r3, 3, 0x1c, 0x1c
/* 8012C2C4 00128EA4  98 1F 22 1E */	stb r0, 0x221e(r31)
/* 8012C2C8 00128EA8  7F C3 F3 78 */	mr r3, r30
/* 8012C2CC 00128EAC  4B FF F5 D9 */	bl func_8012B8A4
/* 8012C2D0 00128EB0  7F E3 FB 78 */	mr r3, r31
/* 8012C2D4 00128EB4  4B F6 5A 85 */	bl func_80091D58
/* 8012C2D8 00128EB8  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 8012C2DC 00128EBC  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 8012C2E0 00128EC0  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 8012C2E4 00128EC4  83 A1 00 5C */	lwz r29, 0x5c(r1)
/* 8012C2E8 00128EC8  38 21 00 68 */	addi r1, r1, 0x68
/* 8012C2EC 00128ECC  7C 08 03 A6 */	mtlr r0
/* 8012C2F0 00128ED0  4E 80 00 20 */	blr 
}
#pragma pop

void lbl_8012C2F4(HSD_GObj* fighter_gobj) {
    s32* x1CC;
    s32 bone_idx;
    Fighter* fp2;
    HSD_JObj* jobj;
    u32 unused[6];
    Fighter* fp = fighter_gobj->user_data;

    f32 state_var = fp->x2340_f32;
    fp->x2340_f32 += lbl_804D9A28;
	// TODO: figure out why this has diffrent params in this func vs lbl_8012C030
    func_80092BCC(fighter_gobj, state_var);
    if (func_800925A4(fighter_gobj)) {
        fp = fighter_gobj->user_data;
        func_80074B0C(fighter_gobj, 0, 0);
        func_8007B0C0(fighter_gobj, 0);
    
        x1CC = &fp->x110_attr.x1CC;
        bone_idx = func_8007500C(fp, 4);
        fp2 = fighter_gobj->user_data;
        jobj = fp->x5E8_fighterBones[bone_idx].x0_jobj;
        efAsync_Spawn(fighter_gobj, &fp2->x60C, 4U, 0x4CF, jobj, x1CC);
    }
    else if ((fp->x234C_stateVar4_s32 != 0) || !(fp->x221B_flag.bits.b0 & 1) && !(fp->x2218_flag.bits.b3)) {
        func_80092BE8(fighter_gobj);
    }
    else {
        func_8012B8A4(fighter_gobj);
    }
}

void lbl_8012C3EC(HSD_GObj* fighter_gobj) {
    if (!func_8009515C(fighter_gobj) &&
		!func_80099794(fighter_gobj) &&
		!func_8009917C(fighter_gobj) &&
		!func_800D8990(fighter_gobj) &&
		!func_8009A080(fighter_gobj)) {
        return;
    }
}

void lbl_8012C45C(void) {
    func_80092B70();
}

void lbl_8012C47C(void) {
    func_80092BAC();
}
