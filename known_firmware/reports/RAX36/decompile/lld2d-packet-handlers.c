
===== TARGET packetio_recv_handler =====

===== FUNCTION FUN_00013148 @ 00013148 =====

void FUN_00013148(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  char *pcVar11;
  undefined4 uVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  bool bVar20;
  
  puVar6 = DAT_000139b0;
  uVar9 = read(param_1,DAT_000139b0,0x800);
  *DAT_000139b4 = uVar9;
  if (uVar9 == 0) {
    piVar10 = __errno_location();
    pcVar11 = strerror(*piVar10);
                    /* WARNING: Subroutine does not return */
    FUN_000129f0(DAT_000139b8,pcVar11);
  }
  uVar12 = DAT_000139bc;
  uVar18 = uVar9;
  if (uVar9 < 0xe) goto LAB_00013478;
  *DAT_000139c0 = puVar6;
  *DAT_000139c4 = puVar6 + 0xe;
  puVar16 = puVar6 + 0x20;
  *DAT_000139c8 = puVar16;
  *DAT_000139cc = puVar16;
  *DAT_000139d0 = puVar16;
  if (*(short *)(puVar6 + 0xc) != -0x2678) {
    return;
  }
  if (uVar9 < 0x20) {
    warn(DAT_000139d4,uVar9,puVar6[6],puVar6[7],puVar6[8],puVar6[9],puVar6[10],puVar6[0xb],*puVar6,
         puVar6[1],puVar6[2],puVar6[3],puVar6[4],puVar6[5]);
    return;
  }
  uVar17 = (uint)(byte)puVar6[0xe];
  uVar12 = DAT_000139d8;
  if (uVar17 != 1) {
LAB_0001329c:
    warn(uVar12,uVar17);
    return;
  }
  uVar17 = (uint)(byte)puVar6[0x11];
  *DAT_000139dc = uVar17;
  piVar8 = DAT_00016fbc;
  piVar10 = DAT_00016fb8;
  if (puVar6[0xf] == 2) {
    uVar9 = *DAT_00016f90;
    uVar12 = DAT_00016f94;
    if (uVar9 < 0xb) {
      iVar13 = *DAT_00016f98;
      uVar19 = *(ushort *)(iVar13 + 0x10) << 8 | *(ushort *)(iVar13 + 0x10) >> 8;
      if (uVar9 == 10) {
        uVar12 = DAT_00016fa8;
        if ((((uVar19 != 0) || (uVar12 = DAT_00016fac, *(char *)(iVar13 + 4) != -1)) ||
            (*(char *)(iVar13 + 5) != -1)) ||
           (((*(char *)(iVar13 + 6) != -1 || (*(char *)(iVar13 + 7) != -1)) ||
            ((*(char *)(iVar13 + 8) != -1 || (*(char *)(iVar13 + 9) != -1)))))) {
          warn(uVar12);
          return;
        }
      }
      else {
        uVar12 = DAT_00016f9c;
        if (((uVar19 == 0) || (uVar12 = DAT_00016fa4, *(char *)(iVar13 + 4) != *DAT_00016fa0)) ||
           (((*(char *)(iVar13 + 5) != DAT_00016fa0[1] ||
             (((*(char *)(iVar13 + 6) != DAT_00016fa0[2] ||
               (*(char *)(iVar13 + 7) != DAT_00016fa0[3])) ||
              (*(char *)(iVar13 + 8) != DAT_00016fa0[4])))) ||
            (*(char *)(iVar13 + 9) != DAT_00016fa0[5])))) goto LAB_00016544;
      }
      pcVar11 = (char *)*DAT_00016fb0;
      if (((((pcVar11[6] == *(char *)(iVar13 + 10)) && (pcVar11[7] == *(char *)(iVar13 + 0xb))) &&
           ((pcVar11[8] == *(char *)(iVar13 + 0xc) &&
            ((pcVar11[9] == *(char *)(iVar13 + 0xd) && (pcVar11[10] == *(char *)(iVar13 + 0xe)))))))
          && ((pcVar11[0xb] == *(char *)(iVar13 + 0xf) &&
              ((((*(char *)(iVar13 + 4) == *pcVar11 && (*(char *)(iVar13 + 5) == pcVar11[1])) &&
                (*(char *)(iVar13 + 6) == pcVar11[2])) &&
               ((*(char *)(iVar13 + 7) == pcVar11[3] && (*(char *)(iVar13 + 8) == pcVar11[4]))))))))
         && (*(char *)(iVar13 + 9) == pcVar11[5])) {
        *DAT_00016fb4 = uVar19;
        iVar13 = iVar13 + 0x12;
        *piVar10 = iVar13;
        piVar10 = DAT_00016fc0;
        *piVar8 = iVar13;
        *piVar10 = iVar13;
                    /* WARNING: Could not recover jumptable at 0x00016760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        if (uVar9 < 0xb) {
          (*(code *)(&switchD_00016760::switchdataD_00016768)[uVar9])();
          return;
        }
      }
    }
    else {
LAB_00016544:
      warn(uVar12);
    }
    return;
  }
  if (1 < (byte)puVar6[0xf]) {
    return;
  }
  uVar12 = DAT_000139e0;
  if (0xc < uVar17) goto LAB_0001329c;
  bVar14 = puVar6[0x12];
  if (uVar17 != 4 && uVar17 != 1) {
    if ((((*DAT_000139e4 != bVar14) || (DAT_000139e4[1] != puVar6[0x13])) ||
        ((DAT_000139e4[2] != puVar6[0x14] ||
         (((DAT_000139e4[3] != puVar6[0x15] || (DAT_000139e4[4] != puVar6[0x16])) ||
          (DAT_000139e4[5] != puVar6[0x17])))))) &&
       ((puVar6[0x17] & puVar6[0x16] & puVar6[0x15] & puVar6[0x14] & puVar6[0x13] & bVar14) != 0xff)
       ) {
      return;
    }
  }
  if ((bVar14 & 1) == 0) {
LAB_00013380:
    uVar18 = (*(ushort *)(puVar6 + 0x1e) & 0xff) << 8 | (uint)(*(ushort *)(puVar6 + 0x1e) >> 8);
    if (uVar18 == 0) {
      bVar20 = 9 < uVar17;
      if (uVar17 != 10) {
        bVar20 = 1 < uVar17 - 5;
      }
      if (!bVar20 || (uVar17 == 10 || uVar17 - 5 == 2)) {
        uVar1 = puVar6[0x1d];
        uVar2 = puVar6[0x1c];
        uVar3 = puVar6[0x1b];
        uVar4 = puVar6[0x1a];
        uVar5 = puVar6[0x19];
        bVar14 = puVar6[0x18];
        uVar12 = DAT_000139f0;
        goto LAB_00013378;
      }
    }
    else {
      if ((~(0x1ee5U >> uVar17) & 1) != 0) {
        warn(DAT_000139ec,uVar17,uVar18,puVar6[0x18],puVar6[0x19],puVar6[0x1a],puVar6[0x1b],
             puVar6[0x1c],puVar6[0x1d]);
        return;
      }
      if (uVar17 != 0) {
        uVar15 = (uint)*DAT_000139f4;
        if (uVar18 == uVar15) {
          if (uVar17 == *DAT_000139f8) {
            FUN_00012cbc(DAT_00013a00,*DAT_000139fc);
            return;
          }
          uVar12 = DAT_00013a04;
          uVar18 = (uint)*(byte *)(DAT_00013a00 + 0x11);
LAB_00013478:
          warn(uVar12,uVar18);
          return;
        }
        if (uVar15 != 0) {
          uVar15 = uVar15 + 1;
          if ((uVar15 & 0xffff) == 0) {
            uVar15 = 1;
          }
          uVar12 = DAT_00013a08;
          if (uVar15 != uVar18) goto LAB_00013478;
        }
      }
    }
    *DAT_00013a0c = (short)uVar18;
    puVar7 = DAT_00013a10;
    *DAT_00013a10 = 0;
    puVar7[1] = 0;
    puVar7[2] = 0;
    puVar7[3] = 0;
    puVar7[4] = 0;
    puVar7[5] = 0;
                    /* WARNING: Could not recover jumptable at 0x000134dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar17 < 0xd) {
      (*(code *)(&switchD_000134dc::switchdataD_000134e4)[uVar17])(uVar18,uVar9);
      return;
    }
  }
  else {
    bVar20 = 7 < uVar17;
    if (uVar17 != 8) {
      bVar20 = uVar17 != 0;
    }
    if (!bVar20 || (uVar17 == 8 || uVar17 == 1)) goto LAB_00013380;
    uVar1 = puVar6[0x17];
    uVar2 = puVar6[0x16];
    uVar3 = puVar6[0x15];
    uVar4 = puVar6[0x14];
    uVar5 = puVar6[0x13];
    uVar12 = DAT_000139e8;
LAB_00013378:
    warn(uVar12,uVar17,bVar14,uVar5,uVar4,uVar3,uVar2,uVar1);
  }
  return;
}


===== TARGET rx_discover =====

===== FUNCTION FUN_000143a0 @ 000143a0 =====

undefined4 FUN_000143a0(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  uVar1 = *(ushort *)(*DAT_00014484 + 2);
  uVar5 = 1;
  if (*(int *)(DAT_0001448c + 0xc) != 1) {
    uVar3 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    uVar5 = 0;
    pcVar4 = (char *)(*DAT_00014484 + 4);
    for (uVar2 = 0;
        (pcVar4 + 6 <= (char *)(*DAT_00014480 + *DAT_00014488) && ((int)uVar2 < (int)uVar3));
        uVar2 = uVar2 + 1) {
      if (((*pcVar4 == *DAT_00014490) &&
          (((pcVar4[1] == DAT_00014490[1] && (pcVar4[2] == DAT_00014490[2])) &&
           (pcVar4[3] == DAT_00014490[3])))) &&
         ((pcVar4[4] == DAT_00014490[4] && (pcVar4[5] == DAT_00014490[5])))) {
        uVar5 = 1;
      }
      pcVar4 = pcVar4 + 6;
    }
    if (uVar3 != uVar2) {
      warn(DAT_00014494);
    }
  }
  return uVar5;
}


===== TARGET rx_hello =====

===== TARGET validate_emit =====

===== TARGET query-ltlv-rcvd =====
