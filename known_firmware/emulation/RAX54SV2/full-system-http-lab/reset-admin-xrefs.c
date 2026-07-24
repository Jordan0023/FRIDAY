STRING 00148fb8 http_passwd
REF 0002eda0 owner=FUN_0002c068
REF 0002bce4 owner=FUN_0002bc94
STRING 00148fd6 http_passwd_digest
REF 00064370 owner=FUN_00064274
REF 000644e4 owner=FUN_00064274
REF 00064548 owner=FUN_00064274
REF 00064750 owner=FUN_00064274
REF 0002bd3c owner=FUN_0002bc94
REF 0002bd88 owner=FUN_0002bc94
REF 00113780 owner=FUN_001134c4
REF 001137f8 owner=FUN_001134c4
STRING 00149459 enable_password_recovery
REF 0002d854 owner=FUN_0002c068
REF 0002d8fc owner=FUN_0002c068
REF 0002e270 owner=FUN_0002c068
REF 000645f4 owner=FUN_00064274
REF 00064604 owner=FUN_00064274
REF 000646f0 owner=FUN_00064274
REF 0003c3ec owner=FUN_0003c2e4
STRING 0015184d nvram_get("password_question1");
STRING 0015a09a nvram_get("enable_password_recovery");
STRING 00179dbb password_answer1
REF 00064690 owner=FUN_00064274
STRING 0017a9c9 password_question1
REF 00064630 owner=FUN_00064274
STRING 00181a6f ResetAdminPassword
STRING 001bdff4 RecoverAdminPassword
STRING 001be0f8 RecoverAdminPassword
STRING 001be1fc RecoverAdminPassword
STRING 001be300 RecoverAdminPassword
STRING 001be404 RecoverAdminPassword
CALLER_REF target=FUN_0002c068 from=00037ff8 owner=FUN_00033724
CALLER_REF target=FUN_0002c068 from=00038178 owner=FUN_000381f0
CALLER_REF target=FUN_0002bc94 from=0002ddb4 owner=FUN_0002c068
CALLER_REF target=FUN_001134c4 from=0011a01c owner=FUN_00119f04
CALLER_REF target=FUN_001134c4 from=0011a170 owner=FUN_00119f04
CALLER_REF target=FUN_0003c2e4 from=0002c364 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002d8bc owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002db2c owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002dba4 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002df80 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002e494 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0002eb44 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=000305a0 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0003072c owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00030800 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=000322f0 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032444 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032954 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0003087c owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032d2c owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032aa0 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032db4 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032e74 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=00032f34 owner=FUN_0002c068
CALLER_REF target=FUN_0003c2e4 from=0003c6ec owner=FUN_0003c688
CALLER_REF target=FUN_0003c2e4 from=0003d194 owner=FUN_0003c834
CALLER_REF target=FUN_0003c2e4 from=00059558 owner=FUN_000594cc
CALLER_REF target=FUN_0003c2e4 from=0014748c owner=FUN_00147454

===== FUN_0002c068 @ 0002c068 =====
DECOMPILE_FAILED


===== FUN_0002bc94 @ 0002bc94 =====

