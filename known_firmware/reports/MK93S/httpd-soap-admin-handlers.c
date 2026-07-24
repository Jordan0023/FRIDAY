
===== ENTRY 00098664 =====
===== FUNCTION FUN_00098664 @ 00098664 =====

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00098664(int param_1)

{
  char *__format;
  int iVar1;
  EVP_MD *type;
  EVP_MD_CTX *ctx;
  size_t cnt;
  undefined4 uVar2;
  int *__s;
  byte *pbVar3;
  uint local_a88 [2];
  undefined1 auStack_a80 [28];
  byte abStack_a64 [64];
  undefined4 local_a24;
  undefined1 auStack_a20 [124];
  int local_9a4;
  undefined1 auStack_9a0 [124];
  char local_924 [256];
  undefined4 local_824;
  undefined1 auStack_820 [2044];
  int local_24;
  
  local_24 = *DAT_00098888;
  local_a24 = 0;
  memset(auStack_a20,0,0x7c);
  local_924[0] = '\0';
  local_924[1] = '\0';
  local_924[2] = '\0';
  local_924[3] = '\0';
  memset(local_924 + 4,0,0xfc);
  local_a88[1] = 0;
  memset(auStack_a80,0,0x1c);
  local_824 = 0;
  memset(auStack_820,0,0x7fc);
  FUN_00098334(*(undefined4 *)(param_1 + 8),local_a88 + 1,0x20);
  iVar1 = FUN_0007461c(*(undefined4 *)(param_1 + 0xc),DAT_0009888c,&local_a24,0x80);
  if ((iVar1 == 0) && (iVar1 = acosNvramConfig_match(DAT_00098890,&local_a24), iVar1 != 0)) {
    iVar1 = FUN_0007461c(*(undefined4 *)(param_1 + 0xc),DAT_00098894,local_924,0x100);
    if (iVar1 != 0) goto LAB_00098838;
    local_9a4 = iVar1;
    memset(auStack_9a0,0,0x7c);
    __format = DAT_00098898;
    OPENSSL_init_crypto(8,0,0);
    type = EVP_get_digestbyname(DAT_0009889c);
    ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0);
    cnt = strlen(local_924);
    EVP_DigestUpdate(ctx,local_924,cnt);
    EVP_DigestFinal_ex(ctx,abStack_a64,local_a88);
    EVP_MD_CTX_free(ctx);
    __s = &local_9a4;
    pbVar3 = abStack_a64;
    for (iVar1 = 0; iVar1 < (int)local_a88[0]; iVar1 = iVar1 + 1) {
      sprintf((char *)__s,__format,(uint)*pbVar3);
      __s = (int *)((int)__s + 2);
      pbVar3 = pbVar3 + 1;
    }
    iVar1 = acosNvramConfig_match(DAT_000988a0,&local_9a4);
    uVar2 = 0;
    if (iVar1 != 0) {
      FUN_00097bd8(local_a88 + 1,*(undefined4 *)(param_1 + 8),0);
      iVar1 = FUN_00097f68(local_a88 + 1,*(undefined4 *)(param_1 + 8));
      if (0 < iVar1) {
        uVar2 = 0;
        *(int *)(param_1 + 0x14) = iVar1;
        goto LAB_0009884c;
      }
      uVar2 = 0x1f7;
    }
  }
  else {
LAB_00098838:
    uVar2 = 0x191;
  }
  FUN_00097bd8(local_a88 + 1,*(undefined4 *)(param_1 + 8),1);
LAB_0009884c:
  FUN_00077240(param_1,&local_824,uVar2,0x20000);
  if (local_24 == *DAT_00098888) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ENTRY 0009b2dc =====
===== FUNCTION FUN_0009b2dc @ 0009b2dc =====

undefined4 FUN_0009b2dc(int param_1)

