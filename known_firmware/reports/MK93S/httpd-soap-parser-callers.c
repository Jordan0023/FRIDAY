
===== TARGET 000770a8 =====
REF depth=0 from=000775a4 to=000770a8

===== FUNCTION FUN_00077500 @ 00077500 =====

int FUN_00077500(undefined4 param_1,undefined4 param_2,in_addr param_3)

{
  undefined4 *puVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *__s2;
  undefined4 local_358;
  int local_354;
  in_addr_t local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  char acStack_340 [20];
  char local_32c [256];
  char local_22c [256];
  char local_12c [256];
  int local_2c;
  
  iVar8 = 0;
  local_2c = *DAT_000778c8;
  local_32c[0] = '\0';
  local_32c[1] = '\0';
  local_32c[2] = '\0';
  local_32c[3] = '\0';
  memset(local_32c + 4,0,0xfc);
  local_22c[0] = '\0';
  local_22c[1] = '\0';
  local_22c[2] = '\0';
  local_22c[3] = '\0';
  memset(local_22c + 4,0,0xfc);
  local_12c[0] = '\0';
  local_12c[1] = '\0';
  local_12c[2] = '\0';
  local_12c[3] = '\0';
  memset(local_12c + 4,0,0xfc);
  *DAT_000778cc = 0;
  local_354 = -1;
  local_348 = 0;
  local_344 = 0;
  local_358 = param_2;
  local_350 = param_3.s_addr;
  local_34c = param_1;
  memset(acStack_340,0,0x14);
  iVar2 = FUN_000770a8(param_1,local_32c,local_22c);
  uVar7 = DAT_000778d0;
  if (iVar2 < 0) {
LAB_000775e8:
    FUN_00075848(2,uVar7);
    uVar7 = 0x194;
  }
  else {
    FUN_00075848(2,DAT_000778d4,local_32c,local_22c);
    puVar1 = DAT_000778e0;
    uVar7 = DAT_000778d8;
    if ((local_32c[0] == '\0') || (local_22c[0] == '\0')) goto LAB_000775e8;
    sVar3 = strlen(local_22c);
    for (puVar9 = puVar1;
        (pcVar10 = (char *)puVar9[1], pcVar10 != (char *)0x0 &&
        (__s2 = (char *)*puVar9, __s2 != (char *)0x0)); puVar9 = puVar9 + 4) {
      sVar4 = strlen(pcVar10);
      if (((sVar3 == sVar4) &&
          ((iVar2 = strcmp(local_22c,pcVar10), iVar2 == 0 &&
           (iVar2 = strcmp(local_32c,__s2), iVar2 == 0)))) ||
         ((iVar2 = strcmp(local_22c,__s2), iVar2 == 0 &&
          (iVar2 = strcmp(local_32c,pcVar10), iVar2 == 0)))) goto LAB_000776ac;
      iVar8 = iVar8 + 1;
    }
    iVar8 = -1;
LAB_000776ac:
    FUN_00075848(2,DAT_000778e4,iVar8);
    iVar2 = strcmp(local_32c,DAT_000778e8);
    if (iVar2 != 0) {
      iVar2 = 0;
LAB_00077754:
      uVar7 = DAT_00077908;
      if (iVar8 != -1) {
        uVar7 = DAT_00077904;
        if (((puVar1[iVar8 * 4 + 3] & 1) == 0) && ((puVar1[iVar8 * 4 + 3] & 0x7c) != 0)) {
          if ((iVar2 != 0) ||
             (((iVar5 = FUN_00076db4(param_1,DAT_000778f4,local_12c,0xff), iVar5 == 0 &&
               (local_12c[0] != '\0')) &&
              ((iVar5 = acosNvramConfig_match(DAT_00077900,local_12c), iVar5 != 0 ||
               ((local_12c[0] != '\0' && (iVar5 = strcmp(local_12c,DAT_000778fc), iVar5 == 0))))))))
          {
            pcVar10 = inet_ntoa(param_3);
            snprintf(acStack_340,0x13,DAT_0007790c,pcVar10);
            local_354 = iVar8;
            FUN_00075848(2,DAT_00077910,iVar8);
            uVar6 = (*(code *)puVar1[iVar8 * 4 + 2])(&local_358);
            FUN_00075848(2,DAT_00077914,uVar6);
            printf(DAT_00077918,uVar6);
            if (uVar6 < 2) {
              iVar2 = acosNvramConfig_match(DAT_00077920,DAT_0007791c);
              if (iVar2 != 0) {
                FUN_000891ac();
              }
              FUN_00089270();
              FUN_00089328(param_2);
            }
            else {
              if (iVar2 != 1) goto LAB_000778a4;
              acosNvramConfig_set(DAT_00077900,DAT_000778dc);
            }
            iVar2 = 0;
            goto LAB_000778a4;
          }
          goto LAB_00077884;
        }
      }
      goto LAB_000775e8;
    }
    iVar5 = strcmp(local_22c,DAT_000778ec);
    iVar2 = 0;
    if (iVar5 != 0) goto LAB_00077754;
    printf(DAT_000778f0,1);
    iVar2 = FUN_00076db4(param_1,DAT_000778f4,local_12c,0xff);
    if (iVar2 == 0) {
      printf(DAT_000778f8,local_12c);
      if (local_12c[0] != '\0') {
        iVar2 = strcmp(local_12c,DAT_000778fc);
        if (iVar2 != 0) {
          acosNvramConfig_set(DAT_00077900,local_12c);
        }
        iVar2 = 1;
        goto LAB_00077754;
      }
    }
LAB_00077884:
    uVar7 = 0x191;
  }
  iVar2 = FUN_00077240(&local_358,DAT_000778dc,uVar7,0x20000);
LAB_000778a4:
  if (local_2c != *DAT_000778c8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

