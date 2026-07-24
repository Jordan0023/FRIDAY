
===== ADDRESS 00011614 FUNCTION FUN_00011614 =====

void FUN_00011614(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  char *__pid;
  undefined4 uVar3;
  int iVar4;
  __pid_t _Var5;
  size_t __n;
  ssize_t sVar6;
  char *pcVar7;
  char *local_74;
  char acStack_70 [16];
  char acStack_60 [84];
  
  snprintf(acStack_60,0x50,DAT_000117a4,*DAT_000117a8,*param_1);
  iVar1 = open(acStack_60,0);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    if (*piVar2 != 2) {
      __pid = strerror(*piVar2);
      pcVar7 = acStack_60;
      uVar3 = DAT_000117ac;
      goto LAB_00011670;
    }
  }
  else {
    sVar6 = read(iVar1,acStack_70,0x10);
    if (sVar6 < 0) {
      piVar2 = __errno_location();
      __pid = strerror(*piVar2);
      pcVar7 = acStack_60;
      uVar3 = DAT_000117b0;
      goto LAB_00011670;
    }
    __pid = (char *)strtol(acStack_70,&local_74,10);
    if (*local_74 != '\0' && *local_74 != '\n') {
      __pid = acStack_60;
      pcVar7 = acStack_70;
      uVar3 = DAT_000117b4;
      goto LAB_00011670;
    }
    iVar4 = kill((__pid_t)__pid,0);
    if (iVar4 == 0) {
      pcVar7 = acStack_60;
      uVar3 = DAT_000117b8;
      goto LAB_00011670;
    }
    close(iVar1);
  }
  iVar1 = open(acStack_60,0x241,0x1a4);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    __pid = strerror(*piVar2);
    pcVar7 = acStack_60;
    uVar3 = DAT_000117bc;
  }
  else {
    _Var5 = getpid();
    snprintf(acStack_70,0x10,DAT_000117c0,_Var5);
    __n = strlen(acStack_70);
    sVar6 = write(iVar1,acStack_70,__n);
    if (-1 < sVar6) {
      close(iVar1);
      return;
    }
    piVar2 = __errno_location();
    __pid = strerror(*piVar2);
    pcVar7 = acStack_60;
    uVar3 = DAT_000117c4;
  }
LAB_00011670:
                    /* WARNING: Subroutine does not return */
  FUN_000129f0(uVar3,pcVar7,__pid);
}

REFERENCE 00011238 OWNER FUN_0001100c