{
  byte *pbVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 uStack_220;
  undefined1 auStack_21c [252];
  byte abStack_120 [260];
  int iStack_1c;
  
  iStack_1c = *DAT_0009b3c0;
  uStack_220 = 0;
  memset(auStack_21c,0,0xfc);
  abStack_120[0] = 0;
  abStack_120[1] = 0;
  abStack_120[2] = 0;
  abStack_120[3] = 0;
  memset(abStack_120 + 4,0,0xfd);
  iVar2 = FUN_0007461c(*(undefined4 *)(param_1 + 0xc),DAT_0009b3c4,abStack_120,0x100);
  if (iVar2 == 0) {
    sVar3 = strlen((char *)abStack_120);
    iVar2 = 0;
    uVar4 = 0;
    while (iVar2 < (int)sVar3) {
      pbVar1 = abStack_120 + iVar2;
      iVar2 = iVar2 + 1;
      if (*pbVar1 - 0x21 < 0x5e) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x192;
      }
    }
    acosNvramConfig_set(DAT_0009b3c8,abStack_120);
  }
  else {
    uVar4 = 0x192;
  }
  FUN_00077240(param_1,&uStack_220,uVar4,0x20000);
  if (iStack_1c != *DAT_0009b3c0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}


===== ENTRY 0009b3cc =====
===== FUNCTION FUN_0009b3cc @ 0009b3cc =====

undefined4 FUN_0009b3cc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  char acStack_15c [36];
  undefined4 uStack_138;
  undefined1 auStack_134 [32];
  undefined4 uStack_114;
  undefined1 auStack_110 [252];
  int iStack_14;
  
  iStack_14 = *DAT_0009b4d0;
  uStack_114 = 0;
  memset(auStack_110,0,0xfc);
  acStack_15c[0] = '\0';
  acStack_15c[1] = '\0';
  acStack_15c[2] = '\0';
  acStack_15c[3] = '\0';
  memset(acStack_15c + 4,0,0x1d);
  uStack_138 = 0;
  memset(auStack_134,0,0x1d);
  iVar1 = FUN_0007461c(*(undefined4 *)(param_1 + 0xc),DAT_0009b4d4,&uStack_138,0x20);
  if (iVar1 == 0) {
    bVar3 = (char)uStack_138 != '\0';
    if (bVar3) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    if (acStack_15c[0] == '\0') {
      strcpy(acStack_15c,DAT_0009b4d8);
    }
    iVar1 = FUN_00079eec(1,&uStack_138,acStack_15c);
    if (iVar1 != 0 || !bVar3) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0x192;
  }
  FUN_00077240(param_1,&uStack_114,uVar2,0x20000);
  if (iStack_14 == *DAT_0009b4d0) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ENTRY 0009b4dc =====
===== FUNCTION FUN_0009b4dc @ 0009b4dc =====

undefined4 FUN_0009b4dc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined1 uStack_22c;
  undefined1 auStack_22b [23];
  undefined4 uStack_214;
  undefined1 auStack_210 [124];
  char acStack_194 [128];
  undefined4 uStack_114;
  undefined1 auStack_110 [252];
  int iStack_14;
  
  uVar4 = 0;
  iStack_14 = *DAT_0009b640;
  uStack_114 = 0;
  memset(auStack_110,0,0xfc);
  uStack_214 = 0;
  memset(auStack_210,0,0x7c);
  acStack_194[0] = '\0';
  acStack_194[1] = '\0';
  acStack_194[2] = '\0';
  acStack_194[3] = '\0';
  memset(acStack_194 + 4,0,0x7c);
  iVar1 = FUN_0007461c(*(undefined4 *)(param_1 + 0xc),DAT_0009b644,acStack_194,0x7f);
  if (iVar1 == 0) {
    uVar2 = acosNvramConfig_get(DAT_0009b648);
    strlcpy(&uStack_214,uVar2,0x80);
    sVar3 = strlen(acStack_194);
    bVar5 = false;
    if (sVar3 < 0x41) {
      if (acStack_194[0] == '\0') {
        uVar4 = 2;
      }
      else {
        bVar5 = true;
      }
    }
    else {
      uVar4 = 2;
    }
    uStack_234 = *DAT_0009b64c;
    uStack_230 = DAT_0009b64c[1];
    uStack_22c = *(undefined1 *)(DAT_0009b64c + 2);
    memset(auStack_22b,0,0x17);
    if ((char)uStack_214 == '\0') {
      FUN_00079038(&uStack_234,&uStack_214);
    }
    acosNvramConfig_set(DAT_0009b654,DAT_0009b650);
    iVar1 = FUN_00079eec(7,acStack_194,&uStack_214);
    if (iVar1 != 0) {
      bVar5 = false;
    }
    if (!bVar5) {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0x192;
  }
  FUN_00077240(param_1,&uStack_114,uVar4,0x20000);
  if (iStack_14 != *DAT_0009b640) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

