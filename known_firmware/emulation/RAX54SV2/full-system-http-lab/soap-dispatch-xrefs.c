STRING 0017c24f soap_response_raw
REF 0006c138 owner=FUN_0006c070
REF 0006c154 owner=FUN_0006c070
REF 0006c2f8 owner=FUN_0006c070
REF 0006c318 owner=FUN_0006c070
REF 0006c350 owner=FUN_0006c070
STRING 0017c503 func_index ===%d E

REF 0006c83c owner=FUN_0006c518
STRING 0017c5de function index %d E

REF 0006c9c8 owner=FUN_0006c518
STRING 00181a6f ResetAdminPassword
CALLER_REF target=FUN_0006c070 from=0006c4e8 owner=FUN_0006c448
CALLER_REF target=FUN_0006c070 from=0006cbbc owner=FUN_0006cae8
CALLER_REF target=FUN_0006c518 from=0006bbfc owner=FUN_0006bb6c

===== FUN_0006c070 @ 0006c070 =====

void FUN_0006c070(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int local_12ac;
  int local_12a8;
  undefined1 auStack_12a4 [128];
  char local_1224 [512];
  char local_1024 [4096];
  int local_24;
  
  iVar7 = DAT_0006c3ec + 0x6c090;
  piVar5 = *(int **)(iVar7 + DAT_0006c3f0);
  local_12ac = 0;
  local_24 = *piVar5;
  local_1024[0] = '\0';
  local_1024[1] = '\0';
  local_1024[2] = '\0';
  local_1024[3] = '\0';
  memset(local_1024 + 4,0,0xffc);
  local_1224[0] = '\0';
  local_1224[1] = '\0';
  local_1224[2] = '\0';
  local_1224[3] = '\0';
  memset(local_1224 + 4,0,0x1fc);
  if (param_4 < &UNK_00040001) {
    puVar8 = (undefined *)0x40000;
    local_12ac = *(int *)(iVar7 + DAT_0006c3f4);
  }
  else {
    puVar8 = param_4 + 0x40000;
    iVar1 = FUN_0006cbf4(&local_12ac,puVar8);
    if (iVar1 == 0) {
      uVar4 = 0xffffffff;
      goto LAB_0006c3c0;
    }
  }
  iVar1 = local_12ac;
  iVar9 = DAT_0006c3f8 + 0x6c130;
  FUN_00069de8(1,DAT_0006c3fc + 0x6c138,iVar9,param_1[1]);
  pcVar6 = (char *)(iVar1 + 0x1000);
  if ((int)param_1[1] < 0) {
    FUN_00069de8(1,DAT_0006c418 + 0x6c258,iVar9);
    snprintf(pcVar6,(size_t)(puVar8 + -0x1000),*(char **)(iVar7 + DAT_0006c41c),param_3);
  }
  else {
    FUN_00069de8(1,DAT_0006c400 + 0x6c16c,iVar9);
    iVar9 = param_1[1];
    iVar10 = *(int *)(iVar7 + DAT_0006c404);
    iVar1 = strcmp(*(char **)(iVar10 + iVar9 * 0x10 + 4),(char *)(DAT_0006c408 + 0x6c184));
    if (((iVar1 == 0) &&
        (iVar1 = strcmp(*(char **)(iVar10 + iVar9 * 0x10),(char *)(DAT_0006c40c + 0x6c1ac)),
        iVar1 == 0)) && (iVar9 = param_1[5], iVar9 != 0)) {
      local_12a8 = iVar1;
      memset(auStack_12a4,0,0x7d);
      FUN_0009af0c(iVar9 + -1,&local_12a8);
      snprintf(local_1224,0x200,(char *)(DAT_0006c410 + 0x6c1fc),&local_12a8);
    }
    uVar4 = *(undefined4 *)(iVar10 + param_1[1] * 0x10 + 4);
    snprintf(pcVar6,(size_t)(puVar8 + -0x1000),*(char **)(iVar7 + DAT_0006c414),uVar4,
             *(undefined4 *)(iVar10 + param_1[1] * 0x10),param_2,uVar4,param_3);
  }
  sVar2 = strlen(pcVar6);
  snprintf(local_1024,0x1000,*(char **)(iVar7 + DAT_0006c420),sVar2,local_1224);
  sVar2 = strlen(local_1024);
  pcVar6 = pcVar6 + -sVar2;
  memcpy(pcVar6,local_1024,sVar2);
  pcVar3 = strstr(pcVar6,(char *)(DAT_0006c424 + 0x6c2dc));
  if ((pcVar3 == (char *)0x0) || (iVar7 = access((char *)(DAT_0006c438 + 0x6c33c),0), iVar7 == 0)) {
    iVar7 = DAT_0006c428 + 0x6c2f8;
    FUN_00069de8(1,DAT_0006c42c + 0x6c2fc,iVar7);
    FUN_00069de8(1,DAT_0006c430 + 0x6c314,pcVar6);
    FUN_00069de8(1,DAT_0006c434 + 0x6c328,iVar7);
  }
  printf((char *)(DAT_0006c440 + 0x6c35c),DAT_0006c43c + 0x6c358,0x287);
  sVar2 = strlen(pcVar6);
  iVar7 = FUN_0002bf74(*param_1,pcVar6,sVar2);
  if (iVar7 < 1) {
    uVar4 = 0xffffffff;
    FUN_00069de8(2,DAT_0006c444 + 0x6c394);
  }
  else {
    uVar4 = 0;
  }
  if (((undefined *)0x40000 < param_4) && (local_12ac != 0)) {
    FUN_0006cc64(&local_12ac);
  }
LAB_0006c3c0:
  if (local_24 != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



===== FUN_0006c518 @ 0006c518 =====

void FUN_0006c518(undefined4 param_1,undefined4 param_2,in_addr param_3,undefined4 param_4,
                 int *param_5)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 local_384;
  int local_380;
  in_addr_t local_37c;
  undefined4 local_378;
  undefined4 local_374;
  int local_370;
  int local_36c [5];
  int *local_358;
  char local_354 [48];
  char local_324 [256];
  char local_224 [256];
  char local_124 [256];
  int local_24;
  
  iVar12 = DAT_0006ca68 + 0x6c538;
  piVar11 = *(int **)(iVar12 + DAT_0006ca6c);
  local_324[0] = '\0';
  local_324[1] = '\0';
  local_324[2] = '\0';
  local_324[3] = '\0';
  local_24 = *piVar11;
  memset(local_324 + 4,0,0xfc);
  local_224[0] = '\0';
  local_224[1] = '\0';
  local_224[2] = '\0';
  local_224[3] = '\0';
  memset(local_224 + 4,0,0xfc);
  local_124[0] = '\0';
  local_124[1] = '\0';
  local_124[2] = '\0';
  local_124[3] = '\0';
  memset(local_124 + 4,0,0xfc);
  **(undefined4 **)(iVar12 + DAT_0006ca70) = 0;
  local_384 = param_2;
  if (*param_5 == 0) {
    local_36c[4] = 0;
    local_37c = param_3.s_addr;
  }
  else {
    piVar8 = param_5 + 5;
    piVar13 = local_36c;
    do {
      piVar9 = piVar8 + 2;
      iVar5 = piVar8[1];
      *piVar13 = *piVar8;
      piVar13[1] = iVar5;
      piVar13 = piVar13 + 2;
      piVar8 = piVar9;
    } while (piVar9 != param_5 + 9);
    local_354[0] = '\0';
    local_354[1] = '\0';
    local_354[2] = '\0';
    local_354[3] = '\0';
    memset(local_354 + 4,0,0x2b);
    inet_ntop(10,local_36c,local_354,0x2f);
    printf((char *)(DAT_0006ca78 + 0x6c630),DAT_0006ca74 + 0x6c636,0xed,local_354);
    local_36c[4] = 1;
  }
  local_358 = param_5;
  local_380 = -1;
  local_374 = 0;
  local_370 = 0;
  local_378 = param_1;
  if (*param_5 == 0) {
    pcVar2 = inet_ntoa(param_3);
    pcVar3 = (char *)acosNvramConfig_get(DAT_0006ca7c + 0x6c678);
    iVar5 = strcmp(pcVar2,pcVar3);
    bVar1 = false;
    if (iVar5 == 0) {
      pcVar2 = (char *)(DAT_0006ca80 + 0x6c698);
      goto LAB_0006c70c;
    }
  }
  else {
    local_354[0] = '\0';
    local_354[1] = '\0';
    local_354[2] = '\0';
    local_354[3] = '\0';
    memset(local_354 + 4,0,0x2b);
    inet_ntop(10,param_5 + 5,local_354,0x2f);
    printf((char *)(DAT_0006ca88 + 0x6c6e4),DAT_0006ca84 + 0x6c6ea,0x10a,local_354);
    pcVar2 = (char *)acosNvramConfig_get(DAT_0006ca8c + 0x6c6f0);
    iVar5 = strcmp(local_354,pcVar2);
    if (iVar5 != 0) {
      pcVar2 = (char *)acosNvramConfig_get(DAT_0006ca94 + 0x6c724);
      iVar5 = strcmp(local_354,pcVar2);
      if (iVar5 != 0) {
        pcVar2 = (char *)acosNvramConfig_get(DAT_0006ca98 + 0x6c744);
        iVar5 = strcmp(local_354,pcVar2);
        if (iVar5 != 0) {
          bVar1 = false;
          goto LAB_0006c75c;
        }
      }
    }
    pcVar2 = (char *)(DAT_0006ca90 + 0x6c710);
LAB_0006c70c:
    puts(pcVar2);
    bVar1 = true;
  }
LAB_0006c75c:
  iVar5 = FUN_0006be8c(param_1,local_324,local_224);
  if (iVar5 < 0) {
    iVar12 = DAT_0006ca9c + 0x6c784;
LAB_0006c95c:
    FUN_00069de8(2,iVar12);
    uVar7 = 0x191;
  }
  else {
    iVar5 = 0;
    FUN_00069de8(2,DAT_0006caa0 + 0x6c79c,local_324,local_224);
    while( true ) {
      iVar6 = *(int *)(iVar12 + DAT_0006caa4);
      pcVar2 = *(char **)(iVar6 + iVar5 * 0x10);
      if (pcVar2 == (char *)0x0) break;
      pcVar3 = *(char **)(iVar6 + iVar5 * 0x10 + 4);
      iVar4 = strcmp(local_224,pcVar3);
      if (((iVar4 == 0) && (iVar4 = strcmp(local_324,pcVar2), iVar4 == 0)) ||
         ((iVar4 = strcmp(local_224,pcVar2), iVar4 == 0 &&
          (iVar4 = strcmp(local_324,pcVar3), iVar4 == 0)))) goto LAB_0006c830;
      iVar5 = iVar5 + 1;
    }
    iVar5 = -1;
LAB_0006c830:
    FUN_00069de8(2,DAT_0006caa8 + 0x6c844,iVar5);
    if (iVar5 != -1) {
      local_380 = iVar5;
      iVar4 = local_370;
      if (!bVar1) {
        if ((*(uint *)(iVar6 + iVar5 * 0x10 + 0xc) & 2) == 0) {
          FUN_0006bcd8(param_1,DAT_0006cab0 + 0x6c89c,local_124,0x100);
          pcVar2 = strcasestr(local_124,(char *)(DAT_0006cab4 + 0x6c8ac));
          if (pcVar2 == (char *)0x0) goto LAB_0006c944;
          pcVar2 = pcVar2 + 8;
          pcVar3 = strchr(pcVar2,0x3b);
          iVar4 = DAT_0006cab8 + 0x6c8d4;
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
          }
          FUN_00069de8(2,iVar4,pcVar2);
          iVar4 = FUN_0009b3fc(pcVar2,param_3.s_addr,param_1,param_5);
          FUN_00069de8(2,DAT_0006cabc + 0x6c900,iVar4);
          if (iVar4 != -1) {
            if (iVar4 < 1) {
              iVar12 = DAT_0006cac4 + 0x6c944;
              goto LAB_0006c95c;
            }
            goto LAB_0006c96c;
          }
          FUN_00069de8(2,DAT_0006cac0 + 0x6c924);
          uVar7 = 0x1a7;
          goto LAB_0006ca34;
        }
LAB_0006c944:
        iVar4 = local_370;
        if ((*(uint *)(iVar6 + iVar5 * 0x10 + 0xc) & 2) == 0) {
          iVar12 = DAT_0006cac8 + 0x6c960;
          goto LAB_0006c95c;
        }
      }
LAB_0006c96c:
      local_370 = iVar4;
      iVar6 = iVar6 + iVar5 * 0x10;
      uVar10 = *(uint *)(iVar6 + 0xc);
      if (((uVar10 & 1) == 0) && ((uVar10 & 0x7c) != 0)) {
        pcVar3 = *(char **)(iVar12 + DAT_0006cacc);
        strncpy(pcVar3,(char *)(DAT_0006cad0 + 0x6c99c),0x13);
        pcVar2 = inet_ntoa(param_3);
        strncpy(pcVar3,pcVar2,0x13);
        FUN_00069de8(2,DAT_0006cad4 + 0x6c9d0,iVar5);
        uVar10 = (**(code **)(iVar6 + 8))(&local_384);
        FUN_00069de8(2,DAT_0006cad8 + 0x6c9e8,uVar10);
        if (uVar10 < 2) {
          iVar12 = acosNvramConfig_match(DAT_0006cae0 + 0x6ca14,DAT_0006cadc + 0x6ca10);
          if (iVar12 != 0) {
            FUN_000840e0();
          }
          FUN_000841a8();
          FUN_00084288(param_2);
          uVar7 = 0;
        }
        else {
          uVar7 = 0;
        }
        goto LAB_0006ca48;
      }
    }
    FUN_00069de8(2,DAT_0006caac + 0x6c85c);
    uVar7 = 0x194;
  }
LAB_0006ca34:
  uVar7 = FUN_0006c448(&local_384,DAT_0006cae4 + 0x6ca48,uVar7,0x40000);
LAB_0006ca48:
  if (local_24 != *piVar11) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



===== FUN_0006c448 @ 0006c448 =====

void FUN_0006c448(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char local_b4 [16];
  undefined4 local_a4;
  undefined1 auStack_a0 [124];
  int local_24;
  
  piVar1 = *(int **)(DAT_0006c508 + 0x6c468 + DAT_0006c50c);
  local_a4 = 0;
  local_24 = *piVar1;
  memset(auStack_a0,0,0x7c);
  local_b4[0] = '\0';
  local_b4[1] = '\0';
  local_b4[2] = '\0';
  local_b4[3] = '\0';
  local_b4[4] = '\0';
  local_b4[5] = '\0';
  local_b4[6] = '\0';
  local_b4[7] = '\0';
  local_b4[8] = '\0';
  local_b4[9] = '\0';
  local_b4[10] = '\0';
  local_b4[0xb] = '\0';
  local_b4[0xc] = '\0';
  local_b4[0xd] = '\0';
  local_b4[0xe] = '\0';
  local_b4[0xf] = '\0';
  snprintf(local_b4,0x10,(char *)(DAT_0006c510 + 0x6c4bc),param_3);
  FUN_000685f4(&local_a4,0x80,DAT_0006c514 + 0x6c4d4,local_b4);
  FUN_0006c070(param_1,param_2,&local_a4,param_4);
  if (local_24 != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



===== FUN_0006cae8 @ 0006cae8 =====

void FUN_0006cae8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  char local_b4 [16];
  undefined4 local_a4;
  undefined1 auStack_a0 [124];
  int local_24;
  
  piVar1 = *(int **)(DAT_0006cbdc + 0x6cb08 + DAT_0006cbe0);
  local_24 = *piVar1;
  local_a4 = 0;
  memset(auStack_a0,0,0x7c);
  local_b4[0] = '\0';
  local_b4[1] = '\0';
  local_b4[2] = '\0';
  local_b4[3] = '\0';
  local_b4[4] = '\0';
  local_b4[5] = '\0';
  local_b4[6] = '\0';
  local_b4[7] = '\0';
  local_b4[8] = '\0';
  local_b4[9] = '\0';
  local_b4[10] = '\0';
  local_b4[0xb] = '\0';
  local_b4[0xc] = '\0';
  local_b4[0xd] = '\0';
  local_b4[0xe] = '\0';
  local_b4[0xf] = '\0';
  snprintf(local_b4,0x10,(char *)(DAT_0006cbe4 + 0x6cb64),param_3);
  FUN_000685f4(&local_a4,0x80,DAT_0006cbe8 + 0x6cb78,local_b4);
  snprintf(local_b4,0x10,(char *)(DAT_0006cbec + 0x6cb90),param_4);
  FUN_000685f4(&local_a4,0x80,DAT_0006cbf0 + 0x6cba8,local_b4);
  FUN_0006c070(param_1,param_2,&local_a4,param_5);
  if (local_24 != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



===== FUN_0006bb6c @ 0006bb6c =====

void FUN_0006bb6c(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  char local_424 [1024];
  int local_24;
  
  piVar5 = *(int **)(DAT_0006bcbc + 0x6bb8c + DAT_0006bcc0);
  local_24 = *piVar5;
  local_424[0] = '\0';
  local_424[1] = '\0';
  local_424[2] = '\0';
  local_424[3] = '\0';
  memset(local_424 + 4,0,0x3fc);
  if (param_1 == (char *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    pcVar2 = strcasestr(param_1,(char *)(DAT_0006bcc4 + 0x6bbe0));
    if ((pcVar2 == (char *)0x0) &&
       (pcVar2 = strcasestr(param_1,(char *)(DAT_0006bcc8 + 0x6bc14)), pcVar2 == (char *)0x0)) {
      memset(local_424,0,0x400);
      FUN_000668c0(0x194,local_424,0);
      printf((char *)(DAT_0006bcd0 + 0x6bc58),DAT_0006bccc + 0x6bc54,0x55);
      sVar3 = strlen(local_424);
      iVar4 = FUN_0002bf74(param_3,local_424,sVar3,0);
      if (iVar4 == -1) {
        FUN_00069de8(2,DAT_0006bcd4 + 0x6bc94);
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = FUN_0006c518(param_2,param_3,param_4,param_5,param_6);
    }
  }
  if (local_24 == *piVar5) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}