void FUN_0002bc94(char *param_1,undefined4 param_2)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  char *__s_00;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char local_a4 [128];
  int local_24;
  
  iVar7 = DAT_0002bdd0;
  piVar8 = *(int **)(DAT_0002bdc4 + 0x2bca4 + DAT_0002bdc8);
  local_24 = *piVar8;
  __s = (char *)acosNvramConfig_get(DAT_0002bdcc + 0x2bccc);
  acosNvramConfig_get(DAT_0002bdd4 + 0x2bcec);
  acosNvramConfig_get(DAT_0002bdd8 + 0x2bcf8);
  sVar1 = strlen(param_1);
  sVar2 = strlen(__s);
  local_a4[0] = '\0';
  local_a4[1] = '\0';
  local_a4[2] = '\0';
  local_a4[3] = '\0';
  memset(local_a4 + 4,0,0x7c);
  FUN_00064034(param_2,local_a4);
  sVar3 = strlen(local_a4);
  __s_00 = (char *)acosNvramConfig_get(iVar7 + 0x2bce0);
  sVar4 = strlen(__s_00);
  if (sVar4 == sVar3 && sVar2 == sVar1) {
    iVar6 = ambit_mem_compare(param_1,__s,sVar1);
    uVar5 = 0;
    if (iVar6 != 0) {
      uVar5 = acosNvramConfig_get(iVar7 + 0x2bce0);
      iVar7 = ambit_mem_compare(local_a4,uVar5,sVar3);
      uVar5 = 0;
      if (iVar7 != 0) {
        uVar5 = 1;
      }
    }
  }
  else {
    puts((char *)(DAT_0002bddc + 0x2bd68));
    uVar5 = 0;
  }
  if (local_24 != *piVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



===== FUN_00064274 @ 00064274 =====

void FUN_00064274(undefined4 param_1,int param_2)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  FILE *pFVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  bool bVar11;
  char acStack_40c4 [32];
  char local_40a4 [128];
  char local_4024 [2048];
  char local_3824 [2048];
  undefined1 auStack_3024 [2048];
  char local_2824 [2048];
  char local_2024 [2048];
  undefined1 auStack_1824 [2048];
  undefined1 auStack_1024 [2048];
  char local_824 [2048];
  int local_24;
  
  iVar8 = DAT_000647d0 + 0x64294;
  piVar9 = *(int **)(iVar8 + DAT_000647d4);
  local_40a4[0] = '\0';
  local_40a4[1] = '\0';
  local_40a4[2] = '\0';
  local_40a4[3] = '\0';
  local_24 = *piVar9;
  memset(local_40a4 + 4,0,0x7c);
  FUN_0003b4f8(param_1,DAT_000647d8 + 0x642f0,local_4024,0x800);
  FUN_0003b4f8(param_1,DAT_000647dc + 0x6430c,local_3824,0x800);
  if (((local_3824[0] == '\0') || (sVar2 = strlen(local_3824), 0x20 < sVar2)) ||
     (iVar3 = strcmp(local_3824,(char *)(DAT_000647e0 + 0x64340)), iVar3 == 0)) {
    uVar7 = 0xbc;
    iVar8 = DAT_000647e4 + 0x6435c;
    pcVar4 = (char *)(DAT_000647e8 + 0x64360);
  }
  else {
    uVar7 = acosNvramConfig_get(DAT_000647ec + 0x64378);
    strlcpy(auStack_3024,uVar7,0x800);
    FUN_00147b68(param_1,DAT_000647f0 + 0x643a8,local_2824,0x800,0xb);
    FUN_00147b68(param_1,DAT_000647f4 + 0x643cc,local_2024,0x800,0xb);
    FUN_0003b4f8(param_1,DAT_000647f8 + 0x643fc,auStack_1824,0x800);
    FUN_0003b4f8(param_1,DAT_000647fc + 0x64424,auStack_1024,0x800);
    FUN_0003b4f8(param_1,DAT_00064800 + 0x6444c,local_824,0x800);
    if (((local_2824[0] != '\0') && (local_2024[0] != '\0')) &&
       ((iVar3 = atoi(local_2824), iVar3 - 1U < 9 && (iVar3 = atoi(local_2024), iVar3 - 1U < 8)))) {
      if ((local_4024[0] == '\0') && (local_3824[0] == '\0')) {
        bVar11 = false;
        bVar1 = false;
LAB_000645cc:
        if (local_824[0] == '1') {
          if (local_2824[0] == '\0') goto LAB_000646fc;
          acosNvramConfig_set(DAT_00064834 + 0x64638,local_2824);
          acosNvramConfig_set(DAT_00064838 + 0x64648,local_2024);
          FUN_0003b4f8(param_1,DAT_0006483c + 0x6465c,acStack_40c4,0x20);
          iVar8 = strcmp(acStack_40c4,(char *)(DAT_00064840 + 0x64670));
          if (iVar8 == 0) {
            FUN_00064034(auStack_1824,local_40a4);
            acosNvramConfig_set(DAT_00064844 + 0x64698,local_40a4);
          }
          FUN_0003b4f8(param_1,DAT_00064848 + 0x646b0,acStack_40c4,0x20);
          iVar8 = strcmp(acStack_40c4,(char *)(DAT_0006484c + 0x646c0));
          if (iVar8 == 0) {
            FUN_00064034(auStack_1024,local_40a4);
            acosNvramConfig_set(DAT_00064850 + 0x646e8,local_40a4);
          }
          acosNvramConfig_set(DAT_00064854 + 0x646f8,local_824);
LAB_00064704:
          acosNvramConfig_save();
        }
        else {
          iVar10 = DAT_0006482c + 0x645f0;
          iVar3 = DAT_00064830 + 0x645f4;
          iVar8 = acosNvramConfig_match(iVar3,iVar10);
          if (iVar8 == 0) {
            bVar1 = true;
          }
          acosNvramConfig_set(iVar3,iVar10);
LAB_000646fc:
          if (bVar1) goto LAB_00064704;
        }
        FUN_0003c738(DAT_00064858 + 0x64718,param_2);
        rand();
        rand();
        pFVar6 = fopen64((char *)(DAT_00064860 + 0x64734),(char *)(DAT_0006485c + 0x64730));
        if (pFVar6 == (FILE *)0x0) {
          puts((char *)(DAT_00064864 + 0x64748));
        }
        else {
          uVar7 = acosNvramConfig_get(DAT_00064868 + 0x64758);
          fprintf(pFVar6,(char *)(DAT_0006486c + 0x64764),uVar7);
          fputs((char *)(DAT_00064870 + 0x6477c),pFVar6);
          fclose(pFVar6);
        }
        if (!bVar11) {
          uVar7 = 0;
          goto LAB_000647a4;
        }
        close(param_2);
        FUN_00119f04(1);
      }
      else {
        iVar10 = DAT_0006480c + 0x644e0;
        FUN_00064034(local_4024,local_40a4);
        pcVar4 = (char *)acosNvramConfig_get(iVar10);
        iVar3 = strcmp(local_40a4,pcVar4);
        if (iVar3 == 0) {
          FUN_00064034(local_3824,local_40a4);
          acosNvramConfig_set(iVar10,local_40a4);
          FUN_00058350();
          iVar3 = strcmp(local_3824,local_4024);
          bVar11 = iVar3 != 0;
          if (bVar11) {
            uVar7 = acosNvramConfig_get(DAT_0006481c + 0x64578);
            samba_tdb_backup(uVar7,local_3824);
            FUN_0011c224();
            **(undefined4 **)(iVar8 + DAT_00064820) = 0xffffffff;
          }
          pFVar6 = fopen64((char *)(DAT_00064828 + 0x645b0),(char *)(DAT_00064824 + 0x645ac));
          if (pFVar6 != (FILE *)0x0) {
            fclose(pFVar6);
          }
          bVar1 = true;
          goto LAB_000645cc;
        }
        uVar7 = FUN_0003b984(DAT_00064810 + 0x6450c);
        uVar5 = FUN_0003b984(DAT_00064814 + 0x6451c);
        FUN_00061680(uVar7,uVar5,DAT_00064818 + 0x6452c,param_2);
      }
      uVar7 = 0;
      goto LAB_000647a4;
    }
    uVar7 = 0xd1;
    iVar8 = DAT_00064804 + 0x644a4;
    pcVar4 = (char *)(DAT_00064808 + 0x644a8);
  }
  printf(pcVar4,iVar8,uVar7);
  uVar7 = FUN_00147454(param_2);
LAB_000647a4:
  if (local_24 != *piVar9) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



===== FUN_001134c4 @ 001134c4 =====

void FUN_001134c4(void)

{
  byte *pbVar1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  size_t __size;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int *piVar14;
  int iVar15;
  char *pcVar16;
  int iVar17;
  char *__format;
  undefined1 local_1db4 [16];
  char acStack_1da4 [128];
  char acStack_1d24 [128];
  char acStack_1ca4 [128];
  uint local_1c24;
  undefined1 auStack_1c20 [508];
  int local_1a24;
  undefined1 auStack_1a20 [508];
  undefined1 auStack_1824 [2048];
  uint local_1024;
  undefined1 auStack_1020 [4092];
  int local_24;
  
  piVar14 = *(int **)(DAT_00113b18 + 0x1134d4 + DAT_00113b1c);
  local_24 = *piVar14;
  local_1024 = 0;
  memset(auStack_1020,0,0xffc);
  local_1c24 = 0;
  memset(auStack_1c20,0,0x1fc);
  local_1024 = local_1024 & 0xffffff00;
  local_1c24 = local_1c24 & 0xffffff00;
  pFVar2 = fopen64((char *)(DAT_00113b24 + 0x11353c),(char *)(DAT_00113b20 + 0x113534));
  if (pFVar2 == (FILE *)0x0) {
    puts((char *)(DAT_00113b28 + 0x11355c));
  }
  else {
    fread(&local_1024,1,0x1000,pFVar2);
    snprintf((char *)&local_1c24,0x200,(char *)(DAT_00113b30 + 0x1135a8),DAT_00113b2c + 0x113598,
             DAT_00113b2c + 0x113598);
    strlcat(&local_1024,&local_1c24,0x1000);
    unlink((char *)(DAT_00113b34 + 0x1135c4));
    memset(auStack_1824,0,0x800);
    iVar3 = acosNvramConfig_match(DAT_00113b3c + 0x1135ec,DAT_00113b38 + 0x1135e8);
    if (iVar3 == 0) {
      local_1a24 = iVar3;
      memset(auStack_1a20,0,0x1c);
      iVar4 = DAT_00113b44;
      SHA256((uchar *)(DAT_00113b40 + 0x11361c),5,(uchar *)&local_1a24);
      pcVar16 = (char *)(DAT_00113b48 + 0x113634);
      iVar3 = 0;
      do {
        pbVar1 = (byte *)((int)&local_1a24 + iVar3);
        iVar11 = iVar3 * 2;
        iVar3 = iVar3 + 1;
        snprintf(&UNK_001129f9 + iVar4 + iVar11,2,pcVar16,(uint)*pbVar1);
      } while (iVar3 != 0x20);
      iVar3 = DAT_00113b4c + 0x113668;
      snprintf((char *)&local_1c24,0x200,(char *)(DAT_00113b50 + 0x113670),iVar3,
               &UNK_001129f9 + iVar4,iVar3);
      strlcat(&local_1024,&local_1c24,0x1000);
      snprintf((char *)&local_1a24,0x200,(char *)(DAT_00113b54 + 0x1136a0),iVar3,iVar3);
      COMMAND(&local_1a24);
      sleep(1);
    }
    iVar4 = DAT_00113b60;
    iVar3 = DAT_00113b5c;
    puts((char *)(DAT_00113b58 + 0x1136c8));
    iVar3 = iVar3 + 0x1136d4;
    snprintf((char *)&local_1a24,0x200,(char *)(DAT_00113b64 + 0x1136e8),iVar3);
    strlcat(auStack_1824,&local_1a24,0x800);
    strlcat(auStack_1824,iVar4 + 0x1136e4,0x800);
    snprintf((char *)&local_1a24,0x200,(char *)(DAT_00113b6c + 0x113728),DAT_00113b68 + 0x113720,
             iVar3);
    strlcat(auStack_1824,&local_1a24,0x800);
    strlcat(auStack_1824,iVar4 + 0x1136e4,0x800);
    iVar4 = FUN_0010d4bc();
    pcVar16 = (char *)(DAT_00113b70 + 0x113760);
    pcVar10 = (char *)(DAT_00113b74 + 0x11376c);
    iVar11 = DAT_00113b78 + 0x113778;
    iVar12 = DAT_00113b7c + 0x113784;
    pcVar13 = (char *)(DAT_00113b80 + 0x113790);
    for (iVar15 = 0; iVar15 < iVar4; iVar15 = iVar15 + 1) {
      snprintf(acStack_1da4,0x80,pcVar16,iVar15,iVar3);
      snprintf(acStack_1d24,0x80,pcVar10,iVar15);
      if (iVar15 == 0) {
        uVar5 = acosNvramConfig_get(iVar11);
        acosNvramConfig_set(acStack_1da4,uVar5);
        uVar5 = acosNvramConfig_get(iVar12);
        acosNvramConfig_set(acStack_1d24,uVar5);
      }
      pcVar6 = (char *)acosNvramConfig_get(acStack_1da4);
      if (*pcVar6 == '\0') {
        puts((char *)(DAT_00113b84 + 0x11382c));
        break;
      }
      uVar5 = acosNvramConfig_get(acStack_1da4);
      uVar7 = acosNvramConfig_get(acStack_1d24);
      uVar8 = acosNvramConfig_get(acStack_1da4);
      snprintf((char *)&local_1c24,0x200,pcVar13,uVar5,uVar7,uVar8);
      strlcat(&local_1024,&local_1c24,0x1000);
      memset(acStack_1ca4,0,0x20);
      uVar5 = acosNvramConfig_get(acStack_1da4);
      input_vali_getstrtosys(uVar5,acStack_1ca4,0x1f);
      acosNvramConfig_get(acStack_1da4);
      acosNvramConfig_get(acStack_1d24);
      iVar3 = DAT_00113b90;
      _eval_daemon(local_1db4,DAT_00113b8c + 0x1138ec,0,0,0);
      uVar5 = acosNvramConfig_get(acStack_1d24);
      iVar3 = iVar3 + 0x113910;
      uVar7 = acosNvramConfig_get(acStack_1d24);
      iVar17 = DAT_00113b94 + 0x113930;
      snprintf((char *)&local_1a24,0x200,(char *)(DAT_00113b98 + 0x113934),uVar5,uVar7,iVar3);
      strlcat(auStack_1824,&local_1a24,0x800);
      strlcat(auStack_1824,iVar17,0x800);
      uVar5 = acosNvramConfig_get(acStack_1da4);
      snprintf((char *)&local_1a24,0x200,(char *)(DAT_00113b9c + 0x113978),uVar5,iVar3);
      strlcat(auStack_1824,&local_1a24,0x800);
      strlcat(auStack_1824,iVar17,0x800);
    }
    __size = strlen((char *)&local_1024);
    fwrite(&local_1024,__size,1,pFVar2);
    fclose(pFVar2);
    samba_tdb_restore();
    pFVar2 = fopen64((char *)(DAT_00113ba4 + 0x1139e0),(char *)(DAT_00113ba0 + 0x1139dc));
    if (pFVar2 == (FILE *)0x0) {
      perror((char *)(DAT_00113ba8 + 0x1139f4));
    }
    else {
      iVar3 = FUN_0010d0e8();
      pcVar16 = (char *)(DAT_00113bac + 0x113a10);
      pcVar6 = (char *)(DAT_00113bb0 + 0x113a1c);
      __format = (char *)(DAT_00113bb4 + 0x113a24);
      pcVar10 = (char *)(DAT_00113bb8 + 0x113a28);
      pcVar13 = (char *)(DAT_00113bbc + 0x113a34);
      for (iVar4 = 0; iVar4 < iVar3; iVar4 = iVar4 + 1) {
        snprintf(acStack_1da4,0x80,pcVar16,iVar4);
        pcVar9 = (char *)acosNvramConfig_get(acStack_1da4);
        if (*pcVar9 == '\0') {
          puts((char *)(DAT_00113bc0 + 0x113a78));
          break;
        }
        snprintf(acStack_1ca4,0x80,pcVar10,iVar4);
        pcVar9 = (char *)acosNvramConfig_get(acStack_1ca4);
        pcVar9 = strstr(pcVar9,pcVar13);
        snprintf(acStack_1d24,0x80,pcVar6,pcVar9 + 5);
        uVar5 = acosNvramConfig_get(acStack_1da4);
        fprintf(pFVar2,__format,uVar5,acStack_1d24,acStack_1d24);
      }
    }
    fclose(pFVar2);
  }
  if (local_24 != *piVar14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



===== FUN_0003c2e4 @ 0003c2e4 =====

void FUN_0003c2e4(int param_1,char *param_2,undefined4 param_3,size_t param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 local_824;
  undefined1 auStack_820 [2044];
  int local_24;
  
  iVar6 = DAT_0003c620 + 0x3c304;
  piVar9 = *(int **)(iVar6 + DAT_0003c624);
  local_824 = 0;
  local_24 = *piVar9;
  memset(auStack_820,0,0x7fc);
  if (param_1 == 0x194) {
    iVar1 = DAT_0003c67c + 0x3c5a0;
    pcVar5 = (char *)**(undefined4 **)(iVar6 + DAT_0003c678);
    uVar2 = FUN_0003b984(iVar1);
    uVar3 = FUN_0003b984(iVar1);
    iVar6 = DAT_0003c680 + 0x3c5c4;
LAB_0003c5c0:
    uVar4 = FUN_0003b984(iVar6);
    snprintf(param_2,param_4,pcVar5,uVar2,uVar3,uVar4);
  }
  else {
    if (param_1 < 0x195) {
      if (param_1 == 400) {
        iVar1 = DAT_0003c634 + 0x3c3b8;
        pcVar5 = (char *)**(undefined4 **)(iVar6 + DAT_0003c630);
        uVar2 = FUN_0003b984(iVar1);
        uVar3 = FUN_0003b984(iVar1);
        iVar6 = DAT_0003c638 + 0x3c3dc;
        goto LAB_0003c5c0;
      }
      if (param_1 == 0x191) {
        shared_br_device_detect_do_lan_scan();
        iVar1 = acosNvramConfig_match(DAT_0003c640 + 0x3c3f4,DAT_0003c63c + 0x3c3f0);
        puVar7 = *(undefined4 **)(iVar6 + DAT_0003c644);
        if (iVar1 == 0) {
          uVar8 = *puVar7;
          iVar1 = DAT_0003c660 + 0x3c4a0;
          pcVar5 = (char *)**(undefined4 **)(iVar6 + DAT_0003c65c);
          uVar2 = FUN_0003b984(iVar1);
          uVar3 = FUN_0003b984(iVar1);
          uVar4 = FUN_0003b984(DAT_0003c664 + 0x3c4c4);
          snprintf(param_2,param_4,pcVar5,param_3,uVar8,uVar2,uVar3,uVar4);
          goto LAB_0003c600;
        }
        FUN_0003a8c8(DAT_0003c64c + 0x3c424,&local_824,0x800,DAT_0003c648 + 0x3c420);
        uVar8 = *puVar7;
        pcVar5 = (char *)**(undefined4 **)(iVar6 + DAT_0003c650);
        iVar6 = DAT_0003c654 + 0x3c440;
        uVar2 = FUN_0003b984(iVar6);
        uVar3 = FUN_0003b984(iVar6);
        uVar4 = FUN_0003b984(DAT_0003c658 + 0x3c464);
        goto LAB_0003c57c;
      }
      iVar1 = DAT_0003c628;
      if (param_1 != 0x12e) goto LAB_0003c600;
    }
    else {
      iVar1 = DAT_0003c684;
      if (param_1 != 0xbcd) {
        if (param_1 != 0xfab) {
          if (param_1 == 0xbcc) {
            snprintf(param_2,0x10000,(char *)**(undefined4 **)(iVar6 + DAT_0003c62c));
          }
          goto LAB_0003c600;
        }
        FUN_0003a8c8(DAT_0003c66c + 0x3c510,&local_824,0x800,DAT_0003c668 + 0x3c50c);
        pcVar5 = (char *)**(undefined4 **)(iVar6 + DAT_0003c650);
        uVar8 = **(undefined4 **)(iVar6 + DAT_0003c644);
        iVar6 = DAT_0003c670 + 0x3c534;
        uVar2 = FUN_0003b984(iVar6);
        uVar3 = FUN_0003b984(iVar6);
        uVar4 = FUN_0003b984(DAT_0003c674 + 0x3c558);
LAB_0003c57c:
        snprintf(param_2,param_4,pcVar5,param_3,uVar8,uVar2,uVar3,uVar4,&local_824);
        goto LAB_0003c600;
      }
    }
    snprintf(param_2,param_4,(char *)**(undefined4 **)(iVar6 + iVar1),param_3);
  }
LAB_0003c600:
  if (local_24 == *piVar9) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



===== FUN_00033724 @ 00033724 =====

void FUN_00033724(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  undefined2 uVar13;
  bool bVar14;
  in_addr iVar15;
  in_addr iVar16;
  char *pcVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  undefined4 uVar23;
  SSL_METHOD *meth;
  SSL_CTX *pSVar24;
  int iVar25;
  SSL *s;
  size_t sVar26;
  void *pvVar27;
  char *pcVar28;
  undefined4 uVar29;
  in_addr_t iVar30;
  FILE *pFVar31;
  sockaddr *__addr;
  bool bVar32;
  uint *puVar33;
  uint uVar34;
  uint *puVar35;
  uint *puVar36;
  uint *puVar37;
  uint uVar38;
  uint *puVar39;
  uint *puVar40;
  int *piVar41;
  int iVar42;
  uint uVar43;
  uint *puVar44;
  int *piVar45;
  char *pcVar46;
  char *pcVar47;
  char *pcVar48;
  __fd_mask *p_Var49;
  int iVar50;
  bool bVar51;
  undefined4 *puVar52;
  char *pcVar53;
  int iVar54;
  uint *puVar55;
  int iVar56;
  size_t sVar57;
  uint *puVar58;
  int iVar59;
  char *pcVar60;
  uint *puVar61;
  bool bVar62;
  uint *puVar63;
  uint *puVar64;
  bool bVar65;
  char *pcStack_20bb0;
  int iStack_20bac;
  char *pcStack_20ba8;
  undefined1 *puStack_20ba4;
  int iStack_20ba0;
  FILE *pFStack_20b80;
  char *pcStack_20b74;
  char *pcStack_20b6c;
  socklen_t sStack_20b00;
  uint *puStack_20afc;
  undefined4 uStack_20af8;
  int iStack_20af4;
  uint uStack_20af0;
  timeval tStack_20aec;
  timeval tStack_20ae4;
  uint uStack_20adc;
  uint uStack_20ad8;
  int iStack_20ad4;
  int iStack_20ad0;
  int iStack_20acc;
  undefined1 auStack_20ac8 [4];
  in_addr aiStack_20ac4 [3];
  undefined1 auStack_20ab8 [8];
  undefined1 auStack_20ab0 [4];
  undefined1 auStack_20aac [4];
  uint auStack_20aa8 [5];
  undefined1 auStack_20a94 [12];
  undefined4 auStack_20a88 [4];
  sockaddr sStack_20a78;
  undefined4 uStack_20a68;
  undefined4 uStack_20a64;
  int aiStack_20a5c [4];
  in_addr iStack_20a4c;
  uint uStack_20a48;
  char acStack_20a44 [4];
  undefined4 uStack_20a40;
  undefined4 uStack_20a3c;
  fd_set fStack_20a38;
  fd_set fStack_209b8;
  char acStack_20938 [31];
  undefined1 uStack_20919;
  char acStack_20918 [31];
  undefined1 uStack_208f9;
  char acStack_208f8 [31];
  undefined1 uStack_208d9;
  char acStack_208d8 [31];
  undefined1 uStack_208b9;
  char acStack_208b8 [31];
  undefined1 uStack_20899;
  char acStack_20898 [31];
  undefined1 uStack_20879;
  char acStack_20878 [45];
  undefined1 uStack_2084b;
  undefined1 uStack_2084a;
  char acStack_20848 [255];
  undefined1 uStack_20749;
  char acStack_20748 [284];
  undefined4 uStack_2062c;
  undefined1 auStack_20628 [508];
  char acStack_2042c [512];
  char acStack_2022c [9];
  char acStack_20223 [502];
  undefined1 uStack_2002d;
  uint auStack_2002c [4];
  uint auStack_2001c [16381];
  char acStack_10028 [7];
  char acStack_10021 [3];
  char acStack_1001e [21];
  undefined1 uStack_10009;
  undefined1 local_ffff;
  undefined1 local_fe29;
  int local_24;
  
  iVar50 = DAT_0003463c + 0x33744;
  local_24 = **(int **)(iVar50 + DAT_00034640);
  FUN_0003d6c4();
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034644 + 0x3376c);
  iVar18 = strcmp(pcVar17,(char *)(DAT_00034648 + 0x33778));
  **(uint **)(iVar50 + DAT_0003464c) = (uint)(iVar18 == 0);
  FUN_00058350();
  FUN_00058a6c();
  uStack_20af0 = 1;
  tStack_20aec.tv_sec = 1;
  uVar19 = socket(2,1,0);
  puVar35 = *(uint **)(iVar50 + DAT_00034650);
  if (uVar19 == 0xffffffff) {
    pcVar17 = (char *)(DAT_00034658 + 0x337ec);
    pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034654);
LAB_00033968:
    fputs(pcVar17,pFVar31);
  }
  else {
    iVar18 = setsockopt(uVar19,1,2,&tStack_20aec,4);
    if (iVar18 < 0) {
      fputs((char *)(DAT_0003465c + 0x33824),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
    }
    memset((sockaddr *)&fStack_20a38,0,0x10);
    fStack_20a38.fds_bits[0]._0_2_ = 2;
    uVar13 = (undefined2)DAT_00034660;
    fStack_20a38.fds_bits[0]._2_2_ = uVar13;
    pcVar17 = (char *)nvram_get(DAT_00034664 + 0x33850);
    if (pcVar17 == (char *)0x0) {
LAB_00033874:
      pcVar17 = (char *)acosNvramConfig_get(DAT_0003466c + 0x33880);
      fStack_20a38.fds_bits[1] = inet_addr(pcVar17);
    }
    else {
      iVar18 = strcmp(pcVar17,(char *)(DAT_00034668 + 0x3386c));
      fStack_20a38.fds_bits[1] = 0;
      if (iVar18 != 0) goto LAB_00033874;
    }
    iVar18 = bind(uVar19,(sockaddr *)&fStack_20a38,0x10);
    if (iVar18 == -1) {
      puVar52 = *(undefined4 **)(iVar50 + DAT_00034654);
      pFVar31 = (FILE *)*puVar52;
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      fprintf(pFVar31,(char *)(DAT_00034670 + 0x338c4),pcVar17,0x24e3);
      pFVar31 = (FILE *)*puVar52;
      piVar41 = __errno_location();
      pcVar17 = strerror(*piVar41);
      fprintf(pFVar31,(char *)(DAT_00034674 + 0x338e8),pcVar17);
    }
    else {
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      printf((char *)(DAT_0003803c + 0x37e14),pcVar17,0x24e3);
    }
    if (0 < (int)uVar19) {
      uVar21 = fcntl(uVar19,1);
      fcntl(uVar19,2,uVar21 | 1);
    }
    iVar18 = acosNvramConfig_match(DAT_0003467c + 0x33928,DAT_00034678 + 0x33924);
    if (iVar18 == 0) {
      iVar20 = DAT_00034684 + 0x33980;
      iVar18 = acosNvramConfig_match(iVar20,DAT_00034688 + 0x33984);
      if (((iVar18 == 0) &&
          (iVar18 = acosNvramConfig_match(iVar20,DAT_00038040 + 0x37e28), iVar18 == 0)) &&
         (pcVar17 = (char *)acosNvramConfig_get(DAT_00038044 + 0x37e3c), *pcVar17 != '\0'))
      goto LAB_00033930;
    }
    else {
LAB_00033930:
      tStack_20ae4.tv_sec = 1;
      uVar21 = socket(10,1,0);
      if (uVar21 == 0xffffffff) {
        pcVar17 = (char *)(DAT_00034680 + 0x33968);
        pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034654);
        goto LAB_00033968;
      }
      iVar18 = setsockopt(uVar21,1,2,&tStack_20ae4,4);
      if (iVar18 < 0) {
        fputs((char *)(DAT_0003804c + 0x37e80),(FILE *)**(undefined4 **)(iVar50 + DAT_00038048));
      }
      uStack_20adc = 1;
      iVar18 = setsockopt(uVar21,0x29,0x1a,&uStack_20adc,4);
      if (iVar18 == -1) {
        fputs((char *)(DAT_00038050 + 0x37ec4),(FILE *)**(undefined4 **)(iVar50 + DAT_00038048));
      }
      else {
        printf((char *)(DAT_00038054 + 0x37ed8));
      }
      memset((sockaddr *)&fStack_209b8,0,0x1c);
      fStack_209b8.fds_bits[0] = CONCAT22(uVar13,10);
      p_Var49 = *(__fd_mask **)(iVar50 + DAT_00038058);
      fStack_209b8.fds_bits[2] = *p_Var49;
      fStack_209b8.fds_bits[3] = p_Var49[1];
      fStack_209b8.fds_bits[4] = p_Var49[2];
      fStack_209b8.fds_bits[5] = p_Var49[3];
      iVar18 = bind(uVar21,(sockaddr *)&fStack_209b8,0x1c);
      if (iVar18 == -1) {
        puVar52 = *(undefined4 **)(iVar50 + DAT_00038048);
        fprintf((FILE *)*puVar52,(char *)(DAT_0003805c + 0x37f38),0x24e3);
        pFVar31 = (FILE *)*puVar52;
        piVar41 = __errno_location();
        pcVar17 = strerror(*piVar41);
        fprintf(pFVar31,(char *)(DAT_00038060 + 0x37f58),pcVar17);
        close(uVar21);
      }
      else {
        printf((char *)(DAT_00038064 + 0x37f80),0x3b3,0x24e3);
        if (0 < (int)uVar21) {
          uVar38 = fcntl(uVar21,1);
          fcntl(uVar21,2,uVar38 | 1);
          *puVar35 = uVar21;
        }
      }
    }
  }
  puVar63 = *(uint **)(iVar50 + DAT_00034924);
  *puVar63 = uVar19;
  uVar19 = FUN_0002a48c(0x50);
  iVar20 = DAT_00034870;
  iVar18 = DAT_0003468c;
  puVar58 = *(uint **)(iVar50 + DAT_00034838);
  *puVar58 = 0xffffffff;
  puVar55 = *(uint **)(iVar50 + iVar20);
  *puVar55 = 0xffffffff;
  pcVar17 = (char *)acosNvramConfig_get(iVar18 + 0x339cc);
  iVar18 = strcmp(pcVar17,(char *)(DAT_00034690 + 0x339dc));
  if (iVar18 == 0) {
    pcVar17 = (char *)acosNvramConfig_get(DAT_00034694 + 0x33a00);
    iVar18 = atoi(pcVar17);
    if (iVar18 == 0x50) {
      *puVar58 = 0xffffffff;
    }
    else {
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034698 + 0x33a24);
      iVar20 = strcmp(pcVar17,(char *)(DAT_0003469c + 0x33a30));
      if (iVar20 != 0) {
        uVar21 = FUN_0002a66c(iVar18);
        *puVar58 = uVar21;
        iVar20 = listen(uVar21,10);
        if (iVar20 == -1) {
          fputs((char *)(DAT_000346a0 + 0x33a6c),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
        }
        agApi_setDeviceListenPort(2,iVar18,1);
      }
    }
    iVar59 = DAT_000346a4 + 0x33a90;
    iVar20 = acosNvramConfig_match(iVar59,DAT_000346a8 + 0x33a94);
    if ((iVar20 == 0) &&
       (iVar20 = acosNvramConfig_match(iVar59,DAT_000346ac + 0x33ab0), iVar20 == 0)) {
      uVar21 = FUN_0002a48c(iVar18);
      *puVar55 = uVar21;
      iVar20 = listen(uVar21,5);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000346b0 + 0x33aec),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      }
      agApi_setDeviceListenPort(2,iVar18,1);
      agApi_ipv6_set_listen_port(1,0,6,iVar18);
    }
  }
  else {
    iVar18 = 0;
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346b4 + 0x33b24);
  iVar20 = strcmp(pcVar17,(char *)(DAT_000346b8 + 0x33b30));
  puVar36 = *(uint **)(iVar50 + DAT_00034920);
  if (((iVar20 == 0) && (iVar20 = is_russian_case(), iVar20 != 0)) && (iVar18 != 0x50)) {
    uVar21 = FUN_0002a66c(iVar18 + 0x10000);
    *puVar36 = uVar21;
    iVar18 = listen(uVar21,10);
    if (iVar18 == -1) {
      fputs((char *)(DAT_000346bc + 0x33b8c),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
    }
  }
  else {
    *puVar36 = 0xffffffff;
  }
  setsockopt(uVar19,1,2,&uStack_20af0,4);
  iVar18 = listen(uVar19,10);
  if (iVar18 == -1) {
    fputs((char *)(DAT_000346c0 + 0x33be4),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
LAB_00034140:
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((*puVar63 != 0xffffffff) && (iVar18 = listen(*puVar63,10), iVar18 == -1)) {
    fputs((char *)(DAT_000346c4 + 0x33c20),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
  }
  if ((*puVar35 != 0xffffffff) && (iVar18 = listen(*puVar35,10), iVar18 == -1)) {
    fputs((char *)(DAT_000346c8 + 0x33c58),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346cc + 0x33c68);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d0 + 0x33c7c);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d4 + 0x33c90);
  iVar59 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d8 + 0x33ca4);
  iVar22 = atoi(pcVar17);
  puVar37 = *(uint **)(iVar50 + DAT_00034928);
  if ((iVar18 == 0x50) || (iVar59 == 0 || iVar20 != 0 && iVar18 == iVar22)) {
    *puVar37 = 0xffffffff;
  }
  else {
    pcVar17 = (char *)acosNvramConfig_get(DAT_000346dc + 0x33cec);
    iVar20 = strcmp(pcVar17,(char *)(DAT_000346e0 + 0x33cf8));
    if (iVar20 != 0) {
      uVar21 = FUN_0002a66c(iVar18);
      *puVar37 = uVar21;
      iVar20 = listen(uVar21,10);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000346e4 + 0x33d34),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      }
    }
  }
  iVar20 = acosNvramConfig_match(DAT_000346ec + 0x33d5c,DAT_000346e8 + 0x33d58);
  agApi_setDeviceListenPort(6,iVar18,iVar20 != 0);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f0 + 0x33d7c);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f4 + 0x33d90);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f8 + 0x33da4);
  iVar59 = atoi(pcVar17);
  iVar22 = acosNvramConfig_match(DAT_00034700 + 0x33dc0,DAT_000346fc + 0x33db4);
  if (iVar22 == 0) {
    agApi_setDeviceListenPort(7,iVar20,0);
    agApi_setDeviceListenPort(8,iVar18,0);
  }
  else {
    agApi_setDeviceListenPort(8,iVar18,0);
    agApi_setDeviceListenPort(7,iVar20,1);
    if (iVar20 <= iVar59 && iVar18 <= iVar20) {
      iVar59 = iVar59 - iVar18;
      iVar18 = iVar20 + 1;
      iVar59 = iVar59 + iVar18;
    }
    agApi_setDeviceListenPortRange(8,iVar18,iVar59);
  }
  iVar20 = DAT_0003470c;
  iVar18 = DAT_00034708;
  uVar23 = acosNvramConfig_get(DAT_00034704 + 0x33e58);
  strlcpy(acStack_10028,uVar23,0x28);
  agApi_natSetReadyshareName(acStack_10028);
  FUN_001115e0(acStack_10028);
  iVar22 = DAT_00034714 + 0x33ea4;
  iVar59 = DAT_00034718 + 0x33ea8;
  **(uint **)(iVar50 + DAT_00034710) = uVar19;
  acosNvramConfig_set(iVar59,iVar22);
  pcVar17 = (char *)acosNvramConfig_get(DAT_0003471c + 0x33eb8);
  strncpy(acStack_20938,pcVar17,0x1f);
  uStack_20919 = 0;
  strncpy(acStack_20918,acStack_20938,0x1f);
  uStack_208f9 = 0;
  iVar59 = acosNvramConfig_match(iVar20 + 0x33e6c,(char *)(iVar18 + 0x33e68));
  if (iVar59 == 0) {
    pcVar17 = (char *)(DAT_00034720 + 0x33f34);
    iVar18 = acosNvramConfig_match(iVar20 + 0x33e6c,pcVar17);
    if (iVar18 == 0) {
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034724 + 0x33f64);
      strncpy(acStack_20878,pcVar17,0x2d);
      uStack_2084b = 0;
    }
    else {
      strncpy(acStack_20878,pcVar17,0x2e);
      uStack_2084a = 0;
    }
  }
  else {
    strncpy(acStack_20878,(char *)(iVar18 + 0x33e68),0x2e);
    uStack_2084a = 0;
  }
  iVar18 = is_russian_case();
  if (iVar18 != 0) {
    iVar20 = DAT_00034728 + 0x33f94;
    iVar18 = acosNvramConfig_match(iVar20,DAT_0003472c + 0x33f98);
    if (((iVar18 != 0) ||
        (iVar18 = acosNvramConfig_match(iVar20,DAT_0003473c + 0x33fec), iVar18 != 0)) ||
       (iVar18 = acosNvramConfig_match(iVar20,DAT_00034740 + 0x34004), iVar18 != 0)) {
      iVar20 = DAT_00034730 + 0x33fb8;
      iVar18 = acosNvramConfig_match(iVar20,DAT_00034734 + 0x33fbc);
      if (iVar18 == 0) {
        iVar18 = acosNvramConfig_match(iVar20,DAT_00034744 + 0x34020);
        if (iVar18 == 0) {
          iVar18 = DAT_0003474c + 0x34040;
        }
        else {
          iVar18 = DAT_00034748 + 0x34038;
        }
      }
      else {
        iVar18 = DAT_00034738 + 0x33fdc;
      }
      acosNvramConfig_read(iVar18,acStack_208f8,0x20);
      strncpy(acStack_208d8,acStack_208f8,0x1f);
      uStack_208b9 = 0;
    }
  }
  iVar18 = DAT_00034750;
  OPENSSL_init_ssl(0,0,0);
  OPENSSL_init_ssl(DAT_00034754,0,0);
  OPENSSL_init_ssl(0,0,0);
  meth = (SSL_METHOD *)TLS_server_method();
  pSVar24 = SSL_CTX_new(meth);
  *(SSL_CTX **)(iVar18 + 0x34d58) = pSVar24;
  SSL_CTX_set_options(pSVar24,0x2000000);
  FUN_0003d6c4();
  if (**(char **)(iVar18 + 0x34d5c) != '\0') {
    iVar18 = SSL_CTX_use_certificate_file
                       (*(SSL_CTX **)(iVar18 + 0x34d58),*(char **)(iVar18 + 0x34d5c),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_00034758 + 0x340d8));
    }
    iVar18 = SSL_CTX_use_PrivateKey_file
                       (*(SSL_CTX **)(DAT_0003475c + 0x34dac),*(char **)(DAT_0003475c + 0x34db4),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_00034760 + 0x34104));
    }
    FUN_001487d4();
    FUN_00148770();
    iVar18 = SSL_CTX_check_private_key(*(SSL_CTX **)(DAT_00034764 + 0x34ddc));
    if (iVar18 == 0) {
      ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      puts((char *)(DAT_00034768 + 0x34140));
      goto LAB_00034140;
    }
  }
  iVar18 = DAT_0003476c;
  SSL_CTX_ctrl(*(SSL_CTX **)(DAT_0003476c + 0x34e24),0x21,2,(void *)0x0);
  SSL_CTX_set_cipher_list(*(SSL_CTX **)(iVar18 + 0x34e24),(char *)(DAT_00034770 + 0x34178));
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034774 + 0x34184);
  strncpy(acStack_208b8,pcVar17,0x1f);
  uStack_20899 = 0;
  strncpy(acStack_20898,acStack_208b8,0x1f);
  uStack_20879 = 0;
  pFVar31 = fopen64((char *)(DAT_0003477c + 0x341d0),(char *)(DAT_00034778 + 0x341c8));
  if (pFVar31 != (FILE *)0x0) {
    fread(*(void **)(iVar50 + DAT_00034780),4,1,pFVar31);
    fread(*(void **)(iVar50 + DAT_00034784),4,1,pFVar31);
    fclose(pFVar31);
  }
  iVar20 = DAT_00034790;
  iVar18 = DAT_00034788;
  puts((char *)(DAT_0003478c + 0x34240));
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3423c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34240);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34244);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x34248);
  iVar20 = iVar20 + 0x34250;
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3424c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34250);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34254);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x34258);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3425c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34260);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34264);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x34268);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x3426c);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34270);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  system((char *)(DAT_00034794 + 0x342e0));
  FUN_0003d6c4();
  uVar21 = uVar19 + 0x1f;
  if (-1 < (int)uVar19) {
    uVar21 = uVar19;
  }
  iVar18 = (int)uVar21 >> 5;
  uVar21 = uVar19 & 0x8000001f;
  if ((int)uVar21 < 0) {
    uVar21 = ~(~((uVar21 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  uVar21 = 1 << (uVar21 & 0xff);
  iVar20 = DAT_00034798 + 0x3432c;
  iVar59 = DAT_0003479c + 0x344de;
  iVar22 = DAT_000347a0 + 0x344f2;
LAB_00034354:
  do {
    do {
      while( true ) {
        uVar38 = *puVar58;
        if ((int)*puVar58 < (int)*puVar55) {
          uVar38 = *puVar55;
        }
        if ((int)uVar38 < (int)*puVar63) {
          uVar38 = *puVar63;
        }
        if ((int)uVar38 < (int)*puVar35) {
          uVar38 = *puVar35;
        }
        uVar43 = *puVar36;
        if ((int)*puVar36 <= (int)uVar38) {
          uVar43 = uVar38;
        }
        pcVar17 = (char *)acosNvramConfig_get(iVar20);
        strncpy(acStack_20918,pcVar17,0x1f);
        uStack_208f9 = 0;
        iVar25 = strcmp(acStack_20918,acStack_20938);
        if ((iVar25 == 0) ||
           (iVar25 = strcmp(acStack_20918,(char *)(DAT_000347a4 + 0x343e4)), iVar25 == 0)) {
          bVar65 = false;
        }
        else {
          bVar65 = true;
          strncpy(acStack_20938,acStack_20918,0x1f);
          uStack_20919 = 0;
        }
        iVar56 = DAT_000347a8 + 0x3441c;
        iVar25 = acosNvramConfig_match(iVar56,DAT_000347ac + 0x34420);
        if ((iVar25 == 0) &&
           (iVar25 = acosNvramConfig_match(iVar56,DAT_000347b4 + 0x3447c), iVar25 == 0)) {
          iVar56 = DAT_000347b8 + 0x34494;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
          iVar25 = acosNvramConfig_match(DAT_000347c0 + 0x344d4,DAT_000347bc + 0x344d0);
          if (((iVar25 != 0) &&
              (iVar25 = acosNvramConfig_match(DAT_000347c8 + 0x344f0,DAT_000347c4 + 0x344ec),
              iVar25 == 0)) && (*puVar55 == 0xffffffff)) {
            bVar65 = true;
          }
        }
        else {
          iVar56 = DAT_000347b0 + 0x3443c;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
        }
        iVar25 = acosNvramConfig_match(DAT_000347d0 + 0x3451c,DAT_000347cc + 0x34518);
        if (iVar25 != 0) {
          pcVar17 = (char *)acosNvramConfig_get(DAT_000347d4 + 0x34538);
          strncpy(acStack_20898,pcVar17,0x1f);
          uStack_20879 = 0;
          iVar25 = strcmp(acStack_208b8,acStack_20898);
          if (iVar25 != 0) {
            bVar65 = true;
            strncpy(acStack_208b8,acStack_20898,0x1f);
            uStack_20899 = 0;
          }
        }
        iVar25 = is_russian_case();
        if (iVar25 != 0) {
          iVar56 = DAT_000347d8 + 0x34594;
          iVar25 = acosNvramConfig_match(iVar56,DAT_000347dc + 0x34598);
          if (((iVar25 != 0) ||
              (iVar25 = acosNvramConfig_match(iVar56,DAT_000347ec + 0x345ec), iVar25 != 0)) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000347f0 + 0x34604), iVar25 != 0)) {
            iVar56 = DAT_000347e0 + 0x345b8;
            iVar25 = acosNvramConfig_match(iVar56,DAT_000347e4 + 0x345bc);
            if (iVar25 == 0) {
              iVar25 = acosNvramConfig_match(iVar56,DAT_000347f4 + 0x34620);
              if (iVar25 == 0) {
                iVar25 = DAT_000347fc + 0x34954;
              }
              else {
                iVar25 = (int)&DAT_0003463c + DAT_000347f8;
              }
            }
            else {
              iVar25 = DAT_000347e8 + 0x345dc;
            }
            acosNvramConfig_read(iVar25,acStack_208d8,0x20);
            iVar25 = strcmp(acStack_208d8,acStack_208f8);
            if ((iVar25 != 0) &&
               (iVar25 = strcmp(acStack_208d8,(char *)(DAT_00034800 + 0x3497c)), iVar25 != 0)) {
              bVar65 = true;
              strncpy(acStack_208f8,acStack_208d8,0x1f);
              uStack_208d9 = 0;
            }
          }
        }
        iVar25 = FUN_0010fa90();
        if (iVar25 != 0) {
          FUN_0002a974();
        }
        if (bVar65) {
          FUN_0002a974();
          FUN_0002ab10();
          FUN_00119948(2);
        }
        if ((int)uVar43 < (int)*puVar37) {
          uVar43 = *puVar37;
        }
        if ((int)uVar43 <= (int)uVar19) {
          uVar43 = uVar19;
        }
        iVar25 = acosNvramConfig_match(DAT_00034808 + 0x349e4,DAT_00034804 + 0x349e0);
        if (iVar25 != 0) {
          FUN_0011ad0c();
        }
        tStack_20aec.tv_sec = 1;
        iVar25 = 0;
        tStack_20aec.tv_usec = 0;
        puVar33 = *(uint **)(iVar50 + DAT_0003480c);
        *puVar33 = 0;
        do {
          pcVar17 = ((sockaddr *)&fStack_20a38)->sa_data + iVar25 * 4 + -2;
          pcVar17[0] = '\0';
          pcVar17[1] = '\0';
          pcVar17[2] = '\0';
          pcVar17[3] = '\0';
          iVar25 = iVar25 + 1;
        } while (iVar25 != 0x20);
        fStack_20a38.fds_bits[iVar18] = fStack_20a38.fds_bits[iVar18] | uVar21;
        uVar34 = *puVar63;
        uVar38 = uVar34 + 0x1f;
        if (-1 < (int)uVar34) {
          uVar38 = uVar34;
        }
        uVar34 = uVar34 & 0x8000001f;
        if ((int)uVar34 < 0) {
          uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        fStack_20a38.fds_bits[(int)uVar38 >> 5] =
             fStack_20a38.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
        uVar38 = *puVar35;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        if (**(int **)(iVar50 + DAT_00034810) == 1) {
          FUN_0002ab10();
        }
        uVar38 = *puVar58;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar36;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar55;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar37;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        iVar25 = select(uVar43 + 1,&fStack_20a38,(fd_set *)0x0,(fd_set *)0x0,&tStack_20aec);
        if (iVar25 != -1) break;
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_0003481c + 0x34d00),iVar59);
        FUN_0002b1b4(0,pcVar17);
      }
      if (iVar25 != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034814 + 0x34cb8),DAT_00034818 + 0x34e76);
        FUN_0002b1b4(0,pcVar17);
      }
      if (((**(int **)(iVar50 + DAT_00034820) != 0) ||
          (iVar25 = acosNvramConfig_match(DAT_00034828 + 0x34d68,DAT_00034824 + 0x34d64),
          iVar25 != 0)) && (**(int **)(iVar50 + DAT_00034890) == 0)) {
        FUN_0002b424();
      }
      if (**(int **)(iVar50 + DAT_0003482c) != 0) {
        **(int **)(iVar50 + DAT_0003482c) = 0;
        iVar56 = **(int **)(iVar50 + DAT_00034830);
        iVar25 = iVar56;
        if (iVar56 != 1) {
          iVar25 = iVar56 + -3;
        }
        if (iVar25 != 0 && (iVar56 != 1 && iVar56 + -3 != 1)) {
          if (iVar56 == 2) {
            FUN_0012c708();
          }
        }
        else if (**(int **)(iVar50 + DAT_00034834) == 1) {
          FUN_000c8b60();
        }
        else {
          FUN_000c6f84();
        }
      }
      puVar39 = *(uint **)(iVar50 + DAT_00034838);
      if ((uVar21 & fStack_20a38.fds_bits[iVar18]) != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_0003483c + 0x34e18),DAT_00034840 + 0x34fd6);
        FUN_0002b1b4(0,pcVar17);
        **(uint **)(iVar50 + DAT_000348f4) = uVar19;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034884) = 0;
        **(undefined4 **)(iVar50 + DAT_00034910) = 0;
        goto LAB_00035520;
      }
      uVar38 = **(uint **)(iVar50 + DAT_00034924);
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar34 = uVar38 & 0x8000001f;
        bVar65 = (int)uVar34 < 0;
        if (bVar65) {
          uVar34 = uVar34 - 1;
        }
        if (bVar65) {
          uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar34 & 0xff)) == 0)
        goto LAB_00034ec0;
