
===== ENTRY 00066fb4 =====
===== FUNCTION FUN_00066fb4 @ 00066fb4 =====

void FUN_00066fb4(uint param_1,void *param_2,size_t param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  void *__dest;
  size_t __n;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  timeval local_20d0;
  undefined1 auStack_20c8 [36];
  fd_set local_20a4;
  void *local_2024;
  undefined1 auStack_2020 [8188];
  int local_24;
  
  iVar6 = DAT_000672d0 + 0x67004;
  piVar3 = *(int **)(DAT_000672d4 + 0x67008 + DAT_000672cc);
  local_24 = *piVar3;
  memset(auStack_20c8,0,0x24);
  local_20a4.fds_bits[0] = *(__fd_mask *)(DAT_000672d8 + 0x67040);
  local_20a4.fds_bits[1] = *(__fd_mask *)(DAT_000672d8 + 0x67044);
  local_20a4.fds_bits[2] = *(__fd_mask *)(DAT_000672d8 + 0x67048);
  local_20a4.fds_bits[3] = *(__fd_mask *)(DAT_000672d8 + 0x6704c);
  _eval_daemon(&local_20a4,DAT_000672dc + 0x67060,0,0,0);
  iVar1 = acosNvramConfig_match(iVar6,DAT_000672e0 + 0x67070);
  if (((iVar1 != 0) || (iVar1 = acosNvramConfig_match(iVar6,DAT_000672e8 + 0x670ac), iVar1 != 0)) ||
     (iVar1 = acosNvramConfig_match(iVar6,DAT_000672ec + 0x670c4), iVar1 != 0)) {
    system((char *)(DAT_000672e4 + 0x6708c));
    wait_for_ppp_to_terminate();
    sleep(1);
  }
  sVar7 = param_4 + 0x10;
  system((char *)(DAT_000672f0 + 0x670dc));
  system((char *)(DAT_000672f4 + 0x670e8));
  system((char *)(DAT_000672f8 + 0x670f4));
  __dest = malloc(sVar7);
  if (__dest == (void *)0x0) {
    local_2024 = __dest;
    memset(auStack_2020,0,0x1fc);
    FUN_0006a044(2,DAT_00067300 + 0x67138,sVar7,DAT_000672fc + 0x67152);
    FUN_00066b1c(500,&local_2024,0);
    sVar7 = strlen((char *)&local_2024);
    send(param_1,&local_2024,sVar7,0);
  }
  else {
    if ((int)param_3 < (int)sVar7) {
      memcpy(__dest,param_2,param_3);
    }
    else {
      param_3 = 0;
    }
    uVar4 = param_1 + 0x1f;
    if (-1 < (int)param_1) {
      uVar4 = param_1;
    }
    uVar5 = param_1 & 0x8000001f;
    if ((int)uVar5 < 0) {
      uVar5 = ~(~((uVar5 - 1) * 0x8000000) >> 0x1b) + 1;
    }
    while( true ) {
      local_20d0.tv_sec = 2;
      local_20d0.tv_usec = 0;
      iVar1 = 0;
      do {
        local_20a4.fds_bits[iVar1] = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x20);
      local_20a4.fds_bits[(int)uVar4 >> 5] =
           local_20a4.fds_bits[(int)uVar4 >> 5] | 1 << (uVar5 & 0xff);
      iVar1 = select(param_1 + 1,&local_20a4,(fd_set *)0x0,(fd_set *)0x0,&local_20d0);
      if (iVar1 < 0) break;
      if (iVar1 == 0) {
        FUN_00066c50(__dest,param_1,param_5,param_3,auStack_20c8,0);
        free(__dest);
        uVar2 = 0;
        goto LAB_000672a0;
      }
      __n = recv(param_1,&local_2024,0x1fff,0);
      if ((int)__n < 0) break;
      if ((int)(param_3 + __n) < (int)sVar7) {
        memcpy((void *)((int)__dest + param_3),&local_2024,__n);
        param_3 = param_3 + __n;
      }
    }
    free(__dest);
  }
  uVar2 = 0xffffffff;
LAB_000672a0:
  if (local_24 == *piVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

