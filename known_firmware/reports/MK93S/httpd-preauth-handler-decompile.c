
===== ENTRY 00070358 =====
===== FUNCTION FUN_00070358 @ 00070358 =====

undefined4 FUN_00070358(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)PTR_DAT_000703b4;
  iVar1 = acosNvramConfig_match
                    (PTR_s_enable_password_recovery_000703b8,PTR_s_0_00129c86_0x1a_000703bc,param_3,
                     0,param_1);
  if (iVar1 == 0) {
    FUN_000520ec(PTR_s_MNU_access_setRecovery_redirect__000703c0,param_2);
  }
  if (iVar2 != *(int *)PTR_DAT_000703b4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


===== ENTRY 00070664 =====
===== FUNCTION FUN_00070664 @ 00070664 =====

undefined4 FUN_00070664(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  char *__s2;
  time_t tVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  time_t tStack_18d4;
  tm local_18d0;
  int local_18a4;
  undefined1 auStack_18a0 [124];
  char local_1824 [2048];
  char local_1024 [2048];
  int local_824;
  undefined1 auStack_820 [2044];
  int local_24;
  
  local_24 = *DAT_00070af0;
  FUN_000513d0(param_1,DAT_00070af4,local_1824,0x800);
  FUN_000513d0(param_1,DAT_00070af8,local_1024,0x800);
  iVar1 = acosNvramConfig_match(DAT_00070b00,DAT_00070afc);
  if (iVar1 == 0) {
    uVar5 = DAT_00070b04;
    if ((local_1824[0] != '\0') && (local_1024[0] != '\0')) {
      local_18a4 = iVar1;
      memset(auStack_18a0,0,0x7c);
      local_824 = iVar1;
      memset(auStack_820,0,0x7c);
      FUN_00079038(local_1824,&local_18a4);
      FUN_00079038(local_1024,&local_824);
      memset(local_1824,0,0x800);
      memset(local_1024,0,0x800);
      strlcpy(local_1824,&local_18a4,0x80);
      strlcpy(local_1024,&local_824,0x80);
      pcVar2 = (char *)acosNvramConfig_get(DAT_00070b08);
      __s2 = (char *)acosNvramConfig_get(DAT_00070b0c);
      iVar1 = strcasecmp(local_1824,pcVar2);
      if ((iVar1 == 0) && (iVar1 = strcasecmp(local_1024,__s2), iVar1 == 0)) {
        tVar3 = time((time_t *)0x0);
        piVar8 = DAT_00070b14;
        if (DAT_00070b10 < tVar3) {
          time(&tStack_18d4);
          localtime_r(&tStack_18d4,&local_18d0);
          pcVar2 = (char *)FUN_000e810c(DAT_00070b18);
          iVar1 = strcmp(DAT_00070b1c,pcVar2);
          piVar8 = &local_824;
          if (iVar1 == 0) {
            uVar4 = FUN_00051748(DAT_00070b80);
            uVar5 = DAT_00070b3c;
            if (((((local_18d0.tm_mon != 0) && (uVar5 = DAT_00070b40, local_18d0.tm_mon != 1)) &&
                 (uVar5 = DAT_00070b44, local_18d0.tm_mon != 2)) &&
                (((uVar5 = DAT_00070b48, local_18d0.tm_mon != 3 &&
                  (uVar5 = DAT_00070b4c, local_18d0.tm_mon != 4)) &&
                 ((uVar5 = DAT_00070b50, local_18d0.tm_mon != 5 &&
                  ((uVar5 = DAT_00070b54, local_18d0.tm_mon != 6 &&
                   (uVar5 = DAT_00070b58, local_18d0.tm_mon != 7)))))))) &&
               ((uVar5 = DAT_00070b5c, local_18d0.tm_mon != 8 &&
                ((uVar5 = DAT_00070b60, local_18d0.tm_mon != 9 &&
                 (uVar5 = DAT_00070b64, local_18d0.tm_mon != 10)))))) {
              uVar5 = DAT_00070b68;
            }
            uVar6 = FUN_00051748(uVar5);
            uVar7 = FUN_00051748(DAT_00070b84);
            uVar5 = DAT_00070b20;
            if (((((local_18d0.tm_wday != 0) && (uVar5 = DAT_00070b24, local_18d0.tm_wday != 1)) &&
                 (uVar5 = DAT_00070b28, local_18d0.tm_wday != 2)) &&
                ((uVar5 = DAT_00070b2c, local_18d0.tm_wday != 3 &&
                 (uVar5 = DAT_00070b30, local_18d0.tm_wday != 4)))) &&
               (uVar5 = DAT_00070b34, local_18d0.tm_wday != 5)) {
              uVar5 = DAT_00070b38;
            }
            uVar5 = FUN_00051748(uVar5);
            snprintf((char *)&local_824,0x800,DAT_00070b88,local_18d0.tm_year + 0x76c,uVar4,uVar6,
                     local_18d0.tm_mday,uVar7,uVar5,local_18d0.tm_hour,local_18d0.tm_min);
          }
          else {
            uVar5 = DAT_00070b20;
            if (((local_18d0.tm_wday != 0) && (uVar5 = DAT_00070b24, local_18d0.tm_wday != 1)) &&
               ((uVar5 = DAT_00070b28, local_18d0.tm_wday != 2 &&
                (((uVar5 = DAT_00070b2c, local_18d0.tm_wday != 3 &&
                  (uVar5 = DAT_00070b30, local_18d0.tm_wday != 4)) &&
                 (uVar5 = DAT_00070b34, local_18d0.tm_wday != 5)))))) {
              uVar5 = DAT_00070b38;
            }
            uVar4 = FUN_00051748(uVar5);
            uVar5 = DAT_00070b3c;
            if ((((local_18d0.tm_mon != 0) && (uVar5 = DAT_00070b40, local_18d0.tm_mon != 1)) &&
                ((((uVar5 = DAT_00070b44, local_18d0.tm_mon != 2 &&
                   ((uVar5 = DAT_00070b48, local_18d0.tm_mon != 3 &&
                    (uVar5 = DAT_00070b4c, local_18d0.tm_mon != 4)))) &&
                  (uVar5 = DAT_00070b50, local_18d0.tm_mon != 5)) &&
                 (((uVar5 = DAT_00070b54, local_18d0.tm_mon != 6 &&
                   (uVar5 = DAT_00070b58, local_18d0.tm_mon != 7)) &&
                  (uVar5 = DAT_00070b5c, local_18d0.tm_mon != 8)))))) &&
               ((uVar5 = DAT_00070b60, local_18d0.tm_mon != 9 &&
                (uVar5 = DAT_00070b64, local_18d0.tm_mon != 10)))) {
              uVar5 = DAT_00070b68;
            }
            uVar5 = FUN_00051748(uVar5);
            snprintf((char *)&local_824,0x800,DAT_00070b6c,uVar4,uVar5,local_18d0.tm_mday,
                     local_18d0.tm_year + 0x76c,local_18d0.tm_hour,local_18d0.tm_min,
                     local_18d0.tm_sec);
          }
        }
        acosNvramConfig_set(DAT_00070b70,piVar8);
        acosNvramConfig_set(DAT_00070b78,DAT_00070b74);
        acosNvramConfig_save();
        uVar5 = DAT_00070b7c;
      }
      else {
        acosNvramConfig_set(DAT_00070b78,DAT_00070afc);
        acosNvramConfig_save();
        uVar5 = DAT_00070b04;
      }
    }
    FUN_000520ec(uVar5,param_2);
  }
  if (local_24 != *DAT_00070af0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