LAB_00034f10:
        **(uint **)(iVar50 + DAT_000348f4) = uVar38;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034884) = 0;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        goto LAB_00035520;
      }
LAB_00034ec0:
      uVar38 = **(uint **)(iVar50 + DAT_00034844);
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar34 = uVar38 & 0x8000001f;
        bVar65 = (int)uVar34 < 0;
        if (bVar65) {
          uVar34 = uVar34 - 1;
        }
        if (bVar65) {
          uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar34 & 0xff)) != 0)
        goto LAB_00034f10;
      }
      uVar38 = *puVar39;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) == 0)
        goto LAB_00035038;
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034848 + 0x34fa0),DAT_0003484c + 0x3515e);
        FUN_0002b1b4(0,pcVar17);
        iVar25 = DAT_00034854;
        iVar56 = DAT_00034850 + 0x34fe8;
        **(uint **)(iVar50 + DAT_000348f4) = *puVar39;
        aiStack_20a5c[0] = 1;
        **(undefined4 **)(iVar50 + DAT_00034884) = 1;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        iVar25 = acosNvramConfig_match(iVar25 + 0x34ff4,iVar56);
        if (iVar25 == 0) goto LAB_0003551c;
        pcVar17 = (char *)acosNvramConfig_get(DAT_00034858 + 0x35024);
        iVar25 = atoi(pcVar17);
        iVar56 = DAT_0003485c + 0x35038;
