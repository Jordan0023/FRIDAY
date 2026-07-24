STRING 000868ae [%s(%d)]:%s(%d) get master key ...

REF 0004cb30 owner=FUN_0004c684
REF 0004cb90 owner=FUN_0004c684
CALLER_REF target=FUN_0004c684 from=00062574 owner=FUN_0006221c

===== FUN_0004c684 @ 0004c684 =====

undefined4
FUN_0004c684(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 *param_6,
            undefined4 param_7)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *__s;
  int *__s_00;
  ssize_t sVar6;
  int iVar7;
  int iVar8;
  size_t sVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *__dest;
  size_t __n;
  undefined4 uVar12;
  uint local_103c;
  int local_1038;
  uint local_1034;
  uint local_1030;
  int local_102c;
  uint uStack_1028;
  uint uStack_1024;
  int aiStack_1020 [3];
  undefined1 auStack_1014 [4076];
  
  memset(&local_102c,0,0x1002);
  local_103c = 0;
  uVar10 = param_4 << 0x18 | (param_4 >> 8 & 0xff) << 0x10 | (param_4 >> 0x10 & 0xff) << 8 |
           param_4 >> 0x18;
  pcVar1 = (char *)FUN_00049808(DAT_0004d5f0 + 0x4c704);
  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d5f4 + 0x4c710));
  if (iVar2 == 0) {
    cprintf(DAT_0004d5fc + 0x4c738,DAT_0004d5f8 + 0x4c734,0x2425,
            param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 | (param_3 >> 0x10 & 0xff) << 8 |
            param_3 >> 0x18,uVar10);
  }
  pcVar1 = (char *)FUN_00049808(DAT_0004d600 + 0x4c744);
  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d604 + 0x4c750));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_0004d60c + 0x4c788,0,1,0,DAT_0004d610 + 0x4c790,DAT_0004d608 + 0x4c77c,0x2425
                 ,param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 | (param_3 >> 0x10 & 0xff) << 8 |
                  param_3 >> 0x18,uVar10);
  }
  pcVar1 = (char *)FUN_00049808(DAT_0004d614 + 0x4c7a4);
  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d618 + 0x4c7b0));
  if (iVar2 == 0) {
    cprintf(DAT_0004d620 + 0x4c7d0,DAT_0004d61c + 0x4c7cc,0x2426);
  }
  pcVar1 = (char *)FUN_00049808(DAT_0004d624 + 0x4c7dc);
  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d628 + 0x4c7e8));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_0004d630 + 0x4c818,0,1,0,DAT_0004d634 + 0x4c81c,DAT_0004d62c + 0x4c80c,0x2426
                );
  }
  if ((uVar10 == 0) ||
     (uVar11 = param_5 << 0x18 | (param_5 >> 8 & 0xff) << 0x10 | (param_5 >> 0x10 & 0xff) << 8 |
               param_5 >> 0x18, uVar11 == 0)) {
    pcVar1 = (char *)FUN_00049808(DAT_0004d638 + 0x4c844);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d63c + 0x4c850));
    if (iVar2 == 0) {
      cprintf(DAT_0004d644 + 0x4c870,DAT_0004d640 + 0x4c86c,0x242a);
    }
    pcVar1 = (char *)FUN_00049808(DAT_0004d648 + 0x4c87c);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d64c + 0x4c888));
    if (iVar2 == 0) {
      uVar12 = 0x242a;
      iVar7 = DAT_0004d650 + 0x4c8b4;
      iVar2 = DAT_0004d654 + 0x4c8c0;
      iVar8 = DAT_0004d658 + 0x4c8c8;
      goto LAB_0004de80;
    }
  }
  else {
    uVar3 = FUN_0001a720(0,param_7,uVar10);
    if (uVar3 == uVar11) {
      memset(&local_102c,0,0x1002);
      uVar10 = rsa_decrypt(param_7,uVar10,*(undefined4 *)(param_2 + 0x4c),
                           *(undefined4 *)(param_2 + 0x50),&local_102c,0x1002,0);
      if (uVar10 == 0) {
        pcVar1 = (char *)FUN_00049808(DAT_0004d680 + 0x4c9e0);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d684 + 0x4c9ec));
        if (iVar2 == 0) {
          cprintf(DAT_0004d68c + 0x4ca0c,DAT_0004d688 + 0x4ca08,0x2438);
        }
        pcVar1 = (char *)FUN_00049808(DAT_0004d690 + 0x4ca18);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d694 + 0x4ca24));
        if (iVar2 == 0) {
          uVar12 = 0x2438;
          iVar7 = DAT_0004d698 + 0x4ca48;
          iVar2 = DAT_0004d69c + 0x4ca54;
          iVar8 = DAT_0004d6a0 + 0x4ca5c;
          goto LAB_0004de80;
        }
      }
      else {
        pcVar1 = (char *)FUN_00049808(DAT_0004d6a4 + 0x4ca70);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d6a8 + 0x4ca7c));
        if (iVar2 == 0) {
          cprintf(DAT_0004d6b0 + 0x4ca9c,DAT_0004d6ac + 0x4ca98,0x243c);
        }
        pcVar1 = (char *)FUN_00049808(DAT_0004d6b4 + 0x4caa8);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d6b8 + 0x4cab4));
        if (iVar2 == 0) {
          asusdebuglog(6,DAT_0004d6c0 + 0x4cae4,0,1,0,DAT_0004d6c4 + 0x4cae8,DAT_0004d6bc + 0x4cad8,
                       0x243c);
        }
        pcVar1 = (char *)FUN_00049808(DAT_0004d6c8 + 0x4cafc);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d6cc + 0x4cb08));
        if (iVar2 == 0) {
          uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
          cprintf(DAT_0004d6d4 + 0x4cb38,DAT_0004d6d0 + 0x4cb2c,0x243d,uVar12,param_1);
        }
        pcVar1 = (char *)FUN_00049808(DAT_0004d6d8 + 0x4cb44);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d6dc + 0x4cb50));
        if (iVar2 == 0) {
          uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
          asusdebuglog(6,DAT_0004d6e4 + 0x4cb88,0,1,0,DAT_0004d6e8 + 0x4cb90,DAT_0004d6e0 + 0x4cb7c,
                       0x243d,uVar12,param_1);
        }
        if (uVar10 < 0xc) {
          pcVar1 = (char *)FUN_00049808(DAT_0004d6ec + 0x4cbb8);
          iVar2 = strcmp(pcVar1,(char *)(DAT_0004d6f0 + 0x4cbc4));
          if (iVar2 == 0) {
            cprintf(DAT_0004d6f8 + 0x4cbe4,DAT_0004d6f4 + 0x4cbe0,0x2440);
          }
          pcVar1 = (char *)FUN_00049808(DAT_0004d6fc + 0x4cbf0);
          iVar2 = strcmp(pcVar1,(char *)(DAT_0004d700 + 0x4cbfc));
          if (iVar2 == 0) {
            uVar12 = 0x2440;
            iVar7 = DAT_0004d704 + 0x4cc20;
            iVar2 = DAT_0004d708 + 0x4cc2c;
            iVar8 = DAT_0004d70c + 0x4cc34;
            goto LAB_0004de80;
          }
        }
        else {
          local_1038 = local_102c;
          local_1034 = uStack_1028;
          local_1030 = uStack_1024;
          uVar11 = uStack_1028 << 0x18 | (uStack_1028 >> 8 & 0xff) << 0x10 |
                   (uStack_1028 >> 0x10 & 0xff) << 8 | uStack_1028 >> 0x18;
          if ((uVar11 == 0) ||
             (uVar3 = uStack_1024 << 0x18 | (uStack_1024 >> 8 & 0xff) << 0x10 |
                      (uStack_1024 >> 0x10 & 0xff) << 8 | uStack_1024 >> 0x18, uVar3 == 0)) {
            pcVar1 = (char *)FUN_00049808(DAT_0004d710 + 0x4cc78);
            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d714 + 0x4cc84));
            if (iVar2 == 0) {
              cprintf(DAT_0004d71c + 0x4cca4,DAT_0004d718 + 0x4cca0,0x2449);
            }
            pcVar1 = (char *)FUN_00049808(DAT_0004d720 + 0x4ccb0);
            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d724 + 0x4ccbc));
            if (iVar2 == 0) {
              uVar12 = 0x2449;
              iVar7 = DAT_0004d728 + 0x4cce0;
              iVar2 = DAT_0004d72c + 0x4ccec;
              iVar8 = DAT_0004d730 + 0x4ccf4;
              goto LAB_0004de80;
            }
          }
          else if (local_102c == 0x1000000) {
            if (uVar10 - 0xc < uVar11) {
              pcVar1 = (char *)FUN_00049808(DAT_0004d758 + 0x4cdb0);
              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d75c + 0x4cdbc));
              if (iVar2 == 0) {
                cprintf(DAT_0004d764 + 0x4cddc,DAT_0004d760 + 0x4cdd8,0x2457);
              }
              pcVar1 = (char *)FUN_00049808(DAT_0004d768 + 0x4cde8);
              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d76c + 0x4cdf4));
              if (iVar2 == 0) {
                uVar12 = 0x2457;
                iVar7 = DAT_0004d770 + 0x4ce18;
                iVar2 = DAT_0004d774 + 0x4ce24;
                iVar8 = DAT_0004d778 + 0x4ce2c;
                goto LAB_0004de80;
              }
            }
            else {
              uVar4 = FUN_0001a720(0,aiStack_1020,uVar11);
              if (uVar4 == uVar3) {
                param_6[3] = uVar11;
                pvVar5 = malloc(uVar11);
                *param_6 = pvVar5;
                if (pvVar5 == (void *)0x0) {
                  pcVar1 = (char *)FUN_00049808(DAT_0004d9bc + 0x4df44);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d9c0 + 0x4df50));
                  if (iVar2 == 0) {
                    cprintf(DAT_0004d9c8 + 0x4df70,DAT_0004d9c4 + 0x4df6c,0x2465);
                  }
                  pcVar1 = (char *)FUN_00049808(DAT_0004d9cc + 0x4df7c);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d9d0 + 0x4df88));
                  if (iVar2 == 0) {
                    uVar12 = 0x2465;
                    iVar7 = DAT_0004d9d4 + 0x4dfac;
                    iVar2 = DAT_0004d9d8 + 0x4dfb8;
                    iVar8 = DAT_0004d9dc + 0x4dfc0;
                    goto LAB_0004de80;
                  }
                }
                else {
                  memset(pvVar5,0,uVar11);
                  memset(pvVar5,0,uVar11);
                  memcpy(pvVar5,aiStack_1020,uVar11);
                  uVar10 = (uVar10 - 0xc) - uVar11;
                  pcVar1 = (char *)FUN_00049808(DAT_0004d7a0 + 0x4cf3c);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7a4 + 0x4cf48));
                  if (iVar2 == 0) {
                    cprintf(DAT_0004d7ac + 0x4cf68,DAT_0004d7a8 + 0x4cf64,0x246d);
                  }
                  pcVar1 = (char *)FUN_00049808(DAT_0004d7b0 + 0x4cf74);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7b4 + 0x4cf80));
                  if (iVar2 == 0) {
                    asusdebuglog(6,DAT_0004d7bc + 0x4cfb0,0,1,0,DAT_0004d7c0 + 0x4cfb4,
                                 DAT_0004d7b8 + 0x4cfa4,0x246d);
                  }
                  pcVar1 = (char *)FUN_00049808(DAT_0004d7c4 + 0x4cfc8);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7c8 + 0x4cfd4));
                  if (iVar2 == 0) {
                    uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                          (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
                    cprintf(DAT_0004d7d0 + 0x4d004,DAT_0004d7cc + 0x4cff8,0x246f,uVar12,param_1);
                  }
                  pcVar1 = (char *)FUN_00049808(DAT_0004d7d4 + 0x4d010);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7d8 + 0x4d01c));
                  if (iVar2 == 0) {
                    uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                          (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
                    asusdebuglog(6,DAT_0004d7e0 + 0x4d054,0,1,0,DAT_0004d7e4 + 0x4d05c,
                                 DAT_0004d7dc + 0x4d048,0x246f,uVar12,param_1);
                  }
                  if (uVar10 < 0xc) {
                    pcVar1 = (char *)FUN_00049808(DAT_0004d7e8 + 0x4d084);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7ec + 0x4d090));
                    if (iVar2 == 0) {
                      cprintf(DAT_0004d7f4 + 0x4d0b0,DAT_0004d7f0 + 0x4d0ac,0x2472);
                    }
                    pcVar1 = (char *)FUN_00049808(DAT_0004d7f8 + 0x4d0bc);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d7fc + 0x4d0c8));
                    if (iVar2 == 0) {
                      uVar12 = 0x2472;
                      iVar7 = DAT_0004d800 + 0x4d0ec;
                      iVar2 = DAT_0004d804 + 0x4d0f8;
                      iVar8 = DAT_0004d808 + 0x4d100;
                      goto LAB_0004de80;
                    }
                  }
                  else {
                    local_1038 = *(int *)((int)aiStack_1020 + uVar11);
                    local_1034 = *(uint *)((int)aiStack_1020 + uVar11 + 4);
                    local_1030 = *(uint *)((int)aiStack_1020 + uVar11 + 8);
                    uVar3 = local_1034 << 0x18 | (local_1034 >> 8 & 0xff) << 0x10 |
                            (local_1034 >> 0x10 & 0xff) << 8 | local_1034 >> 0x18;
                    if ((uVar3 == 0) ||
                       (uVar4 = local_1030 << 0x18 | (local_1030 >> 8 & 0xff) << 0x10 |
                                (local_1030 >> 0x10 & 0xff) << 8 | local_1030 >> 0x18, uVar4 == 0))
                    {
                      pcVar1 = (char *)FUN_00049808(DAT_0004d80c + 0x4d154);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d810 + 0x4d160));
                      if (iVar2 == 0) {
                        cprintf(DAT_0004d818 + 0x4d180,DAT_0004d814 + 0x4d17c,0x2479);
                      }
                      pcVar1 = (char *)FUN_00049808(DAT_0004d81c + 0x4d18c);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d820 + 0x4d198));
                      if (iVar2 == 0) {
                        uVar12 = 0x2479;
                        iVar7 = DAT_0004d824 + 0x4d1bc;
                        iVar2 = DAT_0004d828 + 0x4d1c8;
                        iVar8 = DAT_0004d82c + 0x4d1d0;
                        goto LAB_0004de80;
                      }
                    }
                    else if (local_1038 == 0x3000000) {
                      if (uVar10 - 0xc < uVar3) {
                        pcVar1 = (char *)FUN_00049808(DAT_0004d854 + 0x4d28c);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d858 + 0x4d298));
                        if (iVar2 == 0) {
                          cprintf(DAT_0004d860 + 0x4d2b8,DAT_0004d85c + 0x4d2b4,0x2486);
                        }
                        pcVar1 = (char *)FUN_00049808(DAT_0004d864 + 0x4d2c4);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_0004d868 + 0x4d2d0));
                        if (iVar2 == 0) {
                          uVar12 = 0x2486;
                          iVar7 = DAT_0004d86c + 0x4d2f4;
                          iVar2 = DAT_0004d870 + 0x4d300;
                          iVar8 = DAT_0004d874 + 0x4d308;
                          goto LAB_0004de80;
                        }
                      }
                      else {
                        uVar10 = FUN_0001a720(0,auStack_1014 + uVar11,uVar3);
                        if (uVar4 == uVar10) {
                          param_6[5] = uVar3;
                          pvVar5 = malloc(uVar3);
                          param_6[2] = pvVar5;
                          if (pvVar5 == (void *)0x0) {
                            pcVar1 = (char *)FUN_00049808(DAT_0004d9e0 + 0x4dfd4);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d9e4 + 0x4dfe0));
                            if (iVar2 == 0) {
                              cprintf(DAT_0004d9ec + 0x4e000,DAT_0004d9e8 + 0x4dffc,0x2494);
                            }
                            pcVar1 = (char *)FUN_00049808(DAT_0004d9f0 + 0x4e00c);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d9f4 + 0x4e018));
                            if (iVar2 == 0) {
                              uVar12 = 0x2494;
                              iVar7 = DAT_0004d9f8 + 0x4e03c;
                              iVar2 = DAT_0004d9fc + 0x4e048;
                              iVar8 = DAT_0004da00 + 0x4e050;
                              goto LAB_0004de80;
                            }
                          }
                          else {
                            memset(pvVar5,0,uVar3);
                            memset(pvVar5,0,uVar3);
                            memcpy(pvVar5,auStack_1014 + uVar11,uVar3);
                            pcVar1 = (char *)FUN_00049808(DAT_0004d89c + 0x4d418);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8a0 + 0x4d424));
                            if (iVar2 == 0) {
                              cprintf(DAT_0004d8a8 + 0x4d444,DAT_0004d8a4 + 0x4d440,0x249b);
                            }
                            pcVar1 = (char *)FUN_00049808(DAT_0004d8ac + 0x4d450);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8b0 + 0x4d45c));
                            if (iVar2 == 0) {
                              asusdebuglog(6,DAT_0004d8b8 + 0x4d48c,0,1,0,DAT_0004d8bc + 0x4d490,
                                           DAT_0004d8b4 + 0x4d480,0x249b);
                            }
                            pcVar1 = (char *)FUN_00049808(DAT_0004d8c0 + 0x4d4a4);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8c4 + 0x4d4b0));
                            if (iVar2 == 0) {
                              uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10
                                                    | (param_3 >> 0x10 & 0xff) << 8 |
                                                    param_3 >> 0x18);
                              cprintf(DAT_0004d8cc + 0x4d4e0,DAT_0004d8c8 + 0x4d4d4,0x249d,uVar12,
                                      param_1);
                            }
                            pcVar1 = (char *)FUN_00049808(DAT_0004d8d0 + 0x4d4ec);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8d4 + 0x4d4f8));
                            if (iVar2 == 0) {
                              uVar12 = FUN_000497c4(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10
                                                    | (param_3 >> 0x10 & 0xff) << 8 |
                                                    param_3 >> 0x18);
                              asusdebuglog(6,DAT_0004d8dc + 0x4d530,0,1,0,DAT_0004d8e0 + 0x4d538,
                                           DAT_0004d8d8 + 0x4d524,0x249d,uVar12,param_1);
                            }
                            iVar2 = gen_rand(param_6 + 4);
                            param_6[1] = iVar2;
                            if (iVar2 == 0) {
                              pcVar1 = (char *)FUN_00049808(DAT_0004d8e4 + 0x4d56c);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8e8 + 0x4d578));
                              if (iVar2 == 0) {
                                cprintf(DAT_0004d8f0 + 0x4d598,DAT_0004d8ec + 0x4d594,0x24a1);
                              }
                              pcVar1 = (char *)FUN_00049808(DAT_0004d8f4 + 0x4d5a4);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d8f8 + 0x4d5b0));
                              if (iVar2 == 0) {
                                uVar12 = 0x24a1;
                                iVar7 = DAT_0004d8fc + 0x4d5d4;
                                iVar2 = DAT_0004d900 + 0x4d5e0;
                                iVar8 = DAT_0004d904 + 0x4d5e8;
                                goto LAB_0004de80;
                              }
                            }
                            else {
                              pcVar1 = (char *)FUN_00049808(DAT_0004d908 + 0x4da58);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d90c + 0x4da64));
                              if (iVar2 == 0) {
                                cprintf(DAT_0004d914 + 0x4da84,DAT_0004d910 + 0x4da80,0x24a4);
                              }
                              pcVar1 = (char *)FUN_00049808(DAT_0004d918 + 0x4da90);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d91c + 0x4da9c));
                              if (iVar2 == 0) {
                                asusdebuglog(6,DAT_0004d924 + 0x4dacc,0,1,0,DAT_0004d928 + 0x4dad0,
                                             DAT_0004d920 + 0x4dac0,0x24a4);
                              }
                              pcVar1 = (char *)FUN_00049808(DAT_0004d92c + 0x4dae4);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d930 + 0x4daf0));
                              if (iVar2 == 0) {
                                uVar12 = FUN_000497c4(param_3 << 0x18 |
                                                      (param_3 >> 8 & 0xff) << 0x10 |
                                                      (param_3 >> 0x10 & 0xff) << 8 |
                                                      param_3 >> 0x18);
                                cprintf(DAT_0004d938 + 0x4db20,DAT_0004d934 + 0x4db14,0x24a5,uVar12,
                                        param_1);
                              }
                              pcVar1 = (char *)FUN_00049808(DAT_0004d93c + 0x4db2c);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0004d940 + 0x4db38));
                              if (iVar2 == 0) {
                                uVar12 = FUN_000497c4(param_3 << 0x18 |
                                                      (param_3 >> 8 & 0xff) << 0x10 |
                                                      (param_3 >> 0x10 & 0xff) << 8 |
                                                      param_3 >> 0x18);
                                asusdebuglog(6,DAT_0004d948 + 0x4db70,0,1,0,DAT_0004d94c + 0x4db78,
                                             DAT_0004d944 + 0x4db64,0x24a5,uVar12,param_1);
                              }
                              uVar10 = param_6[4];
                              sVar9 = uVar10 + param_6[5] + 0x18;
                              __s = malloc(sVar9);
                              if (__s == (undefined4 *)0x0) {
                                pcVar1 = (char *)FUN_00049808(DAT_0004da04 + 0x4e064);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_0004da08 + 0x4e070));
                                if (iVar2 == 0) {
                                  cprintf(DAT_0004da10 + 0x4e090,DAT_0004da0c + 0x4e08c,0x24a9);
                                }
                                pcVar1 = (char *)FUN_00049808(DAT_0004da14 + 0x4e09c);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_0004da18 + 0x4e0a8));
                                if (iVar2 == 0) {
                                  uVar12 = 0x24a9;
                                  iVar7 = DAT_0004da1c + 0x4e0cc;
                                  iVar2 = DAT_0004da20 + 0x4e0d8;
                                  iVar8 = DAT_0004da24 + 0x4e0e0;
                                  goto LAB_0004de80;
                                }
                              }
                              else {
                                memset(__s,0,sVar9);
                                memset(__s,0,sVar9);
                                local_1030 = 0;
                                local_1038 = 0x2000000;
                                local_1034 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                                             (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18;
                                uVar10 = FUN_0001a720(0,param_6[1],uVar10);
                                sVar9 = param_6[4];
                                __dest = __s + 3;
                                local_1030 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                                             (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18;
                                *__s = local_1038;
                                __s[1] = local_1034;
                                __s[2] = local_1030;
                                memcpy(__dest,(void *)param_6[1],sVar9);
                                local_1038 = 0x3000000;
                                uVar10 = param_6[5];
                                local_1034 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                                             (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18;
                                local_1030 = 0;
                                uVar10 = FUN_0001a720(0,param_6[2]);
                                local_1030 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                                             (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18;
                                *(int *)((int)__dest + sVar9) = local_1038;
                                __n = param_6[5];
                                *(uint *)((int)__dest + sVar9 + 4) = local_1034;
                                *(uint *)((int)__dest + sVar9 + 8) = local_1030;
                                memcpy((void *)((int)__dest + sVar9 + 0xc),(void *)param_6[2],__n);
                                pvVar5 = (void *)aes_encrypt(*param_6,__s,__n + param_6[4] + 0x18,
                                                             &local_103c);
                                uVar10 = local_103c;
                                if (pvVar5 == (void *)0x0) {
                                  free(__s);
                                  pcVar1 = (char *)FUN_00049808(DAT_0004d950 + 0x4dcc8);
                                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d954 + 0x4dcd4));
                                  if (iVar2 == 0) {
                                    cprintf(DAT_0004d95c + 0x4dcf4,DAT_0004d958 + 0x4dcf0,0x24c6);
                                  }
                                  pcVar1 = (char *)FUN_00049808(DAT_0004d960 + 0x4dd00);
                                  iVar2 = strcmp(pcVar1,(char *)(DAT_0004d964 + 0x4dd0c));
                                  if (iVar2 == 0) {
                                    uVar12 = 0x24c6;
                                    iVar7 = DAT_0004d968 + 0x4dd30;
                                    iVar2 = DAT_0004d96c + 0x4dd3c;
                                    iVar8 = DAT_0004d970 + 0x4dd44;
                                    goto LAB_0004de80;
                                  }
                                }
                                else {
                                  sVar9 = local_103c + 0xc;
                                  __s_00 = malloc(sVar9);
                                  if (__s_00 == (int *)0x0) {
                                    free(pvVar5);
                                    free(__s);
                                    pcVar1 = (char *)FUN_00049808(DAT_0004da28 + 0x4e104);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004da2c + 0x4e110));
                                    if (iVar2 == 0) {
                                      cprintf(DAT_0004da34 + 0x4e130,DAT_0004da30 + 0x4e12c,0x24cf);
                                    }
                                    pcVar1 = (char *)FUN_00049808(DAT_0004da38 + 0x4e13c);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004da3c + 0x4e148));
                                    if (iVar2 == 0) {
                                      uVar12 = 0x24cf;
                                      iVar7 = DAT_0004da40 + 0x4e16c;
                                      iVar2 = DAT_0004da44 + 0x4e178;
                                      iVar8 = DAT_0004da48 + 0x4e180;
                                      goto LAB_0004de80;
                                    }
                                  }
                                  else {
                                    memset(__s_00,0,sVar9);
                                    local_1030 = 0;
                                    local_1038 = 0x4000000;
                                    local_1034 = uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 |
                                                 (uVar10 >> 0x10 & 0xff) << 8 | uVar10 >> 0x18;
                                    uVar11 = FUN_0001a720(0,pvVar5,uVar10);
                                    uVar10 = local_103c;
                                    local_1030 = uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 |
                                                 (uVar11 >> 0x10 & 0xff) << 8 | uVar11 >> 0x18;
                                    *__s_00 = local_1038;
                                    __s_00[1] = local_1034;
                                    __s_00[2] = local_1030;
                                    memcpy(__s_00 + 3,pvVar5,local_103c);
                                    sVar6 = write(param_1,__s_00,uVar10 + 0xc);
                                    if (sVar6 == local_103c + 0xc) {
                                      free(__s_00);
                                      free(__s);
                                      free(pvVar5);
                                      pcVar1 = (char *)FUN_00049808(DAT_0004d998 + 0x4deb0);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d99c + 0x4debc));
                                      if (iVar2 == 0) {
                                        cprintf(DAT_0004d9a4 + 0x4dedc,DAT_0004d9a0 + 0x4ded8,0x24e4
                                               );
                                      }
                                      pcVar1 = (char *)FUN_00049808(DAT_0004d9a8 + 0x4dee8);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d9ac + 0x4def4));
                                      if (iVar2 == 0) {
                                        asusdebuglog(6,DAT_0004d9b4 + 0x4df24,0,1,0,
                                                     DAT_0004d9b8 + 0x4df28,DAT_0004d9b0 + 0x4df18,
                                                     0x24e4);
                                      }
                                      return 1;
                                    }
                                    free(pvVar5);
                                    free(__s_00);
                                    pcVar1 = (char *)FUN_00049808(DAT_0004d974 + 0x4de00);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d978 + 0x4de0c));
                                    if (iVar2 == 0) {
                                      cprintf(DAT_0004d980 + 0x4de2c,DAT_0004d97c + 0x4de28,0x24dd);
                                    }
                                    pcVar1 = (char *)FUN_00049808(DAT_0004d984 + 0x4de38);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_0004d988 + 0x4de44));
                                    if (iVar2 == 0) {
                                      uVar12 = 0x24dd;
                                      iVar7 = DAT_0004d98c + 0x4de68;
                                      iVar2 = DAT_0004d990 + 0x4de74;
                                      iVar8 = DAT_0004d994 + 0x4de7c;
LAB_0004de80:
                                      asusdebuglog(6,iVar2,0,1,0,iVar8,iVar7,uVar12);
                                      return 0;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else {
                          pcVar1 = (char *)FUN_00049808(DAT_0004d878 + 0x4d340);
                          iVar2 = strcmp(pcVar1,(char *)(DAT_0004d87c + 0x4d34c));
                          if (iVar2 == 0) {
                            cprintf(DAT_0004d884 + 0x4d36c,DAT_0004d880 + 0x4d368,0x248c);
                          }
                          pcVar1 = (char *)FUN_00049808(DAT_0004d888 + 0x4d378);
                          iVar2 = strcmp(pcVar1,(char *)(DAT_0004d88c + 0x4d384));
                          if (iVar2 == 0) {
                            uVar12 = 0x248c;
                            iVar7 = DAT_0004d890 + 0x4d3a8;
                            iVar2 = DAT_0004d894 + 0x4d3b4;
                            iVar8 = DAT_0004d898 + 0x4d3bc;
                            goto LAB_0004de80;
                          }
                        }
                      }
                    }
                    else {
                      pcVar1 = (char *)FUN_00049808(DAT_0004d830 + 0x4d1f0);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d834 + 0x4d1fc));
                      if (iVar2 == 0) {
                        cprintf(DAT_0004d83c + 0x4d21c,DAT_0004d838 + 0x4d218,0x2480);
                      }
                      pcVar1 = (char *)FUN_00049808(DAT_0004d840 + 0x4d228);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d844 + 0x4d234));
                      if (iVar2 == 0) {
                        uVar12 = 0x2480;
                        iVar7 = DAT_0004d848 + 0x4d258;
                        iVar2 = DAT_0004d84c + 0x4d264;
                        iVar8 = DAT_0004d850 + 0x4d26c;
                        goto LAB_0004de80;
                      }
                    }
                  }
                }
              }
              else {
                pcVar1 = (char *)FUN_00049808(DAT_0004d77c + 0x4ce60);
                iVar2 = strcmp(pcVar1,(char *)(DAT_0004d780 + 0x4ce6c));
                if (iVar2 == 0) {
                  cprintf(DAT_0004d788 + 0x4ce8c,DAT_0004d784 + 0x4ce88,0x245d);
                }
                pcVar1 = (char *)FUN_00049808(DAT_0004d78c + 0x4ce98);
                iVar2 = strcmp(pcVar1,(char *)(DAT_0004d790 + 0x4cea4));
                if (iVar2 == 0) {
                  uVar12 = 0x245d;
                  iVar7 = DAT_0004d794 + 0x4cec8;
                  iVar2 = DAT_0004d798 + 0x4ced4;
                  iVar8 = DAT_0004d79c + 0x4cedc;
                  goto LAB_0004de80;
                }
              }
            }
          }
          else {
            pcVar1 = (char *)FUN_00049808(DAT_0004d734 + 0x4cd14);
            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d738 + 0x4cd20));
            if (iVar2 == 0) {
              cprintf(DAT_0004d740 + 0x4cd40,DAT_0004d73c + 0x4cd3c,0x2451);
            }
            pcVar1 = (char *)FUN_00049808(DAT_0004d744 + 0x4cd4c);
            iVar2 = strcmp(pcVar1,(char *)(DAT_0004d748 + 0x4cd58));
            if (iVar2 == 0) {
              uVar12 = 0x2451;
              iVar7 = DAT_0004d74c + 0x4cd7c;
              iVar2 = DAT_0004d750 + 0x4cd88;
              iVar8 = DAT_0004d754 + 0x4cd90;
              goto LAB_0004de80;
            }
          }
        }
      }
    }
    else {
      pcVar1 = (char *)FUN_00049808(DAT_0004d65c + 0x4c8fc);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d660 + 0x4c908));
      if (iVar2 == 0) {
        cprintf(DAT_0004d668 + 0x4c928,DAT_0004d664 + 0x4c924,0x2430);
      }
      pcVar1 = (char *)FUN_00049808(DAT_0004d66c + 0x4c934);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0004d670 + 0x4c940));
      if (iVar2 == 0) {
        uVar12 = 0x2430;
        iVar7 = DAT_0004d674 + 0x4c964;
        iVar2 = DAT_0004d678 + 0x4c970;
        iVar8 = DAT_0004d67c + 0x4c978;
        goto LAB_0004de80;
      }
    }
  }
  return 0;
}



