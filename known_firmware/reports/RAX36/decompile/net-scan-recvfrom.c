
===== ADDRESS 00012914 FUNCTION NONE =====

===== ADDRESS 0001297c FUNCTION NONE =====

===== ADDRESS 00018d68 FUNCTION FUN_00018cb8 =====

undefined4 FUN_00018cb8(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  char *__dest;
  byte *pbVar2;
  byte *pbVar3;
  uint extraout_r2;
  uint uVar4;
  uint extraout_r2_00;
  byte bVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  if (param_2 != 0) {
    if (param_1 == (byte *)0x0) {
      __dest = (char *)FUN_00018af0(param_2,3,param_3,param_4,0,param_2);
      if (__dest != (char *)0x0) {
        strcpy(__dest,(char *)(DAT_00018eb8 + 0x18d6c));
        return 1;
      }
    }
    else {
      iVar7 = 0;
      pbVar6 = param_1;
LAB_00018cec:
      while( true ) {
        pbVar3 = pbVar6 + 1;
        bVar5 = *pbVar6;
        if (bVar5 == 0) break;
        pbVar6 = pbVar3;
        if (0x22 < bVar5) goto LAB_00018d9c;
        if ((7 < bVar5) && ((DAT_00018eb4 & 1 << (uint)(byte)(bVar5 - 8)) != 0)) goto LAB_00018d94;
        if (bVar5 < 0x20) {
          iVar7 = iVar7 + 5;
        }
      }
      pbVar6 = pbVar6 + (iVar7 - (int)param_1);
      puVar1 = (undefined1 *)FUN_00018af0(param_2,pbVar6 + 3,pbVar3,0,param_1,param_2);
      if (puVar1 != (undefined1 *)0x0) {
        pbVar3 = puVar1 + 1;
        *puVar1 = 0x22;
        if (iVar7 == 0) {
          memcpy(pbVar3,param_1,(size_t)pbVar6);
          puVar1[(int)(pbVar6 + 1)] = 0x22;
          puVar1[(int)(pbVar6 + 2)] = 0;
        }
        else {
          param_1 = param_1 + -1;
          iVar7 = DAT_00018ebc + 0x18dc8;
          uVar4 = extraout_r2;
          while( true ) {
            param_1 = param_1 + 1;
            bVar5 = *param_1;
            if (bVar5 == 0) break;
            bVar9 = 0x21 < bVar5;
            bVar8 = bVar5 != 0x22;
            if (bVar8) {
              bVar9 = 0x1e < bVar5;
            }
            if (bVar9 && (bVar8 && bVar5 != 0x1f)) {
              uVar4 = 1;
            }
            if (!bVar9 || (!bVar8 || bVar5 == 0x1f)) {
              uVar4 = 0;
            }
            if (bVar5 == 0x5c) {
              uVar4 = 0;
            }
            else {
              uVar4 = uVar4 & 1;
            }
            if (uVar4 != 0) {
              *pbVar3 = bVar5;
              pbVar2 = pbVar3;
              goto LAB_00018e64;
            }
            pbVar2 = pbVar3 + 1;
            *pbVar3 = 0x5c;
            uVar4 = (uint)*param_1;
            if (0xd < uVar4) {
              if ((uVar4 != 0x22) && (uVar4 != 0x5c)) goto switchD_00018e30_default;
              pbVar3[1] = *param_1;
              goto LAB_00018e64;
            }
            if (uVar4 < 8) goto switchD_00018e30_default;
            switch(uVar4) {
            case 8:
              bVar5 = 0x62;
              break;
            case 9:
              bVar5 = 0x74;
              break;
            case 10:
              bVar5 = 0x6e;
              break;
            case 0xb:
            default:
switchD_00018e30_default:
              __sprintf_chk(pbVar2,1,0xffffffff,iVar7,uVar4);
              pbVar2 = pbVar3 + 5;
              uVar4 = extraout_r2_00;
              goto LAB_00018e64;
            case 0xc:
              bVar5 = 0x66;
              break;
            case 0xd:
              bVar5 = 0x72;
            }
            pbVar3[1] = bVar5;
LAB_00018e64:
            pbVar3 = pbVar2 + 1;
          }
          puVar1[(int)(pbVar6 + 1)] = 0x22;
          puVar1[(int)(pbVar6 + 2)] = 0;
        }
        return 1;
      }
    }
  }
  return 0;
LAB_00018d9c:
  if (bVar5 == 0x5c) {
LAB_00018d94:
    iVar7 = iVar7 + 1;
  }
  goto LAB_00018cec;
}


===== ADDRESS 00018ffc FUNCTION FUN_00018ec0 =====