LAB_000352bc:
        pcVar17 = (char *)acosNvramConfig_get(iVar56);
        iVar56 = atoi(pcVar17);
        bVar65 = iVar25 == iVar56;
        goto LAB_00035520;
      }
LAB_00035038:
      puVar40 = *(uint **)(iVar50 + DAT_00034920);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) == 0)
        goto LAB_000350f8;
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034860 + 0x350a0),DAT_00034864 + 0x3525e);
        FUN_0002b1b4(0,pcVar17);
        **(uint **)(iVar50 + DAT_000348f4) = *puVar40;
        **(undefined4 **)(iVar50 + DAT_00034884) = 1;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        goto LAB_0003551c;
      }
LAB_000350f8:
      puVar40 = *(uint **)(iVar50 + DAT_00034928);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) != 0) {
          pcVar17 = *(char **)(iVar50 + DAT_000348f8);
          snprintf(pcVar17,0x400,(char *)(DAT_00034868 + 0x35160),DAT_0003486c + 0x3531e);
          FUN_0002b1b4(0,pcVar17);
          **(undefined4 **)(iVar50 + DAT_00034910) = 2;
          uVar38 = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034884) = 1;
          **(uint **)(iVar50 + DAT_000348f4) = uVar38;
          bVar65 = false;
          aiStack_20a5c[0] = 0;
          goto LAB_00035520;
        }
      }
      puVar40 = *(uint **)(iVar50 + DAT_00034870);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) != 0) {
          pcVar17 = *(char **)(iVar50 + DAT_000348f8);
          snprintf(pcVar17,0x400,(char *)(DAT_00034874 + 0x3522c),DAT_00034878 + 0x353ea);
          FUN_0002b1b4(0,pcVar17);
          iVar25 = DAT_00034880;
          iVar56 = DAT_0003487c + 0x35274;
          **(uint **)(iVar50 + DAT_000348f4) = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034884) = 1;
          aiStack_20a5c[0] = 1;
          **(undefined4 **)(iVar50 + DAT_00034910) = 1;
          iVar25 = acosNvramConfig_match(iVar25 + 0x3527c,iVar56);
          if (iVar25 != 0) {
            pcVar17 = (char *)acosNvramConfig_get(DAT_00034888 + 0x352ac);
            iVar25 = atoi(pcVar17);
            iVar56 = DAT_0003488c + 0x352c0;
            goto LAB_000352bc;
          }
          goto LAB_0003551c;
        }
      }
      iVar25 = FUN_0005c6d8();
      if (iVar25 == 1) {
        if (**(int **)(iVar50 + DAT_00034890) != 0) {
          sync();
          sleep(2);
          system((char *)(DAT_00034894 + 0x35310));
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        iVar56 = DAT_00034898 + 0x35324;
        iVar25 = acosNvramConfig_match(iVar56,DAT_0003489c + 0x35328);
        if (iVar25 == 0) {
          iVar25 = acosNvramConfig_match(iVar56,DAT_000348b4 + 0x35398);
          if ((iVar25 != 0) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000348bc + 0x353cc), iVar25 != 0)) {
            system((char *)(DAT_000348b8 + 0x353ac));
            wait_for_ppp_to_terminate();
            sleep(1);
          }
        }
        else {
          system((char *)(DAT_000348a0 + 0x35340));
          wait_for_ppp_to_terminate();
          sleep(1);
          iVar25 = FUN_000492ac();
          if (iVar25 == 0) {
            acosNvramConfig_set(DAT_000348a8 + 0x3536c,DAT_000348a4 + 0x35368);
            acosNvramConfig_set(DAT_000348b0 + 0x35380,DAT_000348ac + 0x3537c);
            acosNvramConfig_save();
          }
        }
        if (**(int **)(iVar50 + DAT_000348c0) == 1) {
          abDisableLanEthernetPort();
        }
        iVar25 = acosNvramConfig_match(DAT_000348c8 + 0x35400,DAT_000348c4 + 0x353fc);
        if (iVar25 != 0) {
          abDisableLanEthernetPort();
          puts((char *)(DAT_000348cc + 0x35418));
        }
        acos_cms_del_bridge(DAT_000348d0 + 0x35424);
        system((char *)(DAT_000348d4 + 0x35430));
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005c984();
      if (iVar25 == 1) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_000348d8 + 0x35458),DAT_000348dc + 0x35616);
        FUN_0002b1b4(0,pcVar17);
        FUN_0005c92c();
        abDisableLanEthernetPort();
        sleep(3);
        abEnableLanEthernetPort();
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005cab8();
      if (iVar25 == 1) {
        FUN_0005ca60();
        wireless_configure();
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005cc1c();
    } while (iVar25 != 1);
    FUN_0005cbc4();
    pFVar31 = fopen64((char *)(DAT_000348e4 + 0x354d8),(char *)(DAT_000348e0 + 0x354d4));
    if (pFVar31 != (FILE *)0x0) {
      fprintf(pFVar31,(char *)(DAT_000348ec + 0x354fc),DAT_000348e8 + 0x356a1,0x8b3);
      fclose(pFVar31);
    }
    COMMAND(DAT_000348f0 + 0x35514);
    sleep(5);
LAB_0003551c:
    bVar65 = false;
LAB_00035520:
    puVar40 = *(uint **)(iVar50 + DAT_000348f4);
    uVar38 = *puVar40;
    pcVar17 = *(char **)(iVar50 + DAT_000348f8);
    if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034920))) ||
       ((uVar38 == **(uint **)(iVar50 + DAT_00034928) ||
        (uVar38 == **(uint **)(iVar50 + DAT_00034924))))) {
      snprintf(pcVar17,0x400,(char *)(DAT_00034900 + 0x355b8),DAT_000348fc + 0x35756);
      FUN_0002b1b4(0,pcVar17);
      __addr = (sockaddr *)auStack_20ac8;
      sStack_20b00 = 0x10;
    }
    else {
      snprintf(pcVar17,0x400,(char *)(DAT_00034908 + 0x35600),DAT_00034904 + 0x3579e);
      FUN_0002b1b4(0,pcVar17);
      __addr = &sStack_20a78;
      sStack_20b00 = 0x1c;
    }
    uVar38 = accept(*puVar40,__addr,&sStack_20b00);
    *puVar33 = uVar38;
  } while (uVar38 == 0xffffffff);
  puStack_20afc = (uint *)0x0;
  uStack_20af8 = 0;
  pcVar53 = (char *)(DAT_0003490c + 0x35668);
  uStack_2062c = 0;
  memset(auStack_20628,0,0x1fc);
  acStack_2042c[0] = '\0';
  acStack_2042c[1] = '\0';
  acStack_2042c[2] = '\0';
  acStack_2042c[3] = '\0';
  memset(acStack_2042c + 4,0,0x1fc);
  snprintf(pcVar17,0x400,pcVar53,iVar22);
  FUN_0002b1b4(0,pcVar17);
  acStack_20748[0] = '\0';
  acStack_20748[1] = '\0';
  acStack_20748[2] = '\0';
  acStack_20748[3] = '\0';
  memset(acStack_20748 + 4,0,0x118);
  piVar41 = *(int **)(iVar50 + DAT_00034910);
  if (*piVar41 != 0) {
    snprintf(pcVar17,0x400,pcVar53,iVar22);
    FUN_0002b1b4(0,pcVar17);
    s = SSL_new(*(SSL_CTX **)(DAT_00034914 + 0x363dc));
    puVar52 = *(undefined4 **)(iVar50 + DAT_00034918);
    uVar38 = *puVar33;
    *puVar52 = s;
    SSL_set_fd(s,uVar38);
    fcntl(*puVar33,4,0x800);
    FUN_0003d6c4();
    iVar25 = SSL_accept((SSL *)*puVar52);
    if (iVar25 < 1) {
      iVar25 = SSL_get_error((SSL *)*puVar52,iVar25);
      if (iVar25 != 2) {
        close(*puVar33);
        SSL_shutdown((SSL *)*puVar52);
        SSL_free((SSL *)*puVar52);
        ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_0003491c));
        goto LAB_00034354;
      }
      goto LAB_000357a4;
    }
  }
  iStack_20af4 = 0;