undefined4 FUN_0001100c(int param_1,char **param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  void *__s;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  char **__nptr;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  uint *__shortopts;
  int *piVar18;
  
  __shortopts = DAT_00011304;
  puVar2 = DAT_00011300;
  pcVar14 = *param_2;
  iVar12 = param_1;
  __nptr = param_2;
  pcVar8 = strrchr(pcVar14,0x2f);
  pcVar9 = DAT_0001130c;
  piVar18 = DAT_00011308;
  if (pcVar8 != (char *)0x0) {
    pcVar14 = pcVar8 + 1;
  }
  *puVar2 = pcVar14;
  puVar17 = DAT_00011310;
  iVar15 = 0;
  pcVar9 = strstr(pcVar14,pcVar9);
  bVar1 = false;
  *puVar17 = (uint)(pcVar9 != (char *)0x0);
LAB_00011064:
  iVar10 = getopt(param_1,param_2,(char *)__shortopts);
  uVar13 = DAT_00011324;
  uVar16 = DAT_00011320;
  puVar5 = DAT_0001131c;
  puVar4 = DAT_00011318;
  piVar3 = DAT_00011314;
  if (iVar10 != -1) {
    if (iVar10 != 100) goto code_r0x0001125c;
    goto LAB_000112a8;
  }
  iVar10 = *DAT_00011314;
  if (*puVar17 == 0) {
    if (param_1 <= iVar10) {
      fprintf((FILE *)*DAT_00011394,DAT_0001139c,*puVar2,DAT_00011394,iVar12,__nptr,param_3);
      puVar17 = puVar4;
      __shortopts = puVar5;
      piVar18 = piVar3;
      goto LAB_00011294;
    }
  }
  else if (param_1 <= iVar10) {
    pcVar14 = (char *)*puVar2;
    pcVar8 = strstr(pcVar14,DAT_00011328);
    pcVar9 = DAT_00011328;
    if (pcVar8 != (char *)0x0) {
      uVar13 = uVar16;
    }
    *puVar4 = uVar13;
    pcVar8 = strstr(pcVar14,pcVar9);
    pcVar9 = DAT_00011330;
    if (pcVar8 == (char *)0x0) {
      uVar16 = DAT_0001132c;
    }
    *puVar5 = uVar16;
    printf(pcVar9,pcVar14,uVar13);
    goto LAB_000110f0;
  }
  pcVar9 = strdup(param_2[iVar10]);
  iVar12 = *piVar3;
  *puVar4 = (uint)pcVar9;
  iVar12 = iVar12 + 1;
  if (iVar12 < param_1) {
    pcVar9 = strdup(param_2[iVar12]);
  }
  *puVar5 = (uint)pcVar9;
LAB_000110f0:
  __s = DAT_0001133c;
  puVar2 = DAT_00011338;
  *DAT_00011334 = iVar15;
  puVar6 = DAT_00011340;
  *puVar2 = 0;
  *(undefined2 *)(puVar2 + 1) = 0;
  *puVar6 = 0;
  puVar6 = DAT_00011348;
  *DAT_00011344 = 0;
  memset(__s,0,0x1b8);
  puVar7 = DAT_0001134c;
  *DAT_0001134c = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  uVar11 = FUN_000115ec();
  *puVar6 = uVar11;
  memset(DAT_00011350,0,0x800);
  memset(DAT_00011354,0,0x800);
  memset(DAT_00011358,0,0x800);
  memset(DAT_0001135c,0,0x800);
  uVar11 = FUN_00015404(0x400);
  *DAT_00011360 = uVar11;
  *DAT_00011364 = 0;
  *DAT_00011368 = 0;
  *DAT_0001136c = 0;
  *DAT_00011370 = 0;
  *DAT_00011374 = 0;
  *DAT_00011378 = 0xd;
  *DAT_0001137c = 0;
  *DAT_00011380 = 0;
  *DAT_00011384 = 0;
  *DAT_00011388 = 0;
  *DAT_0001138c = 0;
  *DAT_00011390 = 0;
  FUN_00012370();
  FUN_00012588();
  FUN_00016428();
  FUN_000117c8(*puVar6,*puVar4,0);
  FUN_000119c4(*puVar6,puVar2);
  if (!bVar1) {
    FUN_00012b1c();
    FUN_000119f4(*puVar6);
  }
  FUN_00011614(*puVar6);
  FUN_000118fc(*puVar6);
  FUN_0001274c();
  return 0;
code_r0x0001125c:
  if (iVar10 != 0x74) goto LAB_00011298;
  __nptr = (char **)*piVar18;
  iVar15 = atoi((char *)__nptr);
  if (iVar15 == 0) {
    fprintf((FILE *)*DAT_00011394,DAT_00011398,*puVar2,__nptr);
LAB_00011294:
    do {
      FUN_00012340();
LAB_00011298:
    } while (*puVar17 == 0);
    iVar15 = 0x12;
LAB_000112a8:
    bVar1 = true;
  }
  goto LAB_00011064;
}


===== ADDRESS 00011ac0 FUNCTION FUN_00011ac0 =====

undefined4 FUN_00011ac0(char *param_1)

