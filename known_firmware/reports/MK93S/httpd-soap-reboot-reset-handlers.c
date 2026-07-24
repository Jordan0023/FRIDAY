
===== ENTRY 0009ca48 =====
===== FUNCTION FUN_0009ca48 @ 0009ca48 =====

undefined4 FUN_0009ca48(undefined4 param_1)

{
  undefined4 uStack_114;
  undefined1 auStack_110 [252];
  int iStack_14;
  
  iStack_14 = *DAT_0009cac0;
  uStack_114 = 0;
  memset(auStack_110,0,0xfc);
  *DAT_0009cac4 = 1;
  FUN_00077240(param_1,&uStack_114,0,0x20000);
  if (iStack_14 != *DAT_0009cac0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


===== ENTRY 0009d4d4 =====
===== FUNCTION FUN_0009d4d4 @ 0009d4d4 =====

undefined4 FUN_0009d4d4(undefined4 param_1)

{
  undefined4 uStack_114;
  undefined1 auStack_110 [252];
  int iStack_14;
  
  iStack_14 = *DAT_0009d55c;
  uStack_114 = 0;
  memset(auStack_110,0,0xfc);
  system(DAT_0009d560);
  *DAT_0009d564 = 1;
  *DAT_0009d568 = 1;
  FUN_00077240(param_1,&uStack_114,0,0x20000);
  if (iStack_14 != *DAT_0009d55c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