===== FUN_0006221c @ 0006221c =====

undefined4
FUN_0006221c(int param_1,uint *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  ssize_t sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  iVar17 = DAT_00062994 + 0x62238;
  if (param_2 == (uint *)0x0) {
    pcVar1 = (char *)FUN_00049808(DAT_00062998 + 0x62244);
    iVar17 = strcmp(pcVar1,(char *)(DAT_0006299c + 0x62250));
    if (iVar17 == 0) {
      cprintf(DAT_000629a4 + 0x62270,DAT_000629a0 + 0x6226c,0x2d2a);
    }
    pcVar1 = (char *)FUN_00049808(DAT_000629a8 + 0x6227c);
    iVar17 = strcmp(pcVar1,(char *)(DAT_000629ac + 0x62288));
    if (iVar17 == 0) {
      uVar18 = 0x2d2a;
      iVar11 = DAT_000629b0 + 0x622a8;
      iVar17 = DAT_000629b4 + 0x622b4;
      iVar12 = DAT_000629b8 + 0x622b8;
LAB_000628e0:
      asusdebuglog(6,iVar17,0,1,0,iVar12,iVar11,uVar18);
    }
LAB_000628e8:
    uVar18 = 1;
  }
  else {
    pcVar1 = (char *)FUN_00049808(DAT_000629bc + 0x622d4);
    iVar11 = strcmp(pcVar1,(char *)(DAT_000629c0 + 0x622e0));
    if (iVar11 == 0) {
      cprintf(DAT_000629c8 + 0x62304,DAT_000629c4 + 0x62300,0x2d30,param_3);
    }
    pcVar1 = (char *)FUN_00049808(DAT_000629cc + 0x62310);
    iVar11 = strcmp(pcVar1,(char *)(DAT_000629d0 + 0x6231c));
    if (iVar11 == 0) {
      asusdebuglog(6,DAT_000629d8 + 0x6234c,0,1,0,DAT_000629dc + 0x62354,DAT_000629d4 + 0x62340,
                   0x2d30,param_3);
    }
    iVar11 = DAT_000629e0 + 0x6236c;
    pcVar1 = (char *)(DAT_000629e4 + 0x62378);
    iVar12 = DAT_000629e8 + 0x62384;
    iVar13 = DAT_000629ec + 0x62390;
    iVar14 = DAT_000629f0 + 0x6239c;
    for (iVar16 = 0; iVar16 < (int)param_3; iVar16 = iVar16 + 0xcU + uVar2) {
      if (param_3 < iVar16 + 0xcU) {
        pcVar1 = (char *)FUN_00049808(DAT_000629f4 + 0x623bc);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000629f8 + 0x623c8));
        if (iVar17 == 0) {
          cprintf(DAT_00062a00 + 0x623e8,DAT_000629fc + 0x623e4,0x2d36);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062a04 + 0x623f4);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a08 + 0x62400));
        if (iVar17 == 0) {
          asusdebuglog(6,DAT_00062a10 + 0x6243c,0,1,0,DAT_00062a14 + 0x62444,DAT_00062a0c + 0x62430,
                       0x2d36);
          return 0;
        }
        break;
      }
      uVar2 = *param_2;
      uVar7 = param_2[1];
      uVar3 = param_2[2];
      pcVar4 = (char *)FUN_00049808(iVar11);
      iVar5 = strcmp(pcVar4,pcVar1);
      uVar15 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
      if (iVar5 == 0) {
        uVar18 = FUN_000497c4(uVar15);
        cprintf(iVar13,iVar12,0x2d41,uVar18);
      }
      pcVar4 = (char *)FUN_00049808(iVar14);
      iVar5 = strcmp(pcVar4,(char *)(DAT_00062a18 + 0x624bc));
      if (iVar5 == 0) {
        uVar18 = FUN_000497c4(uVar15);
        asusdebuglog(6,DAT_00062a20 + 0x624f4,0,1,0,DAT_00062a24 + 0x624fc,DAT_00062a1c + 0x624e8,
                     0x2d41,uVar18);
      }
      iVar5 = 0;
      do {
        iVar9 = *(int *)(iVar17 + DAT_00062a28);
        iVar8 = iVar5 + iVar9;
        uVar10 = *(uint *)(iVar5 + iVar9);
        if ((int)uVar10 < 1) {
          if ((int)uVar10 < 0) {
            pcVar4 = (char *)FUN_00049808(DAT_00062abc + 0x628fc);
            iVar5 = strcmp(pcVar4,(char *)(DAT_00062ac0 + 0x62908));
            if (iVar5 == 0) {
              cprintf(DAT_00062ac8 + 0x6292c,DAT_00062ac4 + 0x62928,0x2d4a,uVar15);
            }
            pcVar4 = (char *)FUN_00049808(DAT_00062acc + 0x62938);
            iVar5 = strcmp(pcVar4,(char *)(DAT_00062ad0 + 0x62944));
            if (iVar5 == 0) {
              asusdebuglog(6,DAT_00062ad8 + 0x62974,0,1,0,DAT_00062adc + 0x6297c,
                           DAT_00062ad4 + 0x62968,0x2d4a,uVar15);
            }
            goto LAB_00062580;
          }
          break;
        }
        iVar5 = iVar5 + 8;
      } while (uVar10 != uVar15);
      iVar5 = (**(code **)(iVar8 + 4))
                        (param_1,param_6,uVar2,uVar7,uVar3,param_7,param_2 + 3,param_4,param_5);
      if (iVar5 == 0) {
        local_2c = 0x7000000;
        local_28 = iVar5;
        local_24 = iVar5;
        sVar6 = write(param_1,&local_2c,0xc);
        if (sVar6 == 0xc) goto LAB_000628e8;
        pcVar1 = (char *)FUN_00049808(DAT_00062a98 + 0x62868);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a9c + 0x62874));
        if (iVar17 == 0) {
          cprintf(DAT_00062aa4 + 0x62894,DAT_00062aa0 + 0x62890,0x2d80);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062aa8 + 0x628a0);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062aac + 0x628ac));
        if (iVar17 != 0) goto LAB_000628e8;
        uVar18 = 0x2d80;
        iVar11 = DAT_00062ab0 + 0x628cc;
        iVar17 = DAT_00062ab4 + 0x628d8;
        iVar12 = DAT_00062ab8 + 0x628dc;
        goto LAB_000628e0;
      }