{
  undefined2 uVar1;
  byte *__s;
  FILE *__stream;
  int *piVar2;
  char *pcVar3;
  ushort **ppuVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  byte *__s_00;
  ushort *puVar9;
  
  pcVar3 = DAT_00011cb8;
  uVar1 = *(undefined2 *)(DAT_00011cb4 + 1);
  *(undefined4 *)param_1 = *DAT_00011cb4;
  *(undefined2 *)(param_1 + 4) = uVar1;
  __stream = fopen(DAT_00011cbc,pcVar3);
  __s = DAT_00011cc8;
  if (__stream == (FILE *)0x0) {
    piVar2 = __errno_location();
    pcVar3 = strerror(*piVar2);
    warn(DAT_00011cc0,pcVar3);
  }
  else {
    fgets((char *)DAT_00011cc8,0xa0,__stream);
    fgets((char *)DAT_00011cc8,0xa0,__stream);
    while (pcVar3 = fgets((char *)__s,0xa0,__stream), pcVar3 != (char *)0x0) {
      ppuVar4 = __ctype_b_loc();
      puVar9 = *ppuVar4;
      pbVar8 = DAT_00011cc8;
      do {
        __s_00 = pbVar8;
        pbVar8 = __s_00 + 1;
      } while ((puVar9[*__s_00] & 0x2000) != 0);
      pbVar5 = (byte *)strchr((char *)__s_00,0x3a);
      uVar6 = DAT_00011ccc;
      pbVar8 = pbVar5;
      if (pbVar5 == (byte *)0x0) goto LAB_00011ba4;
      do {
        pbVar8 = pbVar8 + 1;
      } while ((puVar9[*pbVar8] & 0x800) != 0);
      if (*pbVar8 == 0x3a) {
        *pbVar8 = 0;
      }
      else {
        *pbVar5 = 0;
      }
      FUN_0001158c(__s_00,param_1);
    }
    iVar7 = ferror(__stream);
    uVar6 = DAT_00011cd0;
    if (iVar7 == 0) {
      fclose(__stream);
      if ((((*param_1 == -1) && (param_1[1] == -1)) && (param_1[2] == -1)) &&
         (((param_1[3] == -1 && (param_1[4] == -1)) && (param_1[5] == -1)))) {
        if ((*DAT_00011cc4 & 8) == 0) {
          return 0;
        }
        FUN_00012ae0(DAT_00011cdc);
        return 0;
      }
      if ((*DAT_00011cc4 & 8) != 0) {
        FUN_00012ae0(DAT_00011cd4,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],param_1[5]);
      }
      return 1;
    }
LAB_00011ba4:
    warn(uVar6);
    fclose(__stream);
  }
  if ((*DAT_00011cc4 & 8) != 0) {
    FUN_00012ae0(DAT_00011cd8);
  }
  return 0;
}


===== ADDRESS 00016084 FUNCTION FUN_00016084 =====

void FUN_00016084(void)

