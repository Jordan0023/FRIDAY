
===== ENTRY 00076db4 =====
===== FUNCTION FUN_00076db4 @ 00076db4 =====

undefined4 FUN_00076db4(char *param_1,undefined4 param_2,char *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  char *__s2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  char local_22c [256];
  char local_12c [256];
  int local_2c;
  
  local_2c = *DAT_0007706c;
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
  pcVar3 = strstr(param_1,DAT_00077070);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = param_1;
  }
  pcVar3 = strstr(pcVar3,DAT_00077074);
  if (pcVar3 == (char *)0x0) {
    uVar7 = 0x2be;
    uVar8 = 0;
  }
  else {
    snprintf(local_22c,0xff,DAT_00077078,param_2);
    snprintf(local_12c,0xff,DAT_0007707c,param_2);
    pcVar3 = strstr(pcVar3 + 8,local_22c);
    if (pcVar3 == (char *)0x0) {
      bVar1 = 0;
      bVar2 = 0;
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = strchr(pcVar3,0x3e);
      if (pcVar4 == (char *)0x0) {
        bVar1 = 0;
        bVar2 = 0;
        pcVar4 = (char *)0x0;
      }
      else {
        pcVar3 = pcVar4 + 1;
        bVar2 = 1;
        pcVar4 = strstr(pcVar3,local_12c);
        bVar1 = 0;
        if (pcVar4 != (char *)0x0) {
          bVar1 = 1;
        }
      }
    }
    if ((bool)(bVar2 & bVar1)) {
      *pcVar4 = '\0';
      uVar8 = (int)pcVar4 - (int)pcVar3;
      if (param_4 < (uint)((int)pcVar4 - (int)pcVar3)) {
        memset(param_3,0,param_4);
        uVar8 = param_4;
      }
      __s2 = DAT_00077080;
      pcVar9 = param_3;
      uVar11 = uVar8;
      if (pcVar3 != (char *)0x0) {
LAB_00076ef8:
        if ((int)uVar11 < 1) goto LAB_00076f00;
        pcVar10 = pcVar9 + 1;
        iVar5 = strncmp(pcVar3,DAT_0007708c,5);
        if (iVar5 == 0) {
          cVar6 = '&';
LAB_00077050:
          pcVar3 = pcVar3 + 5;
          *pcVar9 = cVar6;
          pcVar9 = pcVar10;
          uVar11 = uVar11 - 5;
          goto LAB_00076ef8;
        }
        iVar5 = strncmp(pcVar3,DAT_00077090,4);
        if (iVar5 == 0) {
          cVar6 = '<';
        }
        else {
          iVar5 = strncmp(pcVar3,DAT_00077094,4);
          if (iVar5 != 0) {
            iVar5 = strncmp(pcVar3,DAT_00077098,6);
            if (iVar5 == 0) {
              cVar6 = '\"';
            }
            else {
              iVar5 = strncmp(pcVar3,DAT_0007709c,6);
              if (iVar5 != 0) {
                iVar5 = strncmp(pcVar3,DAT_000770a0,4);
                if (iVar5 == 0) {
                  cVar6 = '\t';
                  goto LAB_00076ffc;
                }
                iVar5 = strncmp(pcVar3,DAT_000770a4,5);
                if (iVar5 == 0) {
                  cVar6 = '\r';
                  goto LAB_00077050;
                }
                iVar5 = strncmp(pcVar3,__s2,5);
                if (iVar5 != 0) {
                  *pcVar9 = *pcVar3;
                  pcVar3 = pcVar3 + 1;
                  pcVar9 = pcVar10;
                  uVar11 = uVar11 - 1;
                  goto LAB_00076ef8;
                }
                cVar6 = '\n';
                goto LAB_00077050;
              }
              cVar6 = '\\';
            }
            *pcVar9 = cVar6;
            pcVar3 = pcVar3 + 6;
            pcVar9 = pcVar10;
            uVar11 = uVar11 - 6;
            goto LAB_00076ef8;
          }
          cVar6 = '>';
        }
LAB_00076ffc:
        *pcVar9 = cVar6;
        pcVar3 = pcVar3 + 4;
        pcVar9 = pcVar10;
        uVar11 = uVar11 - 4;
        goto LAB_00076ef8;
      }
LAB_00076f00:
      uVar7 = 0;
      *pcVar4 = '<';
    }
    else {
      uVar7 = 0x192;
      uVar8 = 0;
    }
  }
  FUN_00075848(2,DAT_00077088,DAT_00077084,uVar7,param_2,param_3,uVar8);
  if (local_2c != *DAT_0007706c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