uint FUN_00018ec0(int param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  lconv *plVar5;
  size_t sVar6;
  void *__dest;
  int iVar7;
  char *__src;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 local_48;
  undefined4 uStack_44;
  char local_40 [28];
  int local_24;
  
  local_24 = **(int **)(DAT_00019488 + 0x18edc + DAT_0001948c);
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) goto switchD_00018f2c_default;
  uVar10 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar10 == 0x10) {
    uVar10 = FUN_00018cb8(*(undefined4 *)(param_1 + 0x10),param_2,DAT_00019488 + 0x18edc,0);
    goto LAB_00019028;
  }
  if (uVar10 < 0x11) {
    switch(uVar10) {
    case 1:
      pcVar4 = (char *)FUN_00018af0(param_2,6);
      if (pcVar4 != (char *)0x0) {
        strcpy(pcVar4,(char *)(DAT_00019494 + 0x19028));
        goto LAB_00019028;
      }
      break;
    case 2:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_0001949c + 0x1906c);
LAB_00018ffc:
        strcpy(pcVar4,__src);
LAB_00019000:
        uVar10 = 1;
        goto LAB_00019028;
      }
      break;
    case 3:
      break;
    case 4:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_00019490 + 0x19000);
        goto LAB_00018ffc;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      uVar12 = *(undefined4 *)(param_1 + 0x18);
      uVar13 = *(undefined4 *)(param_1 + 0x1c);
      plVar5 = localeconv();
      cVar1 = *plVar5->decimal_point;
      uVar14 = FUN_0001e94c(uVar12,uVar13,0,0);
      iVar7 = FUN_0001ee84((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0);
      if (iVar7 == 0) {
        uVar10 = 4;
        strcpy(local_40,(char *)(DAT_000194a0 + 0x190bc));
      }
      else {
        uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194a4 + 0x19110,uVar12,uVar13);
        iVar7 = dni_sscanf_s(DAT_000194ac + 0x1913c,0x1c1,local_40,DAT_000194a8 + 0x19130,&local_48)
        ;
        if ((iVar7 != 1) || (iVar7 = FUN_0001ee84(uVar12,uVar13,local_48,uStack_44), iVar7 == 0)) {
          uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194b0 + 0x19174,uVar12,uVar13);
        }
        if (0x19 < uVar10) break;
      }
      iVar7 = FUN_00018af0(param_2,uVar10);
      if (iVar7 != 0) {
        for (uVar8 = 0; uVar10 != uVar8; uVar8 = uVar8 + 1) {
          cVar2 = local_40[uVar8];
          if (cVar2 == cVar1) {
            *(undefined1 *)(iVar7 + uVar8) = 0x2e;
          }
          else {
            *(char *)(iVar7 + uVar8) = cVar2;
          }
        }
        *(undefined1 *)(iVar7 + uVar10) = 0;
        param_2[2] = param_2[2] + uVar10;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x40) {
    piVar11 = *(int **)(param_1 + 8);
    if (param_2[5] == 0) {
      iVar7 = 1;
    }
    else {
      iVar7 = 2;
    }
    puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x7b;
      param_2[3] = param_2[3] + 1;
      if (param_2[5] != 0) {
        puVar3[1] = 10;
      }
      param_2[2] = param_2[2] + iVar7;
      while (piVar11 != (int *)0x0) {
        if (param_2[5] != 0) {
          puVar9 = (undefined1 *)FUN_00018af0(param_2,param_2[3]);
          puVar3 = puVar9;
          if (puVar9 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          for (; (uint)((int)puVar3 - (int)puVar9) < (uint)param_2[3]; puVar3 = puVar3 + 1) {
            *puVar3 = 9;
          }
          param_2[2] = param_2[2] + param_2[3];
        }
        iVar7 = FUN_00018cb8(piVar11[8],param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (param_2[5] == 0) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        *puVar3 = 0x3a;
        if (param_2[5] != 0) {
          puVar3[1] = 9;
        }
        param_2[2] = param_2[2] + iVar7;
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        uVar10 = (uint)(*piVar11 != 0);
        if (param_2[5] != 0) {
          uVar10 = uVar10 + 1;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,uVar10 + 1);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        puVar9 = puVar3;
        if (*piVar11 != 0) {
          puVar9 = puVar3 + 1;
          *puVar3 = 0x2c;
        }
        puVar3 = puVar9;
        if (param_2[5] != 0) {
          puVar3 = puVar9 + 1;
          *puVar9 = 10;
        }
        *puVar3 = 0;
        piVar11 = (int *)*piVar11;
        param_2[2] = param_2[2] + uVar10;
      }
      if (param_2[5] == 0) {
        iVar7 = 2;
      }
      else {
        iVar7 = param_2[3] + 1;
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
      if (puVar3 != (undefined1 *)0x0) {
        puVar9 = puVar3;
        if (param_2[5] != 0) {
          for (; (uint)((int)puVar9 - (int)puVar3) < param_2[3] - 1; puVar9 = puVar9 + 1) {
            *puVar9 = 9;
          }
        }
        *puVar9 = 0x7d;
        puVar9[1] = 0;
LAB_00018fd0:
        param_2[3] = param_2[3] + -1;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x80) {
    if (*(char **)(param_1 + 0x10) == (char *)0x0) {
      if (param_2[4] == 0) {
        (*(code *)param_2[7])(*param_2);
        uVar10 = 0;
        goto LAB_00019028;
      }
    }
    else {
      sVar6 = strlen(*(char **)(param_1 + 0x10));
      __dest = (void *)FUN_00018af0(param_2,sVar6 + 1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,*(void **)(param_1 + 0x10),sVar6 + 1);
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x20) {
    piVar11 = *(int **)(param_1 + 8);
    puVar3 = (undefined1 *)FUN_00018af0(param_2,1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x5b;
      param_2[2] = param_2[2] + 1;
      param_2[3] = param_2[3] + 1;
      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (*piVar11 != 0) {
          if (param_2[5] == 0) {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
          }
          puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
          if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          *puVar3 = 0x2c;
          if (param_2[5] == 0) {
            puVar9 = puVar3 + 1;
          }
          else {
            puVar9 = puVar3 + 2;
            puVar3[1] = 0x20;
          }
          *puVar9 = 0;
          param_2[2] = param_2[2] + iVar7;
        }
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,2);
      if (puVar3 != (undefined1 *)0x0) {
        puVar3[1] = 0;
        *puVar3 = 0x5d;
        goto LAB_00018fd0;
      }
    }
  }
switchD_00018f2c_default:
  uVar10 = 0;
LAB_00019028:
  if (local_24 != **(int **)(DAT_00019498 + 0x19038 + DAT_0001948c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

REFERENCE 00019068 OWNER FUN_00018ec0

uint FUN_00018ec0(int param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  lconv *plVar5;
  size_t sVar6;
  void *__dest;
  int iVar7;
  char *__src;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 local_48;
  undefined4 uStack_44;
  char local_40 [28];
  int local_24;
  
  local_24 = **(int **)(DAT_00019488 + 0x18edc + DAT_0001948c);
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) goto switchD_00018f2c_default;
  uVar10 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar10 == 0x10) {
    uVar10 = FUN_00018cb8(*(undefined4 *)(param_1 + 0x10),param_2,DAT_00019488 + 0x18edc,0);
    goto LAB_00019028;
  }
  if (uVar10 < 0x11) {
    switch(uVar10) {
    case 1:
      pcVar4 = (char *)FUN_00018af0(param_2,6);
      if (pcVar4 != (char *)0x0) {
        strcpy(pcVar4,(char *)(DAT_00019494 + 0x19028));
        goto LAB_00019028;
      }
      break;
    case 2:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_0001949c + 0x1906c);
LAB_00018ffc:
        strcpy(pcVar4,__src);
LAB_00019000:
        uVar10 = 1;
        goto LAB_00019028;
      }
      break;
    case 3:
      break;
    case 4:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_00019490 + 0x19000);
        goto LAB_00018ffc;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      uVar12 = *(undefined4 *)(param_1 + 0x18);
      uVar13 = *(undefined4 *)(param_1 + 0x1c);
      plVar5 = localeconv();
      cVar1 = *plVar5->decimal_point;
      uVar14 = FUN_0001e94c(uVar12,uVar13,0,0);
      iVar7 = FUN_0001ee84((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0);
      if (iVar7 == 0) {
        uVar10 = 4;
        strcpy(local_40,(char *)(DAT_000194a0 + 0x190bc));
      }
      else {
        uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194a4 + 0x19110,uVar12,uVar13);
        iVar7 = dni_sscanf_s(DAT_000194ac + 0x1913c,0x1c1,local_40,DAT_000194a8 + 0x19130,&local_48)
        ;
        if ((iVar7 != 1) || (iVar7 = FUN_0001ee84(uVar12,uVar13,local_48,uStack_44), iVar7 == 0)) {
          uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194b0 + 0x19174,uVar12,uVar13);
        }
        if (0x19 < uVar10) break;
      }
      iVar7 = FUN_00018af0(param_2,uVar10);
      if (iVar7 != 0) {
        for (uVar8 = 0; uVar10 != uVar8; uVar8 = uVar8 + 1) {
          cVar2 = local_40[uVar8];
          if (cVar2 == cVar1) {
            *(undefined1 *)(iVar7 + uVar8) = 0x2e;
          }
          else {
            *(char *)(iVar7 + uVar8) = cVar2;
          }
        }
        *(undefined1 *)(iVar7 + uVar10) = 0;
        param_2[2] = param_2[2] + uVar10;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x40) {
    piVar11 = *(int **)(param_1 + 8);
    if (param_2[5] == 0) {
      iVar7 = 1;
    }
    else {
      iVar7 = 2;
    }
    puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x7b;
      param_2[3] = param_2[3] + 1;
      if (param_2[5] != 0) {
        puVar3[1] = 10;
      }
      param_2[2] = param_2[2] + iVar7;
      while (piVar11 != (int *)0x0) {
        if (param_2[5] != 0) {
          puVar9 = (undefined1 *)FUN_00018af0(param_2,param_2[3]);
          puVar3 = puVar9;
          if (puVar9 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          for (; (uint)((int)puVar3 - (int)puVar9) < (uint)param_2[3]; puVar3 = puVar3 + 1) {
            *puVar3 = 9;
          }
          param_2[2] = param_2[2] + param_2[3];
        }
        iVar7 = FUN_00018cb8(piVar11[8],param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (param_2[5] == 0) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        *puVar3 = 0x3a;
        if (param_2[5] != 0) {
          puVar3[1] = 9;
        }
        param_2[2] = param_2[2] + iVar7;
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        uVar10 = (uint)(*piVar11 != 0);
        if (param_2[5] != 0) {
          uVar10 = uVar10 + 1;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,uVar10 + 1);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        puVar9 = puVar3;
        if (*piVar11 != 0) {
          puVar9 = puVar3 + 1;
          *puVar3 = 0x2c;
        }
        puVar3 = puVar9;
        if (param_2[5] != 0) {
          puVar3 = puVar9 + 1;
          *puVar9 = 10;
        }
        *puVar3 = 0;
        piVar11 = (int *)*piVar11;
        param_2[2] = param_2[2] + uVar10;
      }
      if (param_2[5] == 0) {
        iVar7 = 2;
      }
      else {
        iVar7 = param_2[3] + 1;
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
      if (puVar3 != (undefined1 *)0x0) {
        puVar9 = puVar3;
        if (param_2[5] != 0) {
          for (; (uint)((int)puVar9 - (int)puVar3) < param_2[3] - 1; puVar9 = puVar9 + 1) {
            *puVar9 = 9;
          }
        }
        *puVar9 = 0x7d;
        puVar9[1] = 0;
LAB_00018fd0:
        param_2[3] = param_2[3] + -1;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x80) {
    if (*(char **)(param_1 + 0x10) == (char *)0x0) {
      if (param_2[4] == 0) {
        (*(code *)param_2[7])(*param_2);
        uVar10 = 0;
        goto LAB_00019028;
      }
    }
    else {
      sVar6 = strlen(*(char **)(param_1 + 0x10));
      __dest = (void *)FUN_00018af0(param_2,sVar6 + 1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,*(void **)(param_1 + 0x10),sVar6 + 1);
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x20) {
    piVar11 = *(int **)(param_1 + 8);
    puVar3 = (undefined1 *)FUN_00018af0(param_2,1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x5b;
      param_2[2] = param_2[2] + 1;
      param_2[3] = param_2[3] + 1;
      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (*piVar11 != 0) {
          if (param_2[5] == 0) {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
          }
          puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
          if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          *puVar3 = 0x2c;
          if (param_2[5] == 0) {
            puVar9 = puVar3 + 1;
          }
          else {
            puVar9 = puVar3 + 2;
            puVar3[1] = 0x20;
          }
          *puVar9 = 0;
          param_2[2] = param_2[2] + iVar7;
        }
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,2);
      if (puVar3 != (undefined1 *)0x0) {
        puVar3[1] = 0;
        *puVar3 = 0x5d;
        goto LAB_00018fd0;
      }
    }
  }
switchD_00018f2c_default:
  uVar10 = 0;
LAB_00019028:
  if (local_24 != **(int **)(DAT_00019498 + 0x19038 + DAT_0001948c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


===== ADDRESS 00019024 FUNCTION FUN_00018ec0 =====

uint FUN_00018ec0(int param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  lconv *plVar5;
  size_t sVar6;
  void *__dest;
  int iVar7;
  char *__src;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 local_48;
  undefined4 uStack_44;
  char local_40 [28];
  int local_24;
  
  local_24 = **(int **)(DAT_00019488 + 0x18edc + DAT_0001948c);
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) goto switchD_00018f2c_default;
  uVar10 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar10 == 0x10) {
    uVar10 = FUN_00018cb8(*(undefined4 *)(param_1 + 0x10),param_2,DAT_00019488 + 0x18edc,0);
    goto LAB_00019028;
  }
  if (uVar10 < 0x11) {
    switch(uVar10) {
    case 1:
      pcVar4 = (char *)FUN_00018af0(param_2,6);
      if (pcVar4 != (char *)0x0) {
        strcpy(pcVar4,(char *)(DAT_00019494 + 0x19028));
        goto LAB_00019028;
      }
      break;
    case 2:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_0001949c + 0x1906c);
LAB_00018ffc:
        strcpy(pcVar4,__src);
LAB_00019000:
        uVar10 = 1;
        goto LAB_00019028;
      }
      break;
    case 3:
      break;
    case 4:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_00019490 + 0x19000);
        goto LAB_00018ffc;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      uVar12 = *(undefined4 *)(param_1 + 0x18);
      uVar13 = *(undefined4 *)(param_1 + 0x1c);
      plVar5 = localeconv();
      cVar1 = *plVar5->decimal_point;
      uVar14 = FUN_0001e94c(uVar12,uVar13,0,0);
      iVar7 = FUN_0001ee84((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0);
      if (iVar7 == 0) {
        uVar10 = 4;
        strcpy(local_40,(char *)(DAT_000194a0 + 0x190bc));
      }
      else {
        uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194a4 + 0x19110,uVar12,uVar13);
        iVar7 = dni_sscanf_s(DAT_000194ac + 0x1913c,0x1c1,local_40,DAT_000194a8 + 0x19130,&local_48)
        ;
        if ((iVar7 != 1) || (iVar7 = FUN_0001ee84(uVar12,uVar13,local_48,uStack_44), iVar7 == 0)) {
          uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194b0 + 0x19174,uVar12,uVar13);
        }
        if (0x19 < uVar10) break;
      }
      iVar7 = FUN_00018af0(param_2,uVar10);
      if (iVar7 != 0) {
        for (uVar8 = 0; uVar10 != uVar8; uVar8 = uVar8 + 1) {
          cVar2 = local_40[uVar8];
          if (cVar2 == cVar1) {
            *(undefined1 *)(iVar7 + uVar8) = 0x2e;
          }
          else {
            *(char *)(iVar7 + uVar8) = cVar2;
          }
        }
        *(undefined1 *)(iVar7 + uVar10) = 0;
        param_2[2] = param_2[2] + uVar10;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x40) {
    piVar11 = *(int **)(param_1 + 8);
    if (param_2[5] == 0) {
      iVar7 = 1;
    }
    else {
      iVar7 = 2;
    }
    puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x7b;
      param_2[3] = param_2[3] + 1;
      if (param_2[5] != 0) {
        puVar3[1] = 10;
      }
      param_2[2] = param_2[2] + iVar7;
      while (piVar11 != (int *)0x0) {
        if (param_2[5] != 0) {
          puVar9 = (undefined1 *)FUN_00018af0(param_2,param_2[3]);
          puVar3 = puVar9;
          if (puVar9 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          for (; (uint)((int)puVar3 - (int)puVar9) < (uint)param_2[3]; puVar3 = puVar3 + 1) {
            *puVar3 = 9;
          }
          param_2[2] = param_2[2] + param_2[3];
        }
        iVar7 = FUN_00018cb8(piVar11[8],param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (param_2[5] == 0) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        *puVar3 = 0x3a;
        if (param_2[5] != 0) {
          puVar3[1] = 9;
        }
        param_2[2] = param_2[2] + iVar7;
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        uVar10 = (uint)(*piVar11 != 0);
        if (param_2[5] != 0) {
          uVar10 = uVar10 + 1;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,uVar10 + 1);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        puVar9 = puVar3;
        if (*piVar11 != 0) {
          puVar9 = puVar3 + 1;
          *puVar3 = 0x2c;
        }
        puVar3 = puVar9;
        if (param_2[5] != 0) {
          puVar3 = puVar9 + 1;
          *puVar9 = 10;
        }
        *puVar3 = 0;
        piVar11 = (int *)*piVar11;
        param_2[2] = param_2[2] + uVar10;
      }
      if (param_2[5] == 0) {
        iVar7 = 2;
      }
      else {
        iVar7 = param_2[3] + 1;
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
      if (puVar3 != (undefined1 *)0x0) {
        puVar9 = puVar3;
        if (param_2[5] != 0) {
          for (; (uint)((int)puVar9 - (int)puVar3) < param_2[3] - 1; puVar9 = puVar9 + 1) {
            *puVar9 = 9;
          }
        }
        *puVar9 = 0x7d;
        puVar9[1] = 0;
LAB_00018fd0:
        param_2[3] = param_2[3] + -1;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x80) {
    if (*(char **)(param_1 + 0x10) == (char *)0x0) {
      if (param_2[4] == 0) {
        (*(code *)param_2[7])(*param_2);
        uVar10 = 0;
        goto LAB_00019028;
      }
    }
    else {
      sVar6 = strlen(*(char **)(param_1 + 0x10));
      __dest = (void *)FUN_00018af0(param_2,sVar6 + 1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,*(void **)(param_1 + 0x10),sVar6 + 1);
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x20) {
    piVar11 = *(int **)(param_1 + 8);
    puVar3 = (undefined1 *)FUN_00018af0(param_2,1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x5b;
      param_2[2] = param_2[2] + 1;
      param_2[3] = param_2[3] + 1;
      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (*piVar11 != 0) {
          if (param_2[5] == 0) {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
          }
          puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
          if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          *puVar3 = 0x2c;
          if (param_2[5] == 0) {
            puVar9 = puVar3 + 1;
          }
          else {
            puVar9 = puVar3 + 2;
            puVar3[1] = 0x20;
          }
          *puVar9 = 0;
          param_2[2] = param_2[2] + iVar7;
        }
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,2);
      if (puVar3 != (undefined1 *)0x0) {
        puVar3[1] = 0;
        *puVar3 = 0x5d;
        goto LAB_00018fd0;
      }
    }
  }
switchD_00018f2c_default:
  uVar10 = 0;
LAB_00019028:
  if (local_24 != **(int **)(DAT_00019498 + 0x19038 + DAT_0001948c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


===== ADDRESS 000190b8 FUNCTION FUN_00018ec0 =====

uint FUN_00018ec0(int param_1,undefined4 *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  lconv *plVar5;
  size_t sVar6;
  void *__dest;
  int iVar7;
  char *__src;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 local_48;
  undefined4 uStack_44;
  char local_40 [28];
  int local_24;
  
  local_24 = **(int **)(DAT_00019488 + 0x18edc + DAT_0001948c);
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) goto switchD_00018f2c_default;
  uVar10 = (uint)*(byte *)(param_1 + 0xc);
  if (uVar10 == 0x10) {
    uVar10 = FUN_00018cb8(*(undefined4 *)(param_1 + 0x10),param_2,DAT_00019488 + 0x18edc,0);
    goto LAB_00019028;
  }
  if (uVar10 < 0x11) {
    switch(uVar10) {
    case 1:
      pcVar4 = (char *)FUN_00018af0(param_2,6);
      if (pcVar4 != (char *)0x0) {
        strcpy(pcVar4,(char *)(DAT_00019494 + 0x19028));
        goto LAB_00019028;
      }
      break;
    case 2:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_0001949c + 0x1906c);
LAB_00018ffc:
        strcpy(pcVar4,__src);
LAB_00019000:
        uVar10 = 1;
        goto LAB_00019028;
      }
      break;
    case 3:
      break;
    case 4:
      pcVar4 = (char *)FUN_00018af0(param_2,5);
      if (pcVar4 != (char *)0x0) {
        __src = (char *)(DAT_00019490 + 0x19000);
        goto LAB_00018ffc;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      uVar12 = *(undefined4 *)(param_1 + 0x18);
      uVar13 = *(undefined4 *)(param_1 + 0x1c);
      plVar5 = localeconv();
      cVar1 = *plVar5->decimal_point;
      uVar14 = FUN_0001e94c(uVar12,uVar13,0,0);
      iVar7 = FUN_0001ee84((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0);
      if (iVar7 == 0) {
        uVar10 = 4;
        strcpy(local_40,(char *)(DAT_000194a0 + 0x190bc));
      }
      else {
        uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194a4 + 0x19110,uVar12,uVar13);
        iVar7 = dni_sscanf_s(DAT_000194ac + 0x1913c,0x1c1,local_40,DAT_000194a8 + 0x19130,&local_48)
        ;
        if ((iVar7 != 1) || (iVar7 = FUN_0001ee84(uVar12,uVar13,local_48,uStack_44), iVar7 == 0)) {
          uVar10 = __sprintf_chk(local_40,1,0x1a,DAT_000194b0 + 0x19174,uVar12,uVar13);
        }
        if (0x19 < uVar10) break;
      }
      iVar7 = FUN_00018af0(param_2,uVar10);
      if (iVar7 != 0) {
        for (uVar8 = 0; uVar10 != uVar8; uVar8 = uVar8 + 1) {
          cVar2 = local_40[uVar8];
          if (cVar2 == cVar1) {
            *(undefined1 *)(iVar7 + uVar8) = 0x2e;
          }
          else {
            *(char *)(iVar7 + uVar8) = cVar2;
          }
        }
        *(undefined1 *)(iVar7 + uVar10) = 0;
        param_2[2] = param_2[2] + uVar10;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x40) {
    piVar11 = *(int **)(param_1 + 8);
    if (param_2[5] == 0) {
      iVar7 = 1;
    }
    else {
      iVar7 = 2;
    }
    puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x7b;
      param_2[3] = param_2[3] + 1;
      if (param_2[5] != 0) {
        puVar3[1] = 10;
      }
      param_2[2] = param_2[2] + iVar7;
      while (piVar11 != (int *)0x0) {
        if (param_2[5] != 0) {
          puVar9 = (undefined1 *)FUN_00018af0(param_2,param_2[3]);
          puVar3 = puVar9;
          if (puVar9 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          for (; (uint)((int)puVar3 - (int)puVar9) < (uint)param_2[3]; puVar3 = puVar3 + 1) {
            *puVar3 = 9;
          }
          param_2[2] = param_2[2] + param_2[3];
        }
        iVar7 = FUN_00018cb8(piVar11[8],param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (param_2[5] == 0) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        *puVar3 = 0x3a;
        if (param_2[5] != 0) {
          puVar3[1] = 9;
        }
        param_2[2] = param_2[2] + iVar7;
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        uVar10 = (uint)(*piVar11 != 0);
        if (param_2[5] != 0) {
          uVar10 = uVar10 + 1;
        }
        puVar3 = (undefined1 *)FUN_00018af0(param_2,uVar10 + 1);
        if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
        puVar9 = puVar3;
        if (*piVar11 != 0) {
          puVar9 = puVar3 + 1;
          *puVar3 = 0x2c;
        }
        puVar3 = puVar9;
        if (param_2[5] != 0) {
          puVar3 = puVar9 + 1;
          *puVar9 = 10;
        }
        *puVar3 = 0;
        piVar11 = (int *)*piVar11;
        param_2[2] = param_2[2] + uVar10;
      }
      if (param_2[5] == 0) {
        iVar7 = 2;
      }
      else {
        iVar7 = param_2[3] + 1;
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7);
      if (puVar3 != (undefined1 *)0x0) {
        puVar9 = puVar3;
        if (param_2[5] != 0) {
          for (; (uint)((int)puVar9 - (int)puVar3) < param_2[3] - 1; puVar9 = puVar9 + 1) {
            *puVar9 = 9;
          }
        }
        *puVar9 = 0x7d;
        puVar9[1] = 0;
LAB_00018fd0:
        param_2[3] = param_2[3] + -1;
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x80) {
    if (*(char **)(param_1 + 0x10) == (char *)0x0) {
      if (param_2[4] == 0) {
        (*(code *)param_2[7])(*param_2);
        uVar10 = 0;
        goto LAB_00019028;
      }
    }
    else {
      sVar6 = strlen(*(char **)(param_1 + 0x10));
      __dest = (void *)FUN_00018af0(param_2,sVar6 + 1);
      if (__dest != (void *)0x0) {
        memcpy(__dest,*(void **)(param_1 + 0x10),sVar6 + 1);
        goto LAB_00019000;
      }
    }
  }
  else if (uVar10 == 0x20) {
    piVar11 = *(int **)(param_1 + 8);
    puVar3 = (undefined1 *)FUN_00018af0(param_2,1);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x5b;
      param_2[2] = param_2[2] + 1;
      param_2[3] = param_2[3] + 1;
      for (; piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {
        iVar7 = FUN_00018ec0(piVar11,param_2);
        if (iVar7 == 0) goto switchD_00018f2c_default;
        FUN_00018ac0(param_2);
        if (*piVar11 != 0) {
          if (param_2[5] == 0) {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
          }
          puVar3 = (undefined1 *)FUN_00018af0(param_2,iVar7 + 1);
          if (puVar3 == (undefined1 *)0x0) goto switchD_00018f2c_default;
          *puVar3 = 0x2c;
          if (param_2[5] == 0) {
            puVar9 = puVar3 + 1;
          }
          else {
            puVar9 = puVar3 + 2;
            puVar3[1] = 0x20;
          }
          *puVar9 = 0;
          param_2[2] = param_2[2] + iVar7;
        }
      }
      puVar3 = (undefined1 *)FUN_00018af0(param_2,2);
      if (puVar3 != (undefined1 *)0x0) {
        puVar3[1] = 0;
        *puVar3 = 0x5d;
        goto LAB_00018fd0;
      }
    }
  }
switchD_00018f2c_default:
  uVar10 = 0;
LAB_00019028:
  if (local_24 != **(int **)(DAT_00019498 + 0x19038 + DAT_0001948c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}


===== ADDRESS 0001ac90 FUNCTION FUN_0001ac5c =====

undefined4 FUN_0001ac5c(int param_1,char *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(DAT_0001ac9c + 0x1ac70);
  do {
    piVar1 = piVar2 + 1;
    if ((char *)*piVar1 == (char *)0x0) {
      return 0xffffffff;
    }
    iVar3 = *piVar2;
    piVar2 = piVar2 + 2;
  } while (iVar3 != param_1);
  strcpy(param_2,(char *)*piVar1);
  return 0;
}


===== ADDRESS 0001b8f0 FUNCTION FUN_0001b780 =====

void FUN_0001b780(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char acStack_84 [32];
  char acStack_64 [32];
  undefined4 local_44;
  undefined1 auStack_40 [28];
  int local_24;
  
  local_24 = **(int **)(DAT_0001b9bc + 0x1b790 + DAT_0001b9c0);
  local_44 = 0;
  memset(auStack_40,0,0x1c);
  iVar5 = DAT_0001b9c8 + 0x1b7d4;
  iVar1 = *(int *)(DAT_0001b9c4 + 0x1b7d8);
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x3f) == '\0') {
      __fprintf_chk(iVar1,1,DAT_0001b9d8 + 0x1b86c,acStack_84,*(undefined4 *)(param_1 + 0x1a4));
    }
    else {
      __fprintf_chk(iVar1,1,DAT_0001b9cc + 0x1b80c,acStack_84,*(undefined4 *)(param_1 + 0x1a4),
                    param_1 + 0x3f);
    }
  }
  if (**(int **)(iVar5 + DAT_0001b9d0) == 0) {
    if (*(int *)(param_1 + 0x14) == 0xd) {
      FUN_0001b68c(param_1);
    }
    else {
      puVar2 = &local_44;
      FUN_0001760c(param_1 + 0xc,acStack_84);
      FUN_00017424(param_2,puVar2,0x20);
      iVar1 = *(int *)(DAT_0001b9dc + 0x1b8a4);
      if (iVar1 != 0) {
        pcVar6 = *(char **)(*(int *)(DAT_0001b9dc + 0x1b8ac) + 0x60);
        while ((pcVar6 != (char *)0x0 && (iVar5 = strcmp(pcVar6,acStack_84), iVar5 != 0))) {
          pcVar6 = *(char **)(pcVar6 + 0x60);
        }
        iVar5 = FUN_0001ac5c(*(undefined4 *)(param_1 + 0x1c0),acStack_64);
        if (iVar5 == -1) {
          strcpy(acStack_64,(char *)(DAT_0001b9e0 + 0x1b8f4));
        }
        iVar5 = *(int *)(param_1 + 0x1a4);
        if ((pcVar6 != (char *)0x0) && (*(int *)(pcVar6 + 0x1c) != 0)) {
          iVar5 = *(int *)(pcVar6 + 0x1c);
        }
        pcVar6 = inet_ntoa((in_addr)*(in_addr_t *)(param_1 + 8));
        if ((char)local_44 == '\0') {
          puVar2 = (undefined4 *)(DAT_0001b9e4 + 0x1b92c);
        }
        if (*(char *)(param_1 + 0x1a0) == '\x02') {
          uVar3 = *(undefined4 *)(param_1 + 0x1b0);
          uVar4 = *(undefined4 *)(param_1 + 0x1b4);
          uVar7 = *(undefined4 *)(param_1 + 0x1a8);
          uVar8 = *(undefined4 *)(param_1 + 0x1ac);
        }
        else {
          uVar3 = 0;
          uVar4 = 0;
          uVar7 = uVar3;
          uVar8 = uVar4;
        }
        if (*(char *)(param_1 + 0x3f) == '\0') {
          param_1 = DAT_0001b9e8 + 0x1b958;
        }
        else {
          param_1 = param_1 + 0x3f;
        }
        __fprintf_chk(iVar1,1,DAT_0001b9f0 + 0x1b978,pcVar6,acStack_84,puVar2,iVar5,acStack_64,uVar3
                      ,uVar4,uVar7,uVar8,DAT_0001b9ec + 0x1b970,DAT_0001b9ec + 0x1b970,param_1);
      }
    }
  }
  if (local_24 != **(int **)(DAT_0001b9d4 + 0x1b844 + DAT_0001b9c0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ADDRESS 0001c63c FUNCTION FUN_0001c45c =====

void FUN_0001c45c(undefined4 param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  ether_addr *peVar6;
  int iVar7;
  char *__needle;
  char *__needle_00;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint local_2ac;
  undefined1 auStack_2a8 [16];
  char local_298 [40];
  char local_270 [128];
  undefined1 auStack_1f0 [8];
  in_addr iStack_1e8;
  undefined4 local_1e4;
  undefined2 local_1e0;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined1 auStack_1b1 [117];
  undefined1 auStack_13c [280];
  int local_24;
  
  bVar2 = 0;
  iVar7 = DAT_0001c7e8 + 0x1c47c;
  local_24 = **(int **)(DAT_0001c7ec + 0x1c488 + DAT_0001c7f0);
  local_270[0] = '\0';
  local_270[1] = '\0';
  local_270[2] = '\0';
  local_270[3] = '\0';
  memset(local_270 + 4,0,0x7c);
  local_298[0] = '\0';
  local_298[1] = '\0';
  local_298[2] = '\0';
  local_298[3] = '\0';
  memset(local_298 + 4,0,0x24);
  local_2ac = 0;
  memset(auStack_2a8,0,0x10);
  __stream = fopen((char *)(DAT_0001c7f8 + 0x1c4e8),(char *)(DAT_0001c7f4 + 0x1c4e4));
  if (__stream != (FILE *)0x0) {
    __stream_00 = fopen((char *)(DAT_0001c800 + 0x1c504),(char *)(DAT_0001c7fc + 0x1c500));
    __needle = (char *)(DAT_0001c804 + 0x1c510);
    __needle_00 = (char *)(DAT_0001c808 + 0x1c51c);
    while( true ) {
      pcVar3 = fgets(local_270,0x80,__stream);
      if (pcVar3 == (char *)0x0) break;
      pcVar3 = strcasestr(local_270,__needle);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = strcasestr(local_270,__needle_00);
        bVar1 = (bool)(bVar2 ^ 1);
        if (pcVar3 != (char *)0x0) {
          bVar1 = true;
        }
        if (!bVar1) {
          iVar9 = DAT_0001c810 + 0x1c5c8;
          pcVar3 = (char *)FUN_00017ec8(local_270,iVar9);
          FUN_00017ec8(0,iVar9);
          pcVar4 = (char *)FUN_00017ec8(0,DAT_0001c814 + 0x1c5ec);
          pcVar5 = (char *)FUN_00017ec8(0,iVar9);
          if ((*pcVar4 != '\0') && (*pcVar5 != '\0')) {
            iVar9 = FUN_0001c2a8(pcVar4,local_298);
            if (iVar9 == 0) {
              strcpy(local_298,(char *)(DAT_0001c818 + 0x1c640));
            }
            FUN_000178c8(local_298);
            memset(auStack_1f0,0,0x1c8);
            peVar6 = ether_aton(local_298);
            local_1e4 = *(undefined4 *)peVar6->ether_addr_octet;
            local_1e0 = *(undefined2 *)(peVar6->ether_addr_octet + 4);
            iVar9 = inet_aton(pcVar3,&iStack_1e8);
            if (iVar9 != 0) {
              iVar10 = DAT_0001c81c + 0x1c6a4;
              local_1d8 = 0x13;
              uStack_1d4 = 0;
              FUN_00017018(auStack_13c,iVar10,0x20);
              FUN_00017018(auStack_1b1,DAT_0001c820 + 0x1c6c4,0x40);
              FUN_00013dfc(auStack_1f0);
              iVar9 = DAT_0001c824 + 0x1c6e8;
              *param_2 = *param_2 + 1;
              FUN_00014e68(auStack_1f0,iVar9,param_1);
              FUN_00014e68(auStack_1f0,iVar10,__stream_00,*param_2);
              if (**(int **)(iVar7 + DAT_0001c828) == 0) {
                FUN_00017018(&local_2ac,DAT_0001c82c + 0x1c730,0x14);
              }
              iVar9 = FUN_0001bdb4(DAT_0001c830 + 0x1c744,pcVar4,pcVar5);
              if (iVar9 != 0) {
                __snprintf_chk(&local_2ac,0x14,1,0x14,DAT_0001c834 + 0x1c764,iVar9);
              }
              if (__stream_00 != (FILE *)0x0) {
                pcVar3 = pcVar4;
                if (*pcVar4 == '\0') {
                  pcVar3 = (char *)(DAT_0001c838 + 0x1c790);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c83c + 0x1c7a0,pcVar3);
                puVar8 = &local_2ac;
                if ((local_2ac & 0xff) == 0) {
                  puVar8 = (uint *)(DAT_0001c840 + 0x1c7b8);
                }
                __fprintf_chk(__stream_00,1,DAT_0001c844 + 0x1c7c8,puVar8);
              }
              FUN_0001b520(auStack_1f0,pcVar4,&local_2ac,1);
            }
          }
          goto LAB_0001c58c;
        }
        bVar2 = 0;
      }
      else {
LAB_0001c58c:
        bVar2 = 1;
      }
    }
    fclose(__stream);
    if (__stream_00 != (FILE *)0x0) {
      fclose(__stream_00);
    }
  }
  if (local_24 != **(int **)(DAT_0001c80c + 0x1c564 + DAT_0001c7f0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ADDRESS 0001d060 FUNCTION FUN_0001cf70 =====

void FUN_0001cf70(int param_1)

{
  FILE *__stream;
  char *pcVar1;
  char *__cp;
  int iVar2;
  char *pcVar3;
  char acStack_144 [32];
  char acStack_124 [256];
  int local_24;
  
  local_24 = **(int **)(DAT_0001d0a0 + 0x1cf84 + DAT_0001d0a4);
  FUN_0001760c(param_1 + 0xc,acStack_144,DAT_0001d0a0 + 0x1cf84,0);
  __stream = fopen((char *)(DAT_0001d0ac + 0x1cfbc),(char *)(DAT_0001d0a8 + 0x1cfb8));
  if (__stream != (FILE *)0x0) {
    pcVar3 = (char *)(DAT_0001d0b0 + 0x1cfd4);
    do {
      pcVar1 = fgets(acStack_124,0x100,__stream);
      if (pcVar1 == (char *)0x0) goto LAB_0001d06c;
      pcVar1 = strtok(acStack_124,pcVar3);
      __cp = strtok((char *)0x0,pcVar3);
    } while ((__cp == (char *)0x0 || pcVar1 == (char *)0x0) ||
            (iVar2 = strcmp(pcVar1,acStack_144), iVar2 != 0));
    inet_aton(__cp,(in_addr *)(param_1 + 8));
    *(undefined4 *)(param_1 + 0x1c) = 2;
    pcVar3 = (char *)(DAT_0001d0b4 + 0x1d054);
    if (*(int *)(param_1 + 0x14) == 0) {
      *(undefined4 *)(param_1 + 0x14) = 8;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    strcpy((char *)(param_1 + 0x20),pcVar3);
    FUN_0001cda0(acStack_144);
LAB_0001d06c:
    fclose(__stream);
  }
  if (local_24 == **(int **)(DAT_0001d0b8 + 0x1d084 + DAT_0001d0a4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ADDRESS 0001db8c FUNCTION FUN_0001da20 =====

void FUN_0001da20(char *param_1,FILE *param_2)

{
  char *pcVar1;
  char *__s1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_a4 [128];
  int local_24;
  
  local_24 = **(int **)(DAT_0001db9c + 0x1da30 + DAT_0001dba0);
  local_a4[0] = '\0';
  local_a4[1] = '\0';
  local_a4[2] = '\0';
  local_a4[3] = '\0';
  memset(local_a4 + 4,0,0x7c);
  iVar3 = DAT_0001dba4;
  fseek(param_2,0,0);
  pcVar4 = (char *)(DAT_0001dba8 + 0x1da88);
  do {
    pcVar1 = fgets(local_a4,0x80,param_2);
    if (pcVar1 == (char *)0x0) goto LAB_0001daf8;
    pcVar1 = strtok(local_a4,(char *)(iVar3 + 0x1da84));
    __s1 = strtok((char *)0x0,pcVar4);
  } while ((__s1 == (char *)0x0 || pcVar1 == (char *)0x0) ||
          (iVar2 = strcmp(pcVar1,param_1), iVar2 != 0));
  iVar3 = strcmp(__s1,(char *)(DAT_0001dbac + 0x1daf0));
  if (iVar3 != 0) {
    pcVar1 = (char *)(DAT_0001dbb4 + 0x1db2c);
    iVar3 = 0;
    pcVar4 = pcVar1;
    do {
      iVar2 = strcmp(pcVar4,__s1);
      if (iVar2 == 0) goto LAB_0001daf8;
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 2;
    } while (iVar3 != 4);
    pcVar4 = (char *)(DAT_0001dbb8 + 0x1db5c);
    iVar3 = 0;
    do {
      iVar2 = strcmp(pcVar1,pcVar4);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
      pcVar1 = pcVar1 + 2;
    } while (iVar3 != 4);
    strcpy((char *)(DAT_0001dbbc + 0x1db8c + iVar3 * 2),__s1);
  }
LAB_0001daf8:
  if (local_24 != **(int **)(DAT_0001dbb0 + 0x1db08 + DAT_0001dba0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

