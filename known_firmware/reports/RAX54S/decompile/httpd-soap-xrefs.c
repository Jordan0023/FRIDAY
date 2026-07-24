
===== TARGET /soap/server_sa/ =====

===== FUNCTION FUN_0002b594 @ 0002b594 =====

void FUN_0002b594(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  
  iVar7 = DAT_0002b784 + 0x2b5ac;
  piVar8 = *(int **)(iVar7 + DAT_0002b788);
  iVar5 = *piVar8;
  iVar1 = acosNvramConfig_match
                    (DAT_0002b790 + 0x2b5c0,DAT_0002b78c + 0x2b5bc,param_3,iVar5,param_1,iVar5,
                     param_3);
  if (iVar1 != 0) {
    uVar6 = 0;
    printf((char *)(DAT_0002b798 + 0x2b5ec),DAT_0002b794 + 0x2b5e8,0x582);
    goto LAB_0002b764;
  }
  pcVar2 = strcasestr(param_1,(char *)(DAT_0002b79c + 0x2b600));
  if ((pcVar2 == (char *)0x0) ||
     (pcVar2 = strcasestr(param_1,(char *)(DAT_0002b7a0 + 0x2b618)), pcVar2 == (char *)0x0)) {
    uVar6 = 0;
    if (param_1 == (char *)0x0) goto LAB_0002b764;
    pcVar2 = strcasestr(param_1,(char *)(DAT_0002b7b4 + 0x2b688));
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strcasestr(param_1,(char *)(DAT_0002b7bc + 0x2b6a8));
      if (pcVar2 != (char *)0x0) {
        pcVar3 = strcasestr(pcVar2,(char *)(DAT_0002b7c0 + 0x2b6bc));
        pcVar4 = (char *)(DAT_0002b7c4 + 0x2b6c8);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\0';
        }
        pcVar2 = strcasestr(pcVar2,pcVar4);
        if (pcVar3 != (char *)0x0) {
          *pcVar3 = '\r';
        }
        if (pcVar2 != (char *)0x0) {
          pcVar2 = (char *)(DAT_0002b7c8 + 0x2b6f4);
          goto LAB_0002b6f0;
        }
      }
      pcVar2 = strcasestr(param_1,(char *)(DAT_0002b7cc + 0x2b708));
      if (pcVar2 == (char *)0x0) goto LAB_0002b764;
      pcVar3 = strcasestr(pcVar2,(char *)(DAT_0002b7d0 + 0x2b71c));
      pcVar4 = (char *)(DAT_0002b7d4 + 0x2b728);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
      }
      pcVar2 = strstr(pcVar2,pcVar4);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\r';
      }
      if (pcVar2 == (char *)0x0) goto LAB_0002b764;
      printf((char *)(DAT_0002b7dc + 0x2b760),DAT_0002b7d8 + 0x2b75c);
    }
    else {
      pcVar2 = (char *)(DAT_0002b7b8 + 0x2b698);
LAB_0002b6f0:
      puts(pcVar2);
    }
  }
  else {
    iVar1 = DAT_0002b7a4 + 0x2b638;
    printf((char *)(DAT_0002b7ac + 0x2b640),DAT_0002b7a8 + 0x2b63c,0x588);
    pcVar2 = (char *)acosNvramConfig_get(iVar1);
    if (*pcVar2 != '\0') {
      pcVar2 = (char *)acosNvramConfig_get(iVar1);
      iVar1 = atoi(pcVar2);
      **(int **)(iVar7 + DAT_0002b7b0) = iVar1;
    }
  }
  uVar6 = 1;
LAB_0002b764:
  if (iVar5 == *piVar8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}


===== TARGET Port 5000 socket accesp failed!! =====

===== TARGET SOAPAction: =====

===== FUNCTION FUN_0009b658 @ 0009b658 =====

void FUN_0009b658(undefined4 param_1,in_addr param_2,undefined4 param_3,int *param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 local_174;
  undefined1 auStack_170 [28];
  char local_154 [48];
  undefined2 local_124;
  undefined1 auStack_122 [254];
  int local_24;
  
  iVar7 = DAT_0009b914;
  piVar8 = *(int **)(DAT_0009b90c + 0x9b678 + DAT_0009b910);
  local_174 = 0;
  local_24 = *piVar8;
  memset(auStack_170,0,0x1c);
  local_124 = *(undefined2 *)(iVar7 + 0x9b6c4);
  iVar7 = iVar7 + 0x9b7c4;
  memset(auStack_122,0,0xfe);
  if (*param_4 == 0) {
    pcVar1 = inet_ntoa(param_2);
    uVar6 = 0x216;
    iVar5 = DAT_0009b918 + 0x9b6f0;
  }
  else {
    local_154[0] = '\0';
    local_154[1] = '\0';
    local_154[2] = '\0';
    local_154[3] = '\0';
    pcVar1 = local_154;
    memset(local_154 + 4,0,0x2b);
    inet_ntop(10,param_4 + 5,pcVar1,0x2f);
    printf((char *)(DAT_0009b91c + 0x9b738),iVar7,0x227,pcVar1);
    uVar6 = 0x229;
    iVar5 = DAT_0009b920 + 0x9b74c;
  }
  FUN_0006a044(2,iVar5,iVar7,uVar6,pcVar1);
  iVar7 = FUN_0009a95c(&local_174,param_2.s_addr,param_4);
  if (iVar7 == 0) {
    pcVar1 = (char *)stristr(param_3,DAT_0009b928 + 0x9b79c);
    pcVar2 = (char *)stristr(param_3,DAT_0009b92c + 0x9b7a8);
    iVar7 = 0;
    if (pcVar2 != (char *)0x0) {
      if (((pcVar2[-2] == '\r') && (pcVar2[-1] == '\n')) &&
         (pcVar3 = strchr(pcVar2,0xd), iVar7 = DAT_0009b930, pcVar3 != (char *)0x0)) {
        *pcVar3 = '\0';
        iVar7 = stristr(pcVar2,iVar7 + 0x9b7f4);
        *pcVar3 = '\r';
      }
      else {
        iVar7 = 0;
      }
    }
    iVar5 = 0;
    if ((iVar7 == 0 && pcVar1 != (char *)0x0) &&
       (pcVar2 = strchr(pcVar1,0xd), iVar7 = DAT_0009b934, pcVar2 != (char *)0x0)) {
      *pcVar2 = '\0';
      pcVar1 = strstr(pcVar1,(char *)(iVar7 + 0x9b850));
      if (pcVar1 == (char *)0x0) {
        *pcVar2 = '\r';
      }
      else {
        snprintf((char *)&local_124,0x81,(char *)(DAT_0009b938 + 0x9b878),pcVar1 + 8);
        iVar4 = FUN_0009b1dc(&local_124,&local_174,param_2.s_addr,param_4);
        FUN_0006a044(2,DAT_0009b93c + 0x9b89c,&local_124,iVar4);
        iVar7 = DAT_0009b940;
        if (iVar4 < 1) {
          FUN_0006a044(2,DAT_0009b944 + 0x9b8e8,iVar4);
        }
        else {
          *pcVar2 = '\r';
          FUN_0006a044(2,iVar7 + 0x9b8c8,iVar4);
          iVar5 = iVar4;
        }
      }
    }
  }
  else {
    FUN_0006a044(2,DAT_0009b924 + 0x9b788);
    iVar5 = -1;
  }
  if (local_24 == *piVar8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar5);
}