LAB_000357a4:
  uVar38 = *puVar40;
  if ((((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034920))) ||
      (uVar38 == **(uint **)(iVar50 + DAT_00034924))) ||
     (uVar38 == **(uint **)(iVar50 + DAT_00034928))) {
    if (aiStack_20ac4[0].s_addr == 0) {
      puts((char *)(DAT_0003492c + 0x35814));
LAB_00037dd0:
      if (local_24 == **(int **)(iVar50 + DAT_00038038)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(0);
    }
    iStack_20a4c.s_addr = aiStack_20ac4[0].s_addr;
    aiStack_20a5c[0] = 0;
  }
  else {
    pcVar53 = inet_ntop(10,sStack_20a78.sa_data + 6,acStack_10028,0x40);
    if ((pcVar53 != (char *)0x0) &&
       (iVar25 = acosNvramConfig_match(DAT_00034934 + 0x35860,DAT_00034930 + 0x3585c), iVar25 != 0))
    {
      pFVar31 = fopen64((char *)(DAT_0003493c + 0x3587c),(char *)(DAT_00034938 + 0x35878));
      fprintf(pFVar31,(char *)(DAT_00034940 + 0x3588c),acStack_10028);
      fclose(pFVar31);
    }
    iVar25 = strcmp(acStack_10028,(char *)(DAT_00034944 + 0x358a8));
    if (iVar25 == 0) goto LAB_00037dd0;
    pcVar53 = strchr(acStack_10028,0x2e);
    if (pcVar53 == (char *)0x0) {
      aiStack_20a5c[0] = 1;
      uStack_20a48._0_1_ = sStack_20a78.sa_data[6];
      uStack_20a48._1_1_ = sStack_20a78.sa_data[7];
      uStack_20a48._2_1_ = sStack_20a78.sa_data[8];
      uStack_20a48._3_1_ = sStack_20a78.sa_data[9];
      acStack_20a44[0] = sStack_20a78.sa_data[10];
      acStack_20a44[1] = sStack_20a78.sa_data[0xb];
      acStack_20a44[2] = sStack_20a78.sa_data[0xc];
      acStack_20a44[3] = sStack_20a78.sa_data[0xd];
      uStack_20a40 = uStack_20a68;
      uStack_20a3c = uStack_20a64;
      printf((char *)(DAT_0003690c + 0x35948),sStack_20a78.sa_data._6_4_ & 0xff,
             (uint)sStack_20a78.sa_data._6_4_ >> 8 & 0xff,
             (uint)sStack_20a78.sa_data._6_4_ >> 0x10 & 0xff);
    }
    else {
      aiStack_20a5c[0] = 0;
      inet_aton(acStack_10021,aiStack_20ac4);
      inet_aton(acStack_10021,&iStack_20a4c);
    }
  }
  auStack_2002c[0]._0_1_ = 0;
  iStack_20ba0 = 0;
  pFStack_20b80 = (FILE *)0x0;
  bVar14 = false;
  pcStack_20ba8 = DAT_00036910;
  pcStack_20b6c = (char *)0x0;
  bVar32 = true;
  pcStack_20bb0 = (char *)0x0;
  bVar51 = false;
  pcStack_20b74 = (char *)0x0;
  bVar62 = false;
  iVar25 = DAT_00036914 + 0x35b3a;
  pcVar53 = (char *)(DAT_00036918 + 0x359a8);
  iVar56 = DAT_0003691c + 0x35b5a;
LAB_000359bc:
  sVar26 = strlen((char *)auStack_2002c);
  if (60000 < sVar26) goto LAB_00037d14;
  iVar42 = 0;
  do {
    fStack_209b8.fds_bits[iVar42] = 0;
    iVar42 = iVar42 + 1;
  } while (iVar42 != 0x20);
  tStack_20ae4.tv_usec = 0;
  uVar43 = *puVar33;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar43 = uVar43 & 0x8000001f;
  if ((int)uVar43 < 0) {
    uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar43 & 0xff);
  if (bVar62) {
    tStack_20ae4.tv_sec = 10;
  }
  else {
    tStack_20ae4.tv_sec = 1;
  }
  if (*piVar41 == 0) {
LAB_00035a7c:
    iVar42 = select(*puVar33 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  }
  else {
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b1b4(0,pcVar17);
    iVar42 = SSL_pending((SSL *)**(undefined4 **)(iVar50 + DAT_00036920));
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b1b4(0,pcVar17);
    if (iVar42 == 0) goto LAB_00035a7c;
  }
  if (iVar42 < 1) {
LAB_000364e8:
    pcVar60 = (char *)(DAT_000369d8 + 0x36508);
    iVar56 = DAT_000369d4 + 0x366a6;
LAB_00036508:
    snprintf(pcVar17,0x400,pcVar60,iVar56);
LAB_0003651c:
    FUN_0002b1b4(0,pcVar17);
LAB_00036520:
    iVar42 = 0;
    goto LAB_00036dc4;
  }
  uVar43 = *puVar33;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar43 = uVar43 & 0x8000001f;
  if ((int)uVar43 < 0) {
    uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  if (((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar43 & 0xff)) == 0) && (*piVar41 == 0))
  goto LAB_000364e8;
  pcVar60 = (char *)(DAT_00036924 + 0x35b88);
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  sVar26 = FUN_0002bde0(*puVar33,acStack_10028,0x400);
  if (sVar26 == 0xffffffff) goto LAB_00036508;
  if (sVar26 == 0) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    goto LAB_0003651c;
  }
  if (sVar26 == 0xfffffffe) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b1b4(0,pcVar17);
    goto LAB_000359bc;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  if (!bVar51) {
    iVar42 = (int)pcStack_20bb0 + sVar26;
    if (iVar42 < 0x10000) {
      snprintf(pcVar17,0x400,pcVar60,iVar56);
      FUN_0002b1b4(0,pcVar17);
      memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
      *(undefined1 *)((int)auStack_2002c + iVar42) = 0;
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036994 + 0x36338));
      pcStack_20bb0 = (char *)iVar42;
      if ((((pcVar60 == (char *)0x0) ||
           (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036998 + 0x36358)),
           pcVar60 == (char *)0x0)) ||
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_0003699c + 0x36370)),
          pcVar60 == (char *)0x0)) ||
         ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369a0 + 0x36388)),
          pcVar60 == (char *)0x0 &&
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369a8 + 0x363ac)),
          pcVar60 == (char *)0x0)))) {
        pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369ac + 0x363c4));
        if ((pcVar60 == (char *)0x0) ||
           ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369b0 + 0x363dc)),
            pcVar60 == (char *)0x0 ||
            (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369b4 + 0x363f4)),
            pcVar60 == (char *)0x0)))) {
          pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369bc + 0x36414));
          if ((pcVar60 == (char *)0x0) ||
             ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369c0 + 0x3642c)),
              pcVar60 == (char *)0x0 ||
              (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369c4 + 0x36444)),
              pcVar60 == (char *)0x0)))) {
            strcasestr((char *)auStack_2002c,(char *)(DAT_000369cc + 0x36480));
            goto LAB_00036680;
          }
          pcVar60 = (char *)(DAT_000369c8 + 0x36458);
        }
        else {
          pcVar60 = (char *)(DAT_000369b8 + 0x36404);
        }
      }
      else {
        pcVar60 = (char *)(DAT_000369a4 + 0x3639c);
      }
      pcVar60 = strcasestr((char *)auStack_2002c,pcVar60);
      if (pcVar60 == (char *)0x0) goto LAB_00036528;
      bVar51 = true;
      goto LAB_00036520;
    }
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b1b4(0,pcVar17);
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369d0 + 0x364bc));
    if (pcVar60 != (char *)0x0) {
      bVar14 = true;
LAB_000364d4:
      bVar32 = false;
      goto LAB_00036528;
    }
LAB_00036680:
    snprintf(pcVar17,0x400,(char *)(DAT_000369e8 + 0x366ac),DAT_000369e4 + 0x36846);
    FUN_0002b1b4(0,pcVar17);
    pcVar60 = inet_ntoa(aiStack_20ac4[0]);
    strncpy(acStack_10028,pcVar60,0x1f);
    uStack_10009 = 0;
    iVar42 = isLanSubnet(acStack_10028);
    if (((iVar42 == 0) && (iVar42 = isOpenvpnLanSubnet(acStack_10028), iVar42 == 0)) &&
       (aiStack_20a5c[0] != 1)) {
      iVar42 = isLoopBack(acStack_10028);
      if (iVar42 == 0) {
        if (((*puVar40 == uVar19) &&
            (iVar42 = acosNvramConfig_match(DAT_00036a0c + 0x367fc,DAT_00036a08 + 0x367f8),
            iVar42 == 0)) || (uVar38 = *puVar40, uVar38 == **(uint **)(iVar50 + DAT_00036c00))) {
          puts((char *)(DAT_00036a10 + 0x36810));
          iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a14 + 0x36824),0xb);
          if (iVar42 == 0) {
            iVar54 = DAT_00036a18 + 0x3683c;
            iVar42 = acosNvramConfig_match(DAT_00036a1c + 0x36840,iVar54);
            if ((iVar42 != 0) ||
               (iVar42 = acosNvramConfig_match(DAT_00036a20 + 0x3685c,iVar54), iVar42 != 0))
            goto LAB_000368f0;
          }
          pcVar60 = (char *)(DAT_00036a24 + 0x36870);
LAB_00036c30:
          puts(pcVar60);
          goto LAB_000359bc;
        }
        if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00036a28))) ||
           (uVar38 == **(uint **)(iVar50 + DAT_00036a2c))) {
          if ((!bVar65) &&
             (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a30 + 0x368c8),0xb),
             iVar42 == 0)) {
            pcVar60 = (char *)(DAT_00036a34 + 0x368dc);
            goto LAB_00036c30;
          }
        }
        else if ((uVar38 == **(uint **)(iVar50 + DAT_00036a38)) &&
                (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a3c + 0x36c20),0xb),
                iVar42 != 0)) {
          pcVar60 = (char *)(DAT_00036a40 + 0x36c34);
          goto LAB_00036c30;
        }
      }
    }
    else {
      iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_000369ec + 0x36708),0xb);
      if ((iVar42 == 0) &&
         (((iVar42 = acosNvramConfig_match(DAT_000369f4 + 0x36748,DAT_000369f0 + 0x36744),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_000369f8) == 0)) ||
          ((iVar42 = acosNvramConfig_match(DAT_00036a04 + 0x36784,DAT_00036a00 + 0x36780),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_000369f8) != 0)))))) {
        pcVar60 = (char *)(DAT_000369fc + 0x36770);
        goto LAB_00036c30;
      }
    }
LAB_000368f0:
    iVar42 = FUN_0002ae90(auStack_2002c,&puStack_20afc);
    if (iVar42 != 0) goto LAB_00036c38;
    goto LAB_000359bc;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  if (bVar32) {
    memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
    pcStack_20bb0 = (char *)((int)pcStack_20bb0 + sVar26);
    *(undefined1 *)((int)auStack_2002c + (int)pcStack_20bb0) = 0;
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036928 + 0x35cd8));
    if ((pcVar60 == (char *)0x0) ||
       (pcVar60 = strcasestr(pcVar60,(char *)(DAT_0003692c + 0x35cf4)), pcVar60 == (char *)0x0)) {
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036948 + 0x35ef0));
      pcVar46 = (char *)0x0;
      if (pcVar60 != (char *)0x0) {
        pcVar46 = (char *)(DAT_0003694c + 0x35f04);
        pcVar60 = strcasestr(pcVar60,pcVar46);
        if (pcVar60 == (char *)0x0) {
          pcVar46 = (char *)0x0;
        }
        else {
          pcVar47 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036950 + 0x35f20));
          if ((((pcVar47 == (char *)0x0) || (pcVar47[-1] != '\n')) ||
              (pcVar46 = strcasestr((char *)auStack_2002c,pcVar46), pcVar46 == (char *)0x0)) ||
             (pcVar60 + 4 <= pcVar46 + 4)) {
            pcVar46 = (char *)0x0;
            bVar14 = true;
          }
          else {
            pcVar60 = strcasestr(pcVar47 + 0x10,(char *)(DAT_00036954 + 0x35f70));
            pcVar48 = pcVar47 + 0xf;
            pcStack_20ba8 = (char *)0x0;
            for (iVar42 = 0; iVar42 < (int)pcVar60 - (int)(pcVar47 + 0x10); iVar42 = iVar42 + 1) {
              pcVar48 = pcVar48 + 1;
              pcStack_20ba8 = (char *)((int)pcStack_20ba8 * 10 + *pcVar48 + -0x30);
            }
            if (&UNK_00100001 <= pcStack_20ba8) {
              bVar62 = true;
              goto LAB_000361e0;
            }
            pcStack_20ba8 = pcVar46 + 4 + ((int)pcStack_20ba8 - (int)auStack_2002c);
            pcVar46 = (char *)0x0;
            **(undefined4 **)(iVar50 + DAT_00036958) = pcStack_20ba8;
          }
        }
      }
LAB_00035ffc:
      if (**(int **)(iVar50 + DAT_00036a5c) == 1) {
        system((char *)(DAT_0003695c + 0x3601c));
        pFStack_20b80 = fopen64((char *)(DAT_00036964 + 0x36030),(char *)(DAT_00036960 + 0x3602c));
        if (pFStack_20b80 == (FILE *)0x0) {
          puts((char *)(DAT_0003696c + 0x360c4));
          bVar14 = true;
        }
        else {
          puVar64 = auStack_20aa8;
          puVar61 = (uint *)((int)auStack_2002c + (int)pcVar46);
          do {
            puVar44 = puVar61 + 2;
            uVar38 = puVar61[1];
            *puVar64 = *puVar61;
            puVar64[1] = uVar38;
            puVar64 = puVar64 + 2;
            puVar61 = puVar44;
          } while (puVar44 != (uint *)((int)auStack_2001c + (int)pcVar46));
          sVar57 = (int)pcStack_20bb0 - (int)(pcVar46 + 0x10);
          sVar26 = fwrite((char *)((int)auStack_2002c + (int)(pcVar46 + 0x10)),1,sVar57,
                          pFStack_20b80);
          if (sVar57 != sVar26) {
            puts((char *)(DAT_00036968 + 0x360a0));
            bVar14 = true;
          }
          iStack_20ba0 = iStack_20ba0 + sVar26;
        }
        goto LAB_00036528;
      }
      piVar45 = *(int **)(iVar50 + DAT_00036970);
      if ((void *)*piVar45 != (void *)0x0) {
        free((void *)*piVar45);
        *piVar45 = 0;
      }
      FUN_0005d570(&uStack_20adc);
      pcVar60 = (char *)((int)pcStack_20bb0 - (int)pcVar46);
      if (((0 < (int)pcVar60) && (pcVar47 = pcStack_20ba8 + 600, pcStack_20ba8 < pcVar47)) &&
         (pcVar60 < pcVar47)) {
        pvVar27 = malloc((size_t)pcVar47);
        *piVar45 = (int)pvVar27;
        if (pvVar27 == (void *)0x0) {
          puts((char *)(DAT_00036978 + 0x3614c));
          system((char *)(DAT_0003697c + 0x36158));
          sleep(2);
          system((char *)(DAT_00036980 + 0x3616c));
          sleep(1);
          pvVar27 = malloc((size_t)pcVar47);
          *piVar45 = (int)pvVar27;
          if (pvVar27 == (void *)0x0) {
            puts((char *)(DAT_00036984 + 0x36198));
            bVar62 = false;
            goto LAB_000361e0;
          }
        }
        memset((void *)*piVar45,0x20,(size_t)pcVar47);
        memcpy((void *)*piVar45,(char *)((int)auStack_2002c + (int)pcVar46),(size_t)pcVar60);
        pcStack_20b74 = pcVar60 + *piVar45;
        pcStack_20b6c = pcVar60;
        goto LAB_000364d4;
      }
      puts((char *)(DAT_00036974 + 0x36128));
    }
    else {
      bVar9 = pcVar60[0xb];
      FUN_0003d6c4();
      uVar38 = FUN_0003d42c(pcVar60 + 4,0x200);
      if (uVar38 == 0) {
        cVar10 = pcVar60[0x14];
        bVar1 = pcVar60[0x17];
        pcVar46 = pcVar60 + 4 + ((uint)bVar9 - (int)auStack_2002c);
        bVar9 = pcVar60[0x16];
        bVar2 = pcVar60[0x15];
        FUN_0003d6c4();
        cVar11 = pcVar60[0x18];
        bVar3 = pcVar60[0x1b];
        bVar4 = pcVar60[0x1a];
        bVar5 = pcVar60[0x19];
        FUN_0003d6c4();
        uVar34 = (uint)(byte)pcVar60[0x1f] + pcVar60[0x1c] * 0x1000000 +
                 (uint)(byte)pcVar60[0x1e] * 0x100 + (uint)(byte)pcVar60[0x1d] * 0x10000;
        FUN_0003d6c4();
        uVar43 = (uint)(byte)pcVar60[0x23] + pcVar60[0x20] * 0x1000000 +
                 (uint)(byte)pcVar60[0x22] * 0x100 + (uint)(byte)pcVar60[0x21] * 0x10000;
        FUN_0003d6c4();
        cVar12 = pcVar60[0x24];
        bVar6 = pcVar60[0x27];
        bVar7 = pcVar60[0x26];
        bVar8 = pcVar60[0x25];
        FUN_0003d6c4();
        pcStack_20ba8 = (char *)(uVar34 + uVar43);
        uStack_20adc = uVar34;
        uStack_20ad8 = uVar43;
        iStack_20ad4 = (uint)bVar1 + cVar10 * 0x1000000 + (uint)bVar9 * 0x100 +
                       (uint)bVar2 * 0x10000;
        iStack_20ad0 = (uint)bVar3 + cVar11 * 0x1000000 + (uint)bVar4 * 0x100 +
                       (uint)bVar5 * 0x10000;
        iStack_20acc = (uint)bVar6 + cVar12 * 0x1000000 + (uint)bVar7 * 0x100 +
                       (uint)bVar8 * 0x10000;
        FUN_0003d6c4();
        if (**(int **)(iVar50 + DAT_00036930) == 1) {
          if (uVar34 < 0x6000001) {
            if (uVar43 < 0x6000001) {
              if (pcStack_20ba8 < (char *)0x6000001) goto LAB_00035ffc;
              pcVar60 = (char *)(DAT_0003693c + 0x35e58);
            }
            else {
              pcVar60 = (char *)(DAT_00036938 + 0x35e40);
            }
          }
          else {
            pcVar60 = (char *)(DAT_00036934 + 0x35e2c);
          }
          puts(pcVar60);
          if (!bVar14) {
            FUN_0005d464(**(undefined4 **)(iVar50 + DAT_00036b7c));
          }
          goto LAB_00035ffc;
        }
        uStack_20af0 = uVar38;
        getRoofsSize(&uStack_20af0);
        printf((char *)(DAT_00036940 + 0x35e98),uVar34,uStack_20af0);
        if (uStack_20af0 < uVar34) {
          FUN_0003d6c4();
          printf((char *)(DAT_00036944 + 0x35eb8),uStack_20af0);
        }
        else {
          if (pcStack_20ba8 < (char *)0x6000001) {
            FUN_0003d6c4();
            bVar62 = true;
            goto LAB_00035ffc;
          }
          FUN_0003d6c4();
        }
      }
    }
