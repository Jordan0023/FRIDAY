
===== ADDRESS 00021e80 FUNCTION NONE =====

===== ADDRESS 00021eb0 FUNCTION NONE =====

===== ADDRESS 00021ed0 FUNCTION NONE =====

===== ADDRESS 00021f60 FUNCTION NONE =====

===== ADDRESS 00021f74 FUNCTION NONE =====

===== ADDRESS 00013090 FUNCTION FUN_00013090 =====

void FUN_00013090(void)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  FILE *__stream_00;
  undefined4 uVar3;
  char *pcVar4;
  char acStack_9c [128];
  int iStack_1c;
  
  iVar1 = DAT_000130dc;
  system((char *)(DAT_000130d8 + 0x130a0));
  iVar2 = DAT_0001dd48;
  if (**(int **)(iVar1 + 78000 + DAT_000130e0) == 0) {
    return;
  }
  if (**(int **)(iVar1 + 78000 + DAT_000130e4) == 0) {
    return;
  }
  iStack_1c = **(int **)(DAT_0001dd40 + 0x1dbd4 + DAT_0001dd44);
  acStack_9c[0] = '\0';
  acStack_9c[1] = '\0';
  acStack_9c[2] = '\0';
  acStack_9c[3] = '\0';
  memset(acStack_9c + 4,0,0x7c);
  iVar1 = DAT_0001dd50;
  system((char *)(DAT_0001dd4c + 0x1dc10));
  FUN_00017310(DAT_0001dd54 + 0x1dc24,(char *)(iVar2 + 0x1dc08));
  system((char *)(DAT_0001dd58 + 0x1dc30));
  __stream = fopen((char *)(iVar2 + 0x1dc08),(char *)(iVar1 + 0x1dc20));
  __stream_00 = fopen((char *)(DAT_0001dd5c + 0x1dc50),(char *)(iVar1 + 0x1dc20));
  iVar1 = DAT_0001dd68;
  if (__stream_00 == (FILE *)0x0 || __stream == (FILE *)0x0) {
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    if (__stream_00 != (FILE *)0x0) {
LAB_0001dc78:
      fclose(__stream_00);
    }
    if (iStack_1c != **(int **)(DAT_0001dd60 + 0x1dc90 + DAT_0001dd44)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  pcVar4 = (char *)(DAT_0001dd64 + 0x1dcb4);
  strcpy((char *)(DAT_0001dd68 + 0x1dcb8),pcVar4);
  strcpy((char *)(iVar1 + 0x1dcba),pcVar4);
  strcpy((char *)(iVar1 + 0x1dcbc),pcVar4);
  iVar2 = DAT_0001dd6c;
  strcpy((char *)(iVar1 + 0x1dcbe),pcVar4);
  do {
    do {
      pcVar4 = fgets(acStack_9c,0x80,__stream);
      if (pcVar4 == (char *)0x0) {
        fclose(__stream);
        goto LAB_0001dc78;
      }
      pcVar4 = strtok(acStack_9c,(char *)(iVar2 + 0x1dcf0));
    } while (pcVar4 == (char *)0x0);
    uVar3 = FUN_0001d948();
    FUN_0001da20(uVar3,__stream_00);
  } while( true );
}

REFERENCE 00013750 OWNER FUN_00013748

undefined4 FUN_00013748(undefined4 param_1)

{
  FILE *__stream;
  FILE *__stream_00;
  
  FUN_00013090();
  __stream = (FILE *)0x0;
  if (**(int **)(DAT_000137d4 + 0x13764 + DAT_000137d8) != 0) {
    __stream = fopen((char *)(DAT_000137e0 + 0x13784),(char *)(DAT_000137dc + 0x13780));
  }
  __stream_00 = fopen((char *)(DAT_000137e8 + 0x1379c),(char *)(DAT_000137e4 + 0x13798));
  if (__stream_00 != (FILE *)0x0) {
    FUN_000134a8(param_1,__stream_00,__stream);
    fclose(__stream_00);
  }
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  return 0;
}

REFERENCE 00013854 OWNER FUN_00015cd8

void FUN_00015cd8(void)

{
  FILE *pFVar1;
  FILE *__stream;
  int iVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  char *pcVar3;
  int *piVar4;
  undefined4 unaff_r6;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_lr;
  
  FUN_00017c04(DAT_00015d00 + 0x15cf4,0x545,DAT_00015cfc + 0x15cf0);
  FUN_00013090();
  pcVar3 = (char *)(DAT_00013920 + 0x13868);
  iVar2 = DAT_00013928 + 0x13878;
  pFVar1 = fopen((char *)(DAT_00013924 + 0x13870),pcVar3);
  if (pFVar1 == (FILE *)0x0) {
    FUN_00017c04(DAT_00013930 + 0x1389c,0xf2,DAT_0001392c + 0x13898);
    return;
  }
  __stream = (FILE *)0x0;
  if (**(int **)(iVar2 + DAT_00013934) != 0) {
    __stream = fopen((char *)(DAT_00013938 + 0x138c0),pcVar3);
  }
  piVar4 = (int *)(DAT_0001393c + 0x13d10);
  piVar5 = (int *)((int)&DAT_00013c90 + DAT_0001393c);
  do {
    piVar6 = piVar5 + 1;
    for (piVar5 = (int *)*piVar5; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
      FUN_000134a8(piVar5,pFVar1,__stream);
    }
    piVar5 = piVar6;
  } while (piVar4 != piVar6);
  fclose(pFVar1);
  if (__stream != (FILE *)0x0) {
    fclose(__stream);
  }
  pcVar3 = (char *)config_get(DAT_00013840 + 0x137fc);
  iVar2 = atoi(pcVar3);
  pFVar1 = fopen((char *)(DAT_00013848 + 0x13818),(char *)(DAT_00013844 + 0x1380c));
  if (pFVar1 == (FILE *)0x0) {
    return;
  }
  __fprintf_chk(pFVar1,1,DAT_0001384c + 0x13834,iVar2,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
  fclose(pFVar1);
  return;
}


===== ADDRESS 0001442c FUNCTION FUN_0001442c =====

void FUN_0001442c(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  int iVar3;
  char acStack_114 [256];
  int local_14;
  
  local_14 = **(int **)(DAT_000145e4 + 0x1443c + DAT_000145e8);
  __stream = fopen((char *)(DAT_000145f0 + 0x14458),(char *)(DAT_000145ec + 0x1444c));
  if (__stream == (FILE *)0x0) {
    system((char *)(DAT_000145f4 + 0x14478));
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = DAT_000145fc + 0x144b8;
    fgets(acStack_114,0x100,__stream);
    iVar1 = DAT_00014600;
    uVar2 = FUN_00017ec8(acStack_114,iVar3);
    FUN_00017018(iVar1 + 0x14918,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x14938,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018((int)&DAT_00014958 + iVar1,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x14998,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x149b8,uVar2,0x20);
    FUN_00017018((int)&DAT_00014978 + iVar1,DAT_00014604 + 0x14564,0x20);
    FUN_00017018(iVar1 + 0x149d8,DAT_00014608 + 0x14578,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x14a38,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x149f8,uVar2,0x20);
    uVar2 = FUN_00017ec8(0,iVar3);
    FUN_00017018(iVar1 + 0x14a18,uVar2,0x20);
    fclose(__stream);
    uVar2 = 0;
  }
  if (local_14 != **(int **)(DAT_000145f8 + 0x1448c + DAT_000145e8)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

REFERENCE 00014788 OWNER FUN_0001474c

void FUN_0001474c(void)

{
  FILE *__stream;
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char acStack_a4 [128];
  int local_24;
  undefined4 *puVar8;
  
  pcVar13 = (char *)(DAT_00014954 + 0x14774);
  local_24 = **(int **)(DAT_0001494c + 0x14760 + DAT_00014950);
  FUN_00017958(DAT_00014958 + 0x1477c,DAT_00014954 + 0x14cf4,DAT_0001494c + 0x14760,0);
  FUN_0001442c();
  iVar10 = DAT_00014964;
  __stream = fopen((char *)(DAT_00014960 + 0x147a4),(char *)(DAT_0001495c + 0x1479c));
  if (__stream == (FILE *)0x0) {
    fputs((char *)(DAT_0001496c + 0x147c4),
          (FILE *)**(undefined4 **)(iVar10 + 0x147ac + DAT_00014968));
    uVar1 = 0xffffffff;
  }
  else {
    iVar10 = 0;
    pcVar12 = (char *)(DAT_00014974 + 0x14804);
    pcVar9 = pcVar13;
    do {
      pcVar2 = strncpy(pcVar9,pcVar12,0x20);
      puVar6 = (undefined4 *)(DAT_00014978 + 0x1482c);
      pcVar9 = pcVar2 + 0x20;
      puVar7 = (undefined4 *)(DAT_00014978 + 0x1481c);
      do {
        puVar8 = puVar7 + 1;
        pcVar3 = pcVar9 + 4;
        *(undefined4 *)pcVar9 = *puVar7;
        pcVar9 = pcVar3;
        puVar7 = puVar8;
      } while (puVar8 != puVar6);
      iVar10 = iVar10 + 1;
      pcVar9 = pcVar2 + 0x3c;
      *(undefined2 *)pcVar3 = *(undefined2 *)puVar8;
      pcVar2[0x34] = '\0';
      pcVar2[0x35] = '\0';
      pcVar2[0x36] = '\0';
      pcVar2[0x37] = '\0';
      pcVar2[0x38] = '\0';
      pcVar2[0x39] = '\0';
      pcVar2[0x3a] = '\0';
      pcVar2[0x3b] = '\0';
    } while (iVar10 != 0x10);
    pcVar9 = (char *)(DAT_0001497c + 0x14868);
    iVar10 = DAT_00014980 + 0x1486c;
LAB_00014868:
    pcVar12 = fgets(acStack_a4,0x80,__stream);
    if (pcVar12 != (char *)0x0) {
      pcVar12 = strtok(acStack_a4,pcVar9);
      pcVar2 = strtok((char *)0x0,pcVar9);
      pcVar3 = strtok((char *)0x0,pcVar9);
      if (pcVar3 != (char *)0x0 && (pcVar12 != (char *)0x0 && pcVar2 != (char *)0x0)) {
        iVar4 = 0;
        pcVar5 = pcVar13;
        do {
          if (*pcVar5 == '\0') {
            FUN_00017018(pcVar5,pcVar12,0x20);
            uVar1 = FUN_0001460c(pcVar2);
            iVar11 = iVar4 * 0x3c + iVar10;
            *(undefined4 *)(iVar11 + 0x38) = uVar1;
            iVar4 = atoi(pcVar3);
            *(int *)(iVar11 + 0x34) = iVar4;
            break;
          }
          iVar4 = iVar4 + 1;
          pcVar5 = pcVar5 + 0x3c;
        } while (iVar4 != 0x10);
      }
      goto LAB_00014868;
    }
    fclose(__stream);
    FUN_000130e8();
    uVar1 = 0;
  }
  if (local_24 != **(int **)(DAT_00014970 + 0x147dc + DAT_00014950)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}


===== ADDRESS 00015394 FUNCTION FUN_00015394 =====

void FUN_00015394(void)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  size_t __n;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  char acStack_244 [32];
  char local_224 [20];
  undefined1 local_210;
  int local_24;
  
  iVar5 = DAT_0001551c;
  local_24 = **(int **)(DAT_00015514 + 0x153a8 + DAT_00015518);
  local_224[0] = '\0';
  local_224[1] = '\0';
  local_224[2] = '\0';
  local_224[3] = '\0';
  memset(local_224 + 4,0,0x1fc);
  iVar1 = DAT_00015530;
  if ((**(int **)(iVar5 + 0x153dc + DAT_00015520) == 0) &&
     (piVar4 = *(int **)(iVar5 + 0x153dc + DAT_00015524), iVar5 = *piVar4, iVar5 == 3 || iVar5 == 0)
     ) {
    __stream = fopen((char *)(DAT_0001552c + 0x15420),(char *)(DAT_00015528 + 0x15418));
    while (__stream != (FILE *)0x0) {
      pcVar2 = fgets(local_224,0x200,__stream);
      if (pcVar2 == (char *)0x0) {
        fclose(__stream);
        break;
      }
      iVar5 = 0;
      piVar6 = (int *)(iVar1 + 0x157e8);
      do {
        for (piVar7 = (int *)*piVar6; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
          FUN_0001760c(piVar7 + 3,acStack_244);
          local_210 = 0;
          FUN_000178c8(local_224);
          __n = strlen(acStack_244);
          iVar3 = strncmp(acStack_244,local_224,__n);
          if (iVar3 == 0) {
            *(undefined2 *)(piVar7 + 1) = 1;
            break;
          }
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar5 != 0x20);
    }
    if (*piVar4 == 0) {
      system((char *)(DAT_00015534 + 0x1546c));
    }
  }
  if (local_24 != **(int **)(DAT_00015538 + 0x1547c + DAT_00015518)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

REFERENCE 00016b9c OWNER FUN_00016aa8

void FUN_00016aa8(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *__ptr;
  FILE *pFVar8;
  int iVar9;
  undefined4 *puVar10;
  uint local_80;
  int local_7c;
  undefined4 *local_78;
  int local_68;
  undefined1 auStack_64 [32];
  undefined4 local_44;
  undefined1 auStack_40 [28];
  int local_24;
  
  pFVar8 = (FILE *)0x0;
  local_24 = **(int **)(DAT_00016dfc + 0x16ab8 + DAT_00016e00);
  pcVar7 = (char *)(DAT_00016e04 + 0x16ae8);
  local_44 = 0;
  memset(auStack_40,0,0x1c);
  local_68 = 0;
  FUN_0001ba00();
  FUN_00015680();
  iVar1 = DAT_00016e0c;
  __stream = fopen((char *)(DAT_00016e08 + 0x16b0c),pcVar7);
  piVar3 = *(int **)(iVar1 + 0x16b18 + DAT_00016e10);
  if ((*piVar3 == 0) &&
     (pFVar8 = fopen((char *)(DAT_00016e14 + 0x16b3c),pcVar7), pFVar8 == (FILE *)0x0)) {
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    FUN_00017c04(DAT_00016e20 + 0x16b74,0x48f,DAT_00016e1c + 0x16b70,DAT_00016e18 + 0x16b6c);
  }
  else {
    iVar5 = DAT_00016e28;
    FUN_00015394();
    iVar9 = 0;
    local_7c = 0;
    local_80 = 0;
    iVar4 = DAT_00016e2c + 0x16bc4;
    local_78 = (undefined4 *)(iVar5 + 0x16f70);
    do {
      iVar5 = DAT_00016e30 + 0x16be0;
      puVar6 = (undefined4 *)*local_78;
      puVar10 = local_78;
      while (__ptr = puVar6, __ptr != (undefined4 *)0x0) {
        local_80 = local_80 + 1;
        if ((*(short *)(__ptr + 1) == 0) ||
           ((**(int **)(iVar1 + 0x16b18 + DAT_00016e48) == 2 && (__ptr[7] == 1)))) {
          uVar2 = FUN_0001760c(__ptr + 3,auStack_64);
          pcVar7 = inet_ntoa((in_addr)__ptr[2]);
          FUN_00017c04(iVar5,0x499,iVar4,uVar2,pcVar7);
          puVar6 = (undefined4 *)*__ptr;
          if ((*piVar3 != 0 || local_80 < 0x100) || (__ptr[7] == 2)) goto LAB_00016dec;
          *puVar10 = puVar6;
          free(__ptr);
          puVar6 = (undefined4 *)*puVar10;
          *(int *)(DAT_00016e4c + 0x172f4) = *(int *)(DAT_00016e4c + 0x172f4) + -1;
        }
        else {
          if (__ptr[5] - 8 < 4) {
            iVar9 = iVar9 + 1;
          }
          FUN_00014df8(__ptr,&local_44,0x20);
          FUN_00013dfc(__ptr);
          local_68 = local_68 + 1;
          FUN_00014e68(__ptr,&local_44,pFVar8);
          FUN_00016984(__ptr,&local_44,__stream,local_68);
          FUN_0001b780(__ptr,&local_44);
          puVar6 = (undefined4 *)*__ptr;
          if ((undefined4 *)*puVar10 != __ptr) {
LAB_00016dec:
            puVar10 = __ptr;
          }
        }
      }
      local_7c = local_7c + 1;
      local_78 = local_78 + 1;
    } while (local_7c != 0x20);
    FUN_0001c45c(pFVar8,&local_68);
    if (pFVar8 != (FILE *)0x0) {
      fclose(pFVar8);
    }
    if (*piVar3 == 0) {
      pFVar8 = fopen((char *)(DAT_00016e38 + 0x16c3c),(char *)(DAT_00016e34 + 0x16c38));
      if (pFVar8 != (FILE *)0x0) {
        local_68 = local_68 + -1;
        __fprintf_chk(pFVar8,1,DAT_00016e3c + 0x16c60,local_68 - iVar9);
        fclose(pFVar8);
      }
      FUN_00017310(DAT_00016e44 + 0x16c80,DAT_00016e40 + 0x16c7c);
    }
    FUN_000156d4();
    FUN_000142d0();
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    FUN_0001ba98();
    FUN_0001672c();
  }
  if (local_24 == **(int **)(DAT_00016e24 + 0x16b84 + DAT_00016e00)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ADDRESS 00016594 FUNCTION FUN_00016594 =====

void FUN_00016594(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_224 [512];
  int local_24;
  
  iVar1 = DAT_00016710;
  local_24 = **(int **)(DAT_00016708 + 0x165a8 + DAT_0001670c);
  local_224[0] = '\0';
  local_224[1] = '\0';
  local_224[2] = '\0';
  local_224[3] = '\0';
  memset(local_224 + 4,0,0x1fc);
  system((char *)(DAT_00016714 + 0x165e0));
  __stream = fopen((char *)(DAT_0001671c + 0x165f4),(char *)(DAT_00016718 + 0x165f0));
  if (__stream == (FILE *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_0001637c(__stream);
    iVar6 = DAT_00016720;
    fgets(local_224,0x200,__stream);
    iVar6 = iVar6 + 0x16624;
LAB_00016620:
    pcVar3 = fgets(local_224,0x200,__stream);
    if (pcVar3 != (char *)0x0) {
      FUN_00017ec8(local_224,iVar6);
      pcVar3 = (char *)FUN_00017ec8(0,iVar6);
      if (*pcVar3 != '\0') {
        FUN_000178c8();
        iVar4 = FUN_00014238(pcVar3);
        if (iVar4 != 0) {
          if ((*(int *)(iVar4 + 0x14) == 7) || (**(int **)(iVar1 + 0x165dc + DAT_00016728) != 0)) {
            uVar2 = 0;
          }
          else {
            FUN_00017ec8(0,iVar6);
            pcVar3 = (char *)FUN_00017ec8(0,iVar6);
            iVar5 = atoi(pcVar3);
            if (0xef < iVar5) goto LAB_00016620;
            uVar2 = 7;
          }
          *(undefined4 *)(iVar4 + 0xb0) = uVar2;
        }
      }
      goto LAB_00016620;
    }
    fclose(__stream);
    FUN_000163c0();
    uVar2 = 0;
  }
  if (local_24 == **(int **)(DAT_00016724 + 0x16658 + DAT_0001670c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

REFERENCE 0001e28c OWNER FUN_0001e26c

void FUN_0001e26c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0001e29c;
  iVar2 = *(int *)(DAT_0001e29c + 0x1e2a4) + 1;
  *(int *)(DAT_0001e29c + 0x1e2a4) = iVar2;
  if (iVar2 != 2) {
    return;
  }
  FUN_00016594();
  *(undefined4 *)(iVar1 + 0x1e2a4) = 0;
  return;
}


===== ADDRESS 0001b4f8 FUNCTION FUN_0001b4f8 =====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0001b4f8(int param_1)

{
  in_addr iVar1;
  FILE *__stream;
  char *pcVar2;
  size_t sVar3;
  ether_addr *peVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char *__s;
  char *pcVar11;
  in_addr local_3ac;
  ether_addr local_3a8;
  undefined4 local_3a0;
  undefined4 uStack_39c;
  undefined4 local_398;
  undefined4 uStack_394;
  undefined4 local_390;
  undefined4 uStack_38c;
  char acStack_385 [32];
  char acStack_365 [32];
  char acStack_345 [32];
  char acStack_325 [128];
  char acStack_2a5 [128];
  char acStack_225 [513];
  int local_24;
  
  if (**(int **)(DAT_0001b518 + 0x1b508 + DAT_0001b51c) == 0) {
    return;
  }
  local_24 = **(int **)(DAT_0001b484 + 0x1b02c + DAT_0001b488);
  if (param_1 == 2) {
    *(undefined4 *)(DAT_0001b48c + 0x1b054) = 0;
  }
  setenv((char *)(DAT_0001b494 + 0x1b06c),(char *)(DAT_0001b490 + 0x1b068),1);
  setenv((char *)(DAT_0001b49c + 0x1b084),(char *)(DAT_0001b498 + 0x1b080),1);
  __stream = popen((char *)(DAT_0001b4a4 + 0x1b098),(char *)(DAT_0001b4a0 + 0x1b094));
  iVar8 = DAT_0001b4a8;
  if (__stream != (FILE *)0x0) {
    iVar9 = DAT_0001b4a8 + 0x1b0d4;
    while( true ) {
      pcVar11 = acStack_385 + 1;
      __s = acStack_225 + 1;
      pcVar7 = acStack_2a5 + 1;
      local_3a0 = 0;
      uStack_39c = 0;
      local_398 = 0;
      uStack_394 = 0;
      local_390 = 0;
      uStack_38c = 0;
      memset(pcVar11,0,0x20);
      local_3a8.ether_addr_octet[0] = '\0';
      local_3a8.ether_addr_octet[1] = '\0';
      local_3a8.ether_addr_octet[2] = '\0';
      local_3a8.ether_addr_octet[3] = '\0';
      local_3a8.ether_addr_octet[4] = '\0';
      local_3a8.ether_addr_octet[5] = '\0';
      memset(__s,0,0x200);
      memset(pcVar7,0,0x80);
      memset(acStack_345 + 1,0,0x20);
      pcVar2 = fgets(pcVar11,0x20,__stream);
      if (pcVar2 == (char *)0x0) break;
      sVar3 = strlen(pcVar11);
      acStack_385[sVar3] = '\0';
      peVar4 = ether_aton_r(pcVar11,&local_3a8);
      if (peVar4 == (ether_addr *)0x0) {
        uVar10 = 0x14b;
        iVar9 = DAT_0001b4ac + 0x1b188;
        iVar8 = DAT_0001b4b0 + 0x1b18c;
LAB_0001b18c:
        __printf_chk(1,iVar8,iVar9,uVar10);
        break;
      }
      pcVar11 = acStack_325 + 1;
      pcVar2 = fgets(pcVar11,0x80,__stream);
      if (pcVar2 == (char *)0x0) break;
      sVar3 = strlen(pcVar11);
      acStack_325[sVar3] = '\0';
      iVar5 = inet_aton(pcVar11,&local_3ac);
      if (iVar5 == 0) {
        local_3ac.s_addr = 0;
      }
      pcVar2 = fgets(__s,0x200,__stream);
      if (pcVar2 == (char *)0x0) {
        uVar10 = 0x156;
        iVar9 = DAT_0001b4b8 + 0x1b22c;
        iVar8 = DAT_0001b4bc + 0x1b230;
        goto LAB_0001b18c;
      }
      iVar5 = 0;
      sVar3 = strlen(__s);
      acStack_225[sVar3] = '\0';
      pcVar2 = fgets(pcVar7,0x80,__stream);
      if (pcVar2 == (char *)0x0) {
        uVar10 = 0x15b;
        iVar9 = DAT_0001b4c0 + 0x1b274;
        iVar8 = DAT_0001b4c4 + 0x1b278;
        goto LAB_0001b18c;
      }
      sVar3 = strlen(pcVar7);
      acStack_2a5[sVar3] = '\0';
      for (; pcVar2 = *(char **)(iVar9 + iVar5 * 8), pcVar2 != (char *)0x0; iVar5 = iVar5 + 1) {
        iVar6 = strcasecmp(pcVar2,pcVar7);
        if (iVar6 == 0) {
          uVar10 = *(undefined4 *)(iVar8 + iVar5 * 8 + 0x1b0d8);
          goto LAB_0001b2bc;
        }
      }
      uVar10 = 0x2f;
LAB_0001b2bc:
      pcVar2 = acStack_365 + 1;
      pcVar7 = fgets(pcVar2,0x20,__stream);
      if (pcVar7 == (char *)0x0) {
        uVar10 = 0x161;
        iVar9 = DAT_0001b4c8 + 0x1b2f0;
        iVar8 = DAT_0001b4cc + 0x1b2f4;
        goto LAB_0001b18c;
      }
      sVar3 = strlen(pcVar2);
      iVar6 = DAT_0001b4d0 + 0x1b318;
      acStack_365[sVar3] = '\0';
      iVar5 = __isoc99_fscanf(__stream,iVar6,&local_3a0);
      if (iVar5 != 1) {
        uVar10 = 0x166;
        iVar9 = DAT_0001b4d4 + 0x1b350;
        iVar8 = DAT_0001b4d8 + 0x1b354;
        goto LAB_0001b18c;
      }
      iVar5 = __isoc99_fscanf(__stream,iVar6,&local_398);
      if (iVar5 != 1) {
        uVar10 = 0x16a;
        iVar9 = DAT_0001b4dc + 0x1b384;
        iVar8 = DAT_0001b4e0 + 0x1b388;
        goto LAB_0001b18c;
      }
      iVar5 = __isoc99_fscanf(__stream,iVar6,&local_390);
      if (iVar5 != 1) {
        uVar10 = 0x16e;
        iVar9 = DAT_0001b4e4 + 0x1b3b8;
        iVar8 = DAT_0001b4e8 + 0x1b3bc;
        goto LAB_0001b18c;
      }
      pcVar11 = acStack_345 + 1;
      pcVar7 = fgets(pcVar11,0x20,__stream);
      if (pcVar7 == (char *)0x0) {
        uVar10 = 0x172;
        iVar9 = DAT_0001b4ec + 0x1b3ec;
        iVar8 = DAT_0001b4f0 + 0x1b3f0;
        goto LAB_0001b18c;
      }
      sVar3 = strlen(pcVar11);
      acStack_345[sVar3] = '\0';
      iVar5 = strcmp((char *)(DAT_0001b4f4 + 0x1b418),pcVar11);
      if (iVar5 != 0) {
        pcVar2 = pcVar11;
      }
      atoi(pcVar2);
      iVar1.s_addr = local_3ac.s_addr;
      if (local_3ac.s_addr != 0) {
        FUN_0001e8ec(local_398,uStack_394);
        FUN_0001e8ec(local_3a0,uStack_39c);
        FUN_0001ae4c(param_1,&local_3a8,iVar1.s_addr,__s,uVar10);
      }
    }
    pclose(__stream);
  }
  if (local_24 != **(int **)(DAT_0001b4b4 + 0x1b1a8 + DAT_0001b488)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

REFERENCE 0001ba28 OWNER FUN_0001ba00

void FUN_0001ba00(void)

{
  int iVar1;
  FILE *pFVar2;
  
  iVar1 = DAT_0001ba80;
  if (**(int **)(DAT_0001ba78 + 0x1ba10 + DAT_0001ba7c) == 0) {
    FUN_0001b4f8(2);
    *(int *)(iVar1 + 0x1ba40) = iVar1 + 0x1ba44;
    FUN_0001aca0();
    pFVar2 = fopen((char *)(DAT_0001ba88 + 0x1ba50),(char *)(DAT_0001ba84 + 0x1ba4c));
    *(FILE **)(iVar1 + 0x1ba38) = pFVar2;
  }
  pFVar2 = fopen((char *)(DAT_0001ba90 + 0x1ba68),(char *)(DAT_0001ba8c + 0x1ba64));
  *(FILE **)((int)&DAT_0001ba7c + DAT_0001ba94) = pFVar2;
  return;
}

REFERENCE 00015a08 OWNER FUN_00015998

void FUN_00015998(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = DAT_00015a38;
  bVar5 = false;
  iVar7 = 0;
  iVar2 = DAT_00015a30 + 0x159b4;
  piVar4 = (int *)(DAT_00015a34 + 0x15d78);
  *(undefined4 *)(DAT_00015a34 + 0x15f4c) = 0;
  iVar6 = 0;
  iVar8 = **(int **)(iVar2 + iVar8);
  do {
    for (piVar3 = (int *)*piVar4; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      uVar1 = *(undefined2 *)(piVar3 + 1);
      *(undefined1 *)(piVar3 + 0x68) = 0;
      iVar6 = iVar6 + 1;
      if (iVar8 == 0) {
        *(undefined2 *)(piVar3 + 1) = 0;
      }
      *(undefined2 *)((int)piVar3 + 6) = uVar1;
      bVar5 = true;
    }
    iVar7 = iVar7 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar7 != 0x20);
  if (bVar5) {
    *(int *)(DAT_00015a3c + 0x15f94) = iVar6;
  }
  FUN_0001b4f8(1);
  return;
}


===== ADDRESS 0001c2a8 FUNCTION FUN_0001c2a8 =====

undefined4 FUN_0001c2a8(undefined4 param_1,char *param_2)

{
  FILE *__stream;
  char *pcVar1;
  char *pcVar2;
  ether_addr *peVar3;
  undefined4 uVar4;
  char local_44 [40];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001c428 + 0x1c2b8 + DAT_0001c42c);
  local_44[0] = '\0';
  local_44[1] = '\0';
  local_44[2] = '\0';
  local_44[3] = '\0';
  memset(local_44 + 4,0,0x24);
  dni_safe_system(DAT_0001c434 + 0x1c310,0,0,DAT_0001c448 + 0x1c34c,DAT_0001c444 + 0x1c340,
                  DAT_0001c440 + 0x1c334,DAT_0001c43c + 0x1c328,DAT_0001c438 + 0x1c318,
                  DAT_0001c430 + 0x1c304,param_1,0);
  system((char *)(DAT_0001c44c + 0x1c358));
  __stream = fopen((char *)(DAT_0001c454 + 0x1c36c),(char *)(DAT_0001c450 + 0x1c368));
  if (__stream == (FILE *)0x0) {
    uVar4 = 0;
  }
  else {
    do {
      pcVar1 = fgets(local_44,0x28,__stream);
      if (pcVar1 == (char *)0x0) goto LAB_0001c3ec;
      pcVar1 = strchr(local_44,0x5b);
    } while (pcVar1 == (char *)0x0);
    pcVar2 = strchr(local_44,0x5d);
    strncpy(param_2,pcVar1 + 1,(int)pcVar2 - (int)(pcVar1 + 1));
    peVar3 = ether_aton(param_2);
    if (peVar3 == (ether_addr *)0x0) {
LAB_0001c3ec:
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
      FUN_0001760c(peVar3,param_2);
    }
    fclose(__stream);
  }
  if (local_1c == **(int **)(DAT_0001c458 + 0x1c408 + DAT_0001c42c)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

REFERENCE 0001c624 OWNER FUN_0001c45c

void FUN_0001c45c(undefined4 param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  ether_addr *peVar6;
  int iVar7;
  char *__needle;
  char *__needle_00;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint local_2ac;
  undefined1 auStack_2a8 [16];
  char local_298 [40];
  char local_270 [128];
  undefined1 auStack_1f0 [8];
  in_addr iStack_1e8;
  undefined4 local_1e4;
  undefined2 local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined1 auStack_1b1 [117];
  undefined1 auStack_13c [280];
  int local_24;
  
  bVar2 = 0;
  iVar7 = DAT_0001c7e8 + 0x1c47c;
  local_24 = **(int **)(DAT_0001c7ec + 0x1c488 + DAT_0001c7f0);
  local_270[0] = '\0';
  local_270[1] = '\0';
  local_270[2] = '\0';
  local_270[3] = '\0';
  memset(local_270 + 4,0,0x7c);
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  memset(local_298 + 4,0,0x24);
  local_2ac = 0;
  memset(auStack_2a8,0,0x10);
  __stream = fopen((char *)(DAT_0001c7f8 + 0x1c4e8),(char *)(DAT_0001c7f4 + 0x1c4e4));
  if (__stream != (FILE *)0x0) {
    __stream_00 = fopen((char *)(DAT_0001c800 + 0x1c504),(char *)(DAT_0001c7fc + 0x1c500));
    __needle = (char *)(DAT_0001c804 + 0x1c510);
    __needle_00 = (char *)(DAT_0001c808 + 0x1c51c);
    while( true ) {
      pcVar3 = fgets(local_270,0x80,__stream);
      if (pcVar3 == (char *)0x0) break;
      pcVar3 = strcasestr(local_270,__needle);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = strcasestr(local_270,__needle_00);
        bVar1 = (bool)(bVar2 ^ 1);
        if (pcVar3 != (char *)0x0) {
          bVar1 = true;
        }
        if (!bVar1) {
          iVar9 = DAT_0001c810 + 0x1c5c8;
          pcVar3 = (char *)FUN_00017ec8(local_270,iVar9);
          FUN_00017ec8(0,iVar9);
          pcVar4 = (char *)FUN_00017ec8(0,DAT_0001c814 + 0x1c5ec);
          pcVar5 = (char *)FUN_00017ec8(0,iVar9);
          if ((*pcVar4 != '\0') && (*pcVar5 != '\0')) {
            iVar9 = FUN_0001c2a8(pcVar4,local_298);
            if (iVar9 == 0) {
              strcpy(local_298,(char *)(DAT_0001c818 + 0x1c640));
            }
            FUN_000178c8(local_298);
            memset(auStack_1f0,0,0x1c8);
            peVar6 = ether_aton(local_298);
            local_1e4 = *(undefined4 *)peVar6->ether_addr_octet;
            local_1e0 = *(undefined2 *)(peVar6->ether_addr_octet + 4);
            iVar9 = inet_aton(pcVar3,&iStack_1e8);
            if (iVar9 != 0) {
              iVar10 = DAT_0001c81c + 0x1c6a4;
              local_1d8 = 0x13;
              uStack_1d4 = 0;
              FUN_00017018(auStack_13c,iVar10,0x20);
              FUN_00017018(auStack_1b1,DAT_0001c820 + 0x1c6c4,0x40);
              FUN_00013dfc(auStack_1f0);
              iVar9 = DAT_0001c824 + 0x1c6e8;
              *param_2 = *param_2 + 1;
              FUN_00014e68(auStack_1f0,iVar9,param_1);
              FUN_00014e68(auStack_1f0,iVar10,__stream_00,*param_2);
              if (**(int **)(iVar7 + DAT_0001c828) == 0) {
                FUN_00017018(&local_2ac,DAT_0001c82c + 0x1c730,0x14);
              }
              iVar9 = FUN_0001bdb4(DAT_0001c830 + 0x1c744,pcVar4,pcVar5);
              if (iVar9 != 0) {
                __snprintf_chk(&local_2ac,0x14,1,0x14,DAT_0001c834 + 0x1c764,iVar9);
              }
              if (__stream_00 != (FILE *)0x0) {
                pcVar3 = pcVar4;
                if (*pcVar4 == '\0') {
                  pcVar3 = (char *)(DAT_0001c838 + 0x1c790);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c83c + 0x1c7a0,pcVar3);
                puVar8 = &local_2ac;
                if ((local_2ac & 0xff) == 0) {
                  puVar8 = (uint *)(DAT_0001c840 + 0x1c7b8);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c844 + 0x1c7c8,puVar8);
              }
              FUN_0001b520(auStack_1f0,pcVar4,&local_2ac,1);
            }
          }
          goto LAB_0001c58c;
        }
        bVar2 = 0;
      }
      else {
LAB_0001c58c:
        bVar2 = 1;
      }
    }
    fclose(__stream);
    if (__stream_00 != (FILE *)0x0) {
      fclose(__stream_00);
    }
  }
  if (local_24 != **(int **)(DAT_0001c80c + 0x1c564 + DAT_0001c7f0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ADDRESS 0001c45c FUNCTION FUN_0001c45c =====

void FUN_0001c45c(undefined4 param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  ether_addr *peVar6;
  int iVar7;
  char *__needle;
  char *__needle_00;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint local_2ac;
  undefined1 auStack_2a8 [16];
  char local_298 [40];
  char local_270 [128];
  undefined1 auStack_1f0 [8];
  in_addr iStack_1e8;
  undefined4 local_1e4;
  undefined2 local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined1 auStack_1b1 [117];
  undefined1 auStack_13c [280];
  int local_24;
  
  bVar2 = 0;
  iVar7 = DAT_0001c7e8 + 0x1c47c;
  local_24 = **(int **)(DAT_0001c7ec + 0x1c488 + DAT_0001c7f0);
  local_270[0] = '\0';
  local_270[1] = '\0';
  local_270[2] = '\0';
  local_270[3] = '\0';
  memset(local_270 + 4,0,0x7c);
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  memset(local_298 + 4,0,0x24);
  local_2ac = 0;
  memset(auStack_2a8,0,0x10);
  __stream = fopen((char *)(DAT_0001c7f8 + 0x1c4e8),(char *)(DAT_0001c7f4 + 0x1c4e4));
  if (__stream != (FILE *)0x0) {
    __stream_00 = fopen((char *)(DAT_0001c800 + 0x1c504),(char *)(DAT_0001c7fc + 0x1c500));
    __needle = (char *)(DAT_0001c804 + 0x1c510);
    __needle_00 = (char *)(DAT_0001c808 + 0x1c51c);
    while( true ) {
      pcVar3 = fgets(local_270,0x80,__stream);
      if (pcVar3 == (char *)0x0) break;
      pcVar3 = strcasestr(local_270,__needle);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = strcasestr(local_270,__needle_00);
        bVar1 = (bool)(bVar2 ^ 1);
        if (pcVar3 != (char *)0x0) {
          bVar1 = true;
        }
        if (!bVar1) {
          iVar9 = DAT_0001c810 + 0x1c5c8;
          pcVar3 = (char *)FUN_00017ec8(local_270,iVar9);
          FUN_00017ec8(0,iVar9);
          pcVar4 = (char *)FUN_00017ec8(0,DAT_0001c814 + 0x1c5ec);
          pcVar5 = (char *)FUN_00017ec8(0,iVar9);
          if ((*pcVar4 != '\0') && (*pcVar5 != '\0')) {
            iVar9 = FUN_0001c2a8(pcVar4,local_298);
            if (iVar9 == 0) {
              strcpy(local_298,(char *)(DAT_0001c818 + 0x1c640));
            }
            FUN_000178c8(local_298);
            memset(auStack_1f0,0,0x1c8);
            peVar6 = ether_aton(local_298);
            local_1e4 = *(undefined4 *)peVar6->ether_addr_octet;
            local_1e0 = *(undefined2 *)(peVar6->ether_addr_octet + 4);
            iVar9 = inet_aton(pcVar3,&iStack_1e8);
            if (iVar9 != 0) {
              iVar10 = DAT_0001c81c + 0x1c6a4;
              local_1d8 = 0x13;
              uStack_1d4 = 0;
              FUN_00017018(auStack_13c,iVar10,0x20);
              FUN_00017018(auStack_1b1,DAT_0001c820 + 0x1c6c4,0x40);
              FUN_00013dfc(auStack_1f0);
              iVar9 = DAT_0001c824 + 0x1c6e8;
              *param_2 = *param_2 + 1;
              FUN_00014e68(auStack_1f0,iVar9,param_1);
              FUN_00014e68(auStack_1f0,iVar10,__stream_00,*param_2);
              if (**(int **)(iVar7 + DAT_0001c828) == 0) {
                FUN_00017018(&local_2ac,DAT_0001c82c + 0x1c730,0x14);
              }
              iVar9 = FUN_0001bdb4(DAT_0001c830 + 0x1c744,pcVar4,pcVar5);
              if (iVar9 != 0) {
                __snprintf_chk(&local_2ac,0x14,1,0x14,DAT_0001c834 + 0x1c764,iVar9);
              }
              if (__stream_00 != (FILE *)0x0) {
                pcVar3 = pcVar4;
                if (*pcVar4 == '\0') {
                  pcVar3 = (char *)(DAT_0001c838 + 0x1c790);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c83c + 0x1c7a0,pcVar3);
                puVar8 = &local_2ac;
                if ((local_2ac & 0xff) == 0) {
                  puVar8 = (uint *)(DAT_0001c840 + 0x1c7b8);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c844 + 0x1c7c8,puVar8);
              }
              FUN_0001b520(auStack_1f0,pcVar4,&local_2ac,1);
            }
          }
          goto LAB_0001c58c;
        }
        bVar2 = 0;
      }
      else {
LAB_0001c58c:
        bVar2 = 1;
      }
    }
    fclose(__stream);
    if (__stream_00 != (FILE *)0x0) {
      fclose(__stream_00);
    }
  }
  if (local_24 != **(int **)(DAT_0001c80c + 0x1c564 + DAT_0001c7f0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

REFERENCE 00016c04 OWNER FUN_00016aa8

void FUN_00016aa8(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *__ptr;
  FILE *pFVar8;
  int iVar9;
  undefined4 *puVar10;
  uint local_80;
  int local_7c;
  undefined4 *local_78;
  int local_68;
  undefined1 auStack_64 [32];
  undefined4 local_44;
  undefined1 auStack_40 [28];
  int local_24;
  
  pFVar8 = (FILE *)0x0;
  local_24 = **(int **)(DAT_00016dfc + 0x16ab8 + DAT_00016e00);
  pcVar7 = (char *)(DAT_00016e04 + 0x16ae8);
  local_44 = 0;
  memset(auStack_40,0,0x1c);
  local_68 = 0;
  FUN_0001ba00();
  FUN_00015680();
  iVar1 = DAT_00016e0c;
  __stream = fopen((char *)(DAT_00016e08 + 0x16b0c),pcVar7);
  piVar3 = *(int **)(iVar1 + 0x16b18 + DAT_00016e10);
  if ((*piVar3 == 0) &&
     (pFVar8 = fopen((char *)(DAT_00016e14 + 0x16b3c),pcVar7), pFVar8 == (FILE *)0x0)) {
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    FUN_00017c04(DAT_00016e20 + 0x16b74,0x48f,DAT_00016e1c + 0x16b70,DAT_00016e18 + 0x16b6c);
  }
  else {
    iVar5 = DAT_00016e28;
    FUN_00015394();
    iVar9 = 0;
    local_7c = 0;
    local_80 = 0;
    iVar4 = DAT_00016e2c + 0x16bc4;
    local_78 = (undefined4 *)(iVar5 + 0x16f70);
    do {
      iVar5 = DAT_00016e30 + 0x16be0;
      puVar6 = (undefined4 *)*local_78;
      puVar10 = local_78;
      while (__ptr = puVar6, __ptr != (undefined4 *)0x0) {
        local_80 = local_80 + 1;
        if ((*(short *)(__ptr + 1) == 0) ||
           ((**(int **)(iVar1 + 0x16b18 + DAT_00016e48) == 2 && (__ptr[7] == 1)))) {
          uVar2 = FUN_0001760c(__ptr + 3,auStack_64);
          pcVar7 = inet_ntoa((in_addr)__ptr[2]);
          FUN_00017c04(iVar5,0x499,iVar4,uVar2,pcVar7);
          puVar6 = (undefined4 *)*__ptr;
          if ((*piVar3 != 0 || local_80 < 0x100) || (__ptr[7] == 2)) goto LAB_00016dec;
          *puVar10 = puVar6;
          free(__ptr);
          puVar6 = (undefined4 *)*puVar10;
          *(int *)(DAT_00016e4c + 0x172f4) = *(int *)(DAT_00016e4c + 0x172f4) + -1;
        }
        else {
          if (__ptr[5] - 8 < 4) {
            iVar9 = iVar9 + 1;
          }
          FUN_00014df8(__ptr,&local_44,0x20);
          FUN_00013dfc(__ptr);
          local_68 = local_68 + 1;
          FUN_00014e68(__ptr,&local_44,pFVar8);
          FUN_00016984(__ptr,&local_44,__stream,local_68);
          FUN_0001b780(__ptr,&local_44);
          puVar6 = (undefined4 *)*__ptr;
          if ((undefined4 *)*puVar10 != __ptr) {
LAB_00016dec:
            puVar10 = __ptr;
          }
        }
      }
      local_7c = local_7c + 1;
      local_78 = local_78 + 1;
    } while (local_7c != 0x20);
    FUN_0001c45c(pFVar8,&local_68);
    if (pFVar8 != (FILE *)0x0) {
      fclose(pFVar8);
    }
    if (*piVar3 == 0) {
      pFVar8 = fopen((char *)(DAT_00016e38 + 0x16c3c),(char *)(DAT_00016e34 + 0x16c38));
      if (pFVar8 != (FILE *)0x0) {
        local_68 = local_68 + -1;
        __fprintf_chk(pFVar8,1,DAT_00016e3c + 0x16c60,local_68 - iVar9);
        fclose(pFVar8);
      }
      FUN_00017310(DAT_00016e44 + 0x16c80,DAT_00016e40 + 0x16c7c);
    }
    FUN_000156d4();
    FUN_000142d0();
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    FUN_0001ba98();
    FUN_0001672c();
  }
  if (local_24 == **(int **)(DAT_00016e24 + 0x16b84 + DAT_00016e00)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ADDRESS 0001cf70 FUNCTION FUN_0001cf70 =====

void FUN_0001cf70(int param_1)

{
  FILE *__stream;
  char *pcVar1;
  char *__cp;
  int iVar2;
  char *pcVar3;
  char acStack_144 [32];
  char acStack_124 [256];
  int local_24;
  
  local_24 = **(int **)(DAT_0001d0a0 + 0x1cf84 + DAT_0001d0a4);
  FUN_0001760c(param_1 + 0xc,acStack_144,DAT_0001d0a0 + 0x1cf84,0);
  __stream = fopen((char *)(DAT_0001d0ac + 0x1cfbc),(char *)(DAT_0001d0a8 + 0x1cfb8));
  if (__stream != (FILE *)0x0) {
    pcVar3 = (char *)(DAT_0001d0b0 + 0x1cfd4);
    do {
      pcVar1 = fgets(acStack_124,0x100,__stream);
      if (pcVar1 == (char *)0x0) goto LAB_0001d06c;
      pcVar1 = strtok(acStack_124,pcVar3);
      __cp = strtok((char *)0x0,pcVar3);
    } while ((__cp == (char *)0x0 || pcVar1 == (char *)0x0) ||
            (iVar2 = strcmp(pcVar1,acStack_144), iVar2 != 0));
    inet_aton(__cp,(in_addr *)(param_1 + 8));
    *(undefined4 *)(param_1 + 0x1c) = 2;
    pcVar3 = (char *)(DAT_0001d0b4 + 0x1d054);
    if (*(int *)(param_1 + 0x14) == 0) {
      *(undefined4 *)(param_1 + 0x14) = 8;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    strcpy((char *)(param_1 + 0x20),pcVar3);
    FUN_0001cda0(acStack_144);
LAB_0001d06c:
    fclose(__stream);
  }
  if (local_24 == **(int **)(DAT_0001d0b8 + 0x1d084 + DAT_0001d0a4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

REFERENCE 0001365c OWNER FUN_000134a8

void FUN_000134a8(int param_1,FILE *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char *__s2;
  size_t __n;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_244 [32];
  char acStack_224 [512];
  int local_24;
  
  iVar6 = DAT_00013724 + 0x134d0;
  local_24 = **(int **)(DAT_00013720 + 0x134cc + DAT_0001371c);
  if (param_1 != 0 && param_2 != (FILE *)0x0) {
    fseek(param_2,0,0);
    iVar4 = DAT_0001372c;
    FUN_0001760c(param_1 + 0xc,acStack_244);
    fgets(acStack_224,0x200,param_2);
    do {
      do {
        pcVar2 = fgets(acStack_224,0x200,param_2);
        if (pcVar2 == (char *)0x0) goto LAB_000134f0;
        pcVar2 = strtok(acStack_224,(char *)(iVar4 + 0x1355c));
        __s2 = strtok((char *)0x0,(char *)(iVar4 + 0x1355c));
      } while (__s2 == (char *)0x0 || pcVar2 == (char *)0x0);
      FUN_000178c8();
      __n = strlen(acStack_244);
      iVar3 = strncmp(acStack_244,__s2,__n);
    } while (iVar3 != 0);
    iVar4 = atoi(pcVar2);
    iVar3 = FUN_0001c244(param_1,iVar4);
    uVar1 = 0;
    if (iVar3 == 0) goto LAB_000134f4;
    pcVar2 = (char *)(DAT_00013730 + 0x135f4);
    iVar3 = 0;
    do {
      if (*pcVar2 == '\0') break;
      if (*(int *)(pcVar2 + 0x34) == iVar4) {
        *(undefined4 *)(param_1 + 0x1c) = 0;
        iVar5 = *(int *)(iVar3 * 0x3c + DAT_00013734 + 0x13670);
        if (iVar5 == 8) {
          *(undefined4 *)(param_1 + 0x1c) = 1;
LAB_00013658:
          FUN_0001cf70(param_1);
          if ((**(int **)(iVar6 + DAT_00013738) != 0) &&
             (*(int *)(iVar3 * 0x3c + DAT_0001373c + 0x136bc) == 7)) {
            FUN_0001dd70(param_1,acStack_244,param_3);
          }
        }
        else if (iVar5 - 7U < 2) goto LAB_00013658;
        FUN_000133c8(iVar3,param_1);
        if (*(int *)(param_1 + 0x1c) == 2) {
          FUN_0001d1fc(param_1);
        }
        if (*(int *)(param_1 + 0x14) == 8) {
          FUN_0001d1fc(param_1);
          FUN_0001cf70(param_1);
        }
        FUN_00017c04(DAT_00013744 + 0x13704,0xb9,DAT_00013740 + 0x136fc,acStack_244,
                     *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c),iVar4);
        uVar1 = 0;
        goto LAB_000134f4;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x3c;
    } while (iVar3 != 0x10);
  }
LAB_000134f0:
  uVar1 = 0xffffffff;
LAB_000134f4:
  if (local_24 == **(int **)(DAT_00013728 + 0x13504 + DAT_0001371c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

REFERENCE 000136d8 OWNER FUN_000134a8

void FUN_000134a8(int param_1,FILE *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char *__s2;
  size_t __n;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_244 [32];
  char acStack_224 [512];
  int local_24;
  
  iVar6 = DAT_00013724 + 0x134d0;
  local_24 = **(int **)(DAT_00013720 + 0x134cc + DAT_0001371c);
  if (param_1 != 0 && param_2 != (FILE *)0x0) {
    fseek(param_2,0,0);
    iVar4 = DAT_0001372c;
    FUN_0001760c(param_1 + 0xc,acStack_244);
    fgets(acStack_224,0x200,param_2);
    do {
      do {
        pcVar2 = fgets(acStack_224,0x200,param_2);
        if (pcVar2 == (char *)0x0) goto LAB_000134f0;
        pcVar2 = strtok(acStack_224,(char *)(iVar4 + 0x1355c));
        __s2 = strtok((char *)0x0,(char *)(iVar4 + 0x1355c));
      } while (__s2 == (char *)0x0 || pcVar2 == (char *)0x0);
      FUN_000178c8();
      __n = strlen(acStack_244);
      iVar3 = strncmp(acStack_244,__s2,__n);
    } while (iVar3 != 0);
    iVar4 = atoi(pcVar2);
    iVar3 = FUN_0001c244(param_1,iVar4);
    uVar1 = 0;
    if (iVar3 == 0) goto LAB_000134f4;
    pcVar2 = (char *)(DAT_00013730 + 0x135f4);
    iVar3 = 0;
    do {
      if (*pcVar2 == '\0') break;
      if (*(int *)(pcVar2 + 0x34) == iVar4) {
        *(undefined4 *)(param_1 + 0x1c) = 0;
        iVar5 = *(int *)(iVar3 * 0x3c + DAT_00013734 + 0x13670);
        if (iVar5 == 8) {
          *(undefined4 *)(param_1 + 0x1c) = 1;
LAB_00013658:
          FUN_0001cf70(param_1);
          if ((**(int **)(iVar6 + DAT_00013738) != 0) &&
             (*(int *)(iVar3 * 0x3c + DAT_0001373c + 0x136bc) == 7)) {
            FUN_0001dd70(param_1,acStack_244,param_3);
          }
        }
        else if (iVar5 - 7U < 2) goto LAB_00013658;
        FUN_000133c8(iVar3,param_1);
        if (*(int *)(param_1 + 0x1c) == 2) {
          FUN_0001d1fc(param_1);
        }
        if (*(int *)(param_1 + 0x14) == 8) {
          FUN_0001d1fc(param_1);
          FUN_0001cf70(param_1);
        }
        FUN_00017c04(DAT_00013744 + 0x13704,0xb9,DAT_00013740 + 0x136fc,acStack_244,
                     *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x1c),iVar4);
        uVar1 = 0;
        goto LAB_000134f4;
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x3c;
    } while (iVar3 != 0x10);
  }
LAB_000134f0:
  uVar1 = 0xffffffff;
LAB_000134f4:
  if (local_24 == **(int **)(DAT_00013728 + 0x13504 + DAT_0001371c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}


===== ADDRESS 0001da20 FUNCTION FUN_0001da20 =====

void FUN_0001da20(char *param_1,FILE *param_2)

{
  char *pcVar1;
  char *__s1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_a4 [128];
  int local_24;
  
  local_24 = **(int **)(DAT_0001db9c + 0x1da30 + DAT_0001dba0);
  local_a4[0] = '\0';
  local_a4[1] = '\0';
  local_a4[2] = '\0';
  local_a4[3] = '\0';
  memset(local_a4 + 4,0,0x7c);
  iVar3 = DAT_0001dba4;
  fseek(param_2,0,0);
  pcVar4 = (char *)(DAT_0001dba8 + 0x1da88);
  do {
    pcVar1 = fgets(local_a4,0x80,param_2);
    if (pcVar1 == (char *)0x0) goto LAB_0001daf8;
    pcVar1 = strtok(local_a4,(char *)(iVar3 + 0x1da84));
    __s1 = strtok((char *)0x0,pcVar4);
  } while ((__s1 == (char *)0x0 || pcVar1 == (char *)0x0) ||
          (iVar2 = strcmp(pcVar1,param_1), iVar2 != 0));
  iVar3 = strcmp(__s1,(char *)(DAT_0001dbac + 0x1daf0));
  if (iVar3 != 0) {
    pcVar1 = (char *)(DAT_0001dbb4 + 0x1db2c);
    iVar3 = 0;
    pcVar4 = pcVar1;
    do {
      iVar2 = strcmp(pcVar4,__s1);
      if (iVar2 == 0) goto LAB_0001daf8;
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 2;
    } while (iVar3 != 4);
    pcVar4 = (char *)(DAT_0001dbb8 + 0x1db5c);
    iVar3 = 0;
    do {
      iVar2 = strcmp(pcVar1,pcVar4);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 2;
    } while (iVar3 != 4);
    strcpy((char *)(DAT_0001dbbc + 0x1db8c + iVar3 * 2),__s1);
  }
LAB_0001daf8:
  if (local_24 != **(int **)(DAT_0001dbb0 + 0x1db08 + DAT_0001dba0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

REFERENCE 0001dd30 OWNER FUN_00013090

void FUN_00013090(void)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  FILE *__stream_00;
  undefined4 uVar3;
  char *pcVar4;
  char acStack_9c [128];
  int iStack_1c;
  
  iVar1 = DAT_000130dc;
  system((char *)(DAT_000130d8 + 0x130a0));
  iVar2 = DAT_0001dd48;
  if (**(int **)(iVar1 + 78000 + DAT_000130e0) == 0) {
    return;
  }
  if (**(int **)(iVar1 + 78000 + DAT_000130e4) == 0) {
    return;
  }
  iStack_1c = **(int **)(DAT_0001dd40 + 0x1dbd4 + DAT_0001dd44);
  acStack_9c[0] = '\0';
  acStack_9c[1] = '\0';
  acStack_9c[2] = '\0';
  acStack_9c[3] = '\0';
  memset(acStack_9c + 4,0,0x7c);
  iVar1 = DAT_0001dd50;
  system((char *)(DAT_0001dd4c + 0x1dc10));
  FUN_00017310(DAT_0001dd54 + 0x1dc24,(char *)(iVar2 + 0x1dc08));
  system((char *)(DAT_0001dd58 + 0x1dc30));
  __stream = fopen((char *)(iVar2 + 0x1dc08),(char *)(iVar1 + 0x1dc20));
  __stream_00 = fopen((char *)(DAT_0001dd5c + 0x1dc50),(char *)(iVar1 + 0x1dc20));
  iVar1 = DAT_0001dd68;
  if (__stream_00 == (FILE *)0x0 || __stream == (FILE *)0x0) {
    if (__stream != (FILE *)0x0) {
      fclose(__stream);
    }
    if (__stream_00 != (FILE *)0x0) {
LAB_0001dc78:
      fclose(__stream_00);
    }
    if (iStack_1c != **(int **)(DAT_0001dd60 + 0x1dc90 + DAT_0001dd44)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  pcVar4 = (char *)(DAT_0001dd64 + 0x1dcb4);
  strcpy((char *)(DAT_0001dd68 + 0x1dcb8),pcVar4);
  strcpy((char *)(iVar1 + 0x1dcba),pcVar4);
  strcpy((char *)(iVar1 + 0x1dcbc),pcVar4);
  iVar2 = DAT_0001dd6c;
  strcpy((char *)(iVar1 + 0x1dcbe),pcVar4);
  do {
    do {
      pcVar4 = fgets(acStack_9c,0x80,__stream);
      if (pcVar4 == (char *)0x0) {
        fclose(__stream);
        goto LAB_0001dc78;
      }
      pcVar4 = strtok(acStack_9c,(char *)(iVar2 + 0x1dcf0));
    } while (pcVar4 == (char *)0x0);
    uVar3 = FUN_0001d948();
    FUN_0001da20(uVar3,__stream_00);
  } while( true );
}

