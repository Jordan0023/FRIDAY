
===== TARGET /tmp/AUTH_no_need_auth =====
STRING 000d6514
REF depth=0 from=0002f7f8 to=000d6514
REF depth=0 from=0002f988 to=000d6514
REF depth=0 from=0002f9b0 to=000d6514
REF depth=0 from=0002ffac to=000d6514
REF depth=0 from=0003160c to=000d6514
REF depth=0 from=00031734 to=000d6514
REF depth=0 from=000318cc to=000d6514
REF depth=0 from=00031940 to=000d6514

===== FUNCTION FUN_0002f77c @ 0002f77c =====

void FUN_0002f77c(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  FILE *__stream;
  undefined1 *puVar3;
  int iVar4;
  undefined1 auStack_80c4 [32800];
  undefined1 auStack_a4 [128];
  int local_24;
  
  iVar4 = DAT_0002f9d0 + 0x2f7b4;
  local_24 = **(int **)(DAT_0002f9c8 + 0x2f7a4 + DAT_0002f9cc);
  if ((param_1 != (char *)0x0) &&
     (iVar1 = strncasecmp(param_1,(char *)(DAT_0002f9d4 + 0x2f7d0),6), iVar1 == 0)) {
    if (**(int **)(iVar4 + DAT_0002f9fc) == 1) {
      uVar2 = config_get(DAT_0002fa14 + 0x2f9a0);
    }
    else {
      uVar2 = config_get(DAT_0002fa00 + 0x2f89c);
    }
    iVar4 = FUN_0007cdd4(auStack_a4,param_1 + 6,0x7f);
    auStack_a4[iVar4] = 0;
    iVar4 = FUN_00081e38(auStack_a4,uVar2);
    if (iVar4 == 0) {
      __stream = fopen((char *)(DAT_0002fa08 + 0x2f8f4),(char *)(DAT_0002fa04 + 0x2f8f0));
      if (__stream != (FILE *)0x0) {
        fread(auStack_80c4,100,0x148,__stream);
        puVar3 = auStack_80c4;
        do {
          puVar3[0x1f] = 0;
          iVar4 = FUN_00081dc4(puVar3,param_2);
          if (iVar4 == 0) {
            FUN_00081d94(puVar3,DAT_0002fa0c + 0x2f95c,0x20);
            rewind(__stream);
            fwrite(auStack_80c4,100,0x148,__stream);
            fclose(__stream);
            FUN_0003c2dc(DAT_0002fa10 + 0x2f990,0);
            goto LAB_0002f848;
          }
          puVar3 = puVar3 + 100;
        } while (puVar3 != auStack_a4);
        FUN_0003c2dc(DAT_0002fa18 + 0x2f9b8,0);
        fclose(__stream);
      }
      goto LAB_0002f848;
    }
  }
  iVar4 = DAT_0002f9d8 + 0x2f7e8;
  FUN_0003ba7c(iVar4,DAT_0002f9dc + 0x2f7ec);
  FUN_0003c2dc(DAT_0002f9e0 + 0x2f800,0);
  FUN_0003ba7c(iVar4,DAT_0002f9e4 + 0x2f810);
  FUN_0003ba7c(iVar4,DAT_0002f9e8 + 0x2f820);
  FUN_0003ba7c(iVar4,DAT_0002f9ec + 0x2f830);
  system((char *)(DAT_0002f9f0 + 0x2f83c));
  system((char *)(DAT_0002f9f4 + 0x2f848));
LAB_0002f848:
  if (local_24 == **(int **)(DAT_0002f9f8 + 0x2f860 + DAT_0002f9cc)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== FUNCTION FUN_0002ff9c @ 0002ff9c =====

undefined4 FUN_0002ff9c(char *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  in_addr_t iVar3;
  in_addr_t iVar4;
  int iVar5;
  size_t __n;
  char *pcVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined1 auStack_26c [32];
  undefined1 auStack_24c [32];
  sysinfo local_22c;
  char acStack_1ec [64];
  char acStack_1ac [64];
  char acStack_16c [64];
  char acStack_12c [128];
  char acStack_ac [128];
  int local_2c;
  
  iVar8 = FUN_0003c2b8(DAT_0002ffd4 + 0x2ffb4);
  if (iVar8 != 1) {
    return 0;
  }
  iVar8 = DAT_0002ff2c + 0x2fa4c;
  local_2c = **(int **)(DAT_0002ff24 + 0x2fa40 + DAT_0002ff28);
  if ((param_2 == (char *)0x0) ||
     (iVar1 = strncasecmp(param_2,(char *)(DAT_0002ff30 + 0x2fa6c),6), iVar1 != 0)) {
LAB_0002fa74:
    iVar1 = DAT_0002ff38;
    uVar2 = FUN_0003b998(DAT_0002ff34 + 0x2fa94);
    FUN_00081d94(auStack_26c,uVar2,0x20);
    uVar2 = FUN_0003b998(DAT_0002ff3c + 0x2fab8);
    FUN_00081d94(auStack_24c,uVar2,0x20);
    uVar2 = FUN_0003b998(DAT_0002ff40 + 0x2fad4);
    FUN_00081d94(acStack_1ac,uVar2,0x40);
    uVar2 = config_get(DAT_0002ff44 + 0x2faf0);
    FUN_00081d94(acStack_1ec,uVar2,0x40);
    uVar2 = config_get(DAT_0002ff48 + 0x2fb0c);
    FUN_00081d94(acStack_16c,uVar2,0x40);
    iVar3 = inet_addr(acStack_16c);
    iVar4 = inet_addr(acStack_1ec);
    uVar11 = iVar3 & iVar4;
    iVar3 = inet_addr(acStack_1ac);
    iVar4 = inet_addr(acStack_1ec);
    uVar9 = iVar3 & iVar4;
    iVar3 = inet_addr(param_1);
    iVar4 = inet_addr(acStack_1ec);
    uVar10 = iVar3 & iVar4;
    iVar5 = FUN_00081e38(param_1,iVar1 + 0x2faac);
    if ((iVar5 == 0) && (iVar1 = FUN_00081e38(acStack_1ac,iVar1 + 0x2faac), iVar1 == 0)) {
      if (uVar11 == uVar9 && uVar11 == uVar10) {
LAB_0002fbcc:
        uVar2 = *(undefined4 *)(iVar8 + DAT_0002ff50);
        uVar12 = *(undefined4 *)(iVar8 + DAT_0002ff54);
        iVar1 = DAT_0002ff58 + 0x2fc04;
        FUN_00036254(DAT_0002ff60 + 0x2fc18,DAT_0002ff5c + 0x2fc14,0,0,1,param_1,uVar12,uVar2,
                     acStack_1ac,auStack_26c,auStack_24c);
        iVar8 = FUN_00081dc4(auStack_26c,iVar1);
        if ((((iVar8 == 0) || (iVar8 = FUN_00081dc4(uVar12,auStack_26c), iVar8 == 0)) ||
            (iVar8 = FUN_00081dc4(auStack_24c,iVar1), iVar8 == 0)) ||
           (iVar8 = FUN_00081dc4(uVar2,auStack_24c), iVar8 != 0)) goto LAB_0002fc2c;
        sysinfo(&local_22c);
        iVar8 = DAT_0002ff94 + 0x2fed0;
      }
      else {
        if (uVar11 == uVar9 || uVar11 == uVar10) goto LAB_0002fc68;
        uVar2 = *(undefined4 *)(iVar8 + DAT_0002ff50);
        iVar1 = DAT_0002ff78 + 0x2fd8c;
        FUN_00036254(DAT_0002ff7c + 0x2fd90,DAT_0002ff80 + 0x2fda0,0,1,0,param_1,
                     *(undefined4 *)(iVar8 + DAT_0002ff54),uVar2,acStack_1ac,auStack_26c,auStack_24c
                    );
        iVar8 = FUN_00081dc4(param_1,iVar1);
        if (((iVar8 == 0) || (iVar8 = FUN_00081dc4(acStack_1ac,param_1), iVar8 == 0)) ||
           ((iVar8 = FUN_00081dc4(uVar2,auStack_24c), iVar8 != 0 ||
            (iVar8 = FUN_00081dc4(acStack_1ac,iVar1), iVar8 == 0)))) goto LAB_0002fc2c;
        sysinfo(&local_22c);
        iVar8 = DAT_0002ff84 + 0x2fe04;
      }
LAB_0002fecc:
      pcVar6 = (char *)FUN_0003b998(iVar8);
      lVar7 = strtol(pcVar6,(char **)0x0,10);
      if (local_22c.uptime - lVar7 < 0x12d) {
        uVar2 = 1;
        goto LAB_0002fc30;
      }
      FUN_0002f77c(param_2,param_1);
    }
    else {
      iVar5 = DAT_0002ff4c + 0x2fbac;
      iVar1 = FUN_00081e38(param_1,iVar5);
      if (((iVar1 != 0) && (iVar1 = FUN_00081e38(acStack_1ac,iVar5), iVar1 != 0)) ||
         (uVar11 == uVar9 || uVar11 == uVar10)) goto LAB_0002fbcc;
LAB_0002fc68:
      uVar2 = *(undefined4 *)(iVar8 + DAT_0002ff50);
      iVar1 = DAT_0002ff68 + 0x2fca0;
      FUN_00036254(DAT_0002ff70 + 0x2fcbc,DAT_0002ff6c + 0x2fcb4,1,0,0,param_1,
                   *(undefined4 *)(iVar8 + DAT_0002ff54),uVar2,acStack_1ac,auStack_26c,auStack_24c);
      iVar8 = FUN_00081dc4(param_1,iVar1);
      if (((iVar8 != 0) && (iVar8 = FUN_00081dc4(acStack_1ac,param_1), iVar8 != 0)) &&
         ((iVar8 = FUN_00081dc4(uVar2,auStack_24c), iVar8 != 0 &&
          (iVar8 = FUN_00081dc4(acStack_1ac,iVar1), iVar8 != 0)))) {
        sysinfo(&local_22c);
        iVar8 = DAT_0002ff74 + 0x2fd20;
        goto LAB_0002fecc;
      }
    }
  }
  else {
    __n = FUN_0007cdd4(acStack_12c,param_2 + 6,0x7f);
    acStack_12c[__n] = '\0';
    iVar1 = config_match(DAT_0002ff8c + 0x2fe40,DAT_0002ff88 + 0x2fe38);
    if (iVar1 == 0) goto LAB_0002fa74;
    pcVar6 = (char *)config_get(DAT_0002ff90 + 0x2fe58);
    if (*pcVar6 != '\0') {
      __n = FUN_00081d48(acStack_ac,0x80,DAT_0002ff98 + 0x2ff18,pcVar6);
    }
    iVar1 = strncmp(acStack_ac,acStack_12c,__n);
    if (iVar1 != 0) goto LAB_0002fa74;
  }
LAB_0002fc2c:
  uVar2 = 0;
LAB_0002fc30:
  if (local_2c != **(int **)(DAT_0002ff64 + 0x2fc40 + DAT_0002ff28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return uVar2;
}


===== FUNCTION FUN_00031390 @ 00031390 =====

int FUN_00031390(int param_1,int param_2,int param_3,char *param_4,undefined4 param_5)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_ac [32];
  undefined1 auStack_8c [32];
  char acStack_6c [64];
  int local_2c;
  
  iVar4 = DAT_00031bec;
  local_2c = **(int **)(DAT_00031be4 + 0x313ac + DAT_00031be8);
  FUN_0003bf0c(param_3,auStack_ac,auStack_8c,0);
  iVar4 = iVar4 + 0x313f0;
  iVar1 = config_invmatch(DAT_00031bf4 + 0x313f8,DAT_00031bf0 + 0x313f4);
  if (iVar1 != 0) {
    iVar1 = 1;
    FUN_00036254(DAT_00031c70 + 0x316d0,DAT_00031c6c + 0x316c4,DAT_00031c68 + 0x31800,0x3a7,
                 **(undefined4 **)(iVar4 + DAT_00031c48));
    goto LAB_0003143c;
  }
  if (param_3 == 0 || (param_1 == 0 || param_2 == 0)) {
    iVar1 = 2;
    FUN_00036254(DAT_00031c60 + 0x31688,DAT_00031c5c + 0x31684,DAT_00031c58 + 0x317b8,0x3ad,param_1,
                 param_2,param_3);
    system((char *)(DAT_00031c64 + 0x31698));
    goto LAB_0003143c;
  }
  iVar1 = FUN_00081dc4(param_3,DAT_00031bf8 + 0x31430);
  if (iVar1 != 0) {
    pcVar2 = getenv((char *)(DAT_00031c00 + 0x31474));
    iVar1 = FUN_00081dc4(pcVar2,DAT_00031c04 + 0x31480);
    if ((iVar1 == 0) &&
       ((((iVar1 = FUN_00081e38(param_1,DAT_00031c74 + 0x316e8), iVar1 != 0 ||
          (iVar1 = FUN_00081e38(param_1,DAT_00031c98 + 0x317fc), iVar1 != 0)) ||
         (iVar1 = FUN_00081e38(param_1,DAT_00031c9c + 0x31814), iVar1 != 0)) ||
        (((iVar1 = FUN_00081e38(param_1,DAT_00031ca0 + 0x3182c), iVar1 != 0 ||
          (iVar1 = FUN_00081e38(param_1,DAT_00031ca4 + 0x31844), iVar1 != 0)) ||
         (iVar1 = FUN_00081e38(param_1,DAT_00031ca8 + 0x3185c), iVar1 != 0)))))) {
      iVar1 = 1;
      FUN_00036254(DAT_00031c80 + 0x31724,DAT_00031c7c + 0x31718,DAT_00031c78 + 0x31854,0x3bf,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      goto LAB_0003143c;
    }
    iVar1 = config_match(DAT_00031c0c + 0x3149c,DAT_00031c08 + 0x31498);
    if (((iVar1 != 0) && (iVar1 = FUN_00081e38(param_2,DAT_00031c10 + 0x314b4), iVar1 == 0)) &&
       ((iVar1 = FUN_00081e38(param_2,DAT_00031cf8 + 0x31a18), iVar1 == 0 &&
        (iVar1 = FUN_00022138(param_2), iVar1 == 1)))) {
      FUN_00036254(DAT_00031d04 + 0x31a64,DAT_00031d00 + 0x31a58,DAT_00031cfc + 0x31b94,0x3ca,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      iVar1 = 1;
      goto LAB_0003143c;
    }
    FUN_00081d48(acStack_6c,0x40,DAT_00031c14 + 0x314d4);
    if (((param_4 == (char *)0x0) ||
        (iVar1 = strncasecmp(param_4,(char *)(DAT_00031c18 + 0x314f0),6), iVar1 != 0)) ||
       ((iVar1 = FUN_0002e5c4(DAT_00031c1c + 0x31508,auStack_ac), iVar1 == 0 &&
        ((iVar1 = FUN_0002e5c4(DAT_00031c20 + 0x31520,auStack_ac), iVar1 == 0 &&
         (iVar1 = FUN_0002e5c4(DAT_00031c24 + 0x31538,auStack_ac), iVar1 == 0)))))) {
      FUN_00036254(DAT_00031cb4 + 0x31898,DAT_00031cb0 + 0x3188c,DAT_00031cac + 0x319c8,0x3d3,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      iVar4 = access(acStack_6c,0);
      if (iVar4 != 0) {
LAB_000319b8:
        FUN_00031160(DAT_00031ce8 + 0x319c8,auStack_ac);
      }
LAB_000318b0:
      iVar1 = 2;
      goto LAB_0003143c;
    }
    iVar1 = FUN_0002ff9c(param_3,param_4);
    if (iVar1 != 0) {
      iVar1 = FUN_00081e38(param_1,DAT_00031c28 + 0x31564);
      if (iVar1 == 0) {
        iVar1 = 3;
        FUN_00036254(DAT_00031d20 + 0x31afc,DAT_00031d1c + 0x31af0,(int)&DAT_00031c2c + DAT_00031d18
                     ,0x3fa,**(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
      iVar1 = FUN_0002e5c4(DAT_00031c2c + 0x3157c,auStack_ac);
      if (iVar1 != 0) {
        iVar3 = DAT_00031c30 + 0x31590;
        iVar1 = FUN_0003c2b8(iVar3);
        if (iVar1 != 1) {
          FUN_0003c2dc(iVar3,1);
          iVar1 = 5;
          FUN_00036254(DAT_00031d2c + 0x31b44,DAT_00031d28 + 0x31b38,
                       (int)&DAT_00031c74 + DAT_00031d24,0x3e5,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
          system((char *)(DAT_00031d30 + 0x31b54));
          goto LAB_0003143c;
        }
      }
      iVar1 = FUN_0002e5c4(DAT_00031c34 + 0x315ac,auStack_ac);
      if ((iVar1 != 0) && (iVar1 = FUN_00030004(param_4,param_3,param_5), iVar1 != 0)) {
        FUN_0002f77c(param_4,param_3);
        FUN_0002e8c8(param_3,param_4);
        iVar1 = 1;
        FUN_00031160(DAT_00031c38 + 0x315f8,auStack_ac);
        unlink((char *)(DAT_00031c3c + 0x31604));
        FUN_0003c2dc(DAT_00031c40 + 0x31614,1);
        FUN_0003c2dc(DAT_00031c44 + 0x31624,0);
        FUN_00036254(DAT_00031c54 + 0x31654,DAT_00031c50 + 0x31648,DAT_00031c4c + 0x31784,0x3f3,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
    }
    iVar5 = DAT_00031c84 + 0x31738;
    iVar1 = FUN_0003c2b8(iVar5);
    iVar3 = FUN_00030004(param_4,param_3,param_5);
    if (iVar3 != 1 || iVar1 != 1) {
      FUN_0002f6d4(param_3,param_4);
      if (iVar1 == 1) {
        FUN_0002e53c(param_3);
      }
      else {
        FUN_0003c2dc(iVar5,1);
      }
      iVar6 = DAT_00031cb8 + 0x318e8;
      iVar5 = config_invmatch(iVar6,DAT_00031cbc + 0x318ec);
      if (iVar5 != 0) {
        config_set(iVar6,DAT_00031d08 + 0x31a7c);
      }
      config_set(DAT_00031cc4 + 0x3190c,DAT_00031cc0 + 0x31908);
      system((char *)(DAT_00031cc8 + 0x31918));
      iVar5 = FUN_0002e5c4(DAT_00031ccc + 0x31928,auStack_ac);
      if (((iVar5 == 0) && (iVar5 = FUN_0002e5c4(DAT_00031cd4 + 0x3195c,auStack_ac), iVar5 == 0)) &&
         (iVar5 = FUN_0002e5c4(DAT_00031cd8 + 0x31974,auStack_ac), iVar5 == 0)) {
        FUN_00036254(DAT_00031ce4 + 0x319ac,DAT_00031ce0 + 0x319a0,DAT_00031cdc + 0x31adc,0x41c,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
        if (iVar1 == 1) goto LAB_000319b8;
        goto LAB_000318b0;
      }
      if (iVar3 != 1) {
        iVar1 = 5;
        FUN_00036254(DAT_00031d14 + 0x31ac0,DAT_00031d10 + 0x31ab4,(int)&DAT_00031bf0 + DAT_00031d0c
                     ,0x426,**(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
      FUN_0003c2dc(DAT_00031cd0 + 0x31948,1);
    }
    iVar1 = FUN_0002e8c8(param_3,param_4);
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        FUN_00036254(DAT_00031d48 + 0x31bc0,DAT_00031d44 + 0x31bb4,(int)&DAT_00031cf0 + DAT_00031d40
                     ,0x431,**(undefined4 **)(iVar4 + DAT_00031c48));
        system((char *)(DAT_00031d4c + 0x31bd0));
        system((char *)(DAT_00031d50 + 0x31bdc));
      }
      else if (iVar1 == 4) {
        iVar3 = FUN_00081e38(param_1,DAT_00031c88 + 0x3179c);
        if (iVar3 == 0) {
          FUN_00036254(DAT_00031d3c + 0x31b88,DAT_00031d38 + 0x31b7c,
                       (int)&DAT_00031cb8 + DAT_00031d34,0x442,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
        }
        else {
          FUN_0002f77c(param_4,param_3);
          iVar1 = 1;
          FUN_00036254(DAT_00031c94 + 0x317e4,DAT_00031c90 + 0x317d8,DAT_00031c8c + 0x31914,0x43d,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
        }
      }
      else {
        iVar1 = 1;
        FUN_00036254(DAT_00031cf4 + 0x31a00,DAT_00031cf0 + 0x319f4,DAT_00031cec + 0x31b30,0x449,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
      }
      goto LAB_0003143c;
    }
  }
  iVar1 = 1;
LAB_0003143c:
  if (local_2c == **(int **)(DAT_00031bfc + 0x3144c + DAT_00031be8)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== TARGET /tmp/AUTH_nullpass =====
STRING 000d64ac
REF depth=0 from=0002e248 to=000d64ac
REF depth=0 from=0002e290 to=000d64ac
REF depth=0 from=00030384 to=000d64ac
REF depth=0 from=00030754 to=000d64ac

===== FUNCTION FUN_0002e23c @ 0002e23c =====

void FUN_0002e23c(void)

{
  char *pcVar1;
  
  FUN_0003c2dc(DAT_0002e2a8 + 0x2e250,0);
  if (**(int **)(DAT_0002e2ac + 0x2e260 + DAT_0002e2b0) == 1) {
    pcVar1 = (char *)config_get(DAT_0002e2bc + 0x2e2a4);
  }
  else {
    pcVar1 = (char *)config_get(DAT_0002e2b4 + 0x2e278);
  }
  if (*pcVar1 != '\0') {
    return;
  }
  FUN_0003c2dc(DAT_0002e2b8 + 0x2e298,1);
  return;
}


===== FUNCTION FUN_00030004 @ 00030004 =====

undefined4 FUN_00030004(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined1 auStack_2ec [64];
  char acStack_2ac [64];
  char acStack_26c [64];
  undefined1 auStack_22c [128];
  undefined1 auStack_1ac [128];
  undefined1 auStack_12c [128];
  undefined1 auStack_ac [128];
  int local_2c;
  
  iVar6 = DAT_000303c4 + 0x30038;
  local_2c = **(int **)(DAT_000303bc + 0x30020 + DAT_000303c0);
  iVar4 = DAT_000303cc + 0x3005c;
  uVar5 = *(undefined4 *)(iVar6 + DAT_000303d0);
  FUN_00081d48(auStack_2ec,0x40,DAT_000303c8 + 0x30058,uVar5);
  FUN_00081d48(acStack_2ac,0x40,iVar4,DAT_000303d4 + 0x30080,uVar5);
  FUN_00081d48(acStack_26c,0x40,iVar4,DAT_000303d8 + 0x3009c,uVar5);
  if ((param_1 == (char *)0x0) ||
     (iVar4 = strncasecmp(param_1,(char *)(DAT_000303dc + 0x300b8),6), iVar4 != 0)) {
    uVar5 = 0;
    FUN_0003ba7c(DAT_000303e4 + 0x300d8,DAT_000303e0 + 0x300d4);
    FUN_00036254(DAT_000303f0 + 0x30108,DAT_000303f4 + 0x3010c,DAT_000303ec + 0x3010c,0x2f0,
                 **(undefined4 **)(iVar6 + DAT_000303e8),param_1);
    goto LAB_00030110;
  }
  iVar4 = FUN_0007cdd4(auStack_22c,param_1 + 6,0x7f);
  auStack_22c[iVar4] = 0;
  piVar7 = *(int **)(iVar6 + DAT_000303fc);
  if (*piVar7 == 1) {
    pcVar1 = (char *)config_get(DAT_00030440 + 0x30374);
  }
  else {
    pcVar1 = (char *)config_get(DAT_00030400 + 0x3017c);
  }
  uVar5 = 0;
  if (*pcVar1 == '\0') goto LAB_00030110;
  iVar4 = FUN_00081e38(auStack_22c,pcVar1);
  if (iVar4 == 0) {
    config_get(DAT_00030424 + 0x302c4);
    iVar4 = FUN_00081e68();
    if ((iVar4 != 1) || (pcVar1 = (char *)config_get(DAT_00030428 + 0x302e0), *pcVar1 == '\0'))
    goto LAB_00030110;
    iVar4 = FUN_00081d48(auStack_1ac,0x80,DAT_0003042c + 0x30308,pcVar1);
    pcVar1 = (char *)config_get(DAT_00030430 + 0x30318);
    if (*pcVar1 == '\0') goto LAB_0003038c;
    FUN_00081d48(auStack_1ac + iVar4,0x80 - iVar4,DAT_00030434 + 0x3033c,pcVar1);
    iVar4 = FUN_00081dc4(auStack_1ac,auStack_22c);
    if (iVar4 != 0) goto LAB_00030110;
    iVar6 = DAT_00030438 + 0x30364;
    iVar4 = DAT_0003043c + 0x30368;
  }
  else {
    iVar4 = FUN_00081d48(auStack_1ac,0x80,DAT_00030404 + 0x301bc,pcVar1);
    if (*piVar7 == 1) {
      pcVar1 = (char *)config_get(DAT_00030448 + 0x303b0);
    }
    else {
      pcVar1 = (char *)config_get(DAT_00030408 + 0x301d8);
    }
    if (*pcVar1 == '\0') {
      FUN_0003c2dc(DAT_00030444 + 0x3038c,1);
LAB_0003038c:
      uVar5 = 1;
      unlink(acStack_2ac);
      unlink(acStack_26c);
      goto LAB_00030110;
    }
    iVar6 = FUN_00081e38(auStack_22c,auStack_1ac);
    if (iVar6 == 0) goto LAB_00030110;
    FUN_00081d94(auStack_ac,pcVar1,0x80);
    uVar2 = FUN_00082330(iVar6 + iVar4);
    FUN_00081d94(auStack_12c,uVar2,0x80);
    iVar3 = FUN_00081dc4(auStack_12c,auStack_ac);
    FUN_00036254(DAT_00030410 + 0x30260,DAT_0003040c + 0x3025c,iVar6 + iVar4,auStack_12c,iVar3 == 0)
    ;
    iVar4 = FUN_00081dc4(auStack_12c,auStack_ac);
    if (iVar4 != 0) goto LAB_00030110;
    FUN_0003ba7c(DAT_00030418 + 0x30290,DAT_00030414 + 0x3028c);
    iVar6 = DAT_0003041c + 0x302a0;
    iVar4 = DAT_00030420 + 0x302a4;
  }
  uVar5 = 1;
  config_set(iVar4,iVar6);
  unlink(acStack_2ac);
  unlink(acStack_26c);
LAB_00030110:
  if (local_2c == **(int **)(DAT_000303f8 + 0x30120 + DAT_000303c0)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== FUNCTION FUN_00030480 @ 00030480 =====

bool FUN_00030480(char *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  undefined1 auStack_264 [64];
  undefined1 auStack_224 [128];
  undefined1 auStack_1a4 [128];
  undefined1 auStack_124 [128];
  undefined1 auStack_a4 [128];
  int local_24;
  
  iVar6 = DAT_0003076c + 0x304b4;
  local_24 = **(int **)(DAT_00030764 + 0x3049c + DAT_00030768);
  FUN_00081d48(auStack_264,0x40,DAT_00030770 + 0x304c8,*(undefined4 *)(iVar6 + DAT_00030774));
  if ((param_1 == (char *)0x0) ||
     (iVar1 = strncasecmp(param_1,(char *)(DAT_00030778 + 0x304e8),6), iVar1 != 0)) {
    bVar5 = false;
    FUN_0003ba7c(DAT_00030780 + 0x30508,DAT_0003077c + 0x30504);
    FUN_00036254(DAT_0003078c + 0x30538,DAT_00030790 + 0x3053c,DAT_00030788 + 0x3054c,0x363,
                 **(undefined4 **)(iVar6 + DAT_00030784),param_1);
  }
  else {
    iVar6 = FUN_0007cdd4(auStack_224,param_1 + 6,0x7f);
    auStack_224[iVar6] = 0;
    pcVar2 = (char *)config_get(DAT_00030798 + 0x30598);
    bVar5 = false;
    if (*pcVar2 != '\0') {
      iVar6 = FUN_00081e38(auStack_224,pcVar2);
      if (iVar6 == 0) {
        config_get(DAT_000307b4 + 0x306b4);
        iVar6 = FUN_00081e68();
        if ((iVar6 == 1) && (pcVar2 = (char *)config_get(DAT_000307b8 + 0x306d0), *pcVar2 != '\0'))
        {
          iVar6 = FUN_00081d48(auStack_1a4,0x80,DAT_000307bc + 0x306f8,pcVar2);
          pcVar2 = (char *)config_get(DAT_000307c0 + 0x30708);
          if (*pcVar2 == '\0') {
            bVar5 = true;
          }
          else {
            FUN_00081d48(auStack_1a4 + iVar6,0x80 - iVar6,DAT_000307c4 + 0x30730,pcVar2);
            iVar6 = FUN_00081dc4(auStack_1a4,auStack_224);
            bVar5 = iVar6 == 0;
          }
        }
      }
      else {
        iVar6 = FUN_00081d48(auStack_1a4,0x80,DAT_0003079c + 0x305dc,pcVar2);
        pcVar2 = (char *)config_get(DAT_000307a0 + 0x305ec);
        if (*pcVar2 == '\0') {
          bVar5 = true;
          FUN_0003c2dc(DAT_000307c8 + 0x3075c,1);
        }
        else {
          iVar1 = FUN_00081e38(auStack_224,auStack_1a4);
          if (iVar1 != 0) {
            FUN_00081d94(auStack_a4,pcVar2,0x80);
            uVar3 = FUN_00082330(iVar1 + iVar6);
            FUN_00081d94(auStack_124,uVar3,0x80);
            iVar4 = FUN_00081dc4(auStack_124,auStack_a4);
            FUN_00036254(DAT_000307a8 + 0x30674,DAT_000307a4 + 0x30670,iVar1 + iVar6,auStack_124,
                         iVar4 == 0);
            iVar6 = FUN_00081dc4(auStack_124,auStack_a4);
            if (iVar6 == 0) {
              bVar5 = true;
              FUN_0003ba7c(DAT_000307b0 + 0x306a4,DAT_000307ac + 0x306a0);
            }
          }
        }
      }
    }
  }
  if (local_24 != **(int **)(DAT_00030794 + 0x30550 + DAT_00030768)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar5;
}


===== TARGET /tmp/AUTH_token_unauth =====
STRING 000cd5e0
REF depth=0 from=000201f4 to=000cd5e0
REF depth=0 from=00031228 to=000cd5e0
REF depth=0 from=00025004 to=000cd5e0
REF depth=0 from=000314cc to=000cd5e0
REF depth=0 from=000315fc to=000cd5e0
REF depth=0 from=0002e650 to=000cd5e0

===== FUNCTION FUN_00020030 @ 00020030 =====

void FUN_00020030(FILE *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 auStack_758 [4];
  undefined1 auStack_754 [8];
  undefined1 auStack_74c [32];
  undefined1 auStack_72c [32];
  undefined1 auStack_70c [32];
  undefined1 auStack_6ec [64];
  undefined1 auStack_6ac [64];
  char acStack_66c [64];
  undefined4 local_62c;
  undefined1 auStack_628 [508];
  undefined4 local_42c;
  undefined1 auStack_428 [1020];
  int local_2c;
  
  local_2c = **(int **)(DAT_00020544 + 0x20050 + DAT_00020548);
  local_42c = 0;
  memset(auStack_428,0,0x3fc);
  iVar5 = DAT_0002054c;
  local_62c = 0;
  memset(auStack_628,0,0x1fc);
  iVar1 = FUN_0003c330();
  iVar5 = iVar5 + 0x200bc;
  uVar2 = FUN_0008322c();
  FUN_0003bf0c(uVar2,auStack_74c,auStack_72c);
  uVar7 = *(undefined4 *)(iVar5 + DAT_00020550);
  iVar6 = DAT_00020554 + 0x200e8;
  uVar2 = uVar7;
  FUN_00081d48(acStack_66c,0x40,iVar6,DAT_00020558 + 0x200f0,uVar7);
  iVar3 = access(acStack_66c,0);
  if (iVar3 == 0) {
    uVar2 = FUN_0003b998(acStack_66c);
    FUN_00081d94(auStack_754,uVar2,8);
    iVar4 = DAT_000205e0 + 0x2042c;
    iVar3 = FUN_00081e68(auStack_754);
    iVar3 = iVar3 + 1;
    FUN_00081d48(auStack_754,8,iVar4,iVar3);
    if (iVar3 * -0x55555555 + 0x2aaaaaaaU < 0x55555555) {
      uVar2 = uVar7;
      FUN_00081d48(auStack_6ac,0x40,iVar6,DAT_000205e4 + 0x20498,uVar7);
      if (iVar3 == 6) {
        FUN_00081d48(auStack_70c,0x20,iVar4,iVar1 + 0x3c,uVar2);
      }
      else if (6 < iVar3) {
        FUN_00081d48(auStack_70c,0x20,iVar4,iVar1 + 300,uVar2);
      }
      FUN_0003ba7c(auStack_70c,auStack_6ac);
    }
  }
  else {
    FUN_00081d48(auStack_754,8,DAT_0002055c + 0x20128,1,uVar2);
  }
  uVar2 = FUN_00031d54(0,uVar7);
  FUN_00081d94(&local_62c,uVar2,0x200);
  FUN_00036254(DAT_0002056c + 0x2017c,DAT_00020568 + 0x20170,DAT_00020564 + 0x201c8,0xc0,
               **(undefined4 **)(iVar5 + DAT_00020560));
  iVar1 = FUN_00081dc4(param_2,DAT_00020570 + 0x20190);
  if (iVar1 != 0) {
    iVar1 = FUN_00081dc4(param_2,DAT_00020574 + 0x201a8);
    if (iVar1 == 0) {
      FUN_00081d48(auStack_6ec,0x40,DAT_00020578 + 0x201c8);
      goto LAB_000201fc;
    }
    iVar1 = FUN_00081dc4(param_2,DAT_0002057c + 0x201dc);
    if (iVar1 == 0) {
      FUN_00081d48(auStack_6ec,0x40,DAT_000205f0 + 0x20504,auStack_74c);
      goto LAB_000201fc;
    }
  }
  FUN_00081d48(auStack_6ec,0x40,DAT_00020580 + 0x201fc);
LAB_000201fc:
  uVar2 = FUN_0003b998(auStack_6ec);
  FUN_00081d94(&local_62c,uVar2,0x200);
  iVar1 = FUN_00081dc4(param_2,DAT_00020584 + 0x20224);
  if (iVar1 == 0) {
    FUN_00081d48(&local_42c,0x400,DAT_0002058c + 0x2024c,*(undefined4 *)(iVar5 + DAT_00020588));
  }
  else {
    FUN_00081d48(&local_42c,0x400,DAT_000205c0 + 0x20380,&local_62c,
                 *(undefined4 *)(iVar5 + DAT_00020588));
  }
  iVar1 = DAT_00020590 + 0x20258;
  uVar2 = FUN_0003b998(iVar1);
  uVar7 = *(undefined4 *)(iVar5 + DAT_00020594);
  iVar5 = FUN_00081e20(uVar2,uVar7);
  if (iVar5 != 0) {
    FUN_0003ba7c(uVar7,iVar1);
    FUN_0003ba7c(DAT_000205ec + 0x204d4,DAT_000205e8 + 0x204d0);
  }
  iVar1 = DAT_00020598 + 0x20284;
  uVar2 = FUN_0003b998(iVar1);
  FUN_00081d94(auStack_758,uVar2,4);
  iVar5 = FUN_00081dc4(auStack_758,DAT_0002059c + 0x202a8);
  if (iVar5 == 0) {
    FUN_0003ba7c(DAT_000205a0 + 0x202c0,iVar1);
    FUN_0003ba7c(auStack_754,acStack_66c);
    config_set(DAT_000205a8 + 0x202e0,DAT_000205a4 + 0x202dc);
    FUN_0001fbbc(param_1,200,DAT_000205b0 + 0x20300,0,DAT_000205ac + 0x202fc);
  }
  else {
    iVar5 = FUN_00081dc4(auStack_758,DAT_000205c4 + 0x20398);
    if (iVar5 != 0) {
      FUN_0003ba7c(auStack_754,acStack_66c);
    }
    FUN_00081dac(auStack_758,DAT_000205c8 + 0x203b4,4);
    config_set(DAT_000205d0 + 0x203c8,DAT_000205cc + 0x203c4);
    FUN_0003ba7c(auStack_758,DAT_000205d4 + 0x203d8);
    FUN_0001fbbc(param_1,0x191,DAT_000205dc + 0x203f8,&local_42c,DAT_000205d8 + 0x203f4);
  }
  fwrite((void *)(DAT_000205b4 + 0x2031c),1,0x18a,param_1);
  fflush(param_1);
  unlink((char *)(DAT_000205b8 + 0x20330));
  if (local_2c == **(int **)(DAT_000205bc + 0x20340 + DAT_00020548)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== FUNCTION FUN_00031160 @ 00031160 =====

void FUN_00031160(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_324 [64];
  sysinfo local_2e4;
  undefined1 auStack_2a4 [128];
  undefined4 local_224;
  undefined1 auStack_220 [508];
  int local_24;
  
  local_24 = **(int **)(DAT_00031350 + 0x31178 + DAT_00031354);
  uVar1 = FUN_0003c330();
  pcVar2 = getenv((char *)(DAT_00031358 + 0x311a8));
  local_224 = 0;
  memset(auStack_220,0,0x1fc);
  sysinfo(&local_2e4);
  FUN_00081d48(auStack_2a4,0x80,DAT_0003135c + 0x311e0,local_2e4.uptime);
  uVar3 = FUN_00030f60(pcVar2,uVar1,param_2);
  FUN_00081d94(&local_224,uVar3,0x200);
  iVar4 = FUN_00081dc4(param_1,DAT_00031360 + 0x31210);
  if (iVar4 == 0) {
    FUN_00081d48(auStack_324,0x40,DAT_00031364 + 0x31230);
  }
  else {
    iVar4 = FUN_00081dc4(param_1,DAT_0003137c + 0x312c0);
    if (iVar4 == 0) {
      FUN_00081d48(auStack_324,0x40,DAT_00031380 + 0x312e0);
    }
    else {
      iVar4 = FUN_00081dc4(param_1,DAT_00031388 + 0x31328);
      if (iVar4 == 0) {
        FUN_00081d48(auStack_324,0x40,DAT_0003138c + 0x31348,param_2);
      }
    }
  }
  iVar4 = FUN_00081dc4(param_1,DAT_00031368 + 0x31240);
  if (iVar4 == 0) {
    uVar1 = FUN_00030f60(pcVar2,uVar1,param_2);
    FUN_00081d48(&local_224,0x200,DAT_00031384 + 0x31310,uVar1,auStack_2a4);
  }
  FUN_0003ba7c(&local_224,auStack_324);
  FUN_00036254(DAT_00031374 + 0x31288,DAT_00031370 + 0x31284,DAT_0003136c + 0x313a4,param_1,
               &local_224,DAT_0003136c + 0x313a4,0x167);
  if (local_24 == **(int **)(DAT_00031378 + 0x31298 + DAT_00031354)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== FUNCTION FUN_0002287c @ 0002287c =====

void FUN_0002287c(char *param_1,char *param_2,undefined4 param_3,FILE *param_4,FILE *param_5)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  char *pcVar9;
  time_t tVar10;
  time_t tVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined4 uVar14;
  __pid_t _Var15;
  long lVar16;
  int *piVar17;
  ulong *__s;
  char *pcVar18;
  char cVar19;
  code *pcVar20;
  sysinfo *psVar21;
  char *pcVar22;
  undefined4 uVar23;
  undefined1 *puVar24;
  int *piVar25;
  int iVar26;
  byte *pbVar27;
  int *piVar28;
  bool bVar29;
  char *local_15d8;
  int local_15c4;
  undefined4 local_15c0;
  char *local_15bc;
  char *local_15b4;
  char *local_15b0;
  undefined4 uStack_1598;
  undefined4 uStack_1594;
  undefined4 uStack_1590;
  undefined4 uStack_158c;
  stat sStack_1588;
  undefined1 auStack_152c [32];
  undefined1 auStack_150c [32];
  undefined1 auStack_14ec [32];
  undefined1 auStack_14cc [32];
  char acStack_14ac [128];
  undefined1 auStack_142c [1024];
  sysinfo local_102c [64];
  int local_2c;
  
  iVar6 = DAT_00023878;
  __s = local_102c[0].loads;
  uStack_1598 = *(undefined4 *)(DAT_00023864 + 0x228f0);
  uStack_1594 = *(undefined4 *)(DAT_00023864 + 0x228f4);
  uStack_1590 = *(undefined4 *)(DAT_00023864 + 0x228f8);
  uStack_158c = *(undefined4 *)(DAT_00023864 + 0x228fc);
  local_2c = **(int **)(DAT_00023868 + 0x228c0 + DAT_0002386c);
  iVar2 = config_match(DAT_00023874 + 0x2290c,DAT_00023870 + 0x22904);
  psVar21 = (sysinfo *)(iVar6 + 0x22918);
  if (iVar2 != 0) {
    **(undefined4 **)((int)psVar21->loads + DAT_0002387c + -4) = 1;
  }
  pcVar22 = *(char **)((int)psVar21->loads + DAT_00023880 + -4);
  pcVar3 = (char *)(DAT_00023884 + 0x2293c);
  pcVar22[0x7f] = '\0';
  *pcVar22 = '\0';
  pcVar3 = getenv(pcVar3);
  pcVar4 = getenv((char *)(DAT_00023888 + 0x22958));
  if (pcVar4 == (char *)0x0) {
    local_15c4 = 0;
  }
  else {
    local_15c4 = FUN_00081e68();
  }
  pcVar4 = getenv((char *)(DAT_0002388c + 0x22978));
  if (pcVar4 != (char *)0x0) {
    strncpy(pcVar22,pcVar4,0x7f);
  }
  pcVar4 = getenv((char *)(DAT_00023890 + 0x22998));
  iVar5 = FUN_0008322c();
  piVar25 = *(int **)((int)psVar21->loads + DAT_00023894 + -4);
  *piVar25 = iVar5;
  iVar2 = DAT_000238a0;
  iVar6 = DAT_0002389c;
  if (iVar5 == 0) goto LAB_00022f28;
  piVar17 = *(int **)((int)psVar21->loads + DAT_00023898 + -4);
  *piVar17 = 0;
  pcVar22 = *(char **)((int)psVar21->loads + iVar6 + -4);
  uVar23 = *(undefined4 *)((int)psVar21->loads + iVar2 + -4);
  FUN_0003bf0c(iVar5,pcVar22,uVar23);
  iVar6 = FUN_00081dc4(*piVar25,DAT_000238a4 + 0x229fc);
  if ((iVar6 != 0) && (*pcVar22 != '\0')) {
    FUN_0003ba7c(pcVar22,DAT_000239d4 + 0x23484);
  }
  FUN_00081d94(auStack_152c,pcVar22,0x20);
  FUN_00081d94(auStack_150c,uVar23,0x20);
  pcVar7 = getenv((char *)(DAT_000238a8 + 0x22a4c));
  if (pcVar7 == (char *)0x0) {
    local_15c0 = *(undefined4 *)((int)psVar21->loads + DAT_000238ac + -4);
    FUN_00081d94(local_15c0,auStack_152c,0x100);
  }
  else {
    local_15c0 = *(undefined4 *)((int)psVar21->loads + DAT_000238ac + -4);
    FUN_00081d48(local_15c0,0x100,DAT_000238b0 + 0x22a74,auStack_152c,pcVar7);
  }
  FUN_00022300(local_15c0);
  FUN_00081d48(*(undefined4 *)((int)psVar21->loads + DAT_000238b4 + -4),0x100,DAT_000238b8 + 0x22aa4
               ,local_15c0);
  iVar2 = config_match(DAT_000238c0 + 0x22ab8,DAT_000238bc + 0x22ab4);
  iVar6 = DAT_00023980;
  if (iVar2 == 0) {
    config_set(DAT_0002397c + 0x230d8,auStack_152c);
    iVar2 = config_match(iVar6 + 0x230e4,DAT_00023984 + 0x230ec);
    if (iVar2 != 0) {
      config_set(iVar6 + 0x230e4,auStack_152c);
    }
  }
  iVar6 = FUN_00041cc0();
  if (iVar6 == 1) {
    local_15d8 = getenv((char *)(DAT_00023978 + 0x230bc));
  }
  else {
    local_15d8 = getenv((char *)(DAT_000238c4 + 0x22ad8));
  }
  if (local_15d8 == (char *)0x0) {
    local_15b0 = local_15d8;
    local_15b4 = local_15d8;
  }
  else {
    sVar8 = strspn(local_15d8,(char *)(DAT_000238c8 + 0x22af8));
    iVar6 = FUN_00081e38(local_15d8 + sVar8,DAT_000238cc + 0x22b08);
    if (iVar6 == 0) {
      local_15b4 = (char *)0x1;
      local_15d8 = (char *)0x0;
      local_15b0 = (char *)0x0;
    }
    else {
      cVar19 = *(char *)(iVar6 + 9);
      local_15d8 = (char *)(iVar6 + 9);
      pcVar18 = local_15d8;
      if (cVar19 != ':' && cVar19 != '\0') {
        do {
          pcVar18 = pcVar18 + 1;
          cVar19 = *pcVar18;
        } while (cVar19 != ':' && cVar19 != '\0');
      }
      if (cVar19 == '\0') {
        local_15b4 = (char *)0x1;
        local_15b0 = (char *)0x0;
      }
      else {
        pcVar9 = pcVar18 + 1;
        *pcVar18 = '\0';
        cVar19 = pcVar18[1];
        if (cVar19 != '\0' && cVar19 != '#') {
          do {
            pcVar9 = pcVar9 + 1;
            cVar19 = *pcVar9;
          } while (cVar19 != '#' && cVar19 != '\0');
        }
        if (cVar19 == '\0') {
          local_15b4 = (char *)0x1;
          local_15b0 = (char *)0x0;
        }
        else {
          local_15b0 = pcVar9 + 1;
          pcVar18 = local_15b0;
          if (pcVar9[1] != '\0' && pcVar9[1] != '\"') {
            do {
              pcVar18 = pcVar18 + 1;
            } while (*pcVar18 != '\"' && *pcVar18 != '\0');
          }
          local_15b4 = (char *)0x1;
          *pcVar18 = '\0';
        }
      }
    }
  }
  iVar6 = FUN_00081e20(param_3,DAT_00023950 + 0x22f9c);
  if ((iVar6 != 0) && (iVar6 = FUN_00081e20(param_3,DAT_00023954 + 0x22fb4), iVar6 != 0)) {
    uVar23 = FUN_00025e7c(DAT_00023a64 + 0x237d8);
    uVar14 = FUN_00025e7c(DAT_00023a68 + 0x237e8);
    FUN_0001fea0(param_4,0x1f5,DAT_00023a6c + 0x23804,uVar23,uVar14);
    goto LAB_00022f28;
  }
  iVar6 = config_match(DAT_0002395c + 0x22fd0,DAT_00023958 + 0x22fcc);
  if (iVar6 != 0) {
    iVar2 = 1;
    iVar5 = DAT_00023960 + 0x22ff4;
    iVar6 = DAT_00023964 + 0x22ff8;
    while( true ) {
      FUN_00081d48(local_102c,0x20,iVar5,iVar2);
      pcVar18 = (char *)config_get(local_102c);
      if (*pcVar18 == '\0') break;
      iVar26 = FUN_00042514(iVar6,auStack_152c,pcVar18);
      if (iVar26 == 1) {
        uVar23 = FUN_00025e7c(DAT_00023a20 + 0x23628);
        FUN_00021b08(param_4,uVar23);
        goto LAB_00022f28;
      }
      iVar2 = iVar2 + 1;
    }
  }
  if ((local_15b4 != (char *)0x0) &&
     (iVar6 = FUN_00081e20(param_3,DAT_00023968 + 0x23058), iVar6 == 0)) {
    FUN_000b09b8(param_4,param_5,local_15c4,local_15d8,local_15b0,*piVar25,*piVar17);
    goto LAB_00022f28;
  }
  iVar6 = config_match(DAT_00023970 + 0x23074,DAT_0002396c + 0x23070);
  if ((((iVar6 == 0) || (iVar6 = FUN_00081e38(pcVar4,DAT_00023a24 + 0x23648), iVar6 != 0)) ||
      (iVar6 = FUN_00081e38(pcVar4,DAT_00023a28 + 0x23660), iVar6 != 0)) ||
     (iVar6 = FUN_00022138(pcVar4), iVar6 != 1)) {
    iVar6 = FUN_00081e14(param_1);
    if (*param_1 != '\0') {
      bVar29 = false;
      goto LAB_00023094;
    }
    param_1 = (char *)(DAT_00023988 + 0x23110);
    bVar29 = false;
  }
  else {
    param_1 = (char *)(DAT_00023a2c + 0x23688);
    iVar6 = FUN_00081e14();
    bVar29 = true;
LAB_00023094:
    if (param_1[iVar6 + -1] == '/') {
      param_1 = (char *)(DAT_00023974 + 0x230b0);
    }
    else {
      iVar6 = config_match(DAT_000239dc + 0x2349c,DAT_000239d8 + 0x23498);
      if (((iVar6 != 0) &&
          (iVar6 = config_invmatch(DAT_000239e4 + 0x234b8,DAT_000239e0 + 0x234b4), iVar6 != 0)) &&
         (iVar6 = FUN_00031e00(param_1), iVar6 == 0)) {
        param_1 = (char *)(DAT_000239e8 + 0x234d8);
      }
    }
  }
  iVar6 = FUN_00081e38(param_1,DAT_0002398c + 0x2311c);
  if (((iVar6 != 0) &&
      (iVar6 = config_match(DAT_00023994 + 0x23138,DAT_00023990 + 0x23134), iVar6 != 0)) &&
     (iVar6 = config_invmatch(DAT_000239f0 + 0x234fc,DAT_000239ec + 0x234f8), iVar6 != 0)) {
    param_1 = (char *)(DAT_000239f4 + 0x2350c);
  }
  iVar6 = DAT_0002399c;
  iVar5 = DAT_000239a0 + 0x2315c;
  **(undefined4 **)((int)psVar21->loads + DAT_00023998 + -4) = 0;
  iVar2 = *piVar25;
  **(undefined4 **)((int)psVar21->loads + iVar6 + -4) = 0;
  iVar6 = FUN_00081dc4(iVar2,iVar5);
  if (iVar6 != 0) {
    iVar2 = DAT_000239a4 + 0x23188;
    iVar6 = config_match(DAT_000239a8 + 0x2318c,iVar2);
    if ((((iVar6 != 0) && (iVar6 = config_match(DAT_000239f8 + 0x2351c,iVar2), iVar6 != 0)) &&
        (iVar6 = FUN_00081e38(param_1,DAT_000239fc + 0x23534), iVar6 != 0)) &&
       (iVar6 = FUN_00081e38(param_1,DAT_00023a00 + 0x2354c), iVar6 == 0)) {
      iVar6 = config_match(DAT_00023a04 + 0x23564,iVar2);
      if (iVar6 != 0) {
        if (*piVar17 != 1) {
          iVar5 = DAT_00023a08 + 0x2358c;
          iVar6 = config_match(iVar5,iVar2);
          if ((iVar6 != 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023a0c + 0x235a8), iVar6 == 0)) {
            FUN_00021dd8(local_102c);
            FUN_00021b08(param_4,local_102c);
            config_set(iVar5,DAT_00023a10 + 0x235dc);
            goto LAB_00022f28;
          }
          goto LAB_00023198;
        }
        psVar21 = local_102c;
        FUN_00021dd8(psVar21);
        FUN_00021b08(param_4,psVar21);
        _Var15 = fork();
        if (_Var15 != 0) goto LAB_00022f28;
        FUN_0001f6c0();
      }
      iVar5 = DAT_00023bd4 + 0x246a4;
      iVar6 = config_match(iVar5,iVar2);
      if ((iVar6 != 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023bd8 + 0x246c0), iVar6 == 0)) {
        FUN_00021dd8(local_102c);
        FUN_00021b08(param_4,local_102c);
        config_set(iVar5,DAT_00023c28 + 0x248c4);
        FUN_00022068();
        goto LAB_00022f28;
      }
      iVar2 = DAT_00023bdc + 0x246d8;
      iVar6 = config_match(iVar2,DAT_00023be0 + 0x246dc);
      if ((iVar6 != 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023be4 + 0x246f8), iVar6 == 0)) {
        FUN_00021dd8(local_102c);
        FUN_00021b08(param_4,local_102c);
        config_set(iVar2,DAT_00023be8 + 0x2472c);
        FUN_00022068();
        goto LAB_00022f28;
      }
    }
  }
LAB_00023198:
  iVar6 = FUN_00081dc4(*piVar25,DAT_000239ac + 0x231ac);
  if (iVar6 == 0) {
LAB_000231b4:
    bVar1 = false;
  }
  else {
    iVar2 = DAT_00023a30 + 0x236a0;
    iVar6 = config_match(DAT_00023a34 + 0x236a4,iVar2);
    if ((iVar6 == 0) && (iVar6 = config_match(DAT_00023a38 + 0x236c0,iVar2), iVar6 == 0))
    goto LAB_000231b4;
    iVar6 = FUN_00081e38(param_1,DAT_00023a3c + 0x236d8);
    if (((iVar6 != 0) &&
        (((iVar6 = FUN_00081e38(param_1,DAT_00023a40 + 0x236f0), iVar6 == 0 &&
          (iVar6 = FUN_00081e38(param_1,DAT_00023a9c + 0x23dd8), iVar6 == 0)) &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023aa0 + 0x23df0), iVar6 == 0)))) &&
       ((((iVar6 = FUN_00081e38(param_1,DAT_00023aa4 + 0x23e08), iVar6 == 0 &&
          (iVar6 = FUN_00081e38(param_1,DAT_00023aa8 + 0x23e20), iVar6 == 0)) &&
         (iVar6 = FUN_00022530(param_1), iVar6 == 0)) &&
        ((iVar6 = FUN_00081e38(param_1,DAT_00023aac + 0x23e48), iVar6 == 0 &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023ab0 + 0x23e60), iVar6 == 0)))))) {
      tVar10 = time((time_t *)0x0);
      iVar2 = DAT_00023ab8 + 0x23e88;
      iVar6 = DAT_00023ab4 + 0x23f38;
      do {
        if (local_15c4 == 0) break;
        tVar11 = time((time_t *)0x0);
        if (5 < tVar11 - tVar10) {
          FUN_000361c8(iVar2,iVar6,0xb5d);
          tVar10 = time((time_t *)0x0);
        }
        local_15c4 = local_15c4 + -1;
        iVar5 = fgetc(param_5);
      } while (iVar5 != -1);
      iVar6 = FUN_00081e38(param_1,DAT_00023c0c + 0x24800);
      if (((iVar6 == 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023c1c + 0x2485c), iVar6 == 0)) &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023c20 + 0x24874), iVar6 == 0)) {
        iVar6 = FUN_00081e38(param_1,DAT_00023c24 + 0x2488c);
        bVar29 = iVar6 != 0;
      }
      else {
        bVar29 = true;
      }
      iVar6 = FUN_00081e38(param_1,DAT_00023c10 + 0x2481c);
      if (iVar6 != 0) {
        config_set(DAT_00023c18 + 0x24838,DAT_00023c14 + 0x24834);
      }
      FUN_0005b5dc(param_4,bVar29);
      config_commit();
      goto LAB_00022f28;
    }
    bVar1 = true;
  }
  piVar17 = *(int **)((int)psVar21->loads + DAT_000239b0 + -4);
  iVar6 = *piVar17;
  if (iVar6 == 1) {
    iVar6 = FUN_00081e38(param_1,DAT_00023a44 + 0x23710);
    if (((iVar6 == 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023a48 + 0x23728), iVar6 == 0)) &&
       ((((iVar6 = FUN_00081e38(param_1,DAT_00023a4c + 0x23740), iVar6 == 0 &&
          ((iVar6 = FUN_00081e38(param_1,DAT_00023a50 + 0x23758), iVar6 == 0 &&
           (iVar6 = FUN_00081e38(param_1,DAT_00023a54 + 0x23770), iVar6 == 0)))) &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023a58 + 0x23788), iVar6 == 0)) &&
        ((iVar6 = FUN_00081e38(param_1,DAT_00023a5c + 0x237a0), iVar6 == 0 &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023a60 + 0x237b8), iVar6 == 0)))))) {
      iVar6 = *piVar17;
      goto LAB_000231d0;
    }
  }
  else {
LAB_000231d0:
    if (iVar6 == 2) {
LAB_000231d8:
      iVar6 = FUN_00081e38(param_1,DAT_000239b4 + 0x231e8);
      if (((iVar6 == 0) && (iVar6 = FUN_00081e38(param_1,DAT_00023abc + 0x23eec), iVar6 == 0)) &&
         (iVar6 = FUN_00081e38(param_1,DAT_00023ac0 + 0x23f04), iVar6 == 0)) {
LAB_00023290:
        iVar6 = FUN_00081e38(param_1,DAT_000239c4 + 0x232a0);
        if (iVar6 != 0) {
          uVar23 = FUN_00025e7c(DAT_00023ac4 + 0x23f1c);
          uVar14 = FUN_00025e7c(DAT_00023ac8 + 0x23f2c);
          FUN_0001fea0(param_4,0x194,DAT_00023acc + 0x23f48,uVar23,uVar14);
          goto LAB_00022f28;
        }
        if ((*piVar17 == 1) && (iVar6 = FUN_00081e38(param_1,DAT_00023a8c + 0x23d90), iVar6 != 0)) {
          pcVar18 = (char *)(DAT_00023a90 + 0x23da4);
          uVar23 = FUN_0003b998(pcVar18);
          iVar6 = FUN_00081dc4(uVar23,DAT_00023a94 + 0x23db4);
          if (iVar6 == 0) {
            unlink(pcVar18);
          }
          else {
            param_1 = (char *)(DAT_00023a98 + 0x23dc8);
          }
        }
        if (param_2 == (char *)0x0) {
          **(undefined1 **)((int)psVar21->loads + DAT_00023bd0 + -4) = 0;
          local_15b4 = (char *)0x0;
        }
        else {
          puVar12 = (undefined1 *)FUN_00081e38(param_2,DAT_000239c8 + 0x232d4);
          if (puVar12 != (undefined1 *)0x0) {
            *puVar12 = 0;
            if (puVar12[0xd] != '\0') {
              pbVar27 = puVar12 + 0xd;
              uVar13 = FUN_00081e14(pbVar27);
              if (uVar13 < 0x20) {
                uVar13 = (uint)(byte)puVar12[0xd];
                if ((puVar12[0xd] & 0xdf) == 0 || uVar13 - 9 < 2) {
                  iVar6 = 0;
                  puVar24 = *(undefined1 **)((int)psVar21->loads + DAT_00023bd0 + -4);
                }
                else {
                  iVar6 = 0;
                  puVar24 = *(undefined1 **)((int)psVar21->loads + DAT_00023bd0 + -4);
                  puVar12 = puVar24;
                  do {
                    *puVar12 = (char)uVar13;
                    iVar6 = iVar6 + 1;
                    pbVar27 = pbVar27 + 1;
                    uVar13 = (uint)*pbVar27;
                    if ((*pbVar27 & 0xdf) == 0 || (uVar13 == 9 || uVar13 == 10)) break;
                    puVar12 = puVar12 + 1;
                  } while (iVar6 != 0x1f);
                }
                puVar24[iVar6] = 0;
                goto LAB_00023374;
              }
            }
            FUN_000361c8(DAT_00023ad0 + 0x23f68);
            uVar23 = FUN_00025e7c(DAT_00023ad4 + 0x23f74);
            uVar14 = FUN_00025e7c(DAT_00023ad8 + 0x23f84);
            FUN_0001fea0(param_4,400,DAT_00023adc + 0x23fa0,uVar23,uVar14);
            goto LAB_00022f28;
          }
          **(undefined1 **)((int)psVar21->loads + DAT_00023bd0 + -4) = 0;
LAB_00023374:
          iVar6 = DAT_000239cc + 0x23384;
          puVar12 = (undefined1 *)FUN_00081e38(param_2,iVar6);
          if (puVar12 != (undefined1 *)0x0) {
            *puVar12 = 0;
            iVar6 = FUN_00081e14(iVar6);
            uVar13 = (uint)(byte)puVar12[iVar6];
            pbVar27 = puVar12 + iVar6;
            if ((puVar12[iVar6] & 0xdf) == 0 || uVar13 - 9 < 2) {
              iVar6 = 0;
              pcVar9 = *(char **)((int)psVar21->loads + DAT_00023bc8 + -4);
            }
            else {
              iVar6 = 0;
              pcVar9 = *(char **)((int)psVar21->loads + DAT_00023bc8 + -4);
              pcVar18 = pcVar9;
              do {
                *pcVar18 = (char)uVar13;
                iVar6 = iVar6 + 1;
                pbVar27 = pbVar27 + 1;
                uVar13 = (uint)*pbVar27;
                if ((*pbVar27 & 0xdf) == 0 || (uVar13 == 9 || uVar13 == 10)) break;
                pcVar18 = pcVar18 + 1;
              } while (iVar6 != 0x1f);
            }
            pcVar9[iVar6] = '\0';
            if ((*pcVar9 != '\0') && (iVar6 = FUN_00042e60(pcVar9), iVar6 == 0)) {
              uVar23 = FUN_00025e7c(DAT_00023b80 + 0x24450);
              uVar14 = FUN_00025e7c(DAT_00023b84 + 0x24460);
              FUN_0001fea0(param_4,400,DAT_00023b88 + 0x2447c,uVar23,uVar14);
              goto LAB_00022f28;
            }
          }
          if (*piVar17 == 1) {
            local_15b4 = (char *)FUN_0008d38c(param_2,*piVar25,pcVar7,auStack_152c);
            if (local_15b4 == (char *)0x1) {
              param_1 = (char *)(DAT_00023ba4 + 0x24538);
            }
            else if (local_15b4 == (char *)0x3) {
              param_1 = (char *)(DAT_00023bcc + 0x2465c);
            }
            else if (local_15b4 == (char *)0x2) {
              pcVar18 = (char *)(DAT_00023bec + 0x24740);
              uVar23 = FUN_0003b998(pcVar18);
              iVar6 = FUN_00081dc4(uVar23,DAT_00023bf0 + 0x24750);
              if (iVar6 == 0) {
                param_1 = (char *)(DAT_00023bf4 + 0x24764);
              }
              else {
                param_1 = (char *)FUN_0003b998(pcVar18);
                unlink(pcVar18);
              }
            }
            else if (local_15b4 == (char *)0x4) {
              param_1 = (char *)(DAT_000239d0 + 0x23474);
            }
          }
          else {
            local_15b4 = (char *)0x0;
          }
        }
        iVar6 = DAT_00023a7c;
        piVar28 = (int *)(DAT_00023a78 + 0x23cec);
        FUN_00081dac(DAT_00023a70 + 0x23d34,*(undefined4 *)((int)psVar21->loads + DAT_00023a74 + -4)
                     ,0x144);
        iVar2 = *piVar28;
        while (iVar2 != 0) {
          iVar2 = FUN_00081e38(param_1);
          if ((iVar2 != 0) &&
             ((iVar2 = FUN_00041cc0(), iVar2 != 0 ||
              (iVar2 = FUN_00081e38(param_1,iVar6 + 0x23cf8), iVar2 == 0)))) {
            iVar6 = FUN_00081e38(param_1,DAT_000238d0 + 0x22bc4);
            iVar2 = DAT_000238d8 + 0x22be4;
            *(uint *)(DAT_000238d4 + 0x22bec) = (uint)(iVar6 != 0);
            iVar6 = FUN_00081e20(param_3,iVar2);
            if ((iVar6 == 0) && (piVar28[3] == 0)) {
              iVar6 = DAT_00023b98 + 0x244cc;
              uVar23 = FUN_00025e7c(iVar6);
              uVar14 = FUN_00025e7c(iVar6);
              FUN_0001fea0(param_4,0x1f5,DAT_00023b9c + 0x244f8,uVar23,uVar14);
              goto LAB_00022f28;
            }
            iVar6 = FUN_00081e20(param_3,DAT_000238dc + 0x22c0c);
            if ((iVar6 == 0) && (*param_2 != '/' && *param_2 != '\0')) {
              uVar23 = FUN_00025e7c(DAT_00023b2c + 0x241d0);
              uVar14 = FUN_00025e7c(DAT_00023b30 + 0x241e0);
              FUN_0001fea0(param_4,400,DAT_00023b34 + 0x241fc,uVar23,uVar14);
              goto LAB_00022f28;
            }
            iVar6 = FUN_00041cc0();
            if ((iVar6 == 1) && (iVar6 = FUN_00081e38(param_1,DAT_00023ae0 + 0x23fb4), iVar6 != 0))
            {
              FUN_000361c8(DAT_00023ae4 + 0x23fc8);
              if (((*piVar17 != 1) || (iVar6 = FUN_00022340(), iVar6 == 0)) &&
                 (iVar6 = FUN_00030480(pcVar3), iVar6 == 0)) goto LAB_00024518;
              FUN_000361c8(DAT_00023ae8 + 0x23ff4);
              system((char *)(DAT_00023aec + 0x24000));
              goto LAB_00022f28;
            }
            FUN_00081d48(auStack_142c,0x400,DAT_000238e0 + 0x22c54,piVar28[2]);
            if ((((((piVar28[5] != 0) &&
                   (iVar6 = FUN_00081e38(param_1,DAT_000238e4 + 0x22c70), iVar6 == 0)) &&
                  (iVar6 = FUN_00081e38(param_1,DAT_00023b38 + 0x24210), iVar6 == 0)) &&
                 ((iVar6 = FUN_00081e38(param_1,DAT_00023b3c + 0x24228), iVar6 == 0 &&
                  (iVar6 = FUN_00081e38(param_1,DAT_00023b40 + 0x24240), iVar6 == 0)))) &&
                (iVar6 = FUN_00081e38(param_1,DAT_00023b44 + 0x24258), iVar6 == 0)) &&
               ((iVar6 = FUN_00081e38(param_1,DAT_00023b48 + 0x24270), iVar6 == 0 ||
                (iVar6 = FUN_00081e38(param_1,DAT_00023b4c + 0x24288), iVar6 != 0)))) {
              iVar2 = DAT_00023b50 + 0x2429c;
              iVar6 = FUN_0003c2b8(iVar2);
              if (((iVar6 != 1) && (iVar6 = FUN_0003c2b8(iVar2), iVar6 != 3)) ||
                 ((((iVar6 = FUN_00081e38(param_1,DAT_00023bfc + 0x2479c), iVar6 == 0 &&
                    (iVar6 = FUN_00081e38(param_1,DAT_00023c00 + 0x247b4), iVar6 == 0)) &&
                   (iVar6 = FUN_00081e38(param_2,DAT_00023c04 + 0x247cc), iVar6 == 0)) &&
                  (iVar6 = FUN_00081e38(param_1,DAT_00023c08 + 0x247e4), iVar6 == 0)))) {
                iVar2 = DAT_00023b54 + 0x242c4;
                iVar6 = FUN_000370bc(iVar2);
                if (iVar6 == 0) {
                  if (bVar1) {
                    FUN_000370bc(iVar2);
                  }
                  else {
                    iVar6 = FUN_00081e20(param_3,DAT_00025580 + 0x25090);
                    if ((iVar6 == 0) &&
                       (iVar6 = FUN_00081e38(param_1,DAT_000255c0 + 0x251e4), iVar6 != 0)) {
                      iVar2 = DAT_000255c4 + 0x251fc;
                      iVar6 = config_invmatch(DAT_000255c8 + 0x25200,iVar2);
                      if ((iVar6 == 0) ||
                         (iVar6 = config_invmatch(DAT_000255cc + 0x2521c,iVar2), iVar6 == 0))
                      goto LAB_00025098;
                      iVar2 = DAT_000255d0 + 0x25234;
                      iVar6 = config_match(DAT_000255d4 + 0x25238,iVar2);
                      if ((iVar6 == 0) ||
                         (iVar6 = config_match(DAT_000255d8 + 0x25254,iVar2), iVar6 == 0))
                      goto LAB_00025098;
                      iVar6 = strncmp(param_1,(char *)(DAT_000255dc + 0x25270),5);
                      pcVar18 = param_1;
                      if (iVar6 == 0) {
                        pcVar18 = param_1 + 5;
                      }
                      iVar6 = FUN_0003b7e8(pcVar18,&uStack_1598);
                      if (iVar6 != 0) goto LAB_00025098;
                      uVar23 = FUN_0003b998(DAT_000255e0 + 0x25298);
                      iVar6 = FUN_00081dc4(uVar23,DAT_000255e4 + 0x252a4);
                      if (iVar6 == 0) goto LAB_00025098;
LAB_00025180:
                      iVar6 = config_invmatch(DAT_000255b4 + 0x25194,DAT_000255b0 + 0x25190);
                      if (iVar6 == 0) {
                        param_1 = (char *)(DAT_000255b8 + 0x251a8);
                      }
                      else {
                        param_1 = (char *)(DAT_000255bc + 0x251d4);
                      }
                    }
                    else {
LAB_00025098:
                      iVar6 = FUN_000370bc(DAT_00025584 + 0x250a4);
                      if (iVar6 != 0) goto LAB_000250ac;
                    }
                  }
                }
                else {
                  iVar6 = FUN_000370bc(iVar2);
                  if (iVar6 == 0) {
                    bVar1 = false;
                  }
                  else {
                    bVar1 = (bool)(bVar1 ^ 1);
                  }
                  if (!bVar1) goto LAB_000242e0;
LAB_000250ac:
                  iVar6 = FUN_00081e20(param_3,DAT_00025588 + 0x250bc);
                  if ((iVar6 == 0) &&
                     (iVar6 = FUN_00081e38(param_1,DAT_0002558c + 0x250d4), iVar6 != 0)) {
                    iVar2 = DAT_00025590 + 0x250ec;
                    iVar6 = config_invmatch(DAT_00025594 + 0x250f0,iVar2);
                    if ((iVar6 != 0) &&
                       ((iVar6 = config_invmatch(DAT_00025598 + 0x2510c,iVar2), iVar6 != 0 &&
                        (iVar6 = config_match(DAT_000255a0 + 0x25128,DAT_0002559c + 0x25124),
                        iVar6 != 0)))) {
                      iVar6 = strncmp(param_1,(char *)(DAT_000255a4 + 0x25144),5);
                      pcVar18 = param_1;
                      if (iVar6 == 0) {
                        pcVar18 = param_1 + 5;
                      }
                      iVar6 = FUN_0003b7e8(pcVar18,&uStack_1598);
                      if (iVar6 == 0) {
                        uVar23 = FUN_0003b998(DAT_000255a8 + 0x2516c);
                        iVar6 = FUN_00081dc4(uVar23,DAT_000255ac + 0x25178);
                        if (iVar6 != 0) goto LAB_00025180;
                      }
                    }
                  }
                }
LAB_000242e0:
                iVar2 = DAT_00023b58 + 0x242f0;
                iVar6 = FUN_0002df9c(local_15c0,iVar2);
                if (iVar6 == 0) {
                  FUN_000818a4(iVar2,2,DAT_000255e8 + 0x252cc,local_15c0,0);
                }
                iVar6 = config_invmatch(DAT_00023b60 + 0x24310,DAT_00023b5c + 0x2430c);
                if (iVar6 == 0) {
                  if (*piVar17 == 0) {
                    iVar6 = FUN_00031f60(auStack_152c);
                    if (iVar6 != 0) {
LAB_00024a94:
                      FUN_0001fe34(param_4);
                      goto LAB_00022f28;
                    }
                    iVar2 = DAT_00023c88 + 0x24b34;
                    iVar6 = config_match(DAT_00023c8c + 0x24b38,iVar2);
                    if ((iVar6 != 0) &&
                       (iVar6 = config_match(DAT_00025500 + 0x24d2c,iVar2), iVar6 != 0)) {
                      FUN_0003b998(DAT_00025504 + 0x24d40);
                      iVar6 = FUN_00081e68();
                      if (iVar6 != 1) {
                        param_1 = (char *)(DAT_00025508 + 0x24d54);
                      }
                    }
                    iVar6 = FUN_000370bc(DAT_00023c90 + 0x24b50);
                    if ((iVar6 == 0) ||
                       (iVar6 = config_match(DAT_00023c98 + 0x24b6c,DAT_00023c94 + 0x24b68),
                       iVar6 == 0)) {
LAB_00024b74:
                      pcVar22 = (char *)FUN_0003b998(DAT_00023c9c + 0x24b80);
                      if ((*pcVar22 != '\0') &&
                         (((iVar6 = FUN_00081e38(param_1,DAT_00023ca0 + 0x24ba0), iVar6 != 0 ||
                           (iVar6 = FUN_00081e38(param_1,DAT_0002564c + 0x254d4), iVar6 != 0)) ||
                          (iVar6 = FUN_00081e38(param_1,DAT_00025650 + 0x254ec), iVar6 != 0)))) {
                        iVar2 = DAT_00023ca4 + 0x24bb8;
                        iVar6 = FUN_00081e38(param_1,iVar2);
                        if (iVar6 == 0) {
                          local_15d8 = (char *)(DAT_00025648 + 0x254c0);
                        }
                        else {
                          iVar2 = FUN_00081e14(iVar2);
                          local_15d8 = (char *)(iVar6 + iVar2);
                        }
                        iVar6 = DAT_00023ca8;
                        sysinfo(local_102c);
                        lVar16 = strtol(pcVar22,(char **)0x0,10);
                        pcVar22 = (char *)FUN_0003b998(iVar6 + 0x24bf4);
                        iVar2 = 1 - (local_102c[0].uptime - lVar16);
                        if (0 < iVar2 || lVar16 < 1) {
                          if ((iVar2 == 1 && lVar16 >= 1) || (0 < iVar2 && *pcVar22 == '1')) {
                            FUN_0003ba7c(DAT_00025628 + 0x2542c,DAT_00025624 + 0x25428);
                            FUN_0001fbbc(param_4,200,DAT_00025630 + 0x25454,0,DAT_0002562c + 0x25448
                                        );
                            uVar23 = FUN_00025e7c(DAT_00025634 + 0x25460);
                            __fprintf_chk(param_4,1,DAT_00025638 + 0x25480,local_15d8,iVar2 * 1000,
                                          uVar23);
                            goto LAB_00022f28;
                          }
                        }
                        else {
                          FUN_0003ba7c(DAT_00025640 + 0x254a0,DAT_0002563c + 0x2549c);
                          FUN_0003ba7c(DAT_00025644 + 0x254b0,iVar6 + 0x24bf4);
                        }
                      }
                      pcVar22 = getenv((char *)(DAT_00023cac + 0x24c7c));
                      iVar6 = FUN_00031390(param_1,pcVar4,*piVar25,pcVar3,pcVar22);
                      if (iVar6 != 1) {
                        tVar10 = time((time_t *)0x0);
                        iVar5 = DAT_000254fc + 0x24cc8;
                        iVar2 = DAT_000254f8 + 0x24d78;
                        goto LAB_00024ce0;
                      }
                      iVar6 = FUN_0002e5c4(DAT_00025518 + 0x24e1c,auStack_152c);
                      if (iVar6 != 0) {
                        FUN_00031160(DAT_00025564 + 0x25000,auStack_152c);
                        unlink((char *)(DAT_00025568 + 0x2500c));
                        iVar6 = piVar28[2];
                        pcVar22 = (char *)FUN_0003b998(DAT_0002556c + 0x2501c);
                        FUN_00081d48(auStack_142c,0x400,DAT_00025570 + 0x25038,iVar6,pcVar22);
                      }
                      iVar6 = FUN_0002e5c4(DAT_0002551c + 0x24e34,auStack_152c);
                      if (iVar6 != 0) {
                        iVar6 = piVar28[2];
                        pcVar22 = (char *)FUN_0003b998(DAT_0002555c + 0x24fd0);
                        FUN_00081d48(auStack_142c,0x400,DAT_00025560 + 0x24fec,iVar6,pcVar22);
                      }
                      iVar6 = FUN_0002e5c4(DAT_00025520 + 0x24e4c,auStack_152c);
                      if (iVar6 != 0) {
                        FUN_00081d48(local_102c,0x40,DAT_0002554c + 0x24f78,auStack_152c,pcVar22);
                        unlink((char *)local_102c);
                      }
LAB_00024e54:
                      config_set(DAT_00025528 + 0x24e68,DAT_00025524 + 0x24e64);
                    }
                    else {
                      iVar6 = FUN_00081e38(param_1,DAT_000255ec + 0x252e0);
                      if ((((iVar6 == 0) &&
                           (((iVar6 = FUN_00081e38(param_1,DAT_000255f0 + 0x252f8), iVar6 == 0 &&
                             (iVar6 = FUN_00081e38(param_1,DAT_000255f4 + 0x25310), iVar6 == 0)) &&
                            (iVar6 = FUN_00081e38(param_1,DAT_000255f8 + 0x25328), iVar6 == 0)))) &&
                          (iVar6 = FUN_00081e38(param_1,DAT_000255fc + 0x25340), iVar6 == 0)) &&
                         (((iVar6 = FUN_00081e38(param_1,DAT_00025600 + 0x25358), iVar6 == 0 ||
                           (iVar6 = FUN_00081e38(param_1,DAT_00025604 + 0x25370), iVar6 != 0)) &&
                          ((iVar6 = FUN_00081e38(param_1,DAT_00025608 + 0x25388), iVar6 == 0 ||
                           (iVar6 = FUN_00089510(*piVar25,pcVar7,auStack_152c), iVar6 != 1)))))) {
                        iVar2 = FUN_00088604(DAT_0002560c + 0x253c8,*piVar25,pcVar7,auStack_152c);
                        iVar6 = DAT_0002561c;
                        if (iVar2 == 1) goto LAB_00024e54;
                        if (**(int **)((int)psVar21->loads + DAT_00025610 + -4) != 1)
                        goto LAB_00024b74;
                        FUN_0003ba7c(DAT_00025618 + 0x253fc,DAT_00025614 + 0x253f8);
                        iVar2 = DAT_00025620;
                        piVar28[3] = 0;
                        param_1 = (char *)(iVar6 + 0x25410);
                        piVar28[4] = *(int *)((int)psVar21->loads + iVar2 + -4);
                      }
                    }
                  }
                  else if ((local_15b4 != (char *)0x2) &&
                          (((iVar6 = FUN_00081e38(param_1,DAT_00023b64 + 0x24344), iVar6 == 0 ||
                            (iVar6 = FUN_0008d3c4(*piVar25,pcVar7,auStack_152c), iVar6 != 1)) &&
                           (iVar6 = FUN_0008c408(DAT_00023b68 + 0x24384,*piVar25,pcVar7,auStack_152c
                                                ), iVar6 != 1)))) {
                    if (*piVar17 == 2) {
                      iVar6 = FUN_00031f60(pcVar22);
                      if (iVar6 != 0) goto LAB_00024a94;
                      iVar26 = DAT_00023c4c + 0x249b0;
                      iVar5 = FUN_0003c2b8(iVar26);
                      iVar2 = DAT_00023c58;
                      iVar6 = DAT_00023c50;
                      if (iVar5 == 1) {
                        FUN_0003c2dc(iVar26,0);
                        FUN_000226d4(param_1,param_2);
                        uVar23 = FUN_0003b998(iVar2 + 0x24a0c);
                        FUN_00036254(DAT_00023c60 + 0x24a34,DAT_00023c5c + 0x24a30,uVar23);
                        FUN_0001fbbc(param_4,200,DAT_00023c68 + 0x24a54,0,DAT_00023c64 + 0x24a50);
                        uVar23 = FUN_0003b998(iVar2 + 0x24a0c);
                        iVar6 = FUN_00081e38(uVar23,DAT_00023c6c + 0x24a70);
                        if (iVar6 == 0) {
                          fwrite((void *)(DAT_00023c74 + 0x24ab8),1,0x77,param_4);
                        }
                        else {
                          fwrite((void *)(DAT_00023c70 + 0x24a90),1,0x73,param_4);
                        }
                        goto LAB_00024980;
                      }
                      FUN_000226d4(param_1,param_2);
                      param_1 = (char *)(iVar6 + 0x249d8);
                    }
                    else {
                      iVar26 = DAT_00023b6c + 0x243a8;
                      iVar5 = FUN_0003c2b8(iVar26);
                      iVar2 = DAT_00023c2c;
                      iVar6 = DAT_00023b70;
                      if (iVar5 == 1) {
                        FUN_0003c2dc(iVar26,0);
                        FUN_000226d4(param_1,param_2);
                        uVar23 = FUN_0003b998(iVar2 + 0x248fc);
                        FUN_00036254(DAT_00023c34 + 0x24924,DAT_00023c30 + 0x24920,uVar23);
                        FUN_0001fbbc(param_4,200,DAT_00023c3c + 0x2494c,0,DAT_00023c38 + 0x24940);
                        uVar23 = FUN_0003b998(iVar2 + 0x248fc);
                        iVar6 = FUN_00081e38(uVar23,DAT_00023c40 + 0x24960);
                        if (iVar6 == 0) {
                          fwrite((void *)(DAT_00023c54 + 150000),1,0x7c,param_4);
                        }
                        else {
                          fwrite((void *)(DAT_00023c44 + 0x24980),1,0x78,param_4);
                        }
LAB_00024980:
                        FUN_0003c2dc(DAT_00023c48 + 0x24990,0);
                        goto LAB_00022f28;
                      }
                      FUN_000226d4(param_1,param_2);
                      param_1 = (char *)(iVar6 + 0x243d0);
                    }
                  }
                }
              }
            }
            pcVar20 = (code *)piVar28[3];
            piVar17 = (int *)(DAT_000238e8 + 0x22c90);
            *piVar17 = 0;
            local_15bc = param_1;
            if ((pcVar20 != (code *)0x0) &&
               ((*pcVar20)(param_1,param_5,local_15c4), iVar6 = DAT_00023b8c, local_15bc = param_2,
               *piVar17 == 1)) {
              *piVar17 = 0;
              uVar23 = FUN_00025e7c(iVar6 + 0x24490);
              uVar14 = FUN_00025e7c(DAT_00023b90 + 0x244a0);
              FUN_0001fea0(param_4,400,DAT_00023b94 + 0x244bc,uVar23,uVar14);
              goto LAB_00022f28;
            }
            if (*(int *)(DAT_000238ec + 0x22e58) == 400) {
              *(undefined4 *)(DAT_000238ec + 0x22e58) = 200;
              config_uncommit();
              uVar23 = FUN_00025e7c(DAT_00023b14 + 0x24130);
              uVar14 = FUN_00025e7c(DAT_00023b18 + 0x24140);
              FUN_0001fea0(param_4,400,DAT_00023b1c + 0x2415c,uVar23,uVar14);
              goto LAB_00022f28;
            }
            iVar6 = FUN_000370bc(DAT_000238f0 + 0x22cd0);
            if (((iVar6 != 0) && (iVar6 = FUN_00036cf8(), iVar6 == 1)) &&
               (iVar6 = config_match(DAT_00023b00 + 0x240c4,DAT_00023afc + 0x240c0), iVar6 != 0)) {
              uVar23 = FUN_0003b998(DAT_00023b04 + 0x240d8);
              iVar6 = FUN_00081dc4(uVar23,DAT_00023b08 + 0x240e4);
              if (iVar6 == 0) {
                pcVar3 = (char *)(DAT_00023b0c + 0x240f8);
                iVar6 = access(pcVar3,0);
                if (iVar6 < 0) {
                  FUN_0003ba7c(DAT_00023b10 + 0x24114,pcVar3);
                }
              }
            }
            if (((((local_15bc != (char *)0x0) &&
                  (iVar6 = FUN_00081dc4(local_15bc,DAT_000238f4 + 0x22cf4), iVar6 != 0)) &&
                 (piVar28[4] != 0)) &&
                ((iVar6 = FUN_00081dc4(local_15bc,DAT_000238f8 + 0x22d18), iVar6 != 0 &&
                 (iVar6 = FUN_00081dc4(local_15bc,DAT_00023ba8 + 0x24548), iVar6 != 0)))) &&
               (iVar6 = FUN_00081dc4(local_15bc,DAT_00023bac + 0x24560), iVar6 != 0)) {
              iVar6 = FUN_00081e38(local_15bc,DAT_00023bb0 + 0x2457c);
              if (iVar6 == 0) {
                FUN_00081d48(acStack_14ac,0x80,DAT_00023c84 + 0x24b10,local_15bc);
              }
              else {
                FUN_00081d94(acStack_14ac,local_15bc,0x80);
              }
              iVar6 = FUN_00081e38(acStack_14ac,DAT_00023bb4 + 0x245a4);
              if (iVar6 != 0) {
                acStack_14ac[iVar6 - (int)acStack_14ac] = '\0';
              }
              iVar6 = __xstat(3,acStack_14ac,&sStack_1588);
              if (iVar6 == -1) {
                uVar23 = FUN_00025e7c(DAT_00023c78 + 0x24ac8);
                uVar14 = FUN_00025e7c(DAT_00023c7c + 0x24ad8);
                FUN_0001fea0(param_4,0x194,DAT_00023c80 + 0x24af4,uVar23,uVar14);
                goto LAB_00022f28;
              }
              __realpath_chk(acStack_14ac,local_102c,0x1000);
              iVar6 = FUN_00081e38(local_102c,DAT_00023bb8 + 0x24600);
              if (iVar6 == 0) {
                uVar23 = FUN_00025e7c(DAT_00023bbc + 0x24614);
                uVar14 = FUN_00025e7c(DAT_00023bc0 + 0x24624);
                FUN_0001fea0(param_4,0x194,DAT_00023bc4 + 0x24640,uVar23,uVar14);
                goto LAB_00022f28;
              }
            }
            iVar6 = FUN_00041cc0();
            if ((iVar6 == 1) && (piVar28[4] != 0 && piVar28[4] == DAT_00023af0 + 0x2402c)) {
              if (piVar28[2] == 0) {
                FUN_00081d48(local_102c,0x400,DAT_00023bf8 + 0x24788,local_15bc);
              }
              else {
                FUN_00081d48(local_102c,0x400,DAT_00023af4 + 0x24074,local_15bc,piVar28[2]);
              }
              FUN_0001fbbc(param_4,200,DAT_00023af8 + 0x24098,local_102c,piVar28[1]);
              fflush(param_4);
            }
            else {
              if (**(int **)((int)psVar21->loads + DAT_000238fc + -4) == 1) {
                local_102c[0].uptime = 0;
                memset(__s,0,0x1fc);
                FUN_00081d48(local_102c,0x200,DAT_00023b78 + 0x24410,piVar28[2],
                             *(undefined4 *)((int)psVar21->loads + DAT_00023b74 + -4));
                FUN_0001fbbc(param_4,200,DAT_00023b7c + 0x24430,local_102c,piVar28[1]);
              }
              else if (**(int **)((int)psVar21->loads + DAT_00023900 + -4) == 1) {
                local_102c[0].uptime = 0;
                memset(__s,0,0x1fc);
                FUN_00081d48(local_102c,0x200,DAT_00023b24 + 0x241a0,piVar28[2],
                             *(undefined4 *)((int)psVar21->loads + DAT_00023b20 + -4));
                FUN_0001fbbc(param_4,200,DAT_00023b28 + 0x241c0,local_102c,piVar28[1]);
              }
              else {
                FUN_0001fbbc(param_4,200,DAT_00023904 + 0x22d70,auStack_142c,piVar28[1]);
              }
              if ((code *)piVar28[4] != (code *)0x0) {
                (*(code *)piVar28[4])(local_15bc,param_4);
              }
              fflush(param_4);
              if (((!bVar29) &&
                  (iVar6 = config_invmatch(DAT_0002390c + 0x22db0,DAT_00023908 + 0x22dac),
                  iVar6 != 0)) &&
                 (iVar6 = FUN_00081dc4(*piVar25,DAT_00023910 + 0x22dcc), iVar6 != 0)) {
                local_102c[0].uptime = 0;
                memset(__s,0,0x1fc);
                if ((((local_15bc != (char *)0x0) &&
                     (iVar6 = FUN_00081e38(local_15bc,DAT_00023914 + 0x22e08), iVar6 != 0)) &&
                    ((iVar6 = FUN_00081e38(local_15bc,DAT_00023918 + 0x22e20), iVar6 == 0 &&
                     ((iVar6 = FUN_00081e38(local_15bc,DAT_0002391c + 0x22e38), iVar6 == 0 &&
                      (iVar6 = FUN_00081e38(local_15bc,DAT_00023920 + 0x22e50), iVar6 == 0)))))) &&
                   ((iVar6 = FUN_00081e38(local_15bc,DAT_00023924 + 0x22e68), iVar6 == 0 &&
                    (iVar6 = FUN_00081e38(local_15bc,DAT_00023928 + 0x22e80), iVar6 == 0)))) {
                  iVar6 = FUN_00081e38(local_15bc,DAT_0002392c + 0x22e9c);
                  if (iVar6 != 0) {
                    local_15bc = local_15bc + 4;
                  }
                  FUN_00081d48(local_102c,0x200,DAT_00023930 + 0x22ebc,pcVar4,local_15bc);
                  FUN_0003ba7c(local_102c,DAT_00023934 + 0x22ee4);
                  FUN_000818a4(DAT_00023940 + 0x22f10,3,DAT_00023938 + 0x22f04,
                               DAT_0002393c + 0x22f0c,local_102c,0);
                  FUN_00036254(DAT_00023948 + 0x22f28,DAT_00023944 + 0x22f24,local_102c);
                }
              }
            }
            goto LAB_00022f28;
          }
          piVar28 = piVar28 + 6;
          iVar2 = *piVar28;
        }
        uVar23 = FUN_00025e7c(DAT_00023a80 + 0x23d44);
        uVar14 = FUN_00025e7c(DAT_00023a84 + 0x23d54);
        FUN_0001fea0(param_4,0x194,DAT_00023a88 + 0x23d70,uVar23,uVar14);
        fflush(param_4);
        goto LAB_00022f28;
      }
    }
    else {
      iVar6 = FUN_00081e38(param_1,DAT_000239c0 + 0x23278);
      if (iVar6 == 0) {
        if (*piVar17 != 1) goto LAB_000231d8;
        goto LAB_00023290;
      }
    }
  }
  iVar2 = DAT_000239bc;
  iVar6 = DAT_000239b8;
  tVar10 = time((time_t *)0x0);
  do {
    if (local_15c4 == 0) break;
    tVar11 = time((time_t *)0x0);
    if (5 < tVar11 - tVar10) {
      FUN_000361c8(iVar2 + 0x23210,iVar6 + 0x232bc,0xb80);
      tVar10 = time((time_t *)0x0);
    }
    local_15c4 = local_15c4 + -1;
    iVar5 = fgetc(param_5);
  } while (iVar5 != -1);
  uVar23 = FUN_00025e7c(DAT_00023a14 + 0x235ec);
  uVar14 = FUN_00025e7c(DAT_00023a18 + 0x235fc);
  FUN_0001fea0(param_4,0x194,DAT_00023a1c + 0x23618,uVar23,uVar14);
LAB_00022f28:
  if (local_2c == **(int **)(DAT_0002394c + 0x22f40 + DAT_0002386c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
  while( true ) {
    tVar11 = time((time_t *)0x0);
    if (5 < tVar11 - tVar10) {
      FUN_000361c8(iVar5,iVar2,0xcd4);
      tVar10 = time((time_t *)0x0);
    }
    local_15c4 = local_15c4 + -1;
    iVar26 = fgetc(param_5);
    if (iVar26 == -1) break;
LAB_00024ce0:
    if (local_15c4 == 0) break;
  }
  iVar2 = fileno(param_5);
  uVar13 = fcntl(iVar2,3);
  if ((uVar13 != 0xffffffff) && (iVar5 = fcntl(iVar2,4,uVar13 | 0x800), iVar5 != -1)) {
    iVar5 = fgetc(param_5);
    if (iVar5 != -1) {
      fgetc(param_5);
    }
    fcntl(iVar2,4,uVar13);
  }
  if (iVar6 == 2) {
    iVar6 = FUN_0002e5c4(DAT_00025550 + 0x24f94,auStack_152c);
    if (iVar6 != 0) {
      FUN_00031160(DAT_00025554 + 0x24fac,auStack_152c);
    }
  }
  else {
    if (iVar6 == 4) {
      FUN_0001fbbc(param_4,200,DAT_00025578 + 0x25064,0,DAT_00025574 + 0x25058);
      fwrite((void *)(DAT_0002557c + 0x2507c),1,0x8e,param_4);
      goto LAB_00022f28;
    }
    if (iVar6 == 5) {
LAB_00024518:
      FUN_00020030(param_4,DAT_00023ba0 + 0x24528);
      goto LAB_00022f28;
    }
    iVar6 = FUN_00081e38(param_1,DAT_0002550c + 0x24ddc);
    if (iVar6 != 0) {
      FUN_0001fbbc(param_4,200,DAT_00025514 + 0x24e04,0,DAT_00025510 + 0x24e00);
      goto LAB_00022f28;
    }
    iVar6 = FUN_0002e5c4(DAT_0002552c + 0x24e7c,auStack_152c);
    if (iVar6 != 0) {
      FUN_00031160(DAT_00025530 + 0x24ea0,auStack_152c);
      uVar23 = FUN_0008322c();
      FUN_0003bf0c(uVar23,auStack_14ec,auStack_14cc);
      FUN_00081d48(acStack_14ac,0x40,DAT_00025534 + 0x24ed0,auStack_14ec);
      local_102c[0].uptime = 0;
      memset(__s,0,0x3fc);
      uVar23 = FUN_0003b998(acStack_14ac);
      FUN_00081d48(local_102c,0x400,DAT_00025538 + 0x24f04,uVar23);
      FUN_0001fbbc(param_4,200,DAT_00025540 + 0x24f2c,local_102c,DAT_0002553c + 0x24f20);
      fwrite((void *)(DAT_00025544 + 0x24f44),1,0xc5,param_4);
      FUN_0003c2dc(DAT_00025548 + 0x24f54,0);
      goto LAB_00022f28;
    }
  }
  FUN_00020030(param_4,DAT_00025558 + 0x24fbc);
  goto LAB_00022f28;
}


===== FUNCTION FUN_00031390 @ 00031390 =====

int FUN_00031390(int param_1,int param_2,int param_3,char *param_4,undefined4 param_5)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_ac [32];
  undefined1 auStack_8c [32];
  char acStack_6c [64];
  int local_2c;
  
  iVar4 = DAT_00031bec;
  local_2c = **(int **)(DAT_00031be4 + 0x313ac + DAT_00031be8);
  FUN_0003bf0c(param_3,auStack_ac,auStack_8c,0);
  iVar4 = iVar4 + 0x313f0;
  iVar1 = config_invmatch(DAT_00031bf4 + 0x313f8,DAT_00031bf0 + 0x313f4);
  if (iVar1 != 0) {
    iVar1 = 1;
    FUN_00036254(DAT_00031c70 + 0x316d0,DAT_00031c6c + 0x316c4,DAT_00031c68 + 0x31800,0x3a7,
                 **(undefined4 **)(iVar4 + DAT_00031c48));
    goto LAB_0003143c;
  }
  if (param_3 == 0 || (param_1 == 0 || param_2 == 0)) {
    iVar1 = 2;
    FUN_00036254(DAT_00031c60 + 0x31688,DAT_00031c5c + 0x31684,DAT_00031c58 + 0x317b8,0x3ad,param_1,
                 param_2,param_3);
    system((char *)(DAT_00031c64 + 0x31698));
    goto LAB_0003143c;
  }
  iVar1 = FUN_00081dc4(param_3,DAT_00031bf8 + 0x31430);
  if (iVar1 != 0) {
    pcVar2 = getenv((char *)(DAT_00031c00 + 0x31474));
    iVar1 = FUN_00081dc4(pcVar2,DAT_00031c04 + 0x31480);
    if ((iVar1 == 0) &&
       ((((iVar1 = FUN_00081e38(param_1,DAT_00031c74 + 0x316e8), iVar1 != 0 ||
          (iVar1 = FUN_00081e38(param_1,DAT_00031c98 + 0x317fc), iVar1 != 0)) ||
         (iVar1 = FUN_00081e38(param_1,DAT_00031c9c + 0x31814), iVar1 != 0)) ||
        (((iVar1 = FUN_00081e38(param_1,DAT_00031ca0 + 0x3182c), iVar1 != 0 ||
          (iVar1 = FUN_00081e38(param_1,DAT_00031ca4 + 0x31844), iVar1 != 0)) ||
         (iVar1 = FUN_00081e38(param_1,DAT_00031ca8 + 0x3185c), iVar1 != 0)))))) {
      iVar1 = 1;
      FUN_00036254(DAT_00031c80 + 0x31724,DAT_00031c7c + 0x31718,DAT_00031c78 + 0x31854,0x3bf,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      goto LAB_0003143c;
    }
    iVar1 = config_match(DAT_00031c0c + 0x3149c,DAT_00031c08 + 0x31498);
    if (((iVar1 != 0) && (iVar1 = FUN_00081e38(param_2,DAT_00031c10 + 0x314b4), iVar1 == 0)) &&
       ((iVar1 = FUN_00081e38(param_2,DAT_00031cf8 + 0x31a18), iVar1 == 0 &&
        (iVar1 = FUN_00022138(param_2), iVar1 == 1)))) {
      FUN_00036254(DAT_00031d04 + 0x31a64,DAT_00031d00 + 0x31a58,DAT_00031cfc + 0x31b94,0x3ca,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      iVar1 = 1;
      goto LAB_0003143c;
    }
    FUN_00081d48(acStack_6c,0x40,DAT_00031c14 + 0x314d4);
    if (((param_4 == (char *)0x0) ||
        (iVar1 = strncasecmp(param_4,(char *)(DAT_00031c18 + 0x314f0),6), iVar1 != 0)) ||
       ((iVar1 = FUN_0002e5c4(DAT_00031c1c + 0x31508,auStack_ac), iVar1 == 0 &&
        ((iVar1 = FUN_0002e5c4(DAT_00031c20 + 0x31520,auStack_ac), iVar1 == 0 &&
         (iVar1 = FUN_0002e5c4(DAT_00031c24 + 0x31538,auStack_ac), iVar1 == 0)))))) {
      FUN_00036254(DAT_00031cb4 + 0x31898,DAT_00031cb0 + 0x3188c,DAT_00031cac + 0x319c8,0x3d3,
                   **(undefined4 **)(iVar4 + DAT_00031c48));
      iVar4 = access(acStack_6c,0);
      if (iVar4 != 0) {
LAB_000319b8:
        FUN_00031160(DAT_00031ce8 + 0x319c8,auStack_ac);
      }
LAB_000318b0:
      iVar1 = 2;
      goto LAB_0003143c;
    }
    iVar1 = FUN_0002ff9c(param_3,param_4);
    if (iVar1 != 0) {
      iVar1 = FUN_00081e38(param_1,DAT_00031c28 + 0x31564);
      if (iVar1 == 0) {
        iVar1 = 3;
        FUN_00036254(DAT_00031d20 + 0x31afc,DAT_00031d1c + 0x31af0,(int)&DAT_00031c2c + DAT_00031d18
                     ,0x3fa,**(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
      iVar1 = FUN_0002e5c4(DAT_00031c2c + 0x3157c,auStack_ac);
      if (iVar1 != 0) {
        iVar3 = DAT_00031c30 + 0x31590;
        iVar1 = FUN_0003c2b8(iVar3);
        if (iVar1 != 1) {
          FUN_0003c2dc(iVar3,1);
          iVar1 = 5;
          FUN_00036254(DAT_00031d2c + 0x31b44,DAT_00031d28 + 0x31b38,
                       (int)&DAT_00031c74 + DAT_00031d24,0x3e5,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
          system((char *)(DAT_00031d30 + 0x31b54));
          goto LAB_0003143c;
        }
      }
      iVar1 = FUN_0002e5c4(DAT_00031c34 + 0x315ac,auStack_ac);
      if ((iVar1 != 0) && (iVar1 = FUN_00030004(param_4,param_3,param_5), iVar1 != 0)) {
        FUN_0002f77c(param_4,param_3);
        FUN_0002e8c8(param_3,param_4);
        iVar1 = 1;
        FUN_00031160(DAT_00031c38 + 0x315f8,auStack_ac);
        unlink((char *)(DAT_00031c3c + 0x31604));
        FUN_0003c2dc(DAT_00031c40 + 0x31614,1);
        FUN_0003c2dc(DAT_00031c44 + 0x31624,0);
        FUN_00036254(DAT_00031c54 + 0x31654,DAT_00031c50 + 0x31648,DAT_00031c4c + 0x31784,0x3f3,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
    }
    iVar5 = DAT_00031c84 + 0x31738;
    iVar1 = FUN_0003c2b8(iVar5);
    iVar3 = FUN_00030004(param_4,param_3,param_5);
    if (iVar3 != 1 || iVar1 != 1) {
      FUN_0002f6d4(param_3,param_4);
      if (iVar1 == 1) {
        FUN_0002e53c(param_3);
      }
      else {
        FUN_0003c2dc(iVar5,1);
      }
      iVar6 = DAT_00031cb8 + 0x318e8;
      iVar5 = config_invmatch(iVar6,DAT_00031cbc + 0x318ec);
      if (iVar5 != 0) {
        config_set(iVar6,DAT_00031d08 + 0x31a7c);
      }
      config_set(DAT_00031cc4 + 0x3190c,DAT_00031cc0 + 0x31908);
      system((char *)(DAT_00031cc8 + 0x31918));
      iVar5 = FUN_0002e5c4(DAT_00031ccc + 0x31928,auStack_ac);
      if (((iVar5 == 0) && (iVar5 = FUN_0002e5c4(DAT_00031cd4 + 0x3195c,auStack_ac), iVar5 == 0)) &&
         (iVar5 = FUN_0002e5c4(DAT_00031cd8 + 0x31974,auStack_ac), iVar5 == 0)) {
        FUN_00036254(DAT_00031ce4 + 0x319ac,DAT_00031ce0 + 0x319a0,DAT_00031cdc + 0x31adc,0x41c,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
        if (iVar1 == 1) goto LAB_000319b8;
        goto LAB_000318b0;
      }
      if (iVar3 != 1) {
        iVar1 = 5;
        FUN_00036254(DAT_00031d14 + 0x31ac0,DAT_00031d10 + 0x31ab4,(int)&DAT_00031bf0 + DAT_00031d0c
                     ,0x426,**(undefined4 **)(iVar4 + DAT_00031c48));
        goto LAB_0003143c;
      }
      FUN_0003c2dc(DAT_00031cd0 + 0x31948,1);
    }
    iVar1 = FUN_0002e8c8(param_3,param_4);
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        FUN_00036254(DAT_00031d48 + 0x31bc0,DAT_00031d44 + 0x31bb4,(int)&DAT_00031cf0 + DAT_00031d40
                     ,0x431,**(undefined4 **)(iVar4 + DAT_00031c48));
        system((char *)(DAT_00031d4c + 0x31bd0));
        system((char *)(DAT_00031d50 + 0x31bdc));
      }
      else if (iVar1 == 4) {
        iVar3 = FUN_00081e38(param_1,DAT_00031c88 + 0x3179c);
        if (iVar3 == 0) {
          FUN_00036254(DAT_00031d3c + 0x31b88,DAT_00031d38 + 0x31b7c,
                       (int)&DAT_00031cb8 + DAT_00031d34,0x442,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
        }
        else {
          FUN_0002f77c(param_4,param_3);
          iVar1 = 1;
          FUN_00036254(DAT_00031c94 + 0x317e4,DAT_00031c90 + 0x317d8,DAT_00031c8c + 0x31914,0x43d,
                       **(undefined4 **)(iVar4 + DAT_00031c48));
        }
      }
      else {
        iVar1 = 1;
        FUN_00036254(DAT_00031cf4 + 0x31a00,DAT_00031cf0 + 0x319f4,DAT_00031cec + 0x31b30,0x449,
                     **(undefined4 **)(iVar4 + DAT_00031c48));
      }
      goto LAB_0003143c;
    }
  }
  iVar1 = 1;
LAB_0003143c:
  if (local_2c == **(int **)(DAT_00031bfc + 0x3144c + DAT_00031be8)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== FUNCTION FUN_0002e5c4 @ 0002e5c4 =====

void FUN_0002e5c4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_49c [64];
  sysinfo local_45c;
  undefined4 local_41c;
  undefined1 auStack_418 [508];
  char local_21c [512];
  int local_1c;
  
  local_1c = **(int **)(DAT_0002e878 + 0x2e5e0 + DAT_0002e87c);
  local_41c = 0;
  memset(auStack_418,0,0x1fc);
  local_21c[0] = '\0';
  local_21c[1] = '\0';
  local_21c[2] = '\0';
  local_21c[3] = '\0';
  memset(local_21c + 4,0,0x1fc);
  sysinfo(&local_45c);
  iVar1 = FUN_00081dc4(param_1,DAT_0002e880 + 0x2e63c);
  if (iVar1 == 0) {
    FUN_00081d48(auStack_49c,0x40,DAT_0002e884 + 0x2e658);
  }
  else {
    iVar1 = FUN_00081dc4(param_1,DAT_0002e8ac + 0x2e798);
    if (iVar1 == 0) {
      FUN_00081d48(auStack_49c,0x40,DAT_0002e8b0 + 0x2e7b4);
    }
    else {
      iVar1 = FUN_00081dc4(param_1,DAT_0002e8bc + 0x2e818);
      if (iVar1 == 0) {
        FUN_00081d48(auStack_49c,0x40,DAT_0002e8c0 + 0x2e838,param_2);
      }
    }
  }
  iVar1 = FUN_00081dc4(param_1,DAT_0002e888 + 0x2e668);
  if (iVar1 == 0) {
    uVar4 = FUN_0003b998(auStack_49c);
    FUN_00081d94(local_21c,uVar4,0x200);
    pcVar2 = strtok(local_21c,(char *)(DAT_0002e8b4 + 0x2e7e4));
    if (pcVar2 == (char *)0x0) goto LAB_0002e670;
    strtok((char *)0x0,(char *)(DAT_0002e8b8 + 0x2e7fc));
    iVar1 = FUN_00082024();
  }
  else {
LAB_0002e670:
    iVar1 = 0;
  }
  pcVar2 = getenv((char *)(DAT_0002e88c + 0x2e680));
  if ((pcVar2 != (char *)0x0) && (iVar3 = FUN_00081e38(pcVar2,DAT_0002e890 + 0x2e694), iVar3 != 0))
  {
    pcVar2 = strtok((char *)(iVar3 + 0xb),(char *)(DAT_0002e894 + 0x2e6b0));
    FUN_00081d48(&local_41c,0x200,DAT_0002e898 + 0x2e6c8,pcVar2);
    iVar3 = FUN_00081dc4(param_1,DAT_0002e89c + 0x2e6d8);
    if (iVar3 == 0) {
      uVar4 = FUN_0003b998(auStack_49c);
      iVar3 = FUN_00081dc4(&local_41c,uVar4);
      if (iVar3 != 0) goto LAB_0002e6fc;
LAB_0002e858:
      FUN_000361c8(DAT_0002e8c4 + 0x2e86c,param_2,param_1);
      uVar4 = 1;
      goto LAB_0002e75c;
    }
LAB_0002e6fc:
    iVar3 = FUN_00081dc4(param_1,DAT_0002e8a0 + 0x2e70c);
    if (iVar3 == 0) {
      uVar4 = FUN_0003b998(auStack_49c);
      iVar3 = FUN_00081dc4(&local_41c,uVar4);
      if (iVar3 == 0) goto LAB_0002e858;
    }
    iVar3 = FUN_00081dc4(param_1,DAT_0002e8a4 + 0x2e724);
    if (iVar3 == 0) {
      uVar4 = FUN_0003b998(auStack_49c);
      iVar3 = FUN_00081dc4(&local_41c,uVar4);
      if ((iVar3 == 0) && (local_45c.uptime - iVar1 < 0x12d)) goto LAB_0002e858;
    }
  }
  uVar4 = 0;
LAB_0002e75c:
  if (local_1c == **(int **)(DAT_0002e8a8 + 0x2e76c + DAT_0002e87c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}


===== TARGET /tmp/first_time_login =====
STRING 000d367c
REF depth=0 from=0002c3a8 to=000d367c
REF depth=0 from=0002c3d4 to=000d367c

===== FUNCTION FUN_0002c394 @ 0002c394 =====

void FUN_0002c394(FILE *param_1)

{
  int iVar1;
  char *__name;
  
  __name = (char *)(DAT_0002c3e4 + 0x2c3ac);
  iVar1 = access(__name,0);
  if (iVar1 == 0) {
    fputc(0x30,param_1);
    return;
  }
  fputc(0x31,param_1);
  FUN_0003ba7c((int)&DAT_0002c3e4 + DAT_0002c3e8,__name);
  return;
}


===== TARGET /tmp/enable_telnet =====
STRING 000eb130
REF depth=0 from=00116958 to=000eb130

===== TARGET BRS_index.htm =====
STRING 000d4bb3
STRING 000e3a1c
REF depth=0 from=0005a468 to=000e3a1c

===== FUNCTION FUN_0005a3b4 @ 0005a3b4 =====

void FUN_0005a3b4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0005a5a0 + 0x5a3cc;
  iVar1 = config_match(DAT_0005a5a4 + 0x5a3d4,iVar2);
  if (iVar1 == 0) {
    iVar3 = DAT_0005a5b8 + 0x5a42c;
    iVar2 = DAT_0005a5bc + 0x5a430;
    iVar1 = config_invmatch(iVar2,iVar3);
    if (iVar1 != 0) {
      config_set(iVar2,iVar3);
    }
    iVar1 = config_match(DAT_0005a5c4 + 0x5a454,DAT_0005a5c0 + 0x5a450);
    if (iVar1 != 0) {
      FUN_0003b998(DAT_0005a5fc + 0x5a564);
      iVar1 = FUN_00081e68();
      if ((iVar1 == 1) && (iVar1 = access((char *)(DAT_0005a600 + 0x5a580),0), iVar1 == 0)) {
        iVar1 = DAT_0005a604 + 0x5a594;
        goto LAB_0005a464;
      }
    }
  }
  else {
    iVar1 = config_match(DAT_0005a5ac + 0x5a3f0,DAT_0005a5a8 + 0x5a3ec);
    if ((iVar1 != 0) && (iVar1 = config_invmatch(DAT_0005a5b0 + 0x5a408,iVar2), iVar1 != 0)) {
      iVar1 = DAT_0005a5b4 + 0x5a41c;
      goto LAB_0005a464;
    }
    iVar2 = DAT_0005a5dc + 0x5a4c8;
    iVar1 = config_match(DAT_0005a5e0 + 0x5a4cc,iVar2);
    if (iVar1 != 0) {
      iVar1 = config_invmatch(DAT_0005a5e4 + 0x5a4e8,iVar2);
      if (iVar1 == 0) {
        iVar1 = DAT_0005a5e8 + 0x5a4fc;
      }
      else {
        iVar1 = (int)&DAT_0005a5a0 + DAT_0005a608;
      }
      goto LAB_0005a464;
    }
    iVar3 = DAT_0005a5f0 + 0x5a520;
    iVar1 = config_match(iVar3,iVar2);
    if (iVar1 != 0) {
      iVar1 = DAT_0005a5f8 + 0x5a544;
      config_set(iVar3,DAT_0005a5f4 + 0x5a540);
      goto LAB_0005a464;
    }
  }
  iVar1 = DAT_0005a5c8 + 0x5a468;
LAB_0005a464:
  iVar2 = FUN_00081e38(iVar1,DAT_0005a5cc + 0x5a474);
  if (iVar2 == 0) {
    __fprintf_chk(param_1,1,DAT_0005a5ec + 0x5a50c,iVar1);
  }
  else {
    __fprintf_chk(param_1,1,DAT_0005a5d0 + 0x5a494,iVar1);
  }
  FUN_0003c2dc(DAT_0005a5d4 + 0x5a4a4,4);
  FUN_0003c2dc(DAT_0005a5d8 + 0x5a4b8,1000);
  return;
}


===== TARGET upload_firmware =====
STRING 000cc5ac
REF depth=0 from=0001e7f0 to=000cc5ac

===== FUNCTION FUN_0001e704 @ 0001e704 =====

void FUN_0001e704(undefined4 param_1,FILE *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  time_t tVar3;
  time_t tVar4;
  int iVar5;
  int iVar6;
  FILE *__n;
  FILE *pFVar7;
  char acStack_124 [256];
  int local_24;
  
  pFVar7 = (FILE *)(param_3 + 1);
  __n = param_2;
  if (pFVar7 < (FILE *)0xff) {
    __n = pFVar7;
  }
  if (pFVar7 >= (FILE *)0xff) {
    __n = (FILE *)0xff;
  }
  local_24 = **(int **)(DAT_0001e904 + 0x1e72c + DAT_0001e908);
  *(undefined4 *)(DAT_0001e90c + 0x1e748) = 0;
  pcVar1 = fgets(acStack_124,(int)__n,param_2);
  iVar6 = DAT_0001e914;
  iVar5 = DAT_0001e910;
  if (pcVar1 != (char *)0x0) {
    iVar2 = FUN_00081e14(acStack_124);
    param_3 = param_3 - iVar2;
    tVar3 = time((time_t *)0x0);
    do {
      if (param_3 == 0) break;
      tVar4 = time((time_t *)0x0);
      if (5 < tVar4 - tVar3) {
        FUN_000361c8(iVar6 + 0x1e790,iVar5 + 0x1e79c,0x497);
        tVar3 = time((time_t *)0x0);
      }
      param_3 = param_3 + -1;
      iVar2 = fgetc(param_2);
    } while (iVar2 != -1);
    iVar5 = FUN_00026564(DAT_0001e918 + 0x1e7f8);
    if (iVar5 == 0) {
      iVar5 = FUN_00081e38(acStack_124,DAT_0001e91c + 0x1e810);
      iVar6 = FUN_00081e38(acStack_124,DAT_0001e920 + 0x1e824);
      if (iVar6 != 0 && iVar5 != 0) {
        if (*(char *)(iVar6 + 0xc) == '1') {
          config_set(DAT_0001e950 + 0x1e8fc,DAT_0001e94c + 0x1e8f8);
        }
        iVar6 = DAT_0001e92c;
        if (*(char *)(iVar5 + 0xf) == '1') {
          iVar5 = DAT_0001e928 + 0x1e864;
          *(undefined4 *)(DAT_0001e924 + 0x1e864) = 1;
          FUN_00037eec(iVar5);
          FUN_0003ba7c(iVar6 + 0x1e874,DAT_0001e930 + 0x1e87c);
          config_set(DAT_0001e934 + 0x1e88c,iVar6 + 0x1e874);
          config_set(DAT_0001e93c + 0x1e8a0,DAT_0001e938 + 0x1e89c);
          config_commit();
          system((char *)(DAT_0001e940 + 0x1e8b0));
        }
      }
    }
    else {
      FUN_000361c8(DAT_0001e948 + 0x1e8e4);
    }
  }
  if (local_24 == **(int **)(DAT_0001e944 + 0x1e8c0 + DAT_0001e908)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