LAB_000361e0:
    bVar14 = true;
    bVar32 = false;
    goto LAB_000359bc;
  }
  if (bVar14) goto LAB_000359bc;
  if (**(int **)(iVar50 + DAT_00036a5c) == 1) {
    sVar57 = fwrite(acStack_10028,1,sVar26,pFStack_20b80);
    if (sVar26 != sVar57) {
      puts((char *)(DAT_00036988 + 0x36244));
      bVar14 = true;
    }
    iStack_20ba0 = iStack_20ba0 + sVar57;
  }
  else {
    memcpy(pcStack_20b74,acStack_10028,sVar26);
    pcStack_20b74 = pcStack_20b74 + sVar26;
    pcStack_20b6c = pcStack_20b6c + sVar26;
    pcStack_20bb0 = (char *)((int)pcStack_20bb0 + sVar26);
    iVar42 = (int)pcStack_20bb0 + 0xffff;
    if (-1 < (int)pcStack_20bb0) {
      iVar42 = (int)pcStack_20bb0;
    }
    if (iVar42 >> 0x10 != *(int *)(DAT_0003698c + 0x36f80)) {
      *(int *)(DAT_0003698c + 0x36f80) = iVar42 >> 0x10;
      fputc(0x2e,(FILE *)**(undefined4 **)(iVar50 + DAT_00036990));
    }
  }
LAB_00036528:
  snprintf(pcVar17,0x400,(char *)(DAT_000369e0 + 0x36550),DAT_000369dc + 0x366ee);
  FUN_0002b1b4(0,pcVar17);
  if ((bVar14) || (pcStack_20b6c < pcStack_20ba8)) {
    bVar51 = true;
    goto LAB_000359bc;
  }
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
  uVar43 = *puVar39;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar34 = uVar43 & 0x8000001f;
  if ((int)uVar34 < 0) {
    uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
  tStack_20ae4.tv_sec = 0;
  tStack_20ae4.tv_usec = 200;
  puStack_20afc = auStack_2002c;
  iVar25 = select(uVar43 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  if (0 < iVar25) {
    uVar43 = *puVar39;
    uVar38 = uVar43 + 0x1f;
    if (-1 < (int)uVar43) {
      uVar38 = uVar43;
    }
    uVar34 = uVar43 & 0x8000001f;
    bVar65 = (int)uVar34 < 0;
    if (bVar65) {
      uVar34 = uVar34 - 1;
    }
    if (bVar65) {
      uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
    }
    if ((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar34 & 0xff)) != 0) {
      FUN_0002bde0(uVar43,acStack_10028,0x400);
    }
  }
  bVar51 = true;
  iVar42 = 1;
LAB_00036c38:
  snprintf(pcVar17,0x400,(char *)(DAT_00036a48 + 0x36c60),DAT_00036a44 + 0x36dfe);
  FUN_0002b1b4(0,pcVar17);
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
  uVar43 = *puVar39;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar34 = uVar43 & 0x8000001f;
  if ((int)uVar34 < 0) {
    uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
  tStack_20ae4.tv_usec = 200;
  tStack_20ae4.tv_sec = 0;
  iVar25 = select(uVar43 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  if (0 < iVar25) {
    uVar43 = *puVar39;
    uVar38 = uVar43 + 0x1f;
    if (-1 < (int)uVar43) {
      uVar38 = uVar43;
    }
    uVar43 = uVar43 & 0x8000001f;
    if ((int)uVar43 < 0) {
      uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
    }
    if ((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar43 & 0xff)) != 0) {
      pcVar53 = (char *)(DAT_00036a50 + 0x36d70);
      iVar25 = DAT_00036a4c + 0x36f0a;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
      FUN_0002bde0(*puVar39,acStack_10028,0x400);
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
    }
  }
LAB_00036dc4:
  pcVar53 = (char *)(DAT_00036a58 + 0x36de8);
  iVar25 = DAT_00036a54 + 0x36f82;
  snprintf(pcVar17,0x400,pcVar53,iVar25);
  FUN_0002b1b4(0,pcVar17);
  piVar45 = *(int **)(iVar50 + DAT_00036a5c);
  if (*piVar45 == 1) {
    acStack_2022c[0] = '\0';
    acStack_2022c[1] = '\0';
    acStack_2022c[2] = '\0';
    acStack_2022c[3] = '\0';
    memset(acStack_2022c + 4,0,0x1fc);
    acStack_10028[0] = '\0';
    acStack_10028[1] = '\0';
    acStack_10028[2] = '\0';
    acStack_10028[3] = '\0';
    memset(acStack_10028 + 4,0,0x1fc);
    memset(auStack_20aa8 + 4,0,0x10);
    memset(auStack_20a88,0,0x10);
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b1b4(0,pcVar17);
    if (pFStack_20b80 != (FILE *)0x0) {
      fclose(pFStack_20b80);
    }
    iVar25 = DAT_00036a60;
    *piVar45 = 0;
    pcVar53 = (char *)(DAT_00036a64 + 0x36edc);
    rename((char *)(iVar25 + 0x36ed0),pcVar53);
    if (DAT_00036a68 < auStack_20aa8[0] - 1) {
      puts((char *)(DAT_00036a6c + 0x36f08));
      snprintf(acStack_20748,0x11b,(char *)(DAT_00036a74 + 0x36f28),2);
      uVar38 = *puVar33;
      iVar56 = DAT_00036a78 + 0x36f48;
      iVar25 = DAT_00036a7c + 0x36f4c;
    }
    else {
      iVar56 = truncate64(pcVar53,(ulonglong)auStack_20aa8[0]);
      if (iVar56 == 0) {
        pcVar60 = (char *)(DAT_00036a94 + 0x36fc8);
        printf((char *)(DAT_00036a98 + 0x36fd0),auStack_20aa8[0]);
        pFVar31 = fopen64(pcVar53,pcVar60);
        if (pFVar31 == (FILE *)0x0) {
          puts((char *)(DAT_00036a9c + 0x36ff8));
          snprintf(acStack_20748,0x11b,(char *)(DAT_00036aa4 + 0x37018),2);
          iVar56 = DAT_00036aa8 + 0x37038;
          iVar25 = DAT_00036aac + 0x3703c;
          uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
        }
        else {
          iVar56 = FUN_0012ae88(pFVar31,auStack_20aa8[0],&iStack_20af4);
          if (iVar56 == 0) {
            fclose(pFVar31);
            if (auStack_20aa8[1] == iStack_20af4 && iStack_20af4 != 0) {
              system((char *)(DAT_00036ad8 + 0x37148));
              pFVar31 = fopen64((char *)(iVar25 + 0x36ed0),pcVar60);
              if (pFVar31 == (FILE *)0x0) {
                puts((char *)(DAT_00036adc + 0x37174));
                FUN_00130b80(2);
                snprintf(acStack_20748,0x11b,(char *)(DAT_00036ae0 + 0x37190),2);
                iVar56 = DAT_00036ae4 + 0x371b4;
                iVar25 = DAT_00036ae8 + 0x371b8;
                uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
              }
              else {
                fseek(pFVar31,0,0);
                iStack_20bac = ftell(pFVar31);
                if (iStack_20bac == -1) {
                  perror((char *)(DAT_00036aec + 0x371e8));
                  iStack_20bac = 0;
                }
                iVar25 = 0;
                bVar51 = false;
                pcVar53 = (char *)(DAT_00036af0 + 0x37204);
                bVar65 = false;
                puStack_20ba4 = (undefined1 *)0x0;
                pcVar60 = (char *)(DAT_00036af4 + 0x37218);
                pcStack_20bb0 = (char *)0x0;
                pcVar46 = (char *)(DAT_00036af8 + 0x37228);
                pcVar47 = (char *)(DAT_00036afc + 0x37234);
                pcVar48 = (char *)(DAT_00036b00 + 0x37240);
                bVar62 = false;
                while (iVar56 = feof(pFVar31), iVar56 == 0) {
                  iVar25 = ftell(pFVar31);
                  if (iVar25 == -1) {
                    perror(pcVar53);
                    iVar25 = 0;
                  }
                  uStack_2062c = CONCAT22(uStack_2062c._2_2_,0xffff);
                  fgets((char *)&uStack_2062c,0x200,pFVar31);
                  pcVar28 = strcasestr((char *)&uStack_2062c,pcVar60);
                  bVar32 = (bool)(bVar65 ^ 1);
                  if (pcVar28 == (char *)0x0) {
                    bVar32 = false;
                  }
                  if (bVar32) {
                    strncpy(acStack_2022c,(char *)&uStack_2062c,0x1ff);
                    uStack_2002d = 0;
                    pcStack_20bb0 = acStack_20223;
                    pcVar28 = strrchr(acStack_2022c,0x22);
                    bVar65 = true;
                    if (pcVar28 != (char *)0x0) {
                      *pcVar28 = '\0';
                    }
                    printf(pcVar48,pcStack_20bb0);
                  }
                  else {
                    pcVar28 = strcasestr((char *)&uStack_2062c,pcVar46);
                    if (pcVar28 == (char *)0x0 || bVar62) {
                      if ((char)uStack_2062c == '\0') {
                        bVar32 = (bool)(bVar51 ^ 1);
                        if (uStack_2062c._1_1_ != '\0') {
                          bVar32 = false;
                        }
                        if (!bVar32) goto LAB_000373ec;
                      }
                      else {
LAB_000373ec:
                        pcVar28 = strcasestr((char *)&uStack_2062c,acStack_2042c);
                        if (pcVar28 == (char *)0x0) goto LAB_00037410;
                        if (!bVar51) {
                          iVar25 = iVar25 + -2;
                        }
                      }
                      bVar51 = true;
                    }
                    else {
                      strncpy(acStack_10028,(char *)&uStack_2062c,0x1ff);
                      bVar62 = true;
                      local_fe29 = 0;
                      pcVar28 = strrchr(acStack_10028,0x22);
                      if (pcVar28 != (char *)0x0) {
                        *pcVar28 = '\0';
                      }
                      sVar26 = strlen(acStack_1001e);
                      if (0x1f < sVar26) {
                        local_ffff = 0;
                      }
                      puStack_20ba4 = &stack0xfffdf430 + DAT_00036b04;
                      printf(pcVar47,puStack_20ba4);
                    }
                  }
LAB_00037410:
                  bVar32 = bVar65;
                  if (!bVar62) {
                    bVar32 = false;
                  }
                  if (bVar32) {
                    if (bVar51) {
                      bVar65 = true;
                      bVar62 = true;
                      break;
                    }
                    bVar65 = true;
                    bVar51 = false;
                    bVar62 = bVar65;
                  }
                }
                bVar65 = (bool)(bVar65 ^ 1);
                printf((char *)(DAT_00036b08 + 0x37458),iStack_20ba0);
                iVar56 = feof(pFVar31);
                if (iVar56 != 0) {
                  bVar51 = true;
                }
                if (!bVar62) {
                  bVar65 = true;
                }
                fclose(pFVar31);
                if (!bVar65 && bVar51) {
                  iVar25 = iVar25 - iStack_20bac;
                  if (0 < iVar25) {
                    iVar56 = truncate64((char *)(DAT_00036b20 + 0x3750c),(longlong)iVar25);
                    if (iVar56 != 0) {
                      perror((char *)(DAT_00036b24 + 0x37520));
                    }
                    printf((char *)(DAT_00036b28 + 0x37530),iVar25);
                  }
                  iVar25 = FUN_00131468(auStack_20ab8,&uStack_20af8,DAT_00036b30 + 0x37550,
                                        DAT_00036b2c + 0x37548);
                  if (iVar25 == 0) {
                    if (*pcStack_20bb0 != '\0') {
                      __isoc99_sscanf(pcStack_20bb0,DAT_00036b40 + 0x375e0,auStack_20aa8 + 4,
                                      auStack_20a94);
                    }
                    iVar25 = 0;
                    do {
                      auStack_20ab0[iVar25] = (char)(auStack_20aa8 + 4)[iVar25];
                      iVar56 = iVar25 + 1;
                      auStack_20aac[iVar25] = (char)auStack_20a88[iVar25];
                      iVar25 = iVar56;
                    } while (iVar56 != 4);
                    strncpy(acStack_20848,(char *)(DAT_00036b44 + 0x37650),0xff);
                    uStack_20749 = 0;
                    snprintf(acStack_20848,0x100,(char *)(DAT_00036b48 + 0x37674),
                             DAT_00036b4c + 0x37680);
                    pFVar31 = fopen64((char *)(DAT_00036b54 + 0x37694),
                                      (char *)(DAT_00036b50 + 0x37690));
                    puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
                    if (pFVar31 == (FILE *)0x0) {
                      FUN_00130b80(3);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036b58 + 0x376c8),3);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036b5c + 0x376e8;
                      iVar25 = DAT_00036b60 + 0x376ec;
                    }
                    else {
                      uVar38 = FUN_0012afdc(acStack_20848,pFVar31,uStack_20af8,auStack_20ab8);
                      if (uVar38 == 0) {
                        fclose(pFVar31);
                        FUN_00132d6c(puStack_20ba4);
                        uVar23 = FUN_0003b984(DAT_00036b70 + 0x3777c);
                        uVar29 = FUN_0003b984(DAT_00036b74 + 0x3778c);
                        uStack_20adc = uVar38;
                        FUN_0012b21c(uVar23,uVar29,&uStack_20adc);
                        iVar25 = DAT_00036b78 + 0x377b4;
                        goto LAB_00037868;
                      }
                      fclose(pFVar31);
                      FUN_00130b80(5);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036b64 + 0x3773c),5);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036b68 + 0x3775c;
                      iVar25 = DAT_00036b6c + 0x37760;
                    }
                  }
                  else {
                    FUN_00130b80(4);
                    snprintf(acStack_20748,0x11b,(char *)(DAT_00036b34 + 0x37580),4);
                    iVar56 = DAT_00036b38 + 0x375a4;
                    iVar25 = DAT_00036b3c + 0x375a8;
                    uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
                  }
                }
                else {
                  puts((char *)(DAT_00036b0c + 0x374a0));
                  snprintf(acStack_20748,0x11b,(char *)(DAT_00036b14 + 0x374c0),2);
                  iVar56 = DAT_00036b18 + 0x374e0;
                  iVar25 = DAT_00036b1c + 0x374e4;
                  uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
                }
              }
            }
            else {
              puts((char *)(DAT_00036ac4 + 0x370f4));
              snprintf(acStack_20748,0x11b,(char *)(DAT_00036acc + 0x37114),2);
              iVar56 = DAT_00036ad0 + 0x37134;
              iVar25 = DAT_00036ad4 + 0x37138;
              uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
            }
          }
          else {
            fclose(pFVar31);
            puts((char *)(DAT_00036ab0 + 0x3706c));
            snprintf(acStack_20748,0x11b,(char *)(DAT_00036ab8 + 0x37090),2);
            iVar56 = DAT_00036abc + 0x370b0;
            iVar25 = DAT_00036ac0 + 0x370b4;
            uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
          }
        }
      }
      else {
        perror((char *)(DAT_00036a80 + 0x36f74));
        snprintf(acStack_20748,0x11b,(char *)(DAT_00036a88 + 0x36f94),2);
        uVar38 = *puVar33;
        iVar56 = DAT_00036a8c + 0x36fb4;
        iVar25 = DAT_00036a90 + 0x36fb8;
      }
    }
    FUN_00061680(iVar25,acStack_20748,iVar56,uVar38);
  }
  else {
    if (aiStack_20a5c[0] == 0) {
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
    }
    puVar52 = *(undefined4 **)(iVar50 + DAT_00036b7c);
    if ((*puVar40 != uVar19) ||
       (iVar25 = acosNvramConfig_match(DAT_00036b84 + 0x37818,DAT_00036b80 + 0x37814), iVar25 == 0))
    goto LAB_00037aa8;
    iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036b88 + 0x37834),0x17);
    if (iVar25 == 0) {
      printf((char *)(DAT_00036b90 + 0x37858),DAT_00036b8c + 0x379fd,0xe34);
      iVar25 = DAT_00036b94 + 0x3786c;
      goto LAB_00037868;
    }
    pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036b98 + 0x37880));
    if ((((pcVar53 == (char *)0x0) &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036b9c + 0x37898)),
         pcVar53 == (char *)0x0)) &&
        (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba0 + 0x378b0)),
        pcVar53 == (char *)0x0)) &&
       (((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba4 + 0x378c8)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba8 + 0x378e0)),
         pcVar53 == (char *)0x0)) &&
        ((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bac + 0x378f8)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bb0 + 0x37910)),
         pcVar53 == (char *)0x0)))))) {
      pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bb4 + 0x3792c));
      if (pcVar53 == (char *)0x0) {
        iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bbc + 0x37958),0x19);
        if (iVar25 == 0) {
          iVar25 = DAT_00036bc0 + 0x3796c;
        }
        else {
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bc4 + 0x37980),0xd);
          if ((iVar25 == 0) ||
             (iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bc8 + 0x3799c),0x1d),
             iVar25 == 0)) goto LAB_00037aa8;
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bcc + 0x379b8),0xe);
          iVar15.s_addr = iStack_20a4c.s_addr;
          if (iVar25 == 0) {
            printf((char *)(DAT_00036bd4 + 0x379dc),DAT_00036bd0 + 0x37b81,0xe59);
            iVar25 = DAT_00036bd8 + 0x379f0;
          }
          else {
            if ((aiStack_20a5c[0] == 0) &&
               (iVar30 = inet_addr((char *)(DAT_00036bdc + 0x37a20)), iVar15.s_addr == iVar30))
            goto LAB_00037aa8;
            iVar15.s_addr = iStack_20a4c.s_addr;
            if (aiStack_20a5c[0] == 0) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00036be0 + 0x37a3c);
              iVar30 = inet_addr(pcVar53);
              if (iVar15.s_addr == iVar30) goto LAB_00037aa8;
            }
            if (aiStack_20a5c[0] == 1) {
              inet_pton(10,(char *)(DAT_00036be4 + 0x37a70),auStack_20a88);
              iVar25 = memcmp(&uStack_20a48,auStack_20a88,0x10);
              if (iVar25 == 0) goto LAB_00037aa8;
              iVar25 = DAT_00036be8 + 0x37a98;
            }
            else {
              iVar25 = DAT_00036bec + 0x37aa8;
            }
          }
        }
