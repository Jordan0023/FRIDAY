
===== TARGET /tmp/uhttp_key_telnet =====
STRING 0001356f
REF depth=0 from=00012248 to=0001356f
REF depth=0 from=00010e78 to=0001356f

===== FUNCTION FUN_00012184 @ 00012184 =====

void FUN_00012184(undefined4 param_1)

{
  char cVar1;
  FILE *__stream;
  int __fd;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined1 auStack_1358 [4168];
  char local_310 [12];
  uint local_304;
  undefined4 local_300;
  undefined4 uStack_2fc;
  undefined4 uStack_2f8;
  undefined4 uStack_2f4;
  undefined1 auStack_2ec [88];
  char local_294 [128];
  undefined4 local_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  char acStack_204 [2];
  byte abStack_202 [14];
  char acStack_1f4 [16];
  char acStack_1e4 [200];
  undefined4 local_11c;
  undefined1 auStack_118 [252];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001245c + 0x12198 + DAT_00012460);
  local_294[0] = '\0';
  local_294[1] = '\0';
  local_294[2] = '\0';
  local_294[3] = '\0';
  memset(local_294 + 4,0,0x7c);
  local_310[0] = '\0';
  local_310[1] = '\0';
  local_310[2] = '\0';
  local_310[3] = '\0';
  local_310[4] = '\0';
  local_310[5] = '\0';
  local_310[6] = '\0';
  local_310[7] = '\0';
  local_310[8] = '\0';
  local_310[9] = '\0';
  local_310[10] = '\0';
  local_310[0xb] = '\0';
  local_304 = 0;
  local_300 = 0;
  memset(&uStack_2fc,0,0xd);
  local_11c = 0;
  memset(auStack_118,0,0xfc);
  __stream = fopen((char *)(DAT_00012468 + 0x12250),(char *)(DAT_00012464 + 0x1224c));
  if (__stream != (FILE *)0x0) {
    fgets(local_294,0x80,__stream);
    fclose(__stream);
  }
  __fd = socket(2,3,0xff);
  if (-1 < __fd) {
    strncpy((char *)&local_214,(char *)(DAT_00012474 + 0x122c4),0x10);
    iVar2 = ioctl(__fd,0x8927,&local_214);
    if (iVar2 == 0) {
      iVar2 = 0;
      pcVar4 = local_310;
      pbVar5 = abStack_202;
      do {
        iVar2 = iVar2 + 1;
        cVar1 = *(char *)(DAT_00012478 + 0x122f8 + (*pbVar5 & 0xf));
        *pcVar4 = *(char *)(DAT_00012478 + 0x122f8 + (uint)(*pbVar5 >> 4));
        pcVar4[1] = cVar1;
        pcVar4 = pcVar4 + 2;
        pbVar5 = pbVar5 + 1;
      } while (iVar2 != 6);
      local_304 = local_304 & 0xffffff00;
      close(__fd);
      memset(&local_214,0,0xf8);
      strncpy(acStack_204,local_310,0x10);
      strncpy(acStack_1f4,(char *)(DAT_0001247c + 0x12374),0x10);
      strncpy(acStack_1e4,local_294,0x88);
      FUN_00011c44(auStack_2ec);
      FUN_00011c7c(auStack_2ec,acStack_204,0x70);
      FUN_00011d3c(&local_300,auStack_2ec);
      local_214 = local_300;
      uStack_210 = uStack_2fc;
      uStack_20c = uStack_2f8;
      uStack_208 = uStack_2f4;
      uVar3 = __snprintf_chk(&local_11c,0x100,1,0x100,DAT_00012480 + 0x123f0,local_294);
      FUN_00011100(auStack_1358,&local_11c,uVar3);
      FUN_000120a8(auStack_1358,&local_214,param_1,0xf8);
      if (local_1c != **(int **)(DAT_00012484 + 0x12438 + DAT_00012460)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  __printf_chk(1,DAT_00012470 + 0x122a4,DAT_0001246c + 0x122a0);
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


===== TARGET AMBIT_TELNET_ENABLE =====
STRING 000135b1
REF depth=0 from=000123ec to=000135b1

===== FUNCTION FUN_00012184 @ 00012184 =====

void FUN_00012184(undefined4 param_1)

{
  char cVar1;
  FILE *__stream;
  int __fd;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined1 auStack_1358 [4168];
  char local_310 [12];
  uint local_304;
  undefined4 local_300;
  undefined4 uStack_2fc;
  undefined4 uStack_2f8;
  undefined4 uStack_2f4;
  undefined1 auStack_2ec [88];
  char local_294 [128];
  undefined4 local_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  char acStack_204 [2];
  byte abStack_202 [14];
  char acStack_1f4 [16];
  char acStack_1e4 [200];
  undefined4 local_11c;
  undefined1 auStack_118 [252];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001245c + 0x12198 + DAT_00012460);
  local_294[0] = '\0';
  local_294[1] = '\0';
  local_294[2] = '\0';
  local_294[3] = '\0';
  memset(local_294 + 4,0,0x7c);
  local_310[0] = '\0';
  local_310[1] = '\0';
  local_310[2] = '\0';
  local_310[3] = '\0';
  local_310[4] = '\0';
  local_310[5] = '\0';
  local_310[6] = '\0';
  local_310[7] = '\0';
  local_310[8] = '\0';
  local_310[9] = '\0';
  local_310[10] = '\0';
  local_310[0xb] = '\0';
  local_304 = 0;
  local_300 = 0;
  memset(&uStack_2fc,0,0xd);
  local_11c = 0;
  memset(auStack_118,0,0xfc);
  __stream = fopen((char *)(DAT_00012468 + 0x12250),(char *)(DAT_00012464 + 0x1224c));
  if (__stream != (FILE *)0x0) {
    fgets(local_294,0x80,__stream);
    fclose(__stream);
  }
  __fd = socket(2,3,0xff);
  if (-1 < __fd) {
    strncpy((char *)&local_214,(char *)(DAT_00012474 + 0x122c4),0x10);
    iVar2 = ioctl(__fd,0x8927,&local_214);
    if (iVar2 == 0) {
      iVar2 = 0;
      pcVar4 = local_310;
      pbVar5 = abStack_202;
      do {
        iVar2 = iVar2 + 1;
        cVar1 = *(char *)(DAT_00012478 + 0x122f8 + (*pbVar5 & 0xf));
        *pcVar4 = *(char *)(DAT_00012478 + 0x122f8 + (uint)(*pbVar5 >> 4));
        pcVar4[1] = cVar1;
        pcVar4 = pcVar4 + 2;
        pbVar5 = pbVar5 + 1;
      } while (iVar2 != 6);
      local_304 = local_304 & 0xffffff00;
      close(__fd);
      memset(&local_214,0,0xf8);
      strncpy(acStack_204,local_310,0x10);
      strncpy(acStack_1f4,(char *)(DAT_0001247c + 0x12374),0x10);
      strncpy(acStack_1e4,local_294,0x88);
      FUN_00011c44(auStack_2ec);
      FUN_00011c7c(auStack_2ec,acStack_204,0x70);
      FUN_00011d3c(&local_300,auStack_2ec);
      local_214 = local_300;
      uStack_210 = uStack_2fc;
      uStack_20c = uStack_2f8;
      uStack_208 = uStack_2f4;
      uVar3 = __snprintf_chk(&local_11c,0x100,1,0x100,DAT_00012480 + 0x123f0,local_294);
      FUN_00011100(auStack_1358,&local_11c,uVar3);
      FUN_000120a8(auStack_1358,&local_214,param_1,0xf8);
      if (local_1c != **(int **)(DAT_00012484 + 0x12438 + DAT_00012460)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  __printf_chk(1,DAT_00012470 + 0x122a4,DAT_0001246c + 0x122a0);
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


===== TARGET telnet_update.sh =====
STRING 00013609

===== TARGET utelnetd =====
STRING 00013648