{
  char *pcVar1;
  FILE *__stream;
  char *pcVar2;
  size_t sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  char acStack_20 [16];
  
  __stream = fopen(DAT_00016228,DAT_00016224);
  pcVar1 = DAT_00016230;
  if (__stream == (FILE *)0x0) {
    warn(DAT_00016254);
    *DAT_00016244 = 0;
    *DAT_00016240 = 0;
    *DAT_0001623c = 0;
    *DAT_00016238 = 0;
  }
  else {
    strncpy(acStack_20,(char *)*DAT_0001622c,0xe);
    strcat(acStack_20,DAT_00016234);
    do {
      pcVar2 = fgets(DAT_00016230,0xa0,__stream);
      if (pcVar1 != pcVar2) {
        uVar5 = 0xffffffff;
        *DAT_00016238 = 0xffffffff;
        *DAT_0001623c = 0xffffffff;
        *DAT_00016240 = 0xffffffff;
        puVar4 = DAT_00016244;
        goto LAB_000161d8;
      }
      pcVar2 = strstr(pcVar2,acStack_20);
    } while (pcVar2 == (char *)0x0);
    local_2c = *DAT_00016248;
    uStack_28 = DAT_00016248[1];
    local_24 = DAT_00016248[2];
    local_30 = pcVar2;
    sVar3 = strlen(acStack_20);
    local_30 = pcVar2 + sVar3;
    iVar6 = 6;
    strtoul(local_30,&local_30,10);
    strtoul(local_30,&local_30,10);
    do {
      strtoul(local_30,&local_30,10);
      if (*local_30 == '\0') {
        warn(DAT_0001624c);
        local_30 = (char *)&local_2c;
        break;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    strtoul(local_30,&local_30,10);
    strtoul(local_30,(char **)0x0,10);
    warn(DAT_00016250);
    uVar5 = 0;
    *DAT_00016244 = 0;
    *DAT_00016240 = 0;
    *DAT_0001623c = 0;
    puVar4 = DAT_00016238;
LAB_000161d8:
    *puVar4 = uVar5;
    fclose(__stream);
  }
  return;
}

REFERENCE 00016c20 OWNER FUN_00013148

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

REFERENCE 000162f4 OWNER FUN_000162a4

void FUN_000162a4(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  short sVar7;
  int extraout_r1;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  timeval local_30;
  undefined4 uStack_28;
  
  puVar2 = DAT_00016400;
  piVar1 = DAT_000163fc;
  iVar9 = *DAT_000163f8;
  *DAT_000163f8 = iVar9 + -1;
  piVar4 = DAT_00016410;
  if (iVar9 + -1 == 0) {
    *piVar1 = 0;
    *puVar2 = 0;
  }
  else {
    iVar14 = *DAT_00016404;
    iVar13 = *DAT_00016408;
    iVar12 = *DAT_0001640c;
    iVar11 = *DAT_00016410;
    iVar9 = *piVar1;
    local_30.tv_sec = param_1;
    local_30.tv_usec = param_2;
    uStack_28 = param_3;
    FUN_00016084();
    iVar5 = DAT_00016414;
    piVar3 = DAT_00016408;
    iVar9 = iVar9 * 8;
    iVar8 = *DAT_0001640c;
    if (iVar14 == *DAT_00016404) {
      iVar14 = 0;
    }
    else {
      iVar14 = *DAT_00016404 - iVar14;
    }
    *(short *)(DAT_00016414 + iVar9) = (short)((uint)(iVar14 << 6) >> 0x10);
    if (iVar13 == *piVar3) {
      sVar7 = 0;
    }
    else {
      sVar7 = (short)*piVar3 - (short)iVar13;
    }
    *(short *)(iVar5 + iVar9 + 2) = sVar7;
    if (iVar12 == iVar8) {
      iVar8 = 0;
    }
    else {
      iVar8 = iVar8 - iVar12;
    }
    *(short *)(iVar5 + iVar9 + 4) = (short)((uint)(iVar8 << 6) >> 0x10);
    if (iVar11 == *piVar4) {
      sVar7 = 0;
    }
    else {
      sVar7 = (short)*piVar4 - (short)iVar11;
    }
    *(short *)(iVar5 + iVar9 + 6) = sVar7;
    gettimeofday(&local_30,(__timezone_ptr_t)0x0);
    iVar9 = *piVar1;
    *DAT_0001641c = (longlong)local_30.tv_sec * (longlong)DAT_00016418 + (longlong)local_30.tv_usec;
    FUN_00017338(iVar9 + 1,0x3c);
    uVar10 = *puVar2;
    *piVar1 = extraout_r1;
    if (uVar10 < 0x3c) {
      *puVar2 = uVar10 + 1;
    }
    gettimeofday(&local_30,(__timezone_ptr_t)0x0);
    local_30.tv_sec = local_30.tv_sec + 1;
    uVar6 = FUN_000125b0(&local_30,DAT_00016420,0);
    *DAT_00016424 = uVar6;
  }
  return;
}