LAB_00037868:
        FUN_0003c738(iVar25);
        goto LAB_00037d14;
      }
      puts((char *)(DAT_00036bb8 + 0x37940));
    }
LAB_00037aa8:
    if (iVar42 == 0) {
      pcVar53 = (char *)(DAT_00038018 + 0x37c54);
      iVar25 = DAT_00038014 + 0x37dee;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
      if (bVar51) {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b1b4(0,pcVar17);
        pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_0003801c + 0x37cb4));
        if (pcVar53 == (char *)0x0) {
          pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_00038020 + 0x37cd0));
          uVar23 = *puVar52;
          if (pcVar53 == (char *)0x0) {
            FUN_0005d464(uVar23);
            goto LAB_00037d14;
          }
        }
        else {
          uVar23 = *puVar52;
        }
        FUN_000492f8(uVar23);
      }
      else {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b1b4(0,pcVar17);
      }
    }
    else {
      iVar25 = FUN_0002b4a0(auStack_2002c);
      if (iVar25 == 1) {
        strlcpy(acStack_10028,auStack_2002c,DAT_00036bf0);
        acStack_2022c[0] = '\0';
        acStack_2022c[1] = '\0';
        acStack_2022c[2] = '\0';
        acStack_2022c[3] = '\0';
        memset(acStack_2022c + 4,0,0xfc);
        iVar25 = FUN_0002b0c8(auStack_2002c,acStack_2022c);
        puVar61 = *(uint **)(iVar50 + DAT_00036bf4);
        puVar39 = *(uint **)(iVar50 + DAT_00036c00);
        printf((char *)(DAT_00036bfc + 0x37b2c),DAT_00036bf8 + 0x37cbd,0xe8f,*puVar40);
        iVar15.s_addr = iStack_20a4c.s_addr;
        if ((*puVar40 != *puVar39) && (*puVar40 != *puVar61)) {
          if (aiStack_20a5c[0] == 0) {
            iVar30 = inet_addr((char *)(DAT_0003800c + 0x37c08));
            iVar16.s_addr = iStack_20a4c.s_addr;
            if (iVar15.s_addr != iVar30) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00038010 + 0x37c20);
              iVar30 = inet_addr(pcVar53);
              if (iVar16.s_addr != iVar30) goto LAB_00037bb4;
            }
          }
          else {
LAB_00037bb4:
            if (iVar25 != 1 || aiStack_20a5c[0] == 0) {
              printf((char *)(DAT_00036c08 + 0x37bf0),DAT_00036c04 + 0x37d95,0xe9d);
              goto LAB_00037d14;
            }
          }
        }
        sVar26 = strlen((char *)auStack_2002c);
        FUN_000669f4(acStack_10028,*puVar52,iStack_20a4c.s_addr,sVar26);
      }
      else {
        snprintf(pcVar17,0x400,(char *)(DAT_0003806c + 0x37fd8),DAT_00038068 + 0x38176);
        FUN_0002b1b4(0,pcVar17);
        FUN_0002c068(auStack_2002c,puStack_20afc,aiStack_20a5c,*puVar52);
      }
    }
  }
LAB_00037d14:
  if (*piVar41 != 0) {
    puVar52 = *(undefined4 **)(iVar50 + DAT_00038024);
    iVar25 = SSL_get_fd((SSL *)*puVar52);
    SSL_shutdown((SSL *)*puVar52);
    SSL_free((SSL *)*puVar52);
    snprintf(pcVar17,0x400,(char *)(DAT_0003802c + 0x37d70),DAT_00038028 + 0x37f0e);
    FUN_0002b1b4(0,pcVar17);
    close(iVar25);
  }
  snprintf(pcVar17,0x400,(char *)(DAT_00038034 + 0x37db0),DAT_00038030 + 0x37f4e);
  FUN_0002b1b4(0,pcVar17);
  close(*puVar33);
  goto LAB_00034354;
}



===== FUN_000381f0 @ 000381f0 =====

void FUN_000381f0(int param_1)