LAB_00062580:
      switch(uVar15) {
      case 7:
        pcVar1 = (char *)FUN_00049808(DAT_00062a2c + 0x62668);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a30 + 0x62674));
        if (iVar17 == 0) {
          cprintf(DAT_00062a38 + 0x62694,DAT_00062a34 + 0x62690,0x2d54);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062a3c + 0x626a0);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a40 + 0x626ac));
        if (iVar17 == 0) {
          asusdebuglog(6,DAT_00062a48 + 0x626dc,0,1,0,DAT_00062a4c + 0x626e0,DAT_00062a44 + 0x626d0,
                       0x2d54);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062a50 + 0x626f4);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a54 + 0x62700));
        if (iVar17 == 0) {
          cprintf(DAT_00062a5c + 0x62720,DAT_00062a58 + 0x6271c,0x2d55);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062a60 + 0x6272c);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a64 + 0x62738));
        if (iVar17 != 0) goto LAB_000628e8;
        uVar18 = 0x2d55;
        iVar11 = DAT_00062a68 + 0x62758;
        iVar17 = DAT_00062a6c + 0x62764;
        iVar12 = DAT_00062a70 + 0x62768;
        goto LAB_000628e0;
      case 8:
        break;
      case 9:
        break;
      case 10:
        goto LAB_00062770;
      case 0xb:
        break;
      case 0xc:
        break;
      case 0xd:
        break;
      case 0xe:
        goto LAB_00062770;
      case 0xf:
        goto LAB_00062770;
      case 0x10:
        break;
      case 0x11:
        break;
      case 0x12:
        goto LAB_00062770;
      case 0x13:
        break;
      case 0x14:
        goto LAB_00062770;
      case 0x15:
        break;
      case 0x16:
        goto LAB_00062770;
      case 0x17:
        goto LAB_00062770;
      case 0x18:
        break;
      case 0x19:
        goto LAB_00062770;
      case 0x1a:
        break;
      case 0x1b:
        goto LAB_00062770;
      case 0x1c:
        break;
      case 0x1d:
        goto LAB_00062770;
      case 0x1e:
        break;
      case 0x1f:
        break;
      case 0x20:
        break;
      case 0x21:
        goto LAB_00062770;
      case 0x22:
        goto LAB_00062770;
      case 0x23:
        break;
      case 0x24:
        goto LAB_00062770;
      case 0x25:
        break;
      case 0x26:
        goto LAB_00062770;
      case 0x27:
        break;
      case 0x28:
        break;
      case 0x29:
        break;
      case 0x2a:
        goto LAB_00062770;
      case 0x2b:
        goto LAB_00062770;
      case 0x2c:
        break;
      case 0x2d:
        goto LAB_00062770;
      case 0x2e:
        break;
      case 0x2f:
        goto LAB_00062770;
      case 0x30:
        break;
      case 0x31:
        goto LAB_00062770;
      case 0x32:
        break;
      case 0x33:
        goto LAB_00062770;
      case 0x34:
        break;
      case 0x35:
        goto LAB_00062770;
      case 0x36:
        break;
      case 0x37:
        goto LAB_00062770;
      case 0x38:
        break;
      case 0x39:
LAB_00062770:
        pcVar1 = (char *)FUN_00049808(DAT_00062a74 + 0x6277c);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a78 + 0x62788));
        if (iVar17 == 0) {
          uVar18 = FUN_000497c4(uVar15);
          cprintf(DAT_00062a80 + 0x627b4,DAT_00062a7c + 0x627a8,0x2d73,uVar18);
        }
        pcVar1 = (char *)FUN_00049808(DAT_00062a84 + 0x627c0);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00062a88 + 0x627cc));
        if (iVar17 == 0) {
          uVar18 = FUN_000497c4(uVar15);
          asusdebuglog(6,DAT_00062a90 + 0x62804,0,1,0,DAT_00062a94 + 0x6280c,DAT_00062a8c + 0x627f8,
                       0x2d73,uVar18);
        }
        goto LAB_000628e8;
      }
      uVar2 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
              uVar7 >> 0x18;
      param_2 = (uint *)((int)(param_2 + 3) + uVar2);
    }
    uVar18 = 0;
  }
  return uVar18;
}