{
  size_t __n;
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  char *__modes;
  char *__filename;
  undefined4 uStack_10050;
  undefined1 auStack_1004c [36];
  undefined1 auStack_10028 [65552];
  
  iVar5 = DAT_00038410 + 0x38208;
  piVar6 = *(int **)(iVar5 + DAT_00038414);
  iVar3 = *piVar6;
  if (param_1 == 10) {
    **(undefined4 **)(iVar5 + DAT_00038418) = 1;
    if (**(int **)(iVar5 + DAT_0003841c) == 2) {
      FUN_0012c708();
    }
  }
  else if (param_1 == 1) {
    **(undefined4 **)(iVar5 + DAT_00038420) = 1;
  }
  else if (param_1 == 0xc) {
    FUN_000af3b4();
  }
  else {
    if (param_1 == 0x11) {
      if (iVar3 == *piVar6) {
        wait((void *)0x0);
        return;
      }
      goto LAB_00038404;
    }
    if (param_1 == 3) {
      iVar5 = FUN_00058c7c();
      if (iVar5 != 0) {
        FUN_00059794();
      }
      if (iVar3 == *piVar6) {
        FUN_00125088();
        return;
      }
      goto LAB_00038404;
    }
    if (param_1 == 4) {
      if (iVar3 == *piVar6) {
        iVar4 = DAT_000381c0 + 0x38090;
        piVar6 = *(int **)(iVar4 + DAT_000381c4);
        iVar5 = DAT_000381c8 + 0x380a4;
        iVar2 = *piVar6;
        uStack_10050 = 0;
        iVar3 = acosNvramConfig_match(DAT_000381cc + 0x380ac,iVar5);
        if (iVar3 == 0) {
          iVar5 = DAT_000381d0 + 0x380d8;
        }
        iVar3 = get_pid(iVar5);
        acosNvramConfig_unset(DAT_000381d4 + 0x380e8);
        __n = DAT_000381dc;
        puVar7 = *(undefined4 **)(iVar4 + DAT_000381d8);
        *puVar7 = 1;
        memset(auStack_10028,0,__n);
        FUN_0003c24c(DAT_000381e4 + 0x38124,DAT_000381e0 + 0x38120,0);
        iVar5 = open64((char *)(DAT_000381e8 + 0x38134),0);
        read(iVar5,auStack_10028,0x10000);
        printf((char *)(DAT_000381ec + 0x38154),auStack_10028);
        close(iVar5);
        FUN_0002ae90(auStack_10028,&uStack_10050);
        FUN_0002c068(auStack_10028,uStack_10050,auStack_1004c,0xfffffffe);
        *puVar7 = 0;
        if (iVar3 != 0) {
          kill(iVar3,4);
        }
        if (iVar2 != *piVar6) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
      goto LAB_00038404;
    }
    if (param_1 == 0x1c) {
      __modes = (char *)(DAT_00038424 + 0x38300);
      __filename = (char *)(DAT_00038428 + 0x38304);
      pFVar1 = fopen64(__filename,__modes);
      iVar2 = DAT_0003842c;
      if (pFVar1 == (FILE *)0x0) {
        agApi_clear_nat_for_httpd();
        FUN_000b889c();
        FUN_000b94e0();
        FUN_00062754();
        FUN_00063624();
        FUN_000bc76c();
        FUN_000accf4();
        FUN_000b3c00();
        FUN_000bbd0c();
        FUN_000ac02c();
        FUN_000ab1f0();
        FUN_000bdedc();
        FUN_000b03f0();
        FUN_000f0994();
        FUN_00125088();
        pFVar1 = fopen64((char *)(iVar2 + 0x38344),__modes);
        if (pFVar1 != (FILE *)0x0) {
          printf((char *)(DAT_00038434 + 0x383a4),&UNK_00038550 + DAT_00038430,0x2188);
          close((int)pFVar1);
          unlink((char *)(iVar2 + 0x38344));
          deviceAccessControlInit();
        }
        if (**(int **)(iVar5 + DAT_00038438) != 0) {
          FUN_00050738();
        }
        FUN_0011c224();
        iVar5 = *piVar6;
      }
      else {
        close((int)pFVar1);
        unlink(__filename);
        FUN_0011c224();
        iVar5 = *piVar6;
      }
      if (iVar3 == iVar5) {
        FUN_00119f04(1);
        return;
      }
      goto LAB_00038404;
    }
  }
  if (iVar3 == *piVar6) {
    return;
  }
LAB_00038404:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



===== FUN_00119f04 @ 00119f04 =====

void FUN_00119f04(int param_1)

{
  bool bVar1;
  __pid_t _Var2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iStack_18;
  int local_14;
  
  iVar4 = DAT_0011a26c + 0x119f1c;
  piVar5 = *(int **)(iVar4 + DAT_0011a270);
  local_14 = *piVar5;
  iStack_18 = param_1;
  if (param_1 == 1) {
    iVar3 = 0;
    do {
      bVar1 = true;
      if (*(int *)(iVar3 + *(int *)(iVar4 + DAT_0011a278)) == 1) goto LAB_00119f58;
      iVar3 = iVar3 + 0x54d80;
    } while (iVar3 != DAT_0011a274);
    bVar1 = false;
LAB_00119f58:
    FUN_00113bc4();
    _Var2 = fork();
    if (_Var2 == 0) {
      _Var2 = fork();
      if (_Var2 == 0) {
        if (**(int **)(iVar4 + DAT_0011a27c) != 0) {
          close(**(int **)(iVar4 + DAT_0011a27c));
        }
        if (**(int **)(iVar4 + DAT_0011a280) != 0) {
          close(**(int **)(iVar4 + DAT_0011a280));
        }
        if (**(int **)(iVar4 + DAT_0011a284) != -1) {
          close(**(int **)(iVar4 + DAT_0011a284));
        }
        if (**(int **)(iVar4 + DAT_0011a288) != -1) {
          close(**(int **)(iVar4 + DAT_0011a288));
        }
        if (**(int **)(iVar4 + DAT_0011a28c) != -1) {
          close(**(int **)(iVar4 + DAT_0011a28c));
        }
        if (**(int **)(iVar4 + DAT_0011a290) != -1) {
          close(**(int **)(iVar4 + DAT_0011a290));
        }
        FUN_001145fc();
        remove((char *)(DAT_0011a294 + 0x11a014));
        if (bVar1) {
          FUN_001134c4();
          if ((**(int **)(iVar4 + DAT_0011a298) == 0) && (**(int **)(iVar4 + DAT_0011a29c) != 0)) {
            system((char *)(DAT_0011a2a0 + 0x11a054));
          }
          else {
            remove((char *)(DAT_0011a2a4 + 0x11a064));
          }
          iVar4 = acosNvramConfig_match(DAT_0011a2ac + 0x11a078,DAT_0011a2a8 + 0x11a074);
          if (iVar4 != 0) {
            sleep(5);
            FUN_0011452c();
          }
        }
      }
LAB_0011a08c:
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (0 < _Var2) {
      waitpid(_Var2,&iStack_18,0);
    }
  }
  else if (param_1 == 2) {
    iVar3 = 0;
    do {
      bVar1 = true;
      if (*(int *)(iVar3 + *(int *)(iVar4 + DAT_0011a278)) == 1) goto LAB_0011a0e0;
      iVar3 = iVar3 + 0x54d80;
    } while (iVar3 != DAT_0011a274);
    bVar1 = false;
LAB_0011a0e0:
    FUN_00113bc4();
    _Var2 = fork();
    if (_Var2 == 0) {
      _Var2 = fork();
      if (_Var2 == 0) {
        if (**(int **)(iVar4 + DAT_0011a27c) != 0) {
          close(**(int **)(iVar4 + DAT_0011a27c));
        }
        if (**(int **)(iVar4 + DAT_0011a280) != 0) {
          close(**(int **)(iVar4 + DAT_0011a280));
        }
        if (**(int **)(iVar4 + DAT_0011a284) != -1) {
          close(**(int **)(iVar4 + DAT_0011a284));
        }
        if (**(int **)(iVar4 + DAT_0011a288) != -1) {
          close(**(int **)(iVar4 + DAT_0011a288));
        }
        remove((char *)(DAT_0011a2b0 + 0x11a168));
        if (bVar1) {
          FUN_001134c4();
          if ((**(int **)(iVar4 + DAT_0011a298) == 0) && (**(int **)(iVar4 + DAT_0011a29c) != 0)) {
            system((char *)(DAT_0011a2b4 + 0x11a1a8));
          }
          else {
            remove((char *)(DAT_0011a2b8 + 0x11a1b8));
          }
          iVar4 = acosNvramConfig_match(DAT_0011a2c0 + 0x11a1cc,DAT_0011a2bc + 0x11a1c8);
          if (iVar4 != 0) {
            system((char *)(DAT_0011a2c4 + 0x11a1e0));
          }
          system((char *)(DAT_0011a2c8 + 0x11a1ec));
        }
      }
      goto LAB_0011a08c;
    }
    if (0 < _Var2) {
      waitpid(_Var2,&iStack_18,0);
    }
    goto LAB_0011a20c;
  }
  FUN_00119948(1);
LAB_0011a20c:
  iVar4 = acosNvramConfig_match(DAT_0011a2d0 + 0x11a220,DAT_0011a2cc + 0x11a21c);
  if ((iVar4 != 0) && (iVar4 = access((char *)(DAT_0011a2d4 + 0x11a238),0), iVar4 != 0)) {
    system((char *)(DAT_0011a2d8 + 0x11a24c));
  }
  if (local_14 != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



===== FUN_0003c688 @ 0003c688 =====

undefined4 FUN_0003c688(undefined4 param_1,undefined4 param_2)

{
  size_t sVar1;
  int *piVar2;
  char local_404 [1000];
  int local_1c;
  
  piVar2 = *(int **)(DAT_0003c72c + 0x3c698 + DAT_0003c730);
  local_1c = *piVar2;
  local_404[0] = '\0';
  local_404[1] = '\0';
  local_404[2] = '\0';
  local_404[3] = '\0';
  memset(local_404 + 4,0,0x3e4);
  printf((char *)(DAT_0003c734 + 0x3c6dc),param_1);
  FUN_0003c2e4(0x194,local_404,0,1000);
  sVar1 = strlen(local_404);
  FUN_0002bf74(param_2,local_404,sVar1,0);
  if (local_1c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0xffffffff;
}



===== FUN_0003c834 @ 0003c834 =====

void FUN_0003c834(char *param_1,char *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  int iVar11;
  char acStack_424 [1024];
  int local_24;
  
  iVar11 = DAT_0003d248 + 0x3c854;
  piVar10 = *(int **)(iVar11 + DAT_0003d24c);
  local_24 = *piVar10;
  iVar2 = acosNvramConfig_match(DAT_0003d254 + 0x3c86c,DAT_0003d250 + 0x3c868);
  if (iVar2 != 0) {
    printf((char *)(DAT_0003d25c + 0x3c8a0),DAT_0003d258 + 0x3c8e9,0x4f5,param_1);
  }
  pcVar3 = strchr(param_1,0x3f);
  pcVar7 = (char *)(DAT_0003d260 + 0x3c8b8);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
  }
  pcVar7 = strstr(param_1,pcVar7);
  iVar4 = DAT_0003d268;
  iVar2 = DAT_0003d264;
  if (pcVar7 != (char *)0x0) {
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '?';
    }
    iVar2 = acosNvramConfig_match(iVar4 + 0x3c8f0,iVar2 + 0x3c8e8);
    if (iVar2 != 0) {
      printf((char *)(DAT_0003d270 + 0x3c918),DAT_0003d26c + 0x3c961,0x500,param_1);
    }
    FUN_000a56c4(param_2,param_3,param_1,1);
  }
  iVar2 = DAT_0003d274;
  pcVar7 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    pcVar7 = pcVar3 + 1;
    *pcVar3 = '\0';
  }
  iVar2 = strcmp(param_1,(char *)(iVar2 + 0x3c944));
  if (((((((iVar2 == 0) || (iVar2 = strcmp(param_1,(char *)(DAT_0003d27c + 0x3c97c)), iVar2 == 0))
         || (iVar2 = strcmp(param_1,(char *)(DAT_0003d280 + 0x3c994)), iVar2 == 0)) ||
        ((iVar2 = strcmp(param_1,(char *)(DAT_0003d284 + 0x3c9ac)), iVar2 == 0 ||
         (iVar2 = strcmp(param_1,(char *)(DAT_0003d288 + 0x3c9c4)), iVar2 == 0)))) ||
       (iVar2 = strncmp(param_1,(char *)(DAT_0003d28c + 0x3c9e0),0xc), iVar2 == 0)) ||
      (pcVar3 = strstr(param_1,(char *)(DAT_0003d290 + 0x3c9f8)), pcVar3 != (char *)0x0)) ||
     ((iVar2 = acosNvramConfig_match(DAT_0003d298 + 0x3ca14,DAT_0003d294 + 0x3ca10), iVar2 != 0 &&
      ((((pcVar3 = strstr(param_1,(char *)(DAT_0003d29c + 0x3ca2c)), pcVar3 != (char *)0x0 ||
         (pcVar3 = strstr(param_1,(char *)(DAT_0003d2a0 + 0x3ca44)), pcVar3 != (char *)0x0)) ||
        ((pcVar3 = strstr(param_1,(char *)(DAT_0003d2a4 + 0x3ca5c)), pcVar3 != (char *)0x0 ||
         (((pcVar3 = strstr(param_1,(char *)(DAT_0003d2a8 + 0x3ca74)), pcVar3 != (char *)0x0 ||
           (pcVar3 = strstr(param_1,(char *)(DAT_0003d2ac + 0x3ca8c)), pcVar3 != (char *)0x0)) ||
          (pcVar3 = strstr(param_1,(char *)(DAT_0003d2b0 + 0x3caa4)), pcVar3 != (char *)0x0)))))) ||
       (iVar2 = strcmp(param_1,(char *)(DAT_0003d2b4 + 0x3cabc)), iVar2 == 0)))))) {
LAB_0003c950:
    pcVar3 = strstr(param_1,(char *)(DAT_0003d278 + 0x3c960));
    bVar1 = pcVar3 == (char *)0x0;
  }
  else {
    iVar4 = DAT_0003d2b8 + 0x3cad4;
    iVar8 = DAT_0003d2bc + 0x3cad8;
    iVar2 = acosNvramConfig_match(iVar8,iVar4);
    if ((((iVar2 != 0) || (iVar2 = acosNvramConfig_match(iVar8,DAT_0003d2c4 + 0x3cb14), iVar2 != 0))
        || ((iVar2 = acosNvramConfig_match(iVar8,DAT_0003d2c8 + 0x3cb2c), iVar2 != 0 &&
            (iVar2 = acosNvramConfig_match(DAT_0003d2cc + 0x3cb4c,iVar4), iVar2 != 0)))) &&
       (((((pcVar3 = strstr(param_1,(char *)(DAT_0003d2c0 + 0x3caf8)), pcVar3 != (char *)0x0 ||
           (pcVar3 = strstr(param_1,(char *)(DAT_0003d2d0 + 0x3cb68)), pcVar3 != (char *)0x0)) ||
          (pcVar3 = strstr(param_1,(char *)(DAT_0003d2d4 + 0x3cb80)), pcVar3 != (char *)0x0)) ||
         ((((pcVar3 = strstr(param_1,(char *)(DAT_0003d2d8 + 0x3cb98)), pcVar3 != (char *)0x0 ||
            (pcVar3 = strstr(param_1,(char *)(DAT_0003d2dc + 0x3cbb0)), pcVar3 != (char *)0x0)) ||
           (pcVar3 = strstr(param_1,(char *)(DAT_0003d2e0 + 0x3cbc8)), pcVar3 != (char *)0x0)) ||
          ((iVar2 = strcmp(param_1,(char *)(DAT_0003d2e4 + 0x3cbe0)), iVar2 == 0 ||
           (iVar2 = strcmp(param_1,(char *)(DAT_0003d2e8 + 0x3cbf8)), iVar2 == 0)))))) ||
        (*param_1 == '\0')))) goto LAB_0003c950;
    bVar1 = false;
  }
  iVar4 = strcmp(param_1,(char *)(DAT_0003d2ec + 0x3cc20));
  iVar2 = 0;
  if (iVar4 != 0) {
    iVar4 = strcmp(param_1,(char *)(DAT_0003d2f0 + 0x3cc38));
    iVar2 = 0;
    if (iVar4 != 0) {
      iVar4 = strcmp(param_1,(char *)(DAT_0003d2f4 + 0x3cc50));
      iVar2 = 0;
      if (iVar4 != 0) {
        iVar4 = strcmp(param_1,(char *)(DAT_0003d2f8 + 0x3cc68));
        iVar2 = 0;
        if (iVar4 != 0) {
          iVar4 = strcmp(param_1,(char *)(DAT_0003d2fc + 0x3cc80));
          iVar2 = 0;
          if (iVar4 != 0) {
            iVar4 = strcmp(param_1,(char *)(DAT_0003d300 + 0x3cc98));
            iVar2 = 0;
            if (iVar4 != 0) {
              iVar4 = strcmp(param_1,(char *)(DAT_0003d304 + 0x3ccb0));
              iVar2 = 0;
              if (iVar4 != 0) {
                iVar4 = strcmp(param_1,(char *)(DAT_0003d308 + 0x3ccc8));
                iVar2 = 0;
                if (iVar4 != 0) {
                  iVar4 = strcmp(param_1,(char *)(DAT_0003d30c + 0x3cce0));
                  iVar2 = 0;
                  if (iVar4 != 0) {
                    iVar2 = strcmp(param_1,(char *)(DAT_0003d310 + 0x3ccf8));
                    if (iVar2 == 0) {
LAB_0003cec0:
                      iVar2 = 0;
                    }
                    else {
                      iVar4 = strcmp(param_1,(char *)(DAT_0003d314 + 0x3cd10));
                      iVar2 = 0;
                      if (iVar4 != 0) {
                        iVar4 = strcmp(param_1,(char *)(DAT_0003d318 + 0x3cd28));
                        iVar2 = 0;
                        if (iVar4 != 0) {
                          pcVar3 = strstr(param_1,(char *)(DAT_0003d31c + 0x3cd40));
                          if (pcVar3 != (char *)0x0) goto LAB_0003cec0;
                          pcVar3 = strstr(param_1,(char *)(DAT_0003d320 + 0x3cd5c));
                          if (pcVar3 == (char *)0x0) {
                            iVar2 = 0;
                            if ((**(int **)(iVar11 + DAT_0003d324) != 1) &&
                               (pcVar3 = strstr(param_1,(char *)(DAT_0003d328 + 0x3cd8c)),
                               pcVar3 == (char *)0x0)) {
                              pcVar3 = strstr(param_1,(char *)(DAT_0003d32c + 0x3cda8));
                              if (pcVar3 != (char *)0x0) goto LAB_0003ceb0;
                              pcVar3 = strstr(param_1,(char *)(DAT_0003d330 + 0x3cdc4));
                              iVar2 = 0;
                              if (pcVar3 == (char *)0x0) {
                                pcVar3 = strstr(param_1,(char *)(DAT_0003d334 + 0x3cde0));
                                if (pcVar3 != (char *)0x0) goto LAB_0003ceb0;
                                iVar2 = strcmp(param_1,(char *)(DAT_0003d338 + 0x3cdfc));
                                if (iVar2 == 0) goto LAB_0003cec0;
                                iVar4 = strcmp(param_1,(char *)(DAT_0003d33c + 0x3ce14));
                                iVar2 = 0;
                                if (iVar4 != 0) {
                                  iVar4 = strcmp(param_1,(char *)(DAT_0003d340 + 0x3ce2c));
                                  iVar2 = 0;
                                  if (iVar4 != 0) {
                                    iVar4 = strcmp(param_1,(char *)(DAT_0003d344 + 0x3ce44));
                                    iVar2 = 0;
                                    if (iVar4 != 0) {
                                      iVar4 = strcmp(param_1,(char *)(DAT_0003d348 + 0x3ce5c));
                                      iVar2 = 0;
                                      if (iVar4 != 0) {
                                        iVar4 = strcmp(param_1,(char *)(DAT_0003d34c + 0x3ce74));
                                        iVar2 = 0;
                                        if (iVar4 != 0) {
                                          iVar2 = strcmp(param_1,(char *)(DAT_0003d350 + 0x3ce8c));
                                          if (iVar2 == 0) {
                                            bVar1 = true;
                                          }
                                          if (bVar1) goto LAB_0003cec0;
                                          iVar2 = FUN_0003aaf0(param_1,pcVar7);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
LAB_0003ceb0:
                            iVar2 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar4 = 0;
  while( true ) {
    iVar8 = *(int *)(iVar11 + DAT_0003d354);
    pcVar3 = *(char **)(iVar8 + iVar4 * 8);
    if (pcVar3 == (char *)0x0) break;
    iVar5 = strcmp(pcVar3,param_1);
    if (iVar5 == 0) {
      bVar1 = true;
      goto LAB_0003cf0c;
    }
    iVar4 = iVar4 + 1;
  }
  bVar1 = false;
LAB_0003cf0c:
  if (**(int **)(iVar11 + DAT_0003d358) == 0) {
    FUN_0003a6b4();
  }
  iVar5 = DAT_0003d394;
  pcVar3 = *(char **)(iVar11 + DAT_0003d35c);
  if (bVar1) {
    iVar11 = acosNvramConfig_match(DAT_0003d364 + 0x3cf48,DAT_0003d360 + 0x3cf44);
    if (iVar11 != 0) {
      iVar11 = DAT_0003d368 + 0x3cfb9;
      printf((char *)(DAT_0003d36c + 0x3cf70),iVar11,0x571,iVar2);
      printf((char *)(DAT_0003d370 + 0x3cf8c),iVar11,0x572,param_2);
    }
    if (iVar2 == 0) {
      iVar2 = strcmp(param_1,(char *)(DAT_0003d374 + 0x3cfa4));
      if (iVar2 == 0) {
        snprintf(pcVar3,0x400,(char *)(DAT_0003d37c + 0x3cfd4),DAT_0003d378 + 0x3d029,0x57a);
        FUN_0002b1b4(0,pcVar3);
        pcVar9 = *(code **)(iVar8 + iVar4 * 8 + 4);
        param_2 = pcVar7;
      }
      else {
        snprintf(pcVar3,0x400,(char *)(DAT_0003d384 + 0x3d024),DAT_0003d380 + 0x3d079,0x580);
        FUN_0002b1b4(0,pcVar3);
        pcVar9 = *(code **)(iVar8 + iVar4 * 8 + 4);
      }
      (*pcVar9)(param_2,param_3);
    }
    else {
      snprintf(pcVar3,0x400,(char *)(DAT_0003d38c + 0x3d078),DAT_0003d388 + 0x3d0cd,0x58c);
      FUN_0002b1b4(0,pcVar3);
      FUN_0003c738(DAT_0003d390 + 0x3d094,param_3);
      FUN_0003a6b4();
    }
  }
  else {
    snprintf(pcVar3,0x400,(char *)(DAT_0003d398 + 0x3d0bc),DAT_0003d394 + 0x3d111,0x597);
    FUN_0002b1b4(0,pcVar3);
    pcVar7 = strstr(param_1,(char *)(DAT_0003d39c + 0x3d0e0));
    if ((pcVar7 == (char *)0x0) &&
       (pcVar7 = strstr(param_1,(char *)(DAT_0003d3a0 + 0x3d0f8)), pcVar7 == (char *)0x0)) {
      iVar2 = acosNvramConfig_match(DAT_0003d3b8 + 0x3d150,DAT_0003d3b4 + 0x3d14c);
      if (iVar2 != 0) {
        printf((char *)(DAT_0003d3bc + 0x3d16c),iVar5 + 0x3d105,0x5a2);
      }
      iVar2 = DAT_0003d3c0 + 0x3d1e1;
      pcVar7 = (char *)(DAT_0003d3c4 + 0x3d190);
      FUN_0003c2e4(0x194,acStack_424,0,0x400);
      snprintf(pcVar3,0x400,pcVar7,iVar2,0x5a4);
      FUN_0002b1b4(0,pcVar3);
      sVar6 = strlen(acStack_424);
      iVar2 = FUN_0002bf74(param_3,acStack_424,sVar6,0);
      if (iVar2 == -1) goto LAB_0003d210;
    }
    else {
      iVar2 = acosNvramConfig_match(DAT_0003d3a8 + 0x3d114,DAT_0003d3a4 + 0x3d110);
      if (iVar2 != 0) {
        printf((char *)(DAT_0003d3b0 + 0x3d138),DAT_0003d3ac + 0x3d181,0x59d);
      }
    }
  }
  pcVar7 = (char *)(DAT_0003d3cc + 0x3d214);
LAB_0003d210:
  snprintf(pcVar3,0x400,pcVar7);
  FUN_0002b1b4(0,pcVar3);
  if (local_24 != *piVar10) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



===== FUN_000594cc @ 000594cc =====

int FUN_000594cc(undefined4 param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  char local_13e4 [64];
  char acStack_13a4 [5000];
  int local_1c;
  
  piVar4 = *(int **)(DAT_000595c4 + 0x594dc + DAT_000595c8);
  local_1c = *piVar4;
  local_13e4[0] = '\0';
  local_13e4[1] = '\0';
  local_13e4[2] = '\0';
  local_13e4[3] = '\0';
  memset(local_13e4 + 4,0,0x3c);
  strcpy(local_13e4,(char *)(DAT_000595cc + 0x59528));
  uVar1 = productAliasName();
  snprintf(local_13e4,0x40,(char *)(DAT_000595d0 + 0x5953c),uVar1);
  FUN_0003c2e4(0xfab,acStack_13a4,local_13e4,5000);
  acosNvramConfig_set(DAT_000595d8 + 0x59570,DAT_000595d4 + 0x5956c);
  sVar2 = strlen(acStack_13a4);
  iVar3 = FUN_0002bf74(param_1,acStack_13a4,sVar2,0);
  if (local_1c == *piVar4) {
    return -(uint)(iVar3 == -1);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



===== FUN_00147454 @ 00147454 =====

int FUN_00147454(undefined4 param_1)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  char acStack_214 [512];
  int local_14;
  
  piVar3 = *(int **)(DAT_001474d8 + 0x147464 + DAT_001474dc);
  local_14 = *piVar3;
  FUN_0003c2e4(400,acStack_214,0,0x200);
  sVar1 = strlen(acStack_214);
  iVar2 = FUN_0002bf74(param_1,acStack_214,sVar1,0);
  if (local_14 == *piVar3) {
    return -(uint)(iVar2 == -1);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


